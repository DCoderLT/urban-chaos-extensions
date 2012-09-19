#ifndef UCC_RADAR_H
#define UCC_RADAR_H

namespace Radar {
	extern char *&Message;
	extern int &MessageSetTime;
	void __cdecl SetMessage(char *Format, ...)
		{ JMP_STD(0x490AF0); }

};

#endif
