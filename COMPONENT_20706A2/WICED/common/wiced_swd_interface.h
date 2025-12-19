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

/*******************************************************************************
 * All common definitions for configuring SWD interface pins
 *******************************************************************************/

#ifndef _WICED_SWD_INTERFACE__H_
#define _WICED_SWD_INTERFACE__H_

 /* Enum of all the possible pins through which SWDCK can be routed. */
typedef enum
{
    SWDCK_DISABLED = -1,
    SWDCK_ON_UART_TXD,
    SWDCK_ON_SMUX,
    SWDCK_ON_P14,
    SWDCK_ON_P11,
    SWDCK_ON_P30
}SWDCK_pin_t;

/* Enum of all the possible pins through which SWDIO can be routed. */
typedef enum
{
    SWDIO_DISABLED = -1,
    SWDIO_ON_UART_RXD,
    SWDIO_ON_SMUX,
    SWDIO_ON_P15,
    SWDIO_ON_P12,
    SWDIO_ON_P31
}SWDIO_pin_t;

#define TCK_PIN_SEL_OFFSET              3       /* SWDCLK */
#define TMS_PIN_SEL_OFFSET              6       /* SWDIO */
#define TCK_PIN_SEL_MASK                (0x7 << TCK_PIN_SEL_OFFSET)
#define TMS_PIN_SEL_MASK                (0x7 << TMS_PIN_SEL_OFFSET)
#define TMS_TCK_PIN_SEL_MASK            (TMS_PIN_SEL_MASK | TCK_PIN_SEL_MASK)

/* Choose the pins for SWDIO and SWDCK */
void wiced_configure_swd_pins(SWDCK_pin_t swdck_pin, SWDIO_pin_t swdio_pin);

#endif  /* _WICED_SWD_INTERFACE__H_ */
