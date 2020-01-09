/******************************************************************************
**
**  File Name:   sbc_types.h
**
**  Description: This file contains types used by SBC
**
**  Copyright (c) 1999-2008, Broadcom Corp., All Rights Reserved.
**  Broadcom Bluetooth Core. Proprietary and confidential.
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
