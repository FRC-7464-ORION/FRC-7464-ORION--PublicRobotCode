/** ===========================================================================
 * @file   CmdZeroAHRSYaw.cpp
 * @brief  This file defines the CmdZeroAHRSYaw class.
 *
 * The CmdZeroAHRSYaw class is used to manually zero the yaw on the AHRS of
 * the NavX MXP IMU.
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

// Include the header file for the CmdZeroAHRSYaw class
#include "commands/DriveTrain/CmdZeroAHRSYaw.h"

/************************** Library Header Files ******************************/


/************************ Member function definitions *************************/

// The default constructor for the CmdZeroAHRSYaw class
CmdZeroAHRSYaw::CmdZeroAHRSYaw() {

  // Indicate our turn is not completed
  m_command_completed = false;

} // end CmdZeroAHRSYaw::CmdZeroAHRSYaw()

// The destructor for the CmdZeroAHRSYaw class
CmdZeroAHRSYaw::~CmdZeroAHRSYaw() {

} // end CmdZeroAHRSYaw::~CmdZeroAHRSYaw()

// Called just before this Command runs the first time
void CmdZeroAHRSYaw::Initialize() {

  // Indicate our turn is not completed
  m_command_completed = false;

} // end CmdZeroAHRSYaw::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdZeroAHRSYaw::Execute() {

  // Zero the yaw, so we are always pointing to 0 when starting
  // (Robot-Based Reference System)
  Robot::m_AHRS->ZeroYaw();

  // Indicate we have now finished the command
  m_command_completed = true;

}  // end CmdZeroAHRSYaw::Execute()

// Make this return true when this Command no longer needs to run Execute()
bool CmdZeroAHRSYaw::IsFinished() {

  // Return if we are completed or not
  return m_command_completed;

} // end CmdZeroAHRSYaw::IsFinished()

// Called once after isFinished returns true
void CmdZeroAHRSYaw::End() {

  // Indicate our command is not completed, as we will be called again
  m_command_completed = false;

} // end CmdZeroAHRSYaw::End()

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdZeroAHRSYaw::Interrupted() {

  // Call the End method
  End();

} // end CmdZeroAHRSYaw::Interrupted()
