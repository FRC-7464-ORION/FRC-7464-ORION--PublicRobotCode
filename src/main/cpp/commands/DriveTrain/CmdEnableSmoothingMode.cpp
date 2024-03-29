/** ===========================================================================
 * @file   CmdEnableSmoothingMode.cpp
 * @brief  This file defines the CmdEnableSmoothingMode class.
 *
 * The CmdEnableSmoothingMode class is used to allow the robot to be 
 * driven using a smoothing function, implemented using an infinite
 * impulse response digital low pass filter (IIR DLPF).
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

// Include the header file for the CmdEnableSmoothingMode class
#include "commands/DriveTrain/CmdEnableSmoothingMode.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// Include the I/O stream class, so we can write to the console
#include <iostream>

/************************ Member function definitions *************************/

// The constructor for the CmdEnableSmoothingMode class
CmdEnableSmoothingMode::CmdEnableSmoothingMode(
  SubSysDriveTrain* subsystem)
  : m_subSysDriveTrain(subsystem){

  // Set the command's name
  SetName("CmdEnableSmoothingMode");

  // Require the use of the drive train subsystem
  AddRequirements({subsystem});

  // Indicate we have not started
  m_this_command_is_finished = false;

} // end CmdEnableSmoothingMode::CmdEnableSmoothingMode(...)

// The destructor for the CmdEnableSmoothingMode class
CmdEnableSmoothingMode::~CmdEnableSmoothingMode() {

} // end CmdEnableSmoothingMode::~CmdEnableSmoothingMode()

// Called just before this Command runs the first time
void CmdEnableSmoothingMode::Initialize() {

  // Indicate we have not started
  m_this_command_is_finished = false;

  // Disable smoothing mode
  m_subSysDriveTrain->SetSmoothingModeOn();

} // end CmdEnableSmoothingMode::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdEnableSmoothingMode::Execute() {

  // Indicate we are finished
  m_this_command_is_finished = true;

}  // end CmdEnableSmoothingMode::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdEnableSmoothingMode::IsFinished() {

  // Indicate we are done
  return m_this_command_is_finished;

} // end CmdEnableSmoothingMode::IsFinished()

// Called once after isFinished returns true, OR command 
//   is interrupted or canceled
void CmdEnableSmoothingMode::End(bool interrupted) {

  // Indicate we are finished
  m_this_command_is_finished = true;

} // end CmdEnableSmoothingMode::End()
