#ifndef UCE_DEBUG_H
#define UCE_DEBUG_H

#pragma comment ( lib, "dbghelp.lib" )

#include "../core/Syringe.h"
#include "../core/ASMMacros.h"

#include <Dbghelp.h>
#include <cstdio>

#include "../core/Statics.h"

namespace UCX {
	namespace Ext {
		namespace Debug {
			extern bool bLog;
			extern FILE* pLogFile;
			extern wchar_t LogFileName[MAX_PATH];
			extern wchar_t LogFileTempName[MAX_PATH];

			void MakeLogFile();
			void LogFileOpen();
			void LogFileClose();
			void LogFileRemove();

			void Log(const char *Format, ...);

			LONG WINAPI ExceptionHandler(LPEXCEPTION_POINTERS pExs);

			void CreateDump(MINIDUMP_EXCEPTION_INFORMATION *pException, wchar_t * generatedFilename = NULL);

			void DumpStack(UCX::Core::REGISTERS *R, DWORD endOffset, DWORD startOffset = 0);
		};
	};
};

#endif
