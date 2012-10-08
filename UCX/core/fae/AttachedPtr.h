#ifndef UCC_FAE_ATTACHED_PTR_H
#define UCC_FAE_ATTACHED_PTR_H

#include "../Generic.h"
#include "../Geometry.h"

#include "_fae.h"


using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Player;
struct People;
struct Special;
struct Pyro;

#pragma pack(push, 1)
union AttachedPtr {
	Player *pPlayer;
  People *pPeople;
  Special *pSpecial;
  Pyro *pPyro;
};
#pragma pack(pop)

		};
	};
};

#endif