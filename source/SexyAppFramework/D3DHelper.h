#ifndef __D3D8HELPER_H__
#define __D3D8HELPER_H__

#include <string>
#include <windows.h>

namespace Sexy
{
	bool GetD3D8AdapterInfo(GUID& theGUID, std::string& theDriver, std::string& theDescription);
	bool GetD3D9AdapterInfo(GUID& theGUID, std::string& theDriver, std::string& theDescription);
	bool GetD3D10AdapterInfo(GUID &theGUID, std::string &theDriver, std::string &theDescription);
	bool GetD3D11AdapterInfo(GUID& theGUID, std::string& theDriver, std::string& theDescription);
}

#endif