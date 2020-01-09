/*
********************************************************************
* THIS INFORMATION IS PROPRIETARY TO
* Cypress Semiconductor.
*-------------------------------------------------------------------
*
*           Copyright (c) 2013 Cypress Semiconductor.
*                      ALL RIGHTS RESERVED
*
********************************************************************

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
