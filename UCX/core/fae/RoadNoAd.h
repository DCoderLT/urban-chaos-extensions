#ifndef UCC_FAE_ROAD_NO_AD_H
#define UCC_FAE_ROAD_NO_AD_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct RoadNoAd
{
  BYTE field_0;
  BYTE field_1;
  BYTE Connections[4];
static RoadNoAd *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif