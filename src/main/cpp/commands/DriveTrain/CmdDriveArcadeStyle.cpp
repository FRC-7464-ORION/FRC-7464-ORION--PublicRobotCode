/** ===========================================================================
 * @file   CmdDriveArcadeStyle.cpp
 * @brief  This file defines the CmdDriveArcadeStyle class.
 *
 * The CmdDriveArcadeStyle class is used to control the movement of the robot
 * using a differential drive in arcade mode.
 *
 * COPYRIGHT NOTICES:
 *
 * Some portions:
 *
 * Copyright (c) 2017-2019 FIRST. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FIRST BSD license file in the root directory of
 * the project.
 *
 * Some portions:
 *
 * Copyright (c) 2019-2022 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// Include the header file for the cmdDriveArcadeStyle class
#include "commands/DriveTrain/CmdDriveArcadeStyle.h"

// Include the header file that defines the F310 axes/buttons
#include "HIDs/LogitechF310.h"

// Include the header file for HID utility functions
#include "HIDs/HID_Utility_Fcns.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// Include the I/O stream class, so we can write to the console
#include <iostream>

/************************ Member function definitions *************************/

// The constructor for the CmdDriveArcadeStyle class
CmdDriveArcadeStyle::CmdDriveArcadeStyle(
  SubSysDriveTrain* subsystem, frc::Joystick* joystick)
  : m_subSysDriveTrain(subsystem), m_joystick(joystick) {

  // Set the command's name
  SetName("CmdDriveArcadeStyle");

  // Require the use of the drive train subsystem
  AddRequirements({subsystem});

} // end CmdDriveArcadeStyle::CmdDriveArcadeStyle(...)

// The destructor for the CmdDriveArcadeStyle class
CmdDriveArcadeStyle::~CmdDriveArcadeStyle() {

} // end CmdDriveArcadeStyle::~CmdDriveArcadeStyle()

// Called just before this Command runs the first time
void CmdDriveArcadeStyle::Initialize() {

  // Set the drive train mode string to arcade
  m_subSysDriveTrain->SetDriveTrainModeStringToArcade();

} // end CmdDriveArcadeStyle::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdDriveArcadeStyle::Execute() {

  // Declare raw thumbstick outputs
  double raw_Y_axis;
  double raw_X_axis;

  // Declare inverted y axis
  double inv_Y_axis;

  // Declare corrected axes for motor speed
  double corrected_Y_axis_motor_speed;
  double corrected_X_axis_motor_speed;

  // Get the raw Y axis output from the left thumbstick
  raw_Y_axis = m_joystick->GetRawAxis(k_F310_leftThumbstick_Y_axis);

  // Get the raw X axis output from the left thumbstick
  raw_X_axis = m_joystick->GetRawAxis(k_F310_leftThumbstick_X_axis);

  // Invert the y axis so we go the expected forward/back direction
  inv_Y_axis = Correct_Y_Axis_Inversion(raw_Y_axis);

  // Now null, desensitize and limit both y and x axes, so we have better
  //   control at low speeds
  corrected_Y_axis_motor_speed =
    NullDesensLimit(inv_Y_axis,
                    m_subSysDriveTrain->GetDriveTrainNullZone(),
                    m_subSysDriveTrain->GetDriveTrainLimit(),
                    m_subSysDriveTrain->GetDriveTrainExponent());

  corrected_X_axis_motor_speed =
    NullDesensLimit(raw_X_axis,
                    m_subSysDriveTrain->GetDriveTrainNullZone(),
                    m_subSysDriveTrain->GetDriveTrainLimit(),
                    m_subSysDriveTrain->GetDriveTrainExponent());

  // Drive arcade style using the corrected joystick inputs
  m_subSysDriveTrain->DriveArcadeStyle(
    corrected_Y_axis_motor_speed,
    corrected_X_axis_motor_speed
  );

}  // end CmdDriveArcadeStyle::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdDriveArcadeStyle::IsFinished() {

  // Always return false, because we always want to drive the robot!
  return false;

} // end CmdDriveArcadeStyle::IsFinished()

// Called once after isFinished returns true, OR command 
//   is interrupted or canceled
void CmdDriveArcadeStyle::End(bool interrupted) {

  // With IsFinished() always returning false, this should never
  //   run. But just in case, this stops the drive train.
  m_subSysDriveTrain->DriveArcadeStyle(k_MotorStopSpeed,
                                       k_MotorStopSpeed);

} // end CmdDriveArcadeStyle::End()
