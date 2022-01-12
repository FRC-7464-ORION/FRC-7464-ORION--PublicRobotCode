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

/************************** Library Header Files ******************************/

// Include the motor safety header file
#include <frc/MotorSafety.h>

/************************ Member function definitions *************************/

// The SubSysPssh default constructor
PIDSubSysPssh::PIDSubSysPssh() 
  : frc2::PIDSubsystem (
      frc2::PIDController(
        k_PsshProportionalTerm,
        k_PsshIntegralTerm,
        k_PsshDerivativeTerm)) {

  // Set the subsystem's name
  SetName("PIDSubSysPssh");

  // Set the absolute tolerance acceptable for the set point
  m_controller.SetTolerance(k_PsshAbsoluteTolerance);

  // Set the name
  SetName(k_PsshPIDName);

  // Indicate what state Pssh is at
  m_PsshState = k_PsshTravelString;

  // Set the motor safety timeout for Pssh
  m_PsshMotorController.SetExpiration(k_PsshSafetyTimeout);

} // end SubSysPssh::SubSysPSSH()

// The SubSysPssh default destructor
PIDSubSysPssh::~PIDSubSysPssh() {

} // end PIDSubSysPssh::~PIDSubSysPssh()

// Method to reset the PID controller
void PIDSubSysPssh::ResetPIDController() {

  // Reset the PID controller
  m_controller.Reset();

} // end PIDSubSysPssh::ResetPIDController()

// Method to disable the PID controller
void PIDSubSysPssh::DisablePIDController() {

  // Disable the PID controller
  Disable();

} // end PIDSubSysPssh::DisablePIDController()

// Method to enable PID controller
void PIDSubSysPssh::EnablePIDController() {

  // Enable the PID controller
  Enable();

} // PIDSubSysPssh::EnablePIDController()

// Return your input value for the PID loop, 
// e.g. a sensor, like a potentiometer
double PIDSubSysPssh::GetMeasurement() {

  // The value output from the potentiometer
  double Pot_Value;

  // Get the value of the potentiometer
  // Remember, in the units used for fullRange and offset
  Pot_Value = m_PsshPot.Get();

#if PSSH_DEBUG
    wpi::outs() << "Pssh Pot Value = " << Pot_Value <<"\n";
    wpi::outs().flush();
#endif // #if PSSH_DEBUG_DEBUG

  // Return the value of the potentiometer
  return Pot_Value;

} // end double PIDSubSysPssh::GetMeasurement()

// Use output to drive your system, like a motor
void PIDSubSysPssh::UseOutput(double output, double setpoint) {
  
#if PSSH_DEBUG
    wpi::outs() << "Pssh motor output = " << output <<"\n";
    wpi::outs().flush();
#endif // #if PSSH_DEBUG

  // Set the speed of the Pssh motor controller, clamped to the
  //   minimum/maximum desired output of the motor
  m_PsshMotorController.Set(
    std::clamp(output,k_PsshMinimumOutput,k_PsshMaximumOutput));

} // end PIDSubSysPssh::UseOutput(double)

// The periodic method for the SubSysPssh subsystem
void PIDSubSysPssh::Periodic() {

    // Put code here to be run every loop

    // If the PID controller subsystem is enabled...
    if(IsEnabled()) {

      // Call UseOutput by calculating our next output by getting 
      //   our measurement and setpoint, and let the PID controller
      //   do its magic
      UseOutput(
        m_controller.Calculate(
          GetMeasurement(), m_controller.GetSetpoint()), 
          m_controller.GetSetpoint());

    } // end if(IsEnabled())

} //end SubSysPssh::Periodic()

// Method to put Pssh in the travel position
void PIDSubSysPssh::Travel() {

  // If the PID controller is not enabled...
  if(!IsEnabled())
    // Enable it
    Enable();

} // end PIDSubSysPssh::Travel()

// Method to put Pssh in the load position
void PIDSubSysPssh::Load() {

  // If the PID controller is not enabled...
  if(!IsEnabled())
    // Enable it
    Enable();

} // end PIDSubSysPssh::Load()

// Method to put Pssh in the dump position
void PIDSubSysPssh::Dump() {

  // If the PID controller subsystem is not enabled...
  if(!IsEnabled())
    // Enable it
    Enable();

} // end PIDSubSysPssh::Dump()

// The method for stopping Pssh
void PIDSubSysPssh::Stop() {

#if PSSH_DEBUG
    frc::DriverStation::ReportWarning("Pssh Stopped!");
#endif // #if PSSH_DEBUG

  // Disable the PID controller
  Disable();

  // Reset the PID controller
  m_controller.Reset();

} // PIDSubSysPssh::Stop()

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
