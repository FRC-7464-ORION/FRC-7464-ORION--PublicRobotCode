/** ===========================================================================
 * @file   CmdEnableHansFranzArms.cpp
 * @brief  This file defines the CmdEnableHansFranzArms class.
 *
 * The CmdEnableHansFranzArms class is used to enable the Hans and Franz
 * arms.
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
 * Copyright (c) 2019-2020 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// Include the header file for the CmdEnableHansFranzArms class
#include "commands/HansAndFranzArms/CmdEnableHansFranzArms.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// Include the I/O stream class, so we can write to the console
#include <iostream>

/************************ Member function definitions *************************/

// The default constructor for the CmdEnableHansFranzArms class
CmdEnableHansFranzArms::CmdEnableHansFranzArms() {

  // Use Requires() here to declare subsystem dependencies

  // Require the use of the Hans/Franz subsystems
  // NOTE: We have to use the .get() function because Requires() expects
  //       a pointer to a subsystem, and the pointer below is a 
  //       shared_ptr.
  // See https://stackoverflow.com/questions/505143/getting-a-normal-ptr-from-shared-ptr
  Requires(Robot::m_subSysHansFranzArms.get());

} // end CmdEnableHansFranzArms::CmdEnableHansFranzArms()

// The destructor for the CmdEnableHansFranzArms class
CmdEnableHansFranzArms::~CmdEnableHansFranzArms() {

} // end CmdEnableHansFranzArms::~CmdEnableHansFranzArms()

// Called just before this Command runs the first time
void CmdEnableHansFranzArms::Initialize() {

  // Indicate we are not finished
  m_this_command_is_finished = false;

} // end CmdEnableHansFranzArms::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdEnableHansFranzArms::Execute() {

  // Enable Hans and Franz Arms
  Robot::m_subSysHansFranzArms->EnableHansFranzArms();

  // If the move Hans and Franz arms command pointer has been intialized...
  if(Robot::m_cmdMoveHansFranzArms != nullptr) {
    // Start the move Hans and Franz Arms command
    Robot::m_cmdMoveHansFranzArms->Start();
  } // end if(Robot::m_cmdMoveHansFranzArms != nullptr)

#if ORION_DEBUG
  else {
    // Output a error
    frc::DriverStation::ReportError("Robot::m_cmdMoveHansFranzArms not initialized!");
  }
#endif // #if ORION_DEBUG

  // Now indicate we are finished
  m_this_command_is_finished = true;

}  // end CmdEnableHansFranzArms::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdEnableHansFranzArms::IsFinished() {

  // Return if we are finished
  return m_this_command_is_finished;

} // end CmdEnableHansFranzArms::IsFinished()

// Called once after isFinished returns true
void CmdEnableHansFranzArms::End() {

} // end CmdEnableHansFranzArms::End()

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdEnableHansFranzArms::Interrupted() {

} // end CmdEnableHansFranzArms::Interrupted()
