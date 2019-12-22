/** ===========================================================================
 * @file   CmdEnableTurboMode.cpp
 * @brief  This file defines the CmdEnableTurboMode class.
 *
 * The CmdEnableTurboMode class is used to allow the robot to be drive using
 * a differential drive in turbo mode (giving extra speed in either arcade or
 * tank mode).
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
 * Copyright (c) 2019 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// Include the header file for the CmdEnableTurboMode class
#include "commands/CmdEnableTurboMode.h"

// Include the header file that defines the F310 axes/buttons
#include "HIDs/LogitechF310.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// Include the I/O stream class, so we can write to the console
#include <iostream>

// Include the WPI library header file
#include "frc/WPILib.h"

/************************ Member function definitions *************************/

// The default constructor for the CmdEnableTurboMode class
CmdEnableTurboMode::CmdEnableTurboMode() {

  // Use Requires() here to declare subsystem dependencies

  // Require the use of the drive train subsystem
  Requires(Robot::m_subSysDriveTrain.get());

} // end CmdEnableTurboMode::CmdEnableTurboMode()

// The destructor for the CmdEnableTurboMode class
CmdEnableTurboMode::~CmdEnableTurboMode() {

} // end CmdEnableTurboMode::~CmdEnableTurboMode()

// Called just before this Command runs the first time
void CmdEnableTurboMode::Initialize() {

  // Turn on turbo mode
  Robot::m_subSysDriveTrain->SetTurboModeOn();

} // end CmdEnableTurboMode::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdEnableTurboMode::Execute() {

  // Run the same method as Initialize()
  CmdEnableTurboMode::Initialize();

}  // end CmdEnableTurboMode::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdEnableTurboMode::IsFinished() {

  // Return true, as we set the turbo mode on already
  return true;

} // end CmdEnableTurboMode::IsFinished()

// Called once after isFinished returns true
void CmdEnableTurboMode::End() {

  // No need to do anything here

} // end CmdEnableTurboMode::End()

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdEnableTurboMode::Interrupted() {

  // Run the same method as End()
  CmdEnableTurboMode::End();

} // end CmdEnableTurboMode::Interrupted()
