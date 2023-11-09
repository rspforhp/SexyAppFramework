// This has to be its own file because d3d8.h and d3d.h conflict
#undef DIRECT3D_VERSION
#include <windows.h>

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// This stuff is copied from d3d8.h because you can't include both d3d.h and d3d8.h in a project

#include <combaseapi.h>
#include <ddraw.h>
#define D3D_SDK_VERSION 220
DEFINE_GUID(IID_IDirect3D8, 0x1dd9e8da, 0x1c77, 0x4d40, 0xb0, 0xcf, 0x98, 0xfe, 0xfd, 0xff, 0x95, 0x12);
DEFINE_GUID(IID_IDirect3D9, 0x81bdcbca, 0x64d4, 0x426d, 0xae, 0x8d, 0xad, 0x1, 0x47, 0xf4, 0x27, 0x5c);
DEFINE_GUID(IID_IDirect3D10, 0x1dd9e8da, 0x1c77, 0x4d40, 0xb0, 0xcf, 0x98, 0xfe, 0xfd, 0xff, 0x95, 0x12);
DEFINE_GUID(IID_IDirect3D11, 0x1dd9e8da, 0x1c77, 0x4d40, 0xb0, 0xcf, 0x98, 0xfe, 0xfd, 0xff, 0x95, 0x12);
#include <d3d9.h>
#include <d3d9caps.h>
#include <d3d10_1.h>//include *first* because otherwise the SAL notations get confused...
#include <d3d10.h>
#include <d3d11.h>

#include "D3DHelper.h"



interface IDirect3D8;
interface IDirect3DDevice8;
interface IDirect3D9;
interface IDirect3DDevice9;
interface IDirect3D10;
interface IDirect3DDevice10;
interface IDirect3D11;
interface IDirect3DDevice11;

typedef struct IDirect3D8* LPDIRECT3D8, * PDIRECT3D8;
typedef struct IDirect3D9* LPDIRECT3D9, * PDIRECT3D9;
typedef struct IDirect3D10* LPDIRECT3D10, * PDIRECT3D10;
typedef struct IDirect3D11* LPDIRECT3D11, * PDIRECT3D11;

#undef INTERFACE
#define INTERFACE IDirect3D8
#define INTERFACE IDirect3D9
#define INTERFACE IDirect3D10
#define INTERFACE IDirect3D11


typedef enum _D3DFORMAT
{
    D3DFMT_UNKNOWN              =  0,

    D3DFMT_R8G8B8               = 20,
    D3DFMT_A8R8G8B8             = 21,
    D3DFMT_X8R8G8B8             = 22,
    D3DFMT_R5G6B5               = 23,
    D3DFMT_X1R5G5B5             = 24,
    D3DFMT_A1R5G5B5             = 25,
    D3DFMT_A4R4G4B4             = 26,
    D3DFMT_R3G3B2               = 27,
    D3DFMT_A8                   = 28,
    D3DFMT_A8R3G3B2             = 29,
    D3DFMT_X4R4G4B4             = 30,
    D3DFMT_A2B10G10R10          = 31,
    D3DFMT_G16R16               = 34,

    D3DFMT_A8P8                 = 40,
    D3DFMT_P8                   = 41,

    D3DFMT_L8                   = 50,
    D3DFMT_A8L8                 = 51,
    D3DFMT_A4L4                 = 52,

    D3DFMT_V8U8                 = 60,
    D3DFMT_L6V5U5               = 61,
    D3DFMT_X8L8V8U8             = 62,
    D3DFMT_Q8W8V8U8             = 63,
    D3DFMT_V16U16               = 64,
    D3DFMT_W11V11U10            = 65,
    D3DFMT_A2W10V10U10          = 67,

    D3DFMT_UYVY                 = MAKEFOURCC('U', 'Y', 'V', 'Y'),
    D3DFMT_YUY2                 = MAKEFOURCC('Y', 'U', 'Y', '2'),
    D3DFMT_DXT1                 = MAKEFOURCC('D', 'X', 'T', '1'),
    D3DFMT_DXT2                 = MAKEFOURCC('D', 'X', 'T', '2'),
    D3DFMT_DXT3                 = MAKEFOURCC('D', 'X', 'T', '3'),
    D3DFMT_DXT4                 = MAKEFOURCC('D', 'X', 'T', '4'),
    D3DFMT_DXT5                 = MAKEFOURCC('D', 'X', 'T', '5'),

    D3DFMT_D16_LOCKABLE         = 70,
    D3DFMT_D32                  = 71,
    D3DFMT_D15S1                = 73,
    D3DFMT_D24S8                = 75,
    D3DFMT_D16                  = 80,
    D3DFMT_D24X8                = 77,
    D3DFMT_D24X4S4              = 79,
   
    D3DFMT_D32F_LOCKABLE = 82,
    D3DFMT_D24FS8 = 83,
    D3DFMT_D32_LOCKABLE = 84,
    D3DFMT_S8_LOCKABLE = 85,



    D3DFMT_VERTEXDATA           =100,
    D3DFMT_INDEX16              =101,
    D3DFMT_INDEX32              =102,
   

    D3DFMT_R16F = 111,
    D3DFMT_G16R16F = 112,
    D3DFMT_A16B16G16R16F = 113,

    D3DFMT_R32F = 114,
    D3DFMT_G32R32F = 115,
    D3DFMT_A32B32G32R32F = 116,

    D3DFMT_CxV8U8 = 117,

    D3DFMT_FORCE_DWORD          =0x7fffffff
} D3DFORMAT;

/* Direct3D8 Device types */
typedef enum _D3DDEVTYPE
{
    D3DDEVTYPE_HAL         = 1,
    D3DDEVTYPE_REF         = 2,
    D3DDEVTYPE_SW          = 3,

    D3DDEVTYPE_FORCE_DWORD  = 0x7fffffff
} D3DDEVTYPE;

typedef enum _D3DRESOURCETYPE {
    D3DRTYPE_SURFACE                =  1,
    D3DRTYPE_VOLUME                 =  2,
    D3DRTYPE_TEXTURE                =  3,
    D3DRTYPE_VOLUMETEXTURE          =  4,
    D3DRTYPE_CUBETEXTURE            =  5,
    D3DRTYPE_VERTEXBUFFER           =  6,
    D3DRTYPE_INDEXBUFFER            =  7,


    D3DRTYPE_FORCE_DWORD            = 0x7fffffff
} D3DRESOURCETYPE;



#define MAX_DEVICE_IDENTIFIER_STRING        512
typedef struct _D3DADAPTER_IDENTIFIER8
{
    char            Driver[MAX_DEVICE_IDENTIFIER_STRING];
    char            Description[MAX_DEVICE_IDENTIFIER_STRING];

#ifdef _WIN32
    LARGE_INTEGER   DriverVersion;            /* Defined for 32 bit components */
#else
    DWORD           DriverVersionLowPart;     /* Defined for 16 bit driver components */
    DWORD           DriverVersionHighPart;
#endif

    DWORD           VendorId;
    DWORD           DeviceId;
    DWORD           SubSysId;
    DWORD           Revision;

    GUID            DeviceIdentifier;

    DWORD           WHQLLevel;

} D3DADAPTER_IDENTIFIER8;

typedef struct _D3DADAPTER_IDENTIFIER9
{
    char            Driver[MAX_DEVICE_IDENTIFIER_STRING];
    char            Description[MAX_DEVICE_IDENTIFIER_STRING];

#ifdef _WIN32
    LARGE_INTEGER   DriverVersion;            /* Defined for 32 bit components */
#else
    DWORD           DriverVersionLowPart;     /* Defined for 16 bit driver components */
    DWORD           DriverVersionHighPart;
#endif

    DWORD           VendorId;
    DWORD           DeviceId;
    DWORD           SubSysId;
    DWORD           Revision;

    GUID            DeviceIdentifier;

    DWORD           WHQLLevel;

} D3DADAPTER_IDENTIFIER9;

typedef struct _D3DDEVICE_CREATION_PARAMETERS
{
    UINT            AdapterOrdinal;
    D3DDEVTYPE      DeviceType;
    HWND            hFocusWindow;
    DWORD           BehaviorFlags;
} _D3DDEVICE_CREATION_PARAMETERS;

typedef struct _D3DADAPTER_IDENTIFIER10
{
    char            Driver[MAX_DEVICE_IDENTIFIER_STRING];
    char            Description[MAX_DEVICE_IDENTIFIER_STRING];

#ifdef _WIN32
    LARGE_INTEGER   DriverVersion;            /* Defined for 32 bit components */
#else
    DWORD           DriverVersionLowPart;     /* Defined for 16 bit driver components */
    DWORD           DriverVersionHighPart;
#endif

    DWORD           VendorId;
    DWORD           DeviceId;
    DWORD           SubSysId;
    DWORD           Revision;

    GUID            DeviceIdentifier;

    DWORD           WHQLLevel;

} D3DADAPTER_IDENTIFIER10;

typedef struct _D3DADAPTER_IDENTIFIER11
{
    char            Driver[MAX_DEVICE_IDENTIFIER_STRING];
    char            Description[MAX_DEVICE_IDENTIFIER_STRING];

#ifdef _WIN32
    LARGE_INTEGER   DriverVersion;            /* Defined for 32 bit components */
#else
    DWORD           DriverVersionLowPart;     /* Defined for 16 bit driver components */
    DWORD           DriverVersionHighPart;
#endif

    DWORD           VendorId;
    DWORD           DeviceId;
    DWORD           SubSysId;
    DWORD           Revision;

    GUID            DeviceIdentifier;

    DWORD           WHQLLevel;

} D3DADAPTER_IDENTIFIER11;

/* Display Modes */
typedef struct _D3DDISPLAYMODE
{
    UINT            Width;
    UINT            Height;
    UINT            RefreshRate;
    D3DFORMAT       Format;
   
} D3DDISPLAYMODE;

/* Multi-Sample buffer types */
typedef enum _D3DMULTISAMPLE_TYPE
{
    D3DMULTISAMPLE_NONE            =  0,
    D3DMULTISAMPLE_2_SAMPLES       =  2,
    D3DMULTISAMPLE_3_SAMPLES       =  3,
    D3DMULTISAMPLE_4_SAMPLES       =  4,
    D3DMULTISAMPLE_5_SAMPLES       =  5,
    D3DMULTISAMPLE_6_SAMPLES       =  6,
    D3DMULTISAMPLE_7_SAMPLES       =  7,
    D3DMULTISAMPLE_8_SAMPLES       =  8,
    D3DMULTISAMPLE_9_SAMPLES       =  9,
    D3DMULTISAMPLE_10_SAMPLES      = 10,
    D3DMULTISAMPLE_11_SAMPLES      = 11,
    D3DMULTISAMPLE_12_SAMPLES      = 12,
    D3DMULTISAMPLE_13_SAMPLES      = 13,
    D3DMULTISAMPLE_14_SAMPLES      = 14,
    D3DMULTISAMPLE_15_SAMPLES      = 15,
    D3DMULTISAMPLE_16_SAMPLES      = 16,

    D3DMULTISAMPLE_FORCE_DWORD     = 0x7fffffff
} D3DMULTISAMPLE_TYPE;

/* SwapEffects */
typedef enum _D3DSWAPEFFECT
{
    D3DSWAPEFFECT_DISCARD           = 1,
    D3DSWAPEFFECT_FLIP              = 2,
    D3DSWAPEFFECT_COPY              = 3,
    D3DSWAPEFFECT_COPY_VSYNC        = 4,

    D3DSWAPEFFECT_FORCE_DWORD       = 0x7fffffff
} D3DSWAPEFFECT;

/* Resize Optional Parameters */
typedef struct _D3DPRESENT_PARAMETERS_
{
    UINT                BackBufferWidth;
    UINT                BackBufferHeight;
    D3DFORMAT           BackBufferFormat;
    UINT                BackBufferCount;

    D3DMULTISAMPLE_TYPE MultiSampleType;

    D3DSWAPEFFECT       SwapEffect;
    HWND                hDeviceWindow;
    BOOL                Windowed;
    BOOL                EnableAutoDepthStencil;
    D3DFORMAT           AutoDepthStencilFormat;
    DWORD               Flags;

    /* Following elements must be zero for Windowed mode */
    UINT                FullScreen_RefreshRateInHz;
    UINT                FullScreen_PresentationInterval;

} D3DPRESENT_PARAMETERS;
#define D3DADAPTER_DEFAULT                     0
#define D3DENUM_NO_WHQL_LEVEL                   0x00000002L



DECLARE_INTERFACE_(IDirect3D8, IUnknown)
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /*** IDirect3D8 methods ***/
    STDMETHOD(RegisterSoftwareDevice)(THIS_ void* pInitializeFunction) PURE;
    STDMETHOD_(UINT, GetAdapterCount)(THIS) PURE;
    STDMETHOD(GetAdapterIdentifier)(THIS_ UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER8 * pIdentifier) PURE;
    STDMETHOD_(UINT, GetAdapterModeCount)(THIS_ UINT Adapter) PURE;
    STDMETHOD(EnumAdapterModes)(THIS_ UINT Adapter, UINT Mode, D3DDISPLAYMODE * pMode) PURE;
    STDMETHOD(GetAdapterDisplayMode)(THIS_ UINT Adapter, D3DDISPLAYMODE * pMode) PURE;
    STDMETHOD(CheckDeviceType)(THIS_ UINT Adapter, D3DDEVTYPE CheckType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL Windowed) PURE;
    STDMETHOD(CheckDeviceFormat)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat) PURE;
    STDMETHOD(CheckDeviceMultiSampleType)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType) PURE;
    STDMETHOD(CheckDepthStencilMatch)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat) PURE;
    STDMETHOD(GetDeviceCaps)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9 * pCaps) PURE;
    STDMETHOD_(HMONITOR, GetAdapterMonitor)(THIS_ UINT Adapter) PURE;
    STDMETHOD(CreateDevice)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS * pPresentationParameters, IDirect3DDevice8 * *ppReturnedDeviceInterface) PURE;

    


};

DECLARE_INTERFACE_(IDirect3D9, IUnknown)
{

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;


    STDMETHOD(RegisterSoftwareDevice)(THIS_ void* pInitializeFunction) PURE;
    STDMETHOD_(UINT, GetAdapterCount)(THIS) PURE;
    STDMETHOD(GetAdapterIdentifier)(THIS_ UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER9 * pIdentifier) PURE;
    STDMETHOD_(UINT, GetAdapterModeCount)(THIS_ UINT Adapter) PURE;
    STDMETHOD(EnumAdapterModes)(THIS_ UINT Adapter, UINT Mode, D3DDISPLAYMODE * pMode) PURE;
    STDMETHOD(GetAdapterDisplayMode)(THIS_ UINT Adapter, D3DDISPLAYMODE * pMode) PURE;
    STDMETHOD(CheckDeviceType)(THIS_ UINT Adapter, D3DDEVTYPE CheckType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL Windowed) PURE;
    STDMETHOD(CheckDeviceFormat)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat) PURE;
    STDMETHOD(CheckDeviceMultiSampleType)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType) PURE;
    STDMETHOD(CheckDepthStencilMatch)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat) PURE;
    STDMETHOD(GetDeviceCaps)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9 * pCaps) PURE;
    STDMETHOD_(HMONITOR, GetAdapterMonitor)(THIS_ UINT Adapter) PURE;
    STDMETHOD(CreateDevice)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS * pPresentationParameters, IDirect3DDevice9 * *ppReturnedDeviceInterface) PURE;
};
DECLARE_INTERFACE_(IDirect3D10, IUnknown)
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /*** IDirect3D8 methods ***/
    STDMETHOD(RegisterSoftwareDevice)(THIS_ void* pInitializeFunction) PURE;
    STDMETHOD_(UINT, GetAdapterCount)(THIS) PURE;
    STDMETHOD(GetAdapterIdentifier)(THIS_ UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER10 * pIdentifier) PURE;
    STDMETHOD_(UINT, GetAdapterModeCount)(THIS_ UINT Adapter) PURE;
    STDMETHOD(EnumAdapterModes)(THIS_ UINT Adapter, UINT Mode, D3DDISPLAYMODE * pMode) PURE;
    STDMETHOD(GetAdapterDisplayMode)(THIS_ UINT Adapter, D3DDISPLAYMODE * pMode) PURE;
    STDMETHOD(CheckDeviceType)(THIS_ UINT Adapter, D3DDEVTYPE CheckType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL Windowed) PURE;
    STDMETHOD(CheckDeviceFormat)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat) PURE;
    STDMETHOD(CheckDeviceMultiSampleType)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType) PURE;
    STDMETHOD(CheckDepthStencilMatch)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat) PURE;
    STDMETHOD(GetDeviceCaps)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9 * pCaps) PURE;
    STDMETHOD_(HMONITOR, GetAdapterMonitor)(THIS_ UINT Adapter) PURE;
    STDMETHOD(CreateDevice)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS * pPresentationParameters, IDirect3DDevice10 * *ppReturnedDeviceInterface) PURE;


};

//copied from d3d10.h to compile for this interface...
typedef struct D3D10_RENDER_TARGET_BLEND_DESC1
{
    BOOL BlendEnable;
    D3D10_BLEND SrcBlend;
    D3D10_BLEND DestBlend;
    D3D10_BLEND_OP BlendOp;
    D3D10_BLEND SrcBlendAlpha;
    D3D10_BLEND DestBlendAlpha;
    D3D10_BLEND_OP BlendOpAlpha;
    UINT8 RenderTargetWriteMask;
} 	D3D10_RENDER_TARGET_BLEND_DESC1;

typedef struct D3D10_BLEND_DESC1
{
    BOOL AlphaToCoverageEnable;
    BOOL IndependentBlendEnable;
    D3D10_RENDER_TARGET_BLEND_DESC1 RenderTarget[8];
} 	D3D10_BLEND_DESC1;



extern RPC_IF_HANDLE __MIDL_itf_d3d10_1_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_d3d10_1_0000_0000_v0_0_s_ifspec;

#ifndef __ID3D10BlendState1_INTERFACE_DEFINED__
#define __ID3D10BlendState1_INTERFACE_DEFINED__

/* interface ID3D10BlendState1 */
/* [unique][local][object][uuid] */


EXTERN_C const IID IID_ID3D10BlendState1;

#if defined(__cplusplus) && !defined(CINTERFACE)

MIDL_INTERFACE("EDAD8D99-8A35-4d6d-8566-2EA276CDE161")
ID3D10BlendState1 : public ID3D10BlendState
{
public:
    virtual void STDMETHODCALLTYPE GetDesc1(
        /* [annotation] */
        _Out_  D3D10_BLEND_DESC1 * pDesc) = 0;

};
#endif
#endif

/*---------------------------------------------------------------------*/
typedef struct D3D10_TEXCUBE_ARRAY_SRV1
{
    UINT MostDetailedMip;
    UINT MipLevels;
    UINT First2DArrayFace;
    UINT NumCubes;
} 	D3D10_TEXCUBE_ARRAY_SRV1;

typedef D3D_SRV_DIMENSION D3D10_SRV_DIMENSION1;

typedef struct D3D10_SHADER_RESOURCE_VIEW_DESC1
{
    DXGI_FORMAT Format;
    D3D10_SRV_DIMENSION1 ViewDimension;
    union
    {
        D3D10_BUFFER_SRV Buffer;
        D3D10_TEX1D_SRV Texture1D;
        D3D10_TEX1D_ARRAY_SRV Texture1DArray;
        D3D10_TEX2D_SRV Texture2D;
        D3D10_TEX2D_ARRAY_SRV Texture2DArray;
        D3D10_TEX2DMS_SRV Texture2DMS;
        D3D10_TEX2DMS_ARRAY_SRV Texture2DMSArray;
        D3D10_TEX3D_SRV Texture3D;
        D3D10_TEXCUBE_SRV TextureCube;
        D3D10_TEXCUBE_ARRAY_SRV1 TextureCubeArray;
    };
} 	D3D10_SHADER_RESOURCE_VIEW_DESC1;



extern RPC_IF_HANDLE __MIDL_itf_d3d10_1_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_d3d10_1_0000_0001_v0_0_s_ifspec;

#ifndef __ID3D10ShaderResourceView1_INTERFACE_DEFINED__
#define __ID3D10ShaderResourceView1_INTERFACE_DEFINED__



/* interface ID3D10ShaderResourceView1 */
/* [unique][local][object][uuid] */


EXTERN_C const IID IID_ID3D10ShaderResourceView1;

#if defined(__cplusplus) && !defined(CINTERFACE)

MIDL_INTERFACE("9B7E4C87-342C-4106-A19F-4F2704F689F0")
ID3D10ShaderResourceView1 : public ID3D10ShaderResourceView
{
public:
    virtual void STDMETHODCALLTYPE GetDesc1(
        /* [annotation] */
        _Out_  D3D10_SHADER_RESOURCE_VIEW_DESC1 * pDesc) = 0;
#endif
#endif

DECLARE_INTERFACE_(IDirect3D11, IUnknown)
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /*** IDirect3D8 methods ***/
    STDMETHOD(RegisterSoftwareDevice)(THIS_ void* pInitializeFunction) PURE;
    STDMETHOD_(UINT, GetAdapterCount)(THIS) PURE;
    STDMETHOD(GetAdapterIdentifier)(THIS_ UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER11 * pIdentifier) PURE;
    STDMETHOD_(UINT, GetAdapterModeCount)(THIS_ UINT Adapter) PURE;
    STDMETHOD(EnumAdapterModes)(THIS_ UINT Adapter, UINT Mode, D3DDISPLAYMODE * pMode) PURE;
    STDMETHOD(GetAdapterDisplayMode)(THIS_ UINT Adapter, D3DDISPLAYMODE * pMode) PURE;
    STDMETHOD(CheckDeviceType)(THIS_ UINT Adapter, D3DDEVTYPE CheckType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL Windowed) PURE;
    STDMETHOD(CheckDeviceFormat)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat) PURE;
    STDMETHOD(CheckDeviceMultiSampleType)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType) PURE;
    STDMETHOD(CheckDepthStencilMatch)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat) PURE;
    STDMETHOD(GetDeviceCaps)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9 * pCaps) PURE;
    STDMETHOD_(HMONITOR, GetAdapterMonitor)(THIS_ UINT Adapter) PURE;
    STDMETHOD(CreateDevice)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS * pPresentationParameters, IDirect3DDevice11 * *ppReturnedDeviceInterface) PURE;
};
/*-----------------------------------------------------------------------------------------------------------------*/

HMODULE gD3D8Lib = nullptr;
HMODULE gD3D9Lib = nullptr;
HMODULE gD3D10Lib = nullptr;
HMODULE gD3D11Lib = nullptr;
LPDIRECT3D8 gD3D8 = nullptr;
LPDIRECT3D9 gD3D9 = nullptr;
LPDIRECT3D10 gD3D10 = nullptr;
LPDIRECT3D11 gD3D11 = nullptr;


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
static bool GetD3D8AdapterLibInfo(GUID &theGUID, std::string &theDriver, std::string &theDescription)
{
	gD3D8Lib = LoadLibraryA("d3d8.dll");
	if (gD3D8Lib==nullptr)
		return false;

	typedef IDirect3D8*(WINAPI *Direct3DCreate8Func)(UINT SDKVersion);
	Direct3DCreate8Func aDirect3DCreate8Func = (Direct3DCreate8Func)GetProcAddress(gD3D8Lib,"Direct3DCreate8");
	if (aDirect3DCreate8Func==nullptr)
		return false;

	gD3D8 = aDirect3DCreate8Func(D3D_SDK_VERSION);
	if (gD3D8==nullptr)
		return false;

	D3DADAPTER_IDENTIFIER8 aV11Id;
	ZeroMemory(&aV8Id,sizeof(aV8Id));
	HRESULT aResult = gD3D8->GetAdapterIdentifier(D3DADAPTER_DEFAULT,D3DENUM_NO_WHQL_LEVEL,&aV11Id);
	if (!SUCCEEDED(aResult))
		return false;

	theGUID = aV8Id.DeviceIdentifier;
	theDriver = aV8Id.Driver;
	theDescription= aV8Id.Description;
	return true;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
bool Sexy::GetD3D8AdapterInfo(GUID &theGUID, std::string &theDriver, std::string &theDescription)
{
	gD3D8 = nullptr;
	gD3D8Lib = nullptr;

	bool aResult = GetD3D8AdapterLibInfo(theGUID,theDriver,theDescription);

	if (gD3D8)
	{
		gD3D8->Release();
		gD3D8 = nullptr;
	}

	if (gD3D8Lib)
	{
		FreeLibrary(gD3D8Lib);
		gD3D8Lib = nullptr;
	}

	return aResult;
}
bool GetD3D9AdapterLibInfo(GUID& theGUID, std::string& theDriver, std::string& theDescription)
{

    gD3D9Lib = LoadLibraryA("d3d9.dll");
    if (gD3D9Lib == nullptr)
        return false;

    typedef IDirect3D9* (WINAPI* Direct3DCreate9Func)(UINT SDKVersion);
    Direct3DCreate9Func aDirect3DCreate9Func = (Direct3DCreate9Func)GetProcAddress(gD3D9Lib, "Direct3DCreate9");
    if (aDirect3DCreate9Func == nullptr)
        return false;

    gD3D9->AddRef();//replace "aDirect3DCreate8Func(D3D_SDK_VERSION)" with this...
    if (gD3D9 == nullptr)
        return false;

    D3DADAPTER_IDENTIFIER9 aV9Id;
    ZeroMemory(&aV9Id, sizeof(aV9Id));
    HRESULT aResult = gD3D9->GetAdapterIdentifier(D3DADAPTER_DEFAULT, D3DENUM_NO_WHQL_LEVEL, &aV9Id);
    if (!SUCCEEDED(aResult))
        return false;

    theGUID = aV9Id.DeviceIdentifier;
    theDriver = aV9Id.Driver;
    theDescription = aV9Id.Description;
    return true;

}
bool Sexy::GetD3D9AdapterInfo(GUID& theGUID, std::string& theDriver, std::string& theDescription)
{
    gD3D9 = nullptr;
    gD3D9Lib = nullptr;

    bool aResult = GetD3D9AdapterLibInfo(theGUID, theDriver, theDescription);

    if (gD3D9)
    {
        gD3D9->Release();
        gD3D9 = nullptr;
    }

    if (gD3D9Lib)
    {
        FreeLibrary(gD3D9Lib);
        gD3D9Lib = nullptr;
    }

    return aResult;
}
bool GetD3D10AdapterLibInfo(GUID& theGUID, std::string& theDriver, std::string& theDescription)
{

    gD3D10Lib = LoadLibraryA("d3d10.dll");
    if (gD3D10Lib == nullptr)
        return false;

    typedef IDirect3D10* (WINAPI* Direct3DCreate10Func)(UINT SDKVersion);
    Direct3DCreate10Func aDirect3DCreate10Func = (Direct3DCreate10Func)GetProcAddress(gD3D10Lib, "Direct3DCreate10");
    if (aDirect3DCreate10Func == nullptr)
        return false;

    gD3D10->AddRef();//replace "aDirect3DCreate8Func(D3D_SDK_VERSION)" with this... for v10..
    if (gD3D10 == nullptr)
        return false;

    D3DADAPTER_IDENTIFIER10 aV10Id;
    ZeroMemory(&aV10Id, sizeof(aV10Id));
    HRESULT aResult = gD3D10->GetAdapterIdentifier(D3DADAPTER_DEFAULT, D3DENUM_NO_WHQL_LEVEL, &aV10Id);
    if (!SUCCEEDED(aResult))
        return false;

    theGUID = aV10Id.DeviceIdentifier;
    theDriver = aV10Id.Driver;
    theDescription = aV10Id.Description;
    return true;

}
bool Sexy::GetD3D10AdapterInfo(GUID& theGUID, std::string& theDriver, std::string& theDescription)
{
    gD3D10 = nullptr;
    gD3D10Lib = nullptr;

    bool aResult = GetD3D10AdapterLibInfo(theGUID, theDriver, theDescription);

    if (gD3D10)
    {
        gD3D10->Release();
        gD3D10 = nullptr;
    }

    if (gD3D10Lib)
    {
        FreeLibrary(gD3D10Lib);
        gD3D10Lib = nullptr;
    }

    return aResult;
}
bool GetD3D11AdapterLibInfo(GUID& theGUID, std::string& theDriver, std::string& theDescription)
{

    gD3D11Lib = LoadLibraryA("d3d11.dll");
    if (gD3D11Lib == nullptr)
        return false;

    typedef IDirect3D11* (WINAPI* Direct3DCreate11Func)(UINT SDKVersion);
    Direct3DCreate11Func aDirect3DCreate11Func = (Direct3DCreate11Func)GetProcAddress(gD3D11Lib, "Direct3DCreate11");
    if (aDirect3DCreate11Func == nullptr)
        return false;

    gD3D11->AddRef();//replace "aDirect3DCreate8Func(D3D_SDK_VERSION)" with this...for v11
    if (gD3D11 == nullptr)
        return false;

    D3DADAPTER_IDENTIFIER11 aV11Id;
    ZeroMemory(&aV11Id, sizeof(aV11Id));
    HRESULT aResult = gD3D11->GetAdapterIdentifier(D3DADAPTER_DEFAULT, D3DENUM_NO_WHQL_LEVEL, &aV11Id);
    if (!SUCCEEDED(aResult))
        return false;

    theGUID = aV11Id.DeviceIdentifier;
    theDriver = aV11Id.Driver;
    theDescription = aV11Id.Description;
    return true;

}
bool Sexy::GetD3D11AdapterInfo(GUID& theGUID, std::string& theDriver, std::string& theDescription)
{
    gD3D11 = nullptr;
    gD3D11Lib = nullptr;

    bool aResult = GetD3D11AdapterLibInfo(theGUID, theDriver, theDescription);

    if (gD3D11)
    {
        gD3D11->Release();
        gD3D11 = nullptr;
    }

    if (gD3D11Lib)
    {
        FreeLibrary(gD3D11Lib);
        gD3D11Lib = nullptr;
    }

    return aResult;
}
