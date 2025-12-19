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
/******************************************************************************
**
**  File Name:   sbc_types.h
**
**  Description: This file contains types used by SBC
**
******************************************************************************/
#ifndef SBC_TYPES_H
#define SBC_TYPES_H

#ifndef NULL
#define NULL     0
#endif

#ifndef FALSE
#define FALSE  0
#endif

#ifndef TRUE
#define TRUE   (!FALSE)
#endif


#ifndef __TYPES_H__
#define    __TYPES_H__

//
// Basic Types
//

#ifndef VOID
#define VOID void
#endif

typedef unsigned char       UINT8;
typedef signed   char       INT8;
typedef unsigned short      UINT16;
typedef signed   short      INT16;
typedef unsigned long       UINT32;
typedef signed   long       INT32;
typedef signed long long    INT64;
typedef unsigned long long UINT64;

typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef unsigned long       DWORD;

typedef unsigned char       uint8;
typedef signed   char       int8;
typedef unsigned short      uint16;
typedef signed   short      int16;
typedef unsigned long       uint32;
typedef signed   long       int32;

#endif


/*TYPEDEFS*/

typedef short SINT16;
typedef long SINT32;

#if defined __ghs__
typedef long long SINT64;
#elif defined __CC_ARM
typedef __int64 SINT64;
#endif


#if defined __ghs__
typedef long long SBC_SINT64;
#elif defined __CC_ARM
typedef __int64 SBC_SINT64;
#endif

#define abs32(x) ( (x >= 0) ? x : (-x) )

#endif
