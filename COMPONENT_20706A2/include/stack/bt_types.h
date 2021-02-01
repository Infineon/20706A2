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
/****************************************************************************
**
**  Name        bt_types.h
**
**  Function    this file contains definitions that are shared between
**              units in the Bluetooth system such as events.
**
****************************************************************************/

#ifndef BT_TYPES_H
#define BT_TYPES_H

#include "stdint.h"

/* Define the header of each buffer used in the Bluetooth stack.
*/
typedef struct
{
    uint16_t          event;
    uint16_t          len;
    uint16_t          offset;
    uint16_t          layer_specific;
} BT_HDR;

#define BT_HDR_SIZE (sizeof (BT_HDR))

#define BT_PSM_SDP                      0x0001 /* Service Discovery Protocol) */
#define BT_PSM_RFCOMM                   0x0003 /* RFCOMM with TS 07.10 */
#define BT_PSM_TCS                      0x0005 /* (deprecated) */
#define BT_PSM_CTP                      0x0007 /* (deprecated) */
#define BT_PSM_BNEP                     0x000F /* Bluetooth Network Encapsulation Protocol */
#define BT_PSM_HIDC                     0x0011 /* Human Interface Device (Control) */
#define BT_PSM_HIDI                     0x0013 /* Human Interface Device (Interrupt) */
#define BT_PSM_UPNP                     0x0015 /* Universal PlugNPlay */
#define BT_PSM_AVCTP                    0x0017 /* Audio/Video Control Transport Protocol */
#define BT_PSM_AVDTP                    0x0019 /* Audio/Video Distribution Transport Protocol */
#define BT_PSM_AVCTP_13                 0x001B /* Advanced Control - Browsing */
#define BT_PSM_UDI_CP                   0x001D /* Unrestricted Digital Information C-Plane  */
#define BT_PSM_ATT                      0x001F /* Attribute Protocol  */
#define BT_PSM_3DS                      0x0021 /* 3D sync */
#define BT_LE_PSM_IPSP                  0x0023 /* Internet Protocol Support (IPv6/6LoWPAN) */


#define BD_ADDR_LEN     6                   /* Device address length */
typedef uint8_t BD_ADDR[BD_ADDR_LEN];         /* Device address */
typedef uint8_t *BD_ADDR_PTR;                 /* Pointer to Device Address */

#define BT_OCTET8_LEN    8
typedef uint8_t BT_OCTET8[BT_OCTET8_LEN];   /* octet array: size 8 */

/* Maximum UUID size - 16 bytes, and structure to hold any type of UUID. */
#define MAX_UUID_SIZE              16
typedef struct
{
#define LEN_UUID_16     2
#define LEN_UUID_32     4
#define LEN_UUID_128    16

    uint16_t          len;

    union
    {
        uint16_t      uuid16;
        uint32_t      uuid32;
        uint8_t       uuid128[MAX_UUID_SIZE];
    } uu;

} tBT_UUID;

#define BT_EIR_FLAGS_TYPE                   0x01
#define BT_EIR_MORE_16BITS_UUID_TYPE        0x02
#define BT_EIR_COMPLETE_16BITS_UUID_TYPE    0x03
#define BT_EIR_MORE_32BITS_UUID_TYPE        0x04
#define BT_EIR_COMPLETE_32BITS_UUID_TYPE    0x05
#define BT_EIR_MORE_128BITS_UUID_TYPE       0x06
#define BT_EIR_COMPLETE_128BITS_UUID_TYPE   0x07
#define BT_EIR_SHORTENED_LOCAL_NAME_TYPE    0x08
#define BT_EIR_COMPLETE_LOCAL_NAME_TYPE     0x09
#define BT_EIR_TX_POWER_LEVEL_TYPE          0x0A
#define BT_EIR_OOB_BD_ADDR_TYPE             0x0C
#define BT_EIR_OOB_COD_TYPE                 0x0D
#define BT_EIR_OOB_SSP_HASH_C_TYPE          0x0E
#define BT_EIR_OOB_SSP_RAND_R_TYPE          0x0F
#define BT_EIR_OOB_SSP_HASH_C_256_TYPE      0x1D
#define BT_EIR_OOB_SSP_RAND_R_256_TYPE      0x1E
#define BT_EIR_3D_SYNC_TYPE                 0x3D
#define BT_EIR_MANUFACTURER_SPECIFIC_TYPE   0xFF

#define BT_EVT_TO_LM_HCI_CMD        0x2000      /* HCI Command                      */
#define BT_EVT_TO_LM_HCI_ACL        0x2100      /* HCI ACL Data                     */
#define BT_EVT_TO_LM_HCI_SCO        0x2200      /* HCI SCO Data                     */
#define BT_EVT_TO_LM_HCIT_ERR       0x2300      /* HCI Transport Error              */
#define BT_EVT_TO_LM_LC_EVT         0x2400      /* LC event                         */
#define BT_EVT_TO_LM_LC_LMP         0x2500      /* LC Received LMP command frame    */
#define BT_EVT_TO_LM_LC_ACL         0x2600      /* LC Received ACL data             */
#define BT_EVT_TO_LM_LC_SCO         0x2700      /* LC Received SCO data  (not used) */
#define BT_EVT_TO_LM_LC_ACL_TX      0x2800      /* LMP data transmit complete       */
#define BT_EVT_TO_LM_LC_LMPC_TX     0x2900      /* LMP Command transmit complete    */
#define BT_EVT_TO_LM_LOCAL_ACL_LB   0x2a00      /* Data to be locally loopbacked    */
#define BT_EVT_TO_LM_HCI_ACL_ACK    0x2b00      /* HCI ACL Data ack      (not used) */
#define BT_EVT_TO_LM_DIAG           0x2c00      /* LM Diagnostics commands          */

typedef uint8_t tBT_TRANSPORT;


/* Define PSMs HID uses */
#define HID_PSM_CONTROL         BT_PSM_HIDC
#define HID_PSM_INTERRUPT       BT_PSM_HIDI


/* Define trace levels */
#define BT_TRACE_LEVEL_NONE    0          /* No trace messages to be generated    */
#define BT_TRACE_LEVEL_ERROR   1          /* Error condition trace messages       */
#define BT_TRACE_LEVEL_WARNING 2          /* Warning condition trace messages     */
#define BT_TRACE_LEVEL_API     3          /* API traces                           */
#define BT_TRACE_LEVEL_EVENT   4          /* Debug messages for events            */
#define BT_TRACE_LEVEL_DEBUG   5          /* Full debug messages                  */

#define MAX_TRACE_LEVEL        5


/********************************************************************************
** Macros to get and put bytes to and from a stream (Little Endian format).
*/
#define UINT128_TO_STREAM(p, u128) {*(p)++ = (uint8_t)(u128);       *(p)++ = (uint8_t)((u128) >> 8);*(p)++ = (uint8_t)((u128) >> 16); *(p)++ = (uint8_t)((u128) >> 24); \
                                    *(p)++ = (uint8_t)((u128) >> 32); *(p)++ = (uint8_t)((u128) >> 40);*(p)++ = (uint8_t)((u128) >> 48); *(p)++ = (uint8_t)((u128) >> 56); \
                                    *(p)++ = (uint8_t)((u128) >> 64); *(p)++ = (uint8_t)((u128) >> 72);*(p)++ = (uint8_t)((u128) >> 80); *(p)++ = (uint8_t)((u128) >> 88); \
                                    *(p)++ = (uint8_t)((u128) >> 96); *(p)++ = (uint8_t)((u128) >> 104);*(p)++ = (uint8_t)((u128) >> 112); *(p)++ = (uint8_t)((u128) >> 120); }
#define UINT64_TO_STREAM(p, u64) {*(p)++ = (uint8_t)(u64);       *(p)++ = (uint8_t)((u64) >> 8);*(p)++ = (uint8_t)((u64) >> 16); *(p)++ = (uint8_t)((u64) >> 24); \
                                    *(p)++ = (uint8_t)((u64) >> 32); *(p)++ = (uint8_t)((u64) >> 40);*(p)++ = (uint8_t)((u64) >> 48); *(p)++ = (uint8_t)((u64) >> 56);}
#define UINT40_TO_STREAM(p, u40) {*(p)++ = (UINT8)(u40); *(p)++ = (UINT8)((u40) >> 8); *(p)++ = (UINT8)((u40) >> 16); *(p)++ = (UINT8)((u40) >> 24); \
                                  *(p)++ = (UINT8)((u40) >> 32);}
