#ifndef UCC_FAE_EWAY_WAY_REPEAT_CONFIG_H
#define UCC_FAE_EWAY_WAY_REPEAT_CONFIG_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

#pragma pack(push, 1)
struct EwayWay_RepeatConfig
{
  WORD Flags;
  WORD Frequency;
};
#pragma pack(pop)

		};
	};
};

#endif
