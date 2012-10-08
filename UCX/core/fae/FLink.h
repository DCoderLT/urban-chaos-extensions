#ifndef UCC_FAE_F_LINK_H
#define UCC_FAE_F_LINK_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct FLink
{
  WORD field_0;
static FLink *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif