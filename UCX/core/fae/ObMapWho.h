#ifndef UCC_FAE_OB_MAP_WHO_H
#define UCC_FAE_OB_MAP_WHO_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct ObMapWho
{
  BYTE field_0;
  BYTE field_1;
static ObMapWho *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif