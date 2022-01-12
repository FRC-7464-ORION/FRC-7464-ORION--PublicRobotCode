/** ===========================================================================
 * @file   CmdToggleSmoothingMode.cpp
 * @brief  This file defines the CmdToggleSmoothingMode class.
 *
 * The CmdToggleSmoothingMode class is used to toggle the robot to be driven
 * using or not using a smoothing function, implemented using an infinite
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
 * Copyright (c) 2019-2020 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// Include the header file for the CmdToggleSmoothingMode class
#include "commands/DriveTrain/CmdToggleSmoothingMode.h"

// Include the header file that defines the F310 axes/buttons
#include "HIDs/LogitechF310.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// Include the I/O stream class, so we can write to the console
#include <iostream>

/************************ Member function definitions *************************/

// The constructor for the CmdToggleSmoothingMode class
CmdToggleSmoothingMode::CmdToggleSmoothingMode(
  SubSysDriveTrain* subsystem)
  : m_subSysDriveTrain(subsystem){

  // Set the command's name
  SetName("CmdToggleSmoothingMode");

  // Require the use of the drive train subsystem
  AddRequirements({subsystem});

  // Turn on the local smoothing mode
  m_local_smooth_mode = true;

  // Indicate we have not started
  m_this_command_is_finished = false;

} // end CmdToggleSmoothingMode::CmdToggleSmoothingMode(...)

// The destructor for the CmdToggleSmoothingMode class
CmdToggleSmoothingMode::~CmdToggleSmoothingMode() {

} // end CmdToggleSmoothingMode::~CmdToggleSmoothingMode()

// Called just before this Command runs the first time
void CmdToggleSmoothingMode::Initialize() {

  // Indicate we have not started
  m_this_command_is_finished = false;

  // Toggle the local smooth mode boolean
  m_local_smooth_mode = !m_local_smooth_mode;

  // If the local smoothing mode is on...
  if (m_local_smooth_mode)
  {
    // Enable smoothing mode
    m_subSysDriveTrain->SetSmoothingModeOn();
  }
  else
  {
    // Disable smoothing mode
    m_subSysDriveTrain->SetSmoothingModeOff();
  }

} // end CmdToggleSmoothingMode::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdToggleSmoothingMode::Execute() {

  // Indicate we are finished
  m_this_command_is_finished = true;

}  // end CmdToggleSmoothingMode::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdToggleSmoothingMode::IsFinished() {

  // Indicate we are done
  return m_this_command_is_finished;

} // end CmdToggleSmoothingMode::IsFinished()

// Called once after isFinished returns true, OR command 
//   is interrupted or canceled
void CmdToggleSmoothingMode::End(bool interrupted) {

  // Indicate we are finished
  m_this_command_is_finished = true;

} // end CmdToggleSmoothingMode::End()
