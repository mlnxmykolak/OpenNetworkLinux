/**************************************************************************//**
 *
 * @file
 * @brief mlnx_common Main Interface Header
 *
 * @addtogroup mlnx_common
 * @{
 *
 *****************************************************************************/
#ifndef __MLNX_COMMON_H__
#define __MLNX_COMMON_H__

#define PLATFORM_NAME_MAX_LEN		64

#ifndef KERNEL_VERSION
#define KERNEL_VERSION(a,b,c) (((a) << 16) + ((b) << 8) + (c))
#endif

/** Specific platform info structure. */
typedef struct mlnx_platform_info_s {
    char onl_platform_name[PLATFORM_NAME_MAX_LEN];
    char onie_platform_name[PLATFORM_NAME_MAX_LEN];	/* ToDo check if can be different and remove if not. */
    int sfp_num;
    int led_num;
    int psu_num;
    int fan_num;
    int thermal_num;
    int cpld_num;
    bool psu_fixed;
    bool fan_fixed;
} mlnx_platform_info_t;

int mc_get_kernel_ver(void);

int mc_get_platform_info(mlnx_platform_info_t* mlnx_platform);

#endif /* __MLNX_COMMON_H__ */
/* @} */
