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
