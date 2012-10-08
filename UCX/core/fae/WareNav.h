#ifndef UCC_FAE_WARE_NAV_H
#define UCC_FAE_WARE_NAV_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct WareNav
{
  BYTE field_0;
  BYTE field_1;
static WareNav *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif