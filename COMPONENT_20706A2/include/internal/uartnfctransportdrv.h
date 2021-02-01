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

/*******************************************************************************
* File Name: uartnfctransportdrv.h
*
* Abstract:
*   Header for the UART transport driver class.
*******************************************************************************/

#ifndef __UART_NFC_TRANSPORT_DRV_H_
#define __UART_NFC_TRANSPORT_DRV_H_

#include "hidconfig.h"
#include "hidapp.h"
#include "bthidtransport.h"
#include "hidconfig.h"
#include "nfctransport.h"
#include "assertpanic.h"
#include "nfcpuart.h"

class UartTransportDrv : public NfcTransport
{

/*******************************************************************************
* Public Methods
*******************************************************************************/
public:
    // Constructor
    UartTransportDrv(void (*callback)(void*),void* parent);

    // Initialize block, NFC Transport, and chip.
    virtual void init(void);

    // SPI read and write wrappers for the transport driver class.
    virtual BYTE readNfc(BYTE *dataPtr, UINT16 length);
    virtual BYTE writeNfc(BYTE *dataPtr, UINT16 length);

/*******************************************************************************
* Public Types
*******************************************************************************/

/*******************************************************************************
* Protected Methods
*******************************************************************************/
protected:
    // Destructor
    ~UartTransportDrv();
/*******************************************************************************
* Protected Types
*******************************************************************************/
    // Pointers to the bus drivers we will use.

/*******************************************************************************
* Private Methods
*******************************************************************************/

};

#endif //__UART_NFC_TRANSPORT_DRV_H_
