#ifndef UCC_FAE_EWAY_COUNTER_H
#define UCC_FAE_EWAY_COUNTER_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct EwayCounter
{
  BYTE Value;
static EwayCounter *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif