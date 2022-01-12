/** ===========================================================================
 * @file   CmdAutoTurnAngle.h
 * @brief  This file declares the CmdAutoTurnAngle class.
 *
 * The CmdAutoTurnAngle class is used to allow the robot to be turned
 * autonomously using a differential drive in tank mode.
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
// If we have not already defined CMDAUTOTURNANGLE_H...
#ifndef CMDAUTOTURNANGLE_H
// Define CMDAUTOTURNANGLE_H
#define CMDAUTOTURNANGLE_H

/*************************** Local Header Files *******************************/

// Include the header file for the drive train, which this command is for
#include "subsystems/SubSysDriveTrain.h"

// Include the Robot Map header file
#include "RobotMap.h"

// Include the Robot Constants header file
#include "RobotConstants.h"

// Include the robot header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// Include the header file for the Command class
#include <frc/commands/Command.h>

// Include the header file for the PIDController
#include <frc/PIDController.h>

// Include the header file for the PIDOutput
#include <frc/PIDOutput.h>

// Include the header file for the PIDCommand
#include <frc/commands/PIDCommand.h>

// Include the header file for the SPI bus
#include <frc/SPI.h>

// Include the header file for the DriverStation, for errors/warning
#include <frc/DriverStation.h>

// Include the header for LiveWindow, so we can tune this PID controller
#include <frc/livewindow/LiveWindow.h>

/** ****************************************************************************
 * @class   CmdAutoTurnAngle
 * @brief   This is a class that defines a command used in turning the
 *            robot autonomously using tank drive.
 * 
 *          NOTE: THIS CLASS USES DEPRECATED CODE (PIDController) AS OF 2020. 
 *                WPILIB HAS MARKED THIS CODE AS BEING DEPRECATED, AND WILL
 *                GENERATE A BUILD WARNING WHEN RobotCode IS BUILT. 
 *                SO THAT OTHER WARNINGS WILL NOT BE IGNORED, THE PIDController
 *                INSTANTIATION HAS BEEN MARKED WITH PRAGMAS SO THE WARNING 
 *                FOR THIS INSTANCE IS IGNORED. THIS MODIFICATION SHOULD BE
 *                REMOVED BY THE 2021 SEASON.
 * 
 *                FOR MORE INFORMATION, SEE THE POST AT CHIEF DELPHI:
 *                https://www.chiefdelphi.com/t/pragma-or-gradle-flag-for-ignoring-deprecated-warnings/375815
 * 
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class CmdAutoTurnAngle : public frc::Command, public frc::PIDOutput {

  public:

    /** The CmdAutoTurnAngle class default constructor. */
    CmdAutoTurnAngle();

    /** The CmdAutoTurnAngle class constructor for setting target angle.
     *  This constructor should always be used
     * 
     * @param max_speed The maximum speed allowed by the PID controller
     * @param angle     The target angle
     */
    CmdAutoTurnAngle(double max_speed, double angle);

    /** The CmdAutoTurnAngle class destructor. */
    ~CmdAutoTurnAngle();

    /**
     * The initialize method is called the first time this Command is run after
     * being started.
    */
    void Initialize() override;

    /**
     * The execute method is called repeatedly until this Command either
     * finishes or is canceled.
    */
    void Execute() override;

    /**
     * Returns whether this command is finished.
     * If it is, then the command will be removed and End() will be called.
     *
     * It may be useful for a team to reference the IsTimedOut() method for
     *   time-sensitive commands.
     *
     * Returning false will result in the command never ending automatically.
     * It may still be cancelled manually or interrupted by another command.
     *
     * Returning true will result in the command executing once and finishing
     * immediately. We recommend using InstantCommand for this.
     *
     * @return True = Command finished, False = Command not finished
    */
    bool IsFinished() override;

    /**
     * Called when the command ended peacefully.
     *
     * This is where you may want to wrap up loose ends, like shutting off
     * a motor that was being used in the command.
     *
     * Reimplemented in frc::CommandGroup.
    */
    void End() override;

    /**
     * Called when the command ends because somebody called Cancel() or another
     * command shared the same requirements as this one, and booted it out.
     *
     * This is where you may want to wrap up loose ends, like shutting off a
     * motor that was being used in the command.
     *
     * Generally, it is useful to simply call the End() method within this
     * method, as done here.
     *
     * Reimplemented in frc::CommandGroup.
    */
    void Interrupted() override;

    /** Invoked periodically by the PID Controller, based upon navX MXP yaw 
        angle input and PID Coefficients. */
    virtual void PIDWrite(double output);

  private:

    /*********************** Private member variables ***********************/

    /** The "P" of our PID loop */
    const double m_P_val   = k_AutoTurn_Proportional;
    /** The "I" of our PID loop */
    const double m_I_val   = k_AutoTurn_Integral;
    /** The "D" of our PID loop */
    const double m_D_val   = k_AutoTurn_Derivative;
    /** The "F" (feedforward coefficient) of our PID loop */
    const double m_F_val   = k_AutoTurn_FeedForward;
    /** The tolerance our PID loop has to meet */
    const double m_Tol_val = k_AutoTurn_ToleranceDegrees;
    
    /** A pointer to a LiveWindow instance */
    frc::LiveWindow *m_LiveWindow;

    /** A pointer to a PID controller */
    PIDController *m_turnController;

    /** The port will be using for the NavX MXP */
    const frc::SPI::Port m_navx_SPI_port = k_navx_mxp_imu_port;

    /** A boolean to indicate that the turn has completed */
    bool m_turn_completed;

    /** The speed at which we rotate and the PID loop controls */
    double m_RotateToAngleSpeed;

    /** The maximimum speed to the motors in the rotation */
    double m_MaxRotateToAngleSpeed;

    /** The angle we are shooting for */
    double m_target_angle;

    /** Indicate if we used the default constructor (DON'T) */
    bool m_default_constructor_called;

    /** The left motors' speed */
    double m_left_motor_speed;

    /** The right motors' speed */
    double m_right_motor_speed;

    /*********************** Private member methods *************************/

    /** An initialization function for the IMU in the various constructors */
    void navx_initialization();

}; // end class CmdAutoTurnAngle

#endif // #ifndef CMDAUTOTURNANGLE_H