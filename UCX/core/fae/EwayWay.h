#ifndef UCC_FAE_EWAY_WAY_H
#define UCC_FAE_EWAY_WAY_H

#include "../Generic.h"
#include "../Geometry.h"

#include "EwayWay_RepeatConfig.h"
#include "EwayWay_Effect.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct EwayWay
{
  WORD Index;
  BYTE field_2;
  BYTE field_3;
  BYTE BehaviorFlags;
  BYTE field_5;
  WORD RechargeTimer;
  WPoint3D XYZ;
  BYTE field_E;
  BYTE field_F;
  EwayCond Condition;
  EwayWay_RepeatConfig Repeat;
  EwayWay_Effect Effect;
static EwayWay *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif