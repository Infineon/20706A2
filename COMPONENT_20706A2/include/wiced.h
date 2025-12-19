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

/****************************************************************************
**
** Name:         wiced.h
**
** Description:  wiced header file
**
******************************************************************************/
#ifndef WICED_H
#define WICED_H

#include "wiced_result.h"
#include "stdint.h"
#include "string.h"

#define WICED_SUPPRESS_WARNINGS(m) if((m)){;}

/* Suppress unused variable warning */
#ifndef UNUSED_VARIABLE
#define UNUSED_VARIABLE(x) /*@-noeffect@*/ ( (void)(x) ) /*@+noeffect@*/
#endif

//typedef int wiced_thread_t;
#if 0
typedef unsigned int    uint32_t;
typedef signed char     int8_t;
typedef short           int16_t;
typedef int             int32_t;
typedef unsigned char   uint8_t;
typedef unsigned short  uint16_t;
#endif
typedef unsigned char   wiced_bool_t;

#define WICED_FALSE 0
#define WICED_TRUE  1

#define WPRINT_BT_APP_INFO(info)   {printf info;}
#endif //WICED_H
