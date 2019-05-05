/** ===========================================================================
 * @file   SubSysCaptHook.cpp
 * @brief  This file defines the SubSysCaptHook class.
 *
 * The SubSysCaptHook class allows the robot to move (grab/release) hatch
 * panels.
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

// Include the header file for our SubSysCaptHook class
#include "subsystems/SubSysCaptHook.h"

// If we are not using the PID controller for Capt. Hook
#if !USE_PID_CAPT_HOOK

// Include the header file for the grab hatch panel command class
#include "commands/CmdGrabHatchPanel.h"

// Include the header file for the release hatch panel command class
#include "commands/CmdReleaseHatchPanel.h"

// Include out robot map header file
#include "RobotMap.h"

// Include the Logitech F310 header
#include "HIDs/LogitechF310.h"

/************************** Library Header Files ******************************/

// Include the motor safety header file
#include "frc/MotorSafety.h"

/************************ Member function definitions *************************/

// The SubSysCaptHook default constructor
SubSysCaptHook::SubSysCaptHook() : Subsystem("SubSysCaptHook") {

  // Create a new motor controller for the Capt. Hook motor and reset
  m_CaptHookController.reset(
    new frc::PWMVictorSPX(k_CaptHookMotorPWMPort));

#if ORION_DEBUG
  if(m_CaptHookController == nullptr) {
    wpi::outs() << "m_CaptHookController not initialized!\n";
    wpi::outs().flush();
  }
#endif

  // Set the motor safety timeout for Capt. Hook
  m_CaptHookController->SetExpiration(k_CaptHookSafetyTimeout);

} // end SubSysCaptHook::SubSysCaptHook()

// The SubSysCaptHook default destructor
SubSysCaptHook::~SubSysCaptHook() {

  // Delete the Capt. Hook controller
  std::default_delete<frc::PWMVictorSPX> m_CaptHookController;

} // end SubSysCaptHook::~SubSysCaptHook()

// The initial default command
void SubSysCaptHook::InitDefaultCommand() {

  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());

} // end SubSysCaptHook::InitDefaultCommand()

// The periodic method for the SubSysCaptHook subsystem
void SubSysCaptHook::Periodic() {

  // Put code here to be run every loop

} // end SubSysCaptHook::Periodic()

// Put methods for controlling this subsystem
// here. Call these from Commands.

// The method for having Capt. Hook move a hatch panel,
//   either grab or release
void SubSysCaptHook::MoveHatchPanel(double speed) {

  // Set the Capt. Hook motor to the passed in speed
  m_CaptHookController->Set(speed);

} // end SubSysCaptHook::MoveHatchPanel(double)

// Method to get Capt. Hook's null zone.
double SubSysCaptHook::GetCaptHookNullZone() {

  // Return Capt. Hook's null zone
  return k_CaptHookAbsNullZone;

} // end SubSysCaptHook::GetCaptHookNullZone()

// Method to get Capt. Hook's speed limit.
double SubSysCaptHook::GetCaptHookLimit() {

  // Return Capt. Hook's speed limit
  return k_CaptHookAbsValMaxSpeed;

} // end SubSysCaptHook::GetCaptHookLimit()

// Method to get Capt. Hook's exponent for the curve.
double SubSysCaptHook::GetCaptHookExponent() {

  // Return Capt. Hook's exponent
  return k_CaptHookExponent;

} // end SubSysCaptHook::GetCaptHookExponent()

#endif // #if !USE_PID_CAPT_HOOK
