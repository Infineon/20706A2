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
