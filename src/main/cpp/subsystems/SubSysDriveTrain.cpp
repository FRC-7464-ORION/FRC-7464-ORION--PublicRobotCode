/** ===========================================================================
 * @file   SubSysDriveTrain.cpp
 * @brief  This file defines the SubSysDriveTrain class.
 *
 * The SubSysDriveTrain class allows the robot to move.
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

// Include the header file for our SubSysDriveTrain class
#include "subsystems/SubSysDriveTrain.h"

// Include the header file for the drive arcade style command class
#include "commands/CmdDriveArcadeStyle.h"

// Include the header file for the drive tank style command class
#include "commands/CmdDriveTankStyle.h"

// Include out robot map header file
#include "RobotMap.h"

// Include the Logitech F310 header
#include "HIDs/LogitechF310.h"

/************************ Member function definitions *************************/

// The DriveTrain default constructor
SubSysDriveTrain::SubSysDriveTrain() : Subsystem("SubSysDriveTrain") {

  // Create a new motor controller for the left motors and reset
  m_leftDriveTrainController.reset(
    new frc::PWMVictorSPX(k_LeftDriveTrainMotorsPWMPort));

#if ORION_DEBUG
  if(m_leftDriveTrainController == nullptr) {
    wpi::outs() << "m_leftDriveTrainController not initialized!\n";
    wpi::outs().flush();
  }
#endif

  // Create a new motor controller for the right motors and reset
  m_rightDriveTrainController.reset(
    new frc::PWMVictorSPX(k_RightDriveTrainMotorsPWMPort));

#if ORION_DEBUG
  if(m_rightDriveTrainController == nullptr) {
    wpi::outs() << "m_rightDriveTrainController not initialized!\n";
    wpi::outs().flush();
  }
#endif

  // Create a new differential drive, and reset
  m_differentialDrive.reset(
    new frc::DifferentialDrive(*m_leftDriveTrainController,
                               *m_rightDriveTrainController));

#if ORION_DEBUG
  if(m_differentialDrive == nullptr) {
    wpi::outs() << "m_differentialDrive not initialized!\n";
    wpi::outs().flush();
  }
#endif

  // Set the motor safety timeout for the drivetrain
  m_differentialDrive->SetExpiration(k_DriveTrainSafetyTimeout);

  // Set turbo mode initially to disabled
  m_TurboModeEnabled = false;

  // Set the drive train turbo mode string to off
  m_DriveTrainTurboString = k_DriveTrainTurboModeOffString;

  // Set smoothing mode initially to enabled
  m_DriveTrain_Smoothing_Enabled = true;

  // Set smoothing mode status string to on
  m_DriveTrain_Smoothing_Status_String = k_DriveTrainSmoothingModeOnString;

  // Set speed 1 past filtered output to 0
  m_speed1_past_filtered_output = 0.0;

  // Set speed 2 past filtered output to 0
  m_speed2_past_filtered_output = 0.0;

} // end SubSysDriveTrain::SubSysDriveTrain()

// The SubSysDriveTrain destructor
SubSysDriveTrain::~SubSysDriveTrain() {

  // Delete the differential drive
  std::default_delete<frc::DifferentialDrive> m_differentialDrive;

  // Delete the right drive train controller
  std::default_delete<frc::PWMVictorSPX> m_rightDriveTrainController;

  // Delete the left drive train controller
  std::default_delete<frc::PWMVictorSPX> m_leftDriveTrainController;

} // end SubSysDriveTrain::~SubSysDriveTrain()

// The initial default command
void SubSysDriveTrain::InitDefaultCommand() {

  // Set the default command for a subsystem here.

  // Set the arcade style drive command as the default command
  SetDefaultCommand(new CmdDriveArcadeStyle());

} // end SubSysDriveTrain::InitDefaultCommand()

// The periodic method for the drive train subsystem
void SubSysDriveTrain::Periodic() {

  // Put code here to be run every loop

} // end SubSysDriveTrain::Periodic()

// Put methods for controlling this subsystem
// here. Call these from Commands.

