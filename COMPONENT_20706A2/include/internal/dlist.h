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
#ifndef _DLIST_H_
#define _DLIST_H_

/*******************************************************************************
*
* File Name: dlist.h
*
* Abstract:  This file constains utilities of generic double linked list
*
* Functions:
*
*******************************************************************************/

/*
 * the overview of the generic double linked list structure:

list_head:          +------+------+
         +--------->| next | prev |-------------------------------------------+
         |          +------+------+                                           |
         |              |      ^                                              |
         |              |      |                                              |
         |   +----------+      +-------------------------------------------+  |
         |   |                                                   v         |  |
         |   |  +-----------+       +-----------+           +-----------+  |  |
list:    |   |  | item1     |       | item2     |           | itemN     |  |  |
         |   |  |           |       |           |           |           |  |  |
         |   |  |           |       |           |           |           |  |  |
         |   |  +-----------+       +-----------+           +-----------+  |  |
         |   +->|   next    |------>|   next    |   ...  -->|   next    |--+  |
         |      +-----------+       +-----------+           +-----------+     |
         +------|   prev    |<------|   prev    |   ...  <--|   prev    |<----+
                +-----------+       +-----------+           +-----------+
                |           |       |           |           |           |
                |           |       |           |           |           |
                +-----------+       +-----------+           +-----------+

 *
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"

//BLTH02940572 ADK release
#ifndef DLIST_NODE_T_DEFINED
#define DLIST_NODE_T_DEFINED
typedef struct dlist_node_t {
	struct dlist_node_t *next, *prev;
} dlist_node_t;
#endif

#define DLIST_NODE_INIT(name) { &(name), &(name) }

#define DLIST_NODE(name) \
	struct dlist_node_t name = DLIST_NODE_INIT(name)

#define INIT_DLIST_NODE(ptr) do { \
	(ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)

/*
 * Insert a new entry between two known consecutive entries.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
/* Silly MS VC++ will get stuck with the variable name new, so
   I have to change it to _new */
INLINE void __dlist_add(struct dlist_node_t * _new,
	struct dlist_node_t * prev,
	struct dlist_node_t * next)
{
	next->prev = _new;
	_new->next = next;
	_new->prev = prev;
	prev->next = _new;
}

/**
 * dlist_add - add a new entry
 * @new: new entry to be added
 * @head: list head to add it after
 *
 * Insert a new entry after the specified head.
 * This is good for implementing stacks.
 */
INLINE void dlist_add(struct dlist_node_t *_new, struct dlist_node_t *head)
{
	__dlist_add(_new, head, head->next);
}

/**
 * dlist_add_tail - add a new entry
 * @new: new entry to be added
 * @head: list head to add it before
 *
 * Insert a new entry before the specified head.
 * This is useful for implementing queues.
 */
INLINE void dlist_add_tail(struct dlist_node_t *_new, struct dlist_node_t *head)
{
	__dlist_add(_new, head->prev, head);
}

/*
 * Delete a list entry by making the prev/next entries
 * point to each other.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
INLINE void __dlist_del(struct dlist_node_t * prev, struct dlist_node_t * next)
{
	next->prev = prev;
	prev->next = next;
}

/**
 * dlist_del - deletes entry from list.
 * @entry: the element to delete from the list.
 */
INLINE void dlist_del(struct dlist_node_t *entry)
{
	__dlist_del(entry->prev, entry->next);
}

/**
 * dlist_empty - tests whether a list is empty
 * @head: the list to test.
 */
INLINE int dlist_empty(struct dlist_node_t *head)
{
	return head->next == head;
}

/**
 * dlist_entry - get the struct for this entry
 * @ptr:	the &struct dlist_node_t pointer.
 * @type:	the type of the struct this is embedded in.
 * @member:	the name of the dlist_node_t within the struct.
 */
#define dlist_entry(ptr, type, member) \
	((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

/**
 * dlist_for_each	-	iterate over a list
 * @pos:	the &struct dlist_node_t to use as a loop counter.
 * @head:	the head for your list.
 */
#define dlist_for_each(pos, head) \
	for (pos = (head)->next; pos != (head); pos = pos->next)

/**
 * dlist_for_each_safe	-	iterate over a list safe against removal of list entry
 * @pos:	the &struct dlist_node_t to use as a loop counter.
 * @n:		another &struct dlist_node_t to use as temporary storage
 * @head:	the head for your list.
 */
#define dlist_for_each_safe(pos, n, head) \
	for (pos = (head)->next, n = pos->next; pos != (head); \
		pos = n, n = pos->next)

/**
 * list_for_each_prev	-	iterate over a list in reverse order
 * @pos:	the &struct dlist_node_t to use as a loop counter.
 * @head:	the head for your list.
 */
#define dlist_for_each_prev(pos, head) \
	for (pos = (head)->prev; pos != (head); \
		pos = pos->prev)

/**
 * dlist_for_each_prev_safe  -   iterate over a list safe in reverse
         order against removal of list entry
 * @pos:    the &struct dlist_node_t to use as a loop counter.
 * @n:      another &struct dlist_node_t to use as temporary storage
 * @head:   the head for your list.
 */
#define dlist_for_each_prev_safe(pos, n, head) \
    for (pos = (head)->prev, n = pos->prev; pos != (head); \
        pos = n, n = pos->prev)

/**
 * dlist_count - get the number of items
 * @head: the list to test.
 */
INLINE int dlist_count(struct dlist_node_t *head)
{
    struct dlist_node_t* pos;
    int i = 0;
    dlist_for_each(pos, head)
        i ++;
    return i;
}

#ifdef __cplusplus
}
#endif


#endif // end of #ifndef _DLIST_H_
