/** ===========================================================================
 * @file   PIDSubSysPssh.h
 * @brief  This file declares the PIDSubSysPssh class, which is a
 *         subsystem of the robot
 *
 * The PIDSubSysPssh class is used to move the Pssh power cell transporter to
 * different positions: Travel, Load, and Dump.  
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
// If we have not already defined PIDSUBSYSPSSH_H...
#ifndef PIDSUBSYSPSSH_H
// Define PIDSUBSYSPSSH_H
#define PIDSUBSYSPSSH_H

/*************************** Local Header Files *******************************/

// Include the robot constants header
#include "RobotConstants.h"

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

/************************** Library Header Files ******************************/

// Include the header file for the PID subsystem class
#include <frc/commands/PIDSubsystem.h>

// Include the header file for an analog potentiometer
#include <frc/AnalogPotentiometer.h>

// Include the PWMVictorSPX header file, for the motor controllers
#include <frc/PWMVictorSPX.h>

// Include the DriverStation, for errors and warnings
#include <frc/DriverStation.h>

/** ****************************************************************************
 * @class   PIDSubSysPssh
 * @brief   This class declares the Pssh PID subsystem.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/

class PIDSubSysPssh : public frc::PIDSubsystem {

  public:

    /** The default constructor for the PIDSubSysPssh class */
    PIDSubSysPssh();

    /** The default destructor for the PIDSubSysPssh class */
    ~PIDSubSysPssh();

    /**
     * Return your input value for the PID loop, e.g. a sensor, like a 
     * potentiometer.
     *
     * @return The PID input
    */
    double ReturnPIDInput() override;

    /**
     * Use output to drive your system, like a motor
     *
     * @param output The output of the PID controller
    */
    void UsePIDOutput(double output) override;

    /**
     * Initialize the default command for this subsystem.
     *
     * This is meant to be the place to call SetDefaultCommand in a subsystem
     * and will be called on all the subsystems by the CommandBase method 
     * before the program starts running by using the list of all registered
     * Subsystems inside the Scheduler.
    */
    void InitDefaultCommand() override;

    /** The periodic method for Pssh */
    void Periodic() override;

    /** Method to put Pssh in the travel position */
    void Travel();

    /** Method to put Pssh in the load position */
    void Load();

    /** Method to put Pssh in the dump position */
    void Dump();

    /** Method to stop Pssh */
    void Stop();

    /** Method to get Pssh state */
    std::string GetPsshState();

    /** Method to set Pssh state */
    void SetPsshState(std::string state);

  private:

    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities

    /***************************** Private Members ****************************/

    /** A pointer to Pssh's motor(speed) controller */
    std::shared_ptr<frc::PWMVictorSPX> m_PsshController;

    /** A pointer to the potentiometer hooked up the axle of Pssh */
    std::shared_ptr<frc::AnalogPotentiometer> m_PsshPot;

    /** A string containing the state of Pssh */
    std::string m_PsshState;

    /***************************** Private Methods ****************************/

}; // end class PIDSubSysPssh

#endif // #if USE_PID_PSSH

#endif // #ifndef PIDSUBSYSPSSH_H
