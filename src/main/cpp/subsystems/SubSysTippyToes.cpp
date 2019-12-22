/** ===========================================================================
 * @file   SubSysTippyToes.cpp
 * @brief  This file defines the SubSysTippyToes class.
 *
 * The SubSysTippyToes class allows the robot to climb platforms.
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

// Include the header file for our SubSysTippyToes class
#include "subsystems/SubSysTippyToes.h"

// If we are using Tippy Toes...
#if USE_TIPPY_TOES

// Include the header file for the climb forward command class
#include "commands/CmdClimbForward.h"

// Include the header file for the climb backward command class
#include "commands/CmdClimbBackward.h"

// Include out robot map header file
#include "RobotMap.h"

// Include the Logitech F310 header
#include "HIDs/LogitechF310.h"

/************************ Member function definitions *************************/

// The SubSysTippyToes default constructor
SubSysTippyToes::SubSysTippyToes() : Subsystem("SubSysTippyToes") {

  // Create a new motor controller for the Tippy Toes motor and reset
  m_TippyToesController.reset(
    new frc::PWMVictorSPX(k_TippyToesMotorsPWMPort));

#if ORION_DEBUG
  if(m_TippyToesController == nullptr) {
    wpi::outs() << "m_TippyToesController not initialized!\n";
    wpi::outs().flush();
  }
#endif

  // Set the motor safety timeout for Tippy Toes
  m_TippyToesController->SetExpiration(k_TippyToesSafetyTimeout);

} // end SubSysTippyToes::SubSysTippyToes()

// The SubSysTippyToes default destructor
SubSysTippyToes::~SubSysTippyToes() {

  // Delete the Tippy Toes controller
  std::default_delete<frc::PWMVictorSPX> m_TippyToesController;

} // end SubSysTippyToes::~SubSysTippyToes()

// The initial default command
void SubSysTippyToes::InitDefaultCommand() {

  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());

} // end SubSysTippyToes::InitDefaultCommand()

// The periodic method for the SubSysTippyToes subsystem
void SubSysTippyToes::Periodic() {

  // Put code here to be run every loop

} // end SubSysTippyToes::Periodic()

// Put methods for controlling this subsystem
// here. Call these from Commands.

// The method for having TippyToes climb
void SubSysTippyToes::Climb(double speed) {

  // Set the Tippy Toes motor to the passed in speed
  m_TippyToesController->Set(speed);

} // end SubSysTippyToes::Climb(double)

// Method to get Tippy Toes' null zone.
double SubSysTippyToes::GetTippyToesNullZone() {

  // Return the drive train null zone
  return k_TippyToesAbsNullZone;

} // end SubSysTippyToes::GetDriveTrainNullZone()

// Method to get the drive train's speed limit.
double SubSysTippyToes::GetTippyToesLimit() {

  // Return the drive train speed limit
  return k_TippyToesAbsValMaxSpeed;

} // end SubSysTippyToes::GetDriveTrainLimit

// Method to get the drive train's exponent for the curve.
double SubSysTippyToes::GetTippyToesExponent() {

  // Return the drive train exponent
  return k_TippyToesExponent;

} // end SubSysTippyToes::GetDriveTrainExponent()

#endif // #if USE_TIPPY_TOES
