#ifndef UCC_FAE_MAV_OPT_H
#define UCC_FAE_MAV_OPT_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct MavOpt
{
  BYTE field_0;
  BYTE field_1;
  BYTE field_2;
  BYTE field_3;
static MavOpt *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif