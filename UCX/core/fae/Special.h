#ifndef UCC_FAE_SPECIAL_H
#define UCC_FAE_SPECIAL_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct Special
{
  BYTE Type;
  BYTE field_1;
  WORD field_2;
  WORD field_4;
  WORD field_6;
  WORD field_8;
  WORD field_A;
  WORD ChargesInClip;
  WORD field_E;
  WORD field_10;
  WORD field_12;
static Special *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif