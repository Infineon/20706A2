/*
********************************************************************
* THIS INFORMATION IS PROPRIETARY TO
* Cypress Semiconductor.
*-------------------------------------------------------------------
*
*           Copyright (c) 2011 Cypress Semiconductor.
*                      ALL RIGHTS RESERVED
*
********************************************************************

********************************************************************
*    File Name: pcmaudio.h
*
*    $History:$
*
********************************************************************
*/
#ifndef __BLEAPP_PCMAUDIO_H__
#define __BLEAPP_PCMAUDIO_H__

#include "bleapp_pcmdriver.h"
#include "bleapp_audiocodec_interface.h"

// Definition of bitmap for for buffer state in VoiceReport
#define PCMBUFFSTATE_FIFO_MASK  0x0007  // 3 bits only
#define PCMBUFFSTATE_FIFO_INP_SHFT 0   // Bit 0-2
#define PCMBUFFSTATE_FIFO_OUT_SHFT 3   // Bit 3-5
#define PCMBUFFSTATE_FIFO_UNRFLOW_SHFT 6   // Bit 6-8
#define PCMBUFFSTATE_FIFO_OVRFLOW_SHFT 9   // Bit 9-11


typedef struct PcmAudio
{
    tAudioCodecInterfaceVtbl *codec;

    //this is the timer that we delay sending audio
    //AppTimer * delayTimer;

    void (*userFn)(void*);
    void * master;

    VoiceReport *audioData;
    UINT16 *dataCnt;

    tPCM_CFG_TYPE paramConf0;

    UINT32 voicePktTime;
    UINT16 audioCounter;
    UINT16 underflowCounter;
    UINT16 overflowCounter;

    volatile BOOLEAN active;
    BOOLEAN pin_en_audio;
    UINT8 fifo_cnt;
    BYTE fifoOutIndex;
    BYTE fifoInIndex;
    BYTE reportsToSend;
    BOOL8 voiceStarted;
    BOOL8 timerRunning;
    BYTE audio_gain;
    BYTE audio_boost;
    BYTE maxSampleInOneSlot;
    BYTE audio_delay;
}tPcmAudio;

tMicrophoneInterfaceVtbl *pcmAudio_Constructor(tMicrophoneInterfaceConfig * config);


#endif
