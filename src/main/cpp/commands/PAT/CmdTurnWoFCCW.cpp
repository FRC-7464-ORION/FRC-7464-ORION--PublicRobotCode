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

// The constructor for this command
CmdTurnWoFCCW::CmdTurnWoFCCW(SubSysPATTurner* subsystem, 
                             frc::Joystick* joystick) 
  : m_subSysPATTurner(subsystem), m_joystick(joystick) {

  // Set the command's name
  SetName("CmdTurnWoFCCW");

  // Require the use of the PAT Turner subsystem
  AddRequirements({subsystem});

} // end CmdTurnWoFCCW::CmdTurnWoFCCW(SubSysPATTurner* subsystem)...

// The destructor for this command
CmdTurnWoFCCW::~CmdTurnWoFCCW() {

}

// Called just before this Command runs the first time
void CmdTurnWoFCCW::Initialize() {

} // end CmdTurnWoFCCW::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdTurnWoFCCW::Execute() {

  // Declare raw axis output
  double raw_axis;

  // Declare the inverted axis
  double inv_axis;

  // Get the raw axis output from the 2nd joystick right trigger y axis
  raw_axis = m_joystick->GetRawAxis(k_F310_rightTrigger_Y_axis);

  // Invert the axis
  // (we are going backward, so we need negative values, but both triggers
  //  output positive numbers)
  inv_axis = Correct_Y_Axis_Inversion(raw_axis);

  // Send the controller the raw inverted speed as we are filtering in
  // the subsystem
  m_subSysPATTurner->TurnWoF(inv_axis);

} // end CmdTurnWoFCCW::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdTurnWoFCCW::IsFinished() {

  // Always return false, so we can always turn the WoF
  return false;

} // end CmdTurnWoFCCW::IsFinished()

// Called once after isFinished returns true, OR command 
//   is interrupted or canceled
void CmdTurnWoFCCW::End(bool interrupted) {

  // With IsFinished() always returning false, this should never
  //   run. But just in case, this stops PAT Turner
  m_subSysPATTurner->TurnWoF(k_MotorStopSpeed);

} // end CmdTurnWoFCCW::End()
