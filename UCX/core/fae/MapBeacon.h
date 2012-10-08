#ifndef UCC_FAE_MAP_BEACON_H
#define UCC_FAE_MAP_BEACON_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct MapBeacon
{
  BYTE Active;
  BYTE field_1;
  WORD AttachedThing;
  WORD AttachedMessage;
  WORD AttachedMessageShown;
  DWORD X;
  DWORD Z;
  DWORD InitialTickCount;
static MapBeacon *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif