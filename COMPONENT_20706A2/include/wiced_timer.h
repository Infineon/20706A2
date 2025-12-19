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
 *  \addtogroup timer Timer Management Services
 *  \ingroup HardwareDrivers
 *
 *  @{
 *
 * Defines the interfaces for Timer Management Services
 */
#ifndef _WICED_TIMER_H_
#define _WICED_TIMER_H_


#include "wiced.h"

/*****************************************************************************
**                                                      Constants
*****************************************************************************/
/**
 * Defines the  wiced timer instance size
 */
 #define WICED_TIMER_INSTANCE_SIZE_IN_WORDS      12

/*****************************************************************************
**                                                     Enumerations
*****************************************************************************/

/*
 * Defines the wiced timer types. These timers are system tick driven and a
 * systick is 12.5 milliseconds.So the minimum timer resolution supported is
 * 12.5 milliseconds
 */
typedef enum
{
    WICED_SECONDS_TIMER = 1,
    WICED_MILLI_SECONDS_TIMER, /* The minimum resolution supported is 12.5 ms */
    WICED_SECONDS_PERIODIC_TIMER,
    WICED_MILLI_SECONDS_PERIODIC_TIMER /*The minimum resolution supported is 12.5 ms */
}wiced_timer_type_t;

/*****************************************************************************
**                                                  Type Definitions
*****************************************************************************/
/*
 * Function prototype for the timer callbacks. Timer callback runs in the
 * application context.
 */
typedef void ( *wiced_timer_callback_t )( uint32_t cb_params );

/*
 * Defines the wiced timer structure. Application has to define the timers that it
 * requires. Timer module doesn't use any dynamic memory and the number of timers
 * depends on the memory available to the application to define the timers
 */
typedef struct
{
    uint32_t reserved[WICED_TIMER_INSTANCE_SIZE_IN_WORDS];
}wiced_timer_t;

/*****************************************************************************
**                                                 Function Declarations
*****************************************************************************/

/**  Initializes the timer
 *
 * @param[in]    p_timer             :Pointer to the timer structure
 * @param[in]    p_cb                 :Timer callback function to be invoked on timer expiry
 * @param[in]    cb_param        :Parameter to be passed to the timer callback function which
 *                                              gets invoked on timer expiry,if any
 * @param[in]    timer_type         :Type of the timer
 *
 * @return   wiced_result_t
 */
wiced_result_t wiced_init_timer( wiced_timer_t* p_timer, wiced_timer_callback_t p_cb, uint32_t cb_param, wiced_timer_type_t timer_type );


/**  Starts the timer
 * Timer should be initialized before starting the timer. Running the timer interfere with the
 * low power modes of the chip. Time to remain in the low power mode is dependent on the
 * timeout values of the running timers, ie time to sleep is dependent on the time after which
 * the next timer among the active timers expires.
 *
 * @param[in]    p_timer             :Pointer to the timer structure
 * @param[in]    timeout              :Timeout value, in seconds or in milliseconds depending on the timer type
  *
 * @return   wiced_result_t
 */
wiced_result_t wiced_start_timer( wiced_timer_t* p_timer,uint32_t timeout );


/**  Stops the timer
 *
 * * @param[in]    p_timer             :Pointer to the timer structure
 *
 * @return   wiced_result_t
 */
wiced_result_t wiced_stop_timer( wiced_timer_t* p_timer );

/**  Checks if the timer is in use
*
* * @param[in]    p_timer             :Pointer to the timer structure
*
* @return   0 if the timer is not in use and non-zero value if the timer is in use
*/
BOOL wiced_is_timer_in_use(wiced_timer_t* p_timer);

/** Deinitialize the timer instance and stops the timer if it is running.
 *
 * * @param[in]    p_timer           :Pointer to the timer
 *
 * @return   None
 */
wiced_result_t wiced_deinit_timer(  wiced_timer_t* p_timer );

/* @} */

#endif //_WICED_TIMER_H_
