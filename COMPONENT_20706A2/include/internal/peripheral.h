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
