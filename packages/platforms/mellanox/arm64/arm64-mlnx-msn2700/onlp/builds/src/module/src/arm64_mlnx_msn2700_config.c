/**************************************************************************//**
 *
 *
 *
 *****************************************************************************/
#include <arm64mlnx_msn2700/arm64mlnx_msn2700_config.h>

/* <auto.start.cdefs(arm64mlnx_msn2700_CONFIG_HEADER).source> */
#define __arm64mlnx_msn2700_config_STRINGIFY_NAME(_x) #_x
#define __arm64mlnx_msn2700_config_STRINGIFY_VALUE(_x) __arm64mlnx_msn2700_config_STRINGIFY_NAME(_x)
arm64mlnx_msn2700_config_settings_t arm64mlnx_msn2700_config_settings[] =
{
#ifdef arm64mlnx_msn2700_CONFIG_INCLUDE_LOGGING
    { __arm64mlnx_msn2700_config_STRINGIFY_NAME(arm64mlnx_msn2700_CONFIG_INCLUDE_LOGGING), __arm64mlnx_msn2700_config_STRINGIFY_VALUE(arm64mlnx_msn2700_CONFIG_INCLUDE_LOGGING) },
#else
{ arm64mlnx_msn2700_CONFIG_INCLUDE_LOGGING(__arm64mlnx_msn2700_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef arm64mlnx_msn2700_CONFIG_LOG_OPTIONS_DEFAULT
    { __arm64mlnx_msn2700_config_STRINGIFY_NAME(arm64mlnx_msn2700_CONFIG_LOG_OPTIONS_DEFAULT), __arm64mlnx_msn2700_config_STRINGIFY_VALUE(arm64mlnx_msn2700_CONFIG_LOG_OPTIONS_DEFAULT) },
#else
{ arm64mlnx_msn2700_CONFIG_LOG_OPTIONS_DEFAULT(__arm64mlnx_msn2700_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef arm64mlnx_msn2700_CONFIG_LOG_BITS_DEFAULT
    { __arm64mlnx_msn2700_config_STRINGIFY_NAME(arm64mlnx_msn2700_CONFIG_LOG_BITS_DEFAULT), __arm64mlnx_msn2700_config_STRINGIFY_VALUE(arm64mlnx_msn2700_CONFIG_LOG_BITS_DEFAULT) },
#else
{ arm64mlnx_msn2700_CONFIG_LOG_BITS_DEFAULT(__arm64mlnx_msn2700_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef arm64mlnx_msn2700_CONFIG_LOG_CUSTOM_BITS_DEFAULT
    { __arm64mlnx_msn2700_config_STRINGIFY_NAME(arm64mlnx_msn2700_CONFIG_LOG_CUSTOM_BITS_DEFAULT), __arm64mlnx_msn2700_config_STRINGIFY_VALUE(arm64mlnx_msn2700_CONFIG_LOG_CUSTOM_BITS_DEFAULT) },
#else
{ arm64mlnx_msn2700_CONFIG_LOG_CUSTOM_BITS_DEFAULT(__arm64mlnx_msn2700_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef arm64mlnx_msn2700_CONFIG_PORTING_STDLIB
    { __arm64mlnx_msn2700_config_STRINGIFY_NAME(arm64mlnx_msn2700_CONFIG_PORTING_STDLIB), __arm64mlnx_msn2700_config_STRINGIFY_VALUE(arm64mlnx_msn2700_CONFIG_PORTING_STDLIB) },
#else
{ arm64mlnx_msn2700_CONFIG_PORTING_STDLIB(__arm64mlnx_msn2700_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef arm64mlnx_msn2700_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS
    { __arm64mlnx_msn2700_config_STRINGIFY_NAME(arm64mlnx_msn2700_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS), __arm64mlnx_msn2700_config_STRINGIFY_VALUE(arm64mlnx_msn2700_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS) },
#else
{ arm64mlnx_msn2700_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS(__arm64mlnx_msn2700_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef arm64mlnx_msn2700_CONFIG_INCLUDE_UCLI
    { __arm64mlnx_msn2700_config_STRINGIFY_NAME(arm64mlnx_msn2700_CONFIG_INCLUDE_UCLI), __arm64mlnx_msn2700_config_STRINGIFY_VALUE(arm64mlnx_msn2700_CONFIG_INCLUDE_UCLI) },
#else
{ arm64mlnx_msn2700_CONFIG_INCLUDE_UCLI(__arm64mlnx_msn2700_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef arm64mlnx_msn2700_CONFIG_INCLUDE_DEFAULT_FAN_DIRECTION
    { __arm64mlnx_msn2700_config_STRINGIFY_NAME(arm64mlnx_msn2700_CONFIG_INCLUDE_DEFAULT_FAN_DIRECTION), __arm64mlnx_msn2700_config_STRINGIFY_VALUE(arm64mlnx_msn2700_CONFIG_INCLUDE_DEFAULT_FAN_DIRECTION) },
#else
{ arm64mlnx_msn2700_CONFIG_INCLUDE_DEFAULT_FAN_DIRECTION(__arm64mlnx_msn2700_config_STRINGIFY_NAME), "__undefined__" },
#endif
    { NULL, NULL }
};
#undef __arm64mlnx_msn2700_config_STRINGIFY_VALUE
#undef __arm64mlnx_msn2700_config_STRINGIFY_NAME

const char*
arm64mlnx_msn2700_config_lookup(const char* setting)
{
    int i;
    for(i = 0; arm64mlnx_msn2700_config_settings[i].name; i++) {
        if(strcmp(arm64mlnx_msn2700_config_settings[i].name, setting)) {
            return arm64mlnx_msn2700_config_settings[i].value;
        }
    }
    return NULL;
}

int
arm64mlnx_msn2700_config_show(struct aim_pvs_s* pvs)
{
    int i;
    for(i = 0; arm64mlnx_msn2700_config_settings[i].name; i++) {
        aim_printf(pvs, "%s = %s\n", arm64mlnx_msn2700_config_settings[i].name, arm64mlnx_msn2700_config_settings[i].value);
    }
    return i;
}

/* <auto.end.cdefs(arm64mlnx_msn2700_CONFIG_HEADER).source> */

