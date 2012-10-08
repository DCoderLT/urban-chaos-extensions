#include "../core/Generic.h"
#include "../core/Net.h"
#include "Debug.h"

using namespace UCX::Ext;

#ifdef INCLUDE_NETWORK
DEFINE_HOOK(0x42C5D4, MainLoop_EnterNetworking, 5)
{
	 UCX::Core::Networking::DirectPlay_Initialize();

	return 0x42C5F5;
}


DEFINE_HOOK(0x4C20BA, Network_CreateSession_OpenSession, 8)
{
	GET(HRESULT, hr, EAX);

	Debug::Log("OpenSession = %X\n", hr);

	if(SUCCEEDED(hr)) {
		return 0x4C20C2;
	} else {
		return 0x4C2143;
	}
}


DEFINE_HOOK(0x4C2113, Network_CreateSession_CreatePlayer, 9)
{
	GET(HRESULT, hr, EAX);

	Debug::Log("CreatePlayer = %X\n", hr);
	
	if(SUCCEEDED(hr)) {
		R->EAX(1);
		return 0x4C211C;
	} else {
		return 0x4C2143;
	}

}
#endif
