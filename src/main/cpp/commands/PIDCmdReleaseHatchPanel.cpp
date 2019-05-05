/** ===========================================================================
 * @file   PIDCmdReleaseHatchPanel.cpp
 * @brief  This file defines the PIDCmdReleaseHatchPanel class.
 *
 * The PIDCmdReleaseHatchPanel class is used to allow the robot to release a
 * hatch panel to a rocket or cargo ship, using a PID controller.
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
 * Copyright (c) 2019 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in 
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// Include the header file for the PIDCmdReleaseHatchPanel class
#include "commands/PIDCmdReleaseHatchPanel.h"

// If we are using Capt. Hook with a PID controller...
#if USE_PID_CAPT_HOOK

// Include the header file that defines the F310 axes/buttons
#include "HIDs/LogitechF310.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// Include the WPI library header file
#include "frc/WPILib.h"

/************************ Member function definitions *************************/

// The default constructor for the PIDCmdGrabHatchPanel class
PIDCmdReleaseHatchPanel::PIDCmdReleaseHatchPanel() {

  // Use Requires() here to declare subsystem dependencies
  // We require the Capt. Hook PID subsystem for this command
  Requires(Robot::m_PIDsubSysCaptHook.get());

} // end PIDCmdReleaseHatchPanel::PIDCmdReleaseHatchPanel()

// The destructor for the CmdGrabHatchPanel class
PIDCmdReleaseHatchPanel::~PIDCmdReleaseHatchPanel() {

} // end PIDCmdReleaseHatchPanel::~PIDCmdReleaseHatchPanel()

// Called just before this Command runs the first time
void PIDCmdReleaseHatchPanel::Initialize() {

  // Set the timeout for this command
  // If the command does not finish by the time specified by
  // k_CaptHookGrabOrReleaseHatchPanelTimeout, the command
  // will be terminated.
  SetTimeout(k_CaptHookGrabOrReleaseHatchPanelTimeout);

} // end PIDCmdReleaseHatchPanel::Initialize()

// Called repeatedly when this Command is scheduled to run
void PIDCmdReleaseHatchPanel::Execute() {

  // Run the method in the subsystem to release the hatch panel
  Robot::m_PIDsubSysCaptHook->ReleaseHatchPanel();

} // end PIDCmdReleaseHatchPanel::Execute()

// Make this return true when this Command no longer needs to run execute()
bool PIDCmdReleaseHatchPanel::IsFinished() {

  // Boolean to see if we are done releasing
  bool done_releasing;
  // Boolean to see if we are timed out
  bool timed_out;

  // See if we have reached our target setpoint, which means we are done
  done_releasing = Robot::m_PIDsubSysCaptHook->OnTarget();
  // See if we have timed out
  timed_out = IsTimedOut();

  // If we are done releasing...
  if(done_releasing)
    // Set our state to released
    Robot::m_PIDsubSysCaptHook->SetCaptHookState(k_CaptHookReleasedString);

  // If this command has timed out...
  if(timed_out)
    // Set our state to timed out
    Robot::m_PIDsubSysCaptHook->SetCaptHookState(k_CaptHookTimedOutString);

  // We are finished when we are at our set point or we timed out
  return done_releasing || timed_out;

} // end PIDCmdReleaseHatchPanel::IsFinished()

// Called once after isFinished returns true
void PIDCmdReleaseHatchPanel::End() {

  // Stop Capt. Hook
  Robot::m_PIDsubSysCaptHook->StopCaptHook();

} // end PIDCmdReleaseHatchPanel::End()

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDCmdReleaseHatchPanel::Interrupted() {

  // Stop Capt. Hook before we go the other way.
  Robot::m_PIDsubSysCaptHook->StopCaptHook();

} // end PIDCmdReleaseHatchPanel::Interrupted()

#endif // #if USE_PID_CAPT_HOOK
