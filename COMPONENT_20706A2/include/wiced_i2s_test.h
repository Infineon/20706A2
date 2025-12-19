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
 * File Name: wiced_i2s_test.h
 *
 * AIROC I2S Test Interface
 */

/******************************************************************************
 *                 Type Definitions
 ******************************************************************************/
/**
 * wiced_i2s_test_interrupt_handler_t
 *
 * This function is invoked on receiving I2S FIFO interrupts and shall be used
 * to set the application generated sample date by using wiced_i2s_test_set_sample.
 * Application should be ready with the sample data to be copied beforehand.
 * Care should be taken when handling this callback as it is invoked in the
 * interrupt context.
 *
 */
typedef void (*wiced_i2s_test_interrupt_handler_t)( void );

/******************************************************************************
 *                 Function Declarations
 ******************************************************************************/

/**
 * Function         wiced_i2s_test_command
 *
 * This function shall be used to start/stop the I2S test and application shall
 * send either internally stored sample data or any generated data.On starting
 * the test,I2S engine is enabled with the chosen sample rate and step parameters.
 * On stopping the test, I2S engine is turned off and the other parameters doesn't
 * matter.
 *
 * To send application generated sample, set the step as zero and shall register
 * the wiced_i2s_test_register_interrupt_handler_cback function.
 * The application shall use the wiced_i2s_test_set_sample to set the sample on
 * receiving the registered callback.

 * To send internally stored sample data, set the step between 1 to 9.
 *
 * @param[in]      start        : Set to TRUE to start the test and FALSE to stop
 *                                the test
 *
 * @param[in]      sample_rate  : Sample rate to be used. Supported values are 8000,
 *                                16000, 32000,44100,48000
 *
 * @param[in]      step         : Output frequency is derived based on this.
 *                                For steps in the range 1 - 9, Output frequency = (sample_rate * step) / 48.
 *                                Set the step to zero for the application to send the
 *                                application generated sample data
 *
 * @return          void
 *
 */
void wiced_i2s_test_command( wiced_bool_t start, uint32_t sample_rate, uint8_t step );

/**
 * Function         wiced_i2s_test_register_interrupt_handler_cback
 *
 * This function shall be used to register the I2S FIFO interrupt handler.Application shall use
 * registered function to set the sample data by using wiced_i2s_test_set_sample.
 *
 * @param[in]      p_cback  : Calback function to be invoked on I2S FIFO interrupts
 *
 * @return         void
 *
 */
void wiced_i2s_test_register_interrupt_handler_cback( wiced_i2s_test_interrupt_handler_t p_cback);

/**
 * Function         wiced_i2s_test_set_sample
 *
 * This function shall be used to set the application generated sample data.This function
 * should be invoked before starting the I2S test. The generated sample should be copied
 * to a 256 word array. Array shall be 4 byte aligned and array pointer shall be passed
 * to set the sample. Application shall take care of setting 16 byte stereo data in the array
 *
 * Eg: short sample_data[256]__attribute__ ((aligned (4))) = { 0x00, 0x00, 0x60,0x60,..};
 *
 * @param[in]      p_sample_data  : Pointer to the generated sample data
 *
 * @return          void
 *
 */
void wiced_i2s_test_set_sample( short* p_sample_data);
