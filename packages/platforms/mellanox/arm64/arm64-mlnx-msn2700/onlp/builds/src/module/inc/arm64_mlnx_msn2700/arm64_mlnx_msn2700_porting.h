/**************************************************************************//**
 *
 * @file
 * @brief arm64_mlnx_msn2700 Porting Macros.
 *
 * @addtogroup arm64_mlnx_msn2700-porting
 * @{
 *
 *****************************************************************************/
#ifndef __arm64_mlnx_msn2700_PORTING_H__
#define __arm64_mlnx_msn2700_PORTING_H__


/* <auto.start.portingmacro(ALL).define> */
#if arm64_mlnx_msn2700_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS == 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <memory.h>
#endif

#ifndef arm64_mlnx_msn2700_MALLOC
    #if defined(GLOBAL_MALLOC)
        #define arm64_mlnx_msn2700_MALLOC GLOBAL_MALLOC
    #elif arm64_mlnx_msn2700_CONFIG_PORTING_STDLIB == 1
        #define arm64_mlnx_msn2700_MALLOC malloc
    #else
        #error The macro arm64_mlnx_msn2700_MALLOC is required but cannot be defined.
    #endif
#endif

#ifndef arm64_mlnx_msn2700_FREE
    #if defined(GLOBAL_FREE)
        #define arm64_mlnx_msn2700_FREE GLOBAL_FREE
    #elif arm64_mlnx_msn2700_CONFIG_PORTING_STDLIB == 1
        #define arm64_mlnx_msn2700_FREE free
    #else
        #error The macro arm64_mlnx_msn2700_FREE is required but cannot be defined.
    #endif
#endif

#ifndef arm64_mlnx_msn2700_MEMSET
    #if defined(GLOBAL_MEMSET)
        #define arm64_mlnx_msn2700_MEMSET GLOBAL_MEMSET
    #elif arm64_mlnx_msn2700_CONFIG_PORTING_STDLIB == 1
        #define arm64_mlnx_msn2700_MEMSET memset
    #else
        #error The macro arm64_mlnx_msn2700_MEMSET is required but cannot be defined.
    #endif
#endif

#ifndef arm64_mlnx_msn2700_MEMCPY
    #if defined(GLOBAL_MEMCPY)
        #define arm64_mlnx_msn2700_MEMCPY GLOBAL_MEMCPY
    #elif arm64_mlnx_msn2700_CONFIG_PORTING_STDLIB == 1
        #define arm64_mlnx_msn2700_MEMCPY memcpy
    #else
        #error The macro arm64_mlnx_msn2700_MEMCPY is required but cannot be defined.
    #endif
#endif

#ifndef arm64_mlnx_msn2700_STRNCPY
    #if defined(GLOBAL_STRNCPY)
        #define arm64_mlnx_msn2700_STRNCPY GLOBAL_STRNCPY
    #elif arm64_mlnx_msn2700_CONFIG_PORTING_STDLIB == 1
        #define arm64_mlnx_msn2700_STRNCPY strncpy
    #else
        #error The macro arm64_mlnx_msn2700_STRNCPY is required but cannot be defined.
    #endif
#endif

#ifndef arm64_mlnx_msn2700_VSNPRINTF
    #if defined(GLOBAL_VSNPRINTF)
        #define arm64_mlnx_msn2700_VSNPRINTF GLOBAL_VSNPRINTF
    #elif arm64_mlnx_msn2700_CONFIG_PORTING_STDLIB == 1
        #define arm64_mlnx_msn2700_VSNPRINTF vsnprintf
    #else
        #error The macro arm64_mlnx_msn2700_VSNPRINTF is required but cannot be defined.
    #endif
#endif

#ifndef arm64_mlnx_msn2700_SNPRINTF
    #if defined(GLOBAL_SNPRINTF)
        #define arm64_mlnx_msn2700_SNPRINTF GLOBAL_SNPRINTF
    #elif arm64_mlnx_msn2700_CONFIG_PORTING_STDLIB == 1
        #define arm64_mlnx_msn2700_SNPRINTF snprintf
    #else
        #error The macro arm64_mlnx_msn2700_SNPRINTF is required but cannot be defined.
    #endif
#endif

#ifndef arm64_mlnx_msn2700_STRLEN
    #if defined(GLOBAL_STRLEN)
        #define arm64_mlnx_msn2700_STRLEN GLOBAL_STRLEN
    #elif arm64_mlnx_msn2700_CONFIG_PORTING_STDLIB == 1
        #define arm64_mlnx_msn2700_STRLEN strlen
    #else
        #error The macro arm64_mlnx_msn2700_STRLEN is required but cannot be defined.
    #endif
#endif

/* <auto.end.portingmacro(ALL).define> */


#endif /* __arm64_mlnx_msn2700_PORTING_H__ */
/* @} */
