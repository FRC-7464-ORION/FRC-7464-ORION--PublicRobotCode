/** ===========================================================================
 * @file   CmdGrpAutoDefCenter.cpp
 * @brief  This file defines the CmdGrpAutoDefCenter class.
 *
 * The CmdGrpAutoDefCenter class is used to allow the robot to be controlled 
 * autonomously using a set of commands.
 *
 * This command group is for a defensive strategy, starting in the center
 * field position, in the autonomous period.
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
 * Copyright (c) 2020-2022 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// Include the header file for the CmdGrpAutoDefCenter class
#include "commandGroups/Autonomous/CmdGrpAutoDefCenter.h"

// Include the header file for driving straight autonomously
#include "commands/DriveTrain/CmdAutoDriveStraight.h"

// Include the header file for turning autonomously
#include "commands/DriveTrain/CmdAutoTurnAngle.h"

// Include the header files for disabling/enabling smoothing mode
#include "commands/DriveTrain/CmdDisableSmoothingMode.h"
#include "commands/DriveTrain/CmdEnableSmoothingMode.h"

// Include the header file for the CmdWaitSeconds class
#include "commands/Generic/CmdWaitSeconds.h"

/************************** Library Header Files ******************************/

/************************ Member function definitions *************************/

// The constructor for the CmdGrpAutoDefCenter class
CmdGrpAutoDefCenter::CmdGrpAutoDefCenter(
    SubSysDriveTrain* drivetrain,
    AHRS* ahrs,
    SubSysBallShooter* ballshooter) {

  // Set the name
  SetName("CmdGrpAutoDefCenter");

  // Add commands to be sequentially ran...
  AddCommands(

    // Disable smoothing mode
    CmdDisableSmoothingMode(drivetrain),

    // Drive straight forward 5.0 seconds at 20%
    CmdAutoDriveStraight(
      drivetrain,
      0.20,
      CmdAutoDriveStraight::SECONDS,
      CmdAutoDriveStraight::FORWARD,
      5.0),

    // Wait 5.0 seconds
    CmdWaitSeconds(5.0_s),

    // Drive straight reverse 5.0 seconds at 20%
    CmdAutoDriveStraight(
      drivetrain,
      0.20,
      CmdAutoDriveStraight::SECONDS,
      CmdAutoDriveStraight::REVERSE,
      5.0),

    // Enable smoothing mode
    CmdEnableSmoothingMode(drivetrain)

  );

} // end CmdGrpAutoDefCenter::CmdGrpAutoDefCenter(...)
