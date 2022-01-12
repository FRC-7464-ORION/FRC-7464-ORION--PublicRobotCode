/** ===========================================================================
 * @file   CmdMoveHansFranzArms.cpp
 * @brief  This file defines the CmdMoveHansFranzArms class.
 *
 * The CmdMoveHansFranzArms class is used to control the movement of the robot
 * using a differential drive in arcade mode.
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

// The default constructor for the CmdMoveHansFranzArms class
CmdMoveHansFranzArms::CmdMoveHansFranzArms() {

  // Use Requires() here to declare subsystem dependencies

  // Require the use of the Hans and Franz subsystem
  // NOTE: We have to use the .get() function because Requires() expects
  //       a pointer to a subsystem, and the pointer below is a 
  //       shared_ptr.
  // See https://stackoverflow.com/questions/505143/getting-a-normal-ptr-from-shared-ptr
  Requires(Robot::m_subSysHansFranzArms.get());

} // end CmdMoveHansFranzArms::CmdMoveHansFranzArms()

// The destructor for the CmdMoveHansFranzArms class
CmdMoveHansFranzArms::~CmdMoveHansFranzArms() {

} // end CmdMoveHansFranzArms::~CmdMoveHansFranzArms()

// Called just before this Command runs the first time
void CmdMoveHansFranzArms::Initialize() {

} // end CmdMoveHansFranzArms::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdMoveHansFranzArms::Execute() {

  // Declare a pointer to a joystick
  frc::Joystick* joystick;

  // Declare raw axis output
  double raw_axis;

  // Declare inverted axis
  double inv_axis;

  // Declare corrected axes for motor speed
  double corrected_axis_motor_speed;

  // Get the pointer to the OI's secondary joystick
  joystick = Robot::m_oi->getSecondaryJoystick();

  // Get the raw axis output from the right thumbstick y axis
  raw_axis = joystick->GetRawAxis(k_F310_rightThumbstick_Y_axis);

  // Invert the axis so we go the expected forward/back direction
  inv_axis = Correct_Y_Axis_Inversion(raw_axis);

  // Now null, desensitize and limit the axis, so we have better
  //   control at low speeds
  corrected_axis_motor_speed =
    NullDesensLimit(inv_axis,
                    Robot::m_subSysHansFranzArms->GetHansFranzArmsNullZone(),
                    Robot::m_subSysHansFranzArms->GetHansFranzArmsLimit(),
                    Robot::m_subSysHansFranzArms->GetHansFranzArmsExponent());

  // Drive arcade style using the corrected joystick inputs
  Robot::m_subSysHansFranzArms->MoveHansFranzArms(
    corrected_axis_motor_speed
  );

}  // end CmdMoveHansFranzArms::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdMoveHansFranzArms::IsFinished() {

  // Always return false, because we always want to move the robot arms
  return false;

} // end CmdMoveHansFranzArms::IsFinished()

// Called once after isFinished returns true
void CmdMoveHansFranzArms::End() {

  // With IsFinished() always returning false, this should never
  //   run. But just in case, this stops the drive train.
  Robot::m_subSysHansFranzArms->MoveHansFranzArms(k_MotorStopSpeed);

} // end CmdMoveHansFranzArms::End()

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdMoveHansFranzArms::Interrupted() {

  // We should never be interrupted, but just in case
  Robot::m_subSysHansFranzArms->MoveHansFranzArms(k_MotorStopSpeed);

} // end CmdMoveHansFranzArms::Interrupted()
