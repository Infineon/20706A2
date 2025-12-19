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
 */

#ifndef _WICED_SLEEP_H_
#define _WICED_SLEEP_H_

/**
 * @addtogroup wiced_sleep_config       AIROC Sleep Configuration
 * @ingroup HardwareDrivers
 *
 *  Defines functions for using the AIROC Sleep Framework
 * @{
 */

#define WICED_SLEEP_MAX_TIME_TO_SLEEP   ~0

/** Wake sources.*/
#define WICED_SLEEP_WAKE_SOURCE_KEYSCAN  (1<<0)  /**< Enable wake from keyscan */
#define WICED_SLEEP_WAKE_SOURCE_QUAD     (1<<1)  /**< Enable wake from quadrature sensor */
#define WICED_SLEEP_WAKE_SOURCE_GPIO     (1<<2)  /**< Enable wake from GPIO */
#define WICED_SLEEP_WAKE_SOURCE_MASK     (WICED_SLEEP_WAKE_SOURCE_GPIO | \
                                         WICED_SLEEP_WAKE_SOURCE_KEYSCAN | \
                                         WICED_SLEEP_WAKE_SOURCE_QUAD) /**< All wake sources */

/** Boot mode */
typedef enum
{
    WICED_SLEEP_COLD_BOOT, /**< Cold boot */
    WICED_SLEEP_FAST_BOOT  /**< Fast boot */
}wiced_sleep_boot_type_t;

/** Sleep modes */
typedef enum
{
    WICED_SLEEP_MODE_NO_TRANSPORT, /**< Used for HID use cases. When a transport is connected, sleep is always disallowed*/
    WICED_SLEEP_MODE_TRANSPORT     /**< This mode allows sleep when transport is connected and uses device wake line to wake up*/
}wiced_sleep_mode_type_t;

/** Active interrupt level for Wake through GPIO*/
typedef enum
{
    WICED_SLEEP_WAKE_ACTIVE_LOW, /**< Active low interrupt wakes the chip */
    WICED_SLEEP_WAKE_ACTIVE_HIGH /**< Active high interrupt wakes the chip*/
}wiced_sleep_wake_type_t;

/** Sleep poll type */
typedef enum
{
    WICED_SLEEP_POLL_TIME_TO_SLEEP,      /**< Polling for maximum allowed sleep duration */
    WICED_SLEEP_POLL_SLEEP_PERMISSION    /**< Polling for permission to sleep */
} wiced_sleep_poll_type_t;

/** Sleep permission
*    Note: SHUTDOWN mode sleep puts the chip in the lowest power saving sleep mode. This turns off most
*    hardware including parts of SRAM. Hence, if the application requires to preserve some context data for it
*    to resume normal operation after wake up, app should store this context data in Always On Memory (the part that is not turned off).
*    This is done by declaring the context variable with the attribute  __attribute__ ((section(".data_in_retention_ram"))).
*    The memory in AON available is limited, the maximum that application can use are 256 bytes.
*    When mode WICED_SLEEP_ALLOWED_WITH_SHUTDOWN is selected, the FW puts the chip in Shutdown sleep mode
*    if that is possible, else the chip will be put in a non-shutdown sleep mode.
*    To prevent FW from attempting to put the chip in Shutdown sleep mode, select WICED_SLEEP_ALLOWED_WITHOUT_SHUTDOWN.
*/
typedef enum
{
    WICED_SLEEP_NOT_ALLOWED,               /**< Sleep is not allowed */
    WICED_SLEEP_ALLOWED_WITHOUT_SHUTDOWN,  /**< Sleep is allowed, but shutdown mode sleep is not allowed */
    WICED_SLEEP_ALLOWED_WITH_SHUTDOWN      /**< Slepp allowed, including shutdown mode sleep */
}wiced_sleep_permission_type_t;

/**
 *
 *  Application implements call back of this type to allow or disallow the chip to go to sleep.
 *
 * @param[in]       type:  Poll type (see #wiced_sleep_poll_type_t)
 *
 * @return          if type == WICED_SLEEP_POLL_TIME_TO_SLEEP, application should return the maximum time allowed to sleep in micro seconds.
 *                     WICED_SLEEP_MAX_TIME_TO_SLEEP allows the Firmware to determine the duration it can sleep.
                       Note: When allowing SDS sleep, always return WICED_SLEEP_MAX_TIME_TO_SLEEP.
 *                  if type == WICED_SLEEP_POLL_SLEEP_PERMISSION, application should return one of the values in wiced_sleep_permission_type_t
 *
 * Note:- Application shall return immediately, with the return value specifying whether
 *        it allows/disallows sleep. Immediate return is required to allow the maximum
 *        time to sleep. Applications shall ensure that all peripheral activity (on PUART, SPI, .. )
 *        is paused before allowing sleep. Any pending activity on the peripherals
 *        is lost when the device goes into sleep.
 */
typedef uint32_t (*wiced_sleep_allow_check_callback ) (wiced_sleep_poll_type_t type );


/** Sleep configuration parameters */
typedef struct
{
    wiced_sleep_mode_type_t                  sleep_mode;             /**< Requested sleep mode */

    /* host_wake_mode, device_wake_mode and device_wake_gpio_num are applicable only
    in case of WICED_SLEEP_MODE_TRANSPORT. For WICED_SLEEP_MODE_NO_TRANSPORT
    use case, application should configure wake pin using
    wiced_hal_gpio_xxx APIS and/or wiced_hal_key_scan_xxx APIs and/or
    wiced_hal_quadrature_xxx depending on LHL, keyscan, qudrature hardware as
    wake source */
    wiced_sleep_wake_type_t                  host_wake_mode;         /**< Active level for host wake */
    wiced_sleep_wake_type_t                  device_wake_mode;       /**< Active level for device wake */
    uint8_t                                  device_wake_source;     /**< Device wake source(s). GPIO mandatory for
                                                                          WICED_SLEEP_MODE_TRANSPORT */
    uint32_t                                 device_wake_gpio_num;   /**< GPIO# for host to wake, mandatory for
                                                                          WICED_SLEEP_MODE_TRANSPORT */
    wiced_sleep_allow_check_callback         sleep_permit_handler;   /**< Call back to be called by sleep framework
                                                                          to poll for sleep permission */

}wiced_sleep_config_t;

/** API to configure sleep mode parameters.
 *
 * @param[in]       p_sleep_config: see @wiced_sleep_config_t
 *
 * @return          WICED_SUCCESS or WICED_ERROR
 */
wiced_result_t wiced_sleep_configure( wiced_sleep_config_t *p_sleep_config );

// not support for 20706A2
/** API to request reboot type.
 *
 * Returns Cold boot or Warm/Fast boot.
 *
 * @return          wiced_sleep_boot_type_t
 */
// wiced_sleep_boot_type_t wiced_sleep_get_boot_mode(void);

// not support for 20706A2
/**
* Function         wiced_hal_set_external_lpo_oscillator_bias
*
*                  Set external LPO oscillator bias. Default 0 = 50nA.
*
* @param[in]       bias       max allowed value is 3 (0=50nA, 1=100nA, 2=150nA, 3=200nA)
*
* @return
*                  WICED_SUCCESS if bias is set successfully, WICED_ERROR otherwise.
*/
// wiced_result_t wiced_hal_set_external_lpo_oscillator_bias(uint8_t bias);

/** @} */
#endif //_WICED_SLEEP_H_
