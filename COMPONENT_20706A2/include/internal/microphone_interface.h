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
