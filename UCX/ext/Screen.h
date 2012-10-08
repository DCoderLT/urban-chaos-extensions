#ifndef UCE_SCREEN_H
#define UCE_SCREEN_H

#include "../core/Generic.h"

namespace UCX {
	namespace Ext {

struct ScreenResolution {
	DWORD Width;
	DWORD Height;
	char * Text;

	enum { OptionCount = 5 };
	static const ScreenResolution Resolutions[OptionCount];
};

	};
};

#endif