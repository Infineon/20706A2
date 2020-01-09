
/*******************************************************************************
* ------------------------------------------------------------------------------
*
* Copyright (c), 2013 Cypress Semiconductor.
*
*          ALL RIGHTS RESERVED
*
********************************************************************************
*
* File Name: spinfctransportdrv.h
*
* Abstract:
*   Header for the SPI transport driver class.
*******************************************************************************/

#ifndef __SPI_NFC_TRANSPORT_DRV_H_
#define __SPI_NFC_TRANSPORT_DRV_H_

#include "hidconfig.h"
#include "hidapp.h"
#include "bthidtransport.h"
#include "spiffydriver.h"
#include "spi.h"
#include "nfctransport.h"
#include "assertpanic.h"

class SpiTransportDrv : public NfcTransport
{

/*******************************************************************************
* Public Methods
*******************************************************************************/
public:
    // Constructor
    SpiTransportDrv(void (*callback)(void*), void* parent);

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
    ~SpiTransportDrv();
/*******************************************************************************
* Protected Types
*******************************************************************************/

/*******************************************************************************
* Private Methods
*******************************************************************************/

};

#endif //__SPI_NFC_TRANSPORT_DRV_H_
