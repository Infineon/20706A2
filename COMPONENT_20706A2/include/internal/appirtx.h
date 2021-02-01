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
#ifndef __APPIR_TX_H__
#define __APPIR_TX_H__

#include "irtx_interface.h"
#include "irtxdriver.h"
#include "aclk.h"

//Example of using accurate HW timer 2 for IR Tx. However, you need to code carefully to
//1) avoid race condition/deadlock, and 2) no sleep/hidoff allowed when HW Timer2 is running.

#define APPIRTX_DATA_SIZE  128

class appIRtx : public IrTx_interface
{
    IS_SINGLETON;
public:
    enum{
        APPIRTX_IDLE = 0,
        APPIRTX_STARTED,
        APPIRTX_REPEAT,
        APPIRTX_END
    };

    static appIRtx *instance;
    static appIRtx* getInstance(UINT8 port=2, UINT8 pin=6); //by default P38 is IR tx

    virtual void SendIR(BYTE code, BOOL8 repeat, BYTE repeatcount);
    virtual BOOL8 isActive(void);
    virtual void stopRepeat(void);
    static void timer2_timeoutCallback(void *app);

    static UINT32 appir_cycle;
    static UINT16 appir_carrier_freq;
    static UINT16 appir_one;
    static UINT16 appir_zero;
    static UINT16 appir_separator;

protected:
    appIRtx(UINT8 port, UINT8 pin);
    ~appIRtx(void);
    static appIRtx* (*createInstance)(UINT8 port, UINT8 pin);
    static appIRtx* defaultCreateInstance(UINT8 port, UINT8 pin);

    virtual void init( void );
    virtual void writebyte(BYTE code);
    virtual void irTxTimerCallback(void);

#ifdef FIX_CQ_2958189
    virtual void irBtClockEnable(BOOL enable);
    UINT32 mia_clock_1M_restore;
#endif

protected:
    IR_TX_CLOCK_SETTING irTxClkSetting;
    UINT16   ir_data[APPIRTX_DATA_SIZE];
    int  irIndex;
    BYTE irTxStarted;
    BOOL8 repeatFlag;
    BYTE  repeatCount;



};

/* @} */
#endif
