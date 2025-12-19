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
* watchdog.
*
*/

#ifndef __WICED_WDOG_RESET_H__
#define __WICED_WDOG_RESET_H__

#include "types.h"

/**  \addtogroup WatchdogInterface Watchdog Interface
* \ingroup HardwareDrivers
* Defines a driver for the watchdog interface. This driver manages the
* hardware watchdog countdown timer. When enabled, the watchdog timer will generate
* an interrupt when the timer counts down to zero, then will reload the counter.
* If the counter counts down to zero again, the hardware performs a device reset.
* The lowest priority "idle" thread restarts the watchdog counter preiodically,
* and other operations that may keep the system busy call wiced_hal_wdog_restart to
* extend the watchdog countdown.
*/
/*! @{ */

/******************************************************************************
*** Function prototypes.
******************************************************************************/

///////////////////////////////////////////////////////////////////////////////
/// Disable the system watchdog. Useful for debugging when the watchdog would
/// interfere and reset the system when not desired (e.g. when the system
/// is connected to a debugger, etc).
///
/// NOTE: This is for debugging purposes only. Hence, there is no complementary
/// "Enable Watchdog" function. Please do *not* use this function in production
/// applications.
///
/// \param none
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_wdog_disable(void);

///////////////////////////////////////////////////////////////////////////////
/// Execute a soft reset of the system.
///
/// \param none
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_wdog_reset_system(void);

///////////////////////////////////////////////////////////////////////////////
/// Restart the watchdog (restart the watchdog's internal timer). Used to
/// manually "pet" the watchdog when certain processes might otherwise cause
/// the watchdog to trigger and reset the system.
/// The default timeout for watchdog reset is two seconds.
///
/// \param none
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_wdog_restart(void);

/**@}*/

#endif // __WICED_WDOG_RESET_H__
