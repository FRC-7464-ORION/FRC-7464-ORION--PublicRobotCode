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
 * Copyright (c) 2020-2022 FRC Team #7464 - ORION. All Rights Reserved.
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

// The header for the NavX MXP AHRS
#include "AHRS.h"

/************************** Library Header Files ******************************/

// Include the header file for the NEW(2020) Command base class
#include <frc2/command/CommandBase.h>

// Include the header file for the NEW(2020) Command helper class
#include <frc2/command/CommandHelper.h>

// Include the header file for the NEW(2020) PID controller
#include <frc/controller/PIDController.h>

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
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class CmdAutoTurnAngle
  : public frc2::CommandHelper<frc2::CommandBase, CmdAutoTurnAngle> {

  public:

    /********************** PUBLIC MEMBER FUNCTIONS ***************************/

    /** 
     * The CmdAutoTurnAngle class constructor.
     * 
     * @param subsystem The subsystem used by this command
     * @param ahrs      The NavX MXP IMU
     * @param max_speed The maximum speed allowed by the PID controller
     * @param angle     The target angle, in degrees
     */
    explicit CmdAutoTurnAngle(
        SubSysDriveTrain* subsystem,
        AHRS* ahrs,
        double max_speed,
        double angle);

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
     * Called when either the command finishes normally, or when it is
     * interrupted/canceled.
     *
     * This is where you may want to wrap up loose ends, like shutting off
     * a motor that was being used in the command.
     *
     * @param interrupted false = not interrupted, true = interrupted
    */
    void End(bool interrupted) override;

private:

    /********************* PRIVATE MEMBER FUNCTIONS ***************************/

    /********************* PRIVATE MEMBER VARIABLES ***************************/

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
    
    /** A pointer to a PID controller */
    frc2::PIDController* m_turnController;

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

    /** The left motors' speed */
    double m_left_motor_speed;

    /** The right motors' speed */
    double m_right_motor_speed;

    /** A pointer to the drive train subsystem */
    SubSysDriveTrain* m_subSysDriveTrain;

    /** A pointer to an AHRS instance */
    AHRS* m_AHRS;

}; // end class CmdAutoTurnAngle

#endif // #ifndef CMDAUTOTURNANGLE_H
