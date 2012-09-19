#ifndef UCC_CRT_H
#define UCC_CRT_H

#include <cstdio>
#include "ASMMacros.h"

namespace CRTpp {
	inline size_t __cdecl fwrite(const void *Str, size_t Size, size_t Count, FILE *File)
		{ JMP_STD(0x4D3730); }

	inline size_t __cdecl fread(void *DstBuf, size_t ElementSize, size_t Count, FILE *File)
		{ JMP_STD(0x4D1730); }
};

#endif
