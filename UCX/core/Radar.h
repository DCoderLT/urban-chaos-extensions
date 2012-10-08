#ifndef UCC_RADAR_H
#define UCC_RADAR_H

namespace UCX {
	namespace Core {

		namespace Radar {
			extern char *Message;
			extern int &MessageSetTime;

			inline void __cdecl SetMessage(char *Format, ...)
				{ JMP_STD(0x490AF0); }

		};

	};
};

#endif
