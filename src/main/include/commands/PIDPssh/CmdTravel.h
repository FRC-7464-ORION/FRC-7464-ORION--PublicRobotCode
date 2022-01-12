/** ===========================================================================
 * @file   commands/PIDPssh/CmdTravel.h
 * @brief  This file declares the CmdTravel class.
 *
 * The CmdTravel class is used to set the power cell mover Pssh in travel
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
// If we have not already defined CMDTRAVEL_H...
#ifndef CMDTRAVEL_H
// Define CMDTRAVEL_H
#define CMDTRAVEL_H

/*************************** Local Header Files *******************************/

// Include the header file for Pssh, which this command is for
#include "subsystems/PIDSubSysPssh.h"

// Include the robot constants header file
#include "RobotConstants.h"

/************************** Library Header Files ******************************/

// Include the header file for the NEW(2020) Command base class
#include <frc2/command/CommandBase.h>

// Include the header file for the NEW(2020) Command helper class
#include <frc2/command/CommandHelper.h>

/** ****************************************************************************
 * @class   CmdTravel
 * @brief   This is a class that defines a command used in setting the power
 *          cell collector to the travel position.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class CmdTravel
  : public frc2::CommandHelper<frc2::CommandBase, CmdTravel> {

  public:

    /********************** PUBLIC MEMBER FUNCTIONS ***************************/

    /** 
     * The CmdTravel class constructor.
     * 
     * @param subsystem The subsystem used by this command
     */
    explicit CmdTravel(PIDSubSysPssh* subsystem);

    /** The CmdTravel class destructor. */
    ~CmdTravel();

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

    /** A pointer to the PID Pssh subsystem */
    PIDSubSysPssh* m_PIDsubSysPssh;

}; // end class CmdTravel

#endif // #ifndef CMDTRAVEL_H
