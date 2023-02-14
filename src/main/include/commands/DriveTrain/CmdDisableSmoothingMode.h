/** ===========================================================================
 * @file   CmdDisableSmoothingMode.h
 * @brief  This file declares the CmdDisableSmoothingMode class.
 *
 * The CmdDisableSmoothingMode class is used to not allow the robot to be 
 * driven using a smoothing function, implemented using an infinite
 * impulse response digital low pass filter.
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
 * Copyright (c) 2019-2022 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

// INCLUDE GUARD - see https://en.wikipedia.org/wiki/Include_guard
// If we have not already defined CMDDISABLESMOOTHINGMODE_H...
#ifndef CMDDISABLESMOOTHINGMODE_H
// Define CMDDISABLESMOOTHINGMODE_H
#define CMDDISABLESMOOTHINGMODE_H

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
 * @class   CmdDisableSmoothingMode
 * @brief   This is a class that defines a command used in disabling the
 *            smoothing mode on the drive train.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class CmdDisableSmoothingMode
  : public frc2::CommandHelper<frc2::CommandBase, CmdDisableSmoothingMode> {

  public:

    /********************** PUBLIC MEMBER FUNCTIONS ***************************/

    /** 
     * The CmdDisableSmoothingMode class constructor.
     * 
     * @param subsystem            The subsystem used by this command
     */
    explicit CmdDisableSmoothingMode(SubSysDriveTrain* subsystem);

    /** The CmdDisableSmoothingMode class destructor. */
    ~CmdDisableSmoothingMode();

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

    /** A local boolean to tell when this command is finished */
    bool m_this_command_is_finished;

    /** A pointer to the drive train subsystem */
    SubSysDriveTrain* m_subSysDriveTrain;

}; // end class CmdDisableSmoothingMode

#endif // #ifndef CMDDISABLESMOOTHINGMODE_H
