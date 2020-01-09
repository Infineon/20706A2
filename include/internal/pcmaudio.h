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
