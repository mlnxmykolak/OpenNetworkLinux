/**************************************************************************//**
 *
 * @file
 * @brief arm64mlnx_msn2700 Configuration Header
 *
 * @addtogroup arm64mlnx_msn2700-config
 * @{
 *
 *****************************************************************************/
#ifndef __arm64mlnx_msn2700_CONFIG_H__
#define __arm64mlnx_msn2700_CONFIG_H__

#ifdef GLOBAL_INCLUDE_CUSTOM_CONFIG
#include <global_custom_config.h>
#endif
#ifdef arm64mlnx_msn2700_INCLUDE_CUSTOM_CONFIG
#include <arm64mlnx_msn2700_custom_config.h>
#endif

/* <auto.start.cdefs(arm64mlnx_msn2700_CONFIG_HEADER).header> */
#include <AIM/aim.h>
/**
 * arm64mlnx_msn2700_CONFIG_INCLUDE_LOGGING
 *
 * Include or exclude logging. */


#ifndef arm64mlnx_msn2700_CONFIG_INCLUDE_LOGGING
#define arm64mlnx_msn2700_CONFIG_INCLUDE_LOGGING 1
#endif

/**
 * arm64mlnx_msn2700_CONFIG_LOG_OPTIONS_DEFAULT
 *
 * Default enabled log options. */


#ifndef arm64mlnx_msn2700_CONFIG_LOG_OPTIONS_DEFAULT
#define arm64mlnx_msn2700_CONFIG_LOG_OPTIONS_DEFAULT AIM_LOG_OPTIONS_DEFAULT
#endif

/**
 * arm64mlnx_msn2700_CONFIG_LOG_BITS_DEFAULT
 *
 * Default enabled log bits. */


#ifndef arm64mlnx_msn2700_CONFIG_LOG_BITS_DEFAULT
#define arm64mlnx_msn2700_CONFIG_LOG_BITS_DEFAULT AIM_LOG_BITS_DEFAULT
#endif

/**
 * arm64mlnx_msn2700_CONFIG_LOG_CUSTOM_BITS_DEFAULT
 *
 * Default enabled custom log bits. */


#ifndef arm64mlnx_msn2700_CONFIG_LOG_CUSTOM_BITS_DEFAULT
#define arm64mlnx_msn2700_CONFIG_LOG_CUSTOM_BITS_DEFAULT 0
#endif

/**
 * arm64mlnx_msn2700_CONFIG_PORTING_STDLIB
 *
 * Default all porting macros to use the C standard libraries. */


#ifndef arm64mlnx_msn2700_CONFIG_PORTING_STDLIB
#define arm64mlnx_msn2700_CONFIG_PORTING_STDLIB 1
#endif

/**
 * arm64mlnx_msn2700_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS
 *
 * Include standard library headers for stdlib porting macros. */


#ifndef arm64mlnx_msn2700_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS
#define arm64mlnx_msn2700_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS arm64mlnx_msn2700_CONFIG_PORTING_STDLIB
#endif

/**
 * arm64mlnx_msn2700_CONFIG_INCLUDE_UCLI
 *
 * Include generic uCli support. */


#ifndef arm64mlnx_msn2700_CONFIG_INCLUDE_UCLI
#define arm64mlnx_msn2700_CONFIG_INCLUDE_UCLI 0
#endif

/**
 * arm64mlnx_msn2700_CONFIG_INCLUDE_DEFAULT_FAN_DIRECTION
 *
 * Assume chassis fan direction is the same as the PSU fan direction. */


#ifndef arm64mlnx_msn2700_CONFIG_INCLUDE_DEFAULT_FAN_DIRECTION
#define arm64mlnx_msn2700_CONFIG_INCLUDE_DEFAULT_FAN_DIRECTION 0
#endif



/**
 * All compile time options can be queried or displayed
 */

/** Configuration settings structure. */
typedef struct arm64mlnx_msn2700_config_settings_s {
    /** name */
    const char* name;
    /** value */
    const char* value;
} arm64mlnx_msn2700_config_settings_t;

/** Configuration settings table. */
/** arm64mlnx_msn2700_config_settings table. */
extern arm64mlnx_msn2700_config_settings_t arm64mlnx_msn2700_config_settings[];

/**
 * @brief Lookup a configuration setting.
 * @param setting The name of the configuration option to lookup.
 */
const char* arm64mlnx_msn2700_config_lookup(const char* setting);

/**
 * @brief Show the compile-time configuration.
 * @param pvs The output stream.
 */
int arm64mlnx_msn2700_config_show(struct aim_pvs_s* pvs);

/* <auto.end.cdefs(arm64mlnx_msn2700_CONFIG_HEADER).header> */

#include "arm64mlnx_msn2700_porting.h"

#endif /* __arm64mlnx_msn2700_CONFIG_H__ */
/* @} */
