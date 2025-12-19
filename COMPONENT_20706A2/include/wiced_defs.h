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
