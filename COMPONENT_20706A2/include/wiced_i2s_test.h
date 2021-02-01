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
 * File Name: wiced_i2s_test.h
 *
 * WICED I2S Test Interface
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
