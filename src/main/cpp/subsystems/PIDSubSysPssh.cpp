/** ===========================================================================
 * @file   PIDSubSyspSSH.cpp
 * @brief  This file defines the PIDSubSysPssh class.
 *
 * The PIDSubSysPssh class is used to move the Pssh power cell transporter to
 * different positions: Travel, Load, and Dump.  
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

// Include the header file for our PIDSubSysPssh class
#include "subsystems/PIDSubSysPssh.h"

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

// Include out robot map header file
#include "RobotMap.h"

/************************** Library Header Files ******************************/

// Include the motor safety header file
#include <frc/MotorSafety.h>

/************************ Member function definitions *************************/

// The SubSysPssh default constructor
PIDSubSysPssh::PIDSubSysPssh() 
  : PIDSubsystem (k_PsshPIDName,
                  k_PsshProportionalTerm,
                  k_PsshIntegralTerm,
                  k_PsshDerivativeTerm,
                  k_PsshFeedforwardTerm,
                  k_PsshPID_Period) {

  // Create a new motor controller for the Pssh motor and reset
  m_PsshController.reset(new frc::PWMVictorSPX(k_PsshMotorPWMPort));

#if ORION_DEBUG
  if (m_PsshController == nullptr) {
    // Inform them
    frc::DriverStation::ReportError("m_PsshController NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_PsshController initialized!");
  }
#endif

  // Create a new analog potentiometer Pssh and reset
  m_PsshPot.reset(
    new frc::AnalogPotentiometer(k_Pssh_Pot_roboRIO_AnalogInChannel,
                                 k_PsshPotScaleFactor,
                                 k_PsshPotOffset));

#if ORION_DEBUG
  // If the potentiometer for Pssh has not been initialized...
  if(m_PsshPot == nullptr) {
    // Inform them
    frc::DriverStation::ReportError("m_PsshPot NOT initialized!");
  } // if(m_PsshPot == nullptr)
  else {
    frc::DriverStation::ReportWarning("m_PsshPot initialized!");
  }
#endif

  // Set the expected min/max input range (from the potentiometer output)
  SetInputRange(k_PsshMinimumInput, k_PsshMaximumInput);

  // Set the absolute tolerance acceptable for the set point
  SetAbsoluteTolerance(k_PsshAbsoluteTolerance);

  // Set the minimum/maximum output range for the motor
  SetOutputRange(k_PsshMinimumOutput, k_PsshMaximumOutput);

  // Indicate what state Pssh is at
  m_PsshState = k_PsshTravelString;

  // Set the motor safety timeout for Pssh
  m_PsshController->SetExpiration(k_PsshSafetyTimeout);

} // end SubSysPssh::SubSysPSSH()

// The SubSysPssh default destructor
PIDSubSysPssh::~PIDSubSysPssh() {

    // Delete the Pssh controller
    std::default_delete<frc::PWMVictorSPX> m_PsshController;

} // end PIDSubSysPssh::~PIDSubSysPssh()

// Return your input value for the PID loop, 
// e.g. a sensor, like a potentiometer
double PIDSubSysPssh::ReturnPIDInput() {

  // The value output from the potentiometer
  double Pot_Value;

  // Get the value of the potentiometer
  // Remember, in the units used for fullRange and offset
  Pot_Value = m_PsshPot->Get();

#if PSSH_DEBUG
    wpi::outs() << "Pssh Pot Value = " << Pot_Value <<"\n";
    wpi::outs().flush();
#endif // #if PSSH_DEBUG_DEBUG

  // Return the value of the potentiometer
  return Pot_Value;

} // end double PIDSubSysPssh::ReturnPIDInput()

// Use output to drive your system, like a motor
void PIDSubSysPssh::UsePIDOutput(double output) {
  
#if PSSH_DEBUG
    wpi::outs() << "Pssh motor output = " << output <<"\n";
    wpi::outs().flush();
#endif // #if PSSH_DEBUG

  // Set the speed of the Pssh motor controller
  m_PsshController->Set(output);

} // end PIDSubSysPssh::UsePIDOutput(double)

// The initial default command
void PIDSubSysPssh::InitDefaultCommand() {

    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());

} // end PIDSubSysPssh::InitDefaultCommand()

// The periodic method for the SubSysPssh subsystem
void PIDSubSysPssh::Periodic() {

    // Put code here to be run every loop

} //end SubSysPssh::Periodic()

// Method to put Pssh in the travel position
void PIDSubSysPssh::Travel() {

#if PSSH_DEBUG
    frc::DriverStation::ReportWarning("Pssh in travel mode!");
#endif // #if PSSH_DEBUG

  // Indicate we are in travel mode
  m_PsshState = k_PsshTravelString;

  // Set the set point for travel mode
  SetSetpoint(k_PsshTravelSetpoint);

  // and enable the PID controller
  Enable();

} // end PIDSubSysPssh::Travel()

// Method to put Pssh in the load position
void PIDSubSysPssh::Load() {

#if PSSH_DEBUG
    frc::DriverStation::ReportWarning("Pssh in load mode!");
#endif // #if PSSH_DEBUG

  // Indicate we are in load mode
  m_PsshState = k_PsshLoadString;

  // Set the set point for load mode
  SetSetpoint(k_PsshLoadSetpoint);
  
  // and enable the PID controller
  Enable();

} // end PIDSubSysPssh::Load()

// Method to put Pssh in the dump position
void PIDSubSysPssh::Dump() {

#if PSSH_DEBUG
    frc::DriverStation::ReportWarning("Pssh in dump mode!");
#endif // #if PSSH_DEBUG

  // Indicate we are in dump mode
  m_PsshState = k_PsshDumpString;

  // Set the set point for dump mode
  SetSetpoint(k_PsshDumpSetpoint);
  
  // and enable the PID controller
  Enable();

} // end PIDSubSysPssh::Dump()

// The method for stopping Pssh
void PIDSubSysPssh::Stop() {

#if PSSH_DEBUG
    frc::DriverStation::ReportWarning("Pssh Stopped!");
#endif // #if PSSH_DEBUG

  // Disable the PID controller
  Disable();

} // PIDSubSysCaptHook::StopCaptHook()

// Method to get Pssh state
std::string PIDSubSysPssh::GetPsshState() {

  // Return the state of Pssh
  return m_PsshState;

} // end std::string PIDSubSysPssh::GetPsshState()

// Method to set Pssh state
void PIDSubSysPssh::SetPsshState(std::string state) {

  // Set the Pssh state to the passed in state
  m_PsshState = state;

} // end PIDSubSysPssh::SetPsshState(std::string state)

#endif // #if USE_PID_PSSH
