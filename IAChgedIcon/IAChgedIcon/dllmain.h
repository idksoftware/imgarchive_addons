// dllmain.h : Declaration of module class.

class CIAChgedIconModule : public ATL::CAtlDllModuleT< CIAChgedIconModule >
{
public :
	DECLARE_LIBID(LIBID_IAChgedIconLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_IACHGEDICON, "{c814851b-97b1-4a2b-ab5f-2b2fbf423599}")
};

extern class CIAChgedIconModule _AtlModule;
