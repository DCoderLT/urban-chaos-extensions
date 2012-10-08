#ifndef UCC_FAE_BARREL_H
#define UCC_FAE_BARREL_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct Barrel
{
  BYTE field_0;
  BYTE field_1;
  WORD field_2;
  WORD field_4;
static Barrel *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif