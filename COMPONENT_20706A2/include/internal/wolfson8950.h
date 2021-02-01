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
*    File Name: wolfson8950.h
*
*    $History:$
*
********************************************************************
*/
#ifndef __WOLFSON8950_H__
#define __WOLFSON8950_H__

#include "audiocodec_interface.h"
#include "i2cm.h"

#define WOLFSON_2WIRE_ADDR 0x34

/*
 * Register values.
 */
#define WM8950_SOFTWARE_RESET                   0x00
#define WM8950_POWER_MANAGEMENT_1               0x01
#define WM8950_POWER_MANAGEMENT_2               0x02
#define WM8950_AUDIO_INTERFACE                  0x04
#define WM8950_COMPANDING_CONTROL               0x05
#define WM8950_CLOCK_GEN_CONTROL                0x06
#define WM8950_ADDITIONAL_CONTROL               0x07
#define WM8950_GPIO_STUFF                       0x08
#define WM8950_ADC_CONTROL                      0x0E
#define WM8950_LEFT_DIG_ADC_VOL                 0x0F
#define WM8950_EQ1_LOW_SHELF                    0x12
#define WM8950_EQ2_PEAK_1                       0x13
#define WM8950_EQ3_PEAK_2                       0x14
#define WM8950_EQ4_PEAK_3                       0x15
#define WM8950_EQ5_HIGH_SHELF                   0x16
#define WM8950_NOTCH_FILTER_1                   0x1B
#define WM8950_NOTCH_FILTER_2                   0x1C
#define WM8950_NOTCH_FILTER_3                   0x1D
#define WM8950_NOTCH_FILTER_4                   0x1E
#define WM8950_ALC_CONTROL_1                    0x20
#define WM8950_ALC_CONTROL_2                    0x21
#define WM8950_ALC_CONTROL_3                    0x22
#define WM8950_NOISE_GATE                       0x23
#define WM8950_PLL_N                            0x24
#define WM8950_PLL_K_1                          0x25
#define WM8950_PLL_K_2                          0x26
#define WM8950_PLL_K_3                          0x27
#define WM8950_INPUT_CTRL                       0x2C
#define WM8950_LEFT_INP_PGA_GAIN_CTRL           0x2D
#define WM8950_LEFT_ADC_BOOST_CTRL              0x2F
#define WM8950_OUTPUT_CTRL                      0x31

#define WM8950_MAX_REGISTER                     0x31

/*
 * Field Definitions.
 */

/*
 * R0 (0x00) - Software Reset
 */
#define WM8950_SOFTWARE_RESET_MASK              0x01FF  /* SOFTWARE RESET - [8:0] */
#define WM8950_SOFTWARE_RESET_SHIFT                  0  /* SOFTWARE RESET - [8:0] */
#define WM8950_SOFTWARE_RESET_WIDTH                  9  /* SOFTWARE RESET - [8:0] */

/*
 * R1 (0x01) - Power management 1
 */
#define WM8950_AUXEN                            0x0040  /* AUXEN */
#define WM8950_AUXEN_MASK                       0x0040  /* AUXEN */
#define WM8950_AUXEN_SHIFT                           6  /* AUXEN */
#define WM8950_AUXEN_WIDTH                           1  /* AUXEN */
#define WM8950_PLLEN                            0x0020  /* PLLEN */
#define WM8950_PLLEN_MASK                       0x0020  /* PLLEN */
#define WM8950_PLLEN_SHIFT                           5  /* PLLEN */
#define WM8950_PLLEN_WIDTH                           1  /* PLLEN */
#define WM8950_MICBEN                           0x0010  /* MICBEN */
#define WM8950_MICBEN_MASK                      0x0010  /* MICBEN */
#define WM8950_MICBEN_SHIFT                          4  /* MICBEN */
#define WM8950_MICBEN_WIDTH                          1  /* MICBEN */
#define WM8950_BIASEN                           0x0008  /* BIASEN */
#define WM8950_BIASEN_MASK                      0x0008  /* BIASEN */
#define WM8950_BIASEN_SHIFT                          3  /* BIASEN */
#define WM8950_BIASEN_WIDTH                          1  /* BIASEN */
#define WM8950_BUFIOEN                          0x0004  /* BUFIOEN */
#define WM8950_BUFIOEN_MASK                     0x0004  /* BUFIOEN */
#define WM8950_BUFIOEN_SHIFT                         2  /* BUFIOEN */
#define WM8950_BUFIOEN_WIDTH                         1  /* BUFIOEN */
#define WM8950_VMIDSEL_MASK                     0x0003  /* VMIDSEL - [1:0] */
#define WM8950_VMIDSEL_SHIFT                         0  /* VMIDSEL - [1:0] */
#define WM8950_VMIDSEL_WIDTH                         2  /* VMIDSEL - [1:0] */

/*
 * R2 (0x02) - Power management 2
 */
#define WM8950_BOOSTEN                          0x0010  /* BOOSTEN */
#define WM8950_BOOSTEN_MASK                     0x0010  /* BOOSTEN */
#define WM8950_BOOSTEN_SHIFT                         4  /* BOOSTEN */
#define WM8950_BOOSTEN_WIDTH                         1  /* BOOSTEN */
#define WM8950_INPPGAEN                         0x0004  /* INPPGAEN */
#define WM8950_INPPGAEN_MASK                    0x0004  /* INPPGAEN */
#define WM8950_INPPGAEN_SHIFT                        2  /* INPPGAEN */
#define WM8950_INPPGAEN_WIDTH                        1  /* INPPGAEN */
#define WM8950_ADCEN                            0x0001  /* ADCEN */
#define WM8950_ADCEN_MASK                       0x0001  /* ADCEN */
#define WM8950_ADCEN_SHIFT                           0  /* ADCEN */
#define WM8950_ADCEN_WIDTH                           1  /* ADCEN */

/*
 * R4 (0x04) - Audio Interface
 */
#define WM8950_BCP                              0x0100  /* BCP */
#define WM8950_BCP_MASK                         0x0100  /* BCP */
#define WM8950_BCP_SHIFT                             8  /* BCP */
#define WM8950_BCP_WIDTH                             1  /* BCP */
#define WM8950_FRAMEP                           0x0080  /* FRAMEP */
#define WM8950_FRAMEP_MASK                      0x0080  /* FRAMEP */
#define WM8950_FRAMEP_SHIFT                          7  /* FRAMEP */
#define WM8950_FRAMEP_WIDTH                          1  /* FRAMEP */
#define WM8950_WL_MASK                          0x0060  /* WL - [6:5] */
#define WM8950_WL_SHIFT                              5  /* WL - [6:5] */
#define WM8950_WL_WIDTH                              2  /* WL - [6:5] */
#define WM8950_FMT_MASK                         0x0018  /* FMT - [4:3] */
#define WM8950_FMT_SHIFT                             3  /* FMT - [4:3] */
#define WM8950_FMT_WIDTH                             2  /* FMT - [4:3] */
#define WM8950_ALRSWAP                          0x0002  /* ALRSWAP */
#define WM8950_ALRSWAP_MASK                     0x0002  /* ALRSWAP */
#define WM8950_ALRSWAP_SHIFT                         1  /* ALRSWAP */
#define WM8950_ALRSWAP_WIDTH                         1  /* ALRSWAP */

/*
 * R5 (0x05) - Companding control
 */
#define WM8950_ADC_COMP_MASK                    0x0006  /* ADC_COMP - [2:1] */
#define WM8950_ADC_COMP_SHIFT                        1  /* ADC_COMP - [2:1] */
#define WM8950_ADC_COMP_WIDTH                        2  /* ADC_COMP - [2:1] */

/*
 * R6 (0x06) - Clock Gen control
 */
#define WM8950_CLKSEL                           0x0100  /* CLKSEL */
#define WM8950_CLKSEL_MASK                      0x0100  /* CLKSEL */
#define WM8950_CLKSEL_SHIFT                          8  /* CLKSEL */
#define WM8950_CLKSEL_WIDTH                          1  /* CLKSEL */
#define WM8950_MCLKDIV_MASK                     0x00E0  /* MCLKDIV - [7:5] */
#define WM8950_MCLKDIV_SHIFT                         5  /* MCLKDIV - [7:5] */
#define WM8950_MCLKDIV_WIDTH                         3  /* MCLKDIV - [7:5] */
#define WM8950_BCLKDIV_MASK                     0x001C  /* BCLKDIV - [4:2] */
#define WM8950_BCLKDIV_SHIFT                         2  /* BCLKDIV - [4:2] */
#define WM8950_BCLKDIV_WIDTH                         3  /* BCLKDIV - [4:2] */
#define WM8950_MS                               0x0001  /* MS */
#define WM8950_MS_MASK                          0x0001  /* MS */
#define WM8950_MS_SHIFT                              0  /* MS */
#define WM8950_MS_WIDTH                              1  /* MS */

/*
 * R7 (0x07) - Additional control
 */
#define WM8950_SR                               0x000E  /* SR */   // MZ : Changed from 0x0008 according to the spec register map
#define WM8950_SR_MASK                          0x000E  /* SR */   // MZ : Changed from 0x0008 according to the spec register map
#define WM8950_SR_SHIFT                              1  /* SR */   // MZ : Changed from 3          according to the spec register map
#define WM8950_SR_WIDTH                              1  /* SR */
#define WM8950_SLOWCLKEN                        0x0001  /* SLOWCLKEN */
#define WM8950_SLOWCLKEN_MASK                   0x0001  /* SLOWCLKEN */
#define WM8950_SLOWCLKEN_SHIFT                       0  /* SLOWCLKEN */
#define WM8950_SLOWCLKEN_WIDTH                       1  /* SLOWCLKEN */

/*
 * R8 (0x08) - GPIO Stuff
 */
#define WM8950_OPCLKDIV_MASK                    0x0030  /* OPCLKDIV - [5:4] */
#define WM8950_OPCLKDIV_SHIFT                        4  /* OPCLKDIV - [5:4] */
#define WM8950_OPCLKDIV_WIDTH                        2  /* OPCLKDIV - [5:4] */
#define WM8950_GPIOPOL                          0x0008  /* GPIOPOL */
#define WM8950_GPIOPOL_MASK                     0x0008  /* GPIOPOL */
#define WM8950_GPIOPOL_SHIFT                         3  /* GPIOPOL */
#define WM8950_GPIOPOL_WIDTH                         1  /* GPIOPOL */
#define WM8950_GPIOSEL_MASK                     0x0007  /* GPIOSEL - [2:0] */
#define WM8950_GPIOSEL_SHIFT                         0  /* GPIOSEL - [2:0] */
#define WM8950_GPIOSEL_WIDTH                         3  /* GPIOSEL - [2:0] */

/*
 * R14 (0x0E) - ADC Control
 */
#define WM8950_HPFEN                            0x0100  /* HPFEN */
#define WM8950_HPFEN_MASK                       0x0100  /* HPFEN */
#define WM8950_HPFEN_SHIFT                           8  /* HPFEN */
#define WM8950_HPFEN_WIDTH                           1  /* HPFEN */
#define WM8950_HPFAPP                           0x0080  /* HPFAPP */
#define WM8950_HPFAPP_MASK                      0x0080  /* HPFAPP */
#define WM8950_HPFAPP_SHIFT                          7  /* HPFAPP */
#define WM8950_HPFAPP_WIDTH                          1  /* HPFAPP */
#define WM8950_HPFCUT_MASK                      0x0070  /* HPFCUT - [6:4] */
#define WM8950_HPFCUT_SHIFT                          4  /* HPFCUT - [6:4] */
#define WM8950_HPFCUT_WIDTH                          3  /* HPFCUT - [6:4] */
#define WM8950_ADCOSR128                        0x0008  /* ADCOSR128 */
#define WM8950_ADCOSR128_MASK                   0x0008  /* ADCOSR128 */
#define WM8950_ADCOSR128_SHIFT                       3  /* ADCOSR128 */
#define WM8950_ADCOSR128_WIDTH                       1  /* ADCOSR128 */
#define WM8950_ADCLPOL                          0x0001  /* ADCLPOL */
#define WM8950_ADCLPOL_MASK                     0x0001  /* ADCLPOL */
#define WM8950_ADCLPOL_SHIFT                         0  /* ADCLPOL */
#define WM8950_ADCLPOL_WIDTH                         1  /* ADCLPOL */

/*
 * R15 (0x0F) - Left Dig ADC Vol
 */
#define WM8950_ADCLVOL_MASK                     0x00FF  /* ADCLVOL - [7:0] */
#define WM8950_ADCLVOL_SHIFT                         0  /* ADCLVOL - [7:0] */
#define WM8950_ADCLVOL_WIDTH                         8  /* ADCLVOL - [7:0] */

/*
 * R18 (0x12) - EQ1 - low shelf
 */
#define WM8950_EQ1C_MASK                        0x0060  /* EQ1C - [6:5] */
#define WM8950_EQ1C_SHIFT                            5  /* EQ1C - [6:5] */
#define WM8950_EQ1C_WIDTH                            2  /* EQ1C - [6:5] */
#define WM8950_EQ1G_MASK                        0x001F  /* EQ1G - [4:0] */
#define WM8950_EQ1G_SHIFT                            0  /* EQ1G - [4:0] */
#define WM8950_EQ1G_WIDTH                            5  /* EQ1G - [4:0] */

/*
 * R19 (0x13) - EQ2 - peak 1
 */
#define WM8950_EQ2BW                            0x0100  /* EQ2BW */
#define WM8950_EQ2BW_MASK                       0x0100  /* EQ2BW */
#define WM8950_EQ2BW_SHIFT                           8  /* EQ2BW */
#define WM8950_EQ2BW_WIDTH                           1  /* EQ2BW */
#define WM8950_EQ2C_MASK                        0x0060  /* EQ2C - [6:5] */
#define WM8950_EQ2C_SHIFT                            5  /* EQ2C - [6:5] */
#define WM8950_EQ2C_WIDTH                            2  /* EQ2C - [6:5] */
#define WM8950_EQ2G_MASK                        0x001F  /* EQ2G - [4:0] */
#define WM8950_EQ2G_SHIFT                            0  /* EQ2G - [4:0] */
#define WM8950_EQ2G_WIDTH                            5  /* EQ2G - [4:0] */

/*
 * R20 (0x14) - EQ3 - peak 2
 */
#define WM8950_EQ3BW                            0x0100  /* EQ3BW */
#define WM8950_EQ3BW_MASK                       0x0100  /* EQ3BW */
#define WM8950_EQ3BW_SHIFT                           8  /* EQ3BW */
#define WM8950_EQ3BW_WIDTH                           1  /* EQ3BW */
#define WM8950_EQ3C_MASK                        0x0060  /* EQ3C - [6:5] */
#define WM8950_EQ3C_SHIFT                            5  /* EQ3C - [6:5] */
#define WM8950_EQ3C_WIDTH                            2  /* EQ3C - [6:5] */
#define WM8950_EQ3G_MASK                        0x001F  /* EQ3G - [4:0] */
#define WM8950_EQ3G_SHIFT                            0  /* EQ3G - [4:0] */
#define WM8950_EQ3G_WIDTH                            5  /* EQ3G - [4:0] */

/*
 * R21 (0x15) - EQ4 - peak 3
 */
#define WM8950_EQ4BW                            0x0100  /* EQ4BW */
#define WM8950_EQ4BW_MASK                       0x0100  /* EQ4BW */
#define WM8950_EQ4BW_SHIFT                           8  /* EQ4BW */
#define WM8950_EQ4BW_WIDTH                           1  /* EQ4BW */
#define WM8950_EQ4C_MASK                        0x0060  /* EQ4C - [6:5] */
#define WM8950_EQ4C_SHIFT                            5  /* EQ4C - [6:5] */
#define WM8950_EQ4C_WIDTH                            2  /* EQ4C - [6:5] */
#define WM8950_EQ4G_MASK                        0x001F  /* EQ4G - [4:0] */
#define WM8950_EQ4G_SHIFT                            0  /* EQ4G - [4:0] */
#define WM8950_EQ4G_WIDTH                            5  /* EQ4G - [4:0] */

/*
 * R22 (0x16) - EQ5 - high shelf
 */
#define WM8950_EQ5C_MASK                        0x0060  /* EQ5C - [6:5] */
#define WM8950_EQ5C_SHIFT                            5  /* EQ5C - [6:5] */
#define WM8950_EQ5C_WIDTH                            2  /* EQ5C - [6:5] */
#define WM8950_EQ5G_MASK                        0x001F  /* EQ5G - [4:0] */
#define WM8950_EQ5G_SHIFT                            0  /* EQ5G - [4:0] */
#define WM8950_EQ5G_WIDTH                            5  /* EQ5G - [4:0] */

/*
 * R27 (0x1B) - Notch Filter 1
 */
#define WM8950_NFU                              0x0100  /* NFU */
#define WM8950_NFU_MASK                         0x0100  /* NFU */
#define WM8950_NFU_SHIFT                             8  /* NFU */
#define WM8950_NFU_WIDTH                             1  /* NFU */
#define WM8950_NFEN                             0x0080  /* NFEN */
#define WM8950_NFEN_MASK                        0x0080  /* NFEN */
#define WM8950_NFEN_SHIFT                            7  /* NFEN */
#define WM8950_NFEN_WIDTH                            1  /* NFEN */
#define WM8950_NFA0_0_MASK                      0x007F  /* NFA0 - [6:0] */
#define WM8950_NFA0_0_SHIFT                          0  /* NFA0 - [6:0] */
#define WM8950_NFA0_0_WIDTH                          7  /* NFA0 - [6:0] */

/*
 * R28 (0x1C) - Notch Filter 2
 */
#define WM8950_NFU                              0x0100  /* NFU */
#define WM8950_NFU_MASK                         0x0100  /* NFU */
#define WM8950_NFU_SHIFT                             8  /* NFU */
#define WM8950_NFU_WIDTH                             1  /* NFU */
#define WM8950_NFA0_MASK                        0x007F  /* NFA0 - [6:0] */
#define WM8950_NFA0_SHIFT                            0  /* NFA0 - [6:0] */
#define WM8950_NFA0_WIDTH                            7  /* NFA0 - [6:0] */

/*
 * R29 (0x1D) - Notch Filter 3
 */
#define WM8950_NFU                              0x0100  /* NFU */
#define WM8950_NFU_MASK                         0x0100  /* NFU */
#define WM8950_NFU_SHIFT                             8  /* NFU */
#define WM8950_NFU_WIDTH                             1  /* NFU */
#define WM8950_NFA1_0_MASK                      0x007F  /* NFA1 - [6:0] */
#define WM8950_NFA1_0_SHIFT                          0  /* NFA1 - [6:0] */
#define WM8950_NFA1_0_WIDTH                          7  /* NFA1 - [6:0] */

/*
 * R30 (0x1E) - Notch Filter 4
 */
#define WM8950_NFU                              0x0100  /* NFU */
#define WM8950_NFU_MASK                         0x0100  /* NFU */
#define WM8950_NFU_SHIFT                             8  /* NFU */
#define WM8950_NFU_WIDTH                             1  /* NFU */
#define WM8950_NFA1_MASK                        0x007F  /* NFA1 - [6:0] */
#define WM8950_NFA1_SHIFT                            0  /* NFA1 - [6:0] */
#define WM8950_NFA1_WIDTH                            7  /* NFA1 - [6:0] */

/*
 * R32 (0x20) - ALC control 1
 */
#define WM8950_ALCSEL                           0x0100  /* ALCSEL */
#define WM8950_ALCSEL_MASK                      0x0100  /* ALCSEL */
#define WM8950_ALCSEL_SHIFT                          8  /* ALCSEL */
#define WM8950_ALCSEL_WIDTH                          1  /* ALCSEL */
#define WM8950_ALCMAX_MASK                      0x0038  /* ALCMAX - [5:3] */
#define WM8950_ALCMAX_SHIFT                          3  /* ALCMAX - [5:3] */
#define WM8950_ALCMAX_WIDTH                          3  /* ALCMAX - [5:3] */
#define WM8950_ALCMIN_MASK                      0x0007  /* ALCMIN - [2:0] */
#define WM8950_ALCMIN_SHIFT                          0  /* ALCMIN - [2:0] */
#define WM8950_ALCMIN_WIDTH                          3  /* ALCMIN - [2:0] */

/*
 * R33 (0x21) - ALC control 2
 */
#define WM8950_ALCZC                            0x0100  /* ALCZC */
#define WM8950_ALCZC_MASK                       0x0100  /* ALCZC */
#define WM8950_ALCZC_SHIFT                           8  /* ALCZC */
#define WM8950_ALCZC_WIDTH                           1  /* ALCZC */
#define WM8950_ALCHLD_MASK                      0x00F0  /* ALCHLD - [7:4] */
#define WM8950_ALCHLD_SHIFT                          4  /* ALCHLD - [7:4] */
#define WM8950_ALCHLD_WIDTH                          4  /* ALCHLD - [7:4] */
#define WM8950_ALCLVL_MASK                      0x000F  /* ALCLVL - [3:0] */
#define WM8950_ALCLVL_SHIFT                          0  /* ALCLVL - [3:0] */
#define WM8950_ALCLVL_WIDTH                          4  /* ALCLVL - [3:0] */

/*
 * R34 (0x22) - ALC control 3
 */
#define WM8950_ALCMODE                          0x0100  /* ALCMODE */
#define WM8950_ALCMODE_MASK                     0x0100  /* ALCMODE */
#define WM8950_ALCMODE_SHIFT                         8  /* ALCMODE */
#define WM8950_ALCMODE_WIDTH                         1  /* ALCMODE */
#define WM8950_ALCDCY_MASK                      0x00F0  /* ALCDCY - [7:4] */
#define WM8950_ALCDCY_SHIFT                          4  /* ALCDCY - [7:4] */
#define WM8950_ALCDCY_WIDTH                          4  /* ALCDCY - [7:4] */
#define WM8950_ALCATK_MASK                      0x000F  /* ALCATK - [3:0] */
#define WM8950_ALCATK_SHIFT                          0  /* ALCATK - [3:0] */
#define WM8950_ALCATK_WIDTH                          4  /* ALCATK - [3:0] */

/*
 * R35 (0x23) - Noise Gate
 */
#define WM8950_NGEN                             0x0008  /* NGEN */
#define WM8950_NGEN_MASK                        0x0008  /* NGEN */
#define WM8950_NGEN_SHIFT                            3  /* NGEN */
#define WM8950_NGEN_WIDTH                            1  /* NGEN */
#define WM8950_NGTH_MASK                        0x0007  /* NGTH - [2:0] */
#define WM8950_NGTH_SHIFT                            0  /* NGTH - [2:0] */
#define WM8950_NGTH_WIDTH                            3  /* NGTH - [2:0] */

/*
 * R36 (0x24) - PLL N
 */
#define WM8950_PLL_PRESCALE                     0x0010  /* PLL_PRESCALE */
#define WM8950_PLL_PRESCALE_MASK                0x0010  /* PLL_PRESCALE */
#define WM8950_PLL_PRESCALE_SHIFT                    4  /* PLL_PRESCALE */
#define WM8950_PLL_PRESCALE_WIDTH                    1  /* PLL_PRESCALE */
#define WM8950_PLLN_MASK                        0x000F  /* PLLN - [3:0] */
#define WM8950_PLLN_SHIFT                            0  /* PLLN - [3:0] */
#define WM8950_PLLN_WIDTH                            4  /* PLLN - [3:0] */

/*
 * R37 (0x25) - PLL K 1
 */
#define WM8950_PLLK_2_MASK                      0x003F  /* PLLK - [5:0] */
#define WM8950_PLLK_2_SHIFT                          0  /* PLLK - [5:0] */
#define WM8950_PLLK_2_WIDTH                          6  /* PLLK - [5:0] */

/*
 * R38 (0x26) - PLL K 2
 */
#define WM8950_PLLK_1_MASK                      0x01FF  /* PLLK - [8:0] */
#define WM8950_PLLK_1_SHIFT                          0  /* PLLK - [8:0] */
#define WM8950_PLLK_1_WIDTH                          9  /* PLLK - [8:0] */

/*
 * R39 (0x27) - PLL K 3
 */
#define WM8950_PLLK_MASK                        0x01FF  /* PLLK - [8:0] */
#define WM8950_PLLK_SHIFT                            0  /* PLLK - [8:0] */
#define WM8950_PLLK_WIDTH                            9  /* PLLK - [8:0] */

/*
 * R44 (0x2C) - Input ctrl
 */
#define WM8950_MICBVSEL                         0x0100  /* MICBVSEL */
#define WM8950_MICBVSEL_MASK                    0x0100  /* MICBVSEL */
#define WM8950_MICBVSEL_SHIFT                        8  /* MICBVSEL */
#define WM8950_MICBVSEL_WIDTH                        1  /* MICBVSEL */
#define WM8950_AUXMODE                          0x0008  /* AUXMODE */
#define WM8950_AUXMODE_MASK                     0x0008  /* AUXMODE */
#define WM8950_AUXMODE_SHIFT                         3  /* AUXMODE */
#define WM8950_AUXMODE_WIDTH                         1  /* AUXMODE */
#define WM8950_AUX2INPPGA                       0x0004  /* AUX2INPPGA */
#define WM8950_AUX2INPPGA_MASK                  0x0004  /* AUX2INPPGA */
#define WM8950_AUX2INPPGA_SHIFT                      2  /* AUX2INPPGA */
#define WM8950_AUX2INPPGA_WIDTH                      1  /* AUX2INPPGA */
#define WM8950_MICN2INPPGA                      0x0002  /* MICN2INPPGA */
#define WM8950_MICN2INPPGA_MASK                 0x0002  /* MICN2INPPGA */
#define WM8950_MICN2INPPGA_SHIFT                     1  /* MICN2INPPGA */
#define WM8950_MICN2INPPGA_WIDTH                     1  /* MICN2INPPGA */
#define WM8950_MICP2INPPGA                      0x0001  /* MICP2INPPGA */
#define WM8950_MICP2INPPGA_MASK                 0x0001  /* MICP2INPPGA */
#define WM8950_MICP2INPPGA_SHIFT                     0  /* MICP2INPPGA */
#define WM8950_MICP2INPPGA_WIDTH                     1  /* MICP2INPPGA */

/*
 * R45 (0x2D) - Left INP PGA gain ctrl
 */
#define WM8950_INPPGAZC                         0x0080  /* INPPGAZC */
#define WM8950_INPPGAZC_MASK                    0x0080  /* INPPGAZC */
#define WM8950_INPPGAZC_SHIFT                        7  /* INPPGAZC */
#define WM8950_INPPGAZC_WIDTH                        1  /* INPPGAZC */
#define WM8950_INPPGAMUTE                       0x0040  /* INPPGAMUTE */
#define WM8950_INPPGAMUTE_MASK                  0x0040  /* INPPGAMUTE */
#define WM8950_INPPGAMUTE_SHIFT                      6  /* INPPGAMUTE */
#define WM8950_INPPGAMUTE_WIDTH                      1  /* INPPGAMUTE */
#define WM8950_INPPGAVOL_MASK                   0x003F  /* INPPGAVOL - [5:0] */
#define WM8950_INPPGAVOL_SHIFT                       0  /* INPPGAVOL - [5:0] */
#define WM8950_INPPGAVOL_WIDTH                       6  /* INPPGAVOL - [5:0] */

/*
 * R47 (0x2F) - Left ADC BOOST ctrl
 */
#define WM8950_PGABOOST                         0x0100  /* PGABOOST */
#define WM8950_PGABOOST_MASK                    0x0100  /* PGABOOST */
#define WM8950_PGABOOST_SHIFT                        8  /* PGABOOST */
#define WM8950_PGABOOST_WIDTH                        1  /* PGABOOST */
#define WM8950_MICP2BOOSTVOL_MASK               0x0070  /* MICP2BOOSTVOL - [6:4] */
#define WM8950_MICP2BOOSTVOL_SHIFT                   4  /* MICP2BOOSTVOL - [6:4] */
#define WM8950_MICP2BOOSTVOL_WIDTH                   3  /* MICP2BOOSTVOL - [6:4] */
#define WM8950_AUX2BOOSTVOL_MASK                0x0007  /* AUX2BOOSTVOL - [2:0] */
#define WM8950_AUX2BOOSTVOL_SHIFT                    0  /* AUX2BOOSTVOL - [2:0] */
#define WM8950_AUX2BOOSTVOL_WIDTH                    3  /* AUX2BOOSTVOL - [2:0] */

/*
 * R49 (0x31) - Output ctrl
 */
#define WM8950_TSDEN                            0x0002  /* TSDEN */
#define WM8950_TSDEN_MASK                       0x0002  /* TSDEN */
#define WM8950_TSDEN_SHIFT                           1  /* TSDEN */
#define WM8950_TSDEN_WIDTH                           1  /* TSDEN */


////////////////////////////////////////////////////////////////
enum
{
    sr_wolfson_48   = 0,
    sr_wolfson_32   = 1,
    sr_wolfson_24   = 2,
    sr_wolfson_16   = 3,
    sr_wolfson_12   = 4,
    sr_wolfson_8    = 5,
};
enum
{
    sr_generic_48   = 0xC0,
    sr_generic_32   = 0x80,
    sr_generic_24   = 0x60,
    sr_generic_16   = 0x40,
    sr_generic_12   = 0x30,
    sr_generic_8    = 0x20,
    sr_generic_bad  = 0xFF,
};
////////////////////////////////////////////////////////////////
enum
{
    PCM16   = 0x00,
    ULAW8   = 0x10,
    ALAW8   = 0x11,
};
////////////////////////////////////////////////////////////////
enum
{
    bitPerSample_wolfson_16	= (0 << WM8950_WL_SHIFT),
    bitPerSample_wolfson_20 = (1 << WM8950_WL_SHIFT),
    bitPerSample_wolfson_24 = (2 << WM8950_WL_SHIFT),
    bitPerSample_wolfson_32 = (3 << WM8950_WL_SHIFT),
};
enum
{
    bitPerSample_generic_8	 = 0x08,
    bitPerSample_generic_16  = 0x10,
    bitPerSample_generic_20  = 0x14,
    bitPerSample_generic_24  = 0x18,
    bitPerSample_generic_32  = 0x20,
    bitPerSample_generic_bad = 0xFF,
};
////////////////////////////////////////////////////////////////
#define WOLFSON_PGA_0dB    16  // 0 dB
#define WOLFSON_PGA_MAXdB  63  // 35.25 dB
#define WOLFSON_PGA_MINdB  0   // -12 dB
#define GENERIC_PGA_MAXdB  ((WOLFSON_PGA_MAXdB-WOLFSON_PGA_0dB)*3)
#define GENERIC_PGA_MINdB  ((WOLFSON_PGA_MINdB-WOLFSON_PGA_0dB)*3)
#define SCALE_PGA_ONETHIRD (10922)


////////////////////////////////////////////////////////////////
#define FREQCUTOFF_AUDIOMODE     4 // Hz
#define FREQCUTOFF_TABLE_NROWS   8  // This corresponds to bits HPFCUT [2:0] from register WM8950_ADC_CONTROL
#define FREQCUTOFF_TABLE_NCOLS   9  // Col 1 to 9 correspond to sampling rates 8, 11.025, 12, 16, 22.05, 24, 32, 44.1, and 48
#define FREQCUTOFF_INVALID       0xFFFF
////////////////////////////////////////////////////////////////


class wolfson8950 : public AudioCodec_interface
{
public:
    wolfson8950();
    virtual void initialize(UINT16 NumChannles, UINT32 SampleRate, UINT16 BitsPerSample, UINT8 gain, UINT8 boost);
    virtual void init(void);

    virtual BYTE readSR(void);
    virtual BYTE readBPS(void);
    virtual BYTE readPCM(void);
    virtual UINT16 readHPF(void);
    virtual INT16 readPGA(void);

    virtual BOOL writeSR(BYTE p);
    virtual BOOL writeBPS(BYTE p);
    virtual BOOL writePCM(BYTE p);
    virtual BOOL writeHPF(UINT16 h);
    virtual BOOL writePGA(INT16 g);

    virtual UINT16 regRead(INT8 index);
    virtual void regWrite(INT8 index, UINT16 data);

protected:
    virtual void reset();
    virtual void write(BYTE addr, UINT16 data);

protected:

};



/* @} */


#endif
