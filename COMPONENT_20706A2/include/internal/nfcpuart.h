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
// Handle LE rx
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
