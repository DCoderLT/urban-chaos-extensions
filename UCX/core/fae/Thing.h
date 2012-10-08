#ifndef UCC_FAE_THING_H
#define UCC_FAE_THING_H

#include "../Generic.h"
#include "../Geometry.h"

#include "AttachedPtr.h"
#include "DrawTween.h"

using namespace UCX::Core;

namespace UCX {
	namespace Core {
		namespace fae {

				#pragma pack(push, 1)

				struct Thing
				{
					BYTE Type;
					BYTE State;
					BYTE field_2;
					BYTE Substate;
					DWORD Flags;
					WORD NextObject;
					WORD PrevObject;
					WORD PrevIndex;
					WORD NextIndex;
					DWPoint3D XYZ;
					void (__cdecl *Callback)(fae::Thing *context);
					fae::DrawTween *DrawTween;
					fae::AttachedPtr AttachedObject;
					DWORD field_28;
					DWORD field_2C;
					WORD field_30;
					WORD AnimAllIndex;
					WORD PrimFace4;
					WORD NextThingIndex;
					DWORD field_38;

					static Thing *& Instances;
					static int *& Instance_Count;
				};
				#pragma pack(pop)

		};
	};
};

#endif