#ifndef UCC_GENERICS_H
#define UCC_GENERICS_H

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#pragma warning(disable : 4100) /* unreferenced formal parameter */
#pragma warning(disable : 4731) /* frame pointer register modified by inline assembly code */

typedef signed __int8 SBYTE;
typedef signed __int16 SWORD;
typedef signed __int32 SDWORD;

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;

#include "Syringe.h"

#include "ASMMacros.h"

#define ALIAS(Type, Obj, Addr) \
	Type &Obj = *(Type *)(Addr);

#define ALIAS_O(Type, Obj, Addr) \
	Type Obj = (Type )(Addr);

#endif
