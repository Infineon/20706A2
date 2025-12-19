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
/*******************************************************************************
* File Name: hidevent.h
*******************************************************************************/

/** \addtogroup HidEvents HID Events
 *  \ingroup hidapp
 *  The HID application assumes that there is an event queue that
 *  holds user events until they can be placed in reports and sent over to the
 *  host. For the convenience of applications, the HID application pre-defines
 *  certain common events and a structure for each event. Application are free
 *  to define their own events.
 */

/// @{
#ifndef __HID_EVENT_H_
#define __HID_EVENT_H_

#include "data_types.h"
#include "keyscan.h"

/////////////////////////////////////////////////////////////////////////////////
// Types and Defines
/////////////////////////////////////////////////////////////////////////////////
typedef unsigned short      WORD;

/// Predefined event types
enum
{
        /// Reserved event type indicating that no event type is acceptable in places where an event type is required
        HID_EVENT_NONE=0,

        /// Motion along axis 0
        HID_EVENT_MOTION_AXIS_0,

        /// Motion along axis 1
        HID_EVENT_MOTION_AXIS_1,

        /// Motion along axis 2
        HID_EVENT_MOTION_AXIS_2,

        /// Motion along axis 3
        HID_EVENT_MOTION_AXIS_3,

        /// Motion along 2 axis. Useful for any input with 2 axis.
        HID_EVENT_MOTION_AXIS_X_Y,

        /// Motion along 2 axis. Useful for a second input with 2 axis, e.g. trackball on a mouse
        HID_EVENT_MOTION_AXIS_A_B,

        /// Change in button state
        HID_EVENT_NEW_BUTTON_STATE,

        /// Change in key state
        HID_EVENT_KEY_STATE_CHANGE,

        /// Motion Sensor data available
        HID_EVENT_MOTION_DATA_AVAILABLE,

        /// Voice data available
        HID_EVENT_VOICE_DATA_AVAILABLE,

        ///the hid event for BRCM_MIC_START
        HID_EVENT_MIC_START,

        ///the hid event for BRCM_MIC_STOP
        HID_EVENT_MIC_STOP,

        ///the hid event for BRCM_RC_MIC_START_REQ
        HID_EVENT_RC_MIC_START_REQ,

        ///the hid event for BRCM_RC_MIC_STOP_REQ
        HID_EVENT_RC_MIC_STOP_REQ,

        ///the hid event for BRCM_RC_VOICEMODE_RD_ACK
        HID_EVENT_AUDIO_MODE,

        ///the hid event for BRCM_RC_CODECSETTINGS_RD_ACK
        HID_EVENT_AUDIO_CODEC_RD,

        ///the hid event for BRCM_RC_CODECSETTINGS_WT_ACK
        HID_EVENT_AUDIO_CODEC_WT,

        /// Event fifo overflow event
        HID_EVENT_EVENT_FIFO_OVERFLOW = 0xfe,

        /// Reserved event type indicating that any event type is acceptable in places where an event type is required
        HID_EVENT_ANY=0xff
};

/// Pack all events to limit the amount of memory used
#pragma pack(1)

/// Basic HID event
typedef PACKED struct
{
    /// Type of event
    BYTE    eventType;

    /// Poll sequence number. Used to identify events from seperate polls
    BYTE    pollSeqn;
}HidEvent;

/// Single axis event structure
typedef PACKED struct
{
    /// Base event info
    HidEvent eventInfo;

    /// Motion along the axis
    INT16   motion;
}HidEventMotionSingleAxis;

/// XY motion event structure
typedef PACKED struct
{
    /// Base event info
    HidEvent eventInfo;

    /// Motion along axis X
    INT16    motionX;

    /// Motion along axis Y
    INT16   motionY;
}HidEventMotionXY;

/// AB motion event structure
typedef PACKED struct
{
    /// Base event info
    HidEvent eventInfo;

    /// Motion along axis A
    INT16   motionA;

    /// Motion along axis B
    INT16   motionB;
}HidEventMotionAB;

/// Button state change event structure
typedef PACKED struct
{
    /// Base event info
    HidEvent eventInfo;

    /// New state of buttons
    WORD    buttonState;
}HidEventButtonStateChange;

/// Key state change event structure
typedef PACKED struct
{
    /// Base event info
    HidEvent eventInfo;

    /// Key event.
    KeyEvent keyEvent;
}HidEventKey;

/// Any generic event
typedef PACKED struct
{
  /// Base event info
  HidEvent eventInfo;

  /// The event
  UINT32 anyEvent;
}HidEventAny;

typedef PACKED struct
{
    /// Base event info
    HidEvent eventInfo;

    void * userDataPtr;
}HidEventUserDefine;

#pragma pack()

/// @}

#endif
