/*
	---------------------------------------------------------------------------
	Copyright (c) 2003, Dominik Reichl <dominik.reichl@t-online.de>, Germany.
	All rights reserved.

	Distributed under the terms of the GNU General Public License v2.

	This software is provided 'as is' with no explicit or implied warranties
	in respect of its properties, including, but not limited to, correctness 
	and/or fitness for purpose.
	---------------------------------------------------------------------------
*/

#ifndef ___RH_SYSTEM_CONFIG_H___
#define ___RH_SYSTEM_CONFIG_H___

//////////////////////////////////////////////////////////////////////////////
// Start build mode
// #define or #undef RH_DEBUG
#define RH_DEBUG
#define RH_RELEASE
// End build mode
//////////////////////////////////////////////////////////////////////////////
// If you define RH_RELEASE, RH_DEBUG will be undefined
//////////////////////////////////////////////////////////////////////////////

#define RH_LITTLE_ENDIAN
#undef RH_BIG_ENDIAN

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <direct.h>
#include <limits.h>
#include <memory.h>
#include <string.h>
#include <errno.h>

// Don't change this!!!:
#ifdef RH_RELEASE
#undef RH_DEBUG
#endif

// Only for release version:
#ifndef RH_DEBUG
#pragma warning(disable : 4101) /* Unused variable */
#endif

#ifndef __cplusplus
#error You need a CPlusPlus compiler to compile the ReHash project
#endif

#define RH_TARGET_SYSTEM_NULL    0
#define RH_TARGET_SYSTEM_WINDOWS 1
#define RH_TARGET_SYSTEM_LINUX   2

#if defined(WIN32)
#define RH_TARGET_SYSTEM RH_TARGET_SYSTEM_WINDOWS
#elif defined(_WIN32)
#define RH_TARGET_SYSTEM RH_TARGET_SYSTEM_WINDOWS
#elif defined(MSC_VER)
#define RH_TARGET_SYSTEM RH_TARGET_SYSTEM_WINDOWS
#elif defined(_MSC_VER)
#define RH_TARGET_SYSTEM RH_TARGET_SYSTEM_WINDOWS
#else
#define RH_TARGET_SYSTEM RH_TARGET_SYSTEM_LINUX
#endif // RH_TARGET_SYSTEM is now defined

#if (RH_TARGET_SYSTEM == RH_TARGET_SYSTEM_WINDOWS)
#define CPS_NEWLINE "\r\n"
#else
#define CPS_NEWLINE "\n"
#endif

#define recursivesafe /* recursive safe variable declaration */

#if (RH_TARGET_SYSTEM == RH_TARGET_SYSTEM_WINDOWS)
#define SZ_DIR_CHAR '\\'
#define SZ_DIR_STR  "\\"
#define SZ_LEVEL_UP ".\\..\\"
#define SZ_DIR_ALL "*"
#else
#define SZ_DIR_CHAR '/'
#define SZ_DIR_STR  "/"
#define SZ_LEVEL_UP "./../"
#define SZ_DIR_ALL "*"
#endif

#ifndef strlwr
#define strlwr _strlwr
#endif
#ifndef fullpath
#define fullpath _fullpath
#endif
#ifndef findfirst
#define findfirst _findfirst
#endif
#ifndef findnext
#define findnext _findnext
#endif
#ifndef findclose
#define findclose _findclose
#endif
#ifndef finddata
#define finddata _finddata_t
#endif
#ifndef chdir
#define chdir _chdir
#endif
#ifndef getcwd
#define getcwd _getcwd
#endif

#ifdef _MSC_VER
#ifndef CONST
#define CONST64(n) n ## ui64
#endif
#ifndef ulong64
typedef unsigned __int64 ulong64;
#endif
#else
#ifndef CONST64
#define CONST64(n) n ## ULL
#endif
#ifndef ulong64
typedef unsigned long long ulong64;
#endif
#endif

// Based on LibTomCrypt's cryptography library
#ifndef LOAD64L
#define LOAD64L(x, y)                                                       \
     { x = (((ulong64)((y)[7] & 255))<<56)|(((ulong64)((y)[6] & 255))<<48)| \
           (((ulong64)((y)[5] & 255))<<40)|(((ulong64)((y)[4] & 255))<<32)| \
           (((ulong64)((y)[3] & 255))<<24)|(((ulong64)((y)[2] & 255))<<16)| \
           (((ulong64)((y)[1] & 255))<<8)|(((ulong64)((y)[0] & 255))); }
#define STORE64L(x, y)                                                                   \
     { (y)[7] = (unsigned char)(((x)>>56)&255); (y)[6] = (unsigned char)(((x)>>48)&255); \
       (y)[5] = (unsigned char)(((x)>>40)&255); (y)[4] = (unsigned char)(((x)>>32)&255); \
       (y)[3] = (unsigned char)(((x)>>24)&255); (y)[2] = (unsigned char)(((x)>>16)&255); \
       (y)[1] = (unsigned char)(((x)>>8)&255); (y)[0] = (unsigned char)((x)&255); }
#endif

#ifndef MIN
#define MAX(x, y) (((x)>(y))?(x):(y))
#define MIN(x, y) (((x)<(y))?(x):(y))
#endif

#define HAVAL_PASS     5 /* 3, 4, or 5 */
#define HAVAL_FPTLEN 256 /* 128, 160, 192, 224 or 256 */

#endif // ___RH_SYSTEM_CONFIG_H___
