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
*    File Name: spi.h
*
*    Abstract: This file defines the spi interface class
*
*    $History:$
*
********************************************************************
*/

#ifndef __SPI_INTERFACE_H__
#define __SPI_INTERFACE_H__

#include "types.h"
#include "hidconfig.h"
#include "hidd_mem.h"
#include "startupallocated.h"

extern "C"
{
#include "spiffydriver.h"
}




/**  \addtogroup interfaces
*/
/*! @{ */
/**
* Defines a spi interface. Applications that use this interface
* can plug in different spi drivers with no impact. Drivers that
* comply with this interface can be used by multiple
* applications.
*/


    /// This is the main spi driver class
class SpiInterface : public StartupAllocated
{
    /* coverity[primary_file:FALSE] */
    /* coverity[bad_arg_type_for_operator_new:FALSE] */
    IS_MULTITON;

public:
    static SpiInterface* getInstance(BYTE blk);
    void configure(UINT32 clkSpeedInHz, SPI_ENDIAN endian,
                           SPI_SS_POLARITY polarity, SPI_MODE mode);
    void reset(void);
    void txData(UINT32 txLen, const UINT8* txBuf);
    void exchangeData(UINT32 len, const UINT8* txBuf, UINT8* rxBuf);
    void rxData(UINT32 rxLen, UINT8* rxBuf);
    void txByte(UINT8 b);
    void txHalfWord(UINT16 h);
    void txWord(UINT32 w);

protected:
    BYTE                blk;
    static SpiInterface* defaultCreateInstance(BYTE blk);
    SpiInterface(BYTE blk);
    ~SpiInterface(void);
    static SpiInterface *instance[MAX_SPIFFYS];

    /// Function pointer to the create instance. It provides a way to use
    /// default create instance or overwrite it.
    static SpiInterface* (*createInstance)(BYTE blk);
};

/* @} */

#endif
