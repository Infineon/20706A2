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
#ifndef _SPIFFY_H_
#define _SPIFFY_H_
/*******************************************************************************
*
* File Name: spiffy.h
*
* Abstract: SPIffy, Serial Peripheral Interface. Functional? Flexible? YES!
*
* Functions:
*
*******************************************************************************/
#include "data_types.h"

/*******************************************************************************
* Defines & Macros for SPIFFY block
*******************************************************************************/
// Spiffy Config
// Spiffy Config Bitmask
#define SPIFFY_CFG_SOFT_RESET                   0x00000001
#define SPIFFY_CFG_MODE_MASK                    0x00000006
#define SPIFFY_CFG_MODE_0                       0x00000000
#define SPIFFY_CFG_MODE_1                       0x00000002
#define SPIFFY_CFG_MODE_2                       0x00000004
#define SPIFFY_CFG_MODE_3                       0x00000006
#define SPIFFY_CFG_BYTE_ENDIANNESS_MASK         0x00000018
#define SPIFFY_CFG_BYTE_ENDIANNESS_LITTLE       0x00000000
#define SPIFFY_CFG_BYTE_ENDIANNESS_BIG_16       0x00000008
#define SPIFFY_CFG_BYTE_ENDIANNESS_BIG_32       0x00000010
#define SPIFFY_CFG_BIT_ENDIANNESS               0x00000020
#define SPIFFY_CFG_CS_POLARITY                  0x00000040
#define SPIFFY_CFG_INT_POLARITY                 0x00000080
#define SPIFFY_CFG_PROTOCOL_MASK                0x00000700
#define SPIFFY_CFG_PROTOCOL_GENERIC_SLAVE       0x00000000
#define SPIFFY_CFG_PROTOCOL_EMPSPI_SLAVE        0x00000100
#define SPIFFY_CFG_PROTOCOL_GENERIC_MASTER      0x00000200
#define SPIFFY_CFG_PROTOCOL_EMPSPI_MASTER       0x00000300
#define SPIFFY_CFG_TX_FIFO_EN                   0x00000800
#define SPIFFY_CFG_RX_FIFO_EN                   0x00001000
#define SPIFFY_CFG_FLOW_CONTROL_MASK            0x00006000
#define SPIFFY_CFG_FLOW_CONTROL_TX              0x00000000
#define SPIFFY_CFG_FLOW_CONTROL_RX              0x00002000
#define SPIFFY_CFG_FLOW_CONTROL_FD              0x00004000
#define SPIFFY_CFG_CS_OEN                       0x00008000
#define SPIFFY_CFG_CS_VAL                       0x00010000
#define SPIFFY_CFG_INT_OEN                      0x00020000
#define SPIFFY_CFG_INT_VAL                      0x00040000
#define SPIFFY_CFG_GO_TO_SLEEP                  0x00080000
#define SPIFFY_CFG_DELAY_INT                    0x00100000
#define SPIFFY_CFG_AUTO_CS                      0x00200000

// Tx Fifo Level Bitmasks
#define SPIFFY_TX_FIFO_LEVEL_MASK               0x000007FF

// Rx Fifo Level Bitmasks
#define SPIFFY_RX_FIFO_LEVEL_MASK               0x000007FF

// Interrupt Status and Enable Bitmasks
#define SPIFFY_INT_TX_AE                        0x00000001
#define SPIFFY_INT_TX_DONE                      0x00000002
#define SPIFFY_INT_TX_UNDERFLOW                 0x00000004
#define SPIFFY_INT_RX_AF                        0x00000008
#define SPIFFY_INT_RX_DONE                      0x00000010
#define SPIFFY_INT_RX_OVERFLOW                  0x00000020
#define SPIFFY_INT_CS_ACTIVE                    0x00000040
#define SPIFFY_INT_CS_INACTIVE                  0x00000080
#define SPIFFY_INT_DIRECT_WRITE_START           0x00000100
#define SPIFFY_INT_TX_EMPTY                     0x00000200
#define SPIFFY_INT_RX_FULL                      0x00000400
#define SPIFFY_INT_GENERIC_SPI_MASTER_DONE      0x00080000

