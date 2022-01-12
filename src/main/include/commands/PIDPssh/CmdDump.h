/** ===========================================================================
 * @file   commands/PIDPssh/CmdDump.h
 * @brief  This file declares the CmdDump class.
 *
 * The CmdDump class is used to set the power cell mover Pssh in dump
 * position.
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
// If we have not already defined CMDDUMP_H...
#ifndef CMDDUMP_H
// Define CMDDUMP_H
#define CMDDUMP_H

/*************************** Local Header Files *******************************/

// Include the robot constants header file
#include "RobotConstants.h"

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

// Include the header file for Pssh, which this command is for
#include "subsystems/PIDSubSysPssh.h"

/************************** Library Header Files ******************************/

// Include the header file for the Command class
#include <frc/commands/Command.h>

/** ****************************************************************************
 * @class   CmdDump
 * @brief   This is a class that defines a command used in setting the power
 *          cell collector to the dump position.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class CmdDump : public frc::Command {

  public:

    /** The CmdDump class default constructor. */
    CmdDump();

    /** The CmdDump class destructor. */
    ~CmdDump();

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

  private:

}; // end class CmdDump

#endif // USE_PID_PSSH

#endif // #ifndef CMDDUMP_H
