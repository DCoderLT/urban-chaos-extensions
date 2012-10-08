#ifndef UCC_FAE_PAINT_MEM_H
#define UCC_FAE_PAINT_MEM_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct PaintMem
{
  BYTE field_0;
static PaintMem *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif