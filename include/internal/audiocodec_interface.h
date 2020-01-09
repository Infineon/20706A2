//  *****************************************************************************
//  Copyright (c), 2009-13 Cypress Semiconductor.
//
//          ALL RIGHTS RESERVED
//
//  *****************************************************************************
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
