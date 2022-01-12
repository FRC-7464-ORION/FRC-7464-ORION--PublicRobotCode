/** ===========================================================================
 * @file   commands/PIDPssh/CmdDump.cpp
 * @brief  This file defines the CmdDump class.
 *
 * The CmdDump class is used to set the power cell mover Pssh in dump
 * position.
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

// Include the header file for the CmdDump class
#include "commands/PIDPssh/CmdDump.h"

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

// Include the header file that defines the F310 axes/buttons
#include "HIDs/LogitechF310.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// Include the I/O stream class, so we can write to the console
#include <iostream>

/************************ Member function definitions *************************/

// The default constructor for the CmdDump class
CmdDump::CmdDump() {

  // Use Requires() here to declare subsystem dependencies

  // Require the use of the PID Pssh subsystem
  // NOTE: We have to use the .get() function because Requires() expects
  //       a pointer to a subsystem, and the pointer below is a 
  //       shared_ptr.
  // See https://stackoverflow.com/questions/505143/getting-a-normal-ptr-from-shared-ptr
  Requires(Robot::m_PIDsubSysPssh.get());

} // end CmdDump::CmdDump()

// The destructor for the CmdDump class
CmdDump::~CmdDump() {

} // end CmdDump::~CmdDump()

// Called just before this Command runs the first time
void CmdDump::Initialize() {

  // Indicate that this command is interruptable
  SetInterruptible(k_CmdIsInterruptable);

} // end CmdDump::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdDump::Execute() {

  // Tell Pssh to go to dump mode
  Robot::m_PIDsubSysPssh->Dump();

}  // end CmdDump::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdDump::IsFinished() {

  // We'll always return false, as gravity and/or the spring 
  // will constantly change our position
  return false;

} // end CmdDump::IsFinished()

// Called once after isFinished returns true
void CmdDump::End() {

  // NOTE: This method should never be executed, as IsFinished() 
  //       should never return true

  // Stop Pssh
  Robot::m_PIDsubSysPssh->Stop();

} // end CmdDump::End()

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdDump::Interrupted() {

  // Stop Pssh
  Robot::m_PIDsubSysPssh->Stop();

} // end CmdDump::Interrupted()

#endif // #if USE_PID_PSSH
