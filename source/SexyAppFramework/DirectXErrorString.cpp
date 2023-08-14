#include "DirectXErrorString.h"

#include <d3d.h>
#include <ddraw.h>
#include "dsoundversion.h"

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
std::string Sexy::GetDirectXErrorString(HRESULT theResult)
{
	switch (theResult)
	{
	case DSERR_ALLOCATED: return "DSERR_ALLOCATED";
	case DSERR_ALREADYINITIALIZED: return "DSERR_ALREADYINITIALIZED";
	case DSERR_BADFORMAT: return "DSERR_BADFORMAT";
	case DSERR_BUFFERLOST: return "DSERR_BUFFERLOST";
	case DSERR_CONTROLUNAVAIL: return "DSERR_CONTROLUNAVAIL";
	case DSERR_GENERIC: return "DSERR_GENERIC";
	case DSERR_INVALIDCALL: return "DSERR_INVALIDCALL";
		//		case DSERR_INVALIDPARAM: return "DSERR_INVALIDPARAM";
	case DSERR_NOAGGREGATION: return "DSERR_NOAGGREGATION";
	case DSERR_NODRIVER: return "DSERR_NODRIVER";
	case DSERR_NOINTERFACE: return "DSERR_NOINTERFACE";
	case DSERR_OTHERAPPHASPRIO: return "DSERR_OTHERAPPHASPRIO";
		//		case DSERR_OUTOFMEMORY: return "DSERR_OUTOFMEMORY";
	case DSERR_PRIOLEVELNEEDED: return "DSERR_PRIOLEVELNEEDED";
	case DSERR_UNINITIALIZED: return "DSERR_UNINITIALIZED";
		//		case DSERR_UNSUPPORTED: return "DSERR_UNSUPPORTED";

	case DDERR_ALREADYINITIALIZED: return "DDERR_ALREADYINITIALIZED";
	case DDERR_BLTFASTCANTCLIP: return "DDERR_BLTFASTCANTCLIP";
	case DDERR_CANNOTATTACHSURFACE: return "DDERR_CANNOTATTACHSURFACE";
	case DDERR_CANNOTDETACHSURFACE: return "DDERR_CANNOTDETACHSURFACE";
	case DDERR_CANTCREATEDC: return "DDERR_CANTCREATEDC";
	case DDERR_CANTDUPLICATE: return "DDERR_CANTDUPLICATE";
	case DDERR_CANTLOCKSURFACE: return "DDERR_CANTLOCKSURFACE";
	case DDERR_CANTPAGELOCK: return "DDERR_CANTPAGELOCK";
	case DDERR_CANTPAGEUNLOCK: return "DDERR_CANTPAGEUNLOCK";
	case DDERR_CLIPPERISUSINGHWND: return "DDERR_CLIPPERISUSINGHWND";
	case DDERR_COLORKEYNOTSET: return "DDERR_COLORKEYNOTSET";
	case DDERR_CURRENTLYNOTAVAIL: return "DDERR_CURRENTLYNOTAVAIL";
	case DDERR_DCALREADYCREATED: return "DDERR_DCALREADYCREATED";
	case DDERR_DEVICEDOESNTOWNSURFACE: return "DDERR_DEVICEDOESNTOWNSURFACE";
	case DDERR_DIRECTDRAWALREADYCREATED: return "DDERR_DIRECTDRAWALREADYCREATED";
	case DDERR_EXCEPTION: return "DDERR_EXCEPTION";
	case DDERR_EXCLUSIVEMODEALREADYSET: return "DDERR_EXCLUSIVEMODEALREADYSET";
	case DDERR_EXPIRED: return "DDERR_EXPIRED";
	case DDERR_HEIGHTALIGN: return "DDERR_HEIGHTALIGN";
	case DDERR_HWNDALREADYSET: return "DDERR_HWNDALREADYSET";
	case DDERR_HWNDSUBCLASSED: return "DDERR_HWNDSUBCLASSED";
	case DDERR_IMPLICITLYCREATED: return "DDERR_IMPLICITLYCREATED";
	case DDERR_INCOMPATIBLEPRIMARY: return "DDERR_INCOMPATIBLEPRIMARY";
	case DDERR_INVALIDCAPS: return "DDERR_INVALIDCAPS";
	case DDERR_INVALIDCLIPLIST: return "DDERR_INVALIDCLIPLIST";
	case DDERR_INVALIDDIRECTDRAWGUID: return "DDERR_INVALIDDIRECTDRAWGUID";
	case DDERR_INVALIDMODE: return "DDERR_INVALIDMODE";
	case DDERR_INVALIDOBJECT: return "DDERR_INVALIDOBJECT";
	case DDERR_INVALIDPARAMS: return "DDERR_INVALIDPARAMS";
	case DDERR_INVALIDPIXELFORMAT: return "DDERR_INVALIDPIXELFORMAT";
	case DDERR_INVALIDPOSITION: return "DDERR_INVALIDPOSITION";
	case DDERR_INVALIDRECT: return "DDERR_INVALIDRECT";
	case DDERR_INVALIDSTREAM: return "DDERR_INVALIDSTREAM";
	case DDERR_INVALIDSURFACETYPE: return "DDERR_INVALIDSURFACETYPE";
	case DDERR_LOCKEDSURFACES: return "DDERR_LOCKEDSURFACES";
	case DDERR_MOREDATA: return "DDERR_MOREDATA";
	case DDERR_NO3D: return "DDERR_NO3D";
	case DDERR_NOALPHAHW: return "DDERR_NOALPHAHW";
	case DDERR_NOBLTHW: return "DDERR_NOBLTHW";
	case DDERR_NOCLIPLIST: return "DDERR_NOCLIPLIST";
	case DDERR_NOCLIPPERATTACHED: return "DDERR_NOCLIPPERATTACHED";
	case DDERR_NOCOLORCONVHW: return "DDERR_NOCOLORCONVHW";
	case DDERR_NOCOLORKEY: return "DDERR_NOCOLORKEY";
	case DDERR_NOCOLORKEYHW: return "DDERR_NOCOLORKEYHW";
	case DDERR_NOCOOPERATIVELEVELSET: return "DDERR_NOCOOPERATIVELEVELSET";
	case DDERR_NODC: return "DDERR_NODC";
	case DDERR_NODDROPSHW: return "DDERR_NODDROPSHW";
	case DDERR_NODIRECTDRAWHW: return "DDERR_NODIRECTDRAWHW";
	case DDERR_NODIRECTDRAWSUPPORT: return "DDERR_NODIRECTDRAWSUPPORT";
	case DDERR_NOEMULATION: return "DDERR_NOEMULATION";
	case DDERR_NOEXCLUSIVEMODE: return "DDERR_NOEXCLUSIVEMODE";
	case DDERR_NOFLIPHW: return "DDERR_NOFLIPHW";
	case DDERR_NOFOCUSWINDOW: return "DDERR_NOFOCUSWINDOW";
	case DDERR_NOGDI: return "DDERR_NOGDI";
	case DDERR_NOHWND: return "DDERR_NOHWND";
	case DDERR_NOMIPMAPHW: return "DDERR_NOMIPMAPHW";
	case DDERR_NOMIRRORHW: return "DDERR_NOMIRRORHW";
	case DDERR_NONONLOCALVIDMEM: return "DDERR_NONONLOCALVIDMEM";
	case DDERR_NOOPTIMIZEHW: return "DDERR_NOOPTIMIZEHW";
	case DDERR_NOOVERLAYHW: return "DDERR_NOOVERLAYHW";
	case DDERR_NOPALETTEATTACHED: return "DDERR_NOPALETTEATTACHED";
	case DDERR_NOPALETTEHW: return "DDERR_NOPALETTEHW";
	case DDERR_NORASTEROPHW: return "DDERR_NORASTEROPHW";
	case DDERR_NOROTATIONHW: return "DDERR_NOROTATIONHW";
	case DDERR_NOSTEREOHARDWARE: return "DDERR_NOSTEREOHARDWARE";
	case DDERR_NOSTRETCHHW: return "DDERR_NOSTRETCHHW";
	case DDERR_NOSURFACELEFT: return "DDERR_NOSURFACELEFT";
	case DDERR_NOT4BITCOLOR: return "DDERR_NOT4BITCOLOR";
	case DDERR_NOT4BITCOLORINDEX: return "DDERR_NOT4BITCOLORINDEX";
	case DDERR_NOT8BITCOLOR: return "DDERR_NOT8BITCOLOR";
	case DDERR_NOTAOVERLAYSURFACE: return "DDERR_NOTAOVERLAYSURFACE";
	case DDERR_NOTEXTUREHW: return "DDERR_NOTEXTUREHW";
	case DDERR_NOTFLIPPABLE: return "DDERR_NOTFLIPPABLE";
	case DDERR_NOTFOUND: return "DDERR_NOTFOUND";
	case DDERR_NOTINITIALIZED: return "DDERR_NOTINITIALIZED";
	case DDERR_NOTLOADED: return "DDERR_NOTLOADED";
	case DDERR_NOTLOCKED: return "DDERR_NOTLOCKED";
	case DDERR_NOTPAGELOCKED: return "DDERR_NOTPAGELOCKED";
	case DDERR_NOTPALETTIZED: return "DDERR_NOTPALETTIZED";
	case DDERR_NOVSYNCHW: return "DDERR_NOVSYNCHW";
	case DDERR_NOZBUFFERHW: return "DDERR_NOZBUFFERHW";
	case DDERR_NOZOVERLAYHW: return "DDERR_NOZOVERLAYHW";
	case DDERR_OUTOFCAPS: return "DDERR_OUTOFCAPS";
		//		case DDERR_OUTOFMEMORY: return "DDERR_OUTOFMEMORY";
	case DDERR_OUTOFVIDEOMEMORY: return "DDERR_OUTOFVIDEOMEMORY";
	case DDERR_OVERLAPPINGRECTS: return "DDERR_OVERLAPPINGRECTS";
	case DDERR_OVERLAYCANTCLIP: return "DDERR_OVERLAYCANTCLIP";
	case DDERR_OVERLAYCOLORKEYONLYONEACTIVE: return "DDERR_OVERLAYCOLORKEYONLYONEACTIVE";
	case DDERR_OVERLAYNOTVISIBLE: return "DDERR_OVERLAYNOTVISIBLE";
	case DDERR_PALETTEBUSY: return "DDERR_PALETTEBUSY";
	case DDERR_PRIMARYSURFACEALREADYEXISTS: return "DDERR_PRIMARYSURFACEALREADYEXISTS";
	case DDERR_REGIONTOOSMALL: return "DDERR_REGIONTOOSMALL";
	case DDERR_SURFACEALREADYATTACHED: return "DDERR_SURFACEALREADYATTACHED";
	case DDERR_SURFACEALREADYDEPENDENT: return "DDERR_SURFACEALREADYDEPENDENT";
	case DDERR_SURFACEBUSY: return "DDERR_SURFACEBUSY";
	case DDERR_SURFACEISOBSCURED: return "DDERR_SURFACEISOBSCURED";
	case DDERR_SURFACELOST: return "DDERR_SURFACELOST";
	case DDERR_SURFACENOTATTACHED: return "DDERR_SURFACENOTATTACHED";
	case DDERR_TOOBIGHEIGHT: return "DDERR_TOOBIGHEIGHT";
	case DDERR_TOOBIGSIZE: return "DDERR_TOOBIGSIZE";
	case DDERR_TOOBIGWIDTH: return "DDERR_TOOBIGWIDTH";
	case DDERR_UNSUPPORTED: return "DDERR_UNSUPPORTED";
	case DDERR_UNSUPPORTEDFORMAT: return "DDERR_UNSUPPORTEDFORMAT";
	case DDERR_UNSUPPORTEDMASK: return "DDERR_UNSUPPORTEDMASK";
	case DDERR_UNSUPPORTEDMODE: return "DDERR_UNSUPPORTEDMODE";
	case DDERR_VERTICALBLANKINPROGRESS: return "DDERR_VERTICALBLANKINPROGRESS";
	case DDERR_VIDEONOTACTIVE: return "DDERR_VIDEONOTACTIVE";
	case DDERR_WASSTILLDRAWING: return "DDERR_WASSTILLDRAWING";
	case DDERR_WRONGMODE: return "DDERR_WRONGMODE";
	case DDERR_XALIGN: return "DDERR_XALIGN";

	case D3DERR_BADMAJORVERSION: return "D3DERR_BADMAJORVERSION";
	case D3DERR_BADMINORVERSION: return "D3DERR_BADMINORVERSION";
	case D3DERR_COLORKEYATTACHED: return "D3DERR_COLORKEYATTACHED";
	case D3DERR_CONFLICTINGTEXTUREFILTER: return "D3DERR_CONFLICTINGTEXTUREFILTER";
	case D3DERR_CONFLICTINGTEXTUREPALETTE: return "D3DERR_CONFLICTINGTEXTUREPALETTE";
	case D3DERR_CONFLICTINGRENDERSTATE: return "D3DERR_CONFLICTINGRENDERSTATE";
	case D3DERR_DEVICEAGGREGATED: return "D3DERR_DEVICEAGGREGATED";
	case D3DERR_INITFAILED: return "D3DERR_INITFAILED";
	case D3DERR_INBEGIN: return "D3DERR_INBEGIN";
	case D3DERR_INBEGINSTATEBLOCK: return "D3DERR_INBEGINSTATEBLOCK";
		//		case D3DERR_INOVERLAYSTATEBLOCK: return "D3DERR_INOVERLAYSTATEBLOCK";
	case D3DERR_INVALID_DEVICE: return "D3DERR_INVALID_DEVICE";
	case D3DERR_INVALIDCURRENTVIEWPORT: return "D3DERR_INVALIDCURRENTVIEWPORT";
	case D3DERR_INVALIDMATRIX: return "D3DERR_INVALIDMATRIX";
	case D3DERR_INVALIDPALETTE: return "D3DERR_INVALIDPALETTE";
	case D3DERR_INVALIDPRIMITIVETYPE: return "D3DERR_INVALIDPRIMITIVETYPE";
	case D3DERR_INVALIDRAMPTEXTURE: return "D3DERR_INVALIDRAMPTEXTURE";
	case D3DERR_INVALIDSTATEBLOCK: return "D3DERR_INVALIDSTATEBLOCK";
	case D3DERR_INVALIDVERTEXFORMAT: return "D3DERR_INVALIDVERTEXFORMAT";
	case D3DERR_INVALIDVERTEXTYPE: return "D3DERR_INVALIDVERTEXTYPE";
	case D3DERR_LIGHT_SET_FAILED: return "D3DERR_LIGHT_SET_FAILED";
	case D3DERR_LIGHTHASVIEWPORT: return "D3DERR_LIGHTHASVIEWPORT";
	case D3DERR_LIGHTNOTINTHISVIEWPORT: return "D3DERR_LIGHTNOTINTHISVIEWPORT";
	case D3DERR_MATERIAL_CREATE_FAILED: return "D3DERR_MATERIAL_CREATE_FAILED";
	case D3DERR_MATERIAL_DESTROY_FAILED: return "D3DERR_MATERIAL_DESTROY_FAILED";
	case D3DERR_MATERIAL_GETDATA_FAILED: return "D3DERR_MATERIAL_GETDATA_FAILED";
	case D3DERR_MATERIAL_SETDATA_FAILED: return "D3DERR_MATERIAL_SETDATA_FAILED";
	case D3DERR_MATRIX_CREATE_FAILED: return "D3DERR_MATRIX_CREATE_FAILED";
	case D3DERR_MATRIX_DESTROY_FAILED: return "D3DERR_MATRIX_DESTROY_FAILED";
	case D3DERR_MATRIX_GETDATA_FAILED: return "D3DERR_MATRIX_GETDATA_FAILED";
	case D3DERR_MATRIX_SETDATA_FAILED: return "D3DERR_MATRIX_SETDATA_FAILED";
	case D3DERR_NOCURRENTVIEWPORT: return "D3DERR_NOCURRENTVIEWPORT";
	case D3DERR_NOTINBEGIN: return "D3DERR_NOTINBEGIN";
	case D3DERR_NOTINBEGINSTATEBLOCK: return "D3DERR_NOTINBEGINSTATEBLOCK";
	case D3DERR_NOVIEWPORTS: return "D3DERR_NOVIEWPORTS";
	case D3DERR_SCENE_BEGIN_FAILED: return "D3DERR_SCENE_BEGIN_FAILED";
	case D3DERR_SCENE_END_FAILED: return "D3DERR_SCENE_END_FAILED";
	case D3DERR_SCENE_IN_SCENE: return "D3DERR_SCENE_IN_SCENE";
	case D3DERR_SCENE_NOT_IN_SCENE: return "D3DERR_SCENE_NOT_IN_SCENE";
	case D3DERR_SETVIEWPORTDATA_FAILED: return "D3DERR_SETVIEWPORTDATA_FAILED";
	case D3DERR_STENCILBUFFER_NOTPRESENT: return "D3DERR_STENCILBUFFER_NOTPRESENT";
	case D3DERR_SURFACENOTINVIDMEM: return "D3DERR_SURFACENOTINVIDMEM";
	case D3DERR_TEXTURE_BADSIZE: return "D3DERR_TEXTURE_BADSIZE";
	case D3DERR_TEXTURE_CREATE_FAILED: return "D3DERR_TEXTURE_CREATE_FAILED";
	case D3DERR_TEXTURE_DESTROY_FAILED: return "D3DERR_TEXTURE_DESTROY_FAILED";
	case D3DERR_TEXTURE_GETSURF_FAILED: return "D3DERR_TEXTURE_GETSURF_FAILED";
	case D3DERR_TEXTURE_LOAD_FAILED: return "D3DERR_TEXTURE_LOAD_FAILED";
	case D3DERR_TEXTURE_LOCK_FAILED: return "D3DERR_TEXTURE_LOCK_FAILED";
	case D3DERR_TEXTURE_LOCKED: return "D3DERR_TEXTURE_LOCKED";
	case D3DERR_TEXTURE_NO_SUPPORT: return "D3DERR_TEXTURE_NO_SUPPORT";
	case D3DERR_TEXTURE_NOT_LOCKED: return "D3DERR_TEXTURE_NOT_LOCKED";
	case D3DERR_TEXTURE_SWAP_FAILED: return "D3DERR_TEXTURE_SWAP_FAILED";
	case D3DERR_TEXTURE_UNLOCK_FAILED: return "D3DERR_TEXTURE_UNLOCK_FAILED";
	case D3DERR_TOOMANYOPERATIONS: return "D3DERR_TOOMANYOPERATIONS";
	case D3DERR_TOOMANYPRIMITIVES: return "D3DERR_TOOMANYPRIMITIVES";
	case D3DERR_UNSUPPORTEDALPHAARG: return "D3DERR_UNSUPPORTEDALPHAARG";
	case D3DERR_UNSUPPORTEDALPHAOPERATION: return "D3DERR_UNSUPPORTEDALPHAOPERATION";
	case D3DERR_UNSUPPORTEDCOLORARG: return "D3DERR_UNSUPPORTEDCOLORARG";
	case D3DERR_UNSUPPORTEDCOLOROPERATION: return "D3DERR_UNSUPPORTEDCOLOROPERATION";
	case D3DERR_UNSUPPORTEDFACTORVALUE: return "D3DERR_UNSUPPORTEDFACTORVALUE";
	case D3DERR_UNSUPPORTEDTEXTUREFILTER: return "D3DERR_UNSUPPORTEDTEXTUREFILTER";
	case D3DERR_VBUF_CREATE_FAILED: return "D3DERR_VBUF_CREATE_FAILED";
	case D3DERR_VERTEXBUFFERLOCKED: return "D3DERR_VERTEXBUFFERLOCKED";
	case D3DERR_VERTEXBUFFEROPTIMIZED: return "D3DERR_VERTEXBUFFEROPTIMIZED";
	case D3DERR_VERTEXBUFFERUNLOCKFAILED: return "D3DERR_VERTEXBUFFERUNLOCKFAILED";
	case D3DERR_VIEWPORTDATANOTSET: return "D3DERR_VIEWPORTDATANOTSET";
	case D3DERR_VIEWPORTHASNODEVICE: return "D3DERR_VIEWPORTHASNODEVICE";
	case D3DERR_WRONGTEXTUREFORMAT: return "D3DERR_WRONGTEXTUREFORMAT";
	case D3DERR_ZBUFF_NEEDS_SYSTEMMEMORY: return "D3DERR_ZBUFF_NEEDS_SYSTEMMEMORY";
	case D3DERR_ZBUFF_NEEDS_VIDEOMEMORY: return "D3DERR_ZBUFF_NEEDS_VIDEOMEMORY";
	case D3DERR_ZBUFFER_NOTPRESENT: return "D3DERR_ZBUFFER_NOTPRESENT";

		//		case E_INVALIDINTERFACE: return "E_INVALIDINTERFACE";
	case E_OUTOFMEMORY: return "E_OUTOFMEMORY";
	}

	char aBuf[50];
	sprintf(aBuf, "%x", theResult);
	return aBuf;
}
