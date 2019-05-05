/** ===========================================================================
 * @file   PIDCmdGrabHatchPanel.cpp
 * @brief  This file defines the PIDCmdGrabHatchPanel class.
 *
 * The PIDCmdGrabHatchPanel class is used to allow the robot to grab a hatch
 * panel from a loading station, using a PID controller.
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

// Include the header file for the PIDCmdGrabHatchPanel class
#include "commands/PIDCmdGrabHatchPanel.h"

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

// The default constructor for the CmdGrabHatchPanel class
PIDCmdGrabHatchPanel::PIDCmdGrabHatchPanel() {

  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::m_PIDsubSysCaptHook.get());

} // end PIDCmdGrabHatchPanel::PIDCmdGrabHatchPanel()

// The destructor for the PIDCmdGrabHatchPanel class
PIDCmdGrabHatchPanel::~PIDCmdGrabHatchPanel() {

} // end PIDCmdGrabHatchPanel::~PIDCmdGrabHatchPanel()

// Called just before this Command runs the first time
void PIDCmdGrabHatchPanel::Initialize() {

  // Set the timeout for this command
  SetTimeout(k_CaptHookGrabOrReleaseHatchPanelTimeout);

} // end PIDCmdGrabHatchPanel::Initialize()

// Called repeatedly when this Command is scheduled to run
void PIDCmdGrabHatchPanel::Execute() {

  // Run the method to grab the hatch panel
  Robot::m_PIDsubSysCaptHook->GrabHatchPanel();

} // end PIDCmdGrabHatchPanel::Execute()

// Make this return true when this Command no longer needs to run execute()
bool PIDCmdGrabHatchPanel::IsFinished() {

  // Boolean to see if we are done grabbing
  bool done_grabbing;
  // Boolean to see if we are timed out
  bool timed_out;

  // See if we have reached our target setpoint, which means we are done
  done_grabbing = Robot::m_PIDsubSysCaptHook->OnTarget();
  // See if we have timed out
  timed_out = IsTimedOut();

  // If we are done grabbing...
  if(done_grabbing)
    // Set our state to grabbed
    Robot::m_PIDsubSysCaptHook->SetCaptHookState(k_CaptHookGrabbedString);

  // If this command has timed out...
  if(timed_out)
    // Set our state to timed out
    Robot::m_PIDsubSysCaptHook->SetCaptHookState(k_CaptHookTimedOutString);

  // We are finished when we are at our set point or we timed out
  return done_grabbing || timed_out;

} // end PIDCmdGrabHatchPanel::IsFinished()

// Called once after isFinished returns true
void PIDCmdGrabHatchPanel::End() {

  // Stop Capt. Hook
  Robot::m_PIDsubSysCaptHook->StopCaptHook();

} // end PIDCmdGrabHatchPanel::End()

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDCmdGrabHatchPanel::Interrupted() {

  // !!! NEED TO STOP MOTOR HERE !!!
  Robot::m_PIDsubSysCaptHook->StopCaptHook();

} // end PIDCmdGrabHatchPanel::Interrupted()

#endif // #if USE_PID_CAPT_HOOK
