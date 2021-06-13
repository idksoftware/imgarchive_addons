// CkoutIcon.h : Declaration of the CCkoutIcon

#pragma once
#include "resource.h"       // main symbols



#include "IACkoutIcon_i.h"
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

// CCkoutIcon

class ATL_NO_VTABLE CCkoutIcon :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCkoutIcon, &CLSID_CkoutIcon>,
	public IShellIconOverlayIdentifier,
	public IDispatchImpl<ICkoutIcon, &IID_ICkoutIcon, &LIBID_IACkoutIconLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CCkoutIcon()
	{
		m_szPath[0] = '\0';
	}

	// IShellIconOverlayIdentifier Methods
	STDMETHOD(GetOverlayInfo)(LPWSTR pwszIconFile,
		int cchMax, int* pIndex, DWORD* pdwFlags);
	STDMETHOD(GetPriority)(int* pPriority);
	STDMETHOD(IsMemberOf)(LPCWSTR pwszPath, DWORD dwAttrib);

DECLARE_REGISTRY_RESOURCEID(IDR_CKOUTICON)


BEGIN_COM_MAP(CCkoutIcon)
	COM_INTERFACE_ENTRY(ICkoutIcon)
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
	bool readFile(const char* path);
	bool GetRegValues();
	TCHAR m_szWorkspacePath[MAX_PATH];
	char m_szPath[MAX_PATH];
	CComAutoCriticalSection m_critSec;
	time_t getFile(const std::string& _name);
};

OBJECT_ENTRY_AUTO(__uuidof(CkoutIcon), CCkoutIcon)
