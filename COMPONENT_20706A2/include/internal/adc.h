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
*    File Name: adc.h
*
*    Abstract: This file defines the ADC driver
*
*
********************************************************************
*/

#ifndef __ADC__H__
#define __ADC__H__

#include "types.h"
#include "adc_cs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**  \addtogroup ADC
 *  \ingroup HardwareDrivers
*/

// config ADC block to default/userconfig state
void adc_config(void);

// calibration for the referenceInput
void adc_adcCalibrate(UINT32 refVoltageInMicroVolts, ADC_INPUT_CHANNEL_SEL referenceInput);

// read the adc value from hardware register as it is
INT16 adc_readSampleRaw(ADC_INPUT_CHANNEL_SEL channel_idx);


// read converted adc voltage
UINT32 adc_readVoltage(ADC_INPUT_CHANNEL_SEL idx);

ADC_POWER_TYPE adc_setPower(ADC_POWER_TYPE pwr);

void adc_SetInputRange(ADC_INPUT_RANGE_SEL range_idx);

/// Convert GPIO to ADC input
UINT8 adc_convertGPIOtoADCInput(UINT8 gpio);

/// Convert ADC input to GPIO
UINT8 adc_convertADCInputtoGPIO(UINT8 adcInput);


/* @} */

#ifdef __cplusplus
}
#endif

#endif
