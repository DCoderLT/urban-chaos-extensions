#ifndef UCC_FAE_CUTSCENE_TEXT_H
#define UCC_FAE_CUTSCENE_TEXT_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct CutsceneText
{
  BYTE field_0;
static CutsceneText *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif