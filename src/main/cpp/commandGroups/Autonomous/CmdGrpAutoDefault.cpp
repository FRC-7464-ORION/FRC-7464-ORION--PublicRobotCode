/** ===========================================================================
 * @file   CmdGrpAutoDefault.cpp
 * @brief  This file defines the CmdGrpAutoDefault class.
 *
 * The CmdGrpAutoDefault class is used to allow the robot to be controlled 
 * autonomously using a set of commands.
 * 
 * This command group is the default for the autonomous period.
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

// Include the header file for the CmdGrpAutoDefault class
#include "commandGroups/Autonomous/CmdGrpAutoDefault.h"

// Include the header file for driving straight autonomously
#include "commands/DriveTrain/CmdAutoDriveStraight.h"

// Include the header file for turning autonomously
#include "commands/DriveTrain/CmdAutoTurnAngle.h"

// Include the header files for disabling/enabling smoothing mode
#include "commands/DriveTrain/CmdDisableSmoothingMode.h"
#include "commands/DriveTrain/CmdEnableSmoothingMode.h"

// Include the header files for shooting low and high
#include "commands/BallShooter/CmdBallShooterShootLow.h"
#include "commands/BallShooter/CmdBallShooterShootHigh.h"

// Include the header file for the CmdWaitSeconds class
#include "commands/Generic/CmdWaitSeconds.h"

/************************** Library Header Files ******************************/

/************************ Member function definitions *************************/

// The constructor for the CmdAutoDriveStraight class
CmdGrpAutoDefault::CmdGrpAutoDefault(
    SubSysDriveTrain* drivetrain,
    AHRS* ahrs,
    SubSysBallShooter* ballshooter) {

  // Set the name
  SetName("CmdGrpAutoDefault");

  // Add commands to be sequentially ran...
  AddCommands(

    // Shoot a ball at the low target
    CmdBallShooterShootLow(ballshooter)

  ); // end AddCommands()

} // end CmdGrpAutoDefault::CmdGrpAutoDefault(...)
