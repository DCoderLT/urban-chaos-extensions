#ifndef UCC_FAE_NIGHT_D_LIGHT_H
#define UCC_FAE_NIGHT_D_LIGHT_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct NightDLight
{
  WORD X;
  WORD Y;
  WORD Z;
  BYTE field_6;
  BYTE field_7;
  BYTE field_8;
  BYTE field_9;
  BYTE field_A;
  BYTE field_B;
static NightDLight *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif