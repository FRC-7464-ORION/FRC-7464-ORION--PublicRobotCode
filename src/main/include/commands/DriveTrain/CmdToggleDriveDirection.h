/** ===========================================================================
 * @file   CmdToggleDriveDirection.h
 * @brief  This file declares the CmdToggleDriveDirection class.
 *
 * The CmdToggleDriveDirection class is used to allow the robot to be driven
 * in a fashion where the front becomes the back, or the back becomes the 
 * front. Also, the switched camera server will switch between the front and
 * back cameras. This allows the robot to be controlled without having to 
 * rotate 180 degrees before moving.
 *
 * COPYRIGHT NOTICES:
 *
 * Some portions:
 *
 * Copyright (c) 2017-2019 FIRST. All Rights Reserved.
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
// If we have not already defined CMDTOGGLEDRIVEDIRECTION_H...
#ifndef CMDTOGGLEDRIVEDIRECTION_H
// Define CMDTOGGLEDRIVEDIRECTION_H
#define CMDTOGGLEDRIVEDIRECTION_H

/*************************** Local Header Files *******************************/

// Include the robot constants header file
#include "RobotConstants.h"

// Include the header file for the drive train, which this command is for
#include "subsystems/SubSysDriveTrain.h"

/************************** Library Header Files ******************************/

// Include the header file for the NEW(2020) Command base class
#include <frc2/command/CommandBase.h>

// Include the header file for the NEW(2020) Command helper class
#include <frc2/command/CommandHelper.h>

/** ****************************************************************************
 * @class   CmdToggleDriveDirection
 * @brief   This is a class that defines a command used in toggling the
 *            drive direction of the drive train, as well as switching the
 *            camera view on the Shuffleboard.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class CmdToggleDriveDirection
  : public frc2::CommandHelper<frc2::CommandBase, CmdToggleDriveDirection> {

  public:

    /********************** PUBLIC MEMBER FUNCTIONS ***************************/

    /** 
     * The CmdToggleDriveDirection class constructor.
     * 
     * @param subsystem            The subsystem used by this command
     */
    explicit CmdToggleDriveDirection(SubSysDriveTrain* subsystem);

    /** The CmdToggleDriveDirection class destructor. */
    ~CmdToggleDriveDirection();

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

    /** A local drive direction variable 
     *    false = normal direction
     *    true  = reversed direction
    */
    bool m_drive_direction_reversed;

    /** A local boolean to tell when this command is finished
     *    false = command not finished
     *    true  = command is finished
    */
    bool m_this_command_is_finished;

    /** A pointer to the drive train subsystem */
    SubSysDriveTrain* m_subSysDriveTrain;

}; // end class CmdToggleDriveDirection 

#endif // #ifndef CMDTOGGLEDRIVEDIRECTION_H
