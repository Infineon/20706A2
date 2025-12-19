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
