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
*    File Name: rtc.h
*
*    This file defines an RTC driver
*
********************************************************************
*/
#ifndef __RTC_H__
#define __RTC_H__


#include "types.h"


/**  \addtogroup RTC
 *  \ingroup HardwareDrivers
*/

/*! @{ */
/**
* Defines an Rtc driver.
*
* 20730/20733 support 48 bits RTC timer from 32kHz crystal
* oscillator.
*
* Usage:
*
*  (1) use Rtc->getInstance() to get the RTC driver instance
*  first.
*
* (2) use Rtc->setRTCTime() to set the current calender time
*
* (3) user Rtc->getRTCTime() to retrieve the current calender
* time.
*
* (4) Rtrc->ctime(), will convert the RTC_time to ascii user
* friendly string.
*
*/

enum
{
    LHL_CTL_32K_OSC_POWER_UP = 0x04,
    LHL_CTL_32K_OSC_POWER_DN = 0x00,
    LHL_CTL_32K_OSC_POWER_MASK = 0x04
};

//
// LHL_CTL register
//
//
typedef union
{
    UINT32          lhl_adc_rtc_ctl_reg;

    struct
    {
        /// bit 0:11  reserved
        UINT32                  reserved1              : 12;

        /// bit 12 -   Real time clock terminal count status enable
        UINT32                  rtcTerminalCntStatusEn  : 1;

        /// bit 13 - RTC reset counter
        UINT32                  rtcResetCounter         : 1;

        /// Bit 14 - RTC timer function enable
        UINT32                  rtcTimerFuncEn          : 1;

        /// Bit 15 - RTC counter enable
        UINT32                  rtcCounterEn            : 1;

        /// reserved 31:3
        UINT32                  reserved2               : 16;
    }bitmap;
} tRTC_LHL_ADC_RTC_CTL_REG;


// RTC enable type
typedef enum
{
    // enable RTC and power up 32kHz crystal oscillator
    LHL_CTL_RTC_ENABLE              = 1,

    // disable RTC and power down the 32kHz crystal oscillator
    LHL_CTL_RTC_DISABLE             = 0,

}tRTC_LHL_CTL_RTC_ENABLE_MODE;


enum
{
    RTC_REF_CLOCK_SRC_32KHZ  = 32,
    RTC_REF_CLOCK_SRC_128KHZ = 128
};


///
/// Real time clock read from hardware (48 bits)
///
///
///
typedef union
{
    UINT64          rtc64;

    struct
    {
        UINT16      rtc16[4];
    }reg16map;

    struct
    {
        UINT32      rtc32[2];
    }reg32map;

} tRTC_REAL_TIME_CLOCK;


//
// time conversion reference timebase
//  2010/1/1
//
typedef enum
{
    BASE_LINE_REF_YEAR      =   2010,
    BASE_LINE_REF_MONTH     =   1,
    BASE_LINE_REF_DATE      =   1,
} tRTC_REFERENCE_TIME_BASE_LINE;

///
/// broken-down calendar representation of time
///
typedef struct
{
    /// seconds (0 - 59), not support leap seconds
    UINT16  second;

    /// minutes (0 - 59),
    UINT16  minute;

    /// hours (0 - 23)
    UINT16  hour;

    /// day of the month (1 - 31)
    UINT16  day;

    /// month (0 - 11, 0=January)
    UINT16  month;

    /// year
    /// should larger then 2010
    UINT16  year;

} RtcTime;

// Internal runtime-state of RTC driver
typedef struct
{
    UINT32                       userSetRtcClockInSeconds;
    tRTC_REAL_TIME_CLOCK         userSetRtcHWTimeStamp;
} RtcState;


// Initialize the RTC block.
void rtc_init(void);

//
// Reads Real time clock value from hardware clock
//
void rtc_getRTCRawClock(tRTC_REAL_TIME_CLOCK *rtcClock);

//
// get current time in RTC_time format
//
void rtc_getRTCTime(RtcTime *timebuf);

//
// set the current time
//
BOOL32 rtc_setRTCTime(RtcTime  *newTime);

// convert the tm object pointed by timer to
// c string containing a human-readable verion of the corresponding local time and data
//
// the returned string has the following format
//
// Mmm dd hh:mm:ss yyyy
// where
//      Mmm - the month in letters
//      dd  - the day of the month
//      hh:mm:ss -  time
//      yyyy - year
//
char *rtc_ctime(RtcTime *timer, char *outbuf);



// conver the 32 bit seconds to RTC_time broken down format
void    rtc_sec2RtcTime(UINT32 second, RtcTime *rtctime);

// convert RTC_time broken-down format to 32-bits seconds
void    rtc_RtcTime2Sec(RtcTime *rtctime, UINT32 *second);

//
// User/application set the RTC time
// will conver the user/app settings to
// seconds
extern UINT32                       userSetRtcClockInSeconds;
extern tRTC_REAL_TIME_CLOCK         userSetRtcHWTimeStamp;


/* @}  */
#endif
