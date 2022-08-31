/*
 * Copyright 2020-2022, Cypress Semiconductor Corporation (an Infineon company) or
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
 * support memory allocation tuning
 *
 */
#ifndef __WICED_MEMORY_PRE_INIT_H__
#define __WICED_MEMORY_PRE_INIT_H__

/**
 * use this define value to indicate no change to parameter
 */
#define WICED_MEM_PRE_INIT_IGNORE   (0xffff)

/**
 * structure containing paramters to pass for memory pre-init
 */
typedef struct tag_mem_pre_init_control
{
    UINT16 scanRssiThresholdDeviceListSize;
    UINT16 lm_cmdQueueAreaSize;

    UINT16  aclDownBufSize;
    UINT16  aclUpBufSize;
    UINT8   aclDownCount;
    UINT8   aclUpCount;

    UINT8   rmulpMaxLLConnection;
    UINT8   ulp_rl_maxSize;
} WICED_MEM_PRE_INIT_CONTROL;

#define SCAN_RSSI_THRESHOLD_DEVICE_LIST_SIZE    25
#define LM_CMD_QUEUE_SIZE                       800


/**
 * set pre-init memory allocation parameters
 * call this from spar_crt_init function to set parameters prior to allocations
 */
void wiced_memory_pre_init(WICED_MEM_PRE_INIT_CONTROL *mem_pre_init);
#endif
