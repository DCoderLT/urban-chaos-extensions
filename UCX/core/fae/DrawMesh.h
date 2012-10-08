#ifndef UCC_FAE_DRAW_MESH_H
#define UCC_FAE_DRAW_MESH_H

#include "../Generic.h"
#include "../Geometry.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

struct Thing;

		#pragma pack(push, 1)
struct DrawMesh
{
  WORD field_0;
  WORD field_2;
  DWORD field_4;
  BYTE field_8;
  BYTE field_9;
static DrawMesh *& Instances;
static int *& Instance_Count;

};
#pragma pack(pop)

		};
	};
};

#endif