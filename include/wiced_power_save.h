/*
 * Copyright 2020, Cypress Semiconductor Corporation or a subsidiary of
 * Cypress Semiconductor Corporation. All Rights Reserved.
 *
 * This software, including source code, documentation and related
 * materials ("Software"), is owned by Cypress Semiconductor Corporation
 * or one of its subsidiaries ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products. Any reproduction, modification, translation,
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
* Wiced Low Power Mode Utilities
*
*/
#ifndef _WICED_POWER_SAVE_H_
#define _WICED_POWER_SAVE_H_

/*****************************************************************************
 *              Macros
 *****************************************************************************/

/** PTU clock enable bit masks.*/
typedef enum
{
    TPORT_CLK_ENABLE_BIT        =( 1 << 0 ),
    TPORT_AUX_CLK_ENABLE_BIT    =( 1 << 1 ),
    FM_FORCE_ON_BIT             =( 1 << 2 ),
    FM_KEEP_ON_BIT              =( 1 << 3 ),
    GATE_ON_SDIO_CLK_BIT        =( 1 << 4 ),
    GATE_ON_DBG_UART_CLK_BIT    =( 1 << 5 ),
    PCM_CLK_EN_BIT              =( 1 << 6 ),
    GATE_UART_CLK_EN_BIT        =( 1 << 10 ),
    GATE_UART_CLK_WAKE_BIT      =( 1 << 11 ),
    GATE_ON_SDIO_HOST_CLK_BIT   =( 1 << 16 )
}wiced_ptu_clock_bits_t;

/** PTU aux clock enable bit masks.*/
typedef enum
{
    PCM_DEV_CLK_EN_BIT          =( 1 << 1 ),
    ABURST_CLK_EN_BIT           =( 1 << 2 ),
    SPIFFY2_TPORT_CLK_EN_BIT    =( 1 << 3 ),
    SPIFFY2_HCLK_CLK_EN_BIT     =( 1 << 4 ),
    UART2_CLK_EN_BIT            =( 1 << 5 )
}wiced_ptu_aux_clock_bits_t;

/*****************************************************************************
 *              Type Definitions
 *****************************************************************************/
/** Wake Up Sources .Used when calling wiced_start_power_save.*/
typedef enum
{
    WICED_WAKE_SOURCE_GPIO = 0x01, /**<  Wake from GPIO */
    WICED_WAKE_SOURCE_TIMEOUT = 0x02, /**<  Wake on timeout, Value of 0 means infinite timeout */
    WICED_WAKE_SOURCE_ALL = WICED_WAKE_SOURCE_GPIO|WICED_WAKE_SOURCE_TIMEOUT
}wiced_wake_source_t;

typedef enum
{
    WICED_WAKE_GPIO_ACTIVE_LOW  = 0x00, /**<  Wake with GPIO set to low  */
    WICED_WAKE_GPIO_ACTIVE_HIGH = 0x01  /**<  Wake with GPIO set to high */
}wiced_wake_gpio_mode_t;

typedef struct
{
    unsigned long (*is_sleep_allowed)(void);
    unsigned long (*get_time_to_sleep)(void);
    void (*pre_sleep_processing)(void);
    void (*post_sleep_processing)(void);
    void (*isr_callback)(void);
}wiced_pmu_callbacks_t;


/*to handle callback for bt_wake toggling */
typedef void (wiced_bt_wake_app_cb_t)(void *data);

/**
 * Power Save callback
 *
 * Callback to the application on entering to power save mode or if entering to the power save
 * mode is aborted
 * Registered using wiced_power_save_register_enter_cback() and
 * wiced_power_save_register_abort_cback()
 *
 * @return void
 */
typedef void wiced_power_save_cback_t( void );

/**
 * Power Save approve callback
 *
 * Callback to the application to check if the application approves the device to go to power save
 *mode
 * Registered using wiced_power_save_register_approve_cback().
 *
 * @return  time to sleep - if the application decides to go to power save mode then it returns amount of time to sleep,
 *                          it may return zero to not to go to power save mode.
 */
typedef uint32_t wiced_power_save_approve_cback_t ( void );

/*****************************************************************************
 *          Function Prototypes
 *****************************************************************************/

/**
 * Function         wiced_power_save_start
 *
 * To start the power save mode of operation. This is the most efficient power save option available.
 * Be cautious on using this power save mode. Application will be restarted on exiting out of the
 * power save mode. If the application desires to save any state before going to power save it
 * can do so by using wiced_power_save_store_state() and retrieve the state on coming back
 * from power save by using wiced_power_save_retrieve_state().  The power save mode request can
 * be cancelled with a call to wiced_power_save_stop().
 *
 * @param[in]      wake_source       : Bit mask of sources to wake the device from power save
 *                                     mode
 *
 * @param[in]      timeout_ms        : Timeout in milliseconds  to wake the device from power
 *                                     save mode. Used  when WICED_WAKE_SOURCE_TIMEOUT
 *                                     or WICED_WAKE_SOURCE_ALL is specified as wake source
 *
 *
 * @return          void
 *
 */
void wiced_power_save_start( wiced_wake_source_t wake_source,
                                   uint32_t timeout_ms );

/**
 * Function         wiced_power_save_stop
 *
 * Stops a previous request to enter the power save mode of operation started by
 * wiced_power_save_start().   Can be called any time after that call up until execution of the
 * callback registered with wiced_power_register_enter_cback().
 *
 * @return          void
 *
 */
void wiced_power_save_stop( void );

