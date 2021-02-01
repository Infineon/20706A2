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
#ifndef _SFI_H_
#define _SFI_H_
/*******************************************************************************
*
* File Name: sfi.h
*
* Abstract: SFI, Serial Flash Interface
*
* Functions:
*
*******************************************************************************/

#include "types.h"

BOOL32 sfi_init(void);
UINT32 sfi_read(UINT32 addr, UINT32 len, UINT8 *buffer);
UINT32 sfi_write(UINT32 addr, UINT32 len, UINT8 *buffer);
UINT32 sfi_size(void);
void sfi_erase(UINT32 addr, UINT32 len);
void sfi_memcpy(UINT32 dest, UINT32 src, UINT32 len);
void sfi_deepPowerDownEnable(void);
void sfi_deepPowerDownDisable(void);
BOOL32 sfi_isSerialFlashdetected(void);
void sfi_enterDeepPowerDown(void);
void sfi_exitDeepPowerDown(void);

// SERIAL FLASH WRITE PROTECT SUPPORT

void sfi_SetWriteProtect_ON(void);
void sfi_SetWriteProtect_OFF(void);

/******************************************************************************
* Type Definitions
******************************************************************************/

typedef union
{
    UINT8  byte;
    struct
    {
        UINT8  SW_WP_Enable       : 1;    // bit    0   // enabled if set to 1
        UINT8  HW_WP_Enable       : 1;    // bit    1   //
        UINT8  HW_WP_Gpio         : 4;    // bits   2-5 // Gpio number 0-15
        UINT8  HID_Port_Plus_1    : 2;    // bits   6-7
    } fields;
} SF_WP_TYPE;

#pragma pack(1)
typedef PACKED struct
{
    UINT8 detected : 1;     // 1, if serial flash found
    UINT8 got_reset : 1;    // 1, if spi master hardware was reset
    UINT8 dont_pwr_dn : 1;  // 1, dont deep power down even if it's available
    UINT8 pwr_is_dn : 1;    // 1, if currently deep power down
    UINT8 pwr_dn_enable : 1; // 1, if deep power down enabled
    UINT8 use_default : 1;    // 1, if default command set is used
    UINT8 reserved : 2;
    UINT8 sf_index;         // index in sf_mem_table
    INT16 delay_cnt;     // delay count for Resume from Deep Power-down. 4 instructions per loop
} SF_STATUS;


typedef PACKED union
{
    UINT8 byte;
    PACKED struct
    {
        UINT8 extra_wrsr : 1;       // workaround for atmel serial flash
        UINT8 page_size_128 : 1; // ATMEL AT25F512 page_size=128, other ATMEL and MXIC, STM page_size=256
        UINT8 poll_btw_prog : 1;    // 1, poll status 0, fixed delay
        UINT8 poll_when_wrsr : 1;   // 1, if need to be conservative
        UINT8 use_ewsr : 1;         // 1, if need ewsr before executing wrsr
        UINT8 fast_read : 1;        // 1, if fast read supported
        UINT8 page_write : 1;       // 1, if page write supported
        UINT8 deep_pwr_dn : 1;      // 1, if can do deep power down

    } attr;

} SF_ATTRIB;
#pragma pack()

typedef struct
{
    UINT8 sig_len;
    UINT8 maker_id;
    UINT8 mem_type;
    UINT8 mem_cap;
    UINT8 size;                     // real size = 64KB * (size + 1), 0 = 64KB
    UINT8 t_RDP;                  // resume from Deep Power-down, in us.
    SF_ATTRIB mem_attr;

} SF_CFG_TABLE_ENTRY;

typedef struct
{
    UINT8 wren;            //write enable
    UINT8 wrdi;             //write disable
    UINT8 rdid;             //read identification
    UINT8 rdsr;             //read status register
    UINT8 wrsr;            //write status register
    UINT8 read;            //read data byte
    UINT8 fast_read;    //read data byte at higher speed
    UINT8 pw;                //page write
    UINT8 pp;                //page program
    UINT8 aai;               //auto address increment program - SST
    UINT8 ewsr;            //enable write status register - SST
    UINT8 pe;                //page erase
    UINT8 sse;               //sub-sector erase
    UINT8 se;                //sector erase
    UINT8 be;                //block erase
    UINT8 ce;                //chip erase
    UINT8 dp;                //deep power-down
    UINT8 res;               //release from deep power-down
} SF_CFG_COMMAND;

