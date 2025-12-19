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

/** @file
*
* Wiced PCM Utilities
*
*/
#include "wiced_bt_dev.h"

#ifndef __WICED_HAL_PCM_H__
#define __WICED_HAL_PCM_H__

/******************************************************
 *              Constants
 ******************************************************/
typedef enum
{
     WICED_HAL_I2SPCM_SLAVE = 0, /* PCM/I2S role type(slave) */
     WICED_HAL_I2SPCM_MASTER,    /* [DEFAULT] PCM/I2S role type(master) */
} wiced_hal_i2spcm_role_t;

enum wiced_hal_pcm_clk_e{
    WICED_HAL_PCM_RATE_128K = 0, /* PCM clock rate (128Kbps)*/
    WICED_HAL_PCM_RATE_256K,     /* PCM clock rate (256Kbps)*/
    WICED_HAL_PCM_RATE_512K,     /* PCM clock rate (512Kbps)*/
    WICED_HAL_PCM_RATE_1024K,    /* PCM clock rate (1024Kbps)*/
    WICED_HAL_PCM_RATE_2048K     /* PCM clock rate (2048bps)*/
};
typedef uint8_t wiced_hal_pcm_clk_t;

enum wiced_hal_pcm_data_order_e{
    WICED_HAL_PCM_MSB_FIRST = 0, /* PCM data format config for MSB first out */
    WICED_HAL_PCM_LSB_FIRST,     /* PCM data format config for LSB first out */
};
typedef uint8_t wiced_hal_pcm_data_order_t;

enum wiced_hal_pcm_sync_type_e{
    WICED_HAL_PCM_FRAME_TYPE_SHORT = 0, /* PCM data format config for short frame sync */
    WICED_HAL_PCM_FRAME_TYPE_LONG,      /* PCM data format config for long frame sync */
};
typedef uint8_t wiced_hal_pcm_sync_type_t;

enum wiced_hal_pcm_right_justify_e{
    WICED_HAL_PCM_DISABLE_RIGHT_JUSTIFY = 0, /* Used default data justify*/
    WICED_HAL_PCM_ENABLE_RIGHT_JUSTIFY,      /* Used right justify to sync data */
};
typedef uint8_t wiced_hal_pcm_right_justify_t;

enum wiced_hal_pcm_fill_data_e{
    WICED_HAL_PCM_FILL_0S = 0,
    WICED_HAL_PCM_FILL_1S,
    WICED_HAL_PCM_FILL_SIGNED,
    WICED_HAL_PCM_FILL_PROG
};
typedef uint8_t wiced_hal_pcm_fill_data_t;

typedef enum
{
    WICED_HAL_I2S_MODE = 0,
    WICED_HAL_PCM_MODE
}wiced_hal_i2spcm_path_t;

typedef struct
{
    wiced_hal_pcm_data_order_t lsbFirst;        /* pcm packet format 0:MSB_FIRST 1:LSB_FIRST */
    uint8_t                   fillBits;        /* pcm fill bits */
    wiced_hal_pcm_fill_data_t  fillData;        /* pcm fill data 0:FILL_0S 1:FILL_1S 2:FILL_SIGNED */
    uint8_t                   fillNum;         /* pcm fill number */
    wiced_hal_pcm_right_justify_t rightJustify;/* 0:no ; 1:yes  pcm only */
    wiced_hal_pcm_sync_type_t  frame_type;      /* frame type: 0: short; 1: long */
}wiced_hal_pcm_param_t;

typedef struct{
    wiced_hal_i2spcm_path_t   mode;          /* 0:I2S, 1:PCM*/
    wiced_hal_i2spcm_role_t   role;          /* I2S/PCM interface role: 0: slave; 1: master */
    wiced_hal_pcm_param_t     pcm_param;     /* Configure pcm1 param here*/
}wiced_hal_pcm_config_t;

/**
 * Function         wiced_hal_set_pcm_config
 *
 * To set the pcm configuration parameter
 *
 * @param[in]      pcm_config : strucure pointer
 *
 * @return          void
 *
 */
void wiced_hal_set_pcm_config (wiced_hal_pcm_config_t *pcm_config);

/**
 * Function         wiced_hal_get_pcm_config
 *
 * To get the current pcm configuration
 *
 * @param[in]      void
 *
 * @return          structure wiced_hal_pcm_config_t pointer
 *
 * Default values :  mode = WICED_HAL_I2S_MODE
 *                   role = WICED_HAL_I2SPCM_MASTER
 *                   pcm_param = NULL
 */
wiced_hal_pcm_config_t* wiced_hal_get_pcm_config(void);


#endif
