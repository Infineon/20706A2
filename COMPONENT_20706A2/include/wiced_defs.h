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

#ifndef WICED_DEFS_H
#define WICED_DEFS_H

#include "bt_types.h"

/* define prefix for exporting APIs from libraries */
#define EXPORT_API

/* The ID of buffer pool 2. */
#define GKI_POOL_ID_1               1

/* The ID of buffer pool 2. */
#define GKI_POOL_ID_2               2

/* The ID of buffer pool 3. */
#define GKI_POOL_ID_3               3

/* When automatic inquiry scan is enabled, this sets the inquiry scan window. */
#define BTM_DEFAULT_DISC_WINDOW     0x0012

/* When automatic inquiry scan is enabled, this sets the inquiry scan interval. */
#define BTM_DEFAULT_DISC_INTERVAL   0x0800

/* Sets the Page_Scan_Window:  the length of time that the device is performing a page scan. */
#define BTM_DEFAULT_CONN_WINDOW     0x0012

/* Sets the Page_Scan_Activity:  the interval between the start of two consecutive page scans. */
#define BTM_DEFAULT_CONN_INTERVAL   0x0800

/* The maximum number of UUID filters supported by SDP databases. */
#define SDP_MAX_UUID_FILTERS        3

/* The maximum number of parameters in an SDP protocol element. */
#define SDP_MAX_PROTOCOL_PARAMS     2

/* The maximum number of attribute filters supported by SDP databases. */
#define SDP_MAX_ATTR_FILTERS        12

/* Maximum size in bytes of the codec capabilities information element. */
#define AVDT_CODEC_SIZE             10

/* Maximum size in bytes of the content protection information element. */
#define AVDT_PROTECT_SIZE           90

/*************************************************************************
** Definitions for Both HID-Host & Device
*/
#define HID_MAX_SVC_NAME_LEN  32

#define HID_MAX_SVC_DESCR_LEN 32

#define HID_MAX_PROV_NAME_LEN 32

/* The HID Device is a virtual cable */
#define HID_DEV_VIRTUAL_CABLE   TRUE

/* The HID device initiates the reconnections */
#define HID_DEV_RECONN_INITIATE     TRUE

/* THe HID device is normally connectable */
#define HID_DEV_NORMALLY_CONN       FALSE

/* The device is battery powered */
#define HID_DEV_BATTERY_POW         TRUE

/* Device is capable of waking up the host */
#define HID_DEV_REMOTE_WAKE         TRUE

#define HID_DEV_MTU_SIZE    64

#define HID_DEV_FLUSH_TO    0xffff

#define HID_DEV_MAX_CONN_RETRY      (1)

#define HID_DEV_REPAGE_WIN  (1)

extern void *GKI_getpoolbuf (UINT8 pool_id);

/* Macro for allocating buffer for HCI commands */
#ifndef HCI_GET_CMD_BUF
#if (!defined(HCI_USE_VARIABLE_SIZE_CMD_BUF) || (HCI_USE_VARIABLE_SIZE_CMD_BUF == FALSE))
/* Allocate fixed-size buffer from HCI_CMD_POOL (default case) */
#define HCI_GET_CMD_BUF(paramlen)    ((BT_HDR *)GKI_getpoolbuf (HCI_CMD_POOL_ID))
#else
/* Allocate smallest possible buffer (for platforms with limited RAM) */
#define HCI_GET_CMD_BUF(paramlen)    ((BT_HDR *)GKI_getbuf ((UINT16)(BT_HDR_SIZE + HCIC_PREAMBLE_SIZE + (paramlen))))
#endif
#endif  /* HCI_GET_CMD_BUF */

#define L2CAP_CONN_CANCEL   256

#define MAY_BE_STATIC
#define HID_API

#ifdef version
#undef version
#endif

#ifdef tx_power
#undef tx_power
#endif

#define BLE_INCLUDED                    TRUE
#define SMP_INCLUDED                    TRUE
#define SMP_LE_SC_INCLUDED              TRUE
#define SMP_LE_SC_OOB_INCLUDED          TRUE

#define HCI_CMD_POOL_ID     GKI_POOL_ID_1
#define HCI_ACL_POOL_ID     GKI_POOL_ID_2

extern void *GKI_getpoolbuf (UINT8 pool_id);
extern void *GKI_getbuf (UINT16);

/* RESERVED buffer pool for OBX */
/* Ideally there should be 1 buffer for each instance for RX data, and some number
of TX buffers based on active instances. OBX will only use these if packet size
requires it. In most cases the large packets are used in only one direction so
the other direction will use smaller buffers.
Devices with small amount of RAM should limit the number of active obex objects.
*/
/* The size of the buffers in pool 4. */
#ifndef GKI_BUF4_SIZE
#define GKI_BUF4_SIZE               0x2000
#endif

#ifndef OBX_LRG_DATA_POOL_SIZE
#define OBX_LRG_DATA_POOL_SIZE      GKI_BUF4_SIZE
#endif

/* Maximum device name length used in btm database. */
#ifndef BTM_MAX_REM_BD_NAME_LEN
#define BTM_MAX_REM_BD_NAME_LEN     20
#endif

#endif /* WICED_DEFS_H */
