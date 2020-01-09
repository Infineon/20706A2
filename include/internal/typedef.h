/******************************************************************************
**
**  File Name:   typedef.h
**
**  Description: This file contains types used by SBC
**
**  Copyright (c) 1999-2008, Broadcom Corp., All Rights Reserved.
**  Broadcom Bluetooth Core. Proprietary and confidential.
**
******************************************************************************/


#ifndef __TYPEDEF__
#define __TYPEDEF__

typedef short   Word16;
typedef long    Word32;
typedef double  Float;
typedef int     Flag;


#if defined __ghs__
typedef long long SINT64;
#elif defined __CC_ARM
typedef __int64 SINT64;
#endif

#endif
