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
*    File Name: spar_setup.c
*
*           The Stackable Patch and Application Runtime
*
*    Abstract: C-runtime setup of this SPAR tier
*
********************************************************************
*/

#include "spar_utils.h"
#include "string.h"
#include "types.h"
#include "wiced_memory_pre_init.h"

/*****************************************************************
*   Definitions
*
*****************************************************************/
#ifndef SPAR_APP_SETUP
#error "You must define SPAR_APP_SETUP to indicate the application setup."
#endif

void SPAR_APP_SETUP(void);

/*****************************************************************
*   Function: spar_setup()
*
*   Abstract: Process the information in .secinfo, copying and
*   clearing sections as needed.
*
*
*****************************************************************/
#ifndef __GNUC__
#pragma arm section code = "spar_setup"
void SPAR_CRT_SETUP(void)
{
    typedef struct
    {
        UINT32 source;
        UINT32 target;
        UINT32 len;
    } armlink_copy_secinfo_t;

	extern void *_tx_initialize_unused_memory;
	extern UINT32 Region$$Table$$Base;
	extern UINT32 Region$$Table$$Limit;

	extern UINT32 Image$$SPAR_DRAM_ZI_AREA$$ZI$$Base;
	extern UINT32 Image$$SPAR_DRAM_ZI_AREA$$ZI$$Length;
	extern UINT32 Image$$first_free_section_in_spar_NV_RAM$$Base;
	extern char * idle_saveThreadxAvailMem;
  armlink_copy_secinfo_t *cpysecinfo;
  extern void install_libs(void);

  // Get the section info base of this spar slice
  UINT32 cpysecinfobase = (UINT32)&Region$$Table$$Base;
  UINT32 cpysecinfolim = (UINT32)&Region$$Table$$Limit;

  UINT32 clrsecbase = (UINT32)&Image$$SPAR_DRAM_ZI_AREA$$ZI$$Base;
  UINT32 clrseclen = (UINT32)&Image$$SPAR_DRAM_ZI_AREA$$ZI$$Length;
  UINT32 endofspar = (UINT32)&Image$$first_free_section_in_spar_NV_RAM$$Base;

  // Here we ought to assert that we're linked against the right
  // image, before we call memcpy/memset in ROM/Flash...

  // Did the images below us end up moving the current-top-of-memory
  // up to where we got linked? (allow some alignment slack)
  // SPAR_ASSERT_PANIC((unsigned int)&Image$$spar_iram_start$$Base >= idle_saveThreadxAvailMem
  //                   && (unsigned int)&Image$$spar_iram_start$$Base <= idle_saveThreadxAvailMem+32);


  if(cpysecinfobase != cpysecinfolim)
    {
      // Section info length is not zero
      // which means that there is RW data
      cpysecinfo = (armlink_copy_secinfo_t *)cpysecinfobase;
      memcpy((void *)cpysecinfo->target, (void *)cpysecinfo->source, cpysecinfo->len);
    }

  // Clear ZI section
  if(clrseclen != 0)
    memset((void *)clrsecbase, 0x00, clrseclen);

  install_libs();

  // And move avail memory above this spar if required
  // Note that if there are other spars will be placed with minimum
  // alignment (because of the linker option to IRAM_SPAR_BEGIN) and itself
  // is responsible for moving the avail mem ptr.
  idle_saveThreadxAvailMem = (char *)endofspar;

  // Call the application setup code
  SPAR_APP_SETUP();
}

#pragma arm section code

#else

/**
 * this weak symbol will have the default values for memory pre-init firmware allocations
 * declare this structure again, with no attribute, in app code
 * initialize with desired values to override
 */
WICED_MEM_PRE_INIT_CONTROL g_mem_pre_init __attribute__((weak)) =
{
    WICED_MEM_PRE_INIT_IGNORE,
    WICED_MEM_PRE_INIT_IGNORE,
    WICED_MEM_PRE_INIT_IGNORE,
    WICED_MEM_PRE_INIT_IGNORE,
    (unsigned char)WICED_MEM_PRE_INIT_IGNORE,
    (unsigned char)WICED_MEM_PRE_INIT_IGNORE,
    (unsigned char)WICED_MEM_PRE_INIT_IGNORE,
    (unsigned char)WICED_MEM_PRE_INIT_IGNORE,
};

ATTRIBUTE((section(".spar_setup")))
void SPAR_CRT_SETUP(void)
{
    extern void* spar_iram_bss_begin;
    extern unsigned spar_iram_data_length, spar_iram_bss_length;
    extern void* spar_irom_data_begin, *spar_iram_data_begin, *spar_iram_end;
    extern char* idle_saveThreadxAvailMem;
	extern void install_libs(void);

    if(((UINT32)&spar_irom_data_begin != (UINT32)&spar_iram_data_begin) && ((UINT32)&spar_iram_data_length != 0))
        memcpy((void*)&spar_iram_data_begin, (void*)&spar_irom_data_begin, (UINT32)&spar_iram_data_length);
    if((UINT32)&spar_iram_bss_length != 0)
    {
        memset((void*)&spar_iram_bss_begin, 0x00, (UINT32)&spar_iram_bss_length);
    }

    // install all patches and libs
    install_libs();

    wiced_memory_pre_init(&g_mem_pre_init);

    idle_saveThreadxAvailMem = (char *)(((UINT32)&spar_iram_end + 1024) & 0xFFFFFFF0);

    SPAR_APP_SETUP();
}
#endif
