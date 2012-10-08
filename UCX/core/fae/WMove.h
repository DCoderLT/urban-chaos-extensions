#ifndef UCC_FAE_W_MOVE_H
#define UCC_FAE_W_MOVE_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct WMove
{
  DWORD field_0;
  DWORD field_4;
  DWORD field_8;
  DWORD field_C;
  DWORD field_10;
  DWORD field_14;
static WMove *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif