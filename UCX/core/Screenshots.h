#ifndef UCC_SCREENSHOTS_H
#define UCC_SCREENSHOTS_H

#include "Generic.h"

#pragma pack(push, 1)
			struct bmpfile_full_header {
				unsigned char magic[2];
				DWORD filesz;
				WORD creator1;
				WORD creator2;
				DWORD bmp_offset;
				DWORD header_sz;
				DWORD width;
				DWORD height;
				WORD nplanes;
				WORD bitspp;
				DWORD compress_type;
				DWORD bmp_bytesz;
				DWORD hres;
				DWORD vres;
				DWORD ncolors;
				DWORD nimpcolors;
				DWORD R; //
				DWORD G; //
				DWORD B; //
			};
#pragma pack(pop)

#endif