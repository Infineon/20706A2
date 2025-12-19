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
 * NOTE: From 0x01 to 0x75 is reserved to the Application.
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
