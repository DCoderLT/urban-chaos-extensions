#ifndef UCC_FAE_PROJECTILE_H
#define UCC_FAE_PROJECTILE_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct Projectile
{
  DWORD field_0;
  DWORD field_4;
static Projectile *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif