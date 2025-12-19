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
 * Generic types
 *
 */
#pragma once
#include "wiced.h"
#include "data_types.h"


#ifdef __cplusplus
extern "C" {
#endif

#define BD_ADDR_LEN     6  /**< Bluetooth device address length */
/**
 * Bluetooth Device address
 * @note: The Bluetooth device address is expressed in Big Endian format
 *
 *  ---------------------------------------------------
 * |byte 0 | byte 1 | byte 2 | byte 3| byte 4| byte 5 |
 *  ---------------------------------------------------
 * | NAP 1 | NAP 0  |   UAP  | LAP 2 | LAP 1 | LAP 0  |
 *  ---------------------------------------------------
 * */
typedef uint8_t         wiced_bt_device_address_t[BD_ADDR_LEN];

#define BD_NAME_LEN     248
typedef uint8_t wiced_bt_remote_name_t[BD_NAME_LEN + 1];        /* Device name array */

typedef uint8_t *wiced_bt_device_address_ptr_t;                 /**< Device address Pointer */

#define DEV_CLASS_LEN   3
typedef uint8_t         wiced_bt_dev_class_t[DEV_CLASS_LEN];    /**< Device class */

#define MAX_UUID_SIZE              16  /**< Maximum UUID size - 16 bytes, and structure to hold any type of UUID. */

/** UUID Type */
typedef struct
{
#define LEN_UUID_16     2
#define LEN_UUID_32     4
#define LEN_UUID_128    16

    uint16_t        len;     /**< UUID length */

    union
    {
        uint16_t    uuid16; /**< 16-bit UUID */
        uint32_t    uuid32; /**< 32-bit UUID */
        uint8_t     uuid128[MAX_UUID_SIZE]; /**< 128-bit UUID */
    } uu;

} wiced_bt_uuid_t;

#define BT_OCTET16_LEN    16                /**<  length: 16 */
typedef uint8_t BT_OCTET16[BT_OCTET16_LEN]; /**< octet array: size 16 */

#define BT_OCTET32_LEN    32
typedef uint8_t BT_OCTET32[BT_OCTET32_LEN];   /* octet array: size 32 */

/** Bluetooth QoS defintions */
typedef struct {
    uint8_t         qos_flags;              /**< TBD */
    uint8_t         service_type;           /**< service type (NO_TRAFFIC, BEST_EFFORT, or GUARANTEED) */
    uint32_t        token_rate;             /**< token rate (bytes/second) */
    uint32_t        token_bucket_size;      /**< token bucket size (bytes) */
    uint32_t        peak_bandwidth;         /**< peak bandwidth (bytes/second) */
    uint32_t        latency;                /**< latency (microseconds) */
    uint32_t        delay_variation;        /**< delay variation (microseconds) */
} wiced_bt_flow_spec_t;

/* Values for swiced_bt_flow_spec_t service_type */
#define NO_TRAFFIC      0
#define BEST_EFFORT     1
#define GUARANTEED      2

/**
 * @anchor WICED_BT_TRANSPORT_TYPE
 * @name Transport types
 * @{
 */
#define BT_TRANSPORT_BR_EDR         1       /**< BR/EDR transport */
#define BT_TRANSPORT_LE             2       /**< LE transport */
typedef uint8_t wiced_bt_transport_t;       /**< Transport type (see @ref WICED_BT_TRANSPORT_TYPE "Bluetooth Transport Types") */

/**
 * @anchor WICED_BT_DEVICE_TYPE
 * @name Device Types
 * @{
 */
#define BT_DEVICE_TYPE_BREDR        0x01    /**< BR/EDR device */
#define BT_DEVICE_TYPE_BLE          0x02    /**< LE device */
#define BT_DEVICE_TYPE_BREDR_BLE    0x03    /**< Dual Mode device */
typedef uint8_t wiced_bt_device_type_t;     /**< Bluetooth device type (see @ref WICED_BT_DEVICE_TYPE "Bluetooth Device Types") */
/** @} WICED_BT_DEVICE_TYPE */

/**
 * @anchor WICED_BT_ADDR_TYPE
 * @name Address Types
 * @{
 */
#define BLE_ADDR_PUBLIC             0x00        /**< Public address */
#define BLE_ADDR_RANDOM             0x01        /**< Random address */
#define BLE_ADDR_PUBLIC_ID          0x02        /**< Public ID      */
#define BLE_ADDR_RANDOM_ID          0x03        /**< Random ID      */
typedef uint8_t wiced_bt_ble_address_type_t;    /**< LE device address type (see @ref WICED_BT_ADDR_TYPE "Bluetooth Address Types")*/
#define BLE_ADDR_TYPE_MASK          (BLE_ADDR_RANDOM | BLE_ADDR_PUBLIC)
/** @} WICED_BT_ADDR_TYPE */

#ifndef wiced_bt_ble_address_t
typedef struct
{
    wiced_bt_ble_address_type_t type;
    wiced_bt_device_address_t   bda;
} wiced_bt_ble_address_t;
#endif

#define LINK_KEY_LEN    16
typedef uint8_t wiced_bt_link_key_t[LINK_KEY_LEN];

#ifdef __cplusplus
}
#endif
