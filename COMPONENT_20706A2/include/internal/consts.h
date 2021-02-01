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
#ifndef __CONSTS_H_
#define __CONSTS_H_
/*******************************************************************************
*
* File Name: consts.h
*
* Abstract:  This file provides all the tunable global constants.
*
*
* Functions:
*
*******************************************************************************/

//////////////////////////////////////////////////////////////////////////////
//    Stack assertion.
//////////////////////////////////////////////////////////////////////////////
#define STACK_BOUNDARY_VALUE 0xEFEFEFEFUL


//////////////////////////////////////////////////////////////////////////////
//    idle thread related constants.
//////////////////////////////////////////////////////////////////////////////
// This is in 4 byte unit.
#ifndef IDLE_STACK_SIZE
#ifdef BCM2048
#define IDLE_STACK_SIZE             92
            /* IF THIS IS CHANGED, MUST UPDATE boot_load in boot_start.arm */
#else
#define IDLE_STACK_SIZE             145
            /* IF THIS IS CHANGED, MUST UPDATE boot_load in boot_start.arm */
#endif
#endif


//////////////////////////////////////////////////////////////////////////////
//  FM thread related constants.
//////////////////////////////////////////////////////////////////////////////
// This is in 4 byte unit.
#ifdef FM_NOISE_SUPRESSION
#define FM_NS_STACK_SIZE               1024
#else
#define FM_NS_STACK_SIZE               0
#endif
#ifndef CONFIG_GPS_FM_SHARED
#define FM_STACK_SIZE               92+FM_NS_STACK_SIZE
#else
#define FM_STACK_SIZE               (512/4)+FM_NS_STACK_SIZE
#endif


#ifdef AA_THREAD_ENABLED
//////////////////////////////////////////////////////////////////////////////
//    advanced audio thread related constants.
//////////////////////////////////////////////////////////////////////////////

#if    (defined(CONFIG_AAC_PLUS_DEC)||defined(CONFIG_MP3_DEC)||defined(CONFIG_MP3_ENC))
#define	MPEG_CODEC_STACK_SIZE	800		// dword
#else
#define	MPEG_CODEC_STACK_SIZE	0
#endif



#ifdef BEC_PLC_ENABLED
#define AA_STACK_SIZE               (326+MPEG_CODEC_STACK_SIZE)
#else
#define AA_STACK_SIZE               (180+MPEG_CODEC_STACK_SIZE)
#endif
#endif

//////////////////////////////////////////////////////////////////////////////
//    transport thread related constants.
//////////////////////////////////////////////////////////////////////////////
// Stack size is in 4 bytes unit.
#ifndef TRAN_STACK_SIZE
#define TRAN_STACK_SIZE            120
#endif

#ifdef ULP_ENABLE
#define TRAN_ACL_DATA_SIZE          (MM_ACL_DOWN_DEFAULT_CNT + MMULP_ACL_UP_DEFAULT_CNT)
#else
#define TRAN_ACL_DATA_SIZE          (MM_ACL_DOWN_DEFAULT_CNT)
#endif

// This queue sizes are in bytes. They need to be multiples of 4 which happens
// to be the size of a void * in 32 bit machine.
#ifndef TRAN_HCI_EVENT_QUEUE_SIZE
#define TRAN_HCI_EVENT_QUEUE_SIZE           ( (sizeof(void *)) * 31)
#endif
#define TRAN_ACL_DATA_QUEUE_SIZE            ( (sizeof(void *)) * 2*(TRAN_ACL_DATA_SIZE)) // need to take care of local loopback, 2-DWORD
#define TRAN_SCO_DATA_QUEUE_SIZE            ( (sizeof(void *)) * 3)
#define TRAN_DIAG_DATA_QUEUE_SIZE           ( (sizeof(void *)) * 20)
#define HCI_COMMAND_QUEUE_SIZE              ( (sizeof(void *)) * 8)
#if defined(UART_BRIDGE) && defined(UART_BRIDGE_UART2)
#define TRAN_UART_BRIDGE_NON_HCI_EVENT_QUEUE_SIZE  ( (sizeof(void *)) * 31)
#endif

// USB queue sizes
#ifdef UHE_CTRL_INTERFACE
#define TRAN_HID_USB_KB_DATA_QUEUE_SIZE     ( (sizeof(void *)) * 34)
#else
#define TRAN_HID_USB_KB_DATA_QUEUE_SIZE     ( (sizeof(void *)) * 16)
#endif

#ifdef UHE_CTRL_INTERFACE
#define TRAN_HID_USB_MS_EVENT_QUEUE_SIZE    ( (sizeof(void *)) * 20)
#else
#define TRAN_HID_USB_MS_EVENT_QUEUE_SIZE    ( (sizeof(void *)) * 12)
#endif


#define TRAN_HID_USB_MS_DATA_QUEUE_SIZE     ( (sizeof(void *)) * 1)
//To allow UHE application to send data to host over control endpoint
#define TRAN_HID_USB_MS_CTRL_QUEUE_SIZE        ( (sizeof(void *)) * 2)
#define TRAN_HID_USB_KB_CTRL_QUEUE_SIZE        ( (sizeof(void *)) * 2)

// Auxillary Data Queue sizes.
#ifdef TRANSQ_ENABLE
#define TRAN_HID_AUX_DATA_QUEUE_SIZE     ( (sizeof(void *)) * 64)
#endif


#if (defined(BB_2045B0) || defined(BB_2045B1))
  #ifdef SDIO_TRANSPORT
    #define CSA_TRANSPORT_HDR_BYTES          4
  #else
    #define CSA_TRANSPORT_HDR_BYTES          0
  #endif
#elif (defined(BT_FW_AUDIO_CORE) && !defined(CSA_STACK_EXCLUDED))
  #define CSA_TRANSPORT_HDR_BYTES            12
#else
  #define CSA_TRANSPORT_HDR_BYTES            0
#endif

#ifdef CONFIG_GPS_THREAD
#define TRAN_GPS_STATUS_QUEUE_SIZE          ( (sizeof(void *)) * 127)
#define TRAN_GPS_DIAG_QUEUE_SIZE          ( (sizeof(void *)) * 20)
#endif

#if defined(FM_ENABLE) && defined(NOKSYM_CH8_FM_CMD)
#define TRAN_NOKSYM_CH8_FM_EVENT_QUEUE_SIZE ( (sizeof(void *)) * 3)
#endif

//////////////////////////////////////////////////////////////////////////////
//    hci firmware related constants.
//////////////////////////////////////////////////////////////////////////////

//
// DSP related calculation such as PLC, MP3, VAD, SSP calculation, and other MIPS intensive
// calculation will be put into DSP_HI_THREAD and DSP_LOW_THREAD. The critiera to be
// in high or low DSP threads are:
// If the calculation duration is less than 5 ms (??), then put it into DSP_HI_THREAD;
// otherwise, put it into DSP_LOW_THREAD. To save RAM usage and reduce OS overhead,
// idle thread is used for DSP_LOW_THREAD. AA thread is used as DSP_HI_THREAD.
//
enum
{
    TRAN_THREAD_PRIORITY    = 7,
    DSP_HI_THREAD_PRIORITY  = 11,
    LM_THREAD_PRIORITY      = 15,
    CSA_THREAD_PRIORITY     = 19,
    FM_THREAD_PRIORITY      = 23,
    WLAN_THREAD_PRIORITY     = 26,
    GPS_THREAD_PRIORITY     = 27,
    IDLE_THREAD_PRIORITY    = 31,
    DSP_LOW_THREAD_PRIORITY = IDLE_THREAD_PRIORITY,
};

#ifdef MONITOR_IRQ_STACK_USAGE
#define IRQ_STACK_SIZE          TX_IRQ_STACK_SIZE_IN_BYTES  /* in Bytes, has to match the value defined in Tx_ill.arm */
#endif
#define STACK_FILL_PATTERN_WORD 0xEFEFEFEF


//////////////////////////////////////////////////////////////////////////////
//    lm thread related constants.
//////////////////////////////////////////////////////////////////////////////
// Stack size is in 4 bytes unit.

// feature specific call stack size definitions.
#ifdef SECURE_CONNECTIONS
// NOTE: Use based on other call stack add ins.
// Add 128(32 words) bytes only if secure connection specific code
// (MultPrecision.c algo)is in the critical path of LM
#define LM_CALL_STACK_MULT_PREC_ALGO_SIZE  (32)
#else
#define LM_CALL_STACK_MULT_PREC_ALGO_SIZE  (0)
#endif

#ifdef USE_CALL_STACK_FOR_SHA1
// TODO: Optimize
// 320 bytes if sha1 is in the critical path of LM
#define LM_CALL_STACK_SHA1_SIZE  (80)
#else
#define LM_CALL_STACK_SHA1_SIZE  (0)
#endif

// Inclusive Max value for the LM call stack add ins.
#define LM_CALL_STACK_ADD_IN                                         \
    ((LM_CALL_STACK_SHA1_SIZE > LM_CALL_STACK_MULT_PREC_ALGO_SIZE) ? \
      LM_CALL_STACK_SHA1_SIZE : LM_CALL_STACK_MULT_PREC_ALGO_SIZE)


#if defined(BT_FW_AUDIO_CORE)
#define LM_STACK_SIZE \
                (200 + 120) /* need to fine tune this value later */
#else
/* need to fine tune this value later */
#define LM_STACK_SIZE (160 + 80 + LM_CALL_STACK_ADD_IN)
#endif

//////////////////////////////////////////////////////////////////////////////
//    CSA thread size
//////////////////////////////////////////////////////////////////////////////
#ifdef RFCOMM_STACK_ENABLE
    #define CSA_THREAD_DEFAULT_STACK_SIZE_DWORDS (1024/4)
#else
#ifdef CSA_THR_SS_DW
    #define CSA_THREAD_DEFAULT_STACK_SIZE_DWORDS (800/4)
#else
    #ifdef UHE_ENABLE

        #ifdef BB_2046A0 /* This is a temp workaround till we have a better fix */
            #define CSA_THREAD_DEFAULT_STACK_SIZE_DWORDS (580/4)
        #else
            #define CSA_THREAD_DEFAULT_STACK_SIZE_DWORDS (800/4)
        #endif
    #else
        #define CSA_THREAD_DEFAULT_STACK_SIZE_DWORDS     (1024/4)
    #endif
#endif
#endif

//////////////////////////////////////////////////////////////////////////////
//
//  here are the features the Host Controller supports
//

#define BT1P2_FEATURE_LO  ( \
        RM_LMP_FEATURES_BYTE0_3_SLOT_PACKETS\
    |   RM_LMP_FEATURES_BYTE0_5_SLOT_PACKETS\
    |   RM_LMP_FEATURES_BYTE0_ENCRYPTION\
    |   RM_LMP_FEATURES_BYTE0_SLOT_OFFSET\
    |   RM_LMP_FEATURES_BYTE0_TIMING_ACCURACY\
    |   RM_LMP_FEATURES_BYTE0_ROLE_SWITCH\
    |   RM_LMP_FEATURES_BYTE0_HOLD_MODE\
    |   RM_LMP_FEATURES_BYTE0_SNIFF_MODE\
    |   RM_LMP_FEATURES_BYTE1_PARK_STATE\
    |   RM_LMP_FEATURES_BYTE1_POWER_CONTROL_REQUESTS\
    |   RM_LMP_FEATURES_BYTE1_CHANNEL_QUALITY_DRIVEN_DATA_RATE\
    |   RM_LMP_FEATURES_BYTE1_SCO_LINK\
    |   RM_LMP_FEATURES_BYTE1_HV2_PACKETS\
    |   RM_LMP_FEATURES_BYTE1_HV3_PACKETS\
    |   RM_LMP_FEATURES_BYTE1_U_LAW_LOG\
    |   RM_LMP_FEATURES_BYTE1_A_LAW_LOG\
    |   RM_LMP_FEATURES_BYTE2_CVSD\
    |   RM_LMP_FEATURES_BYTE2_PAGEING_PARAM_NEGOTIATION\
    |   RM_LMP_FEATURES_BYTE2_POWER_CONTROL\
    |   RM_LMP_FEATURES_BYTE2_TRANSPORT_SCO\
    |   RM_LMP_FEATURES_BYTE2_FLOW_CONTROL_LAG_MSB\
    |   RM_LMP_FEATURES_BYTE2_BROADCAST_ENCRYPTION\
    |   RM_LMP_FEATURES_BYTE3_ENHANCED_INQUIRY_SCAN\
    |   RM_LMP_FEATURES_BYTE3_INTERLACED_INQUIRY_SCAN\
    |   RM_LMP_FEATURES_BYTE3_INTERLACED_PAGE_SCAN\
    |   RM_LMP_FEATURES_BYTE3_RSSI_WITH_INQUIRY_RESULT\
    |   RM_LMP_FEATURES_BYTE3_EV3_PACKETS\
    )

#define BT1P2_FEATURE_HI  ( \
        RM_LMP_FEATURES_BYTE4_EV4_PACKETS\
    |   RM_LMP_FEATURES_BYTE4_EV5_PACKETS\
    |   RM_LMP_FEATURES_BYTE4_AFH_CAPABLE_SLAVE\
    |   RM_LMP_FEATURES_BYTE4_AFH_CLASSIFICATION_SLAVE\
    |   RM_LMP_FEATURES_BYTE5_AFH_CAPABLE_MASTER\
    |   RM_LMP_FEATURES_BYTE5_AFH_CLASSIFICATION_MASTER\
    |   RM_LMP_FEATURES_BYTE7_EXTENDED_FEATURES \
    )



#define BT2P0_FEATURE_LO  ( \
         BT1P2_FEATURE_LO \
     |   RM_LMP_FEATURES_BYTE3_EDR_ACL_2_Mb_MODE\
     |   RM_LMP_FEATURES_BYTE3_EDR_ACL_3_Mb_MODE\
     )

#define BT2P0_FEATURE_HI  ( \
         BT1P2_FEATURE_HI \
     |   RM_LMP_FEATURES_BYTE4_3_SLOT_EDR_ACL_PACKET\
     |   RM_LMP_FEATURES_BYTE5_5_SLOT_EDR_ACL_PACKET\
     |   RM_LMP_FEATURES_BYTE5_EDR_ESCO_2_Mb_MODE \
     |   RM_LMP_FEATURES_BYTE5_EDR_ESCO_3_Mb_MODE \
     |   RM_LMP_FEATURES_BYTE5_3_SLOT_EDR_ESCO_PACKET \
     )

#define BT2P1_FEATURE_LO  BT2P0_FEATURE_LO

#define BT2P1_FEATURE_HI  ( \
         BT2P0_FEATURE_HI \
     |   RM_LMP_FEATURES_BYTE5_SNIFF_SUBRATING \
     |   RM_LMP_FEATURES_BYTE5_EPR \
     |   RM_LMP_FEATURES_BYTE6_EIR \
     |   RM_LMP_FEATURES_BYTE6_ERRONEOUS_DATA_REPORTING \
     |   RM_LMP_FEATURES_BYTE6_SIMPLE_PAIRING \
     |   RM_LMP_FEATURES_BYTE6_ENCAP_PDU \
     |   RM_LMP_FEATURES_BYTE7_INQ_RESP_TX_PWR_LEVEL\
     |   RM_LMP_FEATURES_BYTE6_ENHANCED_FLUSH \
     |   RM_LMP_FEATURES_BYTE7_LSTO \
     )

#define BT3P0_FEATURE_LO  BT2P1_FEATURE_LO

#define BT3P0_FEATURE_HI  ( \
         BT2P1_FEATURE_HI \
     |   RM_LMP_FEATURES_BYTE7_EPC \
     )

//////////////////////////////////////////////////////////////////////////////
//
//  Local Version Information
//
//////////////////////////////////////////////////////////////////////////////
// Manufacturer
#define CONSTS_MANUFACTURER_ERISSON        0
#define CONSTS_MANUFACTURER_NOKIA          1
#define CONSTS_MANUFACTURER_INTEL          2
#define CONSTS_MANUFACTURER_IBM            3
#define CONSTS_MANUFACTURER_TOSHIBA        4
#define CONSTS_MANUFACTURER_3COM           5
#define CONSTS_MANUFACTURER_MICROSOFT      6
#define CONSTS_MANUFACTURER_LUCENT         7
#define CONSTS_MANUFACTURER_MOTOROLA       8
#define CONSTS_MANUFACTURER_INFINEON       9
#define CONSTS_MANUFACTURER_CSR            10
#define CONSTS_MANUFACTURER_SIWAVE         11
#define CONSTS_MANUFACTURER_DIGIANSWER     12
#define CONSTS_MANUFACTURER_TI             13
#define CONSTS_MANUFACTURER_PARTHUS        14
#define CONSTS_MANUFACTURER_BROADCOM       15
#define CONSTS_MANUFACTURER_MITEL          16
#define CONSTS_MANUFACTURER_WIDCOMM        17
#define CONSTS_MANUFACTURER_ZEEVO          18
#define CONSTS_MANUFACTURER_ATMEL          19
#define CONSTS_MANUFACTURER_MITSUBISHI     20
#define CONSTS_MANUFACTURER_RTX            21
#define CONSTS_MANUFACTURER_KC             22
#define CONSTS_MANUFACTURER_NEWLOGIC       23
#define CONSTS_MANUFACTURER_TRANSILLICA    24
#define CONSTS_MANUFACTURER_ROHDE_SCHWARTZ 25
#define CONSTS_MANUFACTURER_TTPCOM         26
#define CONSTS_MANUFACTURER_SIGNIA         27
#define CONSTS_MANUFACTURER_CONEXANT       28
#define CONSTS_MANUFACTURER_QUALCOMM       29
#define CONSTS_MANUFACTURER_INVENTEL       30
#define CONSTS_MANUFACTURER_AVM_BERLIN     31
#define CONSTS_MANUFACTURER_BANDSPEED      32
#define CONSTS_MANUFACTURER_MANSELLA       33
#define CONSTS_MANUFACTURER_NEC            34
#define CONSTS_MANUFACTURER_WAVEPLUS       35
#define CONSTS_MANUFACTURER_ALCATEL        36
#define CONSTS_MANUFACTURER_PHILIPS        37
#define CONSTS_MANUFACTURER_C_TECHNOLOGIES 38
#define CONSTS_MANUFACTURER_OPEN_INTERFACE 39
#define CONSTS_MANUFACTURER_RF_MICRO       40
#define CONSTS_MANUFACTURER_HITACHI        41
#define CONSTS_MANUFACTURER_SYMBOL_TECH    42
#define CONSTS_MANUFACTURER_TENOVIS        43
#define CONSTS_MANUFACTURER_MACRONIX       44
#define CONSTS_MANUFACTURER_GCT            45
#define CONSTS_MANUFACTURER_NORWOOD        46
#define CONSTS_MANUFACTURER_MEWTEL         47
#define CONSTS_MANUFACTURER_ST_MICRO       48
#define CONSTS_MANUFACTURER_SYNOPSYS       49
#define CONSTS_MANUFACTURER_RED_M          50
#define CONSTS_MANUFACTURER_COMMIL         51
#define CONSTS_MANUFACTURER_CATC           52
#define CONSTS_MANUFACTURER_ECLIPSE        53
#define CONSTS_MANUFACTURER_RENESAS        54
#define CONSTS_MANUFACTURER_MOBILIAN       55
#define CONSTS_MANUFACTURER_TERAX          56
#define CONSTS_MANUFACTURER_ISSC           57
#define CONSTS_MANUFACTURER_MATSUSHITA     58
#define CONSTS_MANUFACTURER_GENNUM         59

// LMP Version
#define CONSTS_BLUETOOTH_LMP_VER_1_0B      0
#define CONSTS_BLUETOOTH_LMP_VER_1_1       1
#define CONSTS_BLUETOOTH_LMP_VER_1_2       2
#define CONSTS_BLUETOOTH_LMP_VER_2_0       3
#define CONSTS_BLUETOOTH_LMP_VER_2_1       4
#define CONSTS_BLUETOOTH_LMP_VER_3_0       5
#define CONSTS_BLUETOOTH_LMP_VER_4_0       6
#define CONSTS_BLUETOOTH_LMP_VER_4_1       7

// HCI Version
#define CONSTS_BLUETOOTH_HCI_VER_1_0B      0
#define CONSTS_BLUETOOTH_HCI_VER_1_1       1
#define CONSTS_BLUETOOTH_HCI_VER_1_2       2
#define CONSTS_BLUETOOTH_HCI_VER_2_0       3
#define CONSTS_BLUETOOTH_HCI_VER_2_1       4
#define CONSTS_BLUETOOTH_HCI_VER_3_0       5
#define CONSTS_BLUETOOTH_HCI_VER_4_0       6
#define CONSTS_BLUETOOTH_HCI_VER_4_1       7


//////////////////////////////////////////////////////////////////////////////
//
//  Local Buffer Sizes
//
//////////////////////////////////////////////////////////////////////////////

// this is the host controller's sco buffer size
#define CONSTS_HC_SCO_BUFFER_SIZE           64
#define CONSTS_HC_OLYMPIC_SCO_BUFFER_SIZE  192
// this is the host controller's sco buffer count
// 0 means we don't flow control the Host.
#define CONSTS_HC_SCO_BUFFER_COUNT          1

//////////////////////////////////////////////////////////////////////////////
//
//  Vendor Specific Features supported by the Controller
//
//////////////////////////////////////////////////////////////////////////////
#define VSC_DEFAULT_FEATURES                0
#if defined MULTI_AV_ENABLE
#define VSC_FEATURES_MULTI_AV               1
#else
#define VSC_FEATURES_MULTI_AV               0
#endif
#if defined AA_WBS_SBC
#define VSC_FEATURES_WBS_SBC                2
#else
#define VSC_FEATURES_WBS_SBC                0
#endif
#if defined PLC_LC_ENABLED
#define VSC_FEATURES_FW_LC_PLC              4
#else
#define VSC_FEATURES_FW_LC_PLC              0
#endif
#ifdef LITE_HOST
#define VSC_FEATURES_FM_SBC_INTERNAL_STACK  8
#else
#define VSC_FEATURES_FM_SBC_INTERNAL_STACK  0
#endif
#ifdef NFC_ENABLED
#define VSC_FEATURES_NFC                    0x10
#else
#define VSC_FEATURES_NFC                    0
#endif

#ifdef AUDIO_DAC_160MS_DELAY
#define VSC_FEATURES_AUDIO_DAC_PS  0x20
#else
#define VSC_FEATURES_AUDIO_DAC_PS  0
#endif



#define VSC_FEATURES0   ( \
                VSC_FEATURES_MULTI_AV \
            |	VSC_FEATURES_WBS_SBC \
            |   VSC_FEATURES_FW_LC_PLC \
            |   VSC_FEATURES_FM_SBC_INTERNAL_STACK \
            |   VSC_FEATURES_NFC \
            |   VSC_FEATURES_AUDIO_DAC_PS \
            )

#define VSC_FEATURES1           ( \
                VSC_DEFAULT_FEATURES \
            )


/*
*******************************************************************************
*
* $HISTORY:$
*
*******************************************************************************
*/
#endif // end of #ifndef __CONSTS_H_
