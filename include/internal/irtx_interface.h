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
*    File Name: irtx_interface.h
*
*    Abstract: This file defines an IR TX interface
*
*    $History:$
*
********************************************************************
*/

#ifndef __IRTX_INTERFACE_H__
#define __IRTX_INTERFACE_H__

#include "startupallocated.h"
#include "types.h"

/**  \addtogroup interfaces
*/
/*! @{ */
/**
* Defines an ir tx interface. Applications that use this interface
* can plug in different ir tx drivers with no impact. ir tx drivers that comply with this interface
* can be used by different applications. The BCM remote application uses this
* interface to control Ir Tx activities.
* The BCM standard application Ir Tx driver also complies with this interface.
*/

class IrTx_interface : public StartupAllocated
{
public:
    virtual void SendIR(BYTE code, BOOL8 repeat, BYTE repeatcount) = 0;
    virtual BOOL8 isActive(void) = 0;
    virtual void stopRepeat(void) = 0;
};

/* @} */
#endif