// The method for driving arcade style
void SubSysDriveTrain::DriveArcadeStyle(double y, double x) {

  // The multiplier for putting turbo mode on
  double const TurboMultiplier =
    k_DriveTrainAbsValMaxSpeedTurboOn/k_DriveTrainAbsValMaxSpeedNoTurbo;

  // The y axis value after being nulled, desensitized, and speed limited
  double y_Nulled_Desensed_Limited;
  // The x axis value after being nulled, desensitized, and speed limited
  double x_Nulled_Desensed_Limited;
  // The y axis value after being nulled, desensitized, speed limited,
  //   and turboed (on or off)
  double y_Turboed;
  // The x axis value after being nulled, desensitized, speed limited,
  //   and turboed (on or off)
  double x_Turboed;
  // The y axis value after being nulled, desensitized, speed limited,
  //   turboed (on or off), and smoothed (on or off)
  double y_Smoothed;
  // The x axis value after being nulled, desensitized, speed limited,
  //   turboed (on or off), and smoothed (on or off)
  double x_Smoothed;

  // We were passed in a nulled/desensed/limited value for y,
  //   so we'll use that
  y_Nulled_Desensed_Limited = y;
  // We were passed in a nulled/desensed/limited value for x,
  //   so we'll use that
  x_Nulled_Desensed_Limited = x;

  // If turbo mode is not enabled...
  if(!m_TurboModeEnabled) {

    // We'll just used the passed in values...
    y_Turboed = y_Nulled_Desensed_Limited;
    x_Turboed = x_Nulled_Desensed_Limited;

  } // end if(!m_TurboModeEnabled)

  else { // Turbo mode is enabled...

    // We'll use the passed in values, multiplied by our
    //   turbo factor
    y_Turboed = y_Nulled_Desensed_Limited*TurboMultiplier;
    x_Turboed = x_Nulled_Desensed_Limited*TurboMultiplier;
    
  } // end else (if(!m_TurboModeEnabled))

  // If smoothing mode is not enabled...
  if(!m_DriveTrain_Smoothing_Enabled) {

    // We'll just use the "turboed" y value
    y_Smoothed = y_Turboed;
    // We'll just use the "turboed" x value
    x_Smoothed = x_Turboed;
  }

  // Smoothing is enabled...
  else {

    // The smoothed y value is calculated using the formula for
    //   an infinite impulse repsponse digital low pass filter,
    //   which is:
    //   y_curr_filt = d*y_curr_unfilt + (1-d)*y_past_filt
    y_Smoothed =
      (k_DriveTrain_IIR_DLPF_d * y_Turboed) +
      ((1.0 - k_DriveTrain_IIR_DLPF_d) * m_speed1_past_filtered_output);

    // Save the current filtered y output for next time
    m_speed1_past_filtered_output = y_Smoothed;

    // The smoothed x value is calculated using the formula for
    //   an infinite impulse repsponse digital low pass filter,
    //   which is:
    //   x_curr_filt = d*x_curr_unfilt + (1-d)*x_past_filt
    x_Smoothed =
      (k_DriveTrain_IIR_DLPF_d * x_Turboed) +
      ((1.0 - k_DriveTrain_IIR_DLPF_d) * m_speed2_past_filtered_output);

    // Save the current filtered x output for next time
    m_speed2_past_filtered_output = x_Smoothed;

  } // end else (if(!m_DriveTrain_Smoothing_Enabled))

  // Use arcade drive using the passed in values after:
  //   * Nulling, desensitizing, and speed limiting
  //   * Being Turboed (on or off)
  //   * Being Smoothed (on or off)
  //   * not squaring inputs
  m_differentialDrive->ArcadeDrive(
    y_Smoothed, x_Smoothed, k_DoNOTUseBuiltInSquaring);

} // end SubSysDriveTrain::DriveArcadeStyle()

// The method for driving tank style
void SubSysDriveTrain::DriveTankStyle(double yL, double yR) {

  // The multiplier for putting turbo mode on
  double const TurboMultiplier =
    k_DriveTrainAbsValMaxSpeedTurboOn/k_DriveTrainAbsValMaxSpeedNoTurbo;

  // The yL axis value after being nulled, desensitized, and speed limited
  double yL_Nulled_Desensed_Limited;
  // The yR axis value after being nulled, desensitized, and speed limited
  double yR_Nulled_Desensed_Limited;
  // The yL axis value after being nulled, desensitized, speed limited,
  //   and turboed (on or off)
  double yL_Turboed;
  // The yR axis value after being nulled, desensitized, speed limited,
  //   and turboed (on or off)
  double yR_Turboed;
  // The yL axis value after being nulled, desensitized, speed limited,
  //   turboed (on or off), and smoothed (on or off)
  double yL_Smoothed;
  // The yR axis value after being nulled, desensitized, speed limited,
  //   turboed (on or off), and smoothed (on or off)
  double yR_Smoothed;

  // We were passed in a nulled/desensed/limited value for yL,
  //   so we'll use that
  yL_Nulled_Desensed_Limited = yL;
  // We were passed in a nulled/desensed/limited value for yR,
  //   so we'll use that
  yR_Nulled_Desensed_Limited = yR;

  // If turbo mode is not enabled...
  if(!m_TurboModeEnabled) {

    // We'll just used the passed in values...
    yL_Turboed = yL_Nulled_Desensed_Limited;
    yR_Turboed = yR_Nulled_Desensed_Limited;

  } // end if(!m_TurboModeEnabled)

  else { // Turbo mode is enabled...

    // We'll use the passed in values, multiplied by our
    //   turbo factor
    yL_Turboed = yL_Nulled_Desensed_Limited*TurboMultiplier;
    yR_Turboed = yR_Nulled_Desensed_Limited*TurboMultiplier;

  } // end else (if(!m_TurboModeEnabled))

  // If smoothing mode is not enabled...
  if(!m_DriveTrain_Smoothing_Enabled) {

    // We'll just use the "turboed" yL value
    yL_Smoothed = yL_Turboed;
    // We'll just use the "turboed" yR value
    yR_Smoothed = yR_Turboed;
  }

  // Smoothing is enabled...
  else {

    // The smoothed yL value is calculated using the formula for
    //   an infinite impulse repsponse digital low pass filter,
    //   which is:
    //   yL_curr_filt = d*yL_curr_unfilt + (1-d)*yL_past_filt
    yL_Smoothed =
      (k_DriveTrain_IIR_DLPF_d * yL_Turboed) +
      ((1.0 - k_DriveTrain_IIR_DLPF_d) * m_speed1_past_filtered_output);

    // Save the current filtered y output for next time
    m_speed1_past_filtered_output = yL_Smoothed;

    // The smoothed yR value is calculated using the formula for
    //   an infinite impulse repsponse digital low pass filter,
    //   which is:
    //   yR_curr_filt = d*yR_curr_unfilt + (1-d)*yR_past_filt
    yR_Smoothed =
      (k_DriveTrain_IIR_DLPF_d * yR_Turboed) +
      ((1.0 - k_DriveTrain_IIR_DLPF_d) * m_speed2_past_filtered_output);

    // Save the current filtered yR output for next time
    m_speed2_past_filtered_output = yR_Smoothed;

  } // end else (if(!m_DriveTrain_Smoothing_Enabled))

  // Use tank drive using the passed in values after:
  //   * Nulling, desensitizing, and speed limiting
  //   * Being Turboed (on or off)
  //   * Being Smoothed (on or off)
  //   * not squaring inputs
  m_differentialDrive->TankDrive(
    yL_Smoothed, yR_Smoothed, k_DoNOTUseBuiltInSquaring);

} // end SubSysDriveTrain::DriveTankStyle()

// Method to set the drive train mode string to arcade
void SubSysDriveTrain::SetDriveTrainModeStringToArcade() {

  // Set the drive train mode string to arcade
  m_DriveTrainModeString = k_DriveTrainArcadeModeString;

} // end SubSysDriveTrain::SetDriveTrainModeStringToArcade()

// Method to set the drive train mode string to tank
void SubSysDriveTrain::SetDriveTrainModeStringToTank() {

  // Set the drive train mode string to tank
  m_DriveTrainModeString = k_DriveTrainTankModeString;

} // end SubSysDriveTrain::SetDriveTrainModeStringToTank()

// Method to get the current drive train mode string
std::string SubSysDriveTrain::GetDriveTrainModeString() {

  return m_DriveTrainModeString;

} // end std::string SubSysDriveTrain::GetDriveTrainModeString()

// Method to get the drive train's null zone.
double SubSysDriveTrain::GetDriveTrainNullZone() {

  // Return the drive train null zone
  return k_DriveTrainAbsNullZone;

} // end SubSysDriveTrain::GetDriveTrainNullZone()

// Method to get the drive train's speed limit.
double SubSysDriveTrain::GetDriveTrainLimit() {

  // Return the drive train speed limit
  return k_DriveTrainAbsValMaxSpeedNoTurbo;

} // end SubSysDriveTrain::GetDriveTrainLimit

// Method to get the drive train's exponent for the curve.
double SubSysDriveTrain::GetDriveTrainExponent() {

  // Return the drive train exponent
  return k_DriveTrainExponent;

} // end SubSysDriveTrain::GetDriveTrainExponent()

// Method to enable (turn on) turbo mode
void SubSysDriveTrain::SetTurboModeOn() {

  // Turn on the turbo mode
  m_TurboModeEnabled = true;

  // Set the drive train turbo mode string to on
  m_DriveTrainTurboString = k_DriveTrainTurboModeOnString;

} // end SubSysDriveTrain::SetTurboModeOn()

// Method to disable (turn off) turbo mode
void SubSysDriveTrain::SetTurboModeOff() {

  // Turn off the turbo mode
  m_TurboModeEnabled = false;

  // Set the drive train turbo mode string to off
  m_DriveTrainTurboString = k_DriveTrainTurboModeOffString;

} // end SubSysDriveTrain::SetTurboModeOff()

// Method to get turbo mode status
bool SubSysDriveTrain::GetTurboModeStatus() {

  // Return the status of the turbo mode
  return m_TurboModeEnabled;

} // end SubSysDriveTrain::GetTurboModeStatus()

// Method to get turbo mode status string
std::string SubSysDriveTrain::GetTurboModeStatusString() {

  // Return the drive train turbo mode string
  return m_DriveTrainTurboString;

} // end SubSysDriveTrain::GetTurboModeStatusString()

// Method to enable (turn on) smoothing mode
void SubSysDriveTrain::SetSmoothingModeOn() {

  // Turn on smoothing mode
  m_DriveTrain_Smoothing_Enabled = true;

  // Set the drive train smoothing mode string to on
  m_DriveTrain_Smoothing_Status_String =
    k_DriveTrainSmoothingModeOnString;

} // end SubSysDriveTrain::SetSmoothingModeOn()

// Method to disable (turn off) smoothing mode
void SubSysDriveTrain::SetSmoothingModeOff() {

  // Turn off smoothing mode
  m_DriveTrain_Smoothing_Enabled = false;

  // Set the drive train smoothing mode string to off
  m_DriveTrain_Smoothing_Status_String =
    k_DriveTrainSmoothingModeOffString;

} // end SubSysDriveTrain::SetSmoothingModeOff()

// Method to get smoothing mode status
bool SubSysDriveTrain::GetSmoothingStatus() {

  // Return the status of the smoothing mode
  return m_DriveTrain_Smoothing_Enabled;

} // end SubSysDriveTrain::GetSmoothingStatus()

// Method to get smoothing mode status string
std::string SubSysDriveTrain::GetSmoothingStatusString() {

  // Return the drive train smoothing mode string
  return m_DriveTrain_Smoothing_Status_String;

} // end SubSysDriveTrain::GetSmoothingStatusString()
