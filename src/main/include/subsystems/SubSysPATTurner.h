/** ===========================================================================
 * @file   SubSysPATTurner.h
 * @brief  This file declares the SubSysPATTurner class, which is a
 *         subsystem of the robot.
 *
 * The SubSysPATTurner class is used to turn the "Wheel of Fortune" in the
 * Infinite Recharge trench.
 *
 * COPYRIGHT NOTICES:
 *
 * Some portions:
 *
 * Copyright (c) 2017-2019 FIRST. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FIRST BSD license file in the root directory of
 * the project.
 *
 * Some portions:
 *
 * Copyright (c) 2020 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

// INCLUDE GUARD - see https://en.wikipedia.org/wiki/Include_guard
// If we have not already defined SUBSYSPATTURNER_H...
#ifndef SUBSYSPATTURNER_H
// Define SUBSYSPATTURNER_H
#define SUBSYSPATTURNER_H

/*************************** Local Header Files *******************************/

// Include the robot constants header
#include "RobotConstants.h"

/************************** Library Header Files ******************************/

// Include the NEW(2020) subsystem base class header file
#include <frc2/command/SubsystemBase.h>

// Include the PWMVictorSPX header file, for the motor controllers
#include <frc/PWMVictorSPX.h>

// Include the DriverStation, for errors and warnings
#include <frc/DriverStation.h>

/** ****************************************************************************
 * @class   SubSysPATTurner
 * @brief   This class declares PAT turning the "Wheel of Fortune"
 *          subsystem
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class SubSysPATTurner : public frc2::SubsystemBase {

  public:

    /********************** PUBLIC MEMBER FUNCTIONS ***************************/

    /** The default constructor for the SubSysPATTurner class */
    SubSysPATTurner();

    /** The default destructor for the SubSysPATTurner class */
    ~SubSysPATTurner();

    /** The periodic method for PATTurner */
    void Periodic() override;

    /**
     * The method for having PAT turn the Wheel of Fortune (WoF).
     *
     * @param speed The motor speed, presumbably from some
     *                thumbstick, trigger, etc.
    */
    void TurnWoF(double speed);

    /**
     * Method to get PAT's null zone.
     *
     * @return PAT's null zone value
    */
    double GetPATTurnerNullZone();

    /**
     * Method to get PAT's speed limit.
     *
     * @return PAT's speed limit
    */
    double GetPATTurnerLimit();

    /**
     * Method to get PAT's exponent for the curve.
     *
     * @return PAT's exponent for the curve
    */
    double GetPATTurnerExponent();

  private:

    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities

    /********************* PRIVATE MEMBER FUNCTIONS ***************************/

    /********************* PRIVATE MEMBER VARIABLES ***************************/

    /** The motor controller for PAT, which is a Victor SPX PWM controller */
    frc::PWMVictorSPX m_PATTurnerController;

}; // end class SubSysPATTurner

#endif // #ifndef SUBSYSPATTURNER_H
