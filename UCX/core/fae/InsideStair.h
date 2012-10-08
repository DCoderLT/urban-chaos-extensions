#ifndef UCC_FAE_INSIDE_STAIR_H
#define UCC_FAE_INSIDE_STAIR_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct InsideStair
{
  DWORD field_0;
  DWORD field_4;
  BYTE field_8;
  BYTE field_9;
static InsideStair *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif