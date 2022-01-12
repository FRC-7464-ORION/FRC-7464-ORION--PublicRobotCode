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

// The constructor for the CmdTurnWoFCW class
CmdTurnWoFCW::CmdTurnWoFCW(SubSysPATTurner* subsystem, 
                           frc::Joystick* joystick) 
  : m_subSysPATTurner(subsystem), m_joystick(joystick) {

  // Set the command's name
  SetName("CmdTurnWoFCW");

  // Require the use of the PAT Turner subsystem
  AddRequirements({subsystem});

} // end CmdTurnWoFCW::CmdTurnWoFCW(SubSysPATTurner* subsystem)...

// The destructor for the CmdTurnWoFCW class
CmdTurnWoFCW::~CmdTurnWoFCW() {

} // end CmdTurnWoFCW::~CmdTurnWoFCW()

// Called just before this Command runs the first time
void CmdTurnWoFCW::Initialize() {

} // end CmdTurnWoFCW::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdTurnWoFCW::Execute() {

  // Declare raw output axis
  double raw_axis;

  // Get the raw axis output from the 2nd joystick left trigger y axis
  raw_axis = m_joystick->GetRawAxis(k_F310_leftTrigger_Y_axis);

  // Send the controller the raw speed as we are filtering in
  // the subsystem
  m_subSysPATTurner->TurnWoF(raw_axis);

} // end CmdTurnWoFCW::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdTurnWoFCW::IsFinished() {

  // Always return false, so we can always turn the WoF
  return false;

} // end CmdTurnWoFCW::IsFinished()

// Called once after isFinished returns true, OR command 
//   is interrupted or canceled
void CmdTurnWoFCW::End(bool interrupted) {

  // With IsFinished() always returning false, this should never
  //   run. But just in case, this stops PAT Turner
  m_subSysPATTurner->TurnWoF(k_MotorStopSpeed);

} // end CmdTurnWoFCW::End()
