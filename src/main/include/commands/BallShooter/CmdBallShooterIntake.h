/** ===========================================================================
 * @file   CmdBallShooterIntake.h
 * @brief  This file declares the CmdBallShooterIntake class.
 *
 * The CmdBallShooterIntake class is used to command the ball shooter to 
 * intake balls.
 *
 * COPYRIGHT NOTICES:
 *
 * Some portions:
 *
 * Copyright (c) 2017-2022 FIRST. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FIRST BSD license file in the root directory of
 * the project.
 *
 * Some portions:
 *
 * Copyright (c) 2022 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

// INCLUDE GUARD - see https://en.wikipedia.org/wiki/Include_guard
// If we have not already defined CMDBALLSHOOTERINTAKE_H...
#ifndef CMDBALLSHOOTERINTAKE_H
// Define CMDBALLSHOOTERINTAKE_H
#define CMDBALLSHOOTERINTAKE_H

/*************************** Local Header Files *******************************/

// Include the robot constants header file
#include "RobotConstants.h"

// Include the header file for the ball shooter, which this command is for
#include "subsystems/SubSysBallShooter.h"

/************************** Library Header Files ******************************/

// Include the header file for the NEW(2020) Command base class
#include <frc2/command/CommandBase.h>

// Include the header file for the NEW(2020) Command helper class
#include <frc2/command/CommandHelper.h>

/** ****************************************************************************
 * @class   CmdBallShooterIntake
 * @brief   This is a class that defines a command used to have the ball shooter
 *            subsytem intake balls
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class CmdBallShooterIntake
  : public frc2::CommandHelper<frc2::CommandBase, CmdBallShooterIntake> {

  public:

    /********************** PUBLIC MEMBER FUNCTIONS ***************************/

    /** 
     * The CmdBallShooterIntake class constructor.
     * 
     * @param subsystem The subsystem used by this command
     */
    explicit CmdBallShooterIntake(SubSysBallShooter* subsystem);

    /** The CmdBallShooterIntake class destructor. */
    ~CmdBallShooterIntake();

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

    /** Activate intake motors */
    void ActivateIntakeMotors();

    /** Deactivate intake motors */
    void DeactivateIntakeMotors();

    /********************* PRIVATE MEMBER VARIABLES ***************************/

    /** A pointer to the ball shooter subsystem */
    SubSysBallShooter* m_subSysBallShooter;

    /** A boolean to indicate if this command is finished or not */
    bool m_ThisCommandIsFinished;

}; // end class CmdBallShooterIntake

#endif // #ifndef CMDBALLSHOOTERINTAKE_H
