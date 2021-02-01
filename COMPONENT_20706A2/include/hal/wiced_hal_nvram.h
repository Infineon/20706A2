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

/** @file
 *
 *  \addtogroup nvram NVRAM
 *  \ingroup HardwareDrivers
 *
 *  @{
 *
 *  Defines the interface for reading and writing any data to the NVRAM
 *
 */
#ifndef _WICED_HAL_NVRAM_H_
#define _WICED_HAL_NVRAM_H_


/*****************************************************************************
**                               Constants
*****************************************************************************/

/**
 * @brief Defines the first usable NVRAM Volatile Section Identifier.
 * Application can use the VS ids starting from WICED_NVRAM_VSID_START.
 **/
#define WICED_NVRAM_VSID_START      0x01

/**
 * @brief Defines the last usable NVRAM Volatile Section Identifier.
 * Application can use the VS ids starting from WICED_NVRAM_VSID_START to
 * WICED_NVRAM_VSID_END
 **/
#define WICED_NVRAM_VSID_END        0x75

/*
 * NOTE: From 0x01 to 0x75 is reserved to WICED Application.
 * Internal NVRAM VSID starts from 0x76 to 0x7B and this should not be used by application.
 */


/*****************************************************************************
**                          Function Declarations
*****************************************************************************/

/**
 * Writes the data to NVRAM,
 * Application can write up to 255 bytes in one VS  id section
 *
 * @param[in] vs_id        : Volatile Section Identifier. Application can use
 *                           the VS ids from WICED_NVRAM_VSID_START to
 *                           WICED_NVRAM_VSID_END
 *
 * @param[in] data_length  : Length of the data to be written to the NVRAM,
 *                           Application can only write up to 255 bytes
 *
 * @param[in] p_data       : Pointer to the data to be written to the NVRAM
 *
 * @param[out] p_status    : Pointer to location where status of the call
 *                           is returned
 *
 *
 * @return  number of bytes written, 0 on error
 */
#define wiced_hal_write_nvram        wiced_hal_write_nvram_patch
uint8_t wiced_hal_write_nvram_patch( uint8_t vs_id,
        uint8_t          data_length,
        uint8_t        * p_data,
        wiced_result_t * p_status);

/** Reads the data from NVRAM
 *
 * @param[in]  vs_id       : Volatile Section Identifier. Application can use
 *                           the VS ids from WICED_NVRAM_VSID_START to
 *                           WICED_NVRAM_VSID_END
 *
 * @param[in]  data_length : Length of the data to be read from NVRAM
 *
 * @param[out] p_data      : Pointer to the buffer to which data will be copied
 *
 * @param[out] p_status    : Pointer to location where status of the call
 *                           is returned
 *
 * @return  the number of bytes read, 0 on failure
 */
uint8_t wiced_hal_read_nvram( uint8_t vs_id,
        uint8_t          data_length,
        uint8_t        * p_data,
        wiced_result_t * p_status);

/**
 * Delete the data from NVRAM
 *
 * @param[in] vs_id        : Volatile Section Identifier. Application can use
 *                           the VS ids from WICED_NVRAM_VSID_START to
 *                           WICED_NVRAM_VSID_END
 *
 * @param[out] p_status    : Pointer to location where status of the call
 *                           is returned
 *
 */
void wiced_hal_delete_nvram( uint16_t vs_id,
        wiced_result_t * p_status);

/** @} */

#endif //_WICED_HAL_NVRAM_H_
