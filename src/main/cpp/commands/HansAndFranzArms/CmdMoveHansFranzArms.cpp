/** ===========================================================================
 * @file   CmdMoveHansFranzArms.cpp
 * @brief  This file defines the CmdMoveHansFranzArms class.
 *
 * The CmdMoveHansFranzArms class is used to control the movement of the robot
 * Hans and Franz arms.
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
 * Copyright (c) 2020 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// Include the header file for the CmdMoveHansFranzArms class
#include "commands/HansAndFranzArms/CmdMoveHansFranzArms.h"

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

// The constructor for the CmdMoveHansFranzArms class
CmdMoveHansFranzArms::CmdMoveHansFranzArms(SubSysHansFranzArms* subsystem,
                                           frc::Joystick* joystick)
  : m_subSysHansFranzArms(subsystem), m_joystick(joystick) {

  // Set the command's name
  SetName("CmdMoveHansFranzArms");

  // Require the use of the Hans and Franz arm subsystem
  AddRequirements({subsystem});

} // end CmdMoveHansFranzArms::CmdMoveHansFranzArms()

// The destructor for the CmdMoveHansFranzArms class
CmdMoveHansFranzArms::~CmdMoveHansFranzArms() {

} // end CmdMoveHansFranzArms::~CmdMoveHansFranzArms()

// Called just before this Command runs the first time
void CmdMoveHansFranzArms::Initialize() {

} // end CmdMoveHansFranzArms::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdMoveHansFranzArms::Execute() {

  // Declare raw axis output
  double raw_axis;

  // Declare inverted axis
  double inv_axis;

  // Declare corrected axes for motor speed
  double corrected_axis_motor_speed;

  // Get the raw axis output from the right thumbstick y axis
  raw_axis = m_joystick->GetRawAxis(k_F310_rightThumbstick_Y_axis);

  // Invert the axis so we go the expected forward/back direction
  inv_axis = Correct_Y_Axis_Inversion(raw_axis);

  // Now null, desensitize and limit the axis, so we have better
  //   control at low speeds
  corrected_axis_motor_speed =
    NullDesensLimit(inv_axis,
                    m_subSysHansFranzArms->GetHansFranzArmsNullZone(),
                    m_subSysHansFranzArms->GetHansFranzArmsLimit(),
                    m_subSysHansFranzArms->GetHansFranzArmsExponent());

  // Move the arms using the corrected joystick input
  m_subSysHansFranzArms->MoveHansFranzArms(
    corrected_axis_motor_speed
  );

}  // end CmdMoveHansFranzArms::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdMoveHansFranzArms::IsFinished() {

  // Always return false, because we always want to move the robot arms
  return false;

} // end CmdMoveHansFranzArms::IsFinished()

// Called once after isFinished returns true, OR command 
//   is interrupted or canceled
void CmdMoveHansFranzArms::End(bool interrupted) {

  // With IsFinished() always returning false, this should never
  //   run. But just in case, this stops the drive train.
  m_subSysHansFranzArms->MoveHansFranzArms(k_MotorStopSpeed);

} // end CmdMoveHansFranzArms::End()
