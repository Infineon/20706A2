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

/********************************************************************************
*
* File Name: hiddcfa.h
*
*******************************************************************************/

#ifndef __HIDD_CFA_H_
#define __HIDD_CFA_H_

#include "cfa.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>

enum
{
    LOW,
    HIGH
};

/**  \addtogroup appSupport
*/
/*! @{ */
/**
*  This module extends the standard CFA implementation to provide
*  extra Operating System and Core services which are useful to
*  HID applications.
*
*/

/****************************************************************************
 * Interrupts
 ****************************************************************************/
extern unsigned int hiddcfa_cpuIntDisable(void);
extern void hiddcfa_cpuIntEnable(unsigned int);

/// Put this at the beginning of the function which
/// will invoke HIDDCFA_ARM_INT_DISABLE/ENABLE
#define HIDDCFA_CPU_INT_SAVE_AREA register unsigned int  cpuIntSave;
/// Disable all interrupts to the CPU
#define HIDDCFA_CPU_INT_DISABLE cpuIntSave = hiddcfa_cpuIntDisable();
/// Enable all interrupts to the CPU
#define HIDDCFA_CPU_INT_ENABLE hiddcfa_cpuIntEnable(cpuIntSave);

/****************************************************************************
 * Enums
 ****************************************************************************/
typedef enum
{
    HIDDCFA_BER_1M,
    HIDDCFA_BER_2M_EDR,
    HIDDCFA_BER_3M_EDR
} HIDDCFA_LNK;

enum
{
    INVALID_CORE_CONN_ID = 0xFF
};

enum
{
    INVALID_PICONET_INDEX = 0xFF
};

enum
{
    HIDDCFA_PCX_TO_NAT,
    HIDDCFA_NAT_TO_PCX
};

enum
{
    WAKE_SOURCE_GPIO    = (1 << 0),
    // Wake source GPIO and LHL are the same
    WAKE_SOURCE_LHL     = WAKE_SOURCE_GPIO,
    WAKE_SOURCE_KEYSCAN = (1 << 30),
    WAKE_SOURCE_QUAD    = (int)(1UL << 31)
};

typedef enum
{
    CPU_CLK_SPEED_96MHZ,
    CPU_CLK_SPEED_48MHZ,
    CPU_CLK_SPEED_32MHZ,
    CPU_CLK_SPEED_24MHZ,
    CPU_CLK_SPEED_16MHZ,
    CPU_CLK_SPEED_12MHZ,
    CPU_CLK_SPEED_6MHZ,
    CPU_CLK_SPEED_4MHZ,
    CPU_CLK_SPEED_1MHZ
} CLOCK_SPEED;

enum
{
    LPO_CLK_INTERNAL,
    LPO_CLK_EXTERNAL,
    LPO_CLK_CRYSTAL,
    LPO_NO_SELECTED,
    LPO_32KHZ_OSC,
    LPO_MIA_LPO
};

/****************************************************************************
 * BD_ADDR
 ****************************************************************************/
enum
{
     HIDDCFA_BD_ADDRESS_SIZE = 6
};

typedef UINT8 BD_ADDR[HIDDCFA_BD_ADDRESS_SIZE];

typedef struct
{
    UINT8   selLPOSrc;
    // selSlaveLPOSrc
    // If TRUE: Will continue to use the selected LPO SRC in Sniff.
    // If FALSE: Will use the LPX in Sniff.
    BOOLEAN selSlaveLPOSrc;
    UINT16  driftRate;
}HIDCFA_SELECT_LPO;

typedef struct
{
    UINT16               sniffIntervalLimitLPO;
    HIDCFA_SELECT_LPO    selLPO_Default;
    HIDCFA_SELECT_LPO    selLPO_SniffIntervalLow;
    HIDCFA_SELECT_LPO    selLPO_SniffIntervalHigh;

}HIDDCFA_SELECT_LPO_CONFIGURE;

typedef enum
{
    FAST_SENSOR_COPY_COMPLETE,
    FAST_SENSOR_COPY_ENTRY_NOT_FOUND,
    FAST_SENSOR_COPY_SERIAL_FLASH_NOT_DETECTED,
}  tFAST_SENSOR_COPY_RESULT;



/****************************************************************************
 * Mutexes
 ****************************************************************************/
/// Mutex structure, opaque contents.
typedef struct hiddcfa_mutex_st
{
    UINT32 opaque[14];
} hiddcfa_mutex;

/****************************************************************************
 * App specific config item
 ****************************************************************************/
typedef struct
{
    UINT8* app_specific_config_item;
    UINT16 app_specific_config_item_len;
    UINT8* app_specific_sdp_db_config_location;
    UINT16 app_specific_sdp_db_config_len;
    UINT8* app_specific_sdp_db_location;
} HiddcfaAppSpecificConfig;

extern HiddcfaAppSpecificConfig hiddAppSpecConfig;

/****************************************************************************
 * Sensor Data config item
 ****************************************************************************/
#define MAX_NUM_SENSORS   10
typedef PACKED struct
{
    UINT16 num_of_sensors;
    UINT16 sensor_data_length[MAX_NUM_SENSORS];
    UINT8* sensor_data_config_location;
    UINT16 sensor_data_config_length;
}HiddcfaSensorDataConfig;

extern HiddcfaSensorDataConfig hiddSensorDataConfig;

typedef  struct
{
    UINT8* buffer;
    UINT8* config_location;
    UINT16 length_total;
    UINT16 length_remain;
} HIDDCFA_SENSOR_DATA;

#define HIDDCFA_SENSOR_DATA_READ_LENGTH   100




/// In hiddcfa_mutexGet(): wait forever for the mutex.
#define HIDDCFA_WAIT_FOREVER 0xFFFFFFFFUL
/// Any return code but HIDDCFA_SUCCESS means "error".
#define HIDDCFA_SUCCESS 0

/// For use with hiddcfa_mutexCreate().
#define HIDDCFA_INHERIT 1
/// For use with hiddcfa_mutexCreate().
#define HIDDCFA_NO_INHERIT 0

#define VS_LOCATION_EEPROM          0x10
#define VS_LOCATION_SERIAL_FLASH    0x40
#define VS_LOCATION_PFLASH          0x20

/* Application event for serialization */
//mpaf events
#define HCIFW_EV_CSA_SERIALIZE         (0x00000001)
#define HIDD_APP_TIMER_EVENT           (0x00000002)

UINT32 hiddcfa_mutexCreate(hiddcfa_mutex*, const char* name, UINT32 inherit);
UINT32 hiddcfa_mutexGet(hiddcfa_mutex*, UINT32 wait);
UINT32 hiddcfa_mutexPut(hiddcfa_mutex*);

/****************************************************************************
 * Delays and clocks
 ****************************************************************************/

#define BTTICKS_PER_SEC 3200
#define BTTICKS_PER_OSTICK (BTTICKS_PER_SEC / TICKS_PER_SEC)
#define MS_PER_SEC 1000
BOOL32 hiddcfa_serialize(int priority, void *fn, void* data);
void hiddcfa_delayUs(UINT32 delay);
UINT16 hiddcfa_currentTimeUs(void);
UINT32 hiddcfa_currentNativeBtClk(void);
void hiddcfa_initFixedTimingSource(void* opaqueCtxt);
void hiddcfa_disableFixedTimingSource(void* opaqueCtxt);
UINT32 hiddcfa_snapAndGetBtSlotsSinceLastFromFixedTimingSource(void* opaqueCtxt);
void hiddcfa_currentNativeBtClkAndPhase(UINT32 *pClk, UINT32 *pPhaseCount);
UINT32 hiddcfa_currentPiconetBtClk(UINT32 piconetIndex);
void hiddcfa_currentPiconetBtClkAndPhase(UINT32 piconetIndex, UINT32 *pClk,
    UINT32 *pPhaseCount);
UINT32 hiddcfa_getPiconetIndexFromBdAddr(const BD_ADDR* bdAddr);
UINT32 hiddcfa_getPiconetIndexFromMulticast(void);
void hiddcfa_convertFutureBtClk(UINT32 piconetIndex, UINT32 *pFutureClk,
    UINT32 *pFuturePhaseCount, UINT32 direction);

INT32 hiddcfa_diffBtClks(UINT32 from, UINT32 to);
UINT32 hiddcfa_BtClksSince(UINT32 before);


/****************************************************************************
 * Event logging
 ****************************************************************************/
#ifdef TX_ENABLE_EVENT_LOGGING

void hiddcfa_logEvent(int type, const char* msg8, UINT32 data1, UINT32 data2);

#define HIDDCFA_LOGEVENT0()                             \
    hiddcfa_logEvent(HIDDCFA_EVENT_UNKNOWN,0,0,0)

#define HIDDCFA_LOGEVENT1(type)                 \
    hiddcfa_logEvent(type,0,0,0)

#define HIDDCFA_LOGEVENT2(type,msg8)            \
    hiddcfa_logEvent(type,msg8,0,0)

#define HIDDCFA_LOGEVENT3(type,msg8,data1)     \
    hiddcfa_logEvent(type,msg8,data1,0)

#define HIDDCFA_LOGEVENT4(type,msg8,data1,data2)        \
    hiddcfa_logEvent(type,msg8,data1,data2)

#else
#define HIDDCFA_LOGEVENT0() // dbguart_print_word_inAscii("\n$\n", 0);
#define HIDDCFA_LOGEVENT1(type) //dbguart_print_word_inAscii("\n@=\n", type);
#define HIDDCFA_LOGEVENT2(type,msg8) //dbguart_print_word_inAscii(msg8, type);
#define HIDDCFA_LOGEVENT3(type,msg8,info1) //dbguart_print_word_inAscii(msg8, type);dbguart_print_word_inAscii(msg8, info1);
#define HIDDCFA_LOGEVENT4(type,msg8,info1,info2) //dbguart_print_word_inAscii(msg8, type);dbguart_print_word_inAscii(msg8, info1);
#endif

/***********************************************************************

To use the Event Analyzer (mevgui), you need to have definitions in
the tool for these events.

You can use bld/threadx.mc for this, which I maintain for this
purpose. Mevgui hardcodes the path, you will need to copy it by hand
to:
       C:\GHS\arm423\defaults\event_analyzer\threadx.mc

The key section might look like this:

MEV_Event:0x4:0x1:HIDDCFA Unknown:unknown:MEV_Extra="data1=%4X data2=%4X %C":MEV_Visible
MEV_Event:0x4:0x2:HIDDCFA Generic:genericevent:MEV_Extra="data1=%4X data2=%4X %C":MEV_Visible
MEV_Event:0x4:0x3:HIDDCFA Attention:attention:MEV_Extra="data1=%4X data2=%4X %C":MEV_Visible
MEV_Event:0x4:0x4:HIDDCFA User Action:userevent:MEV_Extra="data1=%4X data2=%4X %C":MEV_Visible
MEV_Event:0x4:0x5:HIDDCFA Error:error:MEV_Extra="data1=%4X data2=%4X %C":MEV_Visible
MEV_Event:0x4:0x6:HIDDCFA Timer:clock:MEV_Extra="data1=%4X data2=%4X %C":MEV_Visible

Feel free to add more specific events. It's just a pain to maintain
three places -- here, threadx.mc, and the code that uses it -- so I
tend to use these general ones.

**********************************************************************/

#define HIDDCFA_EVENT_UNKNOWN           1
#define HIDDCFA_EVENT_GENERIC           2
#define HIDDCFA_EVENT_ATTENTION         3
#define HIDDCFA_EVENT_USER_ACTION       4
#define HIDDCFA_EVENT_ERROR             5
#define HIDDCFA_EVENT_TIMER             6

/****************************************************************************
 * Memory dumping
 ****************************************************************************/

void hiddcfa_srecDump(UINT8* real_src_addr, UINT32 len, UINT32 srec_start_addr);

/****************************************************************************
 * Callbacks serialization on CSA thread
 ****************************************************************************/

#define HIDDCFA_FREE_BUFFER 42
#define HIDDCFA_NO_ACTION   43

#define HIDDCFA_NUM_SRZN_QUEUES 2
#define HIDDCFA_SRZN_PRIORITY_HIGH 0
#define HIDDCFA_SRZN_PRIORITY_LOW ((HIDDCFA_NUM_SRZN_QUEUES)-1)

//BLTH02940572 ADK release
#ifndef MPAF_TRACE_ENABLE
#define MPAF_DBG_TRACE(_level, _string)
#define MPAF_DBG_TRACE_T1(_level, _string, _param)
#define MPAF_DBG_STRACE(_string)
#define MPAF_DBG_TRACE_ARR(_level, _string, array, len)
#define MPAF_DBG_TRACE_BDA(_level, string, bdaddr)
#define MPAF_DBG_TRACE_COD(_level, string, cod)
#endif //MPAF_TRACE_ENABLE

