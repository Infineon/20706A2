/*
 * Copyright 2016-2021, Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
 *
 * This software, including source code, documentation and related
 * materials ("Software") is owned by Cypress Semiconductor Corporation
 * or one of its affiliates ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products.  Any reproduction, modification, translation,
 * compilation, or representation of this Software except as specified
 * above is prohibited without the express written permission of Cypress.
 *
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 * reserves the right to make changes to the Software without notice. Cypress
 * does not assume any liability arising out of the application or use of the
 * Software or any product or circuit described in the Software. Cypress does
 * not authorize its products for use in any products where a malfunction or
 * failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product"). By
 * including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing
 * so agrees to indemnify Cypress against all liability.
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
