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
*    File Name: microphone_interface.h
*
*    $History:$
*
********************************************************************
*/
#ifndef __MICROPHONE_INTERFACE_H__
#define __MICROPHONE_INTERFACE_H__

#include "types.h"
#include "startupallocated.h"
#include "remoterpt.h"
#include "audiocodec_interface.h"

/**  \addtogroup interfaces
*/
/*! @{ */
/**
* Defines an audio codec interface. Applications that use this interface
* can plug in different audio codec with no impact. Audio codec that comply with this interface
* can be used by different applications. The BCM remote application uses this
* interface to control audio codec activities.
*/


class Microphone_interface : public StartupAllocated
{
public:
    enum
    {
        CODEC_SR   = 0,
        CODEC_PCM  = 1,
        CODEC_PGA  = 2,
        CODEC_BPS  = 3,
        CODEC_HPF  = 4,
    };

    virtual void init(void (*userfn)(void*) = NULL, void* userdata = NULL) = 0;
    virtual BYTE pollActivityUser(HidEventUserDefine* data) = 0;

    virtual void setActive(bool a) = 0;
    virtual bool isActive() = 0;
    virtual void stopPCM() = 0;

    virtual UINT8 audioFIFOCnt() = 0;
    virtual void overflow() = 0;
    virtual UINT16 isOverflow() = 0;

    virtual BOOL readCodecSetting(VoiceControlDM1Report * rp) = 0;
    virtual BOOL writeCodecSetting(BYTE t, BYTE *d) = 0;
    virtual AudioCodec_interface *getCodec() = 0;
};


/* @} */


#endif
