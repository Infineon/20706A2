/*
********************************************************************
* THIS INFORMATION IS PROPRIETARY TO
* Cypress Semiconductor.
*-------------------------------------------------------------------
*
*           Copyright (c) 2011 Cypress Semiconductor.
*                      ALL RIGHTS RESERVED
*
********************************************************************/
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