/**
 * Function         wiced_power_save_register_approve_cback
 *
 * Registers the callback function which will be invoked to check if the application approves
 * the device to go to power save mode.  If application disallows, power save mode will continue
 * to be attempted by the device with further invocations.  Use wiced_power_save_stop to stop
 * the device from further retries.
 *
 * @param[in]      p_cback        : Callback function which will be invoked to check if the
 *                                  application approves the device to go to power save mode
 *                                  Application returns non-zero from the callback to approve,
 *                                  or zero to disallow.
 *
 * @return          void
 *
 */
void wiced_power_save_register_approve_cback(
                                   wiced_power_save_approve_cback_t* p_cback );

/**
 * Function         wiced_power_save_register_enter_cback
 *
 * Registers the callback function which will be invoked just before device enters the
 * power save mode.  Power save mode cannot be stopped at this point.
 *
 * @param[in]      p_cback        : callback function which will be invoked just before device
 *                                  enters the power save mode
 *
 * @return         void
 *
 */

void wiced_power_save_register_enter_cback(
                                  wiced_power_save_cback_t* p_cback );

/**
 * Function         wiced_power_save_register_abort_cback
 *
 * Registers the callback function which will be invoked if transition to the power save mode
 * is aborted.  Power save mode can be re-requested with a new call to wiced_power_save_start().
 *
 * @param[in]      p_cback        : callback function which will be invoked if transition to the
 *                                  power save mode is aborted
 *
 * @return         void
 *
 */
void wiced_power_save_register_abort_cback(
                                  wiced_power_save_cback_t* p_cback );

/**
 * Function         wiced_power_save_store_state
 *
 * Application can invoke this function to store any state values before going to power save
 * mode.  Should be called on receipt of the callback registered with
 * wiced_power_save_register_enter_cback().
 *
 * @param[in]      value        : Value to be saved.
 *
 * @return         void
 *
 */
void wiced_power_save_store_state( uint16_t value );

/**
 * Function         wiced_power_save_retrieve_state
 *
 * Application can invoke this function to retrieve any saved state values on waking from power
 * save mode
 *
 * @return         the saved value
 *
 */
uint16_t wiced_power_save_retrieve_state( void );

/**
 * Function         wiced_sleep_config
 *
 * Application can invoke this function to enable/disable low power mode of operation.
 * In this mode, the device achieves power savings by suspending the application and
 * allowing the device to sleep btween BLE advertising intervals.  Enabling sleep mode
 * with this API does not immediately put the device in low power mode, it simply
 * enables the device to transition to low power when idle.  The application is
 * suspended and resumed transparently by the device when it enters and exits sleep.
 * Device wakeup can be triggered by any ativity on an active peripheral, GPIO, the
 * BT radio, or an interrupt from a timer started by the application.
 *
 * The bt_wake and host_wake parameters are not needed for embedded SoC applications,
 * and should be set to NULL.  They are only used in external MCU scenaraios where
 * BT_DEV_WAKE and BT_HOST_WAKE GPIOs are used by external MCU and device to wake
 * each other.
 *
 * @param[in]      enable        : Enable or disable the sleep mode
 *
 * @param[in]      bt_wake       : not used, should be NULL
 *
 * @param[in]      host_wake     : not used, should be NULL
 *
 * @return         void
 *
 */
void wiced_sleep_config ( wiced_bool_t enable, wiced_wake_gpio_mode_t bt_wake, wiced_wake_gpio_mode_t host_wake );

/**
 * Function        wiced_ptu_clock_enable
 *
 * Application can invoke this function to enable ptu clocks required for the application.
 *
 * @param[in]      ptu_clock_bits : Bit mask of clocks which need to be enabled as described in wiced_ptu_clock_bits_t
 *
 * @param[in]      wiced_ptu_aux_clock_bits_t : List of clocks which need to be enabled as described in wiced_ptu_aux_clock_bits_t
 *
 * @return         void
 *
 */

void wiced_ptu_clock_enable(wiced_ptu_clock_bits_t ptu_clock_bits, wiced_ptu_aux_clock_bits_t ptu_aux_clock_bits );

/**
 * Function        wiced_ptu_clock_disable
 *
 * Application can invoke this function to disable ptu clocks required for the application.
 *
 * @param[in]      ptu_clock_bits : Bit mask of clocks which need to be disabled as described in wiced_ptu_clock_bits_t
 *
 * @param[in]      wiced_ptu_aux_clock_bits_t : List of clocks which need to be disabled as described in wiced_ptu_aux_clock_bits_t
 *
 * @return         void
 *
 */
void wiced_ptu_clock_disable(wiced_ptu_clock_bits_t ptu_clock_bits, wiced_ptu_aux_clock_bits_t ptu_aux_clock_bits );



/**
 * Function        wiced_bt_register_pmu_callbacks
 *
 * Application can invoke this function to register callbacks to follow the pmu state
 *
 * @param[in]      pmu_functions : Application registered pmu functions.
 *
 * @return         void
 *
 */
void wiced_bt_register_pmu_callbacks( wiced_pmu_callbacks_t * pmu_cb );

/**
 * Function        wiced_bt_coex_enable
 *
 * Application can invoke this function to enable the coex functionality
 *
 * @return         void
 *
 */
void wiced_bt_coex_enable( void );

/**
 * Function        wiced_bt_coex_disable
 *
 * Application can invoke this function to disable the coex functionality
 *
 * @return         void
 *
 */
void wiced_bt_coex_disable( void );

/**
 * Function        wiced_allow_sleep
 *
 * Application can invoke this function to allow/disallow sleep for debugging purpose
 *
 * @param[in]      allow : Allow or Disallow sleep.
 *                     TRUE  - allow sleep
 *                     FALSE - disallow sleep
 *
 * @return         void
 *
 * */
void wiced_allow_sleep( wiced_bool_t allow );

#endif // _WICED_POWER_SAVE_H_
