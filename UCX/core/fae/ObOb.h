#ifndef UCC_FAE_OB_OB_H
#define UCC_FAE_OB_OB_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct ObOb
{
  WORD Type;
  BYTE X;
  BYTE Z;
  BYTE PrimObjectIdx;
  BYTE field_5;
  BYTE field_6;
  BYTE field_7;
static ObOb *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif