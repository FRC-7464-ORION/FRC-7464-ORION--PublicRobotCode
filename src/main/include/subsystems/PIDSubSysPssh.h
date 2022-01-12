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

// Include the Robot map header 
#include "RobotMap.h"

/************************** Library Header Files ******************************/

// Include the header file for the NEW(2020) PID subsystem
#include <frc2/command/PIDSubsystem.h>

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

class PIDSubSysPssh : public frc2::PIDSubsystem {

  public:

    /** The default constructor for the PIDSubSysPssh class */
    PIDSubSysPssh();

    /** The default destructor for the PIDSubSysPssh class */
    ~PIDSubSysPssh();

    /** Method to reset the PID controller */
    void ResetPIDController();

    /** Method to disable the PID controller */
    void DisablePIDController();

    /** Method to enable PID controller */
    void EnablePIDController();
    
    /**
     * Use the potentiometer as the PID sensor. This method is automatically
     * called by the subsystem.
     */
    double GetMeasurement() override;

    /**
     * Use the motor as the PID output. This method is automatically called
     * by the subsystem.
     */
    void UseOutput(double output, double setpoint) override;

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

    /** The motor controller for Pssh, which is a Victor SPX PWM controller */
    frc::PWMVictorSPX m_PsshMotorController{k_PsshMotorPWMPort};

    // Conversion value of potentiometer varies between the real world and
    // simulation
#ifndef SIMULATION /* aka Real world */
    /** An analog potentiometer hooked up to the axle of Pssh */
    frc::AnalogPotentiometer m_PsshPot{k_Pssh_Pot_roboRIO_AnalogInChannel,
                                       k_PsshPotScaleFactor,
                                       k_PsshPotOffset};
#else
    /** A simulated analog potentiometer hooked up to the axle of Pssh */
    frc::AnalogPotentiometer m_PsshPot{k_Pssh_Pot_roboRIO_AnalogInChannel,
                                       k_PsshPotScaleFactor,
                                       k_PsshPotOffset};
#endif

    /** A string containing the state of Pssh */
    std::string m_PsshState;

    /***************************** Private Methods ****************************/

}; // end class PIDSubSysPssh

#endif // #ifndef PIDSUBSYSPSSH_H
