#ifndef UCC_FAE_EWAY_WAY_EFFECT_H
#define UCC_FAE_EWAY_WAY_EFFECT_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

#pragma pack(push, 1)
struct EwayWay_Effect
{
  BYTE Type;
  BYTE MainArg;
  WORD f2;
  WORD f4;
};
#pragma pack(pop)

		};
	};
};

#endif
