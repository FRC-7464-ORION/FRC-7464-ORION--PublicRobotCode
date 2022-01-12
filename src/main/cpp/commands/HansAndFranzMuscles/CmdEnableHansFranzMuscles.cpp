/** ===========================================================================
 * @file   CmdEnableHansFranzMuscles.cpp
 * @brief  This file defines the CmdEnableHansFranzMuscles class.
 *
 * The CmdEnableHansFranzMuscles class is used to enable the Hans and Franz
 * muscles.
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

// Include the header file for the CmdEnableHansFranzMuscles class
#include "commands/HansAndFranzMuscles/CmdEnableHansFranzMuscles.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// Include the I/O stream class, so we can write to the console
#include <iostream>

/************************ Member function definitions *************************/

// The default constructor for the CmdEnableHansFranzMuscles class
CmdEnableHansFranzMuscles::CmdEnableHansFranzMuscles() {

  // Use Requires() here to declare subsystem dependencies

  // Require the use of the Hans/Franz subsystems
  // NOTE: We have to use the .get() function because Requires() expects
  //       a pointer to a subsystem, and the pointer below is a 
  //       shared_ptr.
  // See https://stackoverflow.com/questions/505143/getting-a-normal-ptr-from-shared-ptr
  Requires(Robot::m_subSysHansFranzMuscles.get());

} // end CmdEnableHansFranzMuscles::CmdEnableHansFranzMuscles()

// The destructor for the CmdEnableHansFranzMuscles class
CmdEnableHansFranzMuscles::~CmdEnableHansFranzMuscles() {

} // end CmdEnableHansFranzMuscles::~CmdEnableHansFranzMuscles()

// Called just before this Command runs the first time
void CmdEnableHansFranzMuscles::Initialize() {

  // Indicate we are not finished
  m_this_command_is_finished = false;

} // end CmdEnableHansFranzMuscles::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdEnableHansFranzMuscles::Execute() {

  // Enable Hans and Franz Muscles
  Robot::m_subSysHansFranzMuscles->EnableHansFranzMuscles();

  // TODO: This may need to be a command for muscles only.
  //       Then have similar one for arms.
  //       Then have a command group to enable both.

  // Enable Hans and Franz Arms
  Robot::m_subSysHansFranzArms->EnableHansFranzArms();

  // Now indicate we are finished
  m_this_command_is_finished = true;

}  // end CmdEnableHansFranzMuscles::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdEnableHansFranzMuscles::IsFinished() {

  // Return if we are finished
  return m_this_command_is_finished;

} // end CmdEnableHansFranzMuscles::IsFinished()

// Called once after isFinished returns true
void CmdEnableHansFranzMuscles::End() {

} // end CmdEnableHansFranzMuscles::End()

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdEnableHansFranzMuscles::Interrupted() {

} // end CmdEnableHansFranzMuscles::Interrupted()
