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
 * Defines the transport utilities for configuring the transport, send data and
 * receive data
 */
#ifndef _WICED_TRANSPORT_H_
#define _WICED_TRANSPORT_H_

#include "spiffydriver.h"
#include "wiced_bt_dev.h"

/*****************************************************************************
**                                                Type Definitions
*****************************************************************************/

/** @defgroup Transport     WICED Transport
 *  @ingroup HardwareDrivers
 *
 * This section describes the API's necessary to configure WICED transport, send
 * and receive data over the transport.
 *
 *  @{
 */

/** Wiced transport types */
typedef enum
{
    WICED_TRANSPORT_UART,           /**< UART Transport */
    WICED_TRANSPORT_SPI,            /**< SPI Transport */
    WICED_TRANSPORT_UNDEFINED       /**< Transport Not Defined */
}wiced_transport_type_t;

/** Wiced uart transport mode */
typedef enum
{
    WICED_TRANSPORT_UART_HCI_MODE, /**<  Data sent as per the WICED HCI Protocol over UART */
    WICED_TRANSPORT_UART_RAW_MODE, /**<  Data sent as raw bytes over UART */
}wiced_transport_uart_mode_t;

/** wiced transport buffer pool */
typedef struct _wiced_trans_buffer_pool_t wiced_transport_buffer_pool_t;

/** Wiced transport status handler  */
typedef void (*wiced_transport_status_handler_t)( wiced_transport_type_t type );

/** Wiced transport data handler
* Handles the data received over transport. This function should return value depending on the
* configured transport/transport mode. Freeing of the buffer is also required depending on the
* mode.Refer the notes below.
*
* Note**: If the application is operating in WICED_TRANSPORT_UART_RAW_MODE, application should return the
* number of bytes read ie, the data that application could process successfully.RAW UART Transport driver
* uses a circular buffer to receive the data and returning the data length is required to update the
* buffer pointers. Application shall not invoke the release buffer API when in raw mode.
*
* If the application is operating in WICED_TRANSPORT_UART_HCI_MODE or using WICED_TRANSPORT_SPI transport,
* application has to free the buffer in which data is received . Use the API
* wiced_transport_free_buffer to release the rx buffer. Also return WICED_SUCCESS if
* data is processed successfully or return error codes otherwise
*/
typedef uint32_t (*wiced_tranport_data_handler_t)( uint8_t* p_data, uint32_t data_len );

/** Wiced transport tx complete indication. Indicates the application that a packet is sent using
  * a buffer in the indicated pool. Application shall register this callback if it wants indication on
  * packet sent using buffer allocated from the transport pool created by the application
  *
  *  @param[in] p_pool : Pool pointer, buffer is used from this pool for sending the packet
  *
  *  @return : None
  */
typedef void (*wiced_transport_tx_complete_t)( wiced_transport_buffer_pool_t* p_pool );

#pragma pack(1)

/** UART transport config */
typedef PACKED struct
{
    wiced_transport_uart_mode_t     mode;                        /**<  UART mode, HCI or Raw */
    uint32_t                        baud_rate;                   /**<  UART baud rate */
}wiced_uart_transport_cfg_t;

/** SPI transport config */
typedef PACKED struct
{
    uint8_t          dev_role;            /**< SPI HW to play either master (1) or slave (2) */
    uint32_t         spi_gpio_cfg;        /**< Pins to use for the data and clk lines. Refer  spiffdriver.h for details */
    uint16_t         spi_pin_pull_config; /**< Pin pull-up or pull-down */
    uint32_t         clock_speed;         /**< Clock speed (non-zero for master, zero for slave).*/
    SPI_ENDIAN       endian;              /**< Direction of bit data flow (MSB or LSB first) */
    SPI_SS_POLARITY  polarity;            /**< Active high or active low for chip select line */
    SPI_MODE         mode;                /**< SPI mode (0-3). */
    uint8_t          cs_pin;              /**< GPIO pin of chip select line */
    uint8_t          slave_ready_pin;     /**< GPIO pin to be used as slave ready */
}wiced_spi_transport_cfg_t;

/** Wiced transport interface config */
typedef PACKED union
{
    wiced_spi_transport_cfg_t  spi_cfg;
    wiced_uart_transport_cfg_t uart_cfg;
}wiced_transport_interface_cfg_t;

/** Wiced receive buffer pool configuration. Application shall use this to receive
* packet of size > 264 bytes
*.Note: If the application is operating in WICED_TRANS_UART_RAW_MODE, application should specify the
* rx buffer size. RAW UART Transport driver uses a circular buffer to receive the data */

typedef PACKED struct
{
    uint32_t buffer_size;
    uint32_t buffer_count;
}wiced_transport_rx_buff_pool_cfg_t;

/** Wiced transport config */
typedef PACKED struct
{
    wiced_transport_type_t              type;                 /**< Wiced transport type. */
    wiced_transport_interface_cfg_t     cfg;                  /**< Wiced transport interface config. */
    wiced_transport_rx_buff_pool_cfg_t  rx_buff_pool_cfg;     /**< Wiced rx buffer pool config. */
    wiced_transport_status_handler_t    p_status_handler;     /**< Wiced transport status handler.*/
    wiced_tranport_data_handler_t       p_data_handler;       /**< Wiced transport receive data handler. */
    wiced_transport_tx_complete_t       p_tx_complete_cback;  /**< Wiced transport tx complete callback. */
}wiced_transport_cfg_t;

#pragma pack()

/*****************************************************************************
**                                                 Function Declarations
*****************************************************************************/

/**
 * Function         wiced_transport_init
 *
 * Initializes and configures the transport and also registers the handlers to be invoked on transport
 * detection and on receiving the data
 *
 * * @param[in]    p_cfg           :wiced transport config
 *
 * @return     : wiced_result_t
 */
wiced_result_t wiced_transport_init( const wiced_transport_cfg_t* p_cfg );

/**
 * Function         wiced_transport_create_buffer_pool
 *
 * Creates a buffer pool for transport usage. Application shall create the buffer pool if it has to send
 * packet of size > 264 bytes. Application shall specify the payload length as the buffer size. Transport
 * will take care of creating a pool of desired size considering the transport header requirements and the
 * application specified payload size. Application cannot release/free the pool memory once created.
 *
 * * @param[in]    buffer_size         : Size of each buffer in pool. Application shall specify
 *                                       the payload length as the buffer size.
 * * @param[in]    buffer_count        : Number of buffers in the pool
 *
 * @return     : pointer to the buffer pool on success, NULL on failure
 */
wiced_transport_buffer_pool_t* wiced_transport_create_buffer_pool( uint32_t buffer_size, uint32_t buffer_count );

/**
 * Function         wiced_transport_allocate_buffer
 *
 * Allocates a buffer from the pool
 *
 * @param[in]    p_pool           : Pointer to buffer pool returned from wiced_transport_create_buffer_pool.
 *
 * @return     : Pointer to the payload on success, NULL on failure.
 *                   Application shall write the payload starting from this location
 */
void* wiced_transport_allocate_buffer( wiced_transport_buffer_pool_t* p_pool );

/**
 * Function         wiced_transport_get_buffer_size
 *
 * Returns the size of buffer of in the pool
 *
 * @param[in]    p_pool           : Pointer to buffer pool returned from wiced_transport_create_buffer_pool
 *
 * @return     : size of the buffers of the pool
 */
uint32_t wiced_transport_get_buffer_size( wiced_transport_buffer_pool_t *p_pool );
/**
 * Function         wiced_transport_get_buffer_count
 *
 * To get the number of buffers available in the pool
 *
 * @param[in]    p_pool           : Pointer to buffer pool created using wiced_transport_create_buffer_pool
 *
 * @return     : the number of buffers available in the pool
 */
uint32_t wiced_transport_get_buffer_count( wiced_transport_buffer_pool_t *p_pool );

/**
 * Function         wiced_transport_send_buffer
 *
 *    Send the packet to the host over the transport using the buffer allocated by the application.
 *    This function takes care of preparing the header and sending the data. In case of
 *    WICED_TRANSPORT_UART_RAW_MODE, the header is not included in the message and is ignored by the
 *    API.The buffer will be freed by the transport after sending the packet.
 *
 * Note: Application has to allocate buffer from transport pool using wiced_transport_allocate_buffer
 *         and copy the payload to this buffer and send the payload pointer.
 *         This allows the application to use custom size buffers and avoid overrun of generic buffers,
 *         which is shared across firmware code.
 *
 *@param[in]    code                 :Group code and command code. Ignored in case of WICED_TRANSPORT_UART_RAW_MODE
 *@param[in]    p_buf                :Pointer to the payload
 *@param[in]    length               :Payload length
 *
 * @return   wiced_result_t
 */
wiced_result_t wiced_transport_send_buffer( uint16_t code, uint8_t* p_buf, uint16_t length );

/**
 * Function         wiced_transport_free_buffer
 *
 * Frees the transport buffer.
 *
 * Note: When receiving a packet in  WICED_TRANSPORT_UART_HCI_MODE or in
 *         WICED_TRANSPORT_SPI mode, application should take care of freeing the rx buffers.
 *         When sending a packet, transport will take care of freeing the buffer after the
 *         packet is sent.
 *
 *@param[in]    p_buf                :Pointer to the buffer to be freed
 *
 * @return   None
 */
void wiced_transport_free_buffer( void * p_buf );

/**
 * Function         wiced_transport_send_data
 *
 *Send the packet to the host over the transport.
 *This function allocates a buffer internally and prepare the header, copy the payload
 *and then sends the packet over the transport. In case of WICED_TRANSPORT_UART_RAW_MODE,
 *the header is not included in the message and is ignored by the API.
 *Maximum size of the buffer that can be allocated is 264 bytes
 *
 * Transport internally uses a buffer from the pool which is available for all general purposes
 * Following are the configuration of the internal pool
 * 1:   buffer size - 32 bytes, buffer count - 48
 * 2:   buffer size - 64 bytes, buffer count - 16
 * 3:   buffer size - 264 bytes, buffer count - 10

 *
 *@param[in]    code                  :Group code and command code.Ignored in case of WICED_TRANSPORT_UART_RAW_MODE
 *@param[in]    p_data                :Pointer to the payload
 *@param[in]    length                :Payload length
 *
 * @return   wiced_result_t
 */
wiced_result_t wiced_transport_send_data ( uint16_t code, uint8_t* p_data, uint16_t length );

/**
 * Function         wiced_transport_send_hci_trace
 *
 *Send the hci trace data over the transport.
 *
 *@param[in]    hci_trans_pool       :Pass the pointer to the pool created by the application
                                      if application  has created a dedicated transport pool for
                                      communicating to host. Pass NULL if the application wants the stack to
                                      take care of allocating the buffer for sending the data to host
 *@param[in]    type                 :HCI trace type
 *@param[in]    p_data               :Pointer to the data payload
 *@param[in]    length               :Data payload length
 *
 * @return   wiced_result_t
 */
wiced_result_t wiced_transport_send_hci_trace( wiced_transport_buffer_pool_t *hci_trans_pool ,
                                                             wiced_bt_hci_trace_type_t type, uint16_t length, uint8_t* p_data );

/* @} */

#endif // _WICED_TRANSPORT_H_
