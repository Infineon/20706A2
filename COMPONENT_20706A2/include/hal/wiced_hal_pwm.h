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
* This file lists the API's and structs required to access the
* Pulse-Width Modulation (PWM) driver.
*
*/

#ifndef __WICED_PWM_H__
#define __WICED_PWM_H__

/**  \addtogroup PwmDriver Pulse Width Modulation (PWM)
* \ingroup HardwareDrivers
* @{
* Defines a driver to facilitate interfacing with the Pulse-Width
* Modulation (PWM) driver.
*
* Use this driver to output a PWM signal to a GPIO pin for external use. There
* are four, 10-bit hardware PWM channels avaliable (0-3). Typical use-cases
* include fine-control over small devices such as LEDs. Please reference the
* Kit Guide for more information.
*
*
*/

/******************************************************************************
 * Global Data Structure definitions                                          *
 ******************************************************************************/

/**
* \addtogroup group_pwm_data_structures Structures
* PWM Structures
* \{
*/

/// PWM HW block has 4 PWM channels each with its own 10 bit counter.
/// The first PWM channel is PWM0.
typedef enum
{
    PWM0  = 0,
    PWM1  = 1,
    PWM2  = 2,
    PWM3  = 3,
    MAX_PWMS = 4
} pwm_channel_t;

/// Clock used for PWM. When LHL_CLK is set, 128 KHz is used.
/// PMU_CLK requires aclk to be configured first.
typedef enum
{
    LHL_CLK,
    PMU_CLK
} pwm_clk_t;

/// init count and toggle count for the PWM counters
typedef struct{
    UINT32 init_count;
    UINT32 toggle_count;
} pwm_config_t;

/** \} group_pwm_data_structures */

/******************************************************************************
*** Global functions .
******************************************************************************/

/**
* \addtogroup group_pwm_functions Functions
* PWM Functions
* \{
*/
///////////////////////////////////////////////////////////////////////////////
/// Configures, enables, and starts the PWM to be active on a
/// preconfigured GPIO pin.
///
/// (!) Note that the desired GPIO pin must have already been configured
/// as output. See the HW muxing section in the Kit Guide for more information.
///
/// \param channel     - Desired PWM channel to use [0-5].
/// \param clk         - PMU_CLK or LHL_CLK
/// \param toggleCount - The number of ticks to wait before toggling the signal.
/// \param initCount   - Initial value for the counter.
/// \param invert      - 1 to invert the signal.
///
/// \return 1 if PWM was successfully started, 0 otherwise.
///
/// The following example outputs a signal on P28 using the PMU clock.
///
/// (!) Note that the maximum width or period of the PWM is 0x3FF (10-bits).
///
/// (!) Note that if you use PMU_CLK instead of LHL_CLK, a call to
///     wiced_hal_aclk_enable() is required. When configuring aclk,
///     ACLK0 is not available for use with PWM--only ACLK1.
///
/// (!) Note that each PWM<#> channel corresponds to a specific GPIO pin,
///     and said pin must be configured for output before PWM may use it.
///     Please reference the Kit Guide or HW User Manual for your device
///     for more information on which
///     pins support PWM on your platform.
///
/// \verbatim
/// wiced_hal_aclk_enable(PWM_INP_CLK_IN_HZ, ACLK1, ACLK_FREQ_24_MHZ);
/// wiced_hal_pwm_get_params(PWM_INP_CLK_IN_HZ, PWM_DUTY_CYCLE, PWM_FREQ_IN_HZ, &pwm_config);
/// wiced_hal_pwm_start(PWM_CHANNEL, PMU_CLK, pwm_config.toggle_count, pwm_config.init_count, 0);
/// \endverbatim
///
///////////////////////////////////////////////////////////////////////////////
BOOL32 wiced_hal_pwm_start(UINT8        channel,
                                         pwm_clk_t clk,
                                         UINT32       toggleCount,
                                         UINT32       initCount,
                                         BOOL32       invert);

///////////////////////////////////////////////////////////////////////////////
/// Changes the PWM settings after the PWM HW has already been started.
///
/// (!) Note that the maximum width or period of the PWM is 0x3FF (10-bits).
///
/// \param channel     - Desired PWM channel to set [0-3].
/// \param toggleCount - The number of ticks to wait before toggling the signal.
/// \param initCount   - Initial value for the counter.
///
/// \return 1 if PWM was successfully changed, 0 otherwise.
///////////////////////////////////////////////////////////////////////////////
BOOL32 wiced_hal_pwm_change_values(UINT8 channel,
                                                 UINT32 toggleCount,
                                                 UINT32 initCount);

///////////////////////////////////////////////////////////////////////////////
/// Returns the current toggle count setting for the corresponding PWM channel.
///
/// \param channel - Desired PWM channel from which to obtain the toggle count.
///
/// \return The value at which the PWM is going to toggle.
///////////////////////////////////////////////////////////////////////////////
UINT32 wiced_hal_pwm_get_toggle_count(UINT8 channel);


///////////////////////////////////////////////////////////////////////////////
/// Returns the current initial count setting for the corresponding PWM channel.
///
/// \param channel - Desired PWM channel from which to obtain the initial count.
///
/// \return The initial count value of the PWM.
///////////////////////////////////////////////////////////////////////////////
UINT32 wiced_hal_pwm_get_init_value(UINT8 channel);

///////////////////////////////////////////////////////////////////////////////
/// Disables the PWM channel.
///
/// \param channel - Desired PWM channel to stop/disable.
///
/// \return VOID
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_pwm_disable(UINT8 channel);

///////////////////////////////////////////////////////////////////////////////
/// Enables the PWM channel which is already preconfigured.
///
/// \param channel - Desired PWM channel to enable.
///
/// \return VOID
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_pwm_enable(UINT8 channel);


///////////////////////////////////////////////////////////////////////////////
/// Calculate PWM parameters
///
/// \param[in]   clock_frequency_in  - in clock frequency
/// \param[in]   duty_cycle          - duty cycle in percentage (0 to 100)
/// \param[in]   pwm_frequency_out   - Desire PWM output frequency
/// \param[out]  params_out          - PWM params
///
/// \return VOID
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_pwm_get_params( UINT32 clock_frequency_in, UINT32 duty_cycle, UINT32 pwm_frequency_out, pwm_config_t * params_out);

/** \} group_pwm_functions */
/* @} */

#endif // __WICED_PWM_H__
