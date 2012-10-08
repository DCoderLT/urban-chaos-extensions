#ifndef UCC_FAE_INSIDE_STOREY_H
#define UCC_FAE_INSIDE_STOREY_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct InsideStorey
{
  DWORD field_0;
  DWORD field_4;
  DWORD field_8;
  DWORD field_C;
  DWORD field_10;
  BYTE field_14;
  BYTE field_15;
static InsideStorey *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif