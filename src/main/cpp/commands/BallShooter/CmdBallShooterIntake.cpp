/** ===========================================================================
 * @file   CmdBallShooterIntake.cpp
 * @brief  This file defines the CmdBallShooterIntake class.
 *
 * The CmdBallShooterIntake class is used to command the ball shooter
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

// Include the header file for the CmdBallShooterIntake class
#include "commands/BallShooter/CmdBallShooterIntake.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// Include the I/O stream class, so we can write to the console
#include <iostream>

/************************ Member function definitions *************************/

// The constructor for the CmdBallShooterIntake class
CmdBallShooterIntake::CmdBallShooterIntake(
  SubSysBallShooter* subsystem)
  : m_subSysBallShooter(subsystem) {

  // Set the command's name
  SetName("CmdBallShooterIntake");

  // Require the use of the ball shooter subsystem
  AddRequirements({subsystem});

} // end CmdBallShooterIntake::CmdBallShooterIntake(...)

// The destructor for the CmdBallShooterIntake class
CmdBallShooterIntake::~CmdBallShooterIntake() {

} // end CmdBallShooterIntake::~CmdBallShooterIntake()

// Called just before this Command runs the first time
void CmdBallShooterIntake::Initialize() {

  // Indicate this command is not finished
  m_ThisCommandIsFinished = false;

  // Set the ball shooter state to "intaking"
  m_subSysBallShooter->SetBallShooterStateToIntaking();

} // end CmdBallShooterIntake::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdBallShooterIntake::Execute() {

  // Turn on all the intake motors
  CmdBallShooterIntake::ActivateIntakeMotors();

  // Indicate this command is never finished, as we want it on till 
  // we release our button on the Logitech controller
  m_ThisCommandIsFinished = false;

}  // end CmdBallShooterIntake::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdBallShooterIntake::IsFinished() {

  // Indicate the status of this command
  return m_ThisCommandIsFinished;

} // end CmdBallShooterIntake::IsFinished()

// Called once after isFinished returns true, OR command 
//   is interrupted or canceled
void CmdBallShooterIntake::End(bool interrupted) {

  // Turn off all the intake motors
  CmdBallShooterIntake::DeactivateIntakeMotors();

  // Indicate this command is finished
  m_ThisCommandIsFinished = true;

} // end CmdBallShooterIntake::End()

// Convenience function to activate intake motors
void CmdBallShooterIntake::ActivateIntakeMotors() {

  // Turn on the intake motor
  m_subSysBallShooter->SetIntakeMotorSpeed(
    k_BallShooterIntakeMotorSpeed);
  // Turn on the left indexer motor
  m_subSysBallShooter->SetLeftIndexerMotorSpeed(
    k_BallShooterIndexerMotorSpeed);
  // Turn on the right indexer motor
  m_subSysBallShooter->SetRightIndexerMotorSpeed(
    k_BallShooterIndexerMotorSpeed*k_ReverseSpeedMultiplier);

} // end CmdBallShooterIntake::TurnOffAllBallShooterMotors()

// Convenience function to deactivate intake motors
void CmdBallShooterIntake::DeactivateIntakeMotors() {

  // Turn off the intake motor
  m_subSysBallShooter->SetIntakeMotorSpeed(k_MotorStopSpeed);
  // Turn off the left indexer motor
  m_subSysBallShooter->SetLeftIndexerMotorSpeed(k_MotorStopSpeed);
  // Turn off the right indexer motor
  m_subSysBallShooter->SetRightIndexerMotorSpeed(k_MotorStopSpeed);

} // end CmdBallShooterIntake::TurnOffAllBallShooterMotors()
