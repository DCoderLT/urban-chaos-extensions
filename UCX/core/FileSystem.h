#ifndef UCC_FILESYSTEM_H
#define UCC_FILESYSTEM_H

#include "Generic.h"

namespace UCX {
	namespace Core {

		namespace Filesystem {
			enum { InvalidHandleValue = 0xFFFFFF9C, InvalidSharedHandleValue = 0xFFFFFF9A, 
				InvalidRead = 0xFFFFFF98, InvalidWrite = 0xFFFFFF97,
				InvalidSeek = 0xFFFFFF96
			};

			struct FileSeekMethod {
				typedef unsigned int Value;
				enum {
					Beginning = 0,
					Current = 1,
					End = 2,
				};
			};

			inline int __cdecl File_Exists(const char * FileName)
				{ JMP_STD(0x4E66F0); }

			/*
			 * note - on error, this returns Filesystem::InvalidHandleValue instead of INVALID_HANDLE_VALUE
			 */
			inline HANDLE __cdecl File_OpenForReading(const char * FileName)
				{ JMP_STD(0x4E670D); }

			inline BOOL __cdecl File_Close(HANDLE hFile)
				{ JMP_STD(0x4E6758); }

			/*
			 * on error, this returns Filesystem::InvalidSharedHandleValue
			 */
			inline HANDLE __cdecl File_CreateForRW(const char * FileName, BOOL ShareWriteInsteadOfRead)
				{ JMP_STD(0x4E6767); }

			inline BOOL __cdecl File_Delete(const char * FileName)
				{ JMP_STD(0x4E67B8); }

			inline int __cdecl File_SizeOf(HANDLE hFile)
				{ JMP_STD(0x4E67C7); }

			/*
			 * on error, returns Filesystem::InvalidRead
			 */
			inline DWORD __cdecl File_Read(HANDLE hFile, void * Buffer, DWORD NumberOfBytesToRead)
				{ JMP_STD(0x4E67EE); }

			/*
			 * on error, returns Filesystem::InvalidWrite
			 */
			inline DWORD __cdecl File_Write(HANDLE hFile, const void * Buffer, DWORD NumberOfBytesToWrite)
				{ JMP_STD(0x4E681C); }

			/*
			 * on error, returns Filesystem::InvalidSeek
			 */
			inline int __cdecl File_Seek(HANDLE hFile, Filesystem::FileSeekMethod::Value dwMoveMethod, LONG lDistanceToMove)
				{ JMP_STD(0x4E684A); }


		};

	};
};

#endif