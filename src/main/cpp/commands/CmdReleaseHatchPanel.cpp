/** ===========================================================================
 * @file   CmdReleaseHatchPanel.cpp
 * @brief  This file defines the CmdReleaseHatchPanel class.
 *
 * The CmdReleaseHatchPanel class is used to allow the robot to release a
 * hatch panel.
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

// Include the header file for the CmdReleaseHatchPanel class
#include "commands/CmdReleaseHatchPanel.h"

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

// The default constructor for the CmdReleaseHatchPanel class
CmdReleaseHatchPanel::CmdReleaseHatchPanel() {

  // Use Requires() here to declare subsystem dependencies

  // Require the use of the Capt. Hook subsystem
  Requires(Robot::m_subSysCaptHook.get());

} // end CmdReleaseHatchPanel::CmdReleaseHatchPanel()

// The destructor for the CmdReleaseHatchPanel class
CmdReleaseHatchPanel::~CmdReleaseHatchPanel() {

} // end CmdReleaseHatchPanel::~CmdReleaseHatchPanel()

// Called just before this Command runs the first time
void CmdReleaseHatchPanel::Initialize() {

} // end CmdReleaseHatchPanel::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdReleaseHatchPanel::Execute() {

  // Declare a pointer to a joystick
  frc::Joystick* joystick;

  // Declare raw trigger output
  double raw_right_trigger_axis;

  // Declare the inverted right trigger axis
  double inv_right_trigger_axis;

  // Declare corrected axis for motor speed
  double corrected_right_trigger_axis_motor_speed;

  // Get the pointer to the OI's joystick
  joystick = Robot::m_oi->getJoystick();

  // Get the raw axis output from the left trigger
  raw_right_trigger_axis = joystick->GetRawAxis(k_rightTrigger_Y);

  // Invert the trigger axis
  // (we are going backward, so we need negative values, but both triggers
  //  output positive numbers)
  inv_right_trigger_axis = Correct_Y_Axis_Inversion(raw_right_trigger_axis);

  // Now null, desensitize and limit the axis for better speed control
  corrected_right_trigger_axis_motor_speed =
    NullDesensLimit(inv_right_trigger_axis,
                    Robot::m_subSysCaptHook->GetCaptHookNullZone(),
                    Robot::m_subSysCaptHook->GetCaptHookLimit(),
                    Robot::m_subSysCaptHook->GetCaptHookExponent());

  // Control Capt. Hook using the corrected axis
  Robot::m_subSysCaptHook->MoveHatchPanel(
    corrected_right_trigger_axis_motor_speed);

} // end CmdReleaseHatchPanel::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdReleaseHatchPanel::IsFinished() {

  // Always return false, so we can always release a hatch panel
  return false;

} // end CmdReleaseHatchPanel::IsFinished()

// Called once after isFinished returns true
void CmdReleaseHatchPanel::End() {

  // With IsFinished() always returning false, this should never
  //   run. But just in case, this stops Capt. Hook.
  Robot::m_subSysCaptHook->MoveHatchPanel(k_MotorStopSpeed);

} // end CmdReleaseHatchPanel::End()

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdReleaseHatchPanel::Interrupted() {

  // This should only run when we switch between releasing a hatch panel and
  //   grabbing a hatch panel, so we will stop Capt. Hook
  Robot::m_subSysCaptHook->MoveHatchPanel(k_MotorStopSpeed);

} // end CmdReleaseHatchPanel::Interrupted()

#endif // #if !USE_PID_CAPT_HOOK
