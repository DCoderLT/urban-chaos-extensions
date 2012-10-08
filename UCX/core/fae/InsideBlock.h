#ifndef UCC_FAE_INSIDE_BLOCK_H
#define UCC_FAE_INSIDE_BLOCK_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct InsideBlock
{
  BYTE field_0;
static InsideBlock *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif