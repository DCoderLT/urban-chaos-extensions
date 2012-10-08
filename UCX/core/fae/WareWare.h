#ifndef UCC_FAE_WARE_WARE_H
#define UCC_FAE_WARE_WARE_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct WareWare
{
  DWORD field_0;
  DWORD field_4;
  DWORD field_8;
  DWORD field_C;
  BYTE field_10;
  BYTE field_11;
  BYTE field_12;
  BYTE field_13;
  BYTE field_14;
  BYTE field_15;
  BYTE field_16;
  BYTE field_17;
  WORD field_18;
  WORD field_1A;
  DWORD field_1C;
static WareWare *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif