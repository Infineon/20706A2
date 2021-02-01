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
/*******************************************************************************
* This file contains all configuration items used by hidd drivers
********************************************************************************/
#ifndef __HIDD_DRIVERS_CONFIG__
#define __HIDD_DRIVERS_CONFIG__

#include "types.h"
#include "adc.h"

#pragma pack(1)

///  Device LPM config items
typedef PACKED struct
{
    ///  Enumeral indicating low power mode to use when in the 'disconnected' state
    ///  on both transports, and the HidApp has nothing to do
    BYTE disconnectedLowPowerMode;

    /// Time to wake up from hid-off in milliseconds. 0 for never.
    UINT32 wakeFromHidoffInMs;

    /// The reference clock to use to wake from hid-off - 32 KHz Ext or 128 KHz MIA
    UINT8 wakeFromHidoffRefClk;

}DeviceLpmConfig;

#ifdef BCM20703
typedef PACKED struct
{
    DeviceLpmConfig devLpmConfig;
    UINT8 bleapp_hidoff_enable;
} BleAppConfig;
#endif


/// Keyscan driver configuration including HW configuration
typedef PACKED struct
{
    /// Configuration value for the rows in the keyscan matrix
    WORD    rowGpioConfig;

    /// Configuration value for the columns in the keyscan matrix
    WORD    colGpioConfig;

    /// Micro debounce count defines how many times a key must be down/up
    /// in back-to-back scans (1 MIA clock/scan) for it to
    /// be considered down or up.
    /// Macro debounce specifies the number of full scan cycles
    /// across which a key must be detected up or down before the
    /// HW will accept it. Note that macro debounce differs from
    /// micro debounce in that with macro debounce works across
    /// scan cycles (which are in the ms range) whereas micro
    /// debounce is inside a single scan cycle. For example
    /// if a macro debounce value of 2 is specified, a key needs
    /// to be detected up/down in 3 consecutive scan cycles
    /// (of the whole matrix) before it is accepted as up or down.
    /// - 3:0 =>    Macro down debounce
    /// - 7:4 =>    Macro up debounce
    /// - 9:8 =>    Micro debounce (single value for up/down)
    /// - 16:10 =>  Keyscan extend count. Specifies the number of idle MIA cycles (x4) between
    ///             two HW scans. This allows the scan cycle to be lengthened
    ///             A value of 1 will insert 4 idle cycles, and 127 by 508
    ///             idle cycles.
    /// - 17 =>     Enables keyscan extend when set
    UINT32 debounceConfig;

    /// Keyscan control register
    ///  - 0 =>     keyscan enable; must be set to 1 or the keyscan HW will be turned off
    ///  - 1 =>     reserved
    ///  - 2 =>     ghost enabled
    ///  - 3 =>     reserved (Keyscan interrupt enable, handled by FW)
    ///  - 4 =>     reserved (Keyscan reset, handled by FW)
    ///  - 5 =>     reserved
    ///  - 7:6  =>  "rc ext": Idle duration between column scans to accomodate
    ///             slow RC times on keyboard designs. Range 0-3
    ///  - 10:8 =>  The number of rows in the matrix minus one, e.g. 0 means 1 row, 7 means 8 rows
    ///  - 15:11=>  The number of columns in the matrix minus one, e.g. 1 means 1 column, 16 means 17 columns, etc.
    ///  - 16 =>    Enable active pull up on the columns after each column scan to alleviate
    ///             slow RC times on keyboard designs.
    ///  - 17 =>    Enable active pull up on the rows in between scans to
    ///             alleviate slow RC times on keyboard designs and avoid
    ///             false key detection
    ///  - 18 =>    keep keyscan clk on always. If not set MIA gates off the
    ///             clock when there is no activity.
    UINT32 control;
} KeyscanConfig;

/// A single pin configuration entry
typedef PACKED struct
{
    /// Combined id for the port and the pin
    BYTE portPin;

    /// Configuration value
    UINT16 configValue;
} GpioPinConfig;

/// GPIO configuration type maps specific pin of a specific port to
/// a config value. A config value is the logical or of one or more
/// configuration options described above.
typedef PACKED struct
{
    /// Total number of pin configs below. Max value of GPIO_NUMBER_OF_PINS
    BYTE configPinCount;

	/// Output value for individual pins
	UINT16 outputValue[GPIO_NUMBER_OF_PORTS];

    /// Configuration for individual pins
    GpioPinConfig pinConfig[GPIO_NUMBER_OF_PINS];
} GpioConfigEntry;

//Maximum number of buttons, set to 16
#define MAX_BUTTONS  16

typedef PACKED struct
{
    /// Number of buttons. This defines the number of columns for the key scan
    /// matrix
    BYTE numButtons;

    /// Whether all pending key events should be processed when a flush
    /// request is received from the HID-APP. If this flag is not
    /// set the flush request is ignored.
    BYTE flushUserActivityAllowed;

    /// Whether current button state should be cleared on a flush.
    /// Note that this is independent of flushUserActivityAllowed item
    /// However, it is reccommended that this flag should only be set if
    /// flushUserActivityAllowed is also set
    BYTE clearCurButtonStateOnFlush;

    /// button->report bit mapping
    WORD reportBit[MAX_BUTTONS];
}ButtonConfig;

#ifdef BCM20703
/// configure for SPI1 GPIO ports
typedef PACKED struct
{
    UINT8   masterOrSlave;
    UINT16  pinPullConfig;
    UINT32  spiGpioConfig;
}Spi1PortConfig;

/// configure for SPI2 GPIO port
typedef PACKED struct
{
    UINT32  spiGpioConfig;
}Spi2PortConfig;

typedef PACKED struct
{
    Spi1PortConfig spi1;
    Spi2PortConfig spi2;
}SpiPortConfig;
#else
/// configure for SPI1 GPIO ports
typedef PACKED struct
{
    UINT16  pinPullConfig;
    UINT32  spiGpioConfig;
}Spi1PortConfig;

/// configure for SPI2 GPIO port
typedef PACKED struct
{
    UINT8   masterOrSlave;
    UINT16  pinPullConfig;
    UINT32  spiGpioConfig;
}Spi2PortConfig;
#endif

/// Real-Time Clock config
typedef PACKED struct
{

    /// configure the oscialltor frequencey
    UINT8       oscillatorFrequencykHz;

    /// The reference clock to use for RTC - the 32K or 128 Mia LPO
    UINT8       rtcRefClock;
}RTCconfig;

//////////////////////////////////////////////////
/// Quadrature driver configuration
/////////////////////////////////////////////////
typedef PACKED struct
{
    /// Scan period
    UINT16    scanPeriod;

    /// LED0(P26) on instants
    UINT16    togglecountLed0;
	/// LED1(P27) on instants
    UINT16    togglecountLed1;
	/// LED2(P28) on instants
    UINT16    togglecountLed2;
	/// LED3(P29) on instants
    UINT16    togglecountLed3;
    /// X axis Sample instant
    UINT16    sampleInstantX;
	/// Y axis Sample instant
    UINT16    sampleInstantY;
	/// Z axis Sample instant
    UINT16    sampleInstantZ;

    /// Optical LED enable/disable method selection
    UINT16    ledEnableDisableControls;

    /// Reserved for future use
    BYTE    reserved0[3];

    /// Configuration value used for each GPIO pin used for quadrature. This
    /// allows configuration of pull up/down, etc. just like a GPIO.
    WORD    quadratureInputGpioConfig;

    /// If TRUE, Port 0 selected as quadrature input port (P2,P3,P4,P5,P6,P7)
    /// If FALSE, Port 2 selected as quadrature input port (P32,P33,P34,P35,P36,P37)
    BYTE    port0PinsUsedAsQuadratureInput;


    /// GPIO configuration for QOC0. If false, leaves the GPIO alone.
    /// Port 1 Pin 10
    BYTE    configureP26AsQOC0      :1; // bit 0
	/// GPIO configuration for QOC1. If false, leaves the GPIO alone.
    /// Port 1 Pin 11
    BYTE    configureP27AsQOC1      :1; // bit 1
	/// GPIO configuration for QOC2. If false, leaves the GPIO alone.
    /// Port 1 Pin 12
    BYTE    configureP28AsQOC2      :1; // bit 2
	/// GPIO configuration for QOC3. If false, leaves the GPIO alone.
    /// Port 1 Pin 13
    BYTE    configureP29AsQOC3      :1; // bit 3
	/// Reserved
    BYTE    reserved1                : 4;
    /// Configuration for QD
    /// XY and Z enable and sampling rate control
    BYTE    channelEnableAndSamplingRate;

    /// Quadrature HW enable and general control
    BYTE    quadratureEnableAndControl;

    /// Flag to indicate that X axis motion should be polled
    BYTE    pollXAxis;

    /// Flag to indicate that Y axis motion should be polled
    BYTE    pollYAxis;

    /// Flag to indicate that Z axis motion should be polled
    BYTE    pollZAxis;
} QuadratureConfig;

typedef PACKED struct
{
    /// time in microseconds to wait after enabling HIDOFF
    UINT32 delayAfterEnteringHidOffInUs;
    /// number of microseconds to wait for keyscan block to get synchronized
    UINT16 keyscanDelay;
    /// port (bits 5-7) and pin (bits 0-4) to generate an interrupt on
    /// when come out of HIDOFF timed wake
    UINT8  timedWakeIntPortPin;
#ifdef BCM20703
    UINT8 lpoActiveFreq;
    UINT8 lpoHidoffFreq;
    UINT8 keyscan128kFreqAutoSwitchEnable;
#endif
} MiaDriverConfig;

typedef PACKED struct
{
    // LDO control Enable Register
    // - ldo_ctl_en_adr
    // When ldo_ctl_en=1, LDO module will use ldo_ctl# regsiter values to control LDO
    // LDO analog IP
    // default values are all zeros,
    PACKED union
    {
        PACKED struct
        {
            // bit 0 ldo control enable
            //
            UINT32            ldo_ctl_en_bit            : 1;

            // bit 1 -   enale powerdown of the bandgap in HIDDOFF mode
            //           set this bit, bandgap will be power down when HIDOFF mode
            UINT32              ldo_bandgap_pd_en       : 1;


            // bit 4:2 - LDO output level when 24MHz crystal is powered down
            // program with the same value as ldo_ctl1[3:1], if no votage step is needed
            UINT32              ldo_sleep_output_level  : 3;

            // reserved 31:5
            UINT32              reserved7            : 27;               // bit 31:5
        } ldo_en_bitmap;

        UINT32          ldo_en_reg32;

    } ldo_ctl_en_reg;

    // ldo_ctl[31:0] = {ldo_ctl1_reg, ldo_ctl0_reg}
    //
    // ldo_ctl[0]   - BG low power mode, default 0 (enable)
    // ldo_ctl[2:1] - LPF enable/adjust to fitler off BG noise , default disabled for faster startup
    // ldo_ctl[3]   - BG power down, default power up
    // ldo_ctl[7:4] - BG PTAT Current adjustment
    // ldo_ctl[11:8]    - BG CTAT current adjustment
    // ldo_ctl[14:12]   - BG Vref Adjustment
    // ldo_ctl[15]      - reserved
    // ldo_ctl[16]      - LDO Power down    , defautl power up
    // ldo_ctl[19:17]   - LDO Output Voltage Adjustment
    // ldo_ctl[20]      - Enable VDS matching amplifier for low dropout, default enabled
    // ldo_ctl[21]      - Enable LDO current limite, default disable
    // ldo_ctl[22]      - Select between constant/feedback current limit mode for LDO
    // ldo_ctl[23]      - LDO current limit adjustment
    // ldo_ctl[25:24]   - adjust LDO feedback pole to compensate ESR zero
    // ldo_ctl[31:26]   - reserved
    //

    PACKED union
    {
        UINT32          ldo_ctl_reg32;

        PACKED struct
        {
            // bit 0    -  dsiable BG lower power mode
            UINT32      bgLowerPowerModeDisable : 1;

            // bit 2:1  - LPF enable to filter off BD noise
            UINT32      lpfEnableFilterBGNoise  : 2;

            // bit 3    - power down the bandgap
            UINT32      bgPowerDown             : 1;

            // bit 7:4  - bandgap ptat current adjustment
            UINT32      bgPTATCurrentAdj        : 4;

            // bit 11:8 - bandgap CTAT current adjustment
            UINT32      bgCTATCurrentAdj        : 4;

            // bit 14:12 - BG Vref adjustment
            UINT32      bgVrefAdjust            : 3;

            // bit 15 -reserved
            UINT32      reserved_1                : 1;

            // bit 16    - LDO Power down
            UINT32      ldoPowerDown             : 1;

            // bit 19:17  - LPF enable to filter off BD noise
            UINT32      ldoOutputVoltageAdj     : 3;

            // bit 20    - Disable VDS matching amplifier for low dropout
            UINT32      ldoVDSdisable           : 1;

            // bit 21   - Enable LDO current limite
            UINT32      ldocurrentLimitenable   : 1;

            // bit 22    - LDO limit mode/loopback mode 0:limite 1:loopback
            UINT32      ldoCurrentMode          : 1;

            // bit 23    - limit mode adjustment
            UINT32      ldoCurrentLimitModeAdj  : 1;

            // bit 25:24    - current mode adjustment
            UINT32      ldoCurrentLoopbackModeAdj   : 2;

            // reserved
            UINT32      reserved_2                :6;

        } ldo_ctl_bitmap;

        PACKED struct
        {
            UINT16                  ldo_ctl0_reg16;
            UINT16                  ldo_ctl1_reg16;

        }ldo_ctl_reg16;

    } ldo_ctl_reg;

} LDOconfig;

/// Clock Config
typedef PACKED struct
{
    /// Flag indicating whether clock switching is enabled
    UINT8 enableClockSwitch;
    /// programs the cpu_clock and pause_cpu_clock frequency
    UINT8 cpuClockDivisor;
} ClockConfig;
#pragma pack()

#ifdef BCM20703
extern SpiPortConfig spiPortConfig;

extern BleAppConfig bleAppConfig;
#else
extern Spi1PortConfig  spi1PortConfig;
extern Spi2PortConfig  spi2PortConfig;

extern DeviceLpmConfig devLpmConfig;
#endif
extern KeyscanConfig ksConfig;
extern MiaDriverConfig miaDriverConfig;
extern GpioConfigEntry gpioConfig;
extern RTCconfig rtcConfig;
extern LDOconfig ldoConfig;
extern ADCConfig adcConfig;
extern ButtonConfig buttonConfig;
extern QuadratureConfig quadratureConfig;
extern ClockConfig clockConfig;

#endif
