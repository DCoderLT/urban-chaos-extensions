#ifndef UCC_MISSION_H
#define UCC_MISSION_H

#include "Generic.h"

namespace UCX {
	namespace Core {

		namespace Mission {
			inline void Restart() {
				JMP_STD(0x41C620);
			}

			extern int & ActiveTimerCount;

			struct Timer {
				float TimeRemaining;
				float unknown_4; // only 320 is used
				float unknown_8; // only 50 is used
			};

			extern Timer *& Timers;
		};

		#pragma pack(push, 1)
		struct Mission_Data
		{
			int ObjectID;
			int GroupID;
			int ParentID;
			int ParentIsGroup;
			int District;
			int Type;
			int Flags;
			char Filename[32];
			int field_3C;
			int field_40;
			int field_44;
			int field_48;
			int field_4C;
			int field_50;
			int field_54;
			int field_58;
			int field_5C;
			int field_60;
			int field_64;
			int field_68;
			int field_6C;
			int field_70;
			int field_74;
			int field_78;
			int field_7C;
			int field_80;
			int field_84;
			int field_88;
			int field_8C;
			int field_90;
			int field_94;
			int field_98;
			int field_9C;
			int field_A0;
			int field_A4;
			int field_A8;
			int field_AC;
			int field_B0;
			int field_B4;
			int field_B8;
			int field_BC;
			int field_C0;
			int field_C4;
			int field_C8;
			int field_CC;
			int field_D0;
			int field_D4;
			int field_D8;
			int field_DC;
			int field_E0;
			int field_E4;
			int field_E8;
			int field_EC;
			int field_F0;
			int field_F4;
			int field_F8;
			int field_FC;
			int field_100;
			int field_104;
			int field_108;
			int field_10C;
			int field_110;
			int field_114;
			char field_118;
			char field_119;
			char field_11A;
			char Title[255];
			char Briefing[4096];
		};
		#pragma pack(pop)

	};
};

#endif