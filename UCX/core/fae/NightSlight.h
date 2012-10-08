#ifndef UCC_FAE_NIGHT_SLIGHT_H
#define UCC_FAE_NIGHT_SLIGHT_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct NightSlight
{
  WORD Height;
  BYTE X;
  BYTE Z;
  BYTE field_4;
  BYTE field_5;
  BYTE field_6;
  BYTE field_7;
static NightSlight *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif