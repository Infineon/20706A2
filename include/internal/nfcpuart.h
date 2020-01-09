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
*    File Name: nfcpuart.h
*
*    Abstract: This file defines a peripheral uart driver for nfc
*
*
********************************************************************
*/
#ifndef __NFCPUART_H__
#define __NFCPUART_H__

#include "types.h"
#include "puart.h"

#ifdef __cplusplus
extern "C" {
#endif

void nfcpuart_init(void);
void nfcpuart_setRxHandlerCallback(void (*cb)(void*), void* p);
int nfcpuart_rxHandler(void* unused);
int nfcpuart_hciRxHandler(void* unused);
int nfcpuart_hciTxHandler(void* unused);
int nfcpuart_hidRxHandler(void* unused);
int nfcpuart_hidTxHandler(void* unused);
int nfcpuart_txHandler(void* unused);

#define nfcpuart_interruptHandler   puart_interruptHandler
#define nfcpuart_interruptHandler   puart_interruptHandler

// Handle HCI tx and Rx
//#define nfcpuart_hciRxHandler       puart_hciRxHandler
//#define nfcpuart_hciTxHandler       puart_hciTxHandler
// Handle HID tx amd Rx

//#define nfcpuart_hidRxHandler       puart_hidRxHandler
//#define nfcpuart_hidTxHandler       puart_hidTxHandler
// Handle BLE rx
#define nfcpuart_bleRxHandler       puart_bleRxHandler
#define nfcpuart_calculateBaudrate  puart_calculateBaudrate

#define nfcpuart_enableInterrupt    puart_enableInterrupt
#define nfcpuart_flowOn             puart_flowOn
#define nfcpuart_flowOff            puart_flowOff
#define nfcpuart_disableTx          puart_disableTx
#define nfcpuart_enableTx           puart_enableTx
#define nfcpuart_setBaudrate        puart_setBaudrate
#define nfcpuart_synchronousRead    puart_synchronousRead
#define nfcpuart_synchronousWrite   puart_synchronousWrite
#define nfcpuart_rxFifoNotEmpty     puart_rxFifoNotEmpty

//#define nfcpuart_txHandler          puart_txHandler

#define nfcpuart_print              puart_print
#define nfcpuart_write              puart_write
#define nfcpuart_read               puart_read

#define nfcpuart_selectUartPads     puart_selectUartPads
#define nfcpuart_checkRxdPortPin    puart_checkRxdPortPin
#define nfcpuart_checkTxdPortPin    puart_checkTxdPortPin
#define nfcpuart_checkCtsPortPin    puart_checkCtsPortPin
#define nfcpuart_checkRtsPortPin    puart_checkRtsPortPin

#ifdef __cplusplus
}
#endif

#endif
