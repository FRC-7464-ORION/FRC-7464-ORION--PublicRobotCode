/** ===========================================================================
 * @file   CmdToggleDriveDirection.cpp
 * @brief  This file defines the CmdToggleDriveDirection class.
 *
 * The CmdToggleDriveDirection class is used to allow the robot to be driven
 * in a fashion where the front becomes the back, or the back becomes the 
 * front. Also, the switched camera server will switch between the front and
 * back cameras. This allows the robot to be controlled without having to 
 * rotate 180 degrees before moving.
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
 * Copyright (c) 2020-2022 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// Include the header file for the CmdToggleDriveDirection class
#include "commands/DriveTrain/CmdToggleDriveDirection.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// Include the I/O stream class, so we can write to the console
#include <iostream>

/************************ Member function definitions *************************/

// The constructor for the CmdToggleDriveDirection class
CmdToggleDriveDirection::CmdToggleDriveDirection(
  SubSysDriveTrain* subsystem)
  : m_subSysDriveTrain(subsystem){

  // Set the command's name
  SetName("CmdToggleDriveDirection");

  // Require the use of the drive train subsystem
  AddRequirements({subsystem});

  // Start with the drive direction normal
  m_drive_direction_reversed = false;

  // Indicate we have not started
  m_this_command_is_finished = false;

} // end CmdToggleDriveDirection::CmdToggleDriveDirection(...)

// The destructor for the CmdToggleDriveDirection class
CmdToggleDriveDirection::~CmdToggleDriveDirection() {

} // end CmdToggleDriveDirection::~CmdToggleDriveDirection()

// Called just before this Command runs the first time
void CmdToggleDriveDirection::Initialize() {

  // Indicate we have not started
  m_this_command_is_finished = false;

  // Toggle the drive train direction
  m_drive_direction_reversed = !m_drive_direction_reversed;

  // If we are supposed to use normal drive direction
  if (!m_drive_direction_reversed)
  {

    // Use normal drive direction
    m_subSysDriveTrain->SetDriveDirectionSwitchingNormal();

  }
  else // we are supposed to use reversed direction
  {

    // Use the reversed drive direction
    m_subSysDriveTrain->SetDriveDirectionSwitchingReverse();

  } // end if (!m_drive_direction_reversed)

} // end CmdToggleDriveDirection::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdToggleDriveDirection::Execute() {

  // Indicate we are finished
  m_this_command_is_finished = true;

}  // end CmdToggleDriveDirection::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdToggleDriveDirection::IsFinished() {

  // Indicate we are done
  return m_this_command_is_finished;

} // end CmdToggleDriveDirection::IsFinished()

// Called once after isFinished returns true, OR command 
//   is interrupted or canceled
void CmdToggleDriveDirection::End(bool interrupted) {

  // Indicate we are finished
  m_this_command_is_finished = true;

} // end CmdToggleDriveDirection::End()
