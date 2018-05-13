#ifndef __Platform_H_
#define __Platform_H_

#define _PLATFORM_UNDEFINED	0
#define _PLATFORM_WIN32		1
#define _PLATFORM_LINUX     2
#define _PLATFORM_UNIX      3
#define _PLATFORM_ANDROID	4
#define _PLATFORM_POSIX     5
#define _PLATFORM_IOS       6
#define _PLATFORM_MAC       6



#define _COMPILER_UNDEFINED	0
#define _COMPILER_MSVC		1
#define _COMPILER_GNUC		2

#define _ENDIAN_UNKNOWN		0xFFFFFFFF
#define _ENDIAN_LITTLE		0x00000001
#define _ENDIAN_BIG			0x01000000
#define _ENDIAN_PDP			0x00010000

#define _ARCHITECTURE_32	1
#define _ARCHITECTURE_64	2

#define _CPP_VER_UNDEFINED	0L
#define _CPP_VER_98			199711L
#define _CPP_VER_11			201103L
#define _CPP_VER_14		    201402L


/** Finds the compiler type and version
*/
#if defined( _MSC_VER )
#	define _COMPILER_TYPE	_COMPILER_MSVC
#   define _COMPILER_VER	_MSC_VER
#elif defined( __GNUC__ )
#   define _COMPILER_TYPE	_COMPILER_GNUC
#   define _COMPILER_VER	(((__GNUC__) * 100) + \
                                (__GNUC_MINOR__ * 10) + \
                                __GNUC_PATCHLEVEL__)
#else
#	define _COMPILER_TYPE	_COMPILER_UNDEFINED
#   define _COMPILER_VER		0
#endif

/** define Visual c++ version
*/
#if _COMPILER_TYPE == _COMPILER_MSVC
#   define _COMPILER_MSVC_4	        1000
#   define _COMPILER_MSVC_5	        1100
#   define _COMPILER_MSVC_6	        1200
#   define _COMPILER_MSVC_7	        1300
#   define _COMPILER_MSVC_7_1	    1310
#   define _COMPILER_MSVC_8	        1400
#   define _COMPILER_MSVC_9	        1500
#   define _COMPILER_MSVC_10	    1600
#   define _COMPILER_MSVC_11	    1700
#   define _COMPILER_MSVC_12	    1800
#   define _COMPILER_MSVC_14	    1900
#   define _COMPILER_MSVC_14_1	    1910
#   define _COMPILER_MSVC_14_1_1    1911
#   define _COMPILER_MSVC_14_1_2    1912
#   define _COMPILER_MSVC_14_1_3    1913
#   define _COMPILER_MSVC_14_1_4    1914
#endif

#define _COMPILER_MIN_VERSION(COMPILER_TYPE, COMPILER_VERSION) \
    (_COMPILER_TYPE == (COMPILER_TYPE) && _COMPILER_VER >= (COMPILER_VERSION))

/** Finds the c++ version
*/
#if defined(__cplusplus)
#	if __cplusplus >= _CPP_VER_14
#		define _CPP_VER _CPP_VER_14
#	elif __cplusplus >= _CPP_VER_11
#		define _CPP_VER _CPP_VER_11
#	elif __cplusplus >= _CPP_VER_98
#		define _CPP_VER _CPP_VER_98
#	else
#		define _CPP_VER _CPP_VER_UNDEFINED
#	endif
#endif

/** Finds the current platform
*/
#if defined(_WIN32)
#   define _PLATFORM_TYPE _PLATFORM_WIN32
//#	include <Windows.h>
#   if (defined(_WIN32_WINNT_WIN8) && _WIN32_WINNT >= _WIN32_WINNT_WIN8)
#       define _HAVE_DIRECTXMATH 1
#	else
#		define _HAVE_DIRECTXMATH 0
#   endif
#   if  !(defined  _CRT_SECURE_NO_WARNINGS)
#       define _CRT_SECURE_NO_WARNINGS
#   endif
#   if !(defined _SCL_SECURE_NO_WARNINGS)
#       define _SCL_SECURE_NO_WARNINGS
#   endif
#elif defined(__APPLE__)
#   include "TargetConditionals.h"
#   if TARGET_IPHONE_SIMULATOR
#       define _PLATFORM_TYPE _PLATFORM_IOS
#   elif TARGET_OS_IPHONE
#       define _PLATFORM_TYPE _PLATFORM_IOS
#   elif TARGET_OS_MAC
#       define _PLATFORM_TYPE _PLATFORM_MAC
#   else
#       define _PLATFORM_TYPE _PLATFORM_UNDEFINED
#endif
#elif defined(__ANDROID__)
#   define _PLATFORM_TYPE _PLATFORM_ANDROID
#elif defined(__linux__)
#   define _PLATFORM_TYPE _PLATFORM_LINUX
#elif defined(__unix__) // all unices not caught above
#   include <unistd.h>
#   define _PLATFORM_TYPE _PLATFORM_UNIX
#elif defined(_POSIX_VERSION)
#   define _PLATFORM_TYPE _PLATFORM_POSIX
#else
#   define _PLATFORM_TYPE _PLATFORM_UNDEFINED
#endif

/** Find the arch type
*/
#if defined(__ia64) || defined(__itanium__) || defined(_M_IA64) || \
    defined(__powerpc64__) || defined(__ppc64__) || defined(__PPC64__) || \
    defined(__x86_64__) || defined(_M_X64) || defined(__sparc)
#   define _ARCHITECTURE_TYPE _ARCHITECTURE_64
#else
#   define _ARCHITECTURE_TYPE _ARCHITECTURE_32
#endif

/** Find the current endian
*/
#if ((1 & 0xFFFFFFFF) == _ENDIAN_LITTLE)
#	define _ENDIAN_TYPE _ENDIAN_LITTLE
#elif ((1 & 0xFFFFFFFF) == _ENDIAN_BIG)
#	define _ENDIAN_TYPE _ENDIAN_BIG
#elif ((1 & 0xFFFFFFFF) == _ENDIAN_PDP)
#	define _ENDIAN_TYPE _ENDIAN_PDP
#else
#	define _ENDIAN_TYPE _ENDIAN_UNKNOWN
#endif

#endif