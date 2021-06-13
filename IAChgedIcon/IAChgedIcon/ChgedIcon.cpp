// ChgedIcon.cpp : Implementation of CChgedIcon

#include "pch.h"
#include "ChgedIcon.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include "atlstr.h"
#include "PreserveChdir.h"

typedef CComCritSecLock<CComCriticalSection> AutoLocker;

#define SYSTEM_OPTIONS "Software\\IDK Software\\ImgArchive 1.0"

time_t  filetime_to_timet(FILETIME const& ft)
{
	ULARGE_INTEGER ull;
	ull.LowPart = ft.dwLowDateTime;
	ull.HighPart = ft.dwHighDateTime;
	return ull.QuadPart / 10000000ULL - 11644473600ULL;
}

void ShortFilename(TCHAR* pPath, TCHAR* fname)
{

	TCHAR drive[_MAX_DRIVE];
	TCHAR dir[_MAX_DIR];
	TCHAR ext[_MAX_EXT];

	_tsplitpath(pPath, drive, dir, fname, ext);
	size_t len = _tcslen(fname);
	if (len)
	{
		// File selected
		lstrcat(fname, ext);
	}
	else
	{
		// Directory selected
		_tcscpy(fname, pPath);
	}

}

time_t getModTime(const std::string& fileName)
{
	WIN32_FILE_ATTRIBUTE_DATA info;
	if (GetFileAttributesExA(fileName.c_str(), GetFileExInfoStandard, &info) == 0)
	{
		return S_FALSE;
	}
	const FILETIME ftLastWriteTime = info.ftLastWriteTime;
	time_t fileTimeT = filetime_to_timet(ftLastWriteTime);
	return fileTimeT;
}

void CChgedIcon::InsertFile(TCHAR* szFile)
{
	/*
	int len = _tcslen(szFile);
	int s = sizeof(TCHAR);
	TCHAR *l_szTmp = new TCHAR[(len + sizeof(TCHAR))];
	_tcscpy(l_szTmp, szFile);
	m_FileList.Add((TCHAR *)l_szTmp);
	*/
}
// CMyOverlayIcon
// IShellIconOverlayIdentifier::GetOverlayInfo
// returns The Overlay Icon Location to the system
STDMETHODIMP CChgedIcon::GetOverlayInfo(LPWSTR pwszIconFile, int cchMax, int* pIndex, DWORD* pdwFlags)
{
	if (!pwszIconFile)
		return E_POINTER;
	if (!pIndex)
		return E_POINTER;
	if (!pdwFlags)
		return E_POINTER;
	if (cchMax < 1)
		return E_INVALIDARG;

	// Get our module's full path
	GetModuleFileNameW(_AtlBaseModule.GetModuleInstance(), pwszIconFile, cchMax);
	m_pwszIconFile = pwszIconFile;
	// Use first icon in the resource
	*pIndex = 0;

	*pdwFlags = ISIOI_ICONFILE | ISIOI_ICONINDEX;
	return S_OK;
}

// IShellIconOverlayIdentifier::GetPriority
// returns the priority of this overlay 0 being the highest. 
STDMETHODIMP CChgedIcon::GetPriority(int* pPriority)
{
	// we want highest priority 
	*pPriority = 0;
	return S_OK;
}

// IShellIconOverlayIdentifier::IsMemberOf
// Returns whether the object should have this overlay or not 
STDMETHODIMP CChgedIcon::IsMemberOf(LPCWSTR pwszPath, DWORD dwAttrib)
{
	if (!pwszPath)
		return E_INVALIDARG;
	const TCHAR* pPath = pwszPath;
	// the shell sometimes asks overlays for invalid paths, e.g. for network
	// printers (in that case the path is "0", at least for me here).
	if (wcslen(pPath) < 2)
		return S_FALSE;

	TCHAR   tcDrive[_MAX_DRIVE] = { 0 };
	TCHAR   tcDir[_MAX_DIR] = { 0 };
	TCHAR   tcFname[_MAX_FNAME] = { 0 };
	TCHAR   tcExt[_MAX_EXT] = { 0 };
	TCHAR   tcPath[_MAX_DIR + _MAX_DRIVE] = { 0 };
	USES_CONVERSION;
	bool isWorkspace = false;

	HRESULT r = S_FALSE;


	DWORD dwReturnCode = _tsplitpath_s(pwszPath, tcDrive, _MAX_DRIVE, tcDir, _MAX_DIR, tcFname, _MAX_FNAME, tcExt, _MAX_EXT);

	// Criteria
	wsprintf(tcPath, _T("%s%s\.imga"), tcDrive, tcDir);
	DWORD dwAttribSIA = GetFileAttributes(tcPath);
	isWorkspace = (dwAttribSIA != INVALID_FILE_ATTRIBUTES && (dwAttribSIA & FILE_ATTRIBUTE_DIRECTORY));
	if (!isWorkspace) {
		r = S_FALSE;
	}
	else {
		

		PreserveChdir preserveChdir;

		// Read Check-out file
		char szPath[_MAX_PATH + 1];
		char szFileName[_MAX_PATH + 1];
		TCHAR   fullFname[_MAX_FNAME];
		wsprintf(fullFname, _T("%s%s"), tcFname, tcExt);
		strcpy(szFileName, T2A(fullFname));
		bool found = false;

		strcpy(szPath, T2A(tcPath));
		AutoLocker lock(m_critSec);
		if (strcmp(m_szPath, szPath) != 0) {


			m_FileList.clear();
			readFile(szPath);
			strcpy(m_szPath, szPath);
		}
		// process file(s)
		const std::string curName = szFileName;
		time_t time = getFile(curName);
		if (time == -1) {
			//std::cout << "Not found" << std::endl;
			return S_FALSE;
		}
		char fnamePath[_MAX_FNAME];
		strcpy(fnamePath, T2A(pPath));
		time_t fileTimeT = getModTime(fnamePath);
		if (fileTimeT > time) {
			//std::cout << TimetoString(time) << "Modifed" << std::endl;
			r = S_OK;
		}
		else {
			//std::cout << TimetoString(time) << "Unmodifed" << std::endl;
			r = S_FALSE;
		}
		/*
		for (auto i = m_FileList.begin(); i != m_FileList.end(); i++) {
			std::shared_ptr<std::string> item = *i;
			if (curName.compare(*item) == 0) {
				found = true;
				break;
			}
		}
		
		if (found)
		{
			r = S_OK;
		}
		else {
			r = S_FALSE;
		}
		//free(s);
		*/
	}
	return r;
}

time_t CChgedIcon::getFile(const std::string& _name)
{
	const auto it = m_FileList.find(_name);

	// if not found
	if (it == m_FileList.end())
		return -1;

	return (it->second);
}

bool CChgedIcon::readFile(const char* p) {
	char path[_MAX_PATH];
	char buffer[_MAX_FNAME];
	sprintf_s(path, "%s\\chged.dat", p);
	std::ifstream fin(path);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin.getline(buffer, _MAX_FNAME);
			//m_FileList.push_back(std::make_shared<FileItem>(buffer));
			std::string str = buffer;
			size_t pos = str.find(':');
			if (pos == std::string::npos) {
				continue;
			}
			std::string fileName = str.substr(0, pos);
			std::string modStr = str.substr(pos + 1, str.length() - pos + 1);
			time_t modTime = std::stoull(modStr, nullptr, 10);
			m_FileList.insert(std::make_pair(fileName, modTime));
		}
	}
	fin.close();
	return true;
}

bool CChgedIcon::GetRegValues() {
	CRegKey hKey;
	long lRet;
	//
	//	Open the registery to extract the directory X:/Temp
	//	and the path to DSDoorMan
	//
	lRet = hKey.Open(HKEY_CURRENT_USER,
		_T(SYSTEM_OPTIONS));

	TCHAR szValue[260];
	LPCTSTR lpszValueName;
	DWORD pdwCount;



	if (lRet != ERROR_SUCCESS)
	{
		// If unsuccessfuly open the key
		::MessageBox(0, __TEXT("Sorry? ImgArchive Installation incomplete.\r")
			__TEXT("Please re-install ImgArchive.\r")
			__TEXT("If the problem persists, please contact IDK Software Ltd."),
			__TEXT("Simple Image Archive"), MB_OK);
		return true;
	}

	pdwCount = 260;
	lRet = hKey.QueryStringValue(m_szWorkspacePath, __TEXT("WorkspacePath"), &pdwCount);
	if (lRet != ERROR_SUCCESS)
	{
		// If unsuccessfuly found the temp directory
		::MessageBox(0, __TEXT("Simple Image Archive"),
			__TEXT("Simple Image Archive Installation incomplete"), MB_OK);
		return false;
	}

	return true;
}




