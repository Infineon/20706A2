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
 *  Defines functions to access functions provided by the RTOS
 *  in a generic way
 *
 */

#pragma once


/* Include the actual RTOS definitions for:
 * - wiced_timed_event_t
 * - timed_event_handler_t
 */
#include "wiced_result.h"
#include "wiced_bt_dev.h"

#ifdef __cplusplus
extern "C" {
#endif


#define WICED_NO_WAIT       0
#define WICED_WAIT_FOREVER  ((uint32_t) 0xFFFFFFFF)
#define WICED_NEVER_TIMEOUT ((uint32_t) 0xFFFFFFFF)


/******************************************************
 * @cond            Enumerations
 ******************************************************/

/** Wiced event flag wait option */
typedef enum
{
    WAIT_FOR_ANY_EVENT,
    WAIT_FOR_ALL_EVENTS,
} wiced_event_flags_wait_option_t;

/** Wiced delay types */
typedef enum
{
    ALLOW_THREAD_TO_SLEEP, /**<  Allow the current running thread to sleep */
    KEEP_THREAD_ACTIVE,    /**<  Keep the current running thread active */
}wiced_delay_type_t;

/******************************************************
 *                 Type Definitions
 ******************************************************/


/******************************************************
 *             Structures
 ******************************************************/

typedef struct _wiced_thread_t        wiced_thread_t        ;
typedef struct _thread_monitor_info_t thread_monitor_info_t ;
typedef struct _wiced_queue_t         wiced_queue_t         ;
typedef struct _wiced_rtos_timer_t    wiced_rtos_timer_t    ;
typedef struct _wiced_semaphore_t     wiced_semaphore_t     ;
typedef struct _wiced_mutex_t         wiced_mutex_t         ;
typedef struct _wiced_event_flags_t   wiced_event_flags_t   ;
typedef struct _wiced_worker_thread_t wiced_worker_thread_t ;
typedef struct _wiced_timed_event_t   wiced_timed_event_t   ;

typedef wiced_result_t (*event_handler_t)( void* arg );

typedef void (*wiced_thread_function_t)( uint32_t arg );

/******************************************************
 *             Function declarations
 * @endcond
 ******************************************************/

extern wiced_worker_thread_t wiced_hardware_io_worker_thread;
extern wiced_worker_thread_t wiced_networking_worker_thread;

/*****************************************************************************/
/** @defgroup rtos       RTOS
 *
 *  AIROC Real-Time Operating System Functions
 */
/*****************************************************************************/


/*****************************************************************************/
/** @addtogroup threads       Threads
 *  @ingroup rtos
 *
 * Thread management functions
 *
 *
 *  @{
 */
/*****************************************************************************/

/** Initializes and starts a new thread
 *
 * Initializes and starts a new thread
 *
 * @param thread     : Pointer to variable that will receive the thread handle
 * @param priority   : A priority number or WICED_DEFAULT_APP_THREAD_PRIORITY.
 * @param name       : a text name for the thread (can be null)
 * @param function   : the main thread function
 * @param stack_size : stack size for this thread
 * @param arg        : argument which will be passed to thread function
 *
 * @return    WICED_SUCCESS : on success.
 * @return    WICED_ERROR   : if an error occurred
 */
wiced_result_t wiced_rtos_create_thread_with_stack( wiced_thread_t* thread, uint8_t priority, const char* name, wiced_thread_function_t function, uint32_t stack_size, void* arg );

/** @} */
/*****************************************************************************/
/** @addtogroup eventflags       Event Flags
 *  @ingroup rtos
 *
 * Event flags management functions
 *
 *
 *  @{
 */
/*****************************************************************************/

/** Creates a new instance of event flags
 *
 * Creates a new event_flag (Allocates memory for a new event flags instance and
 * returns the pointer)
 *
 * @return    valid pointer : on success.
 * @return    NULL          : if an error occurred
 */
wiced_event_flags_t*  wiced_rtos_create_event_flags( void );


/** Initialise an event flags
 *
 * @param event_flags : a pointer to the event flags handle
 *
 * @return    WICED_SUCCESS : on success.
 * @return    WICED_ERROR   : if an error occurred
 */
wiced_result_t wiced_rtos_init_event_flags( wiced_event_flags_t* event_flags );


/** Wait for event flags to be set
 *
 * @param event_flags        : a pointer to the event flags handle
 * @param flags_to_wait_for  : a group of event flags (ORed bit-fields) to wait for
 * @param flags_set          : event flag(s) set
 * @param clear_set_flags    : option to clear set flag(s)
 * @param wait_option        : wait option
 * @param timeout_ms         : timeout in milliseconds
 *
 * @return    WICED_SUCCESS : on success.
 * @return    WICED_ERROR   : if an error occurred
 */
wiced_result_t wiced_rtos_wait_for_event_flags( wiced_event_flags_t* event_flags, uint32_t flags_to_wait_for, uint32_t* flags_set, wiced_bool_t clear_set_flags, wiced_event_flags_wait_option_t wait_option, uint32_t timeout_ms );


/** Set event flags
 *
 * @param event_flags  : a pointer to the event flags handle
 * @param flags_to_set : a group of event flags (ORed bit-fields) to set
 *
 * @return    WICED_SUCCESS : on success.
 * @return    WICED_ERROR   : if an error occurred
 */
wiced_result_t wiced_rtos_set_event_flags( wiced_event_flags_t* event_flags, uint32_t flags_to_set );

/** @} */


/** @} */
/*****************************************************************************/
/** @addtogroup mutexes       Mutexes
 *  @ingroup rtos
 *
 * Mutex management functionss
 *
 *
 *  @{
 */
/*****************************************************************************/

/** Creates a new instance of mutex
 *
 * Creates a new mutex (Allocates memory for a new mutex instance and
 * returns the pointer)
 *
 * @return    valid pointer : on success.
 * @return    NULL          : if an error occurred
 */
wiced_mutex_t*  wiced_rtos_create_mutex( void );


/** Initialises a mutex
 *
 * Initialises a mutex
 * A mutex is different to a semaphore in that a thread that already holds
 * the lock on the mutex can request the lock again (nested) without causing
 * it to be suspended.
 *
 * @param mutex : a pointer to the mutex handle to be initialised
 *
 * @return    WICED_SUCCESS : on success.
 * @return    WICED_ERROR   : if an error occurred
 */
wiced_result_t wiced_rtos_init_mutex( wiced_mutex_t* mutex );


/** Obtains the lock on a mutex
 *
 * Attempts to obtain the lock on a mutex. If the lock is already held
 * by another thead, the calling thread will be suspended until
 * the mutex lock is released by the other thread.
 *
 * @param mutex : a pointer to the mutex handle to be locked
 *
 * @return    WICED_SUCCESS : on success.
 * @return    WICED_ERROR   : if an error occurred
 */
wiced_result_t wiced_rtos_lock_mutex( wiced_mutex_t* mutex );


/** Releases the lock on a mutex
 *
 * Releases a currently held lock on a mutex. If another thread
 * is waiting on the mutex lock, then it will be resumed.
 *
 * @param mutex : a pointer to the mutex handle to be unlocked
 *
 * @return    WICED_SUCCESS : on success.
 * @return    WICED_ERROR   : if an error occurred
 */
wiced_result_t wiced_rtos_unlock_mutex( wiced_mutex_t* mutex );


#ifdef WICED_RTOS_D
/** De-initialise a mutex
 *
 * Deletes a mutex created with @ref wiced_rtos_init_mutex
 *
 * @param mutex : a pointer to the mutex handle
 *
 * @return    WICED_SUCCESS : on success.
 * @return    WICED_ERROR   : if an error occurred
 */
wiced_result_t wiced_rtos_deinit_mutex( wiced_mutex_t* mutex );

#endif // WICED_RTOS_D


#ifdef __cplusplus
} /*extern "C" */
#endif
