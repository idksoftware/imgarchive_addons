// ChgedIcon.h : Declaration of the CChgedIcon

#pragma once
#include "resource.h"       // main symbols
#include "IAChgedIcon_i.h"
#include <shlobj.h>
#include <comdef.h>
#include <string>
#include <vector>
#include <memory>
#include <map>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;

typedef std::map<std::string, time_t> FileMap;
// CChgedIcon

class ATL_NO_VTABLE CChgedIcon :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CChgedIcon, &CLSID_ChgedIcon>,
	public IShellIconOverlayIdentifier,
	public IDispatchImpl<IChgedIcon, &IID_IChgedIcon, &LIBID_IAChgedIconLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CChgedIcon()
	{
	}

	// IShellIconOverlayIdentifier Methods
	STDMETHOD(GetOverlayInfo)(LPWSTR pwszIconFile,
		int cchMax, int* pIndex, DWORD* pdwFlags);
	STDMETHOD(GetPriority)(int* pPriority);
	STDMETHOD(IsMemberOf)(LPCWSTR pwszPath, DWORD dwAttrib);

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CChgedIcon)
	COM_INTERFACE_ENTRY(IChgedIcon)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IShellIconOverlayIdentifier)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	void InsertFile(TCHAR* szFile);
private:
	//CSimpleArray<TCHAR *> m_FileList;
	FileMap m_FileList;

	time_t getFile(const std::string& _name);
	bool readFile(const char* path);
	bool GetRegValues();
	TCHAR  m_szWorkspacePath[MAX_PATH];
	LPWSTR m_pwszIconFile;
	char  m_szPath[MAX_PATH];
	CComAutoCriticalSection m_critSec;
};

OBJECT_ENTRY_AUTO(__uuidof(ChgedIcon), CChgedIcon)
