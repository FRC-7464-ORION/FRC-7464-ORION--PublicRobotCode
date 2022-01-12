/** ===========================================================================
 * @file   CmdDisableHansFranzMuscles.h
 * @brief  This file declares the CmdDisableHansFranzMuscles class.
 *
 * The CmdDisableHansFranzMuscles class is used to disable the Hans/Franz 
 * cylinders.
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
// If we have not already defined CMDDISABLEHANSFRANZMUSCLES_H...
#ifndef CMDDISABLEHANSFRANZMUSCLES_H
// Define CMDDISABLEHANSFRANZMUSCLES_H
#define CMDDISABLEHANSFRANZMUSCLES_H

/*************************** Local Header Files *******************************/

// Include the robot constants header file
#include "RobotConstants.h"

// Include the header file for the Hans/Franz muscles subsystem
#include "subsystems/SubSysHansFranzMuscles.h"

/************************** Library Header Files ******************************/

// Include the header file for the NEW(2020) Command base class
#include <frc2/command/CommandBase.h>

// Include the header file for the NEW(2020) Command helper class
#include <frc2/command/CommandHelper.h>

/** ****************************************************************************
 * @class   CmdDisableHansFranzMuscles
 * @brief   This is a class that is used in disabling Hans and Franz.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class CmdDisableHansFranzMuscles
  : public frc2::CommandHelper<frc2::CommandBase, CmdDisableHansFranzMuscles> {

  public:

    /********************** PUBLIC MEMBER FUNCTIONS ***************************/

    /** 
     * The CmdDisableHansFranzMuscles class constructor.
     * 
     * @param subsystem The subsystem used by this command
     */
    explicit CmdDisableHansFranzMuscles(SubSysHansFranzMuscles* subsystem);

    /** The CmdDisableHansFranzMuscles class destructor. */
    ~CmdDisableHansFranzMuscles();

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

    /** A pointer to a Hans/Franz muscles subsystem */
    SubSysHansFranzMuscles* m_subSysHansFranzMuscles;

    /** Boolean to indicate this command is finished */
    bool m_this_command_is_finished;

}; // end class CmdDisableHansFranzMuscles

#endif // #ifndef CMDDISABLEHANSFRANZMUSCLES_H
