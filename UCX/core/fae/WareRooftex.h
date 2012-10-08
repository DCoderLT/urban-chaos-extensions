#ifndef UCC_FAE_WARE_ROOFTEX_H
#define UCC_FAE_WARE_ROOFTEX_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct WareRooftex
{
  WORD field_0;
static WareRooftex *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif