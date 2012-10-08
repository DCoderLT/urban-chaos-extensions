#ifndef UCC_FAE_EWAY_COND_H
#define UCC_FAE_EWAY_COND_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct EwayCond
{
  BYTE Type;
  BYTE Reversed;
  WORD field_2;
  WORD field_4;
static EwayCond *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif