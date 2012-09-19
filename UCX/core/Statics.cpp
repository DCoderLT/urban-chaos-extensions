#include "Generic.h"
#include "Syringe.h"

#include "Statics.h"
ALIAS(HWND, Statics::hWnd, 0x1AFCCBC);
ALIAS(HINSTANCE, Statics::hInstance, 0x1B02650);

ALIAS(WNDCLASSA, Statics::gWndClass, 0x1B02620);
ALIAS(bool, Statics::gFixDirectX, 0x1A980C4);

ALIAS_O(char *, Statics::KeyBuffer1, 0x1B020E8);
ALIAS_O(char *, Statics::KeyBuffer2, 0x1B01FE8);

void Statics::SetInitialValues() {
//	Statics::gFixDirectX = true;
}

#include "DisplayManager.h"
ALIAS_O(DisplayManager *, DisplayManager::Instance, 0x1AFCBD8);

#include "Magic.h"
ALIAS(WORD, Magic::SlowdownRemaining, 0xACB164);

#include "Radar.h"
ALIAS(char *, Radar::Message, 0xDD00F8);
ALIAS(int, Radar::MessageSetTime, 0xDD0300);
