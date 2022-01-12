/** ===========================================================================
 * @file   CmdDriveTankStyle.cpp
 * @brief  This file defines the CmdDriveTankStyle class.
 *
 * The CmdDriveTankStyle class is used to control the movement of the robot
 * using a differential drive in tank mode.
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

// Include the header file for the cmdDriveTankStyle class
#include "commands/DriveTrain/CmdDriveTankStyle.h"

// Include the header file for HID utility functions
#include "HIDs/HID_Utility_Fcns.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// Include the I/O stream class, so we can write to the console
#include <iostream>

/************************ Member function definitions *************************/

// The constructor for the CmdDriveTankStyle class
CmdDriveTankStyle::CmdDriveTankStyle(
  SubSysDriveTrain* subsystem, frc::Joystick* joystick)
  : m_subSysDriveTrain(subsystem), m_joystick(joystick) {

  // Set the command's name
  SetName("CmdDriveTankStyle");

  // Require the use of the drive train subsystem
  AddRequirements({subsystem});

} // end CmdDriveTankStyle::CmdDriveTankStyle(...)

// The destructor for the CmdDriveTankStyle class
CmdDriveTankStyle::~CmdDriveTankStyle() {

} // end CmdDriveTankStyle::~CmdDriveTankStyle()

// Called just before this Command runs the first time
void CmdDriveTankStyle::Initialize() {

  // Set the drive train mode string to tank
  m_subSysDriveTrain->SetDriveTrainModeStringToTank();

} // end CmdDriveTankStyle::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdDriveTankStyle::Execute() {

  // Declare raw thumbstick outputs
  double raw_left_Y_axis;
  double raw_right_Y_axis;

  // Declare inverted y axes for left and right
  double inv_left_Y_axis;
  double inv_right_Y_axis;

  // Declare corrected axes for motor speed
  double corrected_left_Y_axis_motor_speed;
  double corrected_right_Y_axis_motor_speed;

  // Get the raw Y axis from the left joystick
  raw_left_Y_axis = m_joystick->GetRawAxis(k_F310_leftThumbstick_Y_axis);

  // Get the raw Y axis from the right joystick
  raw_right_Y_axis = m_joystick->GetRawAxis(k_F310_rightThumbstick_Y_axis);

  // Invert the left y axis so we go the expected forward/back direction
  inv_left_Y_axis = Correct_Y_Axis_Inversion(raw_left_Y_axis);

  // Invert the right y axis so we go the expected forward/back direction
  inv_right_Y_axis = Correct_Y_Axis_Inversion(raw_right_Y_axis);

  // Now null, desensitize and limit both left and right Y axes, so we have
  //   better control at low speeds
  corrected_left_Y_axis_motor_speed =
    NullDesensLimit(inv_left_Y_axis,
                    m_subSysDriveTrain->GetDriveTrainNullZone(),
                    m_subSysDriveTrain->GetDriveTrainLimit(),
                    m_subSysDriveTrain->GetDriveTrainExponent());

  corrected_right_Y_axis_motor_speed =
    NullDesensLimit(inv_right_Y_axis,
                    m_subSysDriveTrain->GetDriveTrainNullZone(),
                    m_subSysDriveTrain->GetDriveTrainLimit(),
                    m_subSysDriveTrain->GetDriveTrainExponent());

  // Drive tank style using the corrected joystick inputs
  m_subSysDriveTrain->DriveTankStyle(
    corrected_left_Y_axis_motor_speed,
    corrected_right_Y_axis_motor_speed
  );

}  // end CmdDriveArcadeStyle::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdDriveTankStyle::IsFinished() {

  // Always return false, because we always want to drive the robot!
  return false;

} // end CmdDriveTankStyle::IsFinished()

// Called once after isFinished returns true, OR command 
//   is interrupted or canceled
void CmdDriveTankStyle::End(bool interrupted) {

  // With IsFinished() always returning false, this should never
  //   run. But just in case, this stops the drive train.
  m_subSysDriveTrain->DriveTankStyle(k_MotorStopSpeed,
                                     k_MotorStopSpeed);

} // end CmdDriveTankStyle::End()
