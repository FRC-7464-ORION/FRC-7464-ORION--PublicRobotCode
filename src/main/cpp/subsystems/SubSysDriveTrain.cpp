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
#include "commands/cmdDriveArcadeStyle.h"

// Include the header file for the drive tank style command class
#include "commands/cmdDriveTankStyle.h"

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

  // Use arcade drive using the passed in values, not squaring inputs
  //   (We've done our own desensitizing), and limit our speed to
  //   maximum speed allowed
  m_differentialDrive->ArcadeDrive(y, x, k_DoNOTUseBuiltInSquaring);

} // end SubSysDriveTrain::DriveArcadeStyle()

// The method for driving tank style
void SubSysDriveTrain::DriveTankStyle(double yL, double yR) {

  // Use tank drive using the passed in values, not squaring inputs
  //   (We've done our own desensitizing), and limit our speed to
  //   maximum speed allowed
  m_differentialDrive->TankDrive(yL, yR, k_DoNOTUseBuiltInSquaring);

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
  return k_DriveTrainAbsValMaxSpeed;

} // end SubSysDriveTrain::GetDriveTrainLimit

// Method to get the drive train's exponent for the curve.
double SubSysDriveTrain::GetDriveTrainExponent() {

  // Return the drive train exponent
  return k_DriveTrainExponent;

} // end SubSysDriveTrain::GetDriveTrainExponent()
