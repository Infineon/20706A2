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

/** @file
*
* List of parameters and defined functions needed to utilize the
*
*
*/

#ifndef __WICED_RAND_H__
#define __WICED_RAND_H__

#include "wiced.h"

/**  \addtogroup RandomNumberGenerator Random Number Generator (RNG)
* \ingroup HardwareDrivers
* @{
*
* Defines a driver for the Random Number Generator (RNG). The RNG uses a
* special hardware module to generate either a single 32-bit random number or
* fill a given array with 32-bit random numbers. These are useful for
* applications such as authentication.
*
*/

/******************************************************************************
*** Function prototypes.
******************************************************************************/

///////////////////////////////////////////////////////////////////////////////
/// Generates and returns a random 32-bit integer. Internal functions check
/// that the generating hardware is warmed up and ready before returning
/// the random value. If the hardware is too "cold" at the time of use,
/// the function will instead use the Bluetooth clock as a "seed" and generate a
/// "soft" random number.
///
/// \param none
///
/// \return A randomly generated 32-bit integer.
///////////////////////////////////////////////////////////////////////////////
uint32_t wiced_hal_rand_gen_num(void);

///////////////////////////////////////////////////////////////////////////////
/// Fills a given array with randomly generated 32-bit integers. Uses the
/// function wiced_hal_rand_gen_num().
///
/// \param randNumberArrayPtr - Pointer to an array to be populated with
///                             the random numbers.
/// \param length             - Length of the array pointed to by
///                             randNumberArrayPtr.
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_rand_gen_num_array(uint32_t* randNumberArrayPtr, uint32_t length);

#define wiced_hal_get_pseudo_rand_number        wiced_hal_rand_gen_num
/**@}*/

#endif // __WICED_RAND_H__
