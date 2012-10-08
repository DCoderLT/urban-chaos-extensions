#ifndef UCC_FAE_EWAY_WAY_PREDICATE_H
#define UCC_FAE_EWAY_WAY_PREDICATE_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

#pragma pack(push, 1)
struct EwayWay_Predicate
{
  BYTE Type;
  BYTE field_1;
  WORD field_2;
  WORD field_4;
  EwayWay_Predicate *AdditionalPredicate1;
  EwayWay_Predicate *AdditionalPredicate2;
};
#pragma pack(pop)

		};
	};
};

#endif
