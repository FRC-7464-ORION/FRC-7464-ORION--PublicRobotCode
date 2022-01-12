/** ===========================================================================
 * @file   CmdDisableHansFranzMuscles.cpp
 * @brief  This file defines the CmdDisableHansFranzMuscles class.
 *
 * The CmdDisableHansFranzMuscles class is used to disable the Hans/Franz 
 * cylinders.
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

// Include the header file for the CmdDisableHansFranzMuscles class
#include "commands/HansAndFranzMuscles/CmdDisableHansFranzMuscles.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// Include the I/O stream class, so we can write to the console
#include <iostream>

/************************ Member function definitions *************************/

// The default constructor for the CmdDisableHansFranzMuscles class
CmdDisableHansFranzMuscles::CmdDisableHansFranzMuscles() {

  // Use Requires() here to declare subsystem dependencies

  // Require the use of the Hans/Franz subsystem
  // NOTE: We have to use the .get() function because Requires() expects
  //       a pointer to a subsystem, and the pointer below is a 
  //       shared_ptr.
  // See https://stackoverflow.com/questions/505143/getting-a-normal-ptr-from-shared-ptr
  Requires(Robot::m_subSysHansFranzMuscles.get());

} // end CmdDisableHansFranzMuscles::CmdDisableHansFranzMuscles()

// The destructor for the CmdDisableHansFranzMuscles class
CmdDisableHansFranzMuscles::~CmdDisableHansFranzMuscles() {

} // end CmdDisableHansFranzMuscles::~CmdDisableHansFranzMuscles()

// Called just before this Command runs the first time
void CmdDisableHansFranzMuscles::Initialize() {

  // Indicate we are not finished
  m_this_command_is_finished = false;

} // end CmdDisableHansFranzMuscles::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdDisableHansFranzMuscles::Execute() {

  // Disable Hans and Franz muscles
  Robot::m_subSysHansFranzMuscles->DisableHansFranzMuscles();

  // Now indicate we are finished
  m_this_command_is_finished = true;

}  // end CmdDisableHansFranzMuscles::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdDisableHansFranzMuscles::IsFinished() {

  // Return if we are finished
  return m_this_command_is_finished;

} // end CmdDisableHansFranzMuscles::IsFinished()

// Called once after isFinished returns true
void CmdDisableHansFranzMuscles::End() {


} // end CmdDisableHansFranzMuscles::End()

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdDisableHansFranzMuscles::Interrupted() {


} // end CmdDisableHansFranzMuscles::Interrupted()
