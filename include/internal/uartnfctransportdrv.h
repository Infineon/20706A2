
/*******************************************************************************
* ------------------------------------------------------------------------------
*
* Copyright (c), 2013 Cypress Semiconductor.
*
*          ALL RIGHTS RESERVED
*
********************************************************************************
*
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
