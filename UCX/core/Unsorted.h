#ifndef UCC_UNSORTED_H
#define UCC_UNSORTED_H

#include "Generic.h"

namespace UCX {
	namespace Core {
		namespace CharacterClass {
			extern WORD * ClassHealthMax;

			inline short maxClassHealth(const byte idx) {
				return ClassHealthMax[idx];
			}
		};

		namespace Environment {
			inline void __cdecl Spawn_Water(const short posX, const short posY, const short posZ,
					const int unk0, const int unkA, const int unkB, const int unkC) {
				JMP_STD(0x416F90);
			}

			inline void __cdecl Spawn_Light(const int posX, const int posY, const int posZ,
					const byte state, const short colR, const short colG, const short colB) {
				JMP_STD(0x440860);
			}

			extern byte & EnvironmentStyle;

			extern int & Ambient_R;
			extern int & Ambient_G;
			extern int & Ambient_B;

			inline void Ambient_Update_Part1() {
				JMP_STD(0x04426C0);
			}

			inline void Ambient_Update_Part2() {
				JMP_STD(0x0442BA0);
			}

			inline void Ambient_Update_Part3() {
				JMP_STD(0x0444620);
			}

			inline void Ambient_Update() {
				Ambient_Update_Part1();
				Ambient_Update_Part2();
				Ambient_Update_Part3();
			}

			inline void Ambient_Set(const int R, const int G, const int B) {
				Ambient_R = R;
				Ambient_G = G;
				Ambient_B = B;
				Ambient_Update();
			}
		};

		inline void MakeScreenShot() {
			JMP_STD(0x412B00);
		}

		namespace Person {
			class Type {
				typedef unsigned int Value;
				enum {
					Darci = 0,
					Roper = 1,
					Cop = 2,
					MaleCiv1 = 3, // plain clothes
					Wildcat1 = 4,
					Wildcat2 = 5,
					Wildcat3 = 6,
					Hooker = 7,
					FemCiv1 = 8, // large build
					Gordansky = 9,
					Worker1 = 10,
					OldDude1 = 11, // old man, leather jacket
					MIB1 = 12,
					MIB2 = 13,
					MIB3 = 14,
				};
			};
		};

	};
};

#endif