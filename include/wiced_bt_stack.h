/*
 * Copyright 2014, Cypress Semiconductor
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Cypress Semiconductor;
 * the contents of this file may not be disclosed to third parties, copied
 * or duplicated in any form, in whole or in part, without the prior
 * written permission of Cypress Semiconductor.
 */

#pragma once

#include "wiced_bt_cfg.h"

/******************************************************
 *               Function Declarations
 ******************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************/
/**
 * Framework Management Functions
 *
 * @addtogroup  wicedbt_Framework   Framework
 * @ingroup     wicedbt
 *
 * @{
 */
/****************************************************************************/

/**
 * Function         wiced_bt_stack_init
 *
 *                  Initialize the Bluetooth controller and stack; register
 *                  callback for Bluetooth event notification.
 *
 * @param[in] p_bt_management_cback     : Callback for receiving Bluetooth management events
 * @param[in] p_bt_cfg_settings         : Bluetooth stack configuration
 * @param[in] wiced_bt_cfg_buf_pools    : Buffer pool configuration
 *
 * @return    WICED_BT_SUCCESS : on success;
 *            WICED_BT_FAILED : if an error occurred
 */
wiced_result_t wiced_bt_stack_init(wiced_bt_management_cback_t *p_bt_management_cback,
                                   const wiced_bt_cfg_settings_t     *p_bt_cfg_settings,
                                   const wiced_bt_cfg_buf_pool_t     wiced_bt_cfg_buf_pools[WICED_BT_CFG_NUM_BUF_POOLS]);



/**@} wicedbt_Framework */


#ifdef __cplusplus
}
#endif
