#include "Generic.h"
#include "Syringe.h"

using namespace UCX::Core;

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

#include "Keyboard.h"
ALIAS_O(byte *, Keyboard::KeyState, 0x01B020E8);

#include "Magic.h"
ALIAS(WORD, Magic::SlowdownRemaining, 0xACB164);

#include "Mission.h"
ALIAS(int, Mission::ActiveTimerCount, 0xDCF1C4);
ALIAS(Mission::Timer *, Mission::Timers, 0xDD0098);

#include "Net.h"
ALIAS_O(Networking::PlayerData *, Networking::Players, 0x1B01470);

ALIAS(int, Networking::SessionCount, 0x1B01FD0);
ALIAS_O(Networking::SessionData *, Networking::Sessions, 0x1B00DE8);

ALIAS(int, Networking::ConnectionCount, 0x1B01468);
ALIAS_O(Networking::ConnectionData *, Networking::Connections, 0x1B01D70);


#include "Radar.h"
ALIAS_O(char *, Radar::Message, 0xDD00F8);
ALIAS(int, Radar::MessageSetTime, 0xDD0300);

#include "Radio.h"
ALIAS_O(Radio::MessageData *, Radio::ActiveMessages, 0xDCF320);
ALIAS(int, Radio::ActiveMessageIndex, 0xDCF1C8);

#include "Unsorted.h"
ALIAS_O(WORD *, CharacterClass::ClassHealthMax, 0x4F198C);

ALIAS(byte , Environment::EnvironmentStyle, 0x4EE375);

ALIAS(int, Environment::Ambient_R, 0x8F1658);
ALIAS(int, Environment::Ambient_G, 0x8F15DC);
ALIAS(int, Environment::Ambient_B, 0x8DCB7C);

#include "fae/_fae.h"
ALIAS(fae::Thing *, fae::Thing::Instances, 0x7073F0);