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
 * Copyright (c) 2022 FRC Team #7464 - ORION. All Rights Reserved.
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

// The constructor for the CmdZeroAHRSYaw class
CmdZeroAHRSYaw::CmdZeroAHRSYaw(
  SubSysDriveTrain* subsystem,
  AHRS* ahrs)
  : m_subSysDriveTrain(subsystem),
    m_AHRS(ahrs){

  // Set the command's name
  SetName("CmdZeroAHRSYaw");

  // Indicate we have not started
  m_command_completed = false;

} // end CmdZeroAHRSYaw::CmdZeroAHRSYaw(...)

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
  m_AHRS->ZeroYaw();

  // Indicate we have now finished the command
  m_command_completed = true;

}  // end CmdZeroAHRSYaw::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdZeroAHRSYaw::IsFinished() {

  // Indicate we are done
  return m_command_completed;

} // end CmdZeroAHRSYaw::IsFinished()

// Called once after isFinished returns true, OR command 
//   is interrupted or canceled
void CmdZeroAHRSYaw::End(bool interrupted) {

  // Indicate we are finished
  m_command_completed = true;

} // end CmdZeroAHRSYaw::End()
