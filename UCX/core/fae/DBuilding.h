#ifndef UCC_FAE_D_BUILDING_H
#define UCC_FAE_D_BUILDING_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct DBuilding
{
  DWORD field_0;
  DWORD field_4;
  DWORD field_8;
  WORD field_C;
  WORD field_E;
  DWORD field_10;
  DWORD field_14;
static DBuilding *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif