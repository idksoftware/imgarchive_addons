// CkoutIcon.cpp : Implementation of CCkoutIcon

#include "pch.h"
#include "CkoutIcon.h"
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

void CCkoutIcon::InsertFile(TCHAR* szFile)
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
STDMETHODIMP CCkoutIcon::GetOverlayInfo(LPWSTR pwszIconFile, int cchMax, int* pIndex, DWORD* pdwFlags)
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

	// Use first icon in the resource
	*pIndex = 0;

	*pdwFlags = ISIOI_ICONFILE | ISIOI_ICONINDEX;
	return S_OK;
}

// IShellIconOverlayIdentifier::GetPriority
// returns the priority of this overlay 0 being the highest. 
STDMETHODIMP CCkoutIcon::GetPriority(int* pPriority)
{
	// we want highest priority 
	*pPriority = 1;
	return S_OK;
}

// IShellIconOverlayIdentifier::IsMemberOf
// Returns whether the object should have this overlay or not 
STDMETHODIMP CCkoutIcon::IsMemberOf(LPCWSTR pwszPath, DWORD dwAttrib)
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
	//wchar_t* s = _wcsdup(pwszPath);
	HRESULT r = S_FALSE;

	//_wcslwr(s);
	DWORD dwReturnCode = _tsplitpath_s(pwszPath, tcDrive, _MAX_DRIVE, tcDir, _MAX_DIR, tcFname, _MAX_FNAME, tcExt, _MAX_EXT);

	// Criteria
	wsprintf(tcPath, _T("%s%s\\.imga"), tcDrive, tcDir);
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
		//char fnamePath[_MAX_FNAME];
		//strcpy(fnamePath, T2A(pPath));
		//time_t fileTimeT = getModTime(fnamePath);
		//if (fileTimeT > time) {
			
		//	r = S_OK;
		//}
		//else {
			
			//r = S_FALSE;
		//}
		r = S_OK;
	}
	return r;
}

time_t CCkoutIcon::getFile(const std::string& _name)
{
	const auto it = m_FileList.find(_name);

	// if not found
	if (it == m_FileList.end())
		return -1;

	return (it->second);
}

bool CCkoutIcon::readFile(const char* p) {
	USES_CONVERSION;
	char path[1024];
	char buffer[1024];
	
	sprintf(path, "%s\\chkout.dat", p);
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

bool CCkoutIcon::GetRegValues() {
	CRegKey hKey;
	long lRet;
	//
	//	Open the registery to extract the directory X:/Temp
	//	and the path to DSDoorMan
	//
	lRet = hKey.Open(HKEY_CURRENT_USER,
		_T(SYSTEM_OPTIONS));

	
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


#ifdef XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// CCkoutIcon
// CMyOverlayIcon
// IShellIconOverlayIdentifier::GetOverlayInfo
// returns The Overlay Icon Location to the system
STDMETHODIMP CCOverlayProvider::GetOverlayInfo(
    LPWSTR pwszIconFile,
    int cchMax,
    int* pIndex,
    DWORD* pdwFlags)
{
    // Get our module's full path
    GetModuleFileNameW(_AtlBaseModule.GetModuleInstance(), pwszIconFile, cchMax);

    // Use first icon in the resource
    *pIndex = 0;

    *pdwFlags = ISIOI_ICONFILE | ISIOI_ICONINDEX;
    return S_OK;
}

// IShellIconOverlayIdentifier::GetPriority
// returns the priority of this overlay 0 being the highest. 
STDMETHODIMP CCOverlayProvider::GetPriority(int* pPriority)
{
    // we want highest priority 
    *pPriority = 0;
    return S_OK;
}

// IShellIconOverlayIdentifier::IsMemberOf
// Returns whether the object should have this overlay or not 
STDMETHODIMP CCOverlayProvider::IsMemberOf(LPCWSTR pwszPath, DWORD dwAttrib)
{
    wchar_t* s = _wcsdup(pwszPath);
    HRESULT r = S_FALSE;

    _wcslwr(s);

    // Criteria
    if (wcsstr(s, L"codeproject") != 0)
        r = S_OK;

    free(s);

    return r;
}
#endif