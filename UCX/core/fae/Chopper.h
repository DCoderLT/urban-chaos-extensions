#ifndef UCC_FAE_CHOPPER_H
#define UCC_FAE_CHOPPER_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct Chopper
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
static Chopper *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif