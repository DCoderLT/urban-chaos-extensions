#ifndef UCC_SCREEN_H 
#define UCC_SCREEN_H

#include "generic.h"

namespace UCX {
	namespace Core {
		namespace Screen {
			inline int __cdecl OutputText_Left(char *Message, int X, int Y, DWORD Color, DWORD Spacing = 256, DWORD unk2 = 1479, DWORD ColorFade = 0)
				{ JMP_STD(0x48E310); }
			inline int __cdecl OutputText_Center(char *Message, int X, int Y, DWORD Color, DWORD Spacing = 256, DWORD unk2 = 1479, DWORD ColorFade = 0)
				{ JMP_STD(0x48E8F0); }
			inline int __cdecl OutputText_Right(char *Message, int X, int Y, DWORD Color, DWORD Spacing = 256, DWORD unk2 = 1479, DWORD ColorFade = 0)
				{ JMP_STD(0x48E800); }
		};
	};
};

#endif
