#ifndef UCC_FAE_D_STOREY_H
#define UCC_FAE_D_STOREY_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct DStorey
{
  WORD LowResTextureIndex;
  WORD FirstTextureIndex;
  BYTE TextureCount;
  BYTE field_5;
static DStorey *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif