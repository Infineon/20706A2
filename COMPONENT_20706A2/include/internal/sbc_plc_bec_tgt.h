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
/******************************************************************************
**
**  File Name:   sbc_plc_bec_tgt.h
**
**  Description: This file enables / disable optional feature of the SBC PLC BEC library
**
******************************************************************************/

/* Include MONO A2DP code */
#define SBC_DEC_MONO_A2DP_INCLUDED FALSE

/* Exclude ATTENUATION code */
#define SBC_ATTENUATION_INCLUDED FALSE

/* Exclude MIXING code */
#define SBC_MIXING_INCLUDED FALSE

/* Exclude Stereo 32 kHz downsampling code */
#define SBC_STEREO_32K_DOWNSAMPLED_16K FALSE

/* Exclude FIR Filter Convolution */
#define SBC_CONVOLUTION_FILTER_INCLUDED FALSE


/* Exclude Sample Rate Converter for 2074 A2 only. This is to have the SBC PCM output dowsampled to 16kHz.  This is only for for 2074 A2 where only DAC does support Frequency sampling up to 16 kHz only */
#define SBC_SAMPLE_RATE_CONVERTER_16K FALSE
