/** ===========================================================================
 * @file   CmdResetAHRSYaw.cpp
 * @brief  This file defines the CmdResetAHRSYaw class.
 *
 * The CmdResetAHRSYaw class is used to manually reset the yaw on the AHRS of
 * the NavX MXP IMU to zero.
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

// Include the header file for the CmdResetAHRSYaw class
#include "commands/DriveTrain/CmdResetAHRSYaw.h"

/************************** Library Header Files ******************************/


/************************ Member function definitions *************************/

// The constructor for the CmdResetAHRSYaw class
CmdResetAHRSYaw::CmdResetAHRSYaw(
  SubSysDriveTrain* subsystem,
  AHRS* ahrs)
  : m_subSysDriveTrain(subsystem),
    m_AHRS(ahrs){

  // Set the command's name
  SetName("CmdResetAHRSYaw");

  // Indicate we have not started
  m_command_completed = false;

} // end CmdResetAHRSYaw::CmdResetAHRSYaw(...)

// The destructor for the CmdResetAHRSYaw class
CmdResetAHRSYaw::~CmdResetAHRSYaw() {

} // end CmdResetAHRSYaw::~CmdResetAHRSYaw()

// Called just before this Command runs the first time
void CmdResetAHRSYaw::Initialize() {

  // Indicate our turn is not completed
  m_command_completed = false;

} // end CmdResetAHRSYaw::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdResetAHRSYaw::Execute() {

  // Reset the yaw, so we are always pointing to 0 when starting
  // (Robot-Based Reference System)
  m_AHRS->Reset();

  // Indicate we have now finished the command
  m_command_completed = true;

}  // end CmdResetAHRSYaw::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdResetAHRSYaw::IsFinished() {

  // Indicate we are done
  return m_command_completed;

} // end CmdResetAHRSYaw::IsFinished()

// Called once after isFinished returns true, OR command 
//   is interrupted or canceled
void CmdResetAHRSYaw::End(bool interrupted) {

  // Indicate we are finished
  m_command_completed = true;

} // end CmdResetAHRSYaw::End()
