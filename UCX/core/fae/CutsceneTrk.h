#ifndef UCC_FAE_CUTSCENE_TRK_H
#define UCC_FAE_CUTSCENE_TRK_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct CutsceneTrk
{
  DWORD field_0;
  DWORD field_4;
  DWORD field_8;
static CutsceneTrk *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif