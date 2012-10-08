#ifndef UCC_FAE_PRIM_POINT_H
#define UCC_FAE_PRIM_POINT_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct PrimPoint
{
  WORD X;
  WORD Y;
  WORD Z;
static PrimPoint *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif