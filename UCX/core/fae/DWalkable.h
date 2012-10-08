#ifndef UCC_FAE_D_WALKABLE_H
#define UCC_FAE_D_WALKABLE_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct DWalkable
{
  DWORD field_0;
  DWORD field_4;
  WORD FirstFaceIdx;
  WORD LastFaceIdx;
  DWORD field_C;
  WORD field_10;
  WORD field_12;
  BYTE field_14;
  BYTE field_15;
static DWalkable *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif