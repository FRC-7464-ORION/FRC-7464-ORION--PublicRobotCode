/** ===========================================================================
 * @file   CmdRetractHansFranzMuscles.cpp
 * @brief  This file defines the CmdRetractHansFranzMuscles class.
 *
 * The CmdRetractHansFranzMuscles class is used to move Hans/Franz cylinders
 * to the retracted position.
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

// Include the header file for the CmdRetractHansFranzMuscles class
#include "commands/HansAndFranzMuscles/CmdRetractHansFranzMuscles.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// Include the I/O stream class, so we can write to the console
#include <iostream>

/************************ Member function definitions *************************/

// The constructor for the CmdRetractHansFranzMuscles class
CmdRetractHansFranzMuscles::CmdRetractHansFranzMuscles(
    SubSysHansFranzMuscles* subsystem) 
  : m_subSysHansFranzMuscles(subsystem) {

  // Set the command's name
  SetName("CmdRetractHansFranzMuscles");

  // Require the use of the Hans and Franz muscles subsystem
  AddRequirements({subsystem});

} // end CmdRetractHansFranzMuscles::CmdRetractHansFranzMuscles()

// The destructor for the CmdRetractHansFranzMuscles class
CmdRetractHansFranzMuscles::~CmdRetractHansFranzMuscles() {

} // end CmdRetractHansFranzMuscles::~CmdRetractHansFranzMuscles()

// Called just before this Command runs the first time
void CmdRetractHansFranzMuscles::Initialize() {

  // Indicate we are not finished
  m_this_command_is_finished = false;

} // end CmdRetractHansFranzMuscles::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdRetractHansFranzMuscles::Execute() {

  // Retract Hans and Franz muscles
  m_subSysHansFranzMuscles->RetractHansFranzMuscles();

  // Now indicate we are finished
  m_this_command_is_finished = true;

}  // end CmdRetractHansFranzMuscles::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdRetractHansFranzMuscles::IsFinished() {

  // Return if we are finished
  return m_this_command_is_finished;

} // end CmdRetractHansFranzMuscles::IsFinished()

// Called once after isFinished returns true, OR command 
//   is interrupted or canceled
void CmdRetractHansFranzMuscles::End(bool interrupted) {


} // end CmdRetractHansFranzMuscles::End()