extern SF_WP_TYPE sfi_WriteProtectConfig;
extern SF_STATUS sf_status;
extern SF_ATTRIB sf_attr;
extern UINT8 sf_size;      // real size = 64KB * (size + 1), so 0 = 64KB
extern SF_WP_TYPE sfi_WriteProtectConfig;
// For combo chips which share sflash and eeprom pins,
// use this variable to determine if sflash is present.
extern BOOL8 serial_flash_allowed;

#if defined (BCM20703)
extern UINT32 spiffy2_clk_freq;
void spiffy2_setSpeed(UINT32 spiffyClkFreq);
#endif
#if defined (BCM20730) || defined (BCM20733) || defined(BCM20732)
extern UINT32 spiffy1_clk_freq;
void spiffy1_setSpeed(UINT32 spiffyClkFreq);
void sfi_writeBlock_spiffy2073(UINT32 addr, UINT32 len, UINT8 *buffer);
UINT32 sfi_read_spiffy2073(UINT32 addr, UINT32 len, UINT8 *buffer);
#endif

#if defined(BCM20730) || defined(BCM20732)
// SDA configuration uses bits [5:4] of cr_pad_fcn_ctl_adr1
#define CR_PAD_FCN_CTL1_SDA_MASK    0x0030
#define CR_PAD_FCN_CTL1_SDA_SHIFT   4
#define CR_PAD_FCN_CTL1_SDA_SPIFFY1_MOSI_SEL    1


// SCL configuration uses bits [1:0] of cr_pad_fcn_ctl_adr1
#define CR_PAD_FCN_CTL1_SCL_MASK            0x0003
#define CR_PAD_FCN_CTL1_SCL_SHIFT           0
#define CR_PAD_FCN_CTL1_SCL_SPIFFY1_CLK_SEL     1


// RXD configuration uses bits [9:8] of cr_pad_fcn_ctl_adr2
#define CR_PAD_FCN_CTL2_RXD_MASK            0x0300
#define CR_PAD_FCN_CTL2_RXD_SHIFT           8

// Spiffy1 miso configuration uses bits [7:6] of iocfg_premux_adr
#define IOCFG_PREMUX_SPIFFY1_MISO_MASK      0x00C0
#define IOCFG_PREMUX_SPIFFY1_MISO_SHIFT     6

// LHL iocfg_p#_adr pullup bit
#define LHL_IOCFG_PULLUP                    0x0400
#endif

#ifdef BCM20733
// SDA configuration uses bits [6:4] of cr_pad_fcn_ctl_adr1
#define CR_PAD_FCN_CTL1_SDA_MASK    0x0070
#define CR_PAD_FCN_CTL1_SDA_SHIFT   4
#define CR_PAD_FCN_CTL1_SDA_SPIFFY1_MOSI_SEL    2


// SCL configuration uses bits [2:0] of cr_pad_fcn_ctl_adr1
#define CR_PAD_FCN_CTL1_SCL_MASK            0x0007
#define CR_PAD_FCN_CTL1_SCL_SHIFT           0
#define CR_PAD_FCN_CTL1_SCL_SPIFFY1_CLK_SEL     2


// RXD configuration uses bits [10:8] of cr_pad_fcn_ctl_adr2
#define CR_PAD_FCN_CTL2_RXD_MASK            0x0700
#define CR_PAD_FCN_CTL2_RXD_SHIFT           8

// Spiffy1 miso configuration uses bits [7:6] of iocfg_premux_adr
#define IOCFG_PREMUX_SPIFFY1_MISO_MASK      0x00C0
#define IOCFG_PREMUX_SPIFFY1_MISO_SHIFT     6

// LHL iocfg_p#_adr pullup bit
#define LHL_IOCFG_PULLUP                    0x0400
#endif

#endif //  #ifndef _SFI_H_
