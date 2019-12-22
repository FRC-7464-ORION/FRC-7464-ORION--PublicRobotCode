/** ===========================================================================
 * @file   SubSysCaptHook.h
 * @brief  This file declares the SubSysCaptHook class, which is a
 *         subsystem of the robot.
 *
 * The SubSysCaptHook class is used to grab or release (i.e. move) a 
 * hatch panel.
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
// If we have not already defined SUBSYSCAPTHOOK_H...
#ifndef SUBSYSCAPTHOOK_H
// Define SUBSYSCAPTHOOK_H
#define SUBSYSCAPTHOOK_H

/*************************** Local Header Files *******************************/

// Include the robot constants header
#include "RobotConstants.h"

// If we are not using the PID controller for Capt. Hook
#if !USE_PID_CAPT_HOOK

/************************** Library Header Files ******************************/

// Include the subsystem class header file
#include <frc/commands/Subsystem.h>

// Include the WPI library header file, for the speed controllers
#include "frc/WPILib.h"

/** ****************************************************************************
 * @class   SubSysCaptHook
 * @brief   This class declares the hatch panel moving (grab/release)
 *          subsystem.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class SubSysCaptHook : public frc::Subsystem {

  public:

    /** The default constructor for the SubSysCaptHook class */
    SubSysCaptHook();

    /** The default destructor for the SubSysCaptHook class */
    ~SubSysCaptHook();

    /**
     * Initialize the default command for this subsystem.
     *
     * This is meant to be the place to call SetDefaultCommand in a subsystem
     * and will be called on all the subsystems by the CommandBase method 
     * before the program starts running by using the list of all registered
     * Subsystems inside the Scheduler.
    */
    void InitDefaultCommand() override;

    /** The periodic method for the drivetrain */
    void Periodic() override;

    /**
     * The method for having Capt. Hook move a hatch panel.
     *
     * @param speed The motor speed, presumbably from some
     *                thumbstick, trigger, etc.
    */
    void MoveHatchPanel(double speed);

    /**
     * Method to get Capt. Hook's null zone.
     *
     * @return Capt. Hook's null zone value
    */
    double GetCaptHookNullZone();

    /**
     * Method to get Capt. Hook's speed limit.
     *
     * @return Capt. Hook's speed limit
    */
    double GetCaptHookLimit();

    /**
     * Method to get Capt. Hook's exponent for the curve.
     *
     * @return Capt. Hook's exponent for the curve
    */
    double GetCaptHookExponent();

  private:
    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities

    /***************************** Private Members ****************************/

    /** A pointer to Capt. Hook's motor(speed) controller */
    std::shared_ptr<frc::PWMVictorSPX> m_CaptHookController;

    /***************************** Private Methods ****************************/

}; // end class SubSysCaptHook

#endif // #if !USE_PID_CAPT_HOOK

#endif // #ifndef SUBSYSCAPTHOOK_H
