#ifndef UCC_FAE_PAP_HI_H
#define UCC_FAE_PAP_HI_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct PapHi
{
  WORD field_0;
  BYTE field_2;
  BYTE field_3;
  BYTE field_4;
  BYTE field_5;
static PapHi *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif