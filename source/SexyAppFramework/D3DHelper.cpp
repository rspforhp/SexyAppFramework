// This has to be its own file because d3d8.h and d3d.h conflict
#undef DIRECT3D_VERSION
#include <windows.h>

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// This stuff is copied from d3d8.h because you can't include both d3d.h and d3d8.h in a project

#include <combaseapi.h>
#include <ddraw.h>
#define D3D_SDK_VERSION (32 | 0x80000000) //changed from 220 to the actual one...
DEFINE_GUID(IID_IDirect3D8, 0x1dd9e8da, 0x1c77, 0x4d40, 0xb0, 0xcf, 0x98, 0xfe, 0xfd, 0xff, 0x95, 0x12);

//Helper GUIDs
DEFINE_GUID(IID_IDirect3D9, 0x81bdcbca, 0x64d4, 0x426d, 0xae, 0x8d, 0xad, 0x1, 0x47, 0xf4, 0x27, 0x5c);
//apparently there are WAY too many GUIDs for d3d10 but we'll include them here....

DEFINE_GUID(IID_ID3D10Device1, 0x9B7E4C8F, 0x342C, 0x4106, 0xA1, 0x9F, 0x4F, 0x27, 0x04, 0xF6, 0x89, 0xF0);
DEFINE_GUID(IID_ID3D10BlendState1, 0xEDAD8D99, 0x8A35, 0x4d6d, 0x85, 0x66, 0x2E, 0xA2, 0x76, 0xCD, 0xE1, 0x61);
DEFINE_GUID(IID_ID3D10ShaderResourceView1, 0x9B7E4C87, 0x342C, 0x4106, 0xA1, 0x9F, 0x4F, 0x27, 0x04, 0xF6, 0x89, 0xF0);
DEFINE_GUID(IID_ID3D10DeviceChild, 0x9B7E4C00, 0x342C, 0x4106, 0xA1, 0x9F, 0x4F, 0x27, 0x04, 0xF6, 0x89, 0xF0);
DEFINE_GUID(IID_ID3D10DepthStencilState, 0x2B4B1CC8, 0xA4AD, 0x41f8, 0x83, 0x22, 0xCA, 0x86, 0xFC, 0x3E, 0xC6, 0x75);
DEFINE_GUID(IID_ID3D10BlendState, 0xEDAD8D19, 0x8A35, 0x4d6d, 0x85, 0x66, 0x2E, 0xA2, 0x76, 0xCD, 0xE1, 0x61);
DEFINE_GUID(IID_ID3D10RasterizerState, 0xA2A07292, 0x89AF, 0x4345, 0xBE, 0x2E, 0xC5, 0x3D, 0x9F, 0xBB, 0x6E, 0x9F);
DEFINE_GUID(IID_ID3D10Resource, 0x9B7E4C01, 0x342C, 0x4106, 0xA1, 0x9F, 0x4F, 0x27, 0x04, 0xF6, 0x89, 0xF0);
DEFINE_GUID(IID_ID3D10Buffer, 0x9B7E4C02, 0x342C, 0x4106, 0xA1, 0x9F, 0x4F, 0x27, 0x04, 0xF6, 0x89, 0xF0);
DEFINE_GUID(IID_ID3D10Texture1D, 0x9B7E4C03, 0x342C, 0x4106, 0xA1, 0x9F, 0x4F, 0x27, 0x04, 0xF6, 0x89, 0xF0);
DEFINE_GUID(IID_ID3D10Texture2D, 0x9B7E4C04, 0x342C, 0x4106, 0xA1, 0x9F, 0x4F, 0x27, 0x04, 0xF6, 0x89, 0xF0);
DEFINE_GUID(IID_ID3D10Texture3D, 0x9B7E4C05, 0x342C, 0x4106, 0xA1, 0x9F, 0x4F, 0x27, 0x04, 0xF6, 0x89, 0xF0);
DEFINE_GUID(IID_ID3D10View, 0xC902B03F, 0x60A7, 0x49BA, 0x99, 0x36, 0x2A, 0x3A, 0xB3, 0x7A, 0x7E, 0x33);
DEFINE_GUID(IID_ID3D10ShaderResourceView, 0x9B7E4C07, 0x342C, 0x4106, 0xA1, 0x9F, 0x4F, 0x27, 0x04, 0xF6, 0x89, 0xF0);
DEFINE_GUID(IID_ID3D10RenderTargetView, 0x9B7E4C08, 0x342C, 0x4106, 0xA1, 0x9F, 0x4F, 0x27, 0x04, 0xF6, 0x89, 0xF0);
DEFINE_GUID(IID_ID3D10DepthStencilView, 0x9B7E4C09, 0x342C, 0x4106, 0xA1, 0x9F, 0x4F, 0x27, 0x04, 0xF6, 0x89, 0xF0);
DEFINE_GUID(IID_ID3D10VertexShader, 0x9B7E4C0A, 0x342C, 0x4106, 0xA1, 0x9F, 0x4F, 0x27, 0x04, 0xF6, 0x89, 0xF0);
DEFINE_GUID(IID_ID3D10GeometryShader, 0x6316BE88, 0x54CD, 0x4040, 0xAB, 0x44, 0x20, 0x46, 0x1B, 0xC8, 0x1F, 0x68);
DEFINE_GUID(IID_ID3D10PixelShader, 0x4968B601, 0x9D00, 0x4cde, 0x83, 0x46, 0x8E, 0x7F, 0x67, 0x58, 0x19, 0xB6);
DEFINE_GUID(IID_ID3D10InputLayout, 0x9B7E4C0B, 0x342C, 0x4106, 0xA1, 0x9F, 0x4F, 0x27, 0x04, 0xF6, 0x89, 0xF0);
DEFINE_GUID(IID_ID3D10SamplerState, 0x9B7E4C0C, 0x342C, 0x4106, 0xA1, 0x9F, 0x4F, 0x27, 0x04, 0xF6, 0x89, 0xF0);
DEFINE_GUID(IID_ID3D10Asynchronous, 0x9B7E4C0D, 0x342C, 0x4106, 0xA1, 0x9F, 0x4F, 0x27, 0x04, 0xF6, 0x89, 0xF0);
DEFINE_GUID(IID_ID3D10Query, 0x9B7E4C0E, 0x342C, 0x4106, 0xA1, 0x9F, 0x4F, 0x27, 0x04, 0xF6, 0x89, 0xF0);
DEFINE_GUID(IID_ID3D10Predicate, 0x9B7E4C10, 0x342C, 0x4106, 0xA1, 0x9F, 0x4F, 0x27, 0x04, 0xF6, 0x89, 0xF0);
DEFINE_GUID(IID_ID3D10Counter, 0x9B7E4C11, 0x342C, 0x4106, 0xA1, 0x9F, 0x4F, 0x27, 0x04, 0xF6, 0x89, 0xF0);
DEFINE_GUID(IID_ID3D10Device, 0x9B7E4C0F, 0x342C, 0x4106, 0xA1, 0x9F, 0x4F, 0x27, 0x04, 0xF6, 0x89, 0xF0);
DEFINE_GUID(IID_ID3D10Multithread, 0x9B7E4E00, 0x342C, 0x4106, 0xA1, 0x9F, 0x4F, 0x27, 0x04, 0xF6, 0x89, 0xF0);
//apparently there are WAY too many GUIDs for d3d11 but we'll include them here....

DEFINE_GUID(IID_ID3D11DeviceChild, 0x1841e5c8, 0x16b0, 0x489b, 0xbc, 0xc8, 0x44, 0xcf, 0xb0, 0xd5, 0xde, 0xae);
DEFINE_GUID(IID_ID3D11DepthStencilState, 0x03823efb, 0x8d8f, 0x4e1c, 0x9a, 0xa2, 0xf6, 0x4b, 0xb2, 0xcb, 0xfd, 0xf1);
DEFINE_GUID(IID_ID3D11BlendState, 0x75b68faa, 0x347d, 0x4159, 0x8f, 0x45, 0xa0, 0x64, 0x0f, 0x01, 0xcd, 0x9a);
DEFINE_GUID(IID_ID3D11RasterizerState, 0x9bb4ab81, 0xab1a, 0x4d8f, 0xb5, 0x06, 0xfc, 0x04, 0x20, 0x0b, 0x6e, 0xe7);
DEFINE_GUID(IID_ID3D11Resource, 0xdc8e63f3, 0xd12b, 0x4952, 0xb4, 0x7b, 0x5e, 0x45, 0x02, 0x6a, 0x86, 0x2d);
DEFINE_GUID(IID_ID3D11Buffer, 0x48570b85, 0xd1ee, 0x4fcd, 0xa2, 0x50, 0xeb, 0x35, 0x07, 0x22, 0xb0, 0x37);
DEFINE_GUID(IID_ID3D11Texture1D, 0xf8fb5c27, 0xc6b3, 0x4f75, 0xa4, 0xc8, 0x43, 0x9a, 0xf2, 0xef, 0x56, 0x4c);
DEFINE_GUID(IID_ID3D11Texture2D, 0x6f15aaf2, 0xd208, 0x4e89, 0x9a, 0xb4, 0x48, 0x95, 0x35, 0xd3, 0x4f, 0x9c);
DEFINE_GUID(IID_ID3D11Texture3D, 0x037e866e, 0xf56d, 0x4357, 0xa8, 0xaf, 0x9d, 0xab, 0xbe, 0x6e, 0x25, 0x0e);
DEFINE_GUID(IID_ID3D11View, 0x839d1216, 0xbb2e, 0x412b, 0xb7, 0xf4, 0xa9, 0xdb, 0xeb, 0xe0, 0x8e, 0xd1);
DEFINE_GUID(IID_ID3D11ShaderResourceView, 0xb0e06fe0, 0x8192, 0x4e1a, 0xb1, 0xca, 0x36, 0xd7, 0x41, 0x47, 0x10, 0xb2);
DEFINE_GUID(IID_ID3D11RenderTargetView, 0xdfdba067, 0x0b8d, 0x4865, 0x87, 0x5b, 0xd7, 0xb4, 0x51, 0x6c, 0xc1, 0x64);
DEFINE_GUID(IID_ID3D11DepthStencilView, 0x9fdac92a, 0x1876, 0x48c3, 0xaf, 0xad, 0x25, 0xb9, 0x4f, 0x84, 0xa9, 0xb6);
DEFINE_GUID(IID_ID3D11UnorderedAccessView, 0x28acf509, 0x7f5c, 0x48f6, 0x86, 0x11, 0xf3, 0x16, 0x01, 0x0a, 0x63, 0x80);
DEFINE_GUID(IID_ID3D11VertexShader, 0x3b301d64, 0xd678, 0x4289, 0x88, 0x97, 0x22, 0xf8, 0x92, 0x8b, 0x72, 0xf3);
DEFINE_GUID(IID_ID3D11HullShader, 0x8e5c6061, 0x628a, 0x4c8e, 0x82, 0x64, 0xbb, 0xe4, 0x5c, 0xb3, 0xd5, 0xdd);
DEFINE_GUID(IID_ID3D11DomainShader, 0xf582c508, 0x0f36, 0x490c, 0x99, 0x77, 0x31, 0xee, 0xce, 0x26, 0x8c, 0xfa);
DEFINE_GUID(IID_ID3D11GeometryShader, 0x38325b96, 0xeffb, 0x4022, 0xba, 0x02, 0x2e, 0x79, 0x5b, 0x70, 0x27, 0x5c);
DEFINE_GUID(IID_ID3D11PixelShader, 0xea82e40d, 0x51dc, 0x4f33, 0x93, 0xd4, 0xdb, 0x7c, 0x91, 0x25, 0xae, 0x8c);
DEFINE_GUID(IID_ID3D11ComputeShader, 0x4f5b196e, 0xc2bd, 0x495e, 0xbd, 0x01, 0x1f, 0xde, 0xd3, 0x8e, 0x49, 0x69);
DEFINE_GUID(IID_ID3D11InputLayout, 0xe4819ddc, 0x4cf0, 0x4025, 0xbd, 0x26, 0x5d, 0xe8, 0x2a, 0x3e, 0x07, 0xb7);
DEFINE_GUID(IID_ID3D11SamplerState, 0xda6fea51, 0x564c, 0x4487, 0x98, 0x10, 0xf0, 0xd0, 0xf9, 0xb4, 0xe3, 0xa5);
DEFINE_GUID(IID_ID3D11Asynchronous, 0x4b35d0cd, 0x1e15, 0x4258, 0x9c, 0x98, 0x1b, 0x13, 0x33, 0xf6, 0xdd, 0x3b);
DEFINE_GUID(IID_ID3D11Query, 0xd6c00747, 0x87b7, 0x425e, 0xb8, 0x4d, 0x44, 0xd1, 0x08, 0x56, 0x0a, 0xfd);
DEFINE_GUID(IID_ID3D11Predicate, 0x9eb576dd, 0x9f77, 0x4d86, 0x81, 0xaa, 0x8b, 0xab, 0x5f, 0xe4, 0x90, 0xe2);
DEFINE_GUID(IID_ID3D11Counter, 0x6e8c49fb, 0xa371, 0x4770, 0xb4, 0x40, 0x29, 0x08, 0x60, 0x22, 0xb7, 0x41);
DEFINE_GUID(IID_ID3D11ClassInstance, 0xa6cd7faa, 0xb0b7, 0x4a2f, 0x94, 0x36, 0x86, 0x62, 0xa6, 0x57, 0x97, 0xcb);
DEFINE_GUID(IID_ID3D11ClassLinkage, 0xddf57cba, 0x9543, 0x46e4, 0xa1, 0x2b, 0xf2, 0x07, 0xa0, 0xfe, 0x7f, 0xed);
DEFINE_GUID(IID_ID3D11CommandList, 0xa24bc4d1, 0x769e, 0x43f7, 0x80, 0x13, 0x98, 0xff, 0x56, 0x6c, 0x18, 0xe2);
DEFINE_GUID(IID_ID3D11DeviceContext, 0xc0bfa96c, 0xe089, 0x44fb, 0x8e, 0xaf, 0x26, 0xf8, 0x79, 0x61, 0x90, 0xda);
DEFINE_GUID(IID_ID3D11VideoDecoder, 0x3C9C5B51, 0x995D, 0x48d1, 0x9B, 0x8D, 0xFA, 0x5C, 0xAE, 0xDE, 0xD6, 0x5C);
DEFINE_GUID(IID_ID3D11VideoProcessorEnumerator, 0x31627037, 0x53AB, 0x4200, 0x90, 0x61, 0x05, 0xFA, 0xA9, 0xAB, 0x45, 0xF9);
DEFINE_GUID(IID_ID3D11VideoProcessor, 0x1D7B0652, 0x185F, 0x41c6, 0x85, 0xCE, 0x0C, 0x5B, 0xE3, 0xD4, 0xAE, 0x6C);
DEFINE_GUID(IID_ID3D11AuthenticatedChannel, 0x3015A308, 0xDCBD, 0x47aa, 0xA7, 0x47, 0x19, 0x24, 0x86, 0xD1, 0x4D, 0x4A);
DEFINE_GUID(IID_ID3D11CryptoSession, 0x9B32F9AD, 0xBDCC, 0x40a6, 0xA3, 0x9D, 0xD5, 0xC8, 0x65, 0x84, 0x57, 0x20);
DEFINE_GUID(IID_ID3D11VideoDecoderOutputView, 0xC2931AEA, 0x2A85, 0x4f20, 0x86, 0x0F, 0xFB, 0xA1, 0xFD, 0x25, 0x6E, 0x18);
DEFINE_GUID(IID_ID3D11VideoProcessorInputView, 0x11EC5A5F, 0x51DC, 0x4945, 0xAB, 0x34, 0x6E, 0x8C, 0x21, 0x30, 0x0E, 0xA5);
DEFINE_GUID(IID_ID3D11VideoProcessorOutputView, 0xA048285E, 0x25A9, 0x4527, 0xBD, 0x93, 0xD6, 0x8B, 0x68, 0xC4, 0x42, 0x54);
DEFINE_GUID(IID_ID3D11VideoContext, 0x61F21C45, 0x3C0E, 0x4a74, 0x9C, 0xEA, 0x67, 0x10, 0x0D, 0x9A, 0xD5, 0xE4);
DEFINE_GUID(IID_ID3D11VideoDevice, 0x10EC4D5B, 0x975A, 0x4689, 0xB9, 0xE4, 0xD0, 0xAA, 0xC3, 0x0F, 0xE3, 0x33);
DEFINE_GUID(IID_ID3D11Device, 0xdb6f6ddb, 0xac77, 0x4e88, 0x82, 0x53, 0x81, 0x9d, 0xf9, 0xbb, 0xf1, 0x40);
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
    STDMETHOD(CreateDevice)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS * pPresentationParameters, IDirect3DDevice8 * *ppReturnedDeviceInterface) PURE;
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
    STDMETHOD(CreateDevice)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS * pPresentationParameters, IDirect3DDevice8 * *ppReturnedDeviceInterface) PURE;


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
    STDMETHOD(CreateDevice)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS * pPresentationParameters, IDirect3DDevice8 * *ppReturnedDeviceInterface) PURE;
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
	ZeroMemory(&aV11Id,sizeof(aV11Id));
	HRESULT aResult = gD3D8->GetAdapterIdentifier(D3DADAPTER_DEFAULT,D3DENUM_NO_WHQL_LEVEL,&aV11Id);
	if (!SUCCEEDED(aResult))
		return false;

	theGUID = aV11Id.DeviceIdentifier;
	theDriver = aV11Id.Driver;
	theDescription= aV11Id.Description;
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