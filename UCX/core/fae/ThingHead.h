#ifndef UCC_FAE_THING_HEAD_H
#define UCC_FAE_THING_HEAD_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct ThingHead
{
  WORD Index;
static ThingHead *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif