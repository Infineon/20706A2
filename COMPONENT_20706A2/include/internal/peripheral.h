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
/*
********************************************************************
*    File Name: peripheral.h
*
*    Abstract: This file defines the abstract type of peripheral
*              for the application.
*
*    $History:$
*
********************************************************************
*/
#ifndef __PERIPHERAL_H__
#define __PERIPHERAL_H__

#include "startupallocated.h"
#include "gpiodriver.h"

// Macros to calculate the exact port and pin of a given pin.
#define GPIO_MAX_PINS_PER_PORT 16
#define GPIO_PORT(n) (n / GPIO_MAX_PINS_PER_PORT)
#define GPIO_PIN(n)  (n % GPIO_MAX_PINS_PER_PORT)

class Peripheral : public StartupAllocated
{
public:
    enum
    {
        LOW,
        HIGH,
        NO_INTERRUPT = 0xff,
    };

    enum
    {
        HID_NO_EVENT = 0,
        HID_EVENT_IRuC = 0xf0,
        HID_EVENT_AUDIO_DATA_AVAILABLE   = 0xf1,
        HID_EVENT_MOTION_DATA_AVAILABLE  = 0xf2,
        HID_EVENT_PUART_DATA_AVAILABLE   = 0xf3,
        BTUP_EVENT_PUART_DATA_AVAILABLE  = 0xf4,
        HID_EVENT_AUDIO_DATA_START       = 0xf7,
        HID_EVENT_SPI_DATA_AVAILABLE     = 0xf5,
    };

    Peripheral(void (*callBack)(void*) = NULL, void * parent = NULL,
               BYTE gpio = NO_INTERRUPT, BYTE activeLogic = LOW,
               BYTE config = GPIO_EN_INT_RISING_EDGE);

    virtual void interruptEnable(void);
    virtual void interruptDisable(void);
    virtual BYTE interruptPending();
    virtual void clearInterrupt(void);
    virtual void setEnable(bool en);
    virtual BYTE isEnabled(){return enabled;};
    virtual bool getIntPinState();
    virtual void gpioOut(BYTE gpio, BYTE value);

protected:
    virtual void interruptInit();

    void * parent;
    void (*appCallBack)(void *, UINT8);

    BYTE intrPort, intrPin, activeLogic, intLevelCfg;
    bool enabled;
};

#endif
