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

#pragma once
#include "wiced_bt_constants.h"
#ifdef __cplusplus
extern "C" {
#endif

#ifndef RESULT_ENUM
#define RESULT_ENUM( prefix, name, value )  prefix ## name = (value)
#endif /* ifndef RESULT_ENUM */

/* AIROC result list */
#define WICED_RESULT_LIST( prefix ) \
    RESULT_ENUM( prefix, SUCCESS,                        0 ),   /**< Success */                        \
    RESULT_ENUM( prefix, PENDING,                        1 ),   /**< Pending */                        \
    RESULT_ENUM( prefix, TIMEOUT,                        2 ),   /**< Timeout */                        \
    RESULT_ENUM( prefix, PARTIAL_RESULTS,                3 ),   /**< Partial results */                \
    RESULT_ENUM( prefix, ERROR,                          4 ),   /**< Error */                          \
    RESULT_ENUM( prefix, BADARG,                         5 ),   /**< Bad Arguments */                  \
    RESULT_ENUM( prefix, BADOPTION,                      6 ),   /**< Mode not supported */             \
    RESULT_ENUM( prefix, UNSUPPORTED,                    7 ),   /**< Unsupported function */           \
    RESULT_ENUM( prefix, OUT_OF_HEAP_SPACE,              8 ),   /**< Dynamic memory space exhausted */ \
    RESULT_ENUM( prefix, NOTUP,                          9 ),   /**< Interface is not currently Up */  \
    RESULT_ENUM( prefix, UNFINISHED,                    10 ),   /**< Operation not finished yet */     \
    RESULT_ENUM( prefix, CONNECTION_LOST,               11 ),   /**< Connection to server lost */      \
    RESULT_ENUM( prefix, NOT_FOUND,                     12 ),   /**< Item not found */                 \
    RESULT_ENUM( prefix, PACKET_BUFFER_CORRUPT,         13 ),   /**< Packet buffer corrupted */        \
    RESULT_ENUM( prefix, ROUTING_ERROR,                 14 ),   /**< Routing error */                  \
    RESULT_ENUM( prefix, BADVALUE,                      15 ),   /**< Bad value */                      \
    RESULT_ENUM( prefix, WOULD_BLOCK,                   16 ),   /**< Function would block */           \
    RESULT_ENUM( prefix, ABORTED,                       17 ),   /**< Operation aborted */              \
    RESULT_ENUM( prefix, CONNECTION_RESET,              18 ),   /**< Connection has been reset */      \
    RESULT_ENUM( prefix, CONNECTION_CLOSED,             19 ),   /**< Connection is closed */           \
    RESULT_ENUM( prefix, NOT_CONNECTED,                 20 ),   /**< Connection is not connected */    \
    RESULT_ENUM( prefix, ADDRESS_IN_USE,                21 ),   /**< Address is in use */              \
    RESULT_ENUM( prefix, NETWORK_INTERFACE_ERROR,       22 ),   /**< Network interface error */        \
    RESULT_ENUM( prefix, ALREADY_CONNECTED,             23 ),   /**< Socket is already connected */    \
    RESULT_ENUM( prefix, INVALID_INTERFACE,             24 ),   /**< Interface specified in invalid */ \
    RESULT_ENUM( prefix, SOCKET_CREATE_FAIL,            25 ),   /**< Socket creation failed */         \
    RESULT_ENUM( prefix, INVALID_SOCKET,                26 ),   /**< Socket is invalid */              \
    RESULT_ENUM( prefix, CORRUPT_PACKET_BUFFER,         27 ),   /**< Packet buffer is corrupted */     \
    RESULT_ENUM( prefix, UNKNOWN_NETWORK_STACK_ERROR,   28 ),   /**< Unknown network stack error */    \
    RESULT_ENUM( prefix, NO_STORED_AP_IN_DCT,           29 ),   /**< DCT contains no AP credentials */ \
    RESULT_ENUM( prefix, STA_JOIN_FAILED,               30 ),   /**< Join failed */ \
    RESULT_ENUM( prefix, NO_MEMORY,                   0x10 ),   /**< NO_MEMORY */
/* AIROC result list */


/*************************************************************************/
/**
 *  @addtogroup  Result       AIROC Result Codes
 *  @ingroup     wicedsys
 *
 *  <b> Result types</b>. @b
 *  Result enums, macros with prefix WICED_ to WICED_RESULT_LIST and WICED_BT_ to BT_RESULT_LIST.
 *  See wiced_result.h and wiced_bt_constants.h
 *
 *  @{
 */
/*************************************************************************/
/** AIROC result */
typedef enum
{
#ifdef MPAF_CUSTOM_STACK
    WICED_RESULT_LIST(WICED_)
#endif
    BT_RESULT_LIST      (  WICED_BT_       )  /* 8000 - 8999 */
} wiced_result_t;

/**@}  AIROC Result */

/******************************************************
 *            Structures
 ******************************************************/

/******************************************************
 *            Function Declarations
 ******************************************************/

#ifdef __cplusplus
} /*extern "C" */
#endif
