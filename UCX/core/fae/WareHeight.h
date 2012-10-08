#ifndef UCC_FAE_WARE_HEIGHT_H
#define UCC_FAE_WARE_HEIGHT_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct WareHeight
{
  BYTE field_0;
static WareHeight *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif