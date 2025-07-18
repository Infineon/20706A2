/*
 * Copyright 2016-2025, Cypress Semiconductor Corporation (an Infineon company) or
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

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "wiced.h"
#include "wiced_bt_types.h"
#include "wiced_bt_audio.h"
#include "wiced_result.h"
#include "wiced_bt_a2d.h"
#include "wiced_bt_a2d_sbc.h"
#include "wiced_bt_a2d_m12.h"
#include "wiced_bt_a2d_m24.h"

/** @file:   wiced_bt_a2dp_defs.h */


/******************************************************
 *                   Enumerations
 ******************************************************/

/** Masks for supported Codecs */
typedef enum
{
    WICED_BT_A2DP_CODEC_SBC             = 0x00, /**< SBC Codec */
    WICED_BT_A2DP_CODEC_M12             = 0x01, /**< MPEG-1, 2 Codecs */
    WICED_BT_A2DP_CODEC_M24             = 0x02, /**< MPEG-2, 4 Codecs */
    WICED_BT_A2DP_CODEC_VENDOR_SPECIFIC = 0xFF, /**< Vendor specific codec */
} wiced_bt_a2dp_codec_t;


/** overrun flow control flag */
typedef enum
{
    WICED_BT_A2DP_SINK_OVERRUN_CONTROL_FLUSH_DATA,
    WICED_BT_A2DP_SINK_OVERRUN_CONTROL_FLOW_CONTROL_SOURCE
} wiced_bt_a2dp_sink_overrun_control_t;

/******************************************************
 *                 Type Definitions
 ******************************************************/
/** A2DP data path callback type
 *
 *  Application implements callback of this type to receive A2DP media packets.
 *  Receives raw PCM samples in case of SBC codec and encoded audio data
 *  in case of AAC codec
 *
 *  @param p_audio_data   pointer to audio data
 *  @param a2dp_data_len  audio data length
 *
 *  @return none
 */
typedef void (*wiced_bt_a2dp_sink_data_cb_t)( uint8_t* p_a2dp_data, uint32_t a2dp_data_len );
/******************************************************
 *                    Structures
 ******************************************************/

/** Vendor Specific Codec information element type */
typedef struct
{
    uint8_t  cie_length; /**< Length of codec information element in octets */
    uint8_t* cie;        /**< Codec information element */
} wiced_bt_a2d_vendor_cie_t;

/** Audio data route configuration
 *
 * Note :
 *      --------------------------------------------------------------------
 *     |  Codec  |        Route                        |   Output data type |
 *     |--------------------------------------------------------------------|
 *     |         |  AUDIO_ROUTE_UART                   |      Decoded       |
 *     |   SBC   |  AUDIO_ROUTE_I2S                    |      Decoded       |
 *     |         |  AUDIO_ROUTE_COMPRESSED_TRANSPORT   |      Encoded       |
 *     |--------------------------------------------------------------------|
 *     |         |  AUDIO_ROUTE_UART                   |      Not Supported |
 *     |   AAC   |  AUDIO_ROUTE_I2S                    |      Not Supported |
 *     |         |  AUDIO_ROUTE_COMPRESSED_TRANSPORT   |      Encoded       |
 *      --------------------------------------------------------------------
 *
 */
typedef struct
{
    wiced_audio_route_t             route;      /**< Audio routing path */
    wiced_bt_a2dp_sink_data_cb_t    data_cb;    /**< App callback if audio route is APP*/
    wiced_bool_t                    is_master;  /**< I2S slave/master if audio route is I2S */
} wiced_bt_a2dp_sink_route_config;

/** Codec information element structure, used to provide info of a single type of codec */
typedef struct
{
    wiced_bt_a2dp_codec_t codec_id; /**< One of WICED_BT_A2DP_CODEC_XXX, to indicate the valid element of the cie union */
    union
    {
        wiced_bt_a2d_sbc_cie_t    sbc; /**< SBC information element */
        wiced_bt_a2d_m12_cie_t    m12; /**< MPEG-1, 2 information element */
        wiced_bt_a2d_m24_cie_t    m24; /**< MPEG-2, 4 information element */
        wiced_bt_a2d_vendor_cie_t vsp; /**< Vendor Specific codec information element */
    } cie;
} wiced_bt_a2dp_codec_info_t;

/** Audio data route configuration */
typedef struct
{
    wiced_audio_route_t             route;      /**< Audio routing path */
    wiced_bool_t                    is_master;  /**< I2S slave/master if audio route is I2S */
}wiced_bt_a2dp_source_route_config;

/** Audio quality tuning parameters
 *Note
 *
 * The average buffer level, over a period of time, is compared to the target buffer level
 * (calculated based on the Target BUF Depth %) and used to compute the necessary clock
 * adjustment in ppm (Level Correction). If the Level Correction stays within the ppm range
 * defined by Level Correction Threshold High and Level Correction Threshold Low, then the
 * algorithm only applies small clock adjustments that are proportional to the amplitude of the
 * Level Correction (typically, 1.5%~2.0% of the Level Correction value). Otherwise, if the
 * Level Correction falls outside of the Level Correction Threshold High and Level Correction
 * Threshold Low interval for 3 successive adjustment periods, the algorithm applies large
 * clock adjustments defined Adjustment ppm Max or Adjustment ppm Min in an effort to get
 * back within range*/
typedef struct
{
    uint16_t                              buf_depth_ms;                  /* in msec, Max value allowed is 300 */
    uint8_t                               start_buf_depth;               /* start playback percentage of the buffer depth */
    uint8_t                               target_buf_depth;              /* target level percentage of the buffer depth */
    wiced_bt_a2dp_sink_overrun_control_t  overrun_control;               /* overrun flow control flag */
    int32_t                               adj_ppm_max;                   /* Max PPM adjustment value */
    int32_t                               adj_ppm_min;                   /* Min PPM adjustment value */
    int32_t                               adj_ppb_per_msec;              /* PPM adjustment per milli second */
    int32_t                               lvl_correction_threshold_high; /* Level correction threshold high value */
    int32_t                               lvl_correction_threshold_low;  /* Level correction threshold low value */
    int32_t                               adj_proportional_gain;         /* Proportional component of total PPM adjustment */
    int32_t                               adj_integral_gain;             /* Integral component of total PPM adjustment */
} wiced_bt_a2dp_sink_audio_tuning_params_t;


/** @} */ // end of wicedbt_a2dp

#ifdef __cplusplus
} /*extern "C" */
#endif
