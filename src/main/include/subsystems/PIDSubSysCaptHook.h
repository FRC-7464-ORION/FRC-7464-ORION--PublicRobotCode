/** ===========================================================================
 * @file   PIDSubSysCaptHook.h
 * @brief  This file declares the PIDSubSysCaptHook class, which is a
 *           PID based subsystem of the robot.
 *
 * The PIDSubSysCaptHook class is used to allow the robot to grab and release
 *   hatch panels.
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
 * Copyright (c) 2019 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

// INCLUDE GUARD - see https://en.wikipedia.org/wiki/Include_guard
// If we have not already defined PIDSUBSYSCAPTHOOK_H...
#ifndef PIDSUBSYSCAPTHOOK_H
// Define PIDSUBSYSCAPTHOOK_H
#define PIDSUBSYSCAPTHOOK_H

/*************************** Local Header Files *******************************/

// Include the robot constants header file
#include "RobotConstants.h"

// If we are using Capt. Hook with a PID controller...
#if USE_PID_CAPT_HOOK

// Include the robot map header file
#include "RobotMap.h"

/************************** Library Header Files ******************************/

// Include the header file for the PID subsystem class
#include <frc/commands/PIDSubsystem.h>

// Include the header file for an analog potentiometer
#include <frc/AnalogPotentiometer.h>

// Include the WPI library header file, for the speed controllers
#include "frc/WPILib.h"

/** ****************************************************************************
 * @class   PIDSubSysCaptHook
 * @brief   This class declares the hatch panel moving (grab/release)
 *          subsystem, using a PID controller.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class PIDSubSysCaptHook : public frc::PIDSubsystem {

  public:

    /** The default constructor for the PIDSubSysCaptHook class */
    PIDSubSysCaptHook();

    /** The destructor for the PIDSubSysCaptHook class */
    ~PIDSubSysCaptHook();

    /**
     * Return your input value for the PID loop,
     * e.g. a sensor, like a potentiometer
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
     * This method sets the default command for the
     * PIDSubSysCaptHook subsystem
    */
    void InitDefaultCommand() override;

    /** The periodic method for the drivetrain */
    void Periodic() override;

    /** The method for grabbing a hatch panel */
    void GrabHatchPanel();

    /** The method for releasing a hatch panel */
    void ReleaseHatchPanel();

    /** The method for stopping Capt. Hook */
    void StopCaptHook();

    /** Method to get Capt. Hook state */
    std::string GetCaptHookState();

    /** Method to set Capt. Hook state */
    void SetCaptHookState(std::string state);

  private:

    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities

    /***************************** Private Members ****************************/

    /** A pointer to the motor (speed) controller for Capt. Hook */
    std::shared_ptr<frc::PWMVictorSPX> m_CaptHookController;

    /** A pointer to the potentiometer hooked up the axle of Captain Hook */
    std::shared_ptr<frc::AnalogPotentiometer> m_CaptHookPot;

    /** A string containing the state of Capt. Hook */
    std::string m_CaptHookState;

}; // end class PIDSubSysCaptHook

#endif // #if USE_PID_CAPT_HOOK

#endif // #ifndef PIDSUBSYSCAPTHOOK_H
