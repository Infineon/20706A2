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
* List of parameters and defined functions needed to access the
* Inter-Integrated Circuit (I2C, IIC) Electrically Erasable
* Programmable Read-Only Memory (EEPROM) interface driver.
*
*/

#ifndef __WICED_I2CEEPROM_H__
#define __WICED_I2CEEPROM_H__

#include "seepdrv.h"
#include "wiced.h"

/**  \addtogroup I2CEEPROMInterfaceDriver I2C EEPROM Interface
* \ingroup I2CDriver
* @{
*
* Defines a driver for the I2C EEPROM interface. The driver is responsible for
* interfacing with an EEPROM module via the I2C bus, with its main purpose
* being data handling operations. For instance, any unused space (from the
* system partition) can be used for any purpose to store and access data. It
* is a handy way for an app to save information to non-volatile storage.
*
* Similar to the Serial Flash Interface Driver, this driver includes checks to
* ensure safe data handling operation--it will not allow any write operations
* to take place within active sections (i.e., sections that the system
* currently uses for boot, etc). Note that read operations are unrestricted.
* Please reference the Kit Guide for more information regarding
* these active sections, their importance, and what roles they play in the
* system.
*

******************************************************************************
*** Parameters.
***
*** The following parameters are used to configure the driver or define
*** return status. They are not modifiable.
******************************************************************************

// Status for EEPROM operations.
@verbatim
#define DRV_STATUS_SUCCESS           0x00
#define DRV_STATUS_NO_ACK            0x01
#define DRV_STATUS_INVALID_ADDR      0xFF
@endverbatim
**/

/******************************************************************************
*** Function prototypes.
******************************************************************************/

///////////////////////////////////////////////////////////////////////////////
/// Initialize the I2C lines and low-level EEPROM Driver.
/// Call this before performing any operations.
///
/// \param none
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_ieeprom_init(void);

///////////////////////////////////////////////////////////////////////////////
/// Sets the size of the EEPROM module in bytes, used for bounds checking.
/// The default is 32768 bytes (256 kBit)
///
/// \param size - Size of the installed module in bytes.
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_ieeprom_set_size( uint32_t size );

///////////////////////////////////////////////////////////////////////////////
/// Load data from a certain location on the EEPROM module into
/// memory.
///
/// \param eepromAddress - The starting source address on the EEPROM.
/// \param readCount     - The number of bytes to read.
/// \param buffer        - Pointer to destination data buffer.
/// \param deviceAddress - The source slave address.
///
/// \return Success[0] or no ack[1].
///////////////////////////////////////////////////////////////////////////////
uint8_t wiced_hal_ieeprom_read( uint16_t eepromAddress,
                                uint16_t readCount,
                                uint8_t* buffer,
                                uint8_t  deviceAddress );


///////////////////////////////////////////////////////////////////////////////
/// Write data from memory to a certain location on the EEPROM module.
///
/// (!) Please ensure that the address and (address + length) of data to be
/// written does not go beyond the size of the memory module.
///
/// (!) Note that this function will not allow corruption of certain memory
/// locations, such as currently active sections (boot sectors) and sections
/// required for the proper function of the Bluetooth subsystem.
///
/// \param eepromAddress - The starting destination address on the EEPROM.
/// \param writeCount    - The number of bytes to write.
/// \param buffer        - Pointer to destination data buffer.
/// \param deviceAddress - The destination slave address.
///
/// \return Success[0x00] or no ack[0x01] or invalid eepromAddress/invalid
/// length[0xFF].
///////////////////////////////////////////////////////////////////////////////
UINT8 wiced_hal_ieeprom_write(uint16_t eepromAddress,
                              uint16_t writeCount,
                              uint8_t* buffer,
                              uint8_t  deviceAddress);

/* @} */

#endif // __WICED_I2CEEPROM_H__
