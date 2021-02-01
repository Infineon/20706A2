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
*    File Name: miadriver.h
*
*    Abstract: This file defines the high level driver functionality
*
*
********************************************************************
*/

#ifndef __MIA_DRIVER_H__
#define __MIA_DRIVER_H__

#include "types.h"
#include "quadraturedriver.h"


#ifdef __cplusplus
extern "C" {
#endif


extern BOOL8 shuttingDownOnLowBattery;
#ifdef BCM20703
extern BOOL8 serializeEventsToHidApp;
#endif

/**  \addtogroup mia
 *  \ingroup HardwareDrivers
*/
/*! @{ */
/**
* Defines a MIA driver class. The BCM keyboard application or other applications use this
* driver to obtain the status from and control the behavior of the MIA driver.
*/
/// Mia constants are defined below
enum
{
    // The following will need to be redefined depending on how HW muxes pin functions

    ///Mask for P2_6(GPIO_22). 00 in the mask will be normal P2_6 or GPIO_22.
    MIA_P2_OPSR_SEL_PORT_2_6_BIT_MASK    = 0xC0,
    /// This value in the above mask would set KSO14 output.
    MIA_P2_OPSR_SEL_PORT_2_6_IS_KSO14    = 0x40,
    /// Mask for P2_7(GPIO_23).  00 value in the mask would set normal GPIO_23.
    MIA_OPSR_SEL0_PORT_2_7_BIT_MASK      = 0x03,
    /// This value in the above mask would set KSO15 output.
    MIA_OPSR_SEL0_PORT_2_7_IS_KSO15      = 0x01,
    /// Mask for P3_0(GPIO_24).  00 value in the mask would set normal GPIO_24.
    MIA_OPSR_SEL0_PORT_3_0_BIT_MASK      = 0x0C,
    /// This value in the above mask would set KSO16 output.
    MIA_OPSR_SEL0_PORT_3_0_IS_KSO16      = 0x04,
    /// Mask for P3_1.  0 value in the mask would set normal GPIO_25.
    MIA_OPSR_SEL0_PORT_3_1_BIT_MASK      = 0x10,
    /// This value in the above mask would set KSO17 output.
    MIA_OPSR_SEL0_PORT_3_1_IS_KSO17      = 0x10,
    /// Mask for P3_2.  0 value in the mask would set normal GPIO_26.
    MIA_OPSR_SEL0_PORT_3_2_BIT_MASK      = 0x60,
    /// This value in the above mask would set KSO18 output.
    MIA_OPSR_SEL0_PORT_3_2_IS_KSO18      = 0x20,
    /// Mask for P3_3.  0 value in the mask would set normal GPIO_27.
    MIA_OPSR_SEL1_PORT_3_3_BIT_MASK      = 0x03,
    /// This value in the above mask would set KSO19 output.
    MIA_OPSR_SEL1_PORT_3_3_IS_KSO19      = 0x01,
};

/* @} */

/**  \addtogroup mia
 *  \ingroup HardwareDrivers
*/
/*! @{ */
/**
* Defines the BCM miadriver class. Mia driver class encapsulates the mia clock freeze
* and other functionalities for other mia drivers.
*/

enum
{
    HW_MIA_CTRL_CLK_FREEZE_MASK     = 0x0001,
    HW_MIA_CTRL_CLK_FREEZE_REQ      = 0x0001,
    HW_MIA_CTRL_CLK_UNFREEZE_REQ    = 0x0000,

    HW_MIA_STATUS_CLK_FROZEN_MASK   = 0x0001,
    HW_MIA_STATUS_CLK_FROZEN        = 0x0001,
    HW_MIA_STATUS_CLK_RUNNING       = 0x0000,
    HW_MIA_STATUS_KEYCODE_SET_MASK  = 0x0002,
    HW_MIA_STATUS_KEYCODE_SET       = 0x0002,
    //HW_MIA_STATUS_QUAD_SET_MASK     = 0x0010,
    HW_MIA_STATUS_QUAD_SET          = 0x0010,
    HW_MIA_STATUS_EVT_SET_MASK      = 0x0012,
    HW_MIA_STATUS_EVT_SET           = 0x0012,


    HW_LHL_CTL_HID_OFF_MASK         = 0x0001,
    HW_LHL_CTL_KS_EN_MASK           = 0x0002,
    HW_LHL_CTL_QD_EN_MASK           = 0x0004,
    HW_LHL_CTL_KSI_USED_MASK        = 0xE000,
    HW_LHL_CTL_HID_OFF              = 0x0001,
    HW_LHL_CTL_KS_EN                = 0x0002,
    HW_LHL_CTL_QD_EN                = 0x0004,
    HW_LHL_CTL_KSI_USED_SHIFT_COUNT = 13,

    HW_LHL_STATUS_HID_OFF_WAKEUP_MASK    = 0x0001,
    HW_LHL_STATUS_GPIO_ASYNC_WAKEUP_MASK = 0x0002,
    /// 1 if timer expired, 0 otherwise
    HW_LHL_STATUS_HID_OFF_WAKEUP    = 0x0001,
    /// 1 if GPIO interrupt occurred, 0 otherwise
    HW_LHL_STATUS_GPIO_ASYNC_WAKEUP = 0x0002,

    HW_LDO_CTL_EN_HV_POK_MASK       = 0x8000,
    HW_LDO_CTL_EN_LHL_POK_MASK      = 0x4000,
    HW_LDO_CTL_EN_MIA_FB_DIS_MASK   = 0x0200,
    HW_LDO_CTL_EN_MIA_PASSTH_MASK   = 0x0100,
    HW_LDO_CTL_EN_FW_REG_OFF_MASK   = 0x0002,
    HW_LDO_CTL_EN_CTL_EN_MASK       = 0x0001,
    HW_LDO_CTL_EN_HV_POK            = 0x8000,
    HW_LDO_CTL_EN_LHL_POK           = 0x4000,
    HW_LDO_CTL_EN_MIA_FB_DIS        = 0x0200,
    HW_LDO_CTL_EN_MIA_PASSTH        = 0x0100,
    HW_LDO_CTL_EN_FW_REG_OFF        = 0x0002,
    HW_LDO_CTL_EN_BG_PD_EN          = 0x0002,
    HW_LDO_CTL_EN_CTL_EN            = 0x0001,

    HW_HID_OFF_CNT1_EN_MASK         = 0x8000,
    HW_HID_OFF_CNT1_EN              = 0x8000,

#ifdef BCM20703
    HW_LHL_ADC_CTL_RTC_TERM_CNT_STATUS_EN_P14 = 0x0200,
    HW_LHL_ADC_CTL_RTC_TERM_CNT_STATUS_EN_P15 = 0x0400,
    HW_LHL_ADC_CTL_RTC_TERM_CNT_STATUS_EN_P20 = 0x0800,
    HW_LHL_ADC_CTL_RTC_TERM_CNT_STATUS_EN_P39 = 0x1000,
    HW_LHL_ADC_CTL_RTC_TERM_CNT_STATUS_EN_MASK = (HW_LHL_ADC_CTL_RTC_TERM_CNT_STATUS_EN_P14 | \
                                                  HW_LHL_ADC_CTL_RTC_TERM_CNT_STATUS_EN_P15 | \
                                                  HW_LHL_ADC_CTL_RTC_TERM_CNT_STATUS_EN_P20 | \
                                                  HW_LHL_ADC_CTL_RTC_TERM_CNT_STATUS_EN_P39),
#else
    HW_LHL_ADC_CTL_RTC_TERM_CNT_STATUS_EN_P39 = 0x1000,
    HW_LHL_ADC_CTL_RTC_TERM_CNT_STATUS_EN_MASK = HW_LHL_ADC_CTL_RTC_TERM_CNT_STATUS_EN_P39,
#endif
    HW_LHL_ADC_CTL_RTC_CNT_RESET    = 0x2000,
    HW_LHL_ADC_CTL_RTC_TIMER_FN_EN  = 0x4000,
    HW_LHL_ADC_CTL_RTC_CNT_EN       = 0x8000,

    HW_LHL_LDO_CTL_EN_LHL_RTC_CLOCK_SEL_MASK = 0x0040,
    HW_LHL_LDO_CTL_EN_LHL_MIA_CLOCK_SEL_MASK = 0x0080,
    HW_LHL_LDO_CTL_EN_LHL_RTC_CLOCK_SEL_32KHZ = 0x0040,
    HW_LHL_LDO_CTL_EN_LHL_MIA_CLOCK_SEL_32KHZ = 0x0080,
    HW_LHL_LDO_CTL_EN_LHL_RTC_CLOCK_SEL_128KHZ = 0x0000,
    HW_LHL_LDO_CTL_EN_LHL_MIA_CLOCK_SEL_128KHZ = 0x0000,
#ifdef BCM20703
    HW_HIDOFF_CNT0_MASK             = 0xFF00, // bits 8:15 are valid
    HW_HIDOFF_CNT0_REG_SHIFT        = 0x0008, // shift in the value to this position in register
    HW_HIDOFF_CNT0_RTC_SHIFT        = 0x000D, // shift out 13 bits from rtc value

    HW_HIDOFF_CNT1_MASK             = 0xFFFF,
    HW_HIDOFF_CNT1_RTC_SHIFT        = 0x0015  // shift out 21 bits
#else
    HW_HIDOFF_CNT0_MASK             = 0xFC00, // bits 10:15 are valid
    HW_HIDOFF_CNT0_REG_SHIFT        = 0x000A, // shift in the value to this position in register
    HW_HIDOFF_CNT0_RTC_SHIFT        = 0x000D, // shift out 13 bits from rtc value

    HW_HIDOFF_CNT1_MASK             = 0xFFFF,
    HW_HIDOFF_CNT1_RTC_SHIFT        = 0x0013  // shift out 19 bits
#endif
};

enum
{
        HW_LPO_POWER_DOWN_EN            = 0x0080,
        HW_LPO_POWER_DOWN_SEL_MASK      = 0x0300,
        HW_LPO_POWER_DOWN_SEL_AUTO      = 0x0100,
        HW_LPO_POWER_DOWN_SEL_FORCE     = 0x0200
};

#ifdef BCM20703
enum
{
    HW_LPO_GPIO_ASYNC_WAKEUP_TURNS_ON_LPO_MASK      = 0x0800,
    HW_LPO_GPIO_ASYNC_WAKEUP_TURNS_ON_LPO_DISABLE   = 0x0000,
    HW_LPO_GPIO_ASYNC_WAKEUP_TURNS_ON_LPO_ENABLE    = 0x0800,
};
#endif

enum
{
    HW_LPO_KEYSCAN_128K_FREQ_AUTO_SWITCH_MASK       = 0x8000,
    HW_LPO_KEYSCAN_128K_FREQ_AUTO_SWITCH_ENABLE     = 0x8000,
    HW_LPO_KEYSCAN_128K_FREQ_AUTO_SWITCH_DISABLE    = 0x0000,
    HW_LPO_HIDOFF_FREQUENCY_MASK                    = 0x7000,
    HW_LPO_HIDOFF_FREQUENCY_SHIFT                   = 0x000C,
    HW_LPO_ACTIVE_FREQUENCY_MASK                    = 0x0460,
    HW_LPO_ACTIVE_FREQUENCY_SHIFT                   = 0x0005,
    HW_LPO_FREQ_128KHZ                              = 0x0000,
    HW_LPO_FREQ_32KHZ                               = 0x0001,
    HW_LPO_FREQ_16KHZ                               = 0x0003,
};

enum
{
        HW_MIA_LPO_RC_CLK_DIVISOR_MASK = 0x100,
        HW_MIA_LPO_RC_CLK_DIVISOR_1    = 0x000, // default: don't devide RC clk down
        HW_MIA_LPO_RC_CLK_DIVISOR_4    = 0x100, // devide RC clock by 4 and sent to PDS and PMU
};


enum
{
    KEEPSTATE0_HID_OFF_MASK         = 0x0001,
    KEEPSTATE0_SOFT_POWER_OFF_MASK  = 0x0002,
    KEEPSTATE0_FUNC_LOCK_STATE_MASK = 0x0004,
    KEEPSTATE0_HID_OFF              = 0x0001,
    KEEPSTATE0_SOFT_POWER_OFF       = 0x0002,
    KEEPSTATE0_FUNC_LOCK_STATE_ON   = 0x0004,
    KEEPSTATE0_FUNC_LOCK_STATE_OFF  = 0x0000
};

enum
{
    HID_OFF_WAKEUP_TIME_NONE = 0
};

enum
{
    MIA_LPO_NONE = 0,
    MIA_LPO_LHL_ON = 1,
    MIA_LPO_32K_ON = 2
};

typedef enum
{
    /// Use the 32 KHz clock for the RTC to give a range of ~64 ms - ~36 Hrs
    HID_OFF_TIMED_WAKE_CLK_SRC_32KHZ,

    /// Use the 128 KHz clock for the RTC to give a range of ~256 ms - ~144 Hrs
    HID_OFF_TIMED_WAKE_CLK_SRC_128KHZ
} MiaTimedWakeRefClock;

#pragma pack(1)
typedef PACKED struct
{
    /// Pointer to the timed wake setup function
    void (*mia_virtualSetupTimedWake)(UINT32 wakeupTime, MiaTimedWakeRefClock ref);

    /// Whether mia HW is initialized or not
    UINT8 inited            : 1;

    /// Whether KS driver is registered with this instance
    UINT8 keyscanRegistered : 1;

    /// Whether Quad driver is registered with this instance.
    UINT8 quadRegistered    : 1;

    /// Whether interrupt is enabled/disabled
    UINT8 lhlInterruptState : 1;

    /// Whether interrupt is enabled/disabled
    UINT8 miaInterruptState : 1;

    /// Whether lpo 32k was running
    UINT8 lpo32kWasRunning : 1;

    /// Whether reason for reset was power on
    UINT8 resetReasonPor : 1;

} MiaState;


#ifdef BCM20703 // fixme_bfn clean up
typedef enum
{
    LHL_CLK_SEL_12MHZ     = 0x00, // default clk_rpu/2
    LHL_CLK_SEL_6MHZ      = 0x01, // clk_rpu/4
    LHL_CLK_SEL_3MHZ      = 0x02, // clk_rpu/8
    LHL_CLK_SEL_1_5MHZ    = 0x03, // clk_rpu/16
    LHL_CLK_SEL_MASK      = 0x03
} LHL_CLK_SEL_CTL;


typedef enum
{
    MIA_IRL_CLK_MASK    = 0x04,
    MIA_IRL_CLK_OFF     = 0x00, // default
    MIA_IRL_CLK_ON     = 0x04
} MIA_IRL_CLK_CTL;

typedef enum
{
    HID_UPI_CLK_MASK    = 0x08,
    HID_UPI_CLK_OFF     = 0x00,     // default
    HID_UPI_CLK_ON     = 0x08,
} HID_UPI_CLK_CTL;

typedef enum
{
    MIA_ADC_CLK_SEL_MASK            = 0x30,
    MIA_ADC_CLK_SEL_12MHZ           = 0x00,       // default : using ADC macro 12MHz output clock as ADC clock source
    MIA_ADC_CLK_SEL_RPU_MIA_DIV8    = 0x20,       // for debugging/testing purpose + if rpu clock is 96MHz
    MIA_ADC_CLK_SEL_RPU_MIA_DIV2    = 0x30,       // for debugging/testing purpose + if rpu clock is 24MHz
} MIA_ADC_CLK_SEL_CTL;

typedef enum
{
    MIA_ADC_CLK_MASK    = 0x40,
    MIA_ADC_CLK_DISABLE = 0x00, // default
    MIA_ADC_CLK_ENABLE  = 0x40
} MIA_ADC_CLK_CTL;

typedef enum
{
    HID_CLK_MASK    = 0x100,
    HID_CLK_DISABLE = 0x000,
    HID_CLK_ENABLE  = 0x0100,   // default
} HID_CLK_CTL;

typedef enum
{
    MIA_ADC_DMA_CLK_MASK    = 0x200,
    MIA_ADC_DMA_CLK_DISABLE = 0x000,    // default
    MIA_ADC_DMA_CLK_ENABLE  = 0x200
} MIA_ADC_DMA_CLK_CTL;


typedef enum
{
    MIA_AUX_CLK_1M_MASK     = 0x400,
    MIA_AUX_CLK_1M_DISABLE  = 0x000,
    MIA_AUX_CLK_1M_ENABLE   = 0x400,
} MIA_AUX_CLK_1M_CTL;

typedef enum
{
    MIA_AUX_CLK_XTAL_IN_MASK    = 0x800,
    MIA_AUX_CLK_XTAL_IN_DISABLE = 0x000,
    MIA_AUX_CLK_XTAL_IN_ENABLE  = 0x800,
} MIA_AUX_CLK_XTAL_IN_CTL;


typedef enum
{
    MIA_CLK_1M_NATIVE_MASK      = 0x1000,
    MIA_CLK_1M_NATIVE_DISABLE   = 0x0000, // default
    MIA_CLK_1M_NATIVE_ENABLE    = 0x1000
} MIA_CLK_1M_NATIVE_CTL;

typedef enum
{
    MIA_CLK_1M_MASK     = 0x2000,
    MIA_CLK_1M_DISABLE  = 0x0000,    // default
    MIA_CLK_1M_ENABLE   = 0x2000
} MIA_CLK_1M_CTL;

typedef enum
{
    OTP_CLK_RPU_MASK    = 0xC000,
    OTP_CLK_RPU_DIV_4   = 0x0000, // default
    OTP_CLK_RPU_DIV_8   = 0x4000,
    OTP_CLK_RPU_DIV_16  = 0x8000,
} MIA_OTP_CLK_SEL_CTL;

typedef enum
{
    MIA_DEBUG_SPIFFY1_MASK          = 0x100,
    MIA_DEBUG_SPIFFY1_LHL_GPIO      = 0x100,    // spiffy1 will come from LHL GPIOs
    MIA_DEBUG_SPIFFY1_CORE_DOMAIN   = 0x000,    // spiffy1 will come from core domain
} MIA_DEBUG_SPIFFY1_CTL;

typedef enum
{
    MIA_DEBUG_UART2_MASK          = 0x200,
    MIA_DEBUG_UART2_LHL_GPIO      = 0x200,    // uart2 will come from LHL GPIOs
    MIA_DEBUG_UART2_CORE_DOMAIN   = 0x000,    // uart2 will come from core domain
} MIA_DEBUG_UART2_CTL;

#endif

#pragma pack()

void mia_init(void);
void mia_clkFreezeNotifyDriver(void);
void mia_clkUnfreezeNotifyDriver(void);

// Interrupt handlers are friends of miadriver.
void lhl_interruptHandler(void);
void ks_interruptHandler(void);
void quad_interruptHandler(void);

void mia_unfreezeClk(void);
void mia_freezeClk(void);
void mia_pollHardware(void);
void mia_flushAllEvents(void);
void mia_notificationRegisterKeyscan(void);
void mia_notificationRegisterQuad(void);
int mia_handleLhlInterrupt(void *unused);
int mia_handleKsInterrupt(void *unused);
int mia_handleQuadInterrupt(void *unused);

UINT16 mia_getKeepstate0(void);
UINT16 mia_getKeepstate1(void);
void mia_setKeepstate0(UINT16 newVal);
void mia_setKeepstate1(UINT16 newVal);
void mia_addKeepstate0(UINT16 newVal);
void mia_addKeepstate1(UINT16 newVal);
void mia_delKeepstate0(UINT16 newVal);
void mia_delKeepstate1(UINT16 newVal);
BOOL32 mia_isResetReasonPor(void);
void mia_enableKeyscanPriorToHidOff(void);
void mia_turnOffClockIfUnused(void);
void mia_setupTimedWake(UINT32 wakeupTimeInMs, MiaTimedWakeRefClock ref);
void mia_enterHidOff(UINT32 wakeupTime, MiaTimedWakeRefClock ref);
void mia_setupTimedWake(UINT32 wakeupTime, MiaTimedWakeRefClock ref);
void mia_enableMiaInterrupt(BOOL32 enable);
void mia_enableLhlInterrupt(BOOL32 enable);
BOOL32 mia_getMiaInterruptState(void);
BOOL32 mia_getLhlInterruptState(void);
void mia_restoreMiaInterruptState(void);
void mia_restoreLhlInterruptState(void);
UINT8 mia_turnoffUnusedLpos(void);
UINT8 mia_turnOffLhlAnd32KLposForHidoff(void);

#ifdef BCM20703
void mia_setKeepstate2(UINT16 newVal);
void mia_addKeepstate2(UINT16 newVal);
void mia_delKeepstate2(UINT16 newVal);
void mia_lhlClkSelect(LHL_CLK_SEL_CTL clkSelect);
void mia_irlClkEnable(BOOL32 enable);
void mia_hidUpiClkEnable(BOOL32 enable);
void mia_adcClkSelect(MIA_ADC_CLK_SEL_CTL clkSelect);
void mia_adcClkEnable(BOOL32 enable);
void mia_hidClockEnable(BOOL32 enable);
void mia_adcDmaClkEnable(BOOL32 enable);
void mia_auxClk1M_Enable(BOOL32 enable);
void mia_auxClkXtalInEnable(BOOL32 enable);
void mia_clk1M_NativeEnable(BOOL32 enable);
void mia_clk1M_Enable(BOOL32 enable);
void mia_otpClkSelect(MIA_OTP_CLK_SEL_CTL clkSelect);
void mia_spiffy1SrcSelect(MIA_DEBUG_SPIFFY1_CTL srcSelect);
void mia_uart2SrcSelect(MIA_DEBUG_UART2_CTL srcSelect);

#endif

/* @} */

#ifdef __cplusplus
}
#endif


#endif
