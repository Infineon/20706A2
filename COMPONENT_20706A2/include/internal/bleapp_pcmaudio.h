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
/*
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
