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
* List of parameters and defined functions needed to access the
* General Purpose Input/Ouput (GPIO) driver.
*
*/

#ifndef __WICED_GPIO_H__
#define __WICED_GPIO_H__

#include "gpiodriver.h"

#define wiced_hal_gpio_register_pin_for_interrupt wiced_hal_gpio_register_pin_for_interrupt_patch
/**  \addtogroup GPIODriver GPIO
* \ingroup HardwareDrivers
* @{
* Defines a driver to facilitate interfacing with the GPIO pins.
*
* Use this driver to control the behavior of any desired pin, such as
* driving a 1 or a 0, or as part of other drivers such as controlling
* the chip-select (CS) line for the SPI driver.
*
*

******************************************************************************
*** Parameters.
***
*** The following parameters are used to configure the driver or define
*** return status. They are not modifiable.
******************************************************************************

// GPIO port and pin number constraints expressed in values.
@verbatim
{
    // Number of ports in the system.
    GPIO_NUM_PORTS,

    // Max number of pins per port.
    GPIO_MAX_NUM_PINS_PER_PORT,

    // Number of pins in the system.
    GPIO_NUM_PINS,
 };
@endverbatim

// Pin output config
@verbatim
typedef enum
{
    GPIO_PIN_OUTPUT_LOW,
    GPIO_PIN_OUTPUT_HIGH,
} tGPIO_PIN_OUTPUT_CONFIG;
@endverbatim

// The following enum defines the constant values for the GPIO driver and
// associated GPIOs, each of which has a set of configuration signals.
//
// The first twelve entries are the configuration masks for GPIO.
// A combination of them might be used together; for example a value
// INPUT_DISABLE_MASK|OUTPUT_ENABLE_MASK can be used to set a pin.
// Each pin can be configured in a specific way (using one or a combination
// of values).
@verbatim
enum
{
    // Trigger Type
    // GPIO configuration bit 0, Interrupt type defines
    GPIO_EDGE_TRIGGER_MASK       = 0x0001,
    GPIO_EDGE_TRIGGER            = 0x0001,
    GPIO_LEVEL_TRIGGER           = 0x0000,

    // Negative Edge Triggering
    // GPIO configuration bit 1, Interrupt polarity defines
    GPIO_TRIGGER_POLARITY_MASK   = 0x0002,
    GPIO_TRIGGER_NEG             = 0x0002,

    // Dual Edge Triggering
    // GPIO configuration bit 2, single/dual edge defines
    GPIO_DUAL_EDGE_TRIGGER_MASK  = 0x0004,
    GPIO_EDGE_TRIGGER_BOTH       = 0x0004,
    GPIO_EDGE_TRIGGER_SINGLE     = 0x0000,

    // Interrupt Enable
    // GPIO configuration bit 3, interrupt enable/disable defines
    GPIO_INTERRUPT_ENABLE_MASK   = 0x0008,
    GPIO_INTERRUPT_ENABLE        = 0x0008,
    GPIO_INTERRUPT_DISABLE       = 0x0000,

    // Interrupt Config
    // GPIO configuration bit 0:3, Summary of Interrupt enabling type
    GPIO_EN_INT_MASK             = GPIO_EDGE_TRIGGER_MASK | GPIO_TRIGGER_POLARITY_MASK | GPIO_DUAL_EDGE_TRIGGER_MASK | GPIO_INTERRUPT_ENABLE_MASK,
    GPIO_EN_INT_LEVEL_HIGH       = GPIO_INTERRUPT_ENABLE | GPIO_LEVEL_TRIGGER,
    GPIO_EN_INT_LEVEL_LOW        = GPIO_INTERRUPT_ENABLE | GPIO_LEVEL_TRIGGER | GPIO_TRIGGER_NEG,
    GPIO_EN_INT_RISING_EDGE      = GPIO_INTERRUPT_ENABLE | GPIO_EDGE_TRIGGER,
    GPIO_EN_INT_FALLING_EDGE     = GPIO_INTERRUPT_ENABLE | GPIO_EDGE_TRIGGER | GPIO_TRIGGER_NEG,
    GPIO_EN_INT_BOTH_EDGE        = GPIO_INTERRUPT_ENABLE | GPIO_EDGE_TRIGGER | GPIO_EDGE_TRIGGER_BOTH,

    // GPIO Output Buffer Control and Output Value Multiplexing Control
    // GPIO configuration bit 4:5, and 14 output enable control and
    // muxing control
    GPIO_INPUT_ENABLE            = 0x0000,
    GPIO_OUTPUT_DISABLE          = 0x0000,
    GPIO_OUTPUT_ENABLE           = 0x4000,
    GPIO_KS_OUTPUT_ENABLE        = 0x0010, // Keyscan Output enable
    GPIO_OUTPUT_FN_SEL_MASK      = 0x0030,
    GPIO_OUTPUT_FN_SEL_SHIFT     = 4,

    // Global Input Disable
    // GPIO configuration bit 6, "Global_input_disable" Disable bit
    // This bit when set to "1" , P0 input_disable signal will control
    // ALL GPIOs. Default value (after power up or a reset event) is "0".
    GPIO_GLOBAL_INPUT_ENABLE     = 0x0000,
    GPIO_GLOBAL_INPUT_DISABLE    = 0x0040,

    // Pull-up/Pull-down
    // GPIO configuration bit 9 and bit 10, pull-up and pull-down enable
    // Default value is [0,0]--means no pull resistor.
    GPIO_PULL_UP_DOWN_NONE       = 0x0000,   //[0,0]
    GPIO_PULL_UP                 = 0x0400,   //[1,0]
    GPIO_PULL_DOWN               = 0x0200,   //[0,1]
    GPIO_INPUT_DISABLE           = 0x0600,   //[1,1] // input disables the GPIO

    // Drive Strength
    // GPIO configuration bit 11
    GPIO_DRIVE_SEL_MASK         = 0x0800,
    GPIO_DRIVE_SEL_LOWEST       = 0x0000,  // 2mA @ 1.8V
    GPIO_DRIVE_SEL_MIDDLE_0     = 0x0000,  // 4mA @ 3.3v
    GPIO_DRIVE_SEL_MIDDLE_1     = 0x0800,  // 4mA @ 1.8v
    GPIO_DRIVE_SEL_HIGHEST      = 0x0800,  // 8mA @ 3.3v

    // Input Hysteresis
    // GPIO configuration bit 13, hysteresis control
    GPIO_HYSTERESIS_MASK         = 0x2000,
    GPIO_HYSTERESIS_ON           = 0x2000,
    GPIO_HYSTERESIS_OFF          = 0x0000,
};
@endverbatim
**/


/** GPIO Numbers : first 8 are ARM GPIOs and following rest are LHL GPIOs */
typedef enum wiced_bt_gpio_numbers_e
{
    /* GPIO_P00 to GPIO_P39 are LHL GPIOs */
    WICED_P00 = 0,  /**< LHL GPIO 0 */
    WICED_P01,      /**< LHL GPIO 1 */
    WICED_P02,      /**< LHL GPIO 2 */
    WICED_P03,      /**< LHL GPIO 3 */
    WICED_P04,      /**< LHL GPIO 4 */
    WICED_P05,      /**< LHL GPIO 5 */
    WICED_P06,      /**< LHL GPIO 6 */
    WICED_P07,      /**< LHL GPIO 7 */
    WICED_P08,      /**< LHL GPIO 8 */
    WICED_P09,      /**< LHL GPIO 9 */
    WICED_P10,      /**< LHL GPIO 10 */
    WICED_P11,      /**< LHL GPIO 11 */
    WICED_P12,      /**< LHL GPIO 12 */
    WICED_P13,      /**< LHL GPIO 13 */
    WICED_P14,      /**< LHL GPIO 14 */
    WICED_P15,      /**< LHL GPIO 15 */
    WICED_P16,      /**< LHL GPIO 16 */
    WICED_P17,      /**< LHL GPIO 17 */
    WICED_P18,      /**< LHL GPIO 18 */
    WICED_P19,      /**< LHL GPIO 19 */
    WICED_P20,      /**< LHL GPIO 20 */
    WICED_P21,      /**< LHL GPIO 21 */
    WICED_P22,      /**< LHL GPIO 22 */
    WICED_P23,      /**< LHL GPIO 23 */
    WICED_P24,      /**< LHL GPIO 24 */
    WICED_P25,      /**< LHL GPIO 25 */
    WICED_P26,      /**< LHL GPIO 26 */
    WICED_P27,      /**< LHL GPIO 27 */
    WICED_P28,      /**< LHL GPIO 28 */
    WICED_P29,      /**< LHL GPIO 29 */
    WICED_P30,      /**< LHL GPIO 30 */
    WICED_P31,      /**< LHL GPIO 31 */
    WICED_P32,      /**< LHL GPIO 32 */
    WICED_P33,      /**< LHL GPIO 33 */
    WICED_P34,      /**< LHL GPIO 34 */
    WICED_P35,      /**< LHL GPIO 35 */
    WICED_P36,      /**< LHL GPIO 36 */
    WICED_P37,      /**< LHL GPIO 37 */
    WICED_P38,      /**< LHL GPIO 38 */
    WICED_P39,      /**< LHL GPIO 39 */
    /* GPIO_00 to GPIO_07 are ARM GPIOs */
    WICED_GPIO_00,  /**< ARM GPIO 0 - 40 */
    WICED_GPIO_01,  /**< ARM GPIO 1 - 41 */
    WICED_GPIO_02,  /**< ARM GPIO 2 - 42 */
    WICED_GPIO_03,  /**< ARM GPIO 3 - 43 */
    WICED_GPIO_04,  /**< ARM GPIO 4 - 44 */
    WICED_GPIO_05,  /**< ARM GPIO 5 - 45 */
    WICED_GPIO_06,  /**< ARM GPIO 6 - 46 */
    WICED_GPIO_07,  /**< ARM GPIO 7 - 47 */
    MAX_NUM_OF_GPIO
}wiced_bt_gpio_numbers_t;

// GPIO Active Levels HIGH / LOW
#define WICED_GPIO_ACTIVE_HIGH      1
#define WICED_GPIO_ACTIVE_LOW       0

/******************************************************************************
*** Function prototypes and defines.
******************************************************************************/

///////////////////////////////////////////////////////////////////////////////
/// Initializes the GPIO driver and its private values.
/// Also programs all GPIOs to be ready for use. This must be invoked before
/// accessing any GPIO driver services, typically at boot.
/// This is independent of other drivers and must be one of the first to
/// be initialized.
///
/// \param none
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
static INLINE void wiced_hal_gpio_init(void)
{
    gpio_init();
}

///////////////////////////////////////////////////////////////////////////////
/// Convert a given schematic pin number (i.e. P5) to the internal port/pin
/// representation used by various other drivers such as PSPI and PUART. There
/// could be up to 40 GPIO pins on a board so the numbering is P0 - P39.
///
/// \param pin - The desired pin number from the schematic. Ex: P<pin>
///
/// \return Returns the port and pin representation encoded into a byte.
/// Value is 0xFF if the input parameter is out of range.
///////////////////////////////////////////////////////////////////////////////
UINT8 wiced_hal_gpio_pin_to_port_pin(UINT8 pin);

///////////////////////////////////////////////////////////////////////////////
/// Configures a GPIO pin.
///
/// Note that the GPIO output value is programmed before
/// the GPIO is configured. This ensures that the GPIO will activate with the
/// correct external value. Also note that the output value is always
/// written to the output register regardless of whether the GPIO is configured
/// as input or output.
///
/// Enabling interrupts here isn't sufficient; you also want to
/// register with registerForMask().
///
/// All input parameter values must be in range or the function will
/// have no effect.
///
/// \param pin    - pin id (0-39).
/// \param config - Gpio configuration. See Parameters section above for
/// possible values and below for example.
/// \param outputVal - output value.
///
/// \return none
///
/// For example, to enable interrupts for all edges, with a pull-down,
/// you could set config parameter to:
/// \verbatim
/// GPIO_EDGE_TRIGGER | GPIO_EDGE_TRIGGER_BOTH |
/// GPIO_INTERRUPT_ENABLE_MASK | GPIO_PULL_DOWN_MASK
/// \endverbatim
///////////////////////////////////////////////////////////////////////////////
 void wiced_hal_gpio_configure_pin(BYTE pin,UINT16 config, BYTE outputVal);

///////////////////////////////////////////////////////////////////////////////
/// Retrieve the current configuration of the specified pin.
///
/// All input parameter values must be in range or the function will
/// have no effect.
///
/// \param pin  - pin id (0-39).
///
/// \return Configuration of specified pin.
///////////////////////////////////////////////////////////////////////////////
UINT16 wiced_hal_gpio_get_pin_config(BYTE pin);

///////////////////////////////////////////////////////////////////////////////
/// Sets the output value of a pin. Note that the pin must already be
/// configured as output or this will have no visible effect.
///
/// All input parameter values must be in range or the function will
/// have no effect.
///
/// \param pin  - pin id (0-39).
/// \param val  - the output value
///    -   0        - pin will be set to 0
///    -   non-zero - pin will be set to 1
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_gpio_set_pin_output(BYTE pin, BYTE val);

///////////////////////////////////////////////////////////////////////////////
/// Get the programmed output value of a pin. Note that this does not return
/// the current pin value. It returns the value that the pin would attempt to
/// drive if it is configured as output.
///
/// \param pin  - pin id (0-39).
///
/// \return Returns 1 if output port of the pin is configured 1, likewise
/// for 0. Returns 0xFF if the input parameters are out of range.
///////////////////////////////////////////////////////////////////////////////
BYTE wiced_hal_gpio_get_pin_output(BYTE pin);

///////////////////////////////////////////////////////////////////////////////
/// Read the current value at a pin. Note that for this to be valid, the pin
/// must be configured with input enabled.
///
/// \param pin  - pin id (0-39).
///
/// \return  Returns 1 if the pin is high, 0 if the pin is low, and 0xFF if
/// the input parameters are out of range.
///////////////////////////////////////////////////////////////////////////////
BYTE wiced_hal_gpio_get_pin_input_status(BYTE pin);

///////////////////////////////////////////////////////////////////////////////
/// Get the interrupt status of a pin
///
/// \param pin  - pin id (0-39).
///
/// \return  Returns 1 if an interrupt (programmed edge) was detected at the
/// pin, 0 if not. Returns 0xFF if the input parameters are out of range.
///////////////////////////////////////////////////////////////////////////////
BYTE wiced_hal_gpio_get_pin_interrupt_status(BYTE pin);

///////////////////////////////////////////////////////////////////////////////
/// Register a function for notification of changes to a pin (via interrupt).
///
/// \param masks - Points to an array of NUM_PORTS.
///
/// \param userfn - Points to the function to call when the interrupt
/// comes and matches one of the masks.
///
/// (!) Note that the function does not need to clear the interrupt
/// status; this will be done automatically.
///
/// (!) Note that the function will be called ONCE per interrupt, not once per
/// pin (this makes a difference if multiple pins toggle at the same time).
///
/// \param userdata - Will be passed back to userfn as-is. Typically NULL.
///
/// \return none
///
/// Note that this is independent of configuring the pin for
/// interrupts; a call to configurePin() is also required (this call should be
/// made before invoking this function)  .
///
/// Also note that once registered, you CANNOT UNREGISTER; registration is
/// meant to be a startup activity. To stop receiving notifications,
/// re-configure the pin and disable the interrupt using
/// configurePin().
///
/// Example:
///
/// \verbatim
/// void gpioIntTestCb(void *data);
///
/// UINT16 gpioIntMasks[GPIO_NUM_PORTS] = {0};
/// wiced_hal_gpio_configurePin(27,
///     (GPIO_INPUT_ENABLE|GPIO_PULL_DOWN|GPIO_EN_INT_RISING_EDGE),
///      GPIO_PIN_OUTPUT_LOW);
/// gpioIntMasks[pin2port(27)] |= (1<<pin2pin(27));
/// wiced_hal_gpio_registerPinForInterrupt(gpioIntMasks, gpioIntTestCb, NULL);
/// wiced_hal_gpio_clearPinInterruptStatus(27);
/// \endverbatim
///
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_gpio_register_pin_for_interrupt(UINT16 pin,
                                   void (*userfn)(void*, UINT8), void* userdata);


///////////////////////////////////////////////////////////////////////////////
/// Clear the interrupt status of a pin manually.
///
/// \param pin  - pin id (0-39).
///
/// \return  Returns 1 if successful, 0xFF if the input parameters are
/// out of range.
///////////////////////////////////////////////////////////////////////////////
BYTE wiced_hal_gpio_clear_pin_interrupt_status(BYTE pin);

///////////////////////////////////////////////////////////////////////////////
/// Configures all gpios to be INPUT DISABLED.
///
/// \param none
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
static INLINE void wiced_hal_gpio_disable_all_inputs(void)
{
    gpio_inputDisableAll();
}

/* @} */

#endif // __WICED_GPIO_H__
