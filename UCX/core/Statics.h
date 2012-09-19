#ifndef UCC_STATICS_H
#define UCC_STATICS_H

#include "Generic.h"

#include <windows.h>


namespace Statics {
	extern WNDCLASSA &gWndClass;
	extern HINSTANCE &hInstance;
	extern HWND &hWnd;

	extern bool &gFixDirectX;

	void SetInitialValues();

	extern char * KeyBuffer1;
	extern char * KeyBuffer2;
};

#endif
