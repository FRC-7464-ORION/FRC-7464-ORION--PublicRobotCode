/** ===========================================================================
 * @file   CmdEnableHansFranzMuscles.h
 * @brief  This file declares the CmdEnableHansFranzMuscles class.
 *
 * The CmdEnableHansFranzMuscles class is used to enable the Hans and Franz
 * muscles.
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
// If we have not already defined CMDENABLEHANSFRANZMUSCLES_H...
#ifndef CMDENABLEHANSFRANZMUSCLES_H
// Define CMDENABLEHANSFRANZMUSCLES_H
#define CMDENABLEHANSFRANZMUSCLES_H

/*************************** Local Header Files *******************************/

// Include the robot constants header file
#include "RobotConstants.h"

// Include the header file for the Hans/Franz muscles subsystem
#include "subsystems/SubSysHansFranzMuscles.h"

/************************** Library Header Files ******************************/

// Include the header file for the Command class
#include <frc/commands/Command.h>

/** ****************************************************************************
 * @class   CmdEnableHansFranzMuscles
 * @brief   This is a class that is used in enabling Hans and Franz muscles.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class CmdEnableHansFranzMuscles : public frc::Command {

  public:

    /** The CmdEnableHansFranzMuscles class default constructor. */
    CmdEnableHansFranzMuscles();

    /** The CmdEnableHansFranzMuscles class destructor. */
    ~CmdEnableHansFranzMuscles();

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

    /** Boolean to indicate this command is finished */
    bool m_this_command_is_finished;

}; // end class CmdEnableHansFranzMuscles

#endif // #ifndef CMDENABLEHANSFRANZ_H
