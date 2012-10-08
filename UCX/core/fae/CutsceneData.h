#ifndef UCC_FAE_CUTSCENE_DATA_H
#define UCC_FAE_CUTSCENE_DATA_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct CutsceneData
{
  DWORD field_0;
  DWORD field_4;
static CutsceneData *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif