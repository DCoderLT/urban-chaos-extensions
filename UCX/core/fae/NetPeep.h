#ifndef UCC_FAE_NET_PEEP_H
#define UCC_FAE_NET_PEEP_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct NetPeep
{
  Thing *fae_Thing_Ptr;
static NetPeep *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif