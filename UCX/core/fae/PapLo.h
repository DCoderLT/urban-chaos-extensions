#ifndef UCC_FAE_PAP_LO_H
#define UCC_FAE_PAP_LO_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct PapLo
{
  WORD NextThing;
  WORD FaceIdx;
  WORD FLinkIndex;
  BYTE field_6;
  BYTE field_7;
static PapLo *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif