/** ===========================================================================
 * @file   CmdBallShooterShootLow.cpp
 * @brief  This file defines the CmdBallShooterShootLow class.
 *
 * The CmdBallShooterShootLow class is used to command the ball shooter
 * subsystem to shoot balls to the low target
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
 * Copyright (c) 2022 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// Include the header file for the CmdBallShooterShootLow class
#include "commands/BallShooter/CmdBallShooterShootLow.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// Include the I/O stream class, so we can write to the console
#include <iostream>

/************************ Member function definitions *************************/

// The constructor for the CmdBallShooterShootLow class
CmdBallShooterShootLow::CmdBallShooterShootLow(
  SubSysBallShooter* subsystem)
  : m_subSysBallShooter(subsystem) {

  // Set the command's name
  SetName("CmdBallShooterShootLow");

  // Require the use of the ball shooter subsystem
  AddRequirements({subsystem});

} // end CmdBallShooterShootLow::CmdBallShooterShootLow(...)

// The destructor for the CmdBallShooterShootLow class
CmdBallShooterShootLow::~CmdBallShooterShootLow() {

} // end CmdBallShooterShootLow::~CmdBallShooterShootLow()

// Called just before this Command runs the first time
void CmdBallShooterShootLow::Initialize() {

  // Indicate this command is not finished
  m_ThisCommandIsFinished = false;

  // Set the ball shooter state to "shooting low"
  m_subSysBallShooter->SetBallShooterStateToShootingLow();

} // end CmdBallShooterShootLow::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdBallShooterShootLow::Execute() {

  // Bring the shooter motor to speed
  while(!CmdBallShooterShootLow::ShooterMotorToSpeed())
    frc::Wait(0.05_s);

  // Now the shooter is up to speed, launch the ball
  CmdBallShooterShootLow::ActivateIndexerMotors();

  // Wait some time for the ball to launch, but not the 2nd
  // (if we have a 2nd ball)
  frc::Wait(5.0_s);

  // Now stop all motors
  CmdBallShooterShootLow::DeactivateShooterMotor();
  CmdBallShooterShootLow::DeactivateIndexerMotors();

  // Indicate this command is finished
  m_ThisCommandIsFinished = true;

}  // end CmdBallShooterShootLow::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdBallShooterShootLow::IsFinished() {

  // Indicate the status of this command
  return m_ThisCommandIsFinished;

} // end CmdBallShooterShootLow::IsFinished()

// Called once after isFinished returns true, OR command 
//   is interrupted or canceled
void CmdBallShooterShootLow::End(bool interrupted) {

  // Stop all motors
  CmdBallShooterShootLow::DeactivateShooterMotor();
  CmdBallShooterShootLow::DeactivateIndexerMotors();

  // Indicate this command is finished
  m_ThisCommandIsFinished = true;

} // end CmdBallShooterShootLow::End()

// Convenience function to activate the indexer motors
void CmdBallShooterShootLow::ActivateIndexerMotors() {

  // Turn on the left indexer motor
  m_subSysBallShooter->SetLeftIndexerMotorSpeed(
    k_BallShooterIndexerMotorSpeed);
  // Turn on the right indexer motor
  m_subSysBallShooter->SetRightIndexerMotorSpeed(
    k_BallShooterIndexerMotorSpeed*k_ReverseSpeedMultiplier);

} // end CmdBallShooterShootLow::ActivateIndexerMotors()

// Convenience function to 
void CmdBallShooterShootLow::DeactivateIndexerMotors() {

  // Turn off the left indexer motor
  m_subSysBallShooter->SetLeftIndexerMotorSpeed(k_MotorStopSpeed);
  // Turn off the right indexer motor
  m_subSysBallShooter->SetRightIndexerMotorSpeed(k_MotorStopSpeed);

} // end CmdBallShooterShootLow::DeactivateIndexerMotors()

// Convenience function to bring the shooter motor to speed
bool CmdBallShooterShootLow::ShooterMotorToSpeed() {

  // Turn on the shooter motor for low targets
  m_subSysBallShooter->SetShooterMotorSpeed(
    m_subSysBallShooter->CalcShooterMotorSpeedGivenTargetHeight(
      k_TopofBottomTargetHeight));

  // Wait ample time for motor to get up to speed
  frc::Wait(0.5_s);

  // Indicate we are at speed
  return true; 

} // end CmdBallShooterShootLow::ShooterMotorToSpeed()

// Convenience function to Deactivate Shooter Motor */
void CmdBallShooterShootLow::DeactivateShooterMotor() {

  // Turn off the shooter motor
  m_subSysBallShooter->SetShooterMotorSpeed(k_MotorStopSpeed);

} // end CmdBallShooterShootLow::DeactivateShooterMotor()