// Clock Config Bitmasks and defines
#define SPIFFY_CLK_USE_TPORT                    0x00000001
#define SPIFFY_CLK_TPORT_CLOCK_DIV_MASK         0x0000003F
#define SPIFFY_CLK_TPORT_CLOCK_DIV_H_SHIFT      1
#define SPIFFY_CLK_TPORT_CLOCK_DIV_L_SHIFT      7

// Memory mapped structure of spiffy block
typedef struct
{
    volatile UINT32 cfg;                // 0x0000
    volatile UINT32 transmission_len;   // 0x0004
    volatile UINT32 tx_fifo_level;      // 0x0008
    volatile UINT32 tx_ae_level;        // 0x000C
    volatile UINT32 tx_dma_len;         // 0x0010
    volatile UINT32 rx_len;             // 0x0014
    volatile UINT32 rx_fifo_level;      // 0x0018
    volatile UINT32 rx_af_level;        // 0x001C
    volatile UINT32 rx_dma_len;         // 0x0020
    volatile UINT32 int_status;         // 0x0024
    volatile UINT32 int_enable;         // 0x0028
    volatile UINT32 status;             // 0x002C
    volatile UINT32 clock_cfg;          // 0x0030
#ifdef SPIFFY_16BYTE_FIFO
    volatile UINT32 unused_34_80[(0x80-0x34)/sizeof(UINT32)];
    volatile UINT32 rx_fifo;            // 0x0080
    volatile UINT32 RxFIFO[15];         // 0x0084..0x00BF
    volatile UINT32 tx_fifo;            // 0x00C0
    volatile UINT32 TxFIFO[15];         // 0x00C4..0x00FF
#else
    volatile UINT32 unused_34_100[(0x100-0x34)/sizeof(UINT32)];
    volatile UINT32 rx_fifo;            // 0x0100
    volatile UINT32 tx_fifo;            // 0x0104 or 0x120
#endif
}
tSPIFFY_BLOCK;

#define SPIFFY_MASTER_CLK_FREQ_IN_HZ            24000000
#define SPIFFY_MAX_INTEGRAL_DIVISOR_FREQ_IN_HZ  12000000
#define SPIFFY_MIN_INTEGRAL_DIVISOR_FREQ_IN_HZ     93750

#define SPIFFY_CLK_FREQ_12_MHZ                  12000000

#define SPIFFY_CLK_FREQ_6_MHZ                    6000000
#define SPIFFY_CLK_FREQ_3_MHZ                    3000000

#if defined(BCM20732)
#define SPIFFY_TX_FIFO_LEN      16
#define SPIFFY_RX_FIFO_LEN      16
#else
#define SPIFFY_TX_FIFO_LEN      256
#define SPIFFY_RX_FIFO_LEN      256
#endif

// If there is more than one spiffy block, a pointer passed into functions
// determines which spiffy block to operate on. The following macros
// automatically append "spiffyRegPtr" (and a preceeding comma and/or type
// when necessary) to function calls and function prototypes if and only if
// there is more than one spiffy.  If there is only one spiffy block, the
// static variable "spiffyRegPtr" is initialized to point to the only spiffy
// block, and is used by functions that operate on a spiffy block.
#if NUM_SPIFFY_BLOCKS > 1
#define SPIFFY_PTR_ONLY_ARG_OR_NOTHING          spiffyRegPtr
#define COMMA_AND_SPIFFY_PTR_ARG_OR_NOTHING     , SPIFFY_PTR_ONLY_ARG_OR_NOTHING
#define SPIFFY_PTR_ONLY_PARAM_OR_VOID           tSPIFFY_BLOCK *spiffyRegPtr
#define COMMA_AND_SPIFFY_PTR_PARAM_OR_NOTHING   , SPIFFY_PTR_ONLY_PARAM_OR_VOID
#else
#define SPIFFY_PTR_ONLY_ARG_OR_NOTHING
#define COMMA_AND_SPIFFY_PTR_ARG_OR_NOTHING
#define SPIFFY_PTR_ONLY_PARAM_OR_VOID           void
#define COMMA_AND_SPIFFY_PTR_PARAM_OR_NOTHING
#endif

#ifndef spiffy2_cfg_adr
#define spiffy2_cfg_adr spiffy2_spiffy_cfg_adr
#endif

// SPIFFY_VER 2 is for the new spiffy (spiffy v9) should be for 2076 and later
// SPIFFY_VER 1 is for 2074A0 only
// SPIFFY_VER 0 is for the old spiffy
#ifndef SPIFFY_VER
    #if defined(BCM20730)||defined(BCM20733) || defined(BCM20732)
    #define SPIFFY_VER 2
    #elif defined (BT_FW_AUDIO_CORE)
    #define SPIFFY_VER 1
    #else
    #define SPIFFY_VER 0
    #endif
#endif

#ifndef SPIFFY2_HW
    #if defined(BCM20730)||defined(BCM20733) || defined(BCM20732)
    #define SPIFFY2_HW
    #endif
#endif

#if defined (BCM4314) || defined (BCM4334) || defined (BCM43341) || defined SPIFFY_16BYTE_FIFO || defined(BCM43242) || defined(BCM20703)
// for 4314 This should be defined in ptu related .h
#define HW_PTU_HC_SEL_SPIFFY	0x20
#endif

//SPIFFY DETECT
#define HAVE_NO_SPIFFY 0
#define HAVE_SPIFFY1 0x01
#define HAVE_SPIFFY2 0x02
#define HAVE_SPIFFY1_N_SPIFFY2 0x03


/******************************************************************************
* Type Definitions
******************************************************************************/
typedef enum
{
    SPIFFY_LSB_FIRST = 0,
    SPIFFY_MSB_FIRST = SPIFFY_CFG_BIT_ENDIANNESS
} SPIFFY_ENDIAN;

typedef enum
{
    SPIFFY_SS_ACTIVE_LOW = 0,
    SPIFFY_SS_ACTIVE_HIGH = SPIFFY_CFG_CS_POLARITY
} SPIFFY_SS_POLARITY;

typedef enum
{
    SPIFFY_MODE_0 = SPIFFY_CFG_MODE_0,
    SPIFFY_MODE_1 = SPIFFY_CFG_MODE_1,
    SPIFFY_MODE_2 = SPIFFY_CFG_MODE_2,
    SPIFFY_MODE_3 = SPIFFY_CFG_MODE_3
} SPIFFY_MODE;

typedef enum
{
    SPIFFY_SUCCESS,
    SPIFFY_SLAVE_NOT_ENOUGH_RX_FIFO_BYTES
} SPIFFY_STATUS;


/*******************************************************************************
* externs
*******************************************************************************/
#if defined (BCM20730) || defined (BCM20733) || defined(BCM20732)
extern UINT8 spiffy_tx_fifo_fill_limit;
extern UINT8 spiffy_rx_fifo_fill_limit;
extern UINT8 enable_optimized_sfi_read;
#endif

#if defined (BCM20703)
extern UINT32 (*spiffy_fastReadSerialFlashPtr)(UINT32 addr, UINT32 len, UINT8* destPtr);
#endif

/*******************************************************************************
* Function Prototypes
*******************************************************************************/


void spiffy_soft_reset_check(UINT32 new_cfg_reg_value COMMA_AND_SPIFFY_PTR_PARAM_OR_NOTHING);
void spiffy_reset(UINT32 freq_in_hz, SPIFFY_ENDIAN endian, SPIFFY_SS_POLARITY pol,
                  SPIFFY_MODE mode COMMA_AND_SPIFFY_PTR_PARAM_OR_NOTHING);
void spiffy_txByte(UINT8 b COMMA_AND_SPIFFY_PTR_PARAM_OR_NOTHING);
void spiffy_txHalfWord(UINT16 h COMMA_AND_SPIFFY_PTR_PARAM_OR_NOTHING);
void spiffy_txWord(UINT32 w COMMA_AND_SPIFFY_PTR_PARAM_OR_NOTHING);
void spiffy_txBlock(UINT32 txTotalLen, UINT32 txLen, const UINT8 *txBuf, BOOL32 first,
                    BOOL32 last COMMA_AND_SPIFFY_PTR_PARAM_OR_NOTHING);
void spiffy_txrxBlock(UINT32 txLen, const UINT8* txBuf, UINT32 rxLen,
                      UINT8* rxBuf COMMA_AND_SPIFFY_PTR_PARAM_OR_NOTHING);
void spiffy_exchangeData(UINT32 len, const UINT8* txBuf,
                         UINT8* rxBuf COMMA_AND_SPIFFY_PTR_PARAM_OR_NOTHING);
void spiffy_txData(UINT32 txLen, const UINT8* txBuf COMMA_AND_SPIFFY_PTR_PARAM_OR_NOTHING);
void spiffy_rxData(UINT32 rxLen, UINT8* rxBuf COMMA_AND_SPIFFY_PTR_PARAM_OR_NOTHING);
void spiffy_slaveEnableTx(SPIFFY_PTR_ONLY_PARAM_OR_VOID);
void spiffy_slaveDisableTx(SPIFFY_PTR_ONLY_PARAM_OR_VOID);
void spiffy_slaveEnableRx(SPIFFY_PTR_ONLY_PARAM_OR_VOID);
void spiffy_slaveDisableRx(SPIFFY_PTR_ONLY_PARAM_OR_VOID);
void spiffy_slaveReset(SPIFFY_ENDIAN endian, SPIFFY_SS_POLARITY pol,
                  SPIFFY_MODE mode COMMA_AND_SPIFFY_PTR_PARAM_OR_NOTHING);
void spiffy_slaveTxData(UINT32 txLen,
                        const UINT8* txBuf COMMA_AND_SPIFFY_PTR_PARAM_OR_NOTHING);
void spiffy_slaveTxByte(UINT8 b COMMA_AND_SPIFFY_PTR_PARAM_OR_NOTHING);
void spiffy_slaveTxHalfWord(UINT16 h COMMA_AND_SPIFFY_PTR_PARAM_OR_NOTHING);
void spiffy_slaveTxWord(UINT32 w COMMA_AND_SPIFFY_PTR_PARAM_OR_NOTHING);
UINT32 spiffy_slaveGetTxFifoCount(SPIFFY_PTR_ONLY_PARAM_OR_VOID);
SPIFFY_STATUS spiffy_slaveRxData(UINT32 rxLen,
                                 UINT8* rxBuf COMMA_AND_SPIFFY_PTR_PARAM_OR_NOTHING);
UINT32 spiffy_slaveGetRxFifoCount(SPIFFY_PTR_ONLY_PARAM_OR_VOID);
UINT32 spiffy_detected(void);

#if defined (BCM20730) || defined (BCM20733) || defined(BCM20732)
BOOL32 spiffy_transferDone(SPIFFY_PTR_ONLY_PARAM_OR_VOID);
void spiffy_startTransfer(UINT32 len COMMA_AND_SPIFFY_PTR_PARAM_OR_NOTHING);
UINT32 spiffy_spiffy1ExtendedReadStart(UINT32 addr);
void spiffy_spiffy1ExtendedReadFinish(UINT32 save_pad_fcn_ctl2);
UINT32 spiffy_fastReadSerialFlash(UINT32 addr, UINT32 len, UINT8* destPtr);
#endif

#endif //  #ifndef _SPIFFY_H_
