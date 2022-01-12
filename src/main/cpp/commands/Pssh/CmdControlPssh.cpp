/** ===========================================================================
 * @file   CmdControlPssh.cpp
 * @brief  This file defines the CmdControlPssh class.
 *
 * The CmdControlPssh class is used to allow the robot to control the power
 * cell transporter.
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

// Include the header file for the CmdControlPssh class
#include "commands/Pssh/CmdControlPssh.h"

// If we are not using the Pssh PID controller...
#if !USE_PID_PSSH

// Include the header file that defines the F310 axes/buttons
#include "HIDs/LogitechF310.h"

// Include the header file for HID utility functions
#include "HIDs/HID_Utility_Fcns.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

/************************ Member function definitions *************************/

// The default constructor for the CmdControlPssh class
CmdControlPssh::CmdControlPssh() {

  // Use Requires() here to declare subsystem dependencies

  // Require the use of the Pssh subsystem
  // NOTE: We have to use the .get() function because Requires() expects
  //       a pointer to a subsystem, and the pointer below is a 
  //       shared_ptr.
  // See https://stackoverflow.com/questions/505143/getting-a-normal-ptr-from-shared-ptr
  Requires(Robot::m_subSysPssh.get());

} // end CmdControlPssh::CmdControlPssh()

// The destructor for the CmdControlPssh class
CmdControlPssh::~CmdControlPssh() {

} // end CmdControlPssh::~CmdControlPssh()

// Called just before this Command runs the first time
void CmdControlPssh::Initialize() {

} // end CmdControlPssh::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdControlPssh::Execute() {

  // Declare a pointer to a joystick
  frc::Joystick* joystick;

  // Declare raw axis output
  double raw_axis;

  // Declare the inverted axis
  double inv_axis;

  // Declare corrected axis for motor speed
  double corrected_axis_motor_speed;

  // Get the pointer to the OI's secondary joystick
  joystick = Robot::m_oi->getSecondaryJoystick();

  // Get the raw axis output from the 2nd joystick left y axis 
  raw_axis = joystick->GetRawAxis(k_F310_leftThumbstick_Y_axis);

  // Invert the trigger axis
  // (we are going backward, so we need negative values, but both triggers
  //  output positive numbers)
  inv_axis = Correct_Y_Axis_Inversion(raw_axis);

  // Now null, desensitize and limit the axis for better speed control
  corrected_axis_motor_speed =
    NullDesensLimit(inv_axis,
                    Robot::m_subSysPssh->GetPsshNullZone(),
                    Robot::m_subSysPssh->GetPsshLimit(),
                    Robot::m_subSysPssh->GetPsshExponent());

  // Control Pssh using the corrected axis
  Robot::m_subSysPssh->ControlPssh(corrected_axis_motor_speed);

} // end CmdControlPssh::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdControlPssh::IsFinished() {

  // Always return false, so we can always control the power cell transporter
  return false;

} // end CmdControlPssh::IsFinished()

// Called once after isFinished returns true
void CmdControlPssh::End() {

  // With IsFinished() always returning false, this should never
  //   run. But just in case, this stops PAT Turner
  Robot::m_subSysPssh->ControlPssh(k_MotorStopSpeed);

} // end CmdControlPssh::End()

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdControlPssh::Interrupted() {

  // This should only run when we switch between turning the WoF counter-
  // clockwise to clockwise
  Robot::m_subSysPssh->ControlPssh(k_MotorStopSpeed);

} // end CmdControlPssh::Interrupted()

#endif // #if !USE_PID_PSSH
