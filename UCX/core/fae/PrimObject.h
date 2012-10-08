#ifndef UCC_FAE_PRIM_OBJECT_H
#define UCC_FAE_PRIM_OBJECT_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct PrimObject
{
  WORD FirstPoint;
  WORD LastPoint;
  WORD FirstFace4;
  WORD LastFace4;
  WORD FirstFace3;
  WORD LastFace3;
  BYTE field_C;
  BYTE field_D;
  BYTE field_E;
  BYTE field_F;
static PrimObject *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif