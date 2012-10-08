#ifndef UCC_KEYS_H
#define UCC_KEYS_H

#include "Generic.h"

namespace UCX {
	namespace Core {
		namespace Keyboard {

			extern byte * KeyState;

			inline bool isKeyDown(const byte idx) {
				return !!KeyState[idx];
			}

			inline void unsetKey(const byte idx) {
				KeyState[idx] = 0;
			}

			struct PressedKey {
				typedef unsigned char Value;
				enum key {
					KEY_1 = 2,
					KEY_2 = 3,
					KEY_3 = 4,
					KEY_4 = 5,
					KEY_5 = 6,
					KEY_6 = 7,
					KEY_7 = 8,
					KEY_8 = 9,
					KEY_9 = 10,
					KEY_0 = 11,
					KEY_DASH = 12,
					KEY_EQUAL = 13,
					KEY_BACKSPACE = 14,
					KEY_TAB = 15,
					KEY_Q = 16,
					KEY_W = 17,
					KEY_E = 18,
					KEY_R = 19,
					KEY_T = 20,
					KEY_Y = 21,
					KEY_U = 22,
					KEY_I = 23,
					KEY_O = 24,
					KEY_P = 25,
					KEY_LEFTBRACKET = 26,
					KEY_RIGHTBRACKET = 27,
					KEY_ENTER = 28,
					KEY_A = 30,
					KEY_S = 31,
					KEY_D = 32,
					KEY_F = 33,
					KEY_G = 34,
					KEY_H = 35,
					KEY_J = 36,
					KEY_K = 37,
					KEY_L = 38,
					KEY_COLON = 39,
					KEY_QUOTE = 40,
					KEY_TILDE = 41,
					KEY_LSHIFT = 42,
					KEY_HASH = 43,
					KEY_Z = 44,
					KEY_X = 45,
					KEY_C = 46,
					KEY_V = 47,
					KEY_B = 48,
					KEY_N = 49,
					KEY_M = 50,
					KEY_COMMA = 51,
					KEY_PERIOD = 52,
					KEY_SLASH = 53,
					KEY_RSHIFT = 54,
					KEY_ASTERISK = 55,
					KEY_SPACE = 57,
					KEY_F1 = 59,
					KEY_F2 = 60,
					KEY_F3 = 61,
					KEY_F4 = 62,
					KEY_F5 = 63,
					KEY_F6 = 64,
					KEY_F7 = 65,
					KEY_F8 = 66,
					KEY_F9 = 67,
					KEY_F10 = 68,
					KEY_F11 = 69,
					KEY_F12 = 70,
					KEY_NUM7 = 71,
					KEY_NUMDASH = 74,
					KEY_NUM5 = 76,
					KEY_NUMPLUS = 78,
					KEY_BACKSLASH = 86,
					KEY_F11_AGAIN = 87,
					KEY_SLASH_AGAIN = 96,
					KEY_OPEN_PAREN = 99,
					KEY_CLOSE_PAREN = 100,
					KEY_SLASH_ONCE_MORE = 101,
					KEY_ASTERISK_AGAIN = 102,
				};
			};

		};
	};
};

#endif
