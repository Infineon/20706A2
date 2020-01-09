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

#ifndef __BLEAPP_AUDIOCODEC_INTERFACE_H__
#define __BLEAPP_AUDIOCODEC_INTERFACE_H__

#include "types.h"


/**  \addtogroup interfaces
*/
/*! @{ */
/**
* Defines an audio codec interface. Applications that use this interface
* can plug in different audio codec with no impact. Audio codec that comply with this interface
* can be used by different applications. The BCM remote application uses this
* interface to control audio codec activities.
*/

typedef struct
{
    void (*initialize)(UINT16 NumChannles, UINT32 SampleRate, UINT16 BitsPerSample, UINT8 gain, UINT8 boost);
    void (*init)(void);

    BYTE (*readSR)(void);
    BYTE (*readBPS)(void);
    BYTE (*readPCM)(void);
    UINT16 (*readHPF)(void);
    INT16 (*readPGA)(void);

    BOOL (*writeSR)(BYTE p);
    BOOL (*writeBPS)(BYTE p);
    BOOL (*writePCM)(BYTE p);
    BOOL (*writeHPF)(UINT16 h);
    BOOL (*writePGA)(INT16 g);

    UINT16 (*regRead)(INT8 index);
    void (*regWrite)(INT8 index, UINT16 data);
} tAudioCodecInterfaceVtbl;

#endif
