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

// ******************************************************************************
//  File Name: audiocodec_interface.cpp
//
//  Abstract:  This file defines the Audio Codec Interface.
//
//  History:
//  *******************************************************************************

#ifndef __AUDIOCODEC_INTERFACE_H__
#define __AUDIOCODEC_INTERFACE_H__

#include "types.h"
#include "startupallocated.h"

/**  \addtogroup interfaces
*/
/*! @{ */
/**
* Defines an audio codec interface. Applications that use this interface
* can plug in different audio codec with no impact. Audio codec that comply with this interface
* can be used by different applications. The BCM remote application uses this
* interface to control audio codec activities.
*/

class AudioCodec_interface : public StartupAllocated
{
public:
    virtual void initialize(UINT16 NumChannles, UINT32 SampleRate, UINT16 BitsPerSample, UINT8 gain, UINT8 boost) = 0;
    virtual void init(void) = 0;

    virtual BYTE readSR(void) = 0;
    virtual BYTE readBPS(void) = 0;
    virtual BYTE readPCM(void) = 0;
    virtual UINT16 readHPF(void) = 0;
    virtual INT16 readPGA(void) = 0;

    virtual BOOL writeSR(BYTE p) = 0;
    virtual BOOL writeBPS(BYTE p) = 0;
    virtual BOOL writePCM(BYTE p) = 0;
    virtual BOOL writeHPF(UINT16 h) = 0;
    virtual BOOL writePGA(INT16 g) = 0;

    virtual UINT16 regRead(INT8 index) = 0;
    virtual void regWrite(INT8 index, UINT16 data) = 0;
};



/* @} */


#endif
