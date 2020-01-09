
/*******************************************************************************
* ------------------------------------------------------------------------------
*
* Copyright (c), 2013 Cypress Semiconductor.
*
*          ALL RIGHTS RESERVED
*
********************************************************************************
*
* File Name: i2cnfctransportdrv.h
*
* Abstract:
*   Header for the I2C transport driver class.
*******************************************************************************/

#ifndef __I2C_NFC_TRANSPORT_DRV_H_
#define __I2C_NFC_TRANSPORT_DRV_H_

#include "hidconfig.h"
#include "hidapp.h"
#include "bthidtransport.h"
#include "i2cm.h"
#include "nfctransport.h"
#include "assertpanic.h"

class I2CTransportDrv : public NfcTransport
{
/*******************************************************************************
* Public Methods
*******************************************************************************/
public:
    // Constructor
    I2CTransportDrv(void (*callback)(void*),void* parent);

    // Destructor
    ~I2CTransportDrv();

    // Initialize block, NFC Transport, and chip.
    virtual void init(void);

    // Read and write wrappers for the app driver class.
    virtual BYTE readNfc(BYTE *dataPtr, UINT16 length);
    virtual BYTE writeNfc(BYTE *dataPtr, UINT16 length);

/*******************************************************************************
* Public Types
*******************************************************************************/

/*******************************************************************************
* Protected Methods
*******************************************************************************/
protected:

/*******************************************************************************
* Protected Types
*******************************************************************************/
    // Pointers to the bus drivers we will use.

    // Device bus address
    UINT8 devAddr;

/*******************************************************************************
* Private Methods
*******************************************************************************/

};

#endif //__I2C_NFC__TRANSPORT_DRV_H_
