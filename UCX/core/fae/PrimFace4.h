#ifndef UCC_FAE_PRIM_FACE4_H
#define UCC_FAE_PRIM_FACE4_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct PrimFace4
{
  WORD field_0;
  WORD Point1;
  WORD Point2;
  WORD Point3;
  WORD Point4;
  BYTE field_A;
  BYTE field_B;
  BYTE field_C;
  BYTE field_D;
  BYTE field_E;
  BYTE field_F;
  BYTE field_10;
  BYTE field_11;
  BYTE gap_12[2];
  DWORD field_14;
  DWORD field_18;
  WORD PrimFaceIdx;
  WORD field_1E;
  WORD field_20;
static PrimFace4 *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif