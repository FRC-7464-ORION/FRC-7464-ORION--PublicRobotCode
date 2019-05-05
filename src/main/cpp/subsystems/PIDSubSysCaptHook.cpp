/** ===========================================================================
 * @file   PIDSubSysCaptHook.cpp
 * @brief  This file defines the PIDSubSysCaptHook class.
 *
 * The PIDSubSysCaptHook class allows the robot to grab and release hatch
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

// Include the header file for the PIDSubSysCaptHook class
#include "subsystems/PIDSubSysCaptHook.h"

// If we are using Capt. Hook with a PID controller...
#if USE_PID_CAPT_HOOK

// header of command grab hatch
#include "commands/PIDCmdGrabHatchPanel.h"

// header of command for release hatch
#include  "commands/PIDCmdReleaseHatchPanel.h"

/************************** Library Header Files ******************************/

// Include the header file for LiveWindow
#include <frc/livewindow/LiveWindow.h>

// Include the header file for SmartDashboard
#include <frc/smartdashboard/SmartDashboard.h>

/************************ Member function definitions *************************/

// The default constructor for the class PIDSubSysCaptHook
PIDSubSysCaptHook::PIDSubSysCaptHook()
    : PIDSubsystem(k_CaptHookPIDName,
                   k_CaptHookProportionalTerm,
                   k_CaptHookIntegralTerm,
                   k_CaptHookDerivativeTerm) {

  // Create a new motor controller for Capt Hook and reset
  m_CaptHookController.reset(
    new frc::PWMVictorSPX(k_CaptHookMotorPWMPort));

#if ORION_DEBUG
  // If the motor controller for Capt Hook has not been initialized...
  if(m_CaptHookController == nullptr) {

    // Inform them
    wpi::outs() << "m_CaptHookController not initialized!\n";
    wpi::outs().flush();
  
  } // if(m_CaptHookController == nullptr)
#endif

  // Create a new analog potentiometer for Capt Hook and reset
  m_CaptHookPot.reset(
    new frc::AnalogPotentiometer(k_CaptHook_Pot_roboRIO_AnalogInChannel,
                                 k_CaptHookPotScaleFactor,
                                 k_CaptHookPotOffset));

#if ORION_DEBUG
  // If the potentiometer for Capt Hook has not been initialized...
  if(m_CaptHookPot == nullptr) {

    // Inform them
    wpi::outs() << "m_CaptHookPot not initialized!\n";
    wpi::outs().flush();
  
  } // if(m_CaptHookPot == nullptr)
#endif

  // Set the expected min/max input range (from the potentiometer output)
  SetInputRange(k_CaptHookMinimumInput, k_CaptHookMaximumInput);

  // Set the absolute tolerance acceptable for the set point
  SetAbsoluteTolerance(k_CaptHookAbsoluteTolerance);

  // Set the minimum/maximum output range for the motor
  SetOutputRange(k_CaptHookMinimumOutput, k_CaptHookMaximumOutput);

  // Indicate we do not know what state Capt. Hook is at
  m_CaptHookState = k_CaptHookUnknownString;

} // end PIDSubSysCaptHook::PIDSubSysCaptHook()

// The Capt. Hook destructor
PIDSubSysCaptHook::~PIDSubSysCaptHook() {

} // end PIDSubSysCaptHook::~PIDSubSysCaptHook::()

// Return your input value for the PID loop, 
// e.g. a sensor, like a potentiometer
double PIDSubSysCaptHook::ReturnPIDInput() {

  // The value output from the potentiometer
  double Pot_Value;

  // Get the value of the potentiometer
  // Remember, in the units used for fullRange and offset
  Pot_Value = m_CaptHookPot->Get();

#if CAPT_HOOK_DEBUG
    wpi::outs() << "Capt. Hook Pot Value = " << Pot_Value <<"\n";
    wpi::outs().flush();
#endif // #if CAPT_HOOK_DEBUG

  // Return the value of the potentiometer
  return Pot_Value;

} // end double PIDSubSysCaptHook::ReturnPIDInput()

// Use output to drive your system, like a motor
void PIDSubSysCaptHook::UsePIDOutput(double output) {
  
#if CAPT_HOOK_DEBUG
    wpi::outs() << "Capt. Hook motor output = " << output <<"\n";
    wpi::outs().flush();
#endif // #if CAPT_HOOK_DEBUG

  // Set the speed of the Capt. Hook motor controller
  m_CaptHookController->Set(output);

} // end PIDSubSysCaptHook::UsePIDOutput(double)

  // Set the default command for PIDSubSysCaptHook here.
void PIDSubSysCaptHook::InitDefaultCommand() {

  // SetDefaultCommand(new MySpecialCommand());

} // end PIDSubSysCaptHook::InitDefaultCommand()

// The periodic method for the Capt. Hook subsystem
void PIDSubSysCaptHook::Periodic() {

  // // Put code here to be run every loop
 
} // end PIDSubSysCaptHook::Periodic()

// The method for grabbing a hatch panel 
void PIDSubSysCaptHook::GrabHatchPanel() {

#if CAPT_HOOK_DEBUG
    wpi::outs() << "Capt. Hook Grabbing Hatch Panel!\n";
    wpi::outs().flush();
#endif // #if CAPT_HOOK_DEBUG

  // Indicate we are grabbing a hatch panel
  m_CaptHookState = k_CaptHookGrabbingString;

  // Set the set point for grabbing a hatch panel
  SetSetpoint(k_CaptHookGrabHatchpanelSetpoint);
  // and enable the PID controller
  Enable();

} // end PIDSubSysCaptHook::GrabHatchPanel()

// The method for releasing a hatch panel 
void PIDSubSysCaptHook::ReleaseHatchPanel() {

#if CAPT_HOOK_DEBUG
    wpi::outs() << "Capt. Hook Releasing Hatch Panel!\n";
    wpi::outs().flush();
#endif // #if CAPT_HOOK_DEBUG

  // Indicate we are releasing a hatch panel
  m_CaptHookState = k_CaptHookReleasingString;

  // Set the set point for releasing a hatch panel
  SetSetpoint(k_CaptHookReleaseHatchpanelSetpoint);
  // and enable the PID controller
  Enable();

} // end PIDSubSysCaptHook::ReleaseHatchPanel()

// The method for stopping Capt. Hook 
void PIDSubSysCaptHook::StopCaptHook() {

#if CAPT_HOOK_DEBUG
    wpi::outs() << "Capt. Hook Stopped!\n";
    wpi::outs().flush();
#endif // #if CAPT_HOOK_DEBUG

  // Disable the PID controller
  Disable();

} // PIDSubSysCaptHook::StopCaptHook()

// Method to get Capt. Hook state
std::string PIDSubSysCaptHook::GetCaptHookState() {

  // Return Capt. Hook state
  return m_CaptHookState;

} // end PIDSubSysCaptHook::GetCaptHookState()

// Method to set Capt. Hook state
void PIDSubSysCaptHook::SetCaptHookState(std::string state) {

  // Set Capt. Hook state to the passed in state
  m_CaptHookState = state;

} // end PIDSubSysCaptHook::SetCaptHookState(std::string state)

#endif // #if USE_PID_CAPT_HOOK
