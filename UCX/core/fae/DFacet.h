#ifndef UCC_FAE_D_FACET_H
#define UCC_FAE_D_FACET_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct DFacet
{
  BYTE field_0;
  BYTE field_1;
  BYTE field_2;
  BYTE field_3;
  WORD field_4;
  WORD field_6;
  BYTE field_8;
  BYTE field_9;
  WORD field_A;
  WORD field_C;
  WORD field_E;
  WORD field_10;
  byte field_12;
  byte field_13;
  BYTE field_14;
  BYTE field_15;
  BYTE field_16;
  BYTE field_17;
  BYTE field_18;
  BYTE field_19;
static DFacet *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif