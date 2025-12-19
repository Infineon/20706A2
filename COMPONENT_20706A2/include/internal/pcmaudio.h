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
