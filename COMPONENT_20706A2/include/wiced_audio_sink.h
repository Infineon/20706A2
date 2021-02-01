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
 * Definitions the utilities for configuring the litehost for the sink functionality
 */
#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @addtogroup  wicedbt_a2dp        Advanced Audio Distribution Profile (A2DP) Sink
 * @ingroup     wicedbt_av
 * @{
 */

/*************************************************************
 *                 Function Declarations
 *************************************************************/

/** Wiced audio sink initialization
 *
 *  @param p_cfg    pointer to the sink config structure
 *
 *  @return wiced_result_t (WICED_BT_XXX)
 */
wiced_result_t wiced_audio_sink_config_init( wiced_bt_a2dp_sink_audio_tuning_params_t* p_param );

/** API to configure the sink to perform SBC decoding and to route the decoded
 * audio data over I2S or UART on starting the streaming
 *
 *Called by the application when the streaming is to be started
 *
 *  @param handle  AVDT connection handle
 *
 *  @param audio_route - Audio route to be used to send the decoded audio data,
 *                                 I2S or UART
 *
 *  @param cp_type  Content protection type. Refer AVDT_CP_TYPE defined in wiced_bt_avdt.h
 *
 *  @param p_codec_info    Codec information
 *
 *  @return wiced_result_t (WICED_BT_XXX)
 */
wiced_result_t wiced_audio_sink_configure( uint16_t handle, uint32_t is_master, uint32_t audio_route, uint16_t cp_type,wiced_bt_a2dp_codec_info_t* p_codec_info );

/** API to reset the sink on stopping the streaming
 *
 *Called by the application when the streaming is stopped
 *
 *  @param handle  AVDT connection handle
 *
 *  @return wiced_result_t (WICED_BT_XXX)
 */
wiced_result_t wiced_audio_sink_reset( uint16_t handle );

/** To mute/unmute the audio
 *
 *Called by the application to mute the audio when playing the music. Application shall
 * this function to unmute also to restart playing the music
 *
 *  @param enable    1 to mute, 0 to unmute
 *
 *  @param ramp_ms    ramp up/down time in milli seconds
 *
 *  @return wiced_result_t (WICED_BT_XXX)
 */
wiced_result_t wiced_audio_sink_mute( wiced_bool_t enable, uint16_t ramp_ms );


/** @} */ // end of wiced_audio_sink

#ifdef __cplusplus
} /*extern "C" */
#endif
