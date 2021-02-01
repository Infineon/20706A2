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
/********************************************************************************
*    File Name: cfa.h
*
*    Abstract:  Core Firmware API Definitions, internal use only
*
*    Functions:
*            --
*
*    $History:$
*
*******************************************************************************/


#ifndef _CFA_H_
#define _CFA_H_


#include "types.h"

// DO NOT INCLUDE ANY OTHER HEADERS.  THIS HEADER NEEDS TO BE SUITABLE FOR
// EXTERNAL RELEASE!!!

#ifdef __cplusplus
extern "C" {
#endif

//******************************************************************************
// 10   Public Interfaces
//******************************************************************************

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// 10.5       Host Controller Interface (HCI)
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//------------------------------------------------------------------------------
// 10.5.1       Types
//------------------------------------------------------------------------------
#pragma pack(1)
typedef PACKED struct
{
    UINT16 opcode;
    UINT8 length;
    /* parameter payload follows */
} HCI_CMD_HDR;
#pragma pack()

#pragma pack(1)
typedef PACKED struct
{
    UINT8 eventCode;
    UINT8 length;
    /* parameter payload follows */
} HCI_EVT_HDR;
#pragma pack()

#pragma pack(1)
typedef PACKED struct
{
    UINT16 connectionHandleEtc;
    UINT16 length;
    /* data payload follows */
} HCI_ACL_HDR;
#pragma pack()


#define BD_ADDR_LEN     6

#pragma pack(1)
typedef UINT8 CFA_BD_ADDR[BD_ADDR_LEN];
#pragma pack()

#pragma pack(1)
typedef PACKED struct
{
    HCI_EVT_HDR     header;                // event header
    UINT8           numResponses;
    CFA_BD_ADDR     bdAddr;
    UINT8           pageScanRepetitionMode;
    UINT8           pageScanPeriodMode;
    UINT8           pageScanMode;
    UINT8           classOfDevice[3];
    UINT16          clockOffset;

} HCI_EVT_INQUIRY_RESULT;
#pragma pack()

#pragma pack(1)
typedef PACKED struct
{
    HCI_EVT_HDR     header;                // event header
    UINT8           numResponses;
    CFA_BD_ADDR     bdAddr;
    UINT8           pageScanRepetitionMode;
    UINT8           pageScanPeriodMode;
    UINT8           classOfDevice[3];
    UINT16          clockOffset;
    INT8            rssi;

} HCI_EVT_INQUIRY_RESULT_WITH_RSSI;
#pragma pack()

#define EIR_MAX_PAYLOAD_LEN 240

#pragma pack(1)
typedef PACKED struct
{
    HCI_EVT_HDR     header;                // event header
    UINT8           numResponses;
    CFA_BD_ADDR     bdAddr;
    UINT8           pageScanRepetitionMode;
    UINT8           pageScanPeriodMode;
    UINT8           classOfDevice[3];
    UINT16          clockOffset;
    INT8            rssi;
    UINT8           ird[EIR_MAX_PAYLOAD_LEN];

} HCI_EVT_EXTENDED_INQUIRY_RESULT;
#pragma pack()

#pragma pack(1)
// connectionDescriptorArray parameter
typedef PACKED struct
{
    UINT16           connHandle;          // connection handle
    UINT16           numCompletedPackets; // the number of HCI Data Packets completed since previous time
} HCI_PARAM_CONN_DESCRIPTOR;

typedef PACKED struct
{
    HCI_EVT_HDR             header;     // event header
    UINT8                   numHandles; // number of connection handles

    // variable size array of HCI_PARAM_CONNECTION_DESCRIPTOR (at least one entry)
    HCI_PARAM_CONN_DESCRIPTOR  descriptor [1];  // array of connection parameters
} HCI_EVT_NUM_COMPLETED_PACKETS;
#pragma pack()

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// 10.10 I2C Interface
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//------------------------------------------------------------------------------
// 10.10.1       Types
//------------------------------------------------------------------------------

#define CFA_BSC_CADDR_WCTL_ADR_SLAVE0   0xA0
#define CFA_BSC_CTL_DV_CLK_BY_4         (0x01 << 7)

#define CFA_BSC_CTL_SCL_400KHZ          (0x00 << 4)
#define CFA_BSC_CTL_SCL_100KHZ          (0x01 << 4)
#define CFA_BSC_CTL_SCL_800KHZ          (0x02 << 4)
#define CFA_BSC_CTL_SCL_1000KHZ         (0x03 << 4)
#define CFA_BSC_CTL_SCL_MASK            (0x03 << 4)

#define CFA_BSC_CTL_INT_ENBL            0x40
#define CFA_BSC_CNTL_DISABLE            0x00

// Operation
#define CFA_BSC_OP_READ     0
#define CFA_BSC_OP_WRITE    1

// Max transaction size
#if FIX_CQ_2935115
//Define in bsc.h
#else
#define CFA_BSC_MAX_TRANSACTION_SIZE  8
#endif

typedef enum
{
    CFA_BSC_STATUS_INCOMPLETE = 0,
    CFA_BSC_STATUS_SUCCESS = 1,
    CFA_BSC_STATUS_NO_ACK = 3
}CFA_BSC_STATUS;


#ifdef __cplusplus
}
#endif

#endif // _CFA_H_
