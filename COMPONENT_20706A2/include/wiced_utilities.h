/**
 * @cond
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
 * @endcond
 *
 * @file
 * This file constains general utilities for AIROC BTSDK.
 */
#pragma once

/**
 * @addtogroup helper Generic Helper Macros
 * @ingroup wicedsys
 * @{
 */

/** Macro to get the minimum from 2 arguments */
#ifndef MIN
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#endif

/** Macro to get the maximum from 2 arguments */
#ifndef MAX
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#endif

#ifndef _countof
/** Determine the number of elements in an array. */
#define _countof(x) (sizeof(x) / sizeof(x[0]))
#endif

/** Macro to reverse bytes in a 16-bit value */
#define WICED_SWAP16(val) \
    ((uint16_t)((((uint16_t)(val) & (uint16_t)0x00ffU) << 8) | \
        (((uint16_t)(val) & (uint16_t)0xff00U) >> 8)))

/** Macro to reverse bytes in a 32-bit value */
#define WICED_SWAP32(val) \
    ((uint32_t)((((uint32_t)(val) & (uint32_t)0x000000ffU) << 24) | \
        (((uint32_t)(val) & (uint32_t)0x0000ff00U) <<  8) | \
        (((uint32_t)(val) & (uint32_t)0x00ff0000U) >>  8) | \
        (((uint32_t)(val) & (uint32_t)0xff000000U) >> 24)))

/** Macro to reverse bytes in a 64-bit value */
#define WICED_SWAP64(val) \
    ((uint64_t)( \
        (((uint64_t)(val) & (uint64_t)0x00000000000000ffllU) << 56) | \
        (((uint64_t)(val) & (uint64_t)0x000000000000ff00llU) << 40) | \
        (((uint64_t)(val) & (uint64_t)0x0000000000ff0000llU) << 24) | \
        (((uint64_t)(val) & (uint64_t)0x00000000ff000000llU) <<  8) | \
        (((uint64_t)(val) & (uint64_t)0x000000ff00000000llU) >>  8) | \
        (((uint64_t)(val) & (uint64_t)0x0000ff0000000000llU) >> 24) | \
        (((uint64_t)(val) & (uint64_t)0x00ff000000000000llU) >> 40) | \
        (((uint64_t)(val) & (uint64_t)0xff00000000000000llU) >> 56)))

/** Load 16-bit value from unaligned big-endian byte array */
#define WICED_NTOH16(val) \
    ((uint16_t)( \
        ((uint16_t)((val)[0]) << 8) | \
        ((uint16_t)((val)[1]))))

/** Load 32-bit value from unaligned big-endian byte array */
#define WICED_NTOH32(val) \
    ((uint32_t)( \
        ((uint32_t)((val)[0]) << 24) | \
        ((uint32_t)((val)[1]) << 16) | \
        ((uint32_t)((val)[2]) <<  8) | \
        ((uint32_t)((val)[3]))))

/** Load 64-bit value from unaligned big-endian byte array */
#define WICED_NTOH64(val) \
    ((uint64_t)( \
        ((uint64_t)((val)[0]) << 56) | \
        ((uint64_t)((val)[1]) << 48) | \
        ((uint64_t)((val)[2]) << 40) | \
        ((uint64_t)((val)[3]) << 32) | \
        ((uint64_t)((val)[4]) << 24) | \
        ((uint64_t)((val)[5]) << 16) | \
        ((uint64_t)((val)[6]) <<  8) | \
        ((uint64_t)((val)[7]))))

/** @} */
