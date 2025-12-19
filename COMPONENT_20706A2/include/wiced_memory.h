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
 *  \addtogroup wiced_mem Memory Management
 *  \ingroup wicedsys
 *
 *  @{
 * AIROC Memory Management Interface
 */

#pragma once

#include "wiced_bt_types.h"
#include "wiced_gki.h"

/** wiced buffer pool */
typedef struct wiced_pool_t wiced_bt_buffer_pool_t;

#pragma pack(1)

/** AIROC Bluetooth dynamic buffer statistics */
typedef PACKED struct
{
    uint8_t     pool_id;                    /**< pool id */
    uint16_t    pool_size;                  /**< pool buffer size */
    uint16_t    current_allocated_count;    /**< number of  buffers currently allocated */
    uint16_t    max_allocated_count;        /**< maximum number of buffers allocated at any time */
    uint16_t    total_count;                /**< total number of buffers */
}wiced_bt_buffer_statistics_t;

#pragma pack()

/**
 * Function         wiced_memory_get_free_bytes
 *
 *                  Returns the number of free bytes of RAM left
 *
 * @return          the number of free bytes of RAM left
 */
uint32_t wiced_memory_get_free_bytes( void );

/**
 * Function         wiced_memory_set_application_thread_stack_size
 *
 *                  Update the stack size of the application thread (MPAF)
 *
 *                  NOTE : This API will work only when invoked from SPAR_CRT_SETUP()
 *
 * @param[in]       new_stack_size - required size of the stack.
 *
 * @return          TRUE on success else FALSE
 */
wiced_bool_t wiced_memory_set_application_thread_stack_size(uint16_t new_stack_size);

/**
 * Function         wiced_bt_create_pool
 *
 *                  Creates a private buffer pool dedicated for the application usage.
 *
 * @param[in]       buffer_size          : size of the buffers in the pool
 *
 * @param[in]       buffer_cnt           : number of buffers in the pool
 *
 * @return          pointer to the created pool on success
 *                  NULL on failure
 *
 * Note :           The max number of buffer pools configured in
 *                  wiced_bt_cfg_settings_t.max_number_of_buffer_pools
 *                  must be increased for each buffer pool the application creates.
 */
wiced_bt_buffer_pool_t* wiced_bt_create_pool( uint32_t buffer_size, uint32_t buffer_cnt );

/**
 * Function         wiced_bt_get_buffer_from_pool
 *
 *                  Allocates a buffer from the private pool. Pass the pool pointer to
 *                  get the buffer from the desired pool
 *
 * @param[in]       p_pool           : pool pointer
 *
 * @return          the pointer to the buffer
 *                  NULL on failure
 */
void* wiced_bt_get_buffer_from_pool( wiced_bt_buffer_pool_t* p_pool );

/**
 * Function         wiced_bt_get_buffer_count
 *
 *                  To get the number of buffers available in the pool
 *
 * @param[in]       p_pool           : pool pointer
 *
 * @return          the number of buffers available in the pool
 */
uint32_t wiced_bt_get_buffer_count( wiced_bt_buffer_pool_t* p_pool );

/**
 * Function         wiced_bt_get_buffer
 *
 *                  Allocates a buffer from the public pools. Public pools shall be specified
 *                  using wiced_bt_cfg_buf_pool_t from the application.
 *
 * @param[in]       buffer_size           : size of the buffer
 *
 * @return          the pointer to the buffer
 *                  NULL on failure
 */
void* wiced_bt_get_buffer( uint16_t buffer_size );

/**
 * Function         wiced_bt_free_buffer
 *
 *                  Frees the buffer
 *
 * @param[in]       p_buf           : pointer to the start of the buffer to be freed
 *
 * @return          None
 */
void wiced_bt_free_buffer( void* p_buf );

/**
 * Function         wiced_bt_get_buffer_size
 *
 *                  Gets the buffer size
 *
 * @param[in]       p_buf           : pointer to the start of the buffer
 *
 * @return          the buffer size
 */
uint32_t wiced_bt_get_buffer_size( void* p_buf );

/**
 * Function         wiced_bt_get_buffer_usage
 *
 *                  Dumps dynamic buffer usage (see #wiced_bt_buffer_statistics_t),
 *                  from the last start of the system.
 *
 * @param[in]       p_buffer_stat - pointer buffer to fill statistics.
 * @param[in]       size - size of the memory to get the statistics.
 *
 * @return          WICED_BT_SUCCESS on success else error
 */
wiced_result_t wiced_bt_get_buffer_usage ( wiced_bt_buffer_statistics_t *p_buffer_stat, uint16_t size );

/**
 * Function         wiced_memory_allocate
 *
 *                  Allocates memory from Dynamic Memory pools
 *
 * @param[in]       size           :size of the memory to be allocated
 *
 * @return          pointer to the allocated memory on success
 *                  NULL on failure
 */
void* wiced_memory_allocate( uint32_t size );

/**
 * Function         wiced_memory_free
 *
 *                  Frees the buffer
 *
 * @param[in]       p_buf           : free memory allocated from Dynamic Memory pools
 *
 * @return          None
 */
void wiced_memory_free( void *memoryBlock );

/** Get specific buffer pool utilization
 *
 * @param[in]       pool_id     : (input) pool ID
 *
 * @return          % of buffers used from 0 to 100
 */
UINT16 wiced_bt_buffer_poolutilization (UINT8 pool_id);

/******************************************************************************
* Function Name: wiced_memory_permanent_allocate
***************************************************************************//**
*
* Allocates memory for permanent usage.
*
* @param[in]        size            : The size of the memory to be allocated
*
* @return           The pointer to the allocated memory on success
*                   NULL on failure
*
******************************************************************************/
void* wiced_memory_permanent_allocate( uint32_t size );

/** @} */
