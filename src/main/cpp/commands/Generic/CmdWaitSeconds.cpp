/** ===========================================================================
 * @file   CmdWaitSeconds.cpp
 * @brief  This file defines the CmdWaitSeconds class.
 *
 * The CmdWaitSeconds class is used to allow the robot to be paused for 
 * a given amount of time in seconds, especially between commands who
 * need time to "settle".
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

// Include the header file for the CmdWaitSeconds class
#include "commands/Generic/CmdWaitSeconds.h"

/************************** Library Header Files ******************************/

/************************ Member function definitions *************************/

// The constructor for the CmdWaitSeconds class
CmdWaitSeconds::CmdWaitSeconds(
  double sec) {

  // Set the command's name
  SetName("CmdWaitSeconds");

  // Set the wait time to the passed in time
  wait_time_seconds = sec;

} // end CmdWaitSeconds::CmdWaitSeconds(double sec)

// The destructor for the CmdAutoDriveStraight class
CmdWaitSeconds::~CmdWaitSeconds() {

} // end CmdWaitSeconds::~CmdWaitSeconds()

// Called just before this Command runs the first time
void CmdWaitSeconds::Initialize() {

  // Indicate we have not exceeded our time
  wait_time_exceeded = false;

  // Reset the timer
  m_timer.Reset();

  // Start the timer
  m_timer.Start();

} // end CmdWaitSeconds::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdWaitSeconds::Execute() {

  // If the timer has exceeded our wait time...
  if(m_timer.Get() >= wait_time_seconds)
  {
    // We have exceeded our wait time
    wait_time_exceeded = true;
  }

}  // end CmdWaitSeconds::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdWaitSeconds::IsFinished() {

  // Return the status of if we exceeded our time
  return wait_time_exceeded;

} // end CmdWaitSeconds::IsFinished()

// Called once after isFinished returns true, OR command 
//   is interrupted or canceled
void CmdWaitSeconds::End(bool interrupted) {

  // Stop the timer
  m_timer.Stop();

} // end CmdWaitSeconds::End()
