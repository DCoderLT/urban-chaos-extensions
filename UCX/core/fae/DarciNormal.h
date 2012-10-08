#ifndef UCC_FAE_DARCI_NORMAL_H
#define UCC_FAE_DARCI_NORMAL_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct DarciNormal
{
  WORD Normal;
static DarciNormal *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif