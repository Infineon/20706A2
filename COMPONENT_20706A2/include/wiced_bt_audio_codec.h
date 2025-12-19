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
 * Defines the utilities used by the A2DP for configuring the audio codec
 */
#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

/** Codec Type*/
typedef enum
{
    WICED_AUDIO_CODEC_NONE         = 0,       /**< None */
    WICED_AUDIO_CODEC_SBC_ENC      = 1 << 0,  /**< SBC Encode */
    WICED_AUDIO_CODEC_SBC_DEC      = 1 << 1,  /**< SBC Decode */
    WICED_AUDIO_CODEC_MP3_ENC      = 1 << 2,  /**< MP3 Encode */
    WICED_AUDIO_CODEC_MP3_DEC      = 1 << 3,  /**< MP3 Decode */
    WICED_AUDIO_CODEC_AAC_ENC      = 1 << 4,  /**< AAC Encode */
    WICED_AUDIO_CODEC_AAC_DEC      = 1 << 5,  /**< AAC Decode */
    WICED_AUDIO_CODEC_AAC_PLUS_ENC = 1 << 6,  /**< AAC Plus Encode */
    WICED_AUDIO_CODEC_AAC_PLUS_DEC = 1 << 7,  /**< AAC Plus Decode */
    WICED_AUDIO_CODEC_MP2_ENC      = 1 << 8,  /**< MP2 Encode */
    WICED_AUDIO_CODEC_MP2_DEC      = 1 << 9,  /**< MP2 Decode */
    WICED_AUDIO_CODEC_MP2_5_ENC    = 1 << 10, /**< MP2_5 Encode */
    WICED_AUDIO_CODEC_MP2_5_DEC    = 1 << 11, /**< MP2_5 Decode */
    WICED_AUDIO_CODEC_PCM_ENC      = 1 << 12  /**< PCM Encode */
} wiced_bt_a2dp_codec_type_t;


#define WICED_CODEC_STATUS_SUCCESS   0  /**< Indicates Success */
#define WICED_CODEC_STATUS_FAIL      1  /**< Indicates Failure */

/*************************************************************
 *                 Function Declarations
 *************************************************************/

/** SBC Codec params */
typedef struct
{
    uint8_t pcm_format;     /**< PCM format */
    uint8_t sampling_freq;  /**< Sampling frequency */
    uint8_t channel_mode;   /**< Channel mode */
    uint8_t block_length;   /**< Block length */
    uint8_t num_subbands;   /**< Number of subbands */
    uint8_t alloc_method;   /**< Allocation method */
    uint8_t bitpool_size;   /**< Bitpool size*/
} wiced_codec_param_sbc_t;

/** MP3/MP2/MP2_5 Codec params */
typedef struct
{
    uint8_t pcm_format;     /**< PCM format */
    uint8_t sampling_freq;  /**< Sampling frequency */
    uint8_t mode;           /**< Channel mode */
    uint8_t bit_rate_index; /**< Bit rate index */
} wiced_codec_param_mpx_t;

/** AAC Codec params */
typedef struct
{
    uint8_t  pcm_format;    /**< PCM format */
    uint16_t sampling_freq; /**< Sampling frequency */
    uint8_t  channel_mode;  /**< Channel mode */
    uint32_t bit_rate;      /**< Bit rate */
    uint32_t sbr_profile;   /**< SBR profile */
} wiced_codec_param_aac_t;

/** PCM Codec params */
typedef struct
{
    uint8_t  pcm_format;    /**< PCM format */
    uint16_t sampling_freq; /**< Sampling frequency */
    uint8_t  channel_mode;  /**< Channel mode */
    uint8_t bit_rate_index; /**< Bit rate index */
} wiced_codec_param_pcm_t;

/** Codec params */
typedef union
{
    wiced_codec_param_sbc_t sbc;    /**< SBC codec params */
    wiced_codec_param_mpx_t mp3;    /**< MP3 Codec params */
    wiced_codec_param_mpx_t mp2;    /**< MP2 Codec params */
    wiced_codec_param_mpx_t mp2_5;  /**< MP2_5 Codec params */
    wiced_codec_param_aac_t aac;    /**< AAC Codec params */
    wiced_codec_param_pcm_t pcm;    /**< PCM Codec params */
} wiced_codec_param_t;

/** CODEC returns required memory size in byte*/
typedef uint32_t (wiced_codec_get_mem_size_t)(void);

/*******************************************************************
 *
 *  wiced_codec_init_t
 *
 * CODEC is initialized with allocated memory and codec specific params
 *
 *  WICED_CODEC_STATUS_SUCCESS is returned, if successful.
 *  WICED_CODEC_STATUS_FAIL is returned, otherwise.
 */
typedef uint32_t (wiced_codec_init_t)(void *memory, wiced_codec_param_t *param);

/*******************************************************************
 *
 *  wiced_codec_get_frame_len_t
 *
 *  For encoder,
 *      it returns encoding frame size in byte based on configuration.
 *      pFrame is ignored.
 *  For decoder,
 *      it returns frame size in byte based on header information only if
 *      provided frame has the right information based on initialization
 *      and it found next frame sync.
 *      Otherwise, it returns WICED_CODEC_STATUS_FAIL.
 *
 ******************************************************************/
