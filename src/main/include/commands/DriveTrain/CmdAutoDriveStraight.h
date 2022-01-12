/** ===========================================================================
 * @file   CmdAutoDriveStraight.h
 * @brief  This file declares the CmdAutoDriveStraight class.
 *
 * The CmdAutoDriveStraight class is used to allow the robot to be driven
 * autonomously using a differential drive in arcade mode.
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
// If we have not already defined CMDAUTODRIVESTRAIGHT_H...
#ifndef CMDAUTODRIVESTRAIGHT_H
// Define CMDAUTODRIVESTRAIGHT_H
#define CMDAUTODRIVESTRAIGHT_H

/*************************** Local Header Files *******************************/

// Include the header file for the drive train, which this command is for
#include "subsystems/SubSysDriveTrain.h"

// Include the header file for the timer class
#include <frc/Timer.h>

/************************** Library Header Files ******************************/

// Include the header file for the Command class
#include <frc/commands/Command.h>

/** ****************************************************************************
 * @class   CmdAutoDriveStraight
 * @brief   This is a class that defines a command used in driving the
 *            robot autonomously using arcade drive.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class CmdAutoDriveStraight : public frc::Command {

  public:

    /** An enumeration of distance modes */
    enum DRIVE_STRAIGHT_AUTO_DX_MODE 
      {

        /** Drive straight by an elapsed time, in seconds */
        SECONDS,
        /** Drive straight by a number of elapsed encoder ticks */
        ENCODER_TICKS, 
        /** Drive straight by a number of centimeters */
        CM 

      };

    /** An enumeration of driving straight directions */
    enum DRIVE_STRAIGHT_DIRECTION
    { 

      /** Drive in a forward direction */
      FORWARD,
      /** Drive in a reverse direction */
      REVERSE 
      
    };

    /** The CmdAutoDriveStraight class default constructor. */
    CmdAutoDriveStraight();

    /** 
     * The constructor telling which mode is used 
     *  
     * @param spd  - The motor speed (0.0 to 1.0) at which to move
     * @param mode - The mode to use (SECONDS, ENCODER_TICKS, or CM)
     * @param dir  - The direction to move (FORWARD or REVERSE)
     * @param val  - The seconds, encoder ticks, or cm to move,
     *               based on the mode. 
    */
    CmdAutoDriveStraight(
      double spd,
      DRIVE_STRAIGHT_AUTO_DX_MODE mode,
      DRIVE_STRAIGHT_DIRECTION dir,
      double val);

    /** The CmdAutoDriveStraight class destructor. */
    ~CmdAutoDriveStraight();

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

    /** The speed at which to be driven (0.0 = Stop, 1.0 = Full Speed) */
    double speed;

    /** The direction which to be driven */
    DRIVE_STRAIGHT_DIRECTION direction;

    /** The mode in which distance is used */
    DRIVE_STRAIGHT_AUTO_DX_MODE dx_mode;

    /** The time to be driven, in seconds (if this mode is used) */
    double driven_time_seconds;

    /** The distance to be driven, in encoder ticks (if this mode is used) */
    int driven_distance_in_encoder_ticks;

    /** The distance to be driven, in centimeters (if this mode is used) */
    double driven_distance_in_cm;

    /** A pointer to a timer class */
    frc::Timer* m_timer;

    /** A boolean to indicate we have exceeded our distance */
    bool driven_distance_exceeded;

    /************************** Private methods *****************************/

    /** A common function shared between all constructors */
    void common_constructor_function();

}; // end class CmdAutoDriveStraight

#endif // #ifndef CMDAUTODRIVESTRAIGHT_H
