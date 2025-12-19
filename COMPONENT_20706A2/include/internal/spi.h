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
