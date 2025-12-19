/*
 * (c) 2016-2025, Infineon Technologies AG, or an affiliate of Infineon
 * Technologies AG. All rights reserved.
 * This software, associated documentation and materials ("Software") is
 * owned by Infineon Technologies AG or one of its affiliates ("Infineon")
 * and is protected by and subject to worldwide patent protection, worldwide
 * copyright laws, and international treaty provisions. Therefore, you may use
 * this Software only as provided in the license agreement accompanying the
 * software package from which you obtained this Software. If no license
 * agreement applies, then any use, reproduction, modification, translation, or
 * compilation of this Software is prohibited without the express written
 * permission of Infineon.
 *
 * Disclaimer: UNLESS OTHERWISE EXPRESSLY AGREED WITH INFINEON, THIS SOFTWARE
 * IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING, BUT NOT LIMITED TO, ALL WARRANTIES OF NON-INFRINGEMENT OF
 * THIRD-PARTY RIGHTS AND IMPLIED WARRANTIES SUCH AS WARRANTIES OF FITNESS FOR A
 * SPECIFIC USE/PURPOSE OR MERCHANTABILITY.
 * Infineon reserves the right to make changes to the Software without notice.
 * You are responsible for properly designing, programming, and testing the
 * functionality and safety of your intended application of the Software, as
 * well as complying with any legal requirements related to its use. Infineon
 * does not guarantee that the Software will be free from intrusion, data theft
 * or loss, or other breaches ("Security Breaches"), and Infineon shall have
 * no liability arising out of any Security Breaches. Unless otherwise
 * explicitly approved by Infineon, the Software may not be used in any
 * application where a failure of the Product or any consequences of the use
 * thereof can reasonably be expected to result in personal injury.
 */

/** @file platform audio effects interface
 */
#include "stdint.h"
#include "wiced.h"
#include "wiced_result.h"
#include "wiced_bt_trace.h"
#include "data_types.h"

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define EFFECT_NAME_MAX    (32)

typedef enum
{
	PLATFORM_AUD_EFFECT_NREC,
	PLATFORM_AUD_EFFECT_AEC,
	PLATFORM_AUD_EFFECT_NS,
	PLATFORM_AUD_EFFECT_AGC,
	PLATFORM_AUD_EFFECT_EQ,
	PLATFORM_AUD_EFFECT_MAX,    /*not a valid effect alias*/
}platform_audio_effect_type_t;

typedef struct
{
    uint32_t sample_rate;
}platform_audio_effect_nrec_config_t;

typedef struct
{
	int32_t dummy;
}platform_audio_effect_aec_config_t;

typedef struct
{
	int32_t dummy;
}platform_audio_effect_ns_config_t;

typedef struct
{
	int32_t dummy;
}platform_audio_effect_agc_config_t;

typedef struct
{
	int32_t dummy;
}platform_audio_effect_eq_config_t;

typedef union
{
    platform_audio_effect_nrec_config_t nrec_conf;
    platform_audio_effect_aec_config_t aec_conf;
	platform_audio_effect_ns_config_t ns_conf;
	platform_audio_effect_agc_config_t agc_conf;
	platform_audio_effect_eq_config_t eq_conf;
}platform_audio_effect_config_t;

typedef struct
{
	platform_audio_effect_type_t effect_type;
	uint32_t stack_size;
	uint32_t static_mem;
	uint32_t min_input_size;
	uint32_t min_out_size;
	uint32_t min_ref_size;
	char effect_name[EFFECT_NAME_MAX];
	char effect_vendor[EFFECT_NAME_MAX];
}platform_audio_effect_descrip_t;

typedef enum
{
    PLATFORM_IOCTL_EFFECT_DISABLE = 0,
    PLATFORM_IOCTL_EFFECT_ENABLE,
    PLATFORM_IOCTL_EFFECT_GETPARM,
    PLATFORM_IOCTL_EFFECT_SETPARM,
    PLATFORM_IOCTL_EFFECT_MAX,
} platform_audio_effect_ioctl_t;

typedef struct
{
    int32_t dummy;
}platform_audio_effect_nrec_data_ioctl_t;
typedef struct
{
    int32_t dummy;
}platform_audio_effect_aec_data_ioctl_t;

typedef struct
{
    int32_t dummy;
}platform_audio_effect_ns_data_ioctl_t;

typedef struct
{
    int32_t dummy;
}platform_audio_effect_agc_data_ioctl_t;

typedef struct
{
    int32_t dummy;
}platform_audio_effect_eq_data_ioctl_t;

typedef union
{
    platform_audio_effect_nrec_data_ioctl_t nrec_data;
    platform_audio_effect_aec_data_ioctl_t aec_data;
    platform_audio_effect_ns_data_ioctl_t ns_data;
    platform_audio_effect_agc_data_ioctl_t agc_data;
    platform_audio_effect_eq_data_ioctl_t eq_data;
}platform_audio_effect_ioctl_runtime_t;

typedef struct
{
    platform_audio_effect_type_t            type;
    platform_audio_effect_ioctl_runtime_t   data;
} platform_audio_effect_ioctl_data_t;


typedef struct
{
wiced_result_t (*audio_effect_init)    (platform_audio_effect_type_t effect_type, platform_audio_effect_config_t *config);
wiced_result_t (*audio_effect_deinit)  (uint32_t effect_id);
wiced_result_t (*audio_effect_process) (uint32_t effect_id, const uint32_t in_size,uint8_t *in_buf,
										const uint32_t ref_size,uint8_t *ref_buf, uint32_t *out_size,uint8_t *out_buf);
wiced_result_t (*audio_effect_ioctl)   ( uint32_t effect_id, platform_audio_effect_ioctl_t cmd, platform_audio_effect_ioctl_data_t* cmd_data);
}platform_audio_effect_ops_t;

typedef struct
{
	platform_audio_effect_descrip_t *des;
	platform_audio_effect_ops_t	*func;
}platform_audio_effect_list;


/*
 * Initialize an effect specified by the effect_type
 * inputs
 *    effect_type - refer to platform_audio_effect_type_t
 *    config      - effect specific configuration,refer to platform_audio_effect_config_t
 * returns
 * 		returns unique positive effect_id for the initialized effect
 * 		negative error code in case of failure
 * */
extern wiced_result_t platform_audio_effect_init(platform_audio_effect_type_t effect_type, platform_audio_effect_config_t *config, uint32_t *effect_id);
/*
 * de-initialize an effect specified by the effect_type
 * input
 * 		effect id to be deinit
 * 	returns
 * 		wiced_result_t return code
 * */
extern wiced_result_t platform_audio_effect_deinit(uint32_t effect_id);
/*
 * get list of all effects_type supported
 * input/output
 *      num_of_effects  - total no of effects
 *  returns
 *      pointer to list of effects type OR NULL in case of error
 * */
extern int32_t* platform_audio_effect_get_effects_type(uint32_t *num_of_effects);
/*
 * get effects descriptor for requested type
 * input
 *      type - effect type
 *  returns
 *      pointer to effects descriptor OR NULL in case of error
 * */
extern platform_audio_effect_descrip_t* platform_audio_effect_get_effects_descriptor(platform_audio_effect_type_t type);
/*
 * Process effect for input data
 * input/output
 * 		effect_id - id of the effct to process
 * 		in_size   - input buffer size in bytes
 * 		in_buf    - pointer to input buffer
 * 		if reference buf is not applicable set size as zero and buf as NULL
 * 		ref_size  - reference data input buffer size in bytes
 * 		ref_buf   - reference data buffer
 * 		out_size  - output buffer size in bytes/updated with actual size after process
 * 		out_buf   - output buffer pointer
 * 	returns
 * 		wiced_result_t return code
 * */
extern wiced_result_t platform_audio_effect_process(uint32_t effect_id,
											const uint32_t in_size,uint8_t *in_buf,
											const uint32_t ref_size,uint8_t *ref_buf,
											uint32_t *out_size,uint8_t *out_buf);
/** Send an ioctl command to the audio effects.
 *
 * input
 * effect_id - id of the effct to process.
 * cmd       - ioctl command (platform_audio_effect_ioctl_t).
 * cmd_data  - data associated to ioctl command (platform_audio_effect_ioctl_data_t).
 * return    - wiced_result_t
 */

extern wiced_result_t platform_audio_effect_ioctl ( uint32_t effect_id, platform_audio_effect_ioctl_t cmd, platform_audio_effect_ioctl_data_t* cmd_data );


#ifdef __cplusplus
} /*extern "C" */
#endif
