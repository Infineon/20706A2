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
*    File Name: pcmdriver.h
*
*    Abstract: This file defines the 20703 PCM driver
*
*    $History:$
*
********************************************************************
*/

#ifndef __BLEAPP_PCM_DRIVER_H___
#define __BLEAPP_PCM_DRIVER_H___

#include "types.h"


/** \addtogroup HardwareDrivers*/
/*! @{ */
/**
* Defines the BCM20703 PCM driver interface.
*/

/*****************************************************************************
          Macro Definitions
*****************************************************************************/

/////////////////////////////////////////////////////////////////////////////////
/// This is the PCM2 driver class
/// 20733 supports two PCM instances, each PCM instance can be either Rx or Tx,but
/// not both simutaniously.Each PCM interface can support two channels. Both channle
/// must be configured for the same direction.
/// PCM interface aslo has an I2S operation mode.
/// PCM2 can be configired as mater or slave in in both PCM and I2S operation mode.
/// Supports I2S and PCM-style SYNC mode. SYNC events can be early/aligned
/// Support PCM_CLK rates up to 16 MHz
/// Supports up to 16 slots per frame
/// Supports up to 16 bits of usable data per slot in both master and slave mode.
/// Slots can be shorter or longer in slave mode and master mode, but we can
/// only transmit and receive the first 16-bits of the slot
///
/// How to use the class:
/// user need to use getInstance() to instanciate a PCM instance. and followed
/// by reset() and start() to start a PCM operation.
/// User and use either poll and interrupt based methods. If user choose to reset
/// interrupt based programming method, after each interrupt ISR  it's the user's
/// responsibility to enable the PCM interrupt again.
/////////////////////////////////////////////////////////////////////////////////

enum
{
    PCM_FIFO_DEPTH = 40
};


enum
{
    PCM_BIT_CLOCK_RATE_128K,
    PCM_BIT_CLOCK_RATE_256K,
    PCM_BIT_CLOCK_RATE_512K,
    PCM_BIT_CLOCK_RATE_1024K,
    PCM_BIT_CLOCK_RATE_2048K
};
enum
{
    FILL_NUM_0,
    FILL_NUM_1,
    FILL_NUM_2,
    FILL_NUM_3
};

enum
{
    FILL_0S,
    FILL_1S,
    FILL_SIGNED,
    FILL_PROG
};

enum
{
    LEFT_JUSTIFY,
    RIGHT_JUSTIFY
};

enum
{
    I2S_DISABLED_MASK,
    I2S_ENABLED_MASK
};

enum
{
    PCM_SAMPLE_RATE_8KHz,
    PCM_SAMPLE_RATE_16KHz,
    PCM_SAMPLE_RATE_4KHz
};

enum
{
    PCM_AUDIO_OUT_SRC_DESERIALIZER,
    PCM_AUDIO_OUT_SRC_FIFO
};

enum
{
    SYNC_FM_PULSE_LENGTH_256,
    SYNC_FM_PULSE_LENGTH_512,
    SYNC_FM_PULSE_LENGTH_1024,
    SYNC_FM_PULSE_LENGTH_2048
};

enum
{
    CHAN_0 = 0,
    CHAN_1 = 1,
    CHAN_2 = 2
};

enum
{
    FIFO_RW_FALURE  = 0,
    FIFO_RW_SUCCESS = 1
};

typedef union
{
    UINT32 word;
    struct
    {
        ///This bit must be set to turn on the PCM interface. Clearing this bit turns off the PCM interface (if loopback not
        ///selected) and thus prevents the associated chip I/O pins from toggling when the PCM interface is not being
        ///used.
        UINT32 pcmActive            : 1;    // bit  0


        ///When 0, operate in PCM mode and support multiple channels per frame.
        ///The sync signal is a pulse.When 1, operate in I2S mode and support
        ///two channels.  The sync signal is level sensitive.
        UINT32 lsbFirst             : 1;    // bit  1

        ///This active-high bit enables PCM loopback. For normal functional operation this bit should be cleared.
        ///An in-system test can be performed by using loopback mode in combination with master_pcm set.
        ///If the PCM_activate field (pcm_control_adr[0:0]) is set to 0, the interface will operate however none of the
        ///pins will toggle.
        UINT32 loopBack             : 1;    // bit  2

        ///This active-high bit enables the Bluetooth module to be master for the PCM interface.
        ///Default is slave to prevent contention with other devices
        UINT32 pcmSyncMaster        : 1;    // bit  3

        ///This active-high bit enables the PCM to long frame format, the default is short frame format.
        UINT32 frameTypeLong        : 1;    // bit  4

        ///PCM clock frequency control, selects whether the serial PCM bit stream is synchronized by a 128kHz, 256kHz,
        ///512kHz, 1024kHz and 2048kHz clock. The default value is 128kHz clock selection.
        UINT32 pcmBitClkRate        : 3;    // bit  7:5

        ///Set the number of fill bits. The total number of bits per slot is always sixteen.
        ///Unused bits will be filled as defined by fill[2:0]. Use the r_justify bit to define which end of the word is filled.
        UINT32 fillNum              : 2;    // bit  9:8

        ///Set the method of filling unused data bits
        UINT32 fill                 : 2;    // bit  11:10

        ///When fill is set to 11, these bits give the ability to apply up to a 3 bit fill sequence.
        UINT32 progFill             : 3;    // bit  14:12

        ///Set the data to right justify (fill data shifted out first). Default is left justify (fill data shifted out last).
        UINT32 rJustify             : 1;    // bit  15

        ///PCM channel 0 TDM slot selection, this allows channel 0 to be mapped to any of the 16 TDM slots.
        UINT32 ch0Sel               : 4;    // bit  19:16

        ///PCM channel 1 TDM slot selection, this allows channel 1 to be mapped to any of the 16 TDM slots.
        UINT32 ch1Sel               : 4;    // bit  23:20

        ///PCM channel 2 TDM slot selection, this allow CVS channel 2 map any of the 16 TDM slot.
        UINT32 ch2Sel               : 4;    // bit  27:24

        UINT32 ch0En                : 1;    //bit   28

        UINT32 ch1En                : 1;    //bit   29

        UINT32 ch2En                : 1;    //bit   30

        UINT32 dummy                : 1;    // bit  31
    } fields;
} CONTROL_ADR_TYPE;

typedef union
{
    UINT32 word;
    struct
    {
        ///Based on RTL comments, value of 00 is 8KHz, 01 is 16KHz, and 10 is 4KHz.
        ///The bits have something to do with the generation of WS.
        UINT32 pcmSampleSel         : 2;    // bit  1:0

        ///Set to 1 to enable I2C.
        UINT32 i2sEnable            : 1;    // bit  2

        UINT32 dummy                : 29;   // bit  31:3
    } fields;
} CONTROL_2_ADR_TYPE;

typedef union
{
    UINT32 word;
    struct
    {
        ///When 1, audio data comes from the FIFO.
        ///When 0, audio data comes from the PCM2/PCM/I2S deserializer (from the pin input).
        UINT32 audioDataOutSrcSel   : 1;    // bit  0

        ///Selects the source of the audio for the left and right channels.
        ///I don¡¦t know which is Left and which is Right, but if we say Left is 15:0 and Right is 31:16,
        ///then bits 4:3 select the Right channel number, and bits 2:1 select the Left channel number.
        ///The valid range for each channel number is 0-2.
        ///The reset value for these bits assigns channel 0 to Left and channel 1 to Right.
        UINT32 audioLrSrcSel        : 4;    // bit  4:1

        ///Controls the length of the Sync pulse. The counter counts on the tport_clock.
        ///The table below shows the value of this register,
        ///and the number of tport_clocks used for the length of the pulse.
        UINT32 syncFmPulseLength    : 2;    // bit  6:5

        UINT32 dummy                : 25;   // bit  31:7
    } fields;
} MISC_CTRL_ADR_TYPE;


typedef struct
{
    CONTROL_ADR_TYPE    control;
    CONTROL_2_ADR_TYPE  control2;
    MISC_CTRL_ADR_TYPE  miscCtrl;

    ///PCM channle FIFO threshold
    UINT32              chAeAfLevel;
}tPCM_CFG_TYPE;

void Pcm_Pcm(void);
void Pcm_reset(void);
void Pcm_init(void);
void Pcm_start(tPCM_CFG_TYPE* userConfig, void (*func)(UINT32));
int Pcm_handlePcmInterrupt(void* unused);
void Pcm_intConfig(UINT32 PcmWaterlineLevel, void (*func)(UINT32));
void Pcm_interuptEnable(void);
void Pcm_interruptDisable(void);
UINT8 Pcm_bufferRead(UINT16* readBuff,UINT16 buffLength, BYTE channelNum);
UINT8 Pcm_bufferWrite(UINT16* WriteBuff,UINT16 buffLength,BYTE channelNum);
UINT16 Pcm_getEmptySpace(UINT8 channelIndex);
UINT16 Pcm_getValidDataCount(UINT8 channelIndex);

#endif // end of #ifndef __PCM_DRIVER_H___
