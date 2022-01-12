/** ===========================================================================
 * @file   commands/PIDPssh/CmdTravel.cpp
 * @brief  This file defines the CmdTravel class.
 *
 * The CmdTravel class is used to set the power cell mover Pssh in travel
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

// Include the header file for the CmdTravel class
#include "commands/PIDPssh/CmdTravel.h"

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

// The default constructor for the CmdTravel class
CmdTravel::CmdTravel() {

  // Use Requires() here to declare subsystem dependencies

  // Require the use of the PID Pssh subsystem
  // NOTE: We have to use the .get() function because Requires() expects
  //       a pointer to a subsystem, and the pointer below is a 
  //       shared_ptr.
  // See https://stackoverflow.com/questions/505143/getting-a-normal-ptr-from-shared-ptr
  Requires(Robot::m_PIDsubSysPssh.get());

} // end CmdTravel::CmdTravel()

// The destructor for the CmdTravel class
CmdTravel::~CmdTravel() {

} // end CmdTravel::~CmdTravel()

// Called just before this Command runs the first time
void CmdTravel::Initialize() {

  // Indicate that this command is interruptable
  SetInterruptible(k_CmdIsInterruptable);

} // end CmdTravel::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdTravel::Execute() {

  // Tell Pssh to go to travel mode
  Robot::m_PIDsubSysPssh->Travel();

}  // end CmdTravel::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdTravel::IsFinished() {

  // Boolean to see if we are finished
  bool at_travel_position;

  // Boolean to see if we have timed out
  bool cmd_timed_out;

  // See if we are on target
  at_travel_position = Robot::m_PIDsubSysPssh->OnTarget();

  // See if we have timed out
  cmd_timed_out = IsTimedOut();

  // If we are on target...
  if(at_travel_position)
    // Set the state to travel
    Robot::m_PIDsubSysPssh->SetPsshState(k_PsshTravelString);

  // If we have timed out
  if(cmd_timed_out)
    // Set the state to timed out
    Robot::m_PIDsubSysPssh->SetPsshState(k_PsshTimedOutString);

  // Return true if we have made our target or timed out
  return at_travel_position || cmd_timed_out;

} // end CmdTravel::IsFinished()

// Called once after isFinished returns true
void CmdTravel::End() {

  // Stop Pssh
  Robot::m_PIDsubSysPssh->Stop();

} // end CmdTravel::End()

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdTravel::Interrupted() {

  // Run the same method as End()
  CmdTravel::End();

} // end CmdTravel::Interrupted()

#endif // #if USE_PID_PSSH
