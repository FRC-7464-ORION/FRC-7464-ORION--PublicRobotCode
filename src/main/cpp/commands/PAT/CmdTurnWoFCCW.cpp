/** ===========================================================================
 * @file   CmdTurnWoFCCW.cpp
 * @brief  This file defines the CmdTurnWoFCCW class.
 *
 * The CmdTurnWoFCCW class is used to allow the robot to turn the Wheel of
 * Fortune (WoF) counter-clockwise (CCW).
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

// Include the header file for the CmdTurnWoFCCW class
#include "commands/PAT/CmdTurnWoFCCW.h"

// Include the header file that defines the F310 axes/buttons
#include "HIDs/LogitechF310.h"

// Include the header file for HID utility functions
#include "HIDs/HID_Utility_Fcns.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

/************************ Member function definitions *************************/

// The default constructor for the CmdTurnWoFCCW class
CmdTurnWoFCCW::CmdTurnWoFCCW() {

  // Use Requires() here to declare subsystem dependencies

  // Require the use of the PAT Turner subsystem
  // NOTE: We have to use the .get() function because Requires() expects
  //       a pointer to a subsystem, and the pointer below is a 
  //       shared_ptr.
  // See https://stackoverflow.com/questions/505143/getting-a-normal-ptr-from-shared-ptr
  Requires(Robot::m_subSysPATTurner.get());

} // end CmdTurnWoFCCW::CmdTurnWoFCCW()

// The destructor for the CmdTurnWoFCCW class
CmdTurnWoFCCW::~CmdTurnWoFCCW() {

} // end CmdTurnWoFCCW::~CmdTurnWoFCCW()

// Called just before this Command runs the first time
void CmdTurnWoFCCW::Initialize() {

} // end CmdTurnWoFCCW::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdTurnWoFCCW::Execute() {

  // Declare a pointer to a joystick
  frc::Joystick* joystick;

  // Declare raw axis output
  double raw_axis;

  // Declare the inverted axis
  double inv_axis;

  // Get the pointer to the OI's secondary joystick
  joystick = Robot::m_oi->getSecondaryJoystick();

  // Get the raw axis output from the 2nd joystick right trigger y axis
  raw_axis = joystick->GetRawAxis(k_F310_rightTrigger_Y_axis);

  // Invert the axis
  // (we are going backward, so we need negative values, but both triggers
  //  output positive numbers)
  inv_axis = Correct_Y_Axis_Inversion(raw_axis);

  // Send the controller the raw inverted speed as we are filtering in
  // the subsystem
  Robot::m_subSysPATTurner->TurnWoF(inv_axis);

} // end CmdTurnWoFCCW::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdTurnWoFCCW::IsFinished() {

  // Always return false, so we can always turn the WoF
  return false;

} // end CmdTurnWoFCCW::IsFinished()

// Called once after isFinished returns true
void CmdTurnWoFCCW::End() {

  // With IsFinished() always returning false, this should never
  //   run. But just in case, this stops PAT Turner
  Robot::m_subSysPATTurner->TurnWoF(k_MotorStopSpeed);

} // end CmdTurnWoFCCW::End()

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdTurnWoFCCW::Interrupted() {

  // This should only run when we switch between turning the WoF counter-
  // clockwise to clockwise
  Robot::m_subSysPATTurner->TurnWoF(k_MotorStopSpeed);

} // end CmdTurnWoFCCW::Interrupted()
