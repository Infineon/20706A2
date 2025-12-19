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
* CPU Clock.
*
*/

#ifndef __WICED_CPU_CLOCK_H__
#define __WICED_CPU_CLOCK_H__


/**  \addtogroup CPU Clock
* \ingroup HardwareDrivers
* Defines a driver to facilitate interfacing with the CPU clock.
*
* Use this to update the CPU clock frequency.
* Care should be taken by an App that it doesn't disable a frequency not set by it.
*
* @{ */

/******************************************************************************
*** Parameters.
***
*** The following parameters are used to configure the driver or define
*** return status. They are not modifiable.
******************************************************************************/
/** Clock Frequency*/
typedef enum
{
    WICED_CPU_CLK_24MHZ,    /**< 24Mhz clock frequency */
    WICED_CPU_CLK_32MHZ,    /**< 32Mhz clock frequency */
    WICED_CPU_CLK_48MHZ,    /**< 48Mhz clock frequency */
    WICED_CPU_CLK_96MHZ,    /**< 96Mhz clock frequency */
} wiced_cpu_clk_freq_t;

/******************************************************************************
*** Function prototypes and defines.
******************************************************************************/

///////////////////////////////////////////////////////////////////////////////
/// enables/disables the given cpu clock frequency.
/// the actual clock frequency is selected appropriately within the driver.
///
/// \param enable      - enable or disable clock frequency.
/// \param freq        - clock frequency to enable/disable.
///
///  Note : For 96MHz clock all interrupts will be disabled until it is released.
///
/// \return wiced_bool_t
///
///  Usage:The application should call the API with argument enable set to WICED_TRUE to request the FW to set the clock speed to the desired value.
///        When the application is done with its work at this clock speed and wants to return to the previous speed,
///        it shall call the API with the argument enable set to WICED_FALSE and set the argument freq to the same frequency that it earlier requested to be set.
///
///////////////////////////////////////////////////////////////////////////////
wiced_bool_t wiced_update_cpu_clock( wiced_bool_t enable, wiced_cpu_clk_freq_t freq);

/** @} */
#endif // __WICED_CPU_CLOCK_H__
