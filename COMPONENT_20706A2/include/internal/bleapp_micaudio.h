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
/*
********************************************************************
*    File Name: bleapp_micaudio.h
*
*    $History:$
*
********************************************************************
*/
#ifndef __BLEAPP_MIC_AUDIO_PERIPHERAL_H__
#define __BLEAPP_MIC_AUDIO_PERIPHERAL_H__

#include "bleapp_audiocodec_interface.h"
#include "bleapp_microphone_interface.h"


typedef struct MicAudio
{
    tAudioCodecInterfaceVtbl *codec;

    //this is the timer that we delay sending audio
    //AppTimer * delayTimer;

    void (*userFn)(void*);
    void * master;

    VoiceReport *audioAdcData;
    UINT16 *dataCnt;


    UINT32 voicePktTime;
    UINT16 audioCounter;
    UINT16 underflowCounter;
    UINT16 overflowCounter;

    volatile BOOLEAN active;
    BOOLEAN pin_en_audio;
    UINT8 fifo_cnt;
    BYTE fifoOutIndex;
    BYTE fifoInIndex;
    BOOL8 voiceStarted;
    BYTE reportsToSend;
    BOOL8 timerRunning;
    BYTE audio_gain;
    BYTE audio_boost;
    BYTE maxSampleInOneSlot;
    BYTE audio_delay;
}tMicAudio;

tMicrophoneInterfaceVtbl *micAudio_Constructor(tMicrophoneInterfaceConfig * config);

#endif
