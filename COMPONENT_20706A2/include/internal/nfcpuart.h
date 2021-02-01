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
