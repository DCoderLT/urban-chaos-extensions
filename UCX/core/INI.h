#ifndef UCC_INI_H
#define UCC_INI_H

#include "Generic.h"

namespace UCX {
	namespace Core {

		/* these functions work with the game's config file with no way to override it */

		namespace INI {
			/* uses a static char[] to store the result - duplicate the result instead of caching the pointer */
			inline char *__cdecl GetString(const char * KeyName, const char * SectionName) 
				{ JMP_STD(0x41C700); }

			inline int __cdecl GetInteger(const char * KeyName, int Default, const char * SectionName)
				{ JMP_STD(0x41C740); }

			inline int __cdecl SetString(const char * KeyName, const char * SectionName, const char *Value)
				{ JMP_STD(0x41C7A0); }

			inline int __cdecl SetInteger(const char * KeyName, int Value, const char * SectionName)
				{ JMP_STD(0x41C7C0); }

		};
	};
};

#endif