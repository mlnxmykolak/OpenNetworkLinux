/************************************************************
 * <bsn.cl fy=2014 v=onl>
 *
 *           Copyright 2014 Big Switch Networks, Inc.
 *
 * Licensed under the Eclipse Public License, Version 1.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *        http://www.eclipse.org/legal/epl-v10.html
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the
 * License.
 *
 * </bsn.cl>
 ************************************************************
 *
 *
 *
 ***********************************************************/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <onlplib/file.h>
#include <onlp/platformi/fani.h>
#include <onlp/platformi/ledi.h>
#include <onlp/platformi/psui.h>
#include <onlp/platformi/sysi.h>
#include <onlp/platformi/thermali.h>
#include "mlnx_common_log.h"
#include "mlnx_common_int.h"
#include "mlnx_common/mlnx_common.h"

mlnx_platform_info_t mlnx_platform_info;

static char arr_cplddev_name[MAX_NUM_OF_CPLD][30] =
{
    "cpld_brd_version",
    "cpld_mgmt_version",
    "cpld_port_version"
};

mlnx_platform_info_t* get_platform_info()
{
	return &mlnx_platform_info;
}

const char* onlp_sysi_platform_get()
{
	if (mc_get_platform_info(&mlnx_platform_info) < 0) {
		AIM_LOG_ERROR("Unable to get paltform info!\n");
		return NULL;
	}
	else
		return mlnx_platform_info.onl_platform_name;
}

int
onlp_sysi_platform_info_get(onlp_platform_info_t* pi)
{
    int   i, v[MAX_NUM_OF_CPLD]={0};
    mlnx_platform_info_t* platform_info = get_platform_info();

    for (i=0; i < platform_info->cpld_num; i++) {
        v[i] = 0;
        if(onlp_file_read_int(v+i, "%s/%s", PREFIX_PATH_ON_CPLD_DEV, arr_cplddev_name[i]) < 0) {
            return ONLP_STATUS_E_INTERNAL;
        }
    }
    switch (platform_info->cpld_num) {
    case 1:
    	pi->cpld_versions = aim_fstrdup("unified=%d", v[0]); /* TBD Currently not exist */
    	break;
    case 2:
    	pi->cpld_versions = aim_fstrdup("brd=%d, mgmt=%d", v[0], v[1]);
    	break;
    case 3:
    	pi->cpld_versions = aim_fstrdup("brd=%d, mgmt=%d, port=%d", v[0], v[1], v[2]);
    	break;
    case 0:
    default:
    	AIM_LOG_ERROR("Incorrect CPLD Number %d\n", platform_info->cpld_num);
    	return ONLP_STATUS_E_INTERNAL;
    }

    return ONLP_STATUS_OK;
}

void
onlp_sysi_platform_info_free(onlp_platform_info_t* pi)
{
    aim_free(pi->cpld_versions);
}


