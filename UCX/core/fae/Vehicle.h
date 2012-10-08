#ifndef UCC_FAE_VEHICLE_H
#define UCC_FAE_VEHICLE_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct Vehicle
{
  DWORD field_0;
  DWORD field_4;
  DWORD field_8;
  DWORD field_C;
  DWORD field_10;
  DWORD field_14;
  DWORD field_18;
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
  DWORD field_60;
  DWORD field_64;
  WORD field_68;
  WORD field_6A;
  WORD field_6C;
  WORD Model;
  BYTE field_70;
  BYTE NightDLightIndex;
  BYTE field_72;
  BYTE field_73;
  DWORD field_74;
  DWORD field_78;
  DWORD field_7C;
  DWORD field_80;
  DWORD field_84;
  DWORD field_88;
  DWORD field_8C;
  DWORD field_90;
  DWORD field_94;
  DWORD field_98;
  DWORD field_9C;
  DWORD field_A0;
  DWORD field_A4;
  DWORD field_A8;
  DWORD field_AC;
  DWORD field_B0;
  DWORD field_B4;
static Vehicle *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif