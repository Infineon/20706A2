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
*    File Name: agCommonDriver.h
*
*    Abstract: This file defines a driver for the common Agilent optical
*              motion sensor.
*
*    $History:$
*
********************************************************************
*/

#ifndef __AG_COMMON_DRV_H__
#define __AG_COMMON_DRV_H__

#include "hidconfig.h"
#include "hiddcfa.h"
#include "spi.h"
#include "gpiodriver.h"
#include "planarmotioninterface.h"


/**  \addtogroup AGCommon
 *  \ingroup AglientOpticalSensorDriver
*/
class AgCommonDriver : public PlanarMotionInterface
{

public:

        AgCommonDriver(SpiInterface *spidrv,
                       const AgSensorRegSeq *agIDCheckSeq,
                       UINT8                agIDCheckSeqSize,
                       const AgSensorRegSeq *agResetSeq,
                       UINT8                agResetSeqSize,
                       const AgSensorRegSeq *agPowerUpSeq,
                       UINT8                agPowerUpSeqSize,
                       const AgSensorRegSeq *agPowerDownSeq,
                       UINT8                agPowerDownSeqSize
                       );

    /// Structure of the 7050 burst motion report
    struct BurstMotionReport
    {
	///  indicates if any motion is detected
        UINT8    motion;
        ///  the accumulated X motion
        INT8    x;
	///  the accumulated Y motion
        INT8    y;

        /// reserved
        UINT8    reserved[4];
    };

    void reset(void);
    virtual void getMotion(INT16 *x, INT16 *y, BYTE maxReads);
    virtual void turnOff(void);
    virtual void turnOn(void);
    virtual void registerForInterrupt(void (*userfn)(void*, UINT8), void* userdata);
    virtual void burstRead(BYTE *buf, BYTE bytesToRead);

    BYTE readReg(UINT8 regAddress);
    void writeReg(UINT8 regAddress, BYTE val);

protected:

    ~AgCommonDriver();
    void init(void);
    void configureGpios(void);
    BOOL verifyProductId(void);

    virtual DWORD selfTest(void)=0;
    BYTE walkRegSequence(const AgSensorRegSeq *regSeqList, UINT16 regSeqNo);


    enum
    {
        // This bit must be set in the address byte of every write to
        WRITE_CMD_BIT  = 0x80,

        CS_ASSERT       = 0,    // low active
        CS_DEASSERT     = 1,

        REG_MOTION_BURST      = 0x42 , /**< Motion_Burst register */

        REG_LASER_CTRL0       = 0x1a, /**< LASER_CTRL0 register */
        REG_LSRPWR_CFG0       = 0x1c, /**< LASER_CTRL0 register */
        REG_LSRPWR_CFG1       = 0x1d, /**< LSRPWR_CFG1 register */
        REG_LASER_CTRL1       = 0x1f, /**< LASER_CTRL1 register */

    };

public:
    ///
    /// action id defination for AgSensorRegSeq.rwd
    ///
    /// typedef struct
    /// {
    ///  UINT8       rwd;         // read or write or delay
    ///  UINT8       regoffset;   // register offset or delay time, high byte
    ///  UINT8       value;       // write value 	or delay time low byteus
    ///  }AgSensorRegSeq;
    ///
    ///
    enum AGSENSOR_ACT_PROCEDURE_ID
    {
        /// dely in ms, which indicate in AgSensorRegSeq.value
        /// max delay 255ms
        /// if longer deley is needed, please
        /// add one more action_item list
        ///
        AGSENSOR_DELAY_MS               =  1  ,

        /// dely in us, which indicate in AgSensorRegSeq.value
        /// max is 255
        /// if more delay needed, please add more delay items in the sequencelist
        AGSENSOR_DELAY_US               =  2  ,

        /// perform spi read and compare
        AGSENSOR_READCOMPARE            =  3  ,

        /// just read the sensor register via spi interferace, ignore the read result
        AGSENSOR_READONLY               =  4  ,

        /// write the sensor register
        AGSENSOR_WRITE                  =  5  ,

        /// compare with previoue read value,
        /// the regoffset will become mask
        AGSENSOR_COMPARE                  =  6  ,
    };

protected:
    // Flag indicating that the sensor was detected
    BYTE                deviceFound;

    SpiInterface        *spi;

    //
    // pointer to configuration table
    //
    AgDriverConfig      *agDriverCfg;



    // pointer to power up registers programing sequence list
    // the data can comes form internal supported chip 7050/7350/5090
    // or comes form user cgs defined sequence
    const AgSensorRegSeq      *agPowerUpSeq;

    //
    // point to power down registers program sequence list
    //
    const AgSensorRegSeq      *agPowerDownSeq;


    //
    // point to Reset registers program sequence list
    //
    const AgSensorRegSeq      *agResetSeq;

    const AgSensorRegSeq      *agIDCheckSeq;

    UINT8                agPowerUpSeqSize;
    UINT8                agPowerDownSeqSize;
    UINT8                agResetSeqSize;
    UINT8                agIDCheckSeqSize;
};

#endif
