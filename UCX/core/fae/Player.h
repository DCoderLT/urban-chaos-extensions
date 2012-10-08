#ifndef UCC_FAE_PLAYER_H
#define UCC_FAE_PLAYER_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct Player
{
  BYTE Type;
  BYTE field_1;
  WORD fae_Thing_Index;
  DWORD field_4;
  BYTE Action;
  BYTE field_9;
  BYTE LoadedAmmo;
  BYTE PlayerIndex;
  WORD Health;
  WORD ArrestedScanProgress;
  WORD NetPlyrIndex;
  BYTE Stamina;
  BYTE Constitution;
  DWORD InsideVehicle;
  WORD field_18;
  WORD DrawnWeapon;
  DWORD field_1C;
  DWORD field_20;
  DWORD field_24;
  DWORD field_28;
  DWORD field_2C;
  DWORD field_30;
  DWORD field_34;
  DWORD field_38;
  DWORD field_3C;
  WORD field_40;
  BYTE fae_Pyro_Idx;
  BYTE field_43;
  BYTE field_44;
  BYTE Role;
  BYTE State1;
  BYTE State2;
  DWORD field_48;
  DWORD field_4C;
  BYTE field_50;
  BYTE field_51;
  BYTE Move1;
  BYTE Move2;
  DWORD field_54;
  DWORD field_58;
  DWORD field_5C;
  BYTE field_60;
  BYTE field_61;
  BYTE field_62;
  BYTE field_63;
  DWORD field_64;
  WORD field_68;
  BYTE field_6A;
  BYTE WarehouseIndex;
  BYTE field_6C;
  BYTE field_6D;
  BYTE field_6E;
  BYTE field_6F;
  WORD Agr;
  BYTE PistolAmmo;
  BYTE field_73;
  BYTE ShotgunAmmo;
  BYTE M16Ammo;
  BYTE field_76;
  BYTE field_77;
  BYTE Strength;
  BYTE CiviliansKilled;
  BYTE field_7A;
  BYTE field_7B;
  BYTE field_7C;
  BYTE field_7D;
  BYTE field_7E;
  BYTE Reflexes;
  DWORD field_80;
  Thing *fae_Thing_Ptr;
static Player *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif