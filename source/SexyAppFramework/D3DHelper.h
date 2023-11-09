#ifndef __D3DHELPER_H__
#define __D3DHELPER_H__

#include <string>
#include <windows.h>

namespace Sexy
{
	bool GetD3D8AdapterInfo(GUID& theGUID, std::string& theDriver, std::string& theDescription);

}

#endif
