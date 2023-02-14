/** ===========================================================================
 * @file   CmdBallShooterShootHigh.cpp
 * @brief  This file defines the CmdBallShooterShootHigh class.
 *
 * The CmdBallShooterShootHigh class is used to command the ball shooter
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

// Include the header file for the CmdBallShooterShootHigh class
#include "commands/BallShooter/CmdBallShooterShootHigh.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// Include the I/O stream class, so we can write to the console
#include <iostream>

/************************ Member function definitions *************************/

// The constructor for the CmdBallShooterShootHigh class
CmdBallShooterShootHigh::CmdBallShooterShootHigh(
  SubSysBallShooter* subsystem)
  : m_subSysBallShooter(subsystem) {

  // Set the command's name
  SetName("CmdBallShooterShootHigh");

  // Require the use of the ball shooter subsystem
  AddRequirements({subsystem});

} // end CmdBallShooterShootHigh::CmdBallShooterShootHigh(...)

// The destructor for the CmdBallShooterShootHigh class
CmdBallShooterShootHigh::~CmdBallShooterShootHigh() {

} // end CmdBallShooterShootHigh::~CmdBallShooterShootHigh()

// Called just before this Command runs the first time
void CmdBallShooterShootHigh::Initialize() {

  // Indicate this command is not finished
  m_ThisCommandIsFinished = false;

  // Set the ball shooter state to "shooting high"
  m_subSysBallShooter->SetBallShooterStateToShootingHigh();

} // end CmdBallShooterShootHigh::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdBallShooterShootHigh::Execute() {

  // Bring the shooter motor to speed
  while(!CmdBallShooterShootHigh::ShooterMotorToSpeed())
    frc::Wait(0.05_s);

  // Now the shooter is up to speed, launch the ball
  CmdBallShooterShootHigh::ActivateIndexerMotors();

  // Wait some time for the ball to launch, but not the 2nd
  // (if we have a 2nd ball)
  frc::Wait(5.0_s);

  // Now stop all motors
  CmdBallShooterShootHigh::DeactivateShooterMotor();
  CmdBallShooterShootHigh::DeactivateIndexerMotors();

  // Indicate this command is finished
  m_ThisCommandIsFinished = true;

}  // end CmdBallShooterShootHigh::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdBallShooterShootHigh::IsFinished() {

  // Indicate the status of this command
  return m_ThisCommandIsFinished;

} // end CmdBallShooterShootHigh::IsFinished()

// Called once after isFinished returns true, OR command 
//   is interrupted or canceled
void CmdBallShooterShootHigh::End(bool interrupted) {

  // Stop all motors
  CmdBallShooterShootHigh::DeactivateShooterMotor();
  CmdBallShooterShootHigh::DeactivateIndexerMotors();

  // Indicate this command is finished
  m_ThisCommandIsFinished = true;

} // end CmdBallShooterShootHigh::End()

// Convenience function to activate the indexer motors
void CmdBallShooterShootHigh::ActivateIndexerMotors() {

  // Turn on the left indexer motor
  m_subSysBallShooter->SetLeftIndexerMotorSpeed(
    k_BallShooterIndexerMotorSpeed);
  // Turn on the right indexer motor
  m_subSysBallShooter->SetRightIndexerMotorSpeed(
    k_BallShooterIndexerMotorSpeed*k_ReverseSpeedMultiplier);

} // end CmdBallShooterShootHigh::ActivateIndexerMotors()

// Convenience function to 
void CmdBallShooterShootHigh::DeactivateIndexerMotors() {

  // Turn off the left indexer motor
  m_subSysBallShooter->SetLeftIndexerMotorSpeed(k_MotorStopSpeed);
  // Turn off the right indexer motor
  m_subSysBallShooter->SetRightIndexerMotorSpeed(k_MotorStopSpeed);

} // end CmdBallShooterShootHigh::DeactivateIndexerMotors()

// Convenience function to bring the shooter motor to speed
bool CmdBallShooterShootHigh::ShooterMotorToSpeed() {

  // Turn on the shooter motor for high targets
//  m_subSysBallShooter->SetShooterMotorSpeed(
//    m_subSysBallShooter->CalcShooterMotorSpeedGivenTargetHeight(
//      k_TopofTopTargetHeightFromFloor));


  // Set ball shooter to 5600, since ultrasonic broke
  m_subSysBallShooter->SetShooterMotorSpeed(5600);

  // Wait ample time for motor to get up to speed
  frc::Wait(0.5_s);

  // Indicate we are at speed
  return true; 

} // end CmdBallShooterShootHigh::ShooterMotorToSpeed()

// Convenience function to Deactivate Shooter Motor */
void CmdBallShooterShootHigh::DeactivateShooterMotor() {

  // Turn off the shooter motor
  m_subSysBallShooter->SetShooterMotorSpeed(k_MotorStopSpeed);

} // end CmdBallShooterShootHigh::DeactivateShooterMotor()
