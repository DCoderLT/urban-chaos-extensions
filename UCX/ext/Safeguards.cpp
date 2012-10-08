#include "../core/FileSystem.h"

using namespace UCX::Core;

DEFINE_HOOK(0x444704, Lighting_LoadFromFile, 8)
{
	GET(DWORD, Handle, EBP);
	return (Handle == Filesystem::InvalidHandleValue)
		? 0x444AFB
		: 0x44470C
	;
}

DEFINE_HOOK(0x496F16, Resource_GetClumpsFile, 5)
{
	GET_STACK(char *, filename, 0x104);
	return (filename)
		? 0
		: 0x496F2E
	;
}
