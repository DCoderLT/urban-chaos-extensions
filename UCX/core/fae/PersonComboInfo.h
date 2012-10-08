#ifndef UCC_FAE_PERSON_COMBO_INFO_H
#define UCC_FAE_PERSON_COMBO_INFO_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct PersonComboInfo
{
  BYTE Active;
  BYTE Exclusive;
  DWORD RequiredAction;
static PersonComboInfo *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif