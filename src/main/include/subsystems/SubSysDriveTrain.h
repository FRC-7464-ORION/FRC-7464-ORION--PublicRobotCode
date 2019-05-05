/** ===========================================================================
 * @file   SubSysDriveTrain.h
 * @brief  This file declares the SubSysDriveTrain class, which is a
 *         subsystem of the robot
 *
 * The SubSysDriveTrain class is used to move the robot.  
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

// Preprocessor directive to have this file only be included once in the
//  compilation
// See https://en.wikipedia.org/wiki/Pragma_once for details
#pragma once

/*************************** Local Header Files *******************************/

// Include the robot constants header
#include "RobotConstants.h"

/************************** Library Header Files ******************************/

// Include the subsystem class header file
#include <frc/commands/Subsystem.h>

// Include the WPI library header file, for the speed controllers
#include "frc/WPILib.h"

/** ****************************************************************************
 * @class   SubSysDriveTrain
 * @brief   This class declares the drive train subsystem.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class SubSysDriveTrain : public frc::Subsystem {

  public:

    /** The default constructor for the SubSysDriveTrain class */
    SubSysDriveTrain();

    /** The destructor for the SubSysDriveTrain class */
    ~SubSysDriveTrain();

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
     * The method for driving arcade style.
     *
     * @param y Output from the y axis of a joystick
     * @param x Output from the x axis of a joystick
    */
    void DriveArcadeStyle(double y, double x);

    /**
     * The method for driving tank style.
     *
     * @param yL Output from the y axis of a left joystick
     * @param yR Output from the y axis of a right joystick
     *
     * See:
     * file:///C:/Users/Public/frc2019/documentation/cpp/classfrc_1_1RobotDrive.html#af6b8803c260126190b2aba14d4367dbd
    */
    void DriveTankStyle(double yL, double yR);

    /** Method to set the drive train mode string to arcade */
    void SetDriveTrainModeStringToArcade();

    /** Method to set the drive train mode string to tank */
    void SetDriveTrainModeStringToTank();

    /**
     * Method to get the current drive train mode string.
     *
     * @return A string containing the current drive train mode of driving
    */
    std::string GetDriveTrainModeString();

    /**
     * Method to get the drive train's null zone.
     *
     * @return The drive train null zone value
    */
    double GetDriveTrainNullZone();

    /**
     * Method to get the drive train's speed limit.
     *
     * @return The drive train speed limit
    */
    double GetDriveTrainLimit();

    /**
     * Method to get the drive train's exponent for the curve.
     *
     * @return The drive train exponent for the curve
    */
    double GetDriveTrainExponent();

  private:

    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities

    /***************************** Private Members ****************************/

    /** A pointer to the left drivetrain motors (speed) controller */
    std::shared_ptr<frc::PWMVictorSPX> m_leftDriveTrainController;

    /** A pointer to the right drivetrain motors (speed) controller */
    std::shared_ptr<frc::PWMVictorSPX> m_rightDriveTrainController;

    /** A pointer to a differential drive */
    std::shared_ptr<frc::DifferentialDrive> m_differentialDrive;

    /** A string to hold the drive train mode */
    std::string m_DriveTrainModeString;

    // /***************************** Private Methods ****************************/

}; // end class SubSysDriveTrain
