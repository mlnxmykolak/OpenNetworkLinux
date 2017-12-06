/*
 * mlnx_common_thermali.c
 *
 *  Created on: Nov 24, 2017
 *      Author: c_mykolak
 */
#include <fcntl.h>
#include <unistd.h>
#include <AIM/aim_log.h>
#include <onlplib/file.h>
#include <onlplib/mmap.h>
#include <onlp/platformi/thermali.h>
#include "mlnx_common/mlnx_common.h"

#define prefix_path "/bsp/thermal"

#define VALIDATE(_id)                           \
    do {                                        \
        if(!ONLP_OID_IS_THERMAL(_id)) {         \
            return ONLP_STATUS_E_INVALID;       \
        }                                       \
    } while(0)

/*
 * Retrieve the information structure for the given thermal OID.
 *
 * If the OID is invalid, return ONLP_E_STATUS_INVALID.
 * If an unexpected error occurs, return ONLP_E_STATUS_INTERNAL.
 * Otherwise, return ONLP_STATUS_OK with the OID's information.
 *
 * Note -- it is expected that you fill out the information
 * structure even if the sensor described by the OID is not present.
 */
int
onlp_thermali_info_get(onlp_oid_t id, onlp_thermal_info_t* info)
{
    int   rv, len = 10, temp_base=1, local_id = 0;
    char  r_data[10]   = {0};
    VALIDATE(id);

    local_id = ONLP_OID_ID_GET(id);

    mlnx_platform_info_t* mlnx_platform_info = get_platform_info();

    /* Set the onlp_oid_hdr_t and capabilities */
    *info = mlnx_platform_info->tinfo[local_id];

    rv = onlp_file_read((uint8_t*)r_data, sizeof(r_data), &len, "%s/%s",
                        prefix_path, mlnx_platform_info->thermal_fnames[local_id]);
    if (rv < 0) {
        return ONLP_STATUS_E_INTERNAL;
    }

    info->mcelsius = atoi(r_data) / temp_base;

    return ONLP_STATUS_OK;
}
