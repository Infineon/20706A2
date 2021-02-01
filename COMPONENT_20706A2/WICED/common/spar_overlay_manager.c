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
/*
********************************************************************
*    File Name: spar_overlay_manager.c
*
*           The Stackable Patch and Application Runtime's overlay manager function.
*
*    Abstract: The overlay manager wrapper around the overlay services provided
*             by the ROM/patches.
*
********************************************************************
*/

#include "spar_utils.h"
#include "string.h"
#include "types.h"

/*****************************************************************
*   Definitions
*
*****************************************************************/
extern void spar_ovm_load_and_exec(unsigned int ov_id, unsigned int* dest);
extern void overlay_manager_Load(unsigned int id);
/*****************************************************************
 *   Function: spar_ovm_load_and_exec()
 *
 *   Abstract: Processes the information retrieved
 *
 *
 *****************************************************************/
#ifndef __GNUC__
// Loads the given indexed overlay and invokes the destination function.
// Will return directly to the original caller. Currently does not check
// for crossreferences acrosses overlays (reference counting is perhaps
// the simplest thing to do, but will mean return to this and so reducing
// speed a bit and increasing complexity and RAM used by the overlay manager).
// The per-function trampoline, per-file trampoline and this load-exec function logically
// form one single function. The reason we split these instructions up is to save space
// at the cost of a few extra cycles.
__asm void spar_ovm_load_and_exec(unsigned int ov_id, unsigned int* dest)
{
	IMPORT overlay_manager_Load;
	// The call to this came in  after a PUSH LR by the trampoline followed by
	// a B.W. So there is no need to preserve LR here. The trampoline also preserved
	// the original caller's R0-R4. R0 has the overlay index and R1 has the function to
	// be called.
	BL  overlayManager_Load;   // R0 already has the overlay index. Just call the loader.
	LDR R12, [R4, #0];         // Dereference the destination function pointer.
	POP {R0 - R4, LR};         // Undo what the trampoline did so that the stack is as expected by the real target.
	BX  R12;                   // Invoke the real function called, it will return to caller.
}

#else
void overlay_manager_Load(unsigned int id)
{

}
// No prologue/epilogue required for this function because it is implemented across multiple symbols.
__attribute__((naked))
void spar_ovm_load_and_exec(unsigned int ov_id, unsigned int* dest)
{
	// At function entry, R0 has the overlay index and R1 has the address of the real function definition.
	// LR was already pushed and the parameters that we passed are also in the stack. Call the underlying
	// overlay manager, prepare the scratch register with the real desitnation function pointer, restore
	// parameters to it and the return addres and then jump to the function. Will return to real caller.
	asm volatile
		(
			"bl  overlay_manager_Load\n\t"
			"mov r12, r4\n\t"
			"pop {r0, r1, r2, r3, r4, lr}\n\t"
			"bx  r12" ::: "r12"
		);
}
#endif
