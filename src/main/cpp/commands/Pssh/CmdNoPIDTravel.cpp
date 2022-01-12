/** ===========================================================================
 * @file   CmdNoPIDTravel.cpp
 * @brief  This file defines the CmdNoPIDTravel class.
 *
 * The CmdNoPIDTravel class is used to set the power cell mover Pssh in travel
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
 * Copyright (c) 2019-2020 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// Include the header file for the CmdNoPIDTravel class
#include "commands/Pssh/CmdNoPIDTravel.h"

// If we are NOT using the PID controller for Pssh
#if !USE_PID_PSSH

// Include the header file that defines the F310 axes/buttons
#include "HIDs/LogitechF310.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// Include the I/O stream class, so we can write to the console
#include <iostream>

/************************ Member function definitions *************************/

// The default constructor for the CmdNoPIDTravel class
CmdNoPIDTravel::CmdNoPIDTravel() {

  // Use Requires() here to declare subsystem dependencies

  // Require the use of the Pssh subsystem
  // NOTE: We have to use the .get() function because Requires() expects
  //       a pointer to a subsystem, and the pointer below is a 
  //       shared_ptr.
  // See https://stackoverflow.com/questions/505143/getting-a-normal-ptr-from-shared-ptr
  Requires(Robot::m_subSysPssh.get());

} // end CmdNoPIDTravel::CmdNoPIDTravel()

// The destructor for the CmdNoPIDTravel class
CmdNoPIDTravel::~CmdNoPIDTravel() {

} // end CmdNoPIDTravel::~CmdNoPIDTravel()

// Called just before this Command runs the first time
void CmdNoPIDTravel::Initialize() {

  // Indicate that this command is interruptable
  SetInterruptible(k_CmdIsInterruptable);

} // end CmdNoPIDTravel::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdNoPIDTravel::Execute() {

  // Tell Pssh to go to travel mode
  Robot::m_subSysPssh->Travel();

}  // end CmdNoPIDTravel::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdNoPIDTravel::IsFinished() {

  return false;

} // end CmdNoPIDTravel::IsFinished()

// Called once after isFinished returns true
void CmdNoPIDTravel::End() {


} // end CmdNoPIDTravel::End()

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdNoPIDTravel::Interrupted() {

  // Run the same method as End()
  CmdNoPIDTravel::End();

} // end CmdNoPIDTravel::Interrupted()

#endif // #if !USE_PID_PSSH