#define MPAF_HIDD_TRACE(msg)             MPAF_DBG_TRACE(HIGH, msg)
#define MPAF_HIDD_TRACE_T1(msg, arg)     MPAF_DBG_TRACE_T1(HIGH, msg, arg)

#define MPAF_HIDD_ERROR(msg)             MPAF_DBG_TRACE(CRIT, msg)
#define MPAF_HIDD_ERROR_T1(msg, arg)     MPAF_DBG_TRACE_T1(CRIT, msg, arg)

void hiddcfa_init(void);

/****************************************************************************
 * serial flash access functions
 ****************************************************************************/
BOOLEAN hiddcfa_sflashErase(void);
BOOLEAN hiddcfa_sflashCheck(void);
BOOLEAN hiddcfa_sflashRead(void* buf, UINT32 offset, UINT32 len);
BOOLEAN hiddcfa_sflashWrite(void* buf, UINT32 offset, UINT32 len);

/****************************************************************************
 * EEPROM access functions
 ****************************************************************************/
BOOLEAN hiddcfa_eepromRead(void* buf, UINT32 offset, UINT32 len);
BOOLEAN hiddcfa_eepromWrite(void* buf, UINT32 offset, UINT32 len);

/****************************************************************************
 * Application specific config access functions
 ****************************************************************************/
BOOLEAN hiddcfa_readAppSpecificConfig(void* buf, UINT16 len);
UINT8*  hiddcfa_getSdpDbFromConfig(void);
/****************************************************************************
 * Utility functions
 ****************************************************************************/
UINT32 hiddcfa_readBer(HIDDCFA_LNK lnkType);
BOOLEAN hiddcfa_readRawRssi(const BD_ADDR* bdAddr, INT8* rawRssi);
BOOLEAN hiddcfa_readSupervisionTimeout(const BD_ADDR* bdAddr, UINT16* sto);
void hiddcfa_usbTranceiverSuspendControl(BOOLEAN suspend);
void hiddcfa_convertBdAddrFromStackToCoreFormat(const BD_ADDR* bdAddr, UINT8* adrBytes);
BYTE hiddcfa_getCoreConnIdFromBdAddr(const BD_ADDR* bdAddr);
void hiddcfa_flushAclPackets(BYTE coreConnId);
void hiddcfa_setAutomaticFlushTimeoutInStackToMax(const BD_ADDR* bdAddr);
int hiddcfa_patchReplace(void* oldFunc, void* newFunc);
UINT32 hiddcfa_getSniffInterval(void);
void hiddcfa_hwReset(void);

void hiddcfa_setEIR(UINT8 *eirData, UINT32 length);
// Sample code of how this can be called is also given below:
/*
#include "hiddcfa.h"

void setEirMessage(void)
{
        // Maximum size is 240 bytes, but can be
        // smaller as long as it is big enough
        // to hold EIR data
        UINT8 eirData[EIR_MAX_PAYLOAD_LEN];

        char *name = "HELLOHELLOHELLO";
        memset(eirData, 0x00, sizeof(eirData));

        UINT8 *dataPtr = eirData;

        // EIR data structure len
        *dataPtr++ = strlen(name) + 1;

        // EIR data type
        *dataPtr++ = HCI_EIR_COMPLETE_LOCAL_NAME_TYPE;

        // EIR data
        memcpy(dataPtr, name, strlen(name));

        // length is sum of structure len, data type, and EIR data
        hiddcfa_setEIR(eirData, strlen(name) + 2);
}
*/

/****************************************************************************
 * Link configuration function
 ****************************************************************************/
void hiddcfa_setDefaultLinkSupervisionTimeout(UINT16 slots);

/****************************************************************************
 * GPIO Wakeup source control of the PMU
 ****************************************************************************/
void hiddcfa_pmuActivityWakeupEnable(BOOLEAN enable);
UINT32 hiddcfa_getHidWakeSources(void);
void hiddcfa_setHidWakeSources(UINT32 sources);

extern void hiddcfa_changeSystemClock ( CLOCK_SPEED cpu_speed );

/****************************************************************************
 * BTLPM LPO source selection
 ****************************************************************************/
void hiddcfa_btLpmModeChangeInd(UINT8 mode, UINT16 interval, UINT8 asymmetricMultiplier);
void hiddcfa_changeLPOSource(UINT8 pmu_clkSource, BOOLEAN selSlaveLPOSrc, UINT16 driftRate);
int hiddcfa_calibrateMiaLpo(UINT32 lpoCalibrationCount);
void hiddcfa_updatePmuSettings(BOOLEAN updatePmuSetting);
void hiddcfa_setTestMode(void);

/****************************************************************************
 * Wrapper functions
 ****************************************************************************/
void hiddcfa_petWatchDog(void);
UINT32 hiddcfa_readRemoteTBFCFeature(const BD_ADDR* bdAddr);

/****************************************************************************
 * Sensor Data Read functions
 ****************************************************************************/
BOOLEAN hiddcfa_InitSensorDataFromConfig(UINT8 sensorIndex);
BOOLEAN hiddcfa_isSensorDataAvailable(UINT8 sensorIndex);
BOOLEAN hiddcfa_getSensorDataFromConfig(UINT8 **buffer, UINT16* readlength, UINT8 sensorIndex);
tFAST_SENSOR_COPY_RESULT hiddcfa_FastSensorCopy(UINT8 sensorIndex);

/****************************************************************************
 * CSA thread sleep functions
 ****************************************************************************/
void hiddcfa_CSA_Sleep_timer_init(void);
void hiddcfa_CSA_Sleep_TimerCB(INT32 callbackArg);
void hiddcfa_CSA_ThreadSleep(UINT32 sleep_tick);

/****************************************************************************
 * CSA change priority functions
 ****************************************************************************/
/////////////////////////////////////////////////////////////////////////////////
// Set the priority of CSA thread
//
// \param new_priority - new priority of CSA thread
//
// \return previous priority of CSA thread
//
// WARNING: this function is meant to be used to restore the priority
//          to its previous value after changing the priority through
//          hiddcfa_set_CSA_priority_low() or hiddcfa_set_CSA_priority_high().
//          Calling this function with values other than those returned by
//          hiddcfa_set_CSA_priority_low() or hiddcfa_set_CSA_priority_high()
//          can cause system instability.
/////////////////////////////////////////////////////////////////////////////////
unsigned int hiddcfa_set_CSA_priority(unsigned int new_priority);

/////////////////////////////////////////////////////////////////////////////////
// Set the priority of CSA thread to its default value, which is lower than that
// of LM thread
//
// \return previous priority
/////////////////////////////////////////////////////////////////////////////////
unsigned int hiddcfa_set_CSA_priority_low(void);

/////////////////////////////////////////////////////////////////////////////////
// Set the priority of CSA thread to be higher than that of LM thread
//
// \return previous priority
/////////////////////////////////////////////////////////////////////////////////
unsigned int hiddcfa_set_CSA_priority_high(void);


/****************************************************************************
 * Switch from SSR to ACTIVE Sniff functions
 ****************************************************************************/
void hiddcfa_switchSSRToActiveSniff(const BD_ADDR* bdAddr);
int hiddcfa_deferSSRtoActiveSniff(void* ltch);

//===================================================================
// Function : hiddcfa_ForceActiveSniff
//
// Call this function when you need BCS to bypass SSR and stay in Active Sniff
// \param
//  FALSE: BCS switchs between SSR and active sniff (default)
//  TRUE : BCS stays in active sniff
//===================================================================
void hiddcfa_ForceActiveSniff(BOOLEAN enable);


//===================================================================
// Functions : void hiddcfa_enableVsSectionAccess
//
//  ~ This function should be called from the Application create function.
//  ~ This function should be called before the BT Pairing list Class is initialized.
//  ~ This function should be called if the Config and FW is downloaded directly to the Run Time RAM
//  ~ This function should be called if Access to VS section is also desired. ( EEPROM or Serial Flash)
//
// If there is no NV storage connected to the device, please do not call this function.
//
// Example code:
// hiddcfa_enableVsSectionAccess(VS_LOCATION_EEPROM,0x00C0, 0x0200);
// hiddcfa_enableVsSectionAccess(VS_LOCATION_SERIAL_FLASH,0x001000, 0x1000);
//===================================================================
void hiddcfa_enableVsSectionAccess(UINT8 NV_Storage, UINT32 VS_location, UINT16 VS_length);

/****************************************************************************
 * Use an accurate HW timer - timer2 as a 1-shot timer
 NOTE!!! NOT suggested for application use. It does not have any critical section protection.
               Use it only if your application must need an accurate timer (i.e. no way to work around).
               You need to code the callback func carefully to avoid any race condition/deadlock.
 ****************************************************************************/
typedef void (*HIDDCFA_callbackfn)(void*);
//===================================================================
// Functions : void hiddcfa_registerforHWTimer2
//
// The function SHOULD be called in the Application to register the timeout callback function.
// param: callback function
// param: userdata (can be class instance)
//===================================================================
void hiddcfa_registerforHWTimer2(HIDDCFA_callbackfn callback,void* userdata);
//===================================================================
// Functions : hiddcfa_startHWTimer2
//
// The function SHOULD be called in the Application to start the 1-shot timer. Make sure the app already
// registered the callback function.
// param: timer period in micro seconds.
//===================================================================
void hiddcfa_startHWTimer2(UINT32 microseconds);
//===================================================================
// Functions : hiddcfa_stopHWTimer2
//
// The function should be called in the Application to abort the 1-shot timer, in case the app does not want
// to wait for the timer to timeout
//===================================================================
void hiddcfa_stopHWTimer2(void);
//===================================================================
// Functions : hiddcfa_HWTimer2IntHandler
//
// The function is the HW Timer2 interrupt handler, should be called in the irq.c.
//===================================================================
void hiddcfa_HWTimer2IntHandler(void);


//=======================================================================
// Function : hiddcfa_switch_to_legacy_page
//
// Call this function with param "TRUE",
// if you decide to switch to Legacy Page.
// To switch back to TBFC page the function
// needs to be called again with param "FALSE".
//
// Once switched to legacy page, the device will continue to use
// Legacy page , till the App calls this function again and passes in
// a "FALSE".
//
// When device is connected to non-LLR Host, this API has no meaning.
//
// \param
//  FALSE: Will switch to TBFC page
//  TRUE : Will switch to Legacy page
//=====================================================================
void hiddcfa_switch_to_legacy_page(BOOLEAN legacy_page);

//=====================================================================
// Function : hiddcfa_is_tbfc_page_blocked
//
// This function returns :
//  TRUE : if application has blocked TBFC page
//  FALSE: if application has NOT blocked TBFC Page
//
// This function is directly related to the function
// "hiddcfa_switch_to_legacy_page", that can be called
// by the application to set the choice for TBFC page
// or Legacy Page.
//
//=====================================================================
BOOLEAN hiddcfa_is_tbfc_page_blocked();


//===================================================================
// Functions :
//      hiddcfa_ChangeLPOSrcto32KHz
//
//  This function is used to switch to 32 Khz LPO.
//  Typically called at the time of App creation.
//===================================================================
void hiddcfa_ChangeLPOSrcto32KHz(void);



void hiddcfa_clearPmuWakeIntStatus(void);


/****************************************************************************
 * Add an API to select LPX in Sniff.
 ****************************************************************************/
//===================================================================
// Functions : void hiddcfa_SelectLPXinSniff(void)
//
// The function SHOULD be called in the Application create function
// if LPX is desrired during Connection/Sniff instead of internal LPO.
// By Calling this function, the PMU will set the parameters
// accordingly to use LPX when the device is in Sniff.
//===================================================================
void hiddcfa_SelectLPXinSniff(void);

//===================================================================
// Function : hiddcfa_UseLPXinSniff
//
// Call this function when you need to use LPX in Sniff
// \param
//  FALSE: Will use LPO in Sniff
//  TRUE : Will use LPX in Sniff
//===================================================================
void hiddcfa_UseLPXinSniff(BOOLEAN enable);


/****************************************************************************
 * Add an API for CRC16 and CRC32.
 ****************************************************************************/
//===================================================================
// Continues a 16-bit CRC computation
//
// \param[in/out] crc Pointer to the initial CRC value passed when
// invoking the function and to the final CRC produced by the function.
// \param[in] data Pointer to array of bytes.
// \param[in] len data's len (in bytes).
//===================================================================
void hiddcfa_updateCRC16(UINT16 * crc, const UINT8 * array, int len);


//===================================================================
//Continues a 16-bit CRC computation
//
//\param[in] data Pointer to array of bytes.
//\param[in] len Data's len (in bytes).
//
//\return Evaluated CRC.
//===================================================================
UINT16 hiddcfa_genCRC16(const UINT8 * data, int len);

//===================================================================
// Continues a 32-bit CRC computation
//
// \param[in/out] crc Pointer to the initial CRC value passed when
// invoking the function and to the final CRC produced by the function.
// \param[in] data Pointer to array of bytes.
// \param[in] len data's len (in bytes).
//===================================================================
void hiddcfa_updateCRC32(UINT32 * crc, const UINT8 * data, int len);


//===================================================================
// Continues a 32-bit CRC computation
//
// \param[in] data Pointer to array of bytes.
// \param[in] len data's len (in bytes).
//
// \return Evaluated CRC.
//===================================================================
UINT32 hiddcfa_genCRC32(const UINT8 * data, int size);

//===================================================================
// Function : hiddcfa_lower_CSA_priority
//
// call this function call to change the current task prority
//
// \param
//  FALSE: change to higher priority
//  TRUE : change to lower priority
//===================================================================
void hiddcfa_lower_CSA_priority(BOOLEAN lower_priority);


//=====================================================================
// Function : hiddcfa_disable_AFHChannelAssessMode
//
// The function disabled the Slave AFH channel Assesment.
// This API can be called at the Application start up
// (after Activate App)
//
//=====================================================================
void hiddcfa_disable_AFHChannelAssessMode(void);

//===================================================================
// Functions :
//      hiddcfa_powerDown32KHz
//
//  This function is used to Power down the 32 Khz LPO.
//  Typically called when the device is about to go to HID OFF.
//
//  !! NOTE: Only applicable for Targets that use 32 Khz LPO
//
// ==================
//  Typical use:
// ==================
//           void sampleKb32App::enteringDiscLowPowerMode(UINT8 discLowPowerMode)
//          {
//              // Power down the 32Khz Crystal before going to HID OFF
//              hiddcfa_powerDown32KHz();
//          }
//
//===================================================================
void hiddcfa_powerDown32KHz(void);

//===================================================================
// Functions : void hiddcfa_enableHwControlVoltageSwitching(void)
//
//This function would enable HW to switch the voltage to 1.04v when we will go to sleep and restore when
//we wake up.
//===================================================================
void hiddcfa_enableHwControlVoltageSwitching(void);

//===================================================================
// function: hiddcfa_HandleFactoryCommitBdAddr()
//
// This function provides an API to handle the factory Commit BD Addr
//
// =======================================
// Typical Use: ( from Application code)
// =======================================
// step 1: Fill in the desired Bd Addr.
//    BD_ADDR tempBdAddr;
//    tempBdAddr[0]  = 0xAA;
//    tempBdAddr[1]  = 0xBB;
//    tempBdAddr[2]  = 0xCC;
//    tempBdAddr[3]  = 0xDD;
//    tempBdAddr[4]  = 0xEE;
//    tempBdAddr[5]  = 0xFF;
//
// Step 2: Call the API to commit this bd addr
//   hiddcfa_HandleFactoryCommitBdAddr(tempBdAddr);
//
// ===================================================================

void hiddcfa_HandleFactoryCommitBdAddr(const BD_ADDR *bdAddr);

//===================================================================
// Functions : void hiddcfa_appPollDisable(void);
//
//Disable app poll Notification. Meant to be called by the client,
//* e.g. CSA.
//===================================================================
void hiddcfa_appPollDisable(void);

//===================================================================
// Functions : void hiddcfa_appPollEnable(void (*clientCallback)(void *, UINT32),
//                          UINT32 clientContext,
//                          UINT16 defaultPeriod);
//
//Application poll Notification
//===================================================================
void hiddcfa_appPollEnable(void (*clientCallback)(void *, UINT32),
                          UINT32 clientContext,
                          UINT16 defaultPeriod);

//===================================================================
// Functions : UINT32 hiddcfa_getTimerCount(void);
//
//return irq timer counter
//===================================================================
UINT32 hiddcfa_getTimerCount(void);


#ifdef __cplusplus
}
#endif


void hiddcfa_TxOpNotifEnable(UINT8* bdAddr, void (*clientCallback)(void*, UINT32), UINT32 clientContext, INT16 offset, UINT16 defaultPeriod);
void hiddcfa_TxOpNotifDisable(UINT8* bdAddr);



/****************************************************************************/

/* @}  */


#endif
