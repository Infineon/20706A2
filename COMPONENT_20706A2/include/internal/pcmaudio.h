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
*    File Name: pcmaudio.h
*
*    $History:$
*
********************************************************************
*/
#ifndef __AUDIO_PERIPHERAL_H__
#define __AUDIO_PERIPHERAL_H__

#include "audiocodec_interface.h"
#include "microphone_interface.h"
#include "pcmdriver.h"
#include "apptimer.h"

class pcmAudio : public Microphone_interface
{
public:
    pcmAudio(AudioCodec_interface *mic_codec, VoiceReport *audio_fifo, UINT16 *data_count, UINT8 fifo_count, bool enable);
    virtual void init(void (*userfn)(void*) = NULL, void* userdata = NULL);
    virtual BYTE pollActivityUser(HidEventUserDefine* data);
    static void pcmAudioCallback(UINT32 param);

    virtual void setActive(bool a);
    bool isActive() {return active;};
    virtual void stopPCM();

    void overflow() {overflowCounter++;};
    UINT16 isOverflow() { return overflowCounter;};
    UINT8 audioFIFOCnt() {return fifo_cnt;} ;

    virtual BOOL readCodecSetting(VoiceControlDM1Report * rp);
    virtual BOOL writeCodecSetting(BYTE t, BYTE *d);
    AudioCodec_interface *getCodec() {return codec;};

protected:

    virtual void startMCLK();
    virtual void stopMCLK();
    virtual void audioDataHandler(UINT32 param);
    virtual void configurePCM();
    virtual void startAudio();
    virtual int sendAudio(void* unused);
    virtual void delayTimerCallback(void);

public:
    static pcmAudio *thisApp;
    static UINT32 SampleRate;
    static UINT32 Source_Clk;
    static UINT16 NumChannels;
    static UINT16 BitsPerSample;
    static UINT16 Buffer_Send_Threshold;
    static UINT8  Audio_En_Port;
    static UINT8  Audio_En_Pin;

protected:
    Pcm * pcm;
    AudioCodec_interface *codec;

    //this is the timer that we delay sending audio
    AppTimer * delayTimer;

    static void (*userFn)(void*);
    static void * master;

    VoiceReport *audioData;
    UINT16 *dataCnt;

    Pcm::CFG_TYPE  paramConf0;

    UINT32 voicePktTime;
    UINT16 audioCounter;
    UINT16 underflowCounter;
    UINT16 overflowCounter;

    volatile bool active;
    bool pin_en_audio;
    UINT8 fifo_cnt;
    BYTE fifoOutIndex;
    BYTE fifoInIndex;
    BOOL8 voiceStarted;
    BOOL8 timerRunning;
};


/* @} */


#endif
