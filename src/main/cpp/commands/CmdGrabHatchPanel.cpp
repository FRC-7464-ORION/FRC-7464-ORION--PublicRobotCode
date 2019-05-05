/** ===========================================================================
 * @file   CmdGrabHatchPanel.cpp
 * @brief  This file defines the CmdGrabHatchPanel class.
 *
 * The CmdGrabHatchPanel class is used to allow the robot to grab a hatch
 * panel.
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

// Include the header file for the CmdGrabHatchPanel class
#include "commands/CmdGrabHatchPanel.h"

// If we are not using the PID controller for Capt. Hook
#if !USE_PID_CAPT_HOOK

// Include the header file that defines the F310 axes/buttons
#include "HIDs/LogitechF310.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// Include the WPI library header file
#include "frc/WPILib.h"

/************************ Member function definitions *************************/

// The default constructor for the CmdGrabHatchPanel class
CmdGrabHatchPanel::CmdGrabHatchPanel() {

  // Use Requires() here to declare subsystem dependencies

  // Require the use of the Capt. Hook subsystem
  Requires(Robot::m_subSysCaptHook.get());

} // end CmdGrabHatchPanel::CmdGrabHatchPanel()

// The destructor for the CmdGrabHatchPanel class
CmdGrabHatchPanel::~CmdGrabHatchPanel() {

} // end CmdGrabHatchPanel::~CmdGrabHatchPanel()

// Called just before this Command runs the first time
void CmdGrabHatchPanel::Initialize() {

} // end CmdGrabHatchPanel::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdGrabHatchPanel::Execute() {

  // Declare a pointer to a joystick
  frc::Joystick* joystick;

  // Declare raw trigger output
  double raw_left_trigger_axis;

  // Declare corrected axis for motor speed
  double corrected_left_trigger_axis_motor_speed;

  // Get the pointer to the OI's joystick
  joystick = Robot::m_oi->getJoystick();

  // Get the raw axis output from the left trigger
  raw_left_trigger_axis = joystick->GetRawAxis(k_leftTrigger_Y);

  // Now null, desensitize, and limit the axis for better speed control
  corrected_left_trigger_axis_motor_speed =
    NullDesensLimit(raw_left_trigger_axis,
                    Robot::m_subSysCaptHook->GetCaptHookNullZone(),
                    Robot::m_subSysCaptHook->GetCaptHookLimit(),
                    Robot::m_subSysCaptHook->GetCaptHookExponent());

  // Control Capt. Hook using the corrected axis
  Robot::m_subSysCaptHook->MoveHatchPanel(corrected_left_trigger_axis_motor_speed);

} // end CmdGrabHatchPanel::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdGrabHatchPanel::IsFinished() {

  // Always return false, so we can always move a hatch panel
  return false;

} // end CmdGrabHatchPanel::IsFinished()

// Called once after isFinished returns true
void CmdGrabHatchPanel::End() {

  // With IsFinished() always returning false, this should never
  //   run. But just in case, this stops Capt. Hook.
  Robot::m_subSysCaptHook->MoveHatchPanel(k_MotorStopSpeed);

} // end CmdGrabHatchPanel::End()

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdGrabHatchPanel::Interrupted() {

  // This should only run when we switch between grabbing a hatch panel and
  //   releasing a hatch panel, so we will stop Capt. Hook
  Robot::m_subSysCaptHook->MoveHatchPanel(k_MotorStopSpeed);

} // end CmdGrabHatchPanel::Interrupted()

#endif // #if !USE_PID_CAPT_HOOK
