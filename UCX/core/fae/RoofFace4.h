#ifndef UCC_FAE_ROOF_FACE4_H
#define UCC_FAE_ROOF_FACE4_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct RoofFace4
{
  WORD field_0;
  BYTE field_2;
  BYTE field_3;
  BYTE field_4;
  BYTE field_5;
  BYTE RoofXSize;
  BYTE RoofZSize;
  WORD RoofFaceIdx;
static RoofFace4 *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif