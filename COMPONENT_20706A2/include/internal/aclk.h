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
*    File Name: aclk.h
*
*    This file defines an aclk driver
*
********************************************************************
*/

#ifndef __ACLK_H__
#define __ACLK_H__

/** \addtogroup  ACLK
* \ingroup HardwareDrivers
*/
/*! @{ */
/**
* Defines an Aclk driver.
*/
enum
{
    HW_MIA_ACLK_CTL_ACLK0_SHIFT                     = 0,
    HW_MIA_ACLK_CTL_ACLK0_DIV_MASK                  = 0x000000FF,
    HW_MIA_ACLK_CTL_ACLK0_DIV_SHIFT                 = 0,
    HW_MIA_ACLK_CTL_ACLK0_POST_DIV_MASK             = 0x00000700,
    HW_MIA_ACLK_CTL_ACLK0_POST_DIV_SHIFT            = 8,
    HW_MIA_ACLK_CTL_ACLK0_ENABLE_MASK               = 0x00001000,
    HW_MIA_ACLK_CTL_ACLK0_ENABLE                    = 0x00001000,
    HW_MIA_ACLK_CTL_ACLK0_DISABLE                   = 0x00000000,
    HW_MIA_ACLK_CTL_ACLK0_CLK_SRC_SEL_MASK          = 0x00008000,
    HW_MIA_ACLK_CTL_ACLK0_CLK_SRC_24_MHZ            = 0x00008000,
    HW_MIA_ACLK_CTL_ACLK0_CLK_SRC_1_MHZ             = 0x00000000,
    HW_MIA_ACLK_CTL_ACLK0_MASK_ALL  = (HW_MIA_ACLK_CTL_ACLK0_DIV_MASK
                                       | HW_MIA_ACLK_CTL_ACLK0_POST_DIV_MASK
                                       | HW_MIA_ACLK_CTL_ACLK0_ENABLE_MASK
                                       | HW_MIA_ACLK_CTL_ACLK0_CLK_SRC_SEL_MASK),

    HW_MIA_ACLK_CTL_ACLK1_SHIFT                     = 16,
    HW_MIA_ACLK_CTL_ACLK1_DIV_MASK                  = 0x00FF0000,
    HW_MIA_ACLK_CTL_ACLK1_DIV_SHIFT                 = 16,
    HW_MIA_ACLK_CTL_ACLK1_POST_DIV_MASK             = 0x07000000,
    HW_MIA_ACLK_CTL_ACLK1_POST_DIV_SHIFT            = 24,
    HW_MIA_ACLK_CTL_ACLK1_ENABLE_MASK               = 0x10000000,
    HW_MIA_ACLK_CTL_ACLK1_ENABLE                    = 0x10000000,
    HW_MIA_ACLK_CTL_ACLK1_DISABLE                   = 0x00000000,
    HW_MIA_ACLK_CTL_ACLK1_CLK_SRC_SEL_MASK          = (int)0x80000000,
    HW_MIA_ACLK_CTL_ACLK1_CLK_SRC_24_MHZ            = (int)0x80000000,
    HW_MIA_ACLK_CTL_ACLK1_CLK_SRC_1_MHZ             = 0x00000000,
    HW_MIA_ACLK_CTL_ACLK1_MASK_ALL = (HW_MIA_ACLK_CTL_ACLK1_DIV_MASK
                                      | HW_MIA_ACLK_CTL_ACLK1_POST_DIV_MASK
                                      | HW_MIA_ACLK_CTL_ACLK1_ENABLE_MASK
                                      | HW_MIA_ACLK_CTL_ACLK1_CLK_SRC_SEL_MASK),
};

enum CLK_SRC_SEL
{
    ACLK0,
    ACLK1,
};

enum CLK_SRC_FREQ_SEL
{
    ACLK_FREQ_1_MHZ,
    ACLK_FREQ_24_MHZ
};

#ifdef __cplusplus
extern "C" {
#endif

void aclk_configure(UINT32 frequency, UINT32 src, UINT32 freqSel);
void aclk_disableClock(UINT32 src);

#ifdef BCM20703
void aclk_updateClkGating(void);
#endif

#ifdef __cplusplus
}
#endif

/* @}  */
#endif
