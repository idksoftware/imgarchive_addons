// dllmain.h : Declaration of module class.

class CIACkoutIconModule : public ATL::CAtlDllModuleT< CIACkoutIconModule >
{
public :
	DECLARE_LIBID(LIBID_IACkoutIconLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_IACKOUTICON, "{4369b00d-fbfc-460a-b00b-f6235e33d65e}")
};

extern class CIACkoutIconModule _AtlModule;
