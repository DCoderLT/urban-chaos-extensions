#ifndef UCC_FAE_ROAD_EDGE_H
#define UCC_FAE_ROAD_EDGE_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct RoadEdge
{
  BYTE field_0;
static RoadEdge *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif