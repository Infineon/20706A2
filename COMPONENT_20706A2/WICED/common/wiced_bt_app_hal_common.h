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
 *WICED BT App HAL Common Utilities
 */
#ifndef _WICED_BT_APP_HAL_COMMON_H_
#define _WICED_BT_APP_HAL_COMMON_H_

#include "bt_types.h"
#include "wiced_platform.h"

/******************************************************************************
 *                                                          Constants
 ******************************************************************************/

/* Todo Update the PWM start GPIO number */
#define PWM_START_GPIO      0

/* GPIO flag bit (this is different than definition that used in gpio driver source code (GPIO_INPUT_ENABLE, etc) */
#define GPIO_INPUT          0x0000
#define GPIO_OUTPUT         0x0001

/******************************************************************************
 *                                                        Type Definitions
 ******************************************************************************/

/******************************************************************************
 *                                                          Function Prototypes
 ******************************************************************************/

/**  Wiced BT App Common HAL Initialization
 *
 * @return   None
 */
void wiced_bt_app_hal_init ( void );

/**  Wiced BT App Common LED Initialization
 *
 *  Required if app wants to use wiced_bt_app_hal_led_blink()
 * @return   None
 */
void wiced_bt_app_led_init ( void );

/**  Blinks the LED
 *
 *@param[in]    led_index             : index of LED to be used for blinking
 *
 *@param[in]    on_ms             : LED on duration in milli seconds
 *
  *@param[in]    off_ms             : LED off duration in milliseconds
 *
  *@param[in]    num_of_blinks             : LED number of blinks
 *
 * @return   None
 */
void wiced_bt_app_hal_led_blink(wiced_platform_led_t led_index, UINT16 on_ms, UINT16 off_ms, UINT8 num_of_blinks );

/**  Turns the LED On
 *
 * @return   None
 */
void wiced_bt_app_hal_led_on( wiced_platform_led_t led_index );

/**  Turns the LED Off
 *
 * @return   None
 */
void wiced_bt_app_hal_led_off( wiced_platform_led_t led_index );


#endif //_WICED_BT_APP_HAL_COMMON_H_
