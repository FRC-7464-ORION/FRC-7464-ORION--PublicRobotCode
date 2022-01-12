/** ===========================================================================
 * @file   SubSysPssh.h
 * @brief  This file declares the SubSysPssh class, which is a
 *         subsystem of the robot.
 *
 * The SubSysPssh class is used to manually control the power cell 
 * transporter.
 *
 * COPYRIGHT NOTICES:
 *
 * Some portions:
 *
 * Copyright (c) 2017-2018 FIRST. All Rights Reserved.
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
// If we have not already defined SUBSYSPSSH_H...
#ifndef SUBSYSPSSH_H
// Define SUBSYSPSSH_H
#define SUBSYSPSSH_H

/*************************** Local Header Files *******************************/

// Include the robot constants header
#include "RobotConstants.h"

// If we are not using the Pssh PID controller...
#if !USE_PID_PSSH

/************************** Library Header Files ******************************/

// Include the subsystem class header file
#include <frc/commands/Subsystem.h>

// Include the PWMVictorSPX header file, for the motor controllers
#include <frc/PWMVictorSPX.h>

// Include the DriverStation, for errors and warnings
#include <frc/DriverStation.h>

/** ****************************************************************************
 * @class   SubSysPssh
 * @brief   This class declares the power cell transporter.
 *          subsystem
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class SubSysPssh : public frc::Subsystem {

  public:

    /** The default constructor for the SubSysPssh class */
    SubSysPssh();

    /** The default destructor for the SubSysPssh class */
    ~SubSysPssh();

    /**
     * Initialize the default command for this subsystem.
     *
     * This is meant to be the place to call SetDefaultCommand in a subsystem
     * and will be called on all the subsystems by the CommandBase method 
     * before the program starts running by using the list of all registered
     * Subsystems inside the Scheduler.
    */
    void InitDefaultCommand() override;

    /** The periodic method for PATTurner */
    void Periodic() override;

    /**
     * The method for having Pssh control the power cell transporter.
     *
     * @param speed The motor speed, presumbably from some
     *                thumbstick, trigger, etc.
    */
    void ControlPssh(double speed);

    /** Method to put Pssh in the travel position */
    void Travel();

    /** Method to put Pssh in the load position */
    void Load();

    /** Method to put Pssh in the dump position */
    void Dump();

    /** Method to stop Pssh */
    void Stop();

    /**
     * Method to get Pssh's null zone.
     *
     * @return Pssh's null zone value
    */
    double GetPsshNullZone();

    /**
     * Method to get Pssh's speed limit.
     *
     * @return Pssh's speed limit
    */
    double GetPsshLimit();

    /**
     * Method to get Pssh's exponent for the curve.
     *
     * @return Pssh's exponent for the curve
    */
    double GetPsshExponent();

  private:
    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities

    /***************************** Private Members ****************************/

    /** A pointer to Pssh's motor(speed) controller */
    std::shared_ptr<frc::PWMVictorSPX> m_PsshController;

    /***************************** Private Methods ****************************/

}; // end class SubSysPssh

#endif // #if !USE_PID_PSSH

#endif // #ifndef SUBSYSPSSH_H
