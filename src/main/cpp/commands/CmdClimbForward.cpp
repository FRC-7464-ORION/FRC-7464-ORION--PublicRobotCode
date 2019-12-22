/** ===========================================================================
 * @file   CmdClimbForward.cpp
 * @brief  This file defines the CmdClimbForward class.
 *
 * The CmdClimbForward class is used to allow the robot to climb forwards.
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

// Include the header file for the CmdClimbForward class
#include "commands/CmdClimbForward.h"

// If we are using Tippy Toes...
#if USE_TIPPY_TOES

// Include the header file that defines the F310 axes/buttons
#include "HIDs/LogitechF310.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// Include the WPI library header file
#include "frc/WPILib.h"

/************************ Member function definitions *************************/

// The default constructor for the CmdClimbForward class
CmdClimbForward::CmdClimbForward() {

  // Use Requires() here to declare subsystem dependencies

  // Require the use of the Tippy Toes subsystem
  Requires(Robot::m_subSysTippyToes.get());

} // end CmdClimbForward::CmdClimbForward()

// The destructor for the CmdClimbForward class
CmdClimbForward::~CmdClimbForward() {

} // end CmdClimbForward::~CmdClimbForward()

// Called just before this Command runs the first time
void CmdClimbForward::Initialize() {

} // end CmdClimbForward::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdClimbForward::Execute() {

  // Declare raw fake trigger output
  double raw_fake_trigger_axis;

  // Declare corrected axis for motor speed
  double corrected_fake_trigger_axis_motor_speed;

  // Get the raw axis output from the max speed
  raw_fake_trigger_axis = k_TippyToesAbsValMaxSpeed;

  // Now null, desensitize, and limit the axis for better speed control
  corrected_fake_trigger_axis_motor_speed =
    NullDesensLimit(raw_fake_trigger_axis,
                    Robot::m_subSysTippyToes->GetTippyToesNullZone(),
                    Robot::m_subSysTippyToes->GetTippyToesLimit(),
                    Robot::m_subSysTippyToes->GetTippyToesExponent());

  // Control Tippy Toes using the corrected axis
  Robot::m_subSysTippyToes->Climb(corrected_fake_trigger_axis_motor_speed);

} // end CmdClimbForward::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdClimbForward::IsFinished() {

  // Maybe need a timeout here?

} // end CmdClimbForward::IsFinished()

// Called once after isFinished returns true
void CmdClimbForward::End() {

  // With IsFinished() always returning false, this should never
  //   run. But just in case, this stops Tippy Toes.
  Robot::m_subSysTippyToes->Climb(k_MotorStopSpeed);

} // end CmdClimbForward::End()

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdClimbForward::Interrupted() {

  // This should only run when we switch between climbing forward and
  //   climbing backward, so we will stop Tippy Toes
  Robot::m_subSysTippyToes->Climb(k_MotorStopSpeed);

} // end CmdClimbForward::Interrupted()

#endif // #if USE_TIPPY_TOES
