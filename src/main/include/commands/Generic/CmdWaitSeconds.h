/** ===========================================================================
 * @file   CmdWaitSeconds.h
 * @brief  This file declares the CmdWaitSeconds class.
 *
 * The CmdWaitSeconds class is used to allow the robot to be paused for 
 * a given amount of time in seconds, especially between commands who
 * need time to "settle".
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
// If we have not already defined CMDWAITSECONDS_H...
#ifndef CMDWAITSECONDS_H
// Define CMDWAITSECONDS_H
#define CMDWAITSECONDS_H

/*************************** Local Header Files *******************************/

// Include the header file for the timer class
#include <frc/Timer.h>

/************************** Library Header Files ******************************/

// Include the header file for the Command class
#include <frc/commands/Command.h>

/** ****************************************************************************
 * @class   CmdWaitSeconds
 * @brief   This is a class that defines a command used to pause the robot
 *            for a given time, in seconds
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class CmdWaitSeconds : public frc::Command {

  public:

    /** The CmdWaitSeconds class default constructor. */
    CmdWaitSeconds();

    /** The constructor for giving a time */
    CmdWaitSeconds(double sec);

    /** The CmdWaitSeconds class destructor. */
    ~CmdWaitSeconds();

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

    /*********************** Private member variables *************************/

    /** The time to wait, in seconds */
    double wait_time_seconds;

    /** A pointer to a timer class */
    frc::Timer* m_timer;

    /** A boolean to indicate we have exceeded our time */
    bool wait_time_exceeded;

}; // end class CmdWaitSeconds

#endif // #ifndef CMDWAITSECONDS_H