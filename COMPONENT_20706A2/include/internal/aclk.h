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
