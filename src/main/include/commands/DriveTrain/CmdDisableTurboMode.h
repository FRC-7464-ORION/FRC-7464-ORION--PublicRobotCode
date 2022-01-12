/** ===========================================================================
 * @file   CmdDisableTurboMode.h
 * @brief  This file declares the CmdDisableTurboMode class.
 *
 * The CmdDisableTurboMode class is used to allow the robot to be drive using
 * a differential drive in non-turbo mode (giving extra speed in either arcade
 * or tank mode).
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
 * Copyright (c) 2019-2020 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

// INCLUDE GUARD - see https://en.wikipedia.org/wiki/Include_guard
// If we have not already defined CMDDISABLETURBOMODE_H...
#ifndef CMDDISABLETURBOMODE_H
// Define CMDDISABLETURBOMODE_H
#define CMDDISABLETURBOMODE_H

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
 * @class   CmdDisableTurboMode
 * @brief   This is a class that defines a command used in driving the
 *            robot using non-turbo mode.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class CmdDisableTurboMode
  : public frc2::CommandHelper<frc2::CommandBase, CmdDisableTurboMode> {

  public:

    /********************** PUBLIC MEMBER FUNCTIONS ***************************/

    /** 
     * The CmdDisableTurboMode class constructor.
     * 
     * @param subsystem            The subsystem used by this command
     */
    explicit CmdDisableTurboMode(SubSysDriveTrain* subsystem);

    /** The CmdDisableTurboMode class destructor. */
    ~CmdDisableTurboMode();

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

    /** A pointer to the drive train subsystem */
    SubSysDriveTrain* m_subSysDriveTrain;

}; // end class CmdDisableTurboMode 

#endif // #ifndef CMDDISABLETURBOMODE_H
