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
* This file contains all configuration items used by hid applications.
********************************************************************************/
#ifndef __HID_CONFIG__
#define __HID_CONFIG__

#include "data_types.h"


/// Maximum number of keys supported by our HID
#define KB_MAX_KEYS 160

/// Maximum number of remote reports supported by our HID
#define REMOTE_MAX_USER_DEFINED_RPT_TYPE 8

/// Maximum size of remote translation code
#define REMOTE_MAX_TRANSLATION_CODE_SIZE 2

typedef unsigned short      WORD;

/// Key types. Used to direct key codes to the relevant key processing function
enum KeyType
{
    /// Represents no key. This should not occur normally
    KEY_TYPE_NONE=0,

    /// Represents a standard key. The associated translation code represents the reported value
    /// of this key
    KEY_TYPE_STD=1,

    /// Represents a modifier key. The associated translation value indicates which bit
    /// in the modifier key mask is controlled by this key
    KEY_TYPE_MODIFIER=2,

    /// Represents a bit mapped key in the bit mapped report. The associated translation value
    /// provides the row col of the bit which represents this key
    KEY_TYPE_BIT_MAPPED=3,

    /// The sleep key
    KEY_TYPE_SLEEP=4,

    /// The function lock key
    KEY_TYPE_FUNC_LOCK=5,

    /// Function lock dependent keys. These keys act like bit mapped keys when function lock is on
    /// and standard keys when function lock is off or the keyboard is in boot mode.
    KEY_TYPE_FUNC_LOCK_DEP=6,

    /// A user defined key. Interpretation is provided by user code
    KEY_TYPE_USER_DEF_0=16,

    /// A user defined key. Interpretation is provided by user code
    KEY_TYPE_USER_DEF_1=17,

    /// A user defined key. Interpretation is provided by user code
    KEY_TYPE_USER_DEF_2=18,

    /// A user defined key. Interpretation is provided by user code
    KEY_TYPE_USER_DEF_3=19,

    /// A user defined key. Interpretation is provided by user code
    KEY_TYPE_USER_DEF_4=20,

    /// A user defined key. Interpretation is provided by user code
    KEY_TYPE_USER_DEF_5=21,

    /// A user defined key. Interpretation is provided by user code
    KEY_TYPE_USER_DEF_6=22,

    /// A user defined key. Interpretation is provided by user code
    KEY_TYPE_USER_DEF_7=23
};

#pragma pack(1)
/// Keyboard application configuration
typedef PACKED struct
{
    /// ID of the standard report
    BYTE stdRptID;

    /// Maximum number of keys in standard key report. Should be set to 6
    BYTE maxKeysInStdRpt;

    /// Report ID for the bit mapped report
    BYTE bitReportID;

    /// Number of bit mapped keys. Size of the bit report is automatically calculated from this value
    /// according to the following formula:
    ///     report size = ((num bit mapped keys) + 7)/8
    BYTE numBitMappedKeys;

    /// Report ID for the bit mapped report
    BYTE sleepReportID;

    /// Report ID of the pin entry report
    BYTE pinReportID;

    /// Report ID of the LED (output) report
    BYTE ledReportID;

    /// Default LED state. Note that the default implementation does not tie the LED value to physical LEDs
    BYTE defaultLedState;

    /// Scan code of the connect button
    BYTE connectButtonScanIndex;

    /// After an error has occurred, events from multiple poll cycles are combined to ensure that transient
    /// events are not generated. The count below specifies the recovery period in poll cycles.
    BYTE recoveryPollCount;

    /// HW fifo threshold to stop generating idle rate reports. Idle rate report will be generated
    /// as long as the number of packets in the HW fifo is below this number
    BYTE hwFifoThresholdForIdleRateReports;

    /// This parameter defines the rate at which a rollover report is generated when an error state (ghost or overflow) is
    /// maintained for long periods of time. The rate is in BT clock periods. If set to 0, it disables regeneration of
    /// the rollover report.
    WORD repeatRateInBTClocksForRolloverRpt;

    /// Rollover reports will only be repeated as long as the number of packets in the HW fifo is less than this threshold
    BYTE hwFifoThresholdForRolloverRepeats;

    /// Report ID for func-lock reports
    BYTE funcLockReportID;

    /// Default func lock state
    BYTE defaultFuncLockState;

    /// Scroll report ID
    BYTE scrollReportID;

    /// Length of scroll report
    BYTE scrollReportLen;

    /// Negate scroll data.
    BYTE negateScroll;

    /// Scale values for scroll wheel data. Should be set to zero if no scaling is desired
    /// Scaling always divides the input data, i.e. its a shift right.
    BYTE scrollScale;

    /// Maximum number of ticks for which fractional scroll wheel motion data is kept,
    /// i.e. if no additional motion is detected, remaining fractional data is discarded.
    /// If set to 0, data is never discarded. If scroll scaling is not used, should be set to
    /// 0 to improve execution efficiency.
    BYTE pollsToKeepFracScrollData;

    /// Flag indicating whether multiple scroll events should be combined into a single report
    /// Note that this will not combine any other type of event with scroll info
    BYTE scrollCombining;

    /// Size of each element in the event queue. Note: This has to be at least as large as the
    /// largest event that the app will handle
    BYTE maxEventSize;

    /// Maximum number of events that the event queue can hold.
    BYTE maxEventNum;
}KbAppConfig;

/// Keyboard Key Config
typedef PACKED struct
{
    /// Type of key, e.g. std key, modifier key, etc.
    BYTE    type;

    /// Translation code. The actual value depend on the key type.
    ///     - For modifier keys, it  is a bit mask for the reported key
    ///     - For std key, it is the usage provided in the std key report
    ///     - For bit mapped keys, it is the row/col of the associated bit in the bit mapped report
    BYTE    translationValue;
}KbKeyConfig;

/// Remote user defined report configuration
typedef PACKED struct
{
    /// Remote user defined report ID
    BYTE rptID;

    /// Size of the key translation code
    BYTE translationCodeSize;
}RemoteUserDefinedReportConfig;

/// Remote Key Translation Code
typedef PACKED struct
{
    UINT8 translationValue[REMOTE_MAX_TRANSLATION_CODE_SIZE];
}RemoteKeyTranslationCode;

/// Remote application configuration
typedef PACKED struct
{
    /// the default lpm index for mode "HIGH"
    BYTE default_lpm_idx;

    /// the lpm index for motion
    BYTE motion_lpm_idx;

    /// the lpm index for voice
    BYTE voice_lpm_idx;

    /// report ID for motion data
    BYTE motionRptID;

    /// Scan code of the IR button
    BYTE IR_ButtonScanIndex;

    /// Scan code of the Motion START button
    BYTE MotionStart_ButtonScanIndex;

    /// Scan code of the Motion STOP button
    BYTE MotionStop_ButtonScanIndex;

    /// Scan code of the Voice button
    BYTE Voice_ButtonScanIndex;

    /// delay sending audio time period in ms
    UINT16  audio_delay;

    /// audio mode
    BYTE    audio_mode;

    /// gain of the audio codec
    BYTE    audio_gain;

    /// boost of the audio codec
    BYTE    audio_boost;

    /// Maximum number of data bytes in remote report
    BYTE maxBytesInRemoteRpt;

    /// Number of different typpes of remote reports
    BYTE numOfRemoteRpt;

    /// Maximum sample number read in one slot callback
    BYTE maxSampleInOneSlot;

    /// Remote user defined report configuration
    RemoteUserDefinedReportConfig remoteUserDefinedReportConfig[REMOTE_MAX_USER_DEFINED_RPT_TYPE];

    /// Remote Key Translation Code
    RemoteKeyTranslationCode remoteKeyTranslationCode[KB_MAX_KEYS];
}RemoteAppConfig;

/****************************************************************************
 * App specific config item
 ****************************************************************************/
typedef struct
{
    UINT32 app_specific_config_item;
    UINT16 app_specific_config_item_len;
    UINT8 app_specific_config_item_section;
    UINT32 app_specific_sdp_db_config_location;
    UINT16 app_specific_sdp_db_config_len;
    UINT8* app_specific_sdp_db_location;
    UINT8 app_specific_sdp_db_config_section;
} HiddcfaAppSpecificConfig;



/// Miscellaneous configuration items for applications.
/// Currently, only the application dedicated area in the EEPROM is defined here
/// Items that do not logically fit anywhere maybe added to this.
typedef PACKED struct
{
    /// Port and Pin to which EEPROM WP is connected
    /// Most significant 3 bits - port;
    /// Least significant 5 bits - pin;
    /// 0xFF when WP is not configured
    BYTE bleapputils_eepromWpPortPin;

    /// Location of the application deicated area in the EEPROM
    UINT16 bleapputils_eepromCustAreaOffset;

    /// Size of the application dedicated area in the EEPROM
    UINT16 bleapputils_eepromCustAreaLen;
} MiscBleAppConfig;

#pragma pack()


extern HiddcfaAppSpecificConfig hiddAppSpecConfig;
#endif
