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
