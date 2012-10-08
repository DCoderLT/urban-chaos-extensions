#ifndef UCC_FAE_PRIM_INFO_H
#define UCC_FAE_PRIM_INFO_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct PrimInfo
{
  DWORD MinX;
  DWORD MinY;
  DWORD MinZ;
  DWORD MaxX;
  DWORD MaxY;
  DWORD MaxZ;
  DWORD field_18;
  DWORD field_1C;
  DWORD field_20;
  DWORD Magnitude;
static PrimInfo *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif