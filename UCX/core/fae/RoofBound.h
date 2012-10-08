#ifndef UCC_FAE_ROOF_BOUND_H
#define UCC_FAE_ROOF_BOUND_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct RoofBound
{
  DWORD field_0;
  BYTE field_4;
  BYTE field_5;
static RoofBound *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif