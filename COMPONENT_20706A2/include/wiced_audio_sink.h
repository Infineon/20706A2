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
