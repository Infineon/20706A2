
/*
********************************************************************
* THIS INFORMATION IS PROPRIETARY TO
* Cypress Semiconductor.
*-------------------------------------------------------------------
*
*           Copyright (c) 2009 Cypress Semiconductor.
*                      ALL RIGHTS RESERVED
*
********************************************************************

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
