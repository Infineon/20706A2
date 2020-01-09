/******************************************************************************
**
**  File Name:   sbc_plc_bec_tgt.h
**
**  Description: This file enables / disable optional feature of the SBC PLC BEC library
**
**  Copyright (c) 1999-2008, Broadcom Corp., All Rights Reserved.
**  Broadcom Bluetooth Core. Proprietary and confidential.
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
