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
 * Copyright (c) 2020 FRC Team #7464 - ORION. All Rights Reserved.
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

// Include the header file for the CmdWaitSeconds class
#include "commands/Generic/CmdWaitSeconds.h"

/************************** Library Header Files ******************************/

/************************ Member function definitions *************************/

// The default constructor for the CmdAutoDriveStraight class
CmdGrpAutoDefault::CmdGrpAutoDefault() {

  // TODO: Should we use pointers to commands, intialize them with new,
  //       use the pointers in AddSequential, AddParallel, etc., then
  //       delete the instances using the pointers?
  //       See https://www.chiefdelphi.com/t/can-the-old-commandgroup-framework-cause-memory-leaks/375847

  // Drive straight forward 1/2 second at 20%
  AddSequential(new CmdAutoDriveStraight(
    0.20,
    CmdAutoDriveStraight::SECONDS,
    CmdAutoDriveStraight::FORWARD,
    0.50   
  ));

  // Wait 1 second 
  AddSequential(new CmdWaitSeconds(2.0));

  // Drive straight back 1/2 second at 20%
  AddSequential(new CmdAutoDriveStraight(
    0.20,
    CmdAutoDriveStraight::SECONDS,
    CmdAutoDriveStraight::REVERSE,
    0.50    
  ));

  // Wait 1 second 
  AddSequential(new CmdWaitSeconds(2.0));

  // Turn at 40% speed 45 degrees to the right
  AddSequential(new CmdAutoTurnAngle(0.30, 45.0));

  // Wait 1 second 
  AddSequential(new CmdWaitSeconds(2.0));

  // Turn at 40% speed 45 degrees to the left
  AddSequential(new CmdAutoTurnAngle(0.30, -45.0));

} // end CmdGrpAutoDefault::CmdGrpAutoDefault()

// The destructor for the CmdGrpAutoDefault class
CmdGrpAutoDefault::~CmdGrpAutoDefault() {


} // end CmdGrpAutoDefault::~CmdGrpAutoDefault()
