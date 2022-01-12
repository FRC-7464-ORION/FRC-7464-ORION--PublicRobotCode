/** ===========================================================================
 * @file   SubSysPssh.cpp
 * @brief  This file defines the SubSysPssh class.
 *
 * The SubSysPssh class is used to manually control the power cell 
 * transporter.
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

// Include the header file for our SubSysPssh class
#include "subsystems/SubSysPssh.h"

// If we are NOT using the Pssh PID controller...
#if !USE_PID_PSSH

// Include out robot map header file
#include "RobotMap.h"

/************************** Library Header Files ******************************/

// Include the motor safety header file
#include <frc/MotorSafety.h>

/************************ Member function definitions *************************/

// The SubSysPssh default constructor
SubSysPssh::SubSysPssh() : Subsystem("SubSysPssh") {

  // Create a new motor controller for the Pssh  motor and reset
  m_PsshController.reset(
    new frc::PWMVictorSPX(k_PsshMotorPWMPort));

#if ORION_DEBUG
  if(m_PsshController == nullptr) {
    frc::DriverStation::ReportError("m_PsshController NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_PsshController initialized!");
  }
#endif

  // Set the motor safety timeout for Pssh
  m_PsshController->SetExpiration(k_PsshSafetyTimeout);

} // end SubSysPssh::SubSysPssh()

// The SubSysPssh default destructor
SubSysPssh::~SubSysPssh() {

  // Delete the Pssh controller
  std::default_delete<frc::PWMVictorSPX> m_PsshController;

} // end SubSysPssh::~SubSysPssh()

// The initial default command
void SubSysPssh::InitDefaultCommand() {

  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());

} // end SubSysPssh::InitDefaultCommand()

// The periodic method for the SubSysPssh subsystem
void SubSysPssh::Periodic() {

  // Put code here to be run every loop

  // Feed the motor controller safety system
  m_PsshController->Feed();

} // end SubSysPssh::Periodic()

// Put methods for controlling this subsystem
// here. Call these from Commands.
// The method for having the power cell transported controlled manually. 
void SubSysPssh::ControlPssh(double speed) {

  // Set the Pssh motor to the passed in speed
  m_PsshController->Set(speed);

} // end SubSysPssh::ControlPssh(double)

// Method to put Pssh in the travel position
void SubSysPssh::Travel() {

#if PSSH_DEBUG
    frc::DriverStation::ReportWarning("Pssh in travel mode!");
#endif // #if PSSH_DEBUG


} // end SubSysPssh::Travel()

// Method to put Pssh in the load position
void SubSysPssh::Load() {

#if PSSH_DEBUG
    frc::DriverStation::ReportWarning("Pssh in load mode!");
#endif // #if PSSH_DEBUG


} // end SubSysPssh::Load()

// Method to put Pssh in the dump position
void SubSysPssh::Dump() {

#if PSSH_DEBUG
    frc::DriverStation::ReportWarning("Pssh in dump mode!");
#endif // #if PSSH_DEBUG


} // end SubSysPssh::Dump()

// The method for stopping Pssh
void SubSysPssh::Stop() {

#if PSSH_DEBUG
    frc::DriverStation::ReportWarning("Pssh Stopped!");
#endif // #if PSSH_DEBUG

} // SubSysPssh::Stop()

// Method to get Pssh's null zone.
double SubSysPssh::GetPsshNullZone() {

  // Return Pssh's null zone
  return k_PsshAbsNullZone;

} // end SubSysPssh::GetPsshNullZone()

// Method to get Pssh's speed limit.
double SubSysPssh::GetPsshLimit() {

  // Return Pssh's speed limit
  return k_PsshAbsValMaxSpeedNoTurbo;

} // end SubSysPssh::GetPsshLimit()

// Method to get Pssh's exponent for the curve.
double SubSysPssh::GetPsshExponent() {

  // Return Pssh's exponent
  return k_PsshExponent;

} // end SubSysPssh::GetPsshExponent()

#endif // #if !USE_PID_PSSH
