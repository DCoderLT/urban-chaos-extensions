#ifndef UCC_FAE_PRIM_M_OBJECT_H
#define UCC_FAE_PRIM_M_OBJECT_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct PrimMObject
{
  WORD FirstObject;
  WORD LastObject;
  DWORD field_4;
static PrimMObject *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif