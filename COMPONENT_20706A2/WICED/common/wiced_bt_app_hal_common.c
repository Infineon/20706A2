/*
 * Copyright 2016-2021, Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
 *
 * This software, including source code, documentation and related
 * materials ("Software") is owned by Cypress Semiconductor Corporation
 * or one of its affiliates ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products.  Any reproduction, modification, translation,
 * compilation, or representation of this Software except as specified
 * above is prohibited without the express written permission of Cypress.
 *
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 * reserves the right to make changes to the Software without notice. Cypress
 * does not assume any liability arising out of the application or use of the
 * Software or any product or circuit described in the Software. Cypress does
 * not authorize its products for use in any products where a malfunction or
 * failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product"). By
 * including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing
 * so agrees to indemnify Cypress against all liability.
 */

 /** @file
 *
 *  WICED BT App HAL Common Utilities
 *
 * This file provides definitions of the  HAL interfaces for WICED
 * Application development.
 *
 */
#include "bt_types.h"
#include "wiced_hal_mia.h"
#include "wiced_bt_dev.h"
#include "wiced_bt_trace.h"
#include "wiced_bt_app_hal_common.h"

#include "wiced_timer.h"
#include "sparcommon.h"
#include "wiced_swd_interface.h"
#include "wiced_hal_gpio.h"

/*****************************************************************************
 *                                              External Function Declarations
 ****************************************************************************/

/*****************************************************************************
 *                                              Internal Function Declarations
 ****************************************************************************/

/* LED Timer callback, to handle the LED blinks */
void wiced_bt_app_hal_led_timer_cb( uint32_t param );

/*****************************************************************************
 *                                              Variable Definitions
 ****************************************************************************/
extern wiced_led_config_t platform_led[];

/* wiced bt app led timer, to handle the LED blinks */
wiced_timer_t led_timer;

/* To hold the LED on duration in milliseconds */
static uint16_t wiced_bt_app_hal_led_on_ms = 0;

/* To hold the LED off duration in milliseconds */
static uint16_t wiced_bt_app_hal_led_off_ms = 0;

/* To hold the LED blink count */
static uint8_t  wiced_bt_app_hal_led_blink_count = 0;

/* LED index used for blinking */
static uint32_t wiced_bt_app_hal_led_index = 0xFF;

/*****************************************************************************
 *                                                   Function Definitions
 ****************************************************************************/

/**
 *Wiced BT App Common HAL Initialization
 */
void wiced_bt_app_hal_init ( void )
{
    mia_init();
    gpio_init();
    mia_enableMiaInterrupt(TRUE);
    mia_enableLhlInterrupt(TRUE);

    SETUP_APP_FOR_DEBUG_IF_DEBUG_ENABLED();
    BUSY_WAIT_TILL_MANUAL_CONTINUE_IF_DEBUG_ENABLED();
}

/**
 *Wiced BT App Common LED Initialization
 */
void wiced_bt_app_led_init ( void )
{
    wiced_init_timer( &led_timer, wiced_bt_app_hal_led_timer_cb, 0, WICED_MILLI_SECONDS_TIMER );

    platform_led_init();
}


/**
 * Blinks the LED
 */
void wiced_bt_app_hal_led_blink(wiced_platform_led_t led_index, uint16_t on_ms, uint16_t off_ms, uint8_t num_of_blinks )
{
	wiced_bt_app_hal_led_index = led_index;

    if ( num_of_blinks )
    {
        wiced_bt_app_hal_led_on_ms = on_ms;
        wiced_bt_app_hal_led_off_ms = off_ms;
        wiced_bt_app_hal_led_blink_count = num_of_blinks;

        wiced_bt_app_hal_led_on(led_index);
        wiced_stop_timer(&led_timer);
        wiced_start_timer(&led_timer,on_ms);
    }
}

/**
 * Turns the LED On
 */
void wiced_bt_app_hal_led_on( wiced_platform_led_t led_index )
{
    /* by default LED's are configured to be off
     * hence the default state should indicate the type of the LED */
    if(platform_led[led_index].led_default_state)
    {
        wiced_hal_gpio_set_pin_output(platform_led[led_index].led_gpio, GPIO_PIN_OUTPUT_LOW);
    }
    else
    {
        wiced_hal_gpio_set_pin_output(platform_led[led_index].led_gpio, GPIO_PIN_OUTPUT_HIGH);
    }
}

/**
 * Turns the LED Off
 */
void wiced_bt_app_hal_led_off( wiced_platform_led_t led_index )
{
    /* by default LED's are configured to be off
     * hence the default state should indicate the type of the LED */
    if( platform_led[led_index].led_default_state )
    {
        wiced_hal_gpio_set_pin_output(platform_led[led_index].led_gpio, GPIO_PIN_OUTPUT_HIGH);
    }
    else
    {
        wiced_hal_gpio_set_pin_output(platform_led[led_index].led_gpio, GPIO_PIN_OUTPUT_LOW);
    }
}

/**
 * LED timer callback handler, to handle the LED blinks
 */
void wiced_bt_app_hal_led_timer_cb( uint32_t param )
{
    static uint8_t led_on = 1;

    if(wiced_bt_app_hal_led_index == 0xFF)
    {
        return;
    }

    if ( led_on )
    {
        wiced_bt_app_hal_led_off(wiced_bt_app_hal_led_index);
        if ( --wiced_bt_app_hal_led_blink_count )
        {
            led_on = 0;
            wiced_start_timer( &led_timer, wiced_bt_app_hal_led_off_ms );
        }
        else
        {
		wiced_bt_app_hal_led_index = 0xFF;
        }
    }
    else
    {
        led_on = 1;
        wiced_bt_app_hal_led_on(wiced_bt_app_hal_led_index);
        wiced_start_timer( &led_timer, wiced_bt_app_hal_led_on_ms );
    }
}
