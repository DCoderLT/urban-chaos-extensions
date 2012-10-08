#ifndef UCC_FAE_PRIM_FACE3_H
#define UCC_FAE_PRIM_FACE3_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct PrimFace3
{
  WORD field_0;
  WORD Point1;
  WORD Point2;
  WORD Point3;
  BYTE field_8;
  BYTE field_9;
  BYTE field_A;
  BYTE field_B;
  BYTE field_C;
  BYTE field_D;
  WORD field_E;
  DWORD field_10;
  DWORD field_14;
  WORD field_18;
  WORD field_1A;
static PrimFace3 *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif