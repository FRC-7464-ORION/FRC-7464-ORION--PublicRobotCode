/** ===========================================================================
 * @file   CmdTurnWoFCW.cpp
 * @brief  This file defines the CmdTurnWoFCW class.
 *
 * The CmdTurnWoFCW class is used to allow the robot to turn the Wheel of
 * Fortune (WoF) clockwise (CW).
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

// Include the header file for the CmdTurnWoFCW class
#include "commands/PAT/CmdTurnWoFCW.h"

// Include the header file that defines the F310 axes/buttons
#include "HIDs/LogitechF310.h"

// Include the header file for HID utility functions
#include "HIDs/HID_Utility_Fcns.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

/************************ Member function definitions *************************/

// The default constructor for the CmdTurnWoFCW class
CmdTurnWoFCW::CmdTurnWoFCW() {

  // Use Requires() here to declare subsystem dependencies

  // Require the use of the PAT Turner subsystem
  // NOTE: We have to use the .get() function because Requires() expects
  //       a pointer to a subsystem, and the pointer below is a 
  //       shared_ptr.
  // See https://stackoverflow.com/questions/505143/getting-a-normal-ptr-from-shared-ptr
  Requires(Robot::m_subSysPATTurner.get());

} // end CmdTurnWoFCW::CmdTurnWoFCW()

// The destructor for the CmdTurnWoFCW class
CmdTurnWoFCW::~CmdTurnWoFCW() {

} // end CmdTurnWoFCW::~CmdTurnWoFCW()

// Called just before this Command runs the first time
void CmdTurnWoFCW::Initialize() {

} // end CmdTurnWoFCW::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdTurnWoFCW::Execute() {

  // Declare a pointer to a joystick
  frc::Joystick* joystick;

  // Declare raw output axis
  double raw_axis;

  // Get the pointer to the OI's secondary joystick
  joystick = Robot::m_oi->getSecondaryJoystick();

  // Get the raw axis output from the 2nd joystick left trigger y axis
  raw_axis = joystick->GetRawAxis(k_F310_leftTrigger_Y_axis);

  // Control PAT Turner using the raw axis, as we are filtering in the 
  // subsystem
  Robot::m_subSysPATTurner->TurnWoF(raw_axis);

} // end CmdTurnWoFCW::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdTurnWoFCW::IsFinished() {

  // Always return false, so we can always turn the WoF
  return false;

} // end CmdTurnWoFCW::IsFinished()

// Called once after isFinished returns true
void CmdTurnWoFCW::End() {

  // With IsFinished() always returning false, this should never
  //   run. But just in case, this stops Capt. Hook.
  Robot::m_subSysPATTurner->TurnWoF(k_MotorStopSpeed);

} // end CmdTurnWoFCW::End()

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdTurnWoFCW::Interrupted() {

  // This should only run when we switch between turning the WoF clockwise and
  // then turning the WoF counterclockwise
  Robot::m_subSysPATTurner->TurnWoF(k_MotorStopSpeed);

} // end CmdTurnWoFCW::Interrupted()
