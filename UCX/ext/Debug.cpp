#include "Debug.h"

using namespace UCX::Core;
using namespace UCX::Ext;

bool Debug::bLog = true;
FILE* Debug::pLogFile = NULL;
wchar_t Debug::LogFileName[MAX_PATH] = L"\0";
wchar_t Debug::LogFileTempName[MAX_PATH] = L"\0";

void Debug::Log(const char* Format, ...) {
	va_list args;
	va_start(args, Format);
	vfprintf(pLogFile, Format, args);
	va_end(args);
	fflush(pLogFile);
	//	fprintf(pLogFile, "\n");
}

void Debug::LogFileOpen() {
	Debug::LogFileClose();
	Debug::MakeLogFile();

	Debug::pLogFile = _wfopen(LogFileTempName, L"w");
	if(!Debug::pLogFile) {
		MessageBoxA(NULL, "Couldn't open log file for writing", "Oops", MB_OK);
		ExitProcess(1);
	}
	Debug::Log("Opened log file...\n");
}

void Debug::LogFileClose() {
	if(Debug::pLogFile) {
		fclose(Debug::pLogFile);
		CopyFileW(LogFileTempName, LogFileName, FALSE);
	}

	Debug::pLogFile = NULL;
}

void Debug::MakeLogFile() {
	static bool made = 0;
	if(!made) {
		wchar_t path[MAX_PATH];

		SYSTEMTIME time;

		GetLocalTime(&time);
		GetCurrentDirectoryW(MAX_PATH, path);

		swprintf(Debug::LogFileName, MAX_PATH, L"%s\\debug", path);
		CreateDirectoryW(Debug::LogFileName, NULL);

		swprintf(Debug::LogFileTempName, MAX_PATH, L"%s\\debug\\debug.log", 
			path);

		swprintf(Debug::LogFileName, MAX_PATH, L"%s\\debug\\debug.%04u%02u%02u-%02u%02u%02u.log", 
			path, time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond);

		made = 1;
	}
}

void Debug::LogFileRemove() {
	LogFileClose();
	DeleteFileW(LogFileTempName);
}


LONG WINAPI Debug::ExceptionHandler(LPEXCEPTION_POINTERS pExs) {
	SetWindowText(Statics::hWnd, L"Fatal Error in Urban Chaos");

	if (pExs->ExceptionRecord->ExceptionCode == ERROR_MOD_NOT_FOUND ||
		pExs->ExceptionRecord->ExceptionCode == ERROR_PROC_NOT_FOUND)
	{
		Debug::Log("[1] Exiting process with code %X\n", pExs->ExceptionRecord->ExceptionCode);
		ExitProcess(pExs->ExceptionRecord->ExceptionCode);
	}

	switch(pExs->ExceptionRecord->ExceptionCode)
	{
	case EXCEPTION_ACCESS_VIOLATION:
	case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:
	case EXCEPTION_BREAKPOINT:
	case EXCEPTION_DATATYPE_MISALIGNMENT:
	case EXCEPTION_FLT_DENORMAL_OPERAND:
	case EXCEPTION_FLT_DIVIDE_BY_ZERO:
	case EXCEPTION_FLT_INEXACT_RESULT:
	case EXCEPTION_FLT_INVALID_OPERATION:
	case EXCEPTION_FLT_OVERFLOW:
	case EXCEPTION_FLT_STACK_CHECK:
	case EXCEPTION_FLT_UNDERFLOW:
	case EXCEPTION_ILLEGAL_INSTRUCTION:
	case EXCEPTION_IN_PAGE_ERROR:
	case EXCEPTION_INT_DIVIDE_BY_ZERO:
	case EXCEPTION_INT_OVERFLOW:
	case EXCEPTION_INVALID_HANDLE:
	case EXCEPTION_INVALID_DISPOSITION:
	case EXCEPTION_NONCONTINUABLE_EXCEPTION:
	case EXCEPTION_PRIV_INSTRUCTION:
	case EXCEPTION_SINGLE_STEP:
	case EXCEPTION_STACK_OVERFLOW:
	case 0xE06D7363: // exception thrown and not caught
		{
			Debug::Log("[2] Logging and exiting process with code %X\n", pExs->ExceptionRecord->ExceptionCode);

			MINIDUMP_EXCEPTION_INFORMATION expParam;

			expParam.ThreadId = GetCurrentThreadId();
			expParam.ExceptionPointers = pExs;
			expParam.ClientPointers = FALSE;

			Debug::CreateDump(&expParam);

			ExitProcess(pExs->ExceptionRecord->ExceptionCode); // Exit.
			break;
		}
	default:
		Debug::Log("[3] Exiting process with code %X\n", pExs->ExceptionRecord->ExceptionCode);
		ExitProcess(pExs->ExceptionRecord->ExceptionCode); // Exit.
		break;
	}
}

void Debug::DumpStack(UCX::Core::REGISTERS *R, DWORD endOffset, DWORD startOffset) {
	for(DWORD curOffset = startOffset; curOffset < endOffset; curOffset += 4) {
		Debug::Log("esp+%04X = %08X\n", curOffset, R->Stack32(curOffset)); 
	}
}

void Debug::CreateDump(MINIDUMP_EXCEPTION_INFORMATION *pException, wchar_t * generatedFilename) {
	bool g_ExtendedMinidumps = true;

	wchar_t filename[MAX_PATH];
	wchar_t path[MAX_PATH];

	HANDLE dumpFile;
	SYSTEMTIME time;

	GetLocalTime(&time);
	GetCurrentDirectoryW(MAX_PATH, path);

	swprintf(filename, MAX_PATH, L"%s\\debug", path);
	CreateDirectoryW(filename, NULL);

	swprintf(filename, MAX_PATH, g_ExtendedMinidumps ? L"%s\\debug\\extcrashdump.%04u%02u%02u-%02u%02u%02u.dmp" : L"%s\\debug\\crashdump.%04u%02u%02u-%02u%02u%02u.dmp", 
		path, 
		time.wYear, time.wMonth, time.wDay, 
		time.wHour, time.wMinute, time.wSecond);

	dumpFile = CreateFileW(filename, GENERIC_READ | GENERIC_WRITE, 
		FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_FLAG_WRITE_THROUGH, NULL);

	MINIDUMP_TYPE type = (MINIDUMP_TYPE)MiniDumpWithFullMemory;

	MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), dumpFile, type, pException, NULL, NULL);
	CloseHandle(dumpFile);
}


DEFINE_HOOK(0x4C2E19, SEH_Trap, 7)
{
	SetUnhandledExceptionFilter(&Debug::ExceptionHandler);
	return 0;
}

DEFINE_HOOK(0x4DCDF0, ExceptionFilter, 6)
{
	Debug::Log("Caught Exception.. I think?\n");
	GET_STACK(LPEXCEPTION_POINTERS, pExs, 0x8);
	Debug::ExceptionHandler(pExs);
	return 0x4DCF98;
}

DEFINE_HOOK(0x495D30, Log, 5)
{
#ifdef DEBUGBUILD
	LEA_STACK(va_list, ArgList, 0x8);
	GET_STACK(char *, Format, 0x4);

	vfprintf(Debug::pLogFile, Format, ArgList);
	fflush(Debug::pLogFile);
#endif

	return 0;
}


DEFINE_HOOK(0x42D109, sub_42C8B0_FixRecordedGame, 5)
{
	int *Handle = (int *)0xACB114;
	R->EAX(*Handle);
	if(*Handle == (int)(HANDLE)-100) {
		return 0x42D11B;
	}
	return 0x42D10E;
}


DEFINE_HOOK(0x42D76D, IngameMenu_WndProc, 8)
{
	GET(DWORD, success, EAX);

	Debug::Log("Quicksave load status = %d\n", success);

	return success 
		? 0x42D739
		: 0x42D775
	;
}
