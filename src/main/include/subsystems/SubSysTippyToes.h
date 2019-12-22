/** ===========================================================================
 * @file   SubSysTippyToes.h
 * @brief  This file declares the SubSysTippyToes class, which is a
 *         subsystem of the robot.
 *
 * The SubSysTippyToes class is used to elevate the robot such that it
 * can climb a platform.
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
// If we have not already defined SUBSYSTIPPYTOES_H...
#ifndef SUBSYSTIPPYTOES_H
// Define SUBSYSTIPPYTOES_H
#define SUBSYSTIPPYTOES_H

/*************************** Local Header Files *******************************/

// Include the robot constants header
#include "RobotConstants.h"

// If we are using Tippy Toes...
#if USE_TIPPY_TOES

// Include the subsystem class header file
#include <frc/commands/Subsystem.h>

// Include the WPI library header file, for the speed controllers
#include "frc/WPILib.h"

/** ****************************************************************************
 * @class   SubSysTippyToes
 * @brief   This class declares the platform climbing subsystem.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class SubSysTippyToes : public frc::Subsystem {

  public:

    /** The default constructor for the SubSysTippyToes class */
    SubSysTippyToes();

    /** The default destructor for the SubSysTippyToes class */
    ~SubSysTippyToes();

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
     * The method for having TippyToes climb.
     *
     * @param speed The motor speed, presumbably from some
     *                thumbstick, trigger, etc.
    */
    void Climb(double speed);

    /**
     * Method to get Tippy Toes' null zone.
     *
     * @return Tippy Toes null zone value
    */
    double GetTippyToesNullZone();

    /**
     * Method to get Tippy Toes' speed limit.
     *
     * @return Tippy Toes' speed limit
    */
    double GetTippyToesLimit();

    /**
     * Method to get Tippy Toes' exponent for the curve.
     *
     * @return Tippy Toes' exponent for the curve
    */
    double GetTippyToesExponent();

  private:
    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities

    /***************************** Private Members ****************************/

    /** A pointer to TippyToes' motor(speed) controller */
    std::shared_ptr<frc::PWMVictorSPX> m_TippyToesController;

    /***************************** Private Methods ****************************/

}; // end class SubSysTippyToes

#endif // #if USE_TIPPY_TOES

#endif // #ifndef SUBSYSTIPPYTOES_H