typedef uint32_t (wiced_codec_get_frame_len_t)(UINT8 *frame);

/*******************************************************************
 *
 *  wiced_codec_get_num_pcm_t
 *
 *  CODEC returns number of PCM samples per frame.
 *  For dual channel, number of samples per channel is returned
 *
 ******************************************************************/
typedef uint32_t (wiced_codec_get_num_pcm_t)(void);

/*******************************************************************
**
**  wiced_codec_set_bit_rate_t
**
**  For encoder,
**      it updates bit rate and returns WICED_CODEC_STATUS_SUCCESS if successful.
**      Otherwise it returns WICED_CODEC_STATUS_FAIL.
**      Param will be bitpool for SBC, bit rate index for MP3, bit rate for AAC
**  For decoder
**      it ignores and returns WICED_CODEC_STATUS_FAIL.
*******************************************************************/
typedef uint32_t (wiced_codec_set_bit_rate_t)(uint32_t param);

/*******************************************************************
**
**  wiced_codec_get_bit_rate_t
**
**  For encoder,
**      it returns bit rate based on initialization or wiced_codec_set_bit_rate_t
**
**  For decoder
**      it ignores and returns WICED_CODEC_STATUS_FAIL.
*******************************************************************/
typedef uint32_t (wiced_codec_get_bit_rate_t)(void);

/*******************************************************************
 *
 *  wiced_codec_process_frame_t
 *
 *  For encoder,
 *      it encodes PCM samples (pIn) into a frame (pOut) and returns
 *      frame length. It ignores frame_length parameter.
 *  For decoder,
 *      it decodes a frame (pIn) into PCM (pOut) based on frame_length.
 *      WICED_CODEC_STATUS_SUCCESS is returned, if successful.
 *      WICED_CODEC_STATUS_FAIL is returned, otherwise.
 *
 ******************************************************************/
typedef uint32_t (wiced_codec_process_frame_t)(void *pIn, void *pOut, uint32_t frame_length);

/*******************************************************************
 *
 *  wiced_codec_flush_t
 *
 *  CODEC initializes internal buffer
 *
 *  WICED_CODEC_STATUS_SUCCESS is returned, if successful.
 *  WICED_CODEC_STATUS_FAIL is returned, otherwise.
 *
 ******************************************************************/
typedef uint32_t (wiced_codec_flush_t)(void);

/** Codec Interface function matrix
 *  In external codec library below all function should be implemented */
typedef struct
{
    wiced_codec_get_mem_size_t  *p_get_memory_size_function;    /**< Function should returns required memory size in byte */
    wiced_codec_init_t          *p_init_function;               /**< Function should initialized with allocated memory and codec specific params */
    wiced_codec_get_frame_len_t *p_get_frame_len_function;      /**< Function should returns frame size in byte */
    wiced_codec_get_num_pcm_t   *p_get_num_pcm_function;        /**< Function should returns number of PCM samples per frame */
    wiced_codec_set_bit_rate_t  *p_set_bit_rate_function;       /**< Function should update the give bit rate */
    wiced_codec_get_bit_rate_t  *p_get_bit_rate_function;       /**< Function should returns configured bit rate */
    wiced_codec_process_frame_t *p_process_frame_function;      /**< Function should encode/decode the packet */
    wiced_codec_flush_t         *p_flush_function;              /**< Function should initialize internal buffers */
} wiced_codec_interface_functions_t;

/** External Codec information */
typedef struct
{
    wiced_bt_a2dp_codec_type_t           codec_id;          /**< Codec id */
    wiced_codec_interface_functions_t    *codec_functions;  /**< Codec functions for external codec */
} wiced_bt_a2dp_ext_codec_info_t;

/** Audio buffer information */
typedef struct {
    uint32_t buffer_start;  /**< Start pointer */
    uint32_t  buffer_end;   /**< End pointer */
} wiced_audio_buffer_info_t;

/*******************************************************************************
 *
 * Function         wiced_audio_register_codec_handler
 *
 * Description      Replaces dummy handler with handler in Wiced
 *
 * Parameters       Codec to replace, pointer to the codec function table
 *
 * Returns          NONE
 *
 ******************************************************************************/
void wiced_audio_register_codec_handler(wiced_bt_a2dp_codec_type_t audio_codec, wiced_codec_interface_functions_t * p_codec_functions);

/*******************************************************************************
 *
 * Function         wiced_audio_request_buffer_info
 *
 * Description      Returns the jitter buffer start and stop pointers
 *                  Helper function for packet length calculations
 *
 * Parameters       Buffer info struct
 *
 * Returns          NONE
 *
 ******************************************************************************/
void wiced_audio_request_buffer_info(wiced_audio_buffer_info_t *buffer_info);

/** Volume control - Ramp up/down the PCM samples during mute/un-mute
 *
 *  This API is called by the codec library after the decoding is done to allow FW
 *   to ramp the audio data when mute/un-mute is requested by the application.
 *
 *  @param pIn        pointer to the pcm input buffer
 *
 *  @param pIn        pointer to the pcm output buffer
 *
 *  @param pcm_count  PCM input sample size
 *
 *  @return none
 *
 */
void wiced_audio_volume_ctrl( void *pIn,void *pOut, int pcm_count );

#ifdef __cplusplus
} /*extern "C" */
#endif
