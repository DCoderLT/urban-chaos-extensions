#ifndef UCC_FAE_TRIP_WIRE_H
#define UCC_FAE_TRIP_WIRE_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct TripWire
{
  BYTE Triggered;
  BYTE field_1;
  WORD field_2;
  WORD field_4;
  WORD field_6;
  WORD field_8;
  WORD field_A;
  WORD field_C;
static TripWire *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif