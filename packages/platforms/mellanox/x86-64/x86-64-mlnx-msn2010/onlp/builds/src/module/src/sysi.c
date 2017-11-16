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
#include "platform_lib.h"
#include "x86_64_mlnx_msn2010_int.h"
#include "x86_64_mlnx_msn2010_log.h"
#include <mlnx_common/mlnx_common.h>

#define ONL_PLATFORM_NAME  "x86-64-mlnx-msn2010-r0"
#define ONIE_PLATFORM_NAME "x86_64-mlnx_msn2010-r0"

#define COMMAND_OUTPUT_BUFFER        256


int mc_get_platform_info(mlnx_platform_info_t* mlnx_platform)
{
	strncpy(mlnx_platform->onl_platform_name, ONL_PLATFORM_NAME, PLATFORM_NAME_MAX_LEN);
	strncpy(mlnx_platform->onie_platform_name, ONIE_PLATFORM_NAME, PLATFORM_NAME_MAX_LEN);
	mlnx_platform->sfp_num = NUM_OF_SFP_PORT;
	mlnx_platform->led_num = CHASSIS_LED_COUNT;
	mlnx_platform->psu_num = CHASSIS_PSU_COUNT;
	mlnx_platform->fan_num = CHASSIS_FAN_COUNT;
	mlnx_platform->thermal_num = CHASSIS_THERMAL_COUNT;
	mlnx_platform->cpld_num = NUM_OF_CPLD;
	mlnx_platform->psu_fixed = true;
	mlnx_platform->fan_fixed = true;

	return ONLP_STATUS_OK;
}

void
onlp_sysi_platform_info_free(onlp_platform_info_t* pi)
{
    aim_free(pi->cpld_versions);
}


int
onlp_sysi_oids_get(onlp_oid_t* table, int max)
{
    int i;
    onlp_oid_t* e = table;
    memset(table, 0, max*sizeof(onlp_oid_t));

    for (i = 1; i <= CHASSIS_THERMAL_COUNT; i++)
    {
        *e++ = ONLP_THERMAL_ID_CREATE(i);
    }

    for (i = 1; i <= CHASSIS_LED_COUNT; i++)
    {
        *e++ = ONLP_LED_ID_CREATE(i);
    }

    for (i = 1; i <= CHASSIS_PSU_COUNT; i++)
    {
        *e++ = ONLP_PSU_ID_CREATE(i);
    }

    for (i = 1; i <= CHASSIS_FAN_COUNT; i++)
    {
        *e++ = ONLP_FAN_ID_CREATE(i);
    }

    return ONLP_STATUS_OK;
}

int
onlp_sysi_onie_info_get(onlp_onie_info_t* onie)
{
    int rv = onlp_onie_read_json(onie,
                                 "/lib/platform-config/current/onl/etc/onie/eeprom.json");
    if(rv >= 0) {
        if(onie->platform_name) {
            aim_free(onie->platform_name);
        }
        onie->platform_name = aim_strdup(ONIE_PLATFORM_NAME);
    }

    return rv;
}

int
onlp_sysi_platform_manage_leds(void)
{
	int fan_number;
	onlp_led_mode_t mode;
	int min_fan_speed;
	enum onlp_led_id fan_led_id = LED_FAN;

	/* after reboot, status LED should blink green, SW set to solid green */
	onlp_ledi_mode_set(ONLP_OID_TYPE_CREATE(ONLP_OID_TYPE_LED,LED_SYSTEM), ONLP_LED_MODE_GREEN);
	/*
	 * FAN Indicators
	 *
	 *     Green - Fan is operating
	 *     Red   - No power or Fan failure
	 *     Off   - No power
	 *
	 */
	mode = ONLP_LED_MODE_GREEN;

	for( fan_number = 1; fan_number<= CHASSIS_FAN_COUNT; fan_number+=2)
	{
		/* each 2 fans had same led_fan */
		onlp_fan_info_t fi;
		/* check fans */
		if(onlp_fani_info_get(ONLP_FAN_ID_CREATE(fan_number), &fi) < 0) {
			mode = ONLP_LED_MODE_RED;
		}
		else if(fi.status & ONLP_FAN_STATUS_FAILED) {
			mode = ONLP_LED_MODE_RED;
		}
		else
		{
			min_fan_speed = onlp_fani_get_min_rpm(fan_number);
			if( fi.rpm < min_fan_speed)
			{
				mode = ONLP_LED_MODE_RED;
			}
		}
		/* check fan i+1 */
		if(onlp_fani_info_get(ONLP_FAN_ID_CREATE(fan_number+1), &fi) < 0) {
			mode = ONLP_LED_MODE_RED;
		}
		else if(fi.status & ONLP_FAN_STATUS_FAILED) {
			mode = ONLP_LED_MODE_RED;
		}
		else
		{
			min_fan_speed = onlp_fani_get_min_rpm(fan_number+1);
			if( fi.rpm < min_fan_speed)
			{
				mode = ONLP_LED_MODE_RED;
			}
		}
	}
	onlp_ledi_mode_set(ONLP_OID_TYPE_CREATE(ONLP_OID_TYPE_LED,fan_led_id), mode);

	return ONLP_STATUS_OK;
}

