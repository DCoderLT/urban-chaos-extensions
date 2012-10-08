#ifndef UCC_FAE_PEOPLE_H
#define UCC_FAE_PEOPLE_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct People
{
  BYTE Type;
  BYTE field_1;
  WORD field_2;
  DWORD field_4;
  BYTE field_8;
  BYTE field_9;
  BYTE field_A;
  BYTE field_B;
  DWORD field_C;
  DWORD field_10;
  DWORD field_14;
  WORD field_18;
  WORD field_1A;
  DWORD field_1C;
  DWORD field_20;
  DWORD field_24;
  DWORD field_28;
  DWORD field_2C;
  DWORD field_30;
  DWORD field_34;
  DWORD field_38;
  DWORD field_3C;
  DWORD field_40;
  DWORD field_44;
  DWORD field_48;
  DWORD field_4C;
  DWORD field_50;
  DWORD field_54;
  DWORD field_58;
  DWORD field_5C;
  BYTE field_60;
  BYTE field_61;
  BYTE field_62;
  BYTE field_63;
  BYTE field_64;
  BYTE field_65;
  BYTE field_66;
  BYTE field_67;
  DWORD field_68;
  DWORD field_6C;
  DWORD field_70;
  DWORD field_74;
  DWORD field_78;
  DWORD field_7C;
  DWORD field_80;
  DWORD field_84;
  DWORD field_88;
static People *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif