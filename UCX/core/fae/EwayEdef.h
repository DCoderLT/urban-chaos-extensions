#ifndef UCC_FAE_EWAY_EDEF_H
#define UCC_FAE_EWAY_EDEF_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct EwayEdef
{
  WORD field_0;
  BYTE Person_OwnedObjects;
  BYTE field_3;
  BYTE field_4;
  BYTE field_5;
  BYTE field_6;
  BYTE field_7;
  BYTE field_8;
  BYTE field_9;
  WORD Person_AffectingCombos;
static EwayEdef *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif