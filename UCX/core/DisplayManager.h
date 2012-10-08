#ifndef UCC_DISPLAYMANAGER_H
#define UCC_DISPLAYMANAGER_H

#include "Generic.h"

namespace UCX {
	namespace Core {

		class DisplayManagerAux {
		public:
			int GetBitsPerPixel()
				{ JMP_THIS(0x4C8230); }

			DWORD bleh;
		};

		#pragma pack(push, 1)
		struct ColorStruct
		{
			BYTE R, G, B;

			void operator = (ColorStruct Color)
			{
				R = Color.R;
				G = Color.G;
				B = Color.B;
			}

			bool operator == (ColorStruct rhs)
			{
				return R == rhs.R && G == rhs.G && B == rhs.B;
			}

			ColorStruct()
			{
			}

			ColorStruct(BYTE _R, BYTE _G, BYTE _B)
			{
				R = _R;
				G = _G;
				B = _B;
			}

			ColorStruct(DWORD dwColor) {
				B = dwColor & 0xFF;
				dwColor >>= 8;
				G = dwColor & 0xFF;
				dwColor >>= 8;
				R = dwColor & 0xFF;
			}

			DWORD AsDWORD() const {
				return (R << 16) | (G < 8) | (B);
			}
		};
 
		struct Color16Struct
		{
			int R:5;
			int G:6;
			int B:5;

			void operator = (Color16Struct Color)
			{
				R = Color.R;
				G = Color.G;
				B = Color.B;
			}

			void operator = (ColorStruct Color)
			{
				R = Color.R >> 3;
				G = Color.G >> 2;
				B = Color.B >> 3;
			}

			bool operator == (Color16Struct rhs)
			{
				return R == rhs.R && G == rhs.G && B == rhs.B;
			}

			Color16Struct()
			{
			}

			Color16Struct(ColorStruct Color)
			{
				*this = Color;
			}

			void SwapRB() {
				int tmp = R;
				R = B;
				B = tmp;
			}
		};
		#pragma pack(pop)

		class DisplayManager {
		public:
			static DisplayManager *Instance;

			BYTE unknown_0[0x48];
			DisplayManagerAux *Aux;
			BYTE unknown_4C[0x60];
			DWORD Pack_R_SHL;// 0xAC
			DWORD Pack_G_SHL;
			DWORD Pack_B_SHL;
			DWORD Pack_R_SHR;
			DWORD Pack_G_SHR;
			DWORD Pack_B_SHR;
			int ScreenWidth;
			int ScreenHeight;
			int Pitch;
			int field_D0;
			BYTE *ScreenPixels;
			int field_D8;
		};

		#define CLR_C(clr, var, component) \
			clr.component = (0xFF & ((BYTE)(((unsigned int)var >> Mgr->Pack_ ## component ## _SHR)) << Mgr->Pack_ ## component ## _SHL));

		#define CLR(clr, var) \
			CLR_C(clr, var, R); \
			CLR_C(clr, var, G); \
			CLR_C(clr, var, B); \

	};
};

#endif
