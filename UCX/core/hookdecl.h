#ifndef UCC_HOOKDECL_H
#define UCC_HOOKDECL_H

//Use this for DLL export functions
//e.g. EXPORT FunctionName(REGISTERS* R)
#define EXPORT extern "C" __declspec(dllexport) DWORD __cdecl
#define EXPORT_FUNC(name) extern "C" __declspec(dllexport) DWORD __cdecl name (UCX::Core::REGISTERS *R)

#pragma pack(push, 16)
#pragma warning(push)
#pragma warning( disable : 4324)
__declspec(align(16)) struct hookdecl {
	unsigned int hookAddr;
	unsigned int hookSize;
	const char * hookName;
};

__declspec(align(16)) struct hostdecl {
	unsigned int hostChecksum;
	const char * hostName;
};
#pragma warning(pop)
#pragma pack(pop)

#pragma section(".syhks00", read, write)
#pragma section(".syexe00", read, write)
namespace SyringeData {
	namespace Hooks {

	};
	namespace Hosts {

	};
};

#define declhost(exename, checksum) \
namespace SyringeData { namespace Hosts { __declspec(allocate(".syexe00")) hostdecl _hst__ ## exename = { checksum, #exename }; }; };

#define declhook(hook, funcname, size) \
namespace SyringeData { namespace Hooks { __declspec(allocate(".syhks00")) hookdecl _hk__ ## hook ## funcname = { hook, size, #funcname }; }; };

// injgen
// in addition to the injgen-declaration, also includes the function opening
#define DEFINE_HOOK(hook, funcname, size) \
declhook(hook, funcname, size) \
EXPORT_FUNC(funcname)
// no function opening, use for injgen-decl when repeating the same hook at multiple addrs
#define DEFINE_HOOK_AGAIN(hook, funcname, size) \
declhook(hook, funcname, size)

#endif