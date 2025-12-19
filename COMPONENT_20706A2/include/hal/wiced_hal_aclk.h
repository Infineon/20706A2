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
* List of parameters and defined functions needed to access the
* Auxiliary Clock (aclk) driver.
*
*/

#ifndef __WICED_ACLK_H__
#define __WICED_ACLK_H__

#include "aclk.h"

/**  \addtogroup AuxClkDriver Auxiliary Clock (ACLK)
 *   \ingroup HardwareDrivers
 *
 * @{
 *
 * Defines a driver to facilitate interfacing with the auxiliary clock.
 *
 * Use this driver to output a clock to a GPIO pin for external use. Two clock
 * sources are avaliable: clk0 or clk1, as well as two base frequencies used
 * to calulate the prescaler : 1 MHz or 24 MHz. Note that the desired GPIO pin
 * must have already been configured to output for aclk. See the HW muxing
 * section in the Kit Guide for more information.
 *

***************************************************************************
*** Parameters.
***
*** The following enumerations are used to configure the driver or define
*** return status. They are not modifiable.
***************************************************************************

// Available clock sources.
@verbatim
enum CLK_SRC_SEL
{
    ACLK0,
    ACLK1,
	WICED_ACLK0 = ACLK0,
	WICED_ACLK1 = ACLK1
};
@endverbatim

// Available base clock frequencies.
@verbatim
enum CLK_SRC_FREQ_SEL
{
    ACLK_FREQ_1_MHZ,
    ACLK_FREQ_24_MHZ
	WICED_ACLK_FREQ_24_MHZ = ACLK_FREQ_24_MHZ
};
@endverbatim
**/

/******************************************************************************
*** Function prototypes and defines.
******************************************************************************/

///////////////////////////////////////////////////////////////////////////////
/// Configures, enables, and starts the aclk to be active on a
/// preconfigured GPIO pin.
///
/// (!) Note that the desired GPIO pin must have already been configured
/// to output for aclk. See the HW muxing section in the HW User Manual or Kit
/// Guide for your device for more information.
///
/// \param frequency   - Desired frequency to output; 0 is the same as disable.
/// \param clkSrc      - ACLK0 or ACLK1
/// \param baseFreqSel - ACLK_FREQ_1_MHZ or ACLK_FREQ_24_MHZ.
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
static INLINE void wiced_hal_aclk_enable(UINT32 frequency,
                                         UINT32 clkSrc,
                                         UINT32 baseFreqSel)
{
    aclk_configure(frequency, clkSrc, baseFreqSel);
}

///////////////////////////////////////////////////////////////////////////////
/// Disables the desired auxilary clock source.
///
/// \param clkSrc - Clock source to disable (aclk0 or aclk1).
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
static INLINE void wiced_hal_aclk_disable(UINT32 clkSrc)
{
    aclk_disableClock(clkSrc);
}

///////////////////////////////////////////////////////////////////////////////
/// Configure the GPIO pin for the desired auxilary clock source.
/// This function is in the wiced_hal_aclk_lib.a library.
///
/// \param gpioPin - GPIO pin for the output of Clock source.
///                      Only gpio pin 32, 36 are for ACLK 0
///                      Only gpio pin 33, 37 are for ACLK 1
/// \param clkSrc  - Clock source to disable (aclk0 or aclk1).
///                      0 - aclk0
///                      1 - aclk1
///
/// \return TRUE  - Success
///         FALSE - Failed
///////////////////////////////////////////////////////////////////////////////
UINT32 wiced_hal_aclk_pads_config(UINT32 gpio, UINT32 src);


/* @} */

#endif // __WICED_ACLK_H__
