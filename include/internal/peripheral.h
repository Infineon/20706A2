/*
********************************************************************
* THIS INFORMATION IS PROPRIETARY TO
* Cypress Semiconductor.
*-------------------------------------------------------------------
*
*           Copyright (c) 2013 Cypress Semiconductor.
*                      ALL RIGHTS RESERVED
*
********************************************************************

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
