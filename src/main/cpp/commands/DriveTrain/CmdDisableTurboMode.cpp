/** ===========================================================================
 * @file   CmdDisableTurboMode.cpp
 * @brief  This file defines the CmdDisableTurboMode class.
 *
 * The CmdDisableTurboMode class is used to allow the robot to be drive using
 * a differential drive in non-turbo mode (giving extra speed in either arcade
 * or tank mode).
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
 * Copyright (c) 2019-2022 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// Include the header file for the CmdDisableTurboMode class
#include "commands/DriveTrain/CmdDisableTurboMode.h"

// Include the header file that defines the F310 axes/buttons
#include "HIDs/LogitechF310.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// Include the I/O stream class, so we can write to the console
#include <iostream>

/************************ Member function definitions *************************/

// The constructor for the CmdDisableTurboMode class
CmdDisableTurboMode::CmdDisableTurboMode(
  SubSysDriveTrain* subsystem)
  : m_subSysDriveTrain(subsystem){

  // Set the command's name
  SetName("CmdDisableTurboMode");

  // Require the use of the drive train subsystem
  AddRequirements({subsystem});

} // end CmdDisableTurboMode::CmdDisableTurboMode(...)

// The destructor for the CmdDisableTurboMode class
CmdDisableTurboMode::~CmdDisableTurboMode() {

} // end CmdDisableTurboMode::~CmdDisableTurboMode()

// Called just before this Command runs the first time
void CmdDisableTurboMode::Initialize() {

  // Turn on turbo mode
  m_subSysDriveTrain->SetTurboModeOff();

} // end CmdDisableTurboMode::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdDisableTurboMode::Execute() {

  // Run the same method as Initialize()
  CmdDisableTurboMode::Initialize();

}  // end CmdDisableTurboMode::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdDisableTurboMode::IsFinished() {

  // Return true, as we set the turbo mode on already
  return true;

} // end CmdDisableTurboMode::IsFinished()

// Called once after isFinished returns true, OR command 
//   is interrupted or canceled
void CmdDisableTurboMode::End(bool interrupted) {

  // No need to do anything here

} // end CmdDisableTurboMode::End()
