

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 03:14:07 2038
 */
/* Compiler settings for IACkoutIcon.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __IACkoutIcon_i_h__
#define __IACkoutIcon_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICkoutIcon_FWD_DEFINED__
#define __ICkoutIcon_FWD_DEFINED__
typedef interface ICkoutIcon ICkoutIcon;

#endif 	/* __ICkoutIcon_FWD_DEFINED__ */


#ifndef __CkoutIcon_FWD_DEFINED__
#define __CkoutIcon_FWD_DEFINED__

#ifdef __cplusplus
typedef class CkoutIcon CkoutIcon;
#else
typedef struct CkoutIcon CkoutIcon;
#endif /* __cplusplus */

#endif 	/* __CkoutIcon_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ICkoutIcon_INTERFACE_DEFINED__
#define __ICkoutIcon_INTERFACE_DEFINED__

/* interface ICkoutIcon */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICkoutIcon;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8ab5cc4c-4950-44d9-91f3-6cde6fcefc5e")
    ICkoutIcon : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct ICkoutIconVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICkoutIcon * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICkoutIcon * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICkoutIcon * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICkoutIcon * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICkoutIcon * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICkoutIcon * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICkoutIcon * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ICkoutIconVtbl;

    interface ICkoutIcon
    {
        CONST_VTBL struct ICkoutIconVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICkoutIcon_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICkoutIcon_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICkoutIcon_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICkoutIcon_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICkoutIcon_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICkoutIcon_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICkoutIcon_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICkoutIcon_INTERFACE_DEFINED__ */



#ifndef __IACkoutIconLib_LIBRARY_DEFINED__
#define __IACkoutIconLib_LIBRARY_DEFINED__

/* library IACkoutIconLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_IACkoutIconLib;

EXTERN_C const CLSID CLSID_CkoutIcon;

#ifdef __cplusplus

class DECLSPEC_UUID("540fcc02-7ea1-47d8-8f6a-65e28671c3e5")
CkoutIcon;
#endif
#endif /* __IACkoutIconLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


