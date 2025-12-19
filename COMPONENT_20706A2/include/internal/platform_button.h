/*
 * (c) 2025, Infineon Technologies AG, or an affiliate of Infineon
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
#pragma once

#ifdef CYW20706A2

#include "wiced.h"
// #include "wiced_data_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************
 *                      Macros
 ******************************************************/
/**
 * determine size (number of elements) in an array
 */
#define ARRAY_SIZE(a)                                ( sizeof(a) / sizeof(a[0]) )

/**
 * Macro to determine the element index in an array from the element address
 */
#define ARRAY_POSITION( array, element_pointer )     ( ((uint32_t)element_pointer - (uint32_t)array) / sizeof(array[0]) )

/******************************************************
 *                    Constants
 ******************************************************/

/******************************************************
 *                   Enumerations
 ******************************************************/
/* Logical Button-ids which map to phyiscal buttons on the board */
typedef enum
{
    PLATFORM_BUTTON_1,
	PLATFORM_BUTTON_2,
	PLATFORM_BUTTON_3,
	PLATFORM_BUTTON_4,
	PLATFORM_BUTTON_5,
	PLATFORM_BUTTON_6,
    PLATFORM_BUTTON_MAX, /* Denotes the total number of Buttons on the board. Not a valid Button Alias */
} platform_button_t;
/******************************************************
 *                 Type Definitions
 ******************************************************/
typedef wiced_result_t (*event_handler_t)( void* arg );
typedef void (*platform_button_state_change_callback_t)( platform_button_t id, wiced_bool_t new_state );

/******************************************************
 *                    Structures
 ******************************************************/

/******************************************************
 *                 Global Variables
 ******************************************************/

/******************************************************
 *               Function Declarations
 ******************************************************/
extern wiced_result_t  platform_button_init( platform_button_t button );
extern wiced_result_t  platform_button_deinit( platform_button_t button );
extern wiced_result_t  platform_button_enable( platform_button_t button );
extern wiced_result_t  platform_button_disable( platform_button_t button );
extern wiced_bool_t    platform_button_get_value( platform_button_t button );
extern wiced_result_t  platform_button_register_state_change_callback( platform_button_state_change_callback_t callback );

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
