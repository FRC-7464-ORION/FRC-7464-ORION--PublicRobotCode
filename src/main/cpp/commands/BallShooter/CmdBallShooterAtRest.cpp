/** ===========================================================================
 * @file   CmdBallShooterAtRest.cpp
 * @brief  This file defines the CmdBallShooterAtRest class.
 *
 * The CmdBallShooterAtRest class is used to command the ball shooter
 * subsystem to completely stop (go to at rest).
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

// Include the header file for the CmdBallShooterAtRest class
#include "commands/BallShooter/CmdBallShooterAtRest.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// Include the I/O stream class, so we can write to the console
#include <iostream>

/************************ Member function definitions *************************/

// The constructor for the CmdBallShooterAtRest class
CmdBallShooterAtRest::CmdBallShooterAtRest(
  SubSysBallShooter* subsystem)
  : m_subSysBallShooter(subsystem) {

  // Set the command's name
  SetName("CmdBallShooterAtRest");

  // Require the use of the ball shooter subsystem
  AddRequirements({subsystem});

} // end CmdBallShooterAtRest::CmdBallShooterAtRest(...)

// The destructor for the CmdBallShooterAtRest class
CmdBallShooterAtRest::~CmdBallShooterAtRest() {

} // end CmdBallShooterAtRest::~CmdBallShooterAtRest()

// Called just before this Command runs the first time
void CmdBallShooterAtRest::Initialize() {

  // Indicate this command is not finished
  m_ThisCommandIsFinished = false;

  // Set the ball shooter state to "at rest"
  m_subSysBallShooter->SetBallShooterStateToAtRest();

} // end CmdBallShooterAtRest::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdBallShooterAtRest::Execute() {

  // Turn off all the motors
  CmdBallShooterAtRest::TurnOffAllBallShooterMotors();

  // Indicate this command is now finished
  m_ThisCommandIsFinished = true;

}  // end CmdBallShooterAtRest::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdBallShooterAtRest::IsFinished() {

  // Indicate the status of this command
  return m_ThisCommandIsFinished;

} // end CmdBallShooterAtRest::IsFinished()

// Called once after isFinished returns true, OR command 
//   is interrupted or canceled
void CmdBallShooterAtRest::End(bool interrupted) {

  // Turn off all the motors
  CmdBallShooterAtRest::TurnOffAllBallShooterMotors();

} // end CmdBallShooterAtRest::End()

// Convenience function to turn off all motors
void CmdBallShooterAtRest::TurnOffAllBallShooterMotors() {

  // Turn off the intake motor
  m_subSysBallShooter->SetIntakeMotorSpeed(k_MotorStopSpeed);
  // Turn off the left indexer motor
  m_subSysBallShooter->SetLeftIndexerMotorSpeed(k_MotorStopSpeed);
  // Turn off the right indexer motor
  m_subSysBallShooter->SetRightIndexerMotorSpeed(k_MotorStopSpeed);
  // Turn off the shooter motor
  m_subSysBallShooter->SetShooterMotorSpeed(k_MotorStopSpeed);

} // end CmdBallShooterAtRest::TurnOffAllBallShooterMotors()