#define UINT48_TO_STREAM(p, u48) {*(p)++ = (UINT8)(u48); *(p)++ = (UINT8)((u48) >> 8); *(p)++ = (UINT8)((u48) >> 16); *(p)++ = (UINT8)((u48) >> 24); *(p)++ = (UINT8)((u48) >> 32); *(p)++ = (UINT8)((u48) >> 40);}
#define UINT32_TO_STREAM(p, u32) {*(p)++ = (uint8_t)(u32); *(p)++ = (uint8_t)((u32) >> 8); *(p)++ = (uint8_t)((u32) >> 16); *(p)++ = (uint8_t)((u32) >> 24);}
#define UINT24_TO_STREAM(p, u24) {*(p)++ = (uint8_t)(u24); *(p)++ = (uint8_t)((u24) >> 8); *(p)++ = (uint8_t)((u24) >> 16);}
#define UINT16_TO_STREAM(p, u16) {*(p)++ = (uint8_t)(u16); *(p)++ = (uint8_t)((u16) >> 8);}
#define UINT8_TO_STREAM(p, u8)   {*(p)++ = (uint8_t)(u8);}
#define INT8_TO_STREAM(p, u8)    {*(p)++ = (INT8)(u8);}
#define ARRAY32_TO_STREAM(p, a)  {register int ijk; for (ijk = 0; ijk < 32;           ijk++) *(p)++ = (uint8_t) a[31 - ijk];}
#define ARRAY16_TO_STREAM(p, a)  {register int ijk; for (ijk = 0; ijk < 16;           ijk++) *(p)++ = (uint8_t) a[15 - ijk];}
#define ARRAY8_TO_STREAM(p, a)   {register int ijk; for (ijk = 0; ijk < 8;            ijk++) *(p)++ = (uint8_t) a[7 - ijk];}
#define BDADDR_TO_STREAM(p, a)   {register int ijk; for (ijk = 0; ijk < BD_ADDR_LEN;  ijk++) *(p)++ = (uint8_t) a[BD_ADDR_LEN - 1 - ijk];}
#define LAP_TO_STREAM(p, a)      {register int ijk; for (ijk = 0; ijk < LAP_LEN;      ijk++) *(p)++ = (uint8_t) a[LAP_LEN - 1 - ijk];}
#define DEVCLASS_TO_STREAM(p, a) {register int ijk; for (ijk = 0; ijk < DEV_CLASS_LEN;ijk++) *(p)++ = (uint8_t) a[DEV_CLASS_LEN - 1 - ijk];}
#define ARRAY_TO_STREAM(p, a, len) {register int ijk; for (ijk = 0; ijk < len;        ijk++) *(p)++ = (uint8_t) a[ijk];}
#define REVERSE_ARRAY_TO_STREAM(p, a, len)  {register int ijk; for (ijk = 0; ijk < len; ijk++) *(p)++ = (uint8_t) a[len - 1 - ijk];}

#define STREAM_TO_UINT8(u8, p)   {u8 = (uint8_t)(*(p)); (p) += 1;}
#define STREAM_TO_UINT16(u16, p) {u16 = ((UINT16)(*(p)) + (((UINT16)(*((p) + 1))) << 8)); (p) += 2;}
#define STREAM_TO_UINT24(u32, p) {u32 = (((UINT32)(*(p))) + ((((UINT32)(*((p) + 1)))) << 8) + ((((UINT32)(*((p) + 2)))) << 16) ); (p) += 3;}
#define STREAM_TO_UINT32(u32, p) {u32 = (((UINT32)(*(p))) + ((((UINT32)(*((p) + 1)))) << 8) + ((((UINT32)(*((p) + 2)))) << 16) + ((((UINT32)(*((p) + 3)))) << 24)); (p) += 4;}
#define STREAM_TO_UINT40(u40, p) {u40 = (((UINT64)(*(p))) + ((((UINT64)(*((p) + 1)))) << 8) + ((((UINT64)(*((p) + 2)))) << 16) + ((((UINT64)(*((p) + 3)))) << 24) + ((((UINT64)(*((p) + 4)))) << 32)); (p) += 5;}
#define STREAM_TO_BDADDR(a, p)   {register int ijk; register uint8_t *pbda = (uint8_t *)a + BD_ADDR_LEN - 1; for (ijk = 0; ijk < BD_ADDR_LEN; ijk++) *pbda-- = *p++;}
#define STREAM_TO_ARRAY32(a, p)  {register int ijk; register uint8_t *_pa = (uint8_t *)a + 31; for (ijk = 0; ijk < 32; ijk++) *_pa-- = *p++;}
#define STREAM_TO_ARRAY16(a, p)  {register int ijk; register uint8_t *_pa = (uint8_t *)a + 15; for (ijk = 0; ijk < 16; ijk++) *_pa-- = *p++;}
#define STREAM_TO_ARRAY8(a, p)   {register int ijk; register uint8_t *_pa = (uint8_t *)a + 7; for (ijk = 0; ijk < 8; ijk++) *_pa-- = *p++;}
#define STREAM_TO_DEVCLASS(a, p) {register int ijk; register uint8_t *_pa = (uint8_t *)a + DEV_CLASS_LEN - 1; for (ijk = 0; ijk < DEV_CLASS_LEN; ijk++) *_pa-- = *p++;}
#define STREAM_TO_LAP(a, p)      {register int ijk; register uint8_t *plap = (uint8_t *)a + LAP_LEN - 1; for (ijk = 0; ijk < LAP_LEN; ijk++) *plap-- = *p++;}
#define STREAM_TO_ARRAY(a, p, len) {register int ijk; for (ijk = 0; ijk < len; ijk++) ((uint8_t *) a)[ijk] = *p++;}
#define REVERSE_STREAM_TO_ARRAY(a, p, len) {register int ijk; register uint8_t *_pa = (uint8_t *)a + len - 1; for (ijk = 0; ijk < len; ijk++) *_pa-- = *p++;}

/********************************************************************************
** Macros to get and put bytes to and from a stream (Big Endian format)
*/
#define UINT128_TO_BE_STREAM(p, u128) {*(p)++ = (UINT8)(u128)>> 120;       *(p)++ = (UINT8)((u128) >> 112);*(p)++ = (UINT8)((u128) >> 104); *(p)++ = (UINT8)((u128) >> 96); \
                                    *(p)++ = (UINT8)((u128) >> 88); *(p)++ = (UINT8)((u128) >> 80);*(p)++ = (UINT8)((u128) >> 72); *(p)++ = (UINT8)((u128) >> 64); \
                                    *(p)++ = (UINT8)((u128) >> 56); *(p)++ = (UINT8)((u128) >> 48);*(p)++ = (UINT8)((u128) >> 40); *(p)++ = (UINT8)((u128) >> 32); \
                                    *(p)++ = (UINT8)((u128) >> 24); *(p)++ = (UINT8)((u128) >> 16);*(p)++ = (UINT8)((u128) >> 8); *(p)++ = (UINT8)(u128); }
#define UINT64_TO_BE_STREAM(p, u64) {*(p)++ = (UINT8)((u64) >> 56); *(p)++ = (UINT8)((u64) >> 48);*(p)++ = (UINT8)((u64) >> 40); *(p)++ = (UINT8)((u64) >> 32); \
                                     *(p)++ = (UINT8)((u64) >> 24); *(p)++ = (UINT8)((u64) >> 16);*(p)++ = (UINT8)((u64) >> 8); *(p)++ = (UINT8)(u64); }
#define UINT32_TO_BE_STREAM(p, u32) {*(p)++ = (UINT8)((u32) >> 24);  *(p)++ = (UINT8)((u32) >> 16); *(p)++ = (UINT8)((u32) >> 8); *(p)++ = (UINT8)(u32); }
#define UINT24_TO_BE_STREAM(p, u24) {*(p)++ = (UINT8)((u24) >> 16); *(p)++ = (UINT8)((u24) >> 8); *(p)++ = (UINT8)(u24);}
#define UINT16_TO_BE_STREAM(p, u16) {*(p)++ = (UINT8)((u16) >> 8); *(p)++ = (UINT8)(u16);}
#define UINT8_TO_BE_STREAM(p, u8)   {*(p)++ = (UINT8)(u8);}
#define ARRAY_TO_BE_STREAM(p, a, len) {register int ijk; for (ijk = 0; ijk < len; ijk++) *(p)++ = (UINT8) a[ijk];}

#define BE_STREAM_TO_UINT8(u8, p)   {u8 = (UINT8)(*(p)); (p) += 1;}
#define BE_STREAM_TO_UINT16(u16, p) {u16 = (UINT16)(((UINT16)(*(p)) << 8) + (UINT16)(*((p) + 1))); (p) += 2;}
#define BE_STREAM_TO_UINT24(u32, p) {u32 = (((UINT32)(*((p) + 2))) + ((UINT32)(*((p) + 1)) << 8) + ((UINT32)(*(p)) << 16)); (p) += 3;}
#define BE_STREAM_TO_UINT32(u32, p) {u32 = ((UINT32)(*((p) + 3)) + ((UINT32)(*((p) + 2)) << 8) + ((UINT32)(*((p) + 1)) << 16) + ((UINT32)(*(p)) << 24)); (p) += 4;}
#define BE_STREAM_TO_UINT64(u64, p) {u64 = ((UINT64)(*((p) + 7)) + ((UINT64)(*((p) + 6)) << 8) + ((UINT64)(*((p) + 5)) << 16) + ((UINT64)(*((p) + 4)) << 24) + \
                                           ((UINT64)(*((p) + 3)) << 32) + ((UINT64)(*((p) + 2)) << 40) + ((UINT64)(*((p) + 1)) << 48) + ((UINT64)(*(p)) << 56)); (p) += 8;}
#define BE_STREAM_TO_ARRAY(p, a, len) {register int ijk; for (ijk = 0; ijk < len; ijk++) ((UINT8 *) a)[ijk] = *p++;}

#endif
