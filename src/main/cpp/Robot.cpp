/** ===========================================================================
 * @file   Robot.cpp
 * @brief  This file defines the Robot class.
 *
 * The Robot class is responsible for the main control flow of the robot.
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
 * Copyright (c) 2019-2022 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// The header for the NEW(2020) command scheduler
#include <frc2/command/CommandScheduler.h>

/************************ Member function definitions *************************/

// Robot-wide initialization code should go here.
void Robot::RobotInit() {

  // Output version to console
  outputVersionInfoToConsole();

} // end Robot::RobotInit()

// Robot-wide simulation initialization code should go here.
void Robot::SimulationInit() {
  
} // end Robot::SimulationInit()

// Initialization code for disabled mode should go here.
void Robot::DisabledInit() {

} // end Robot::DisabledInit()

// Periodic code for all modes should go here.
void Robot::RobotPeriodic() { 

  // Run the New(2020) command scheduler
  frc2::CommandScheduler::GetInstance().Run();

  // Output telemetry
  m_RobotContainer.OutputTelemetryToSmartDashboard();

  // Increment the robot tick counter
  m_RobotContainer.IncrementRobotTick();

} // end Robot::RobotPeriodic()

// Periodic simulation code should go here.
void Robot::SimulationPeriodic() {

} // end Robot::SimulationPeriodic()

// Periodic code for disabled mode should go here.
void Robot::DisabledPeriodic() {

} // end Robot::DisabledPeriodic()

// Initialization code for autonomous mode should go here.
void Robot::AutonomousInit() {

  // Store the autonomous command from the RobotContainer
  m_autonomousCommand = m_RobotContainer.GetAutonomousCommand();

  // If the autonomous command has been initialized...
  if (m_autonomousCommand != nullptr) {

    // Schedule the autonomous command to start
    m_autonomousCommand->Schedule();

  } // end if (m_autonomousCommand != nullptr)

} // end Robot::AutonomousInit()

// Periodic code for autonomous mode should go here.
void Robot::AutonomousPeriodic() {

} // end Robot::AutonomousPeriodic()

// Initialization code for teleop mode should go here.
void Robot::TeleopInit() {

  // The following if statement makes sure that the autonomous
  // stops running when teleop starts running. If you want the
  // autonomous to continue until interrupted by another command,
  // remove this if statement or comment it out.

  // If the autonomous command has been initialized...
  if (m_autonomousCommand != nullptr) {

    // Cancel the autonomous command, as we are now operator controlled
    m_autonomousCommand->Cancel();

    // Uninitialize the autonomous command
    m_autonomousCommand = nullptr;

  } // end if (m_autonomousCommand != nullptr)

} // end Robot::TeleopInit()

// Periodic code for teleop mode should go here.
void Robot::TeleopPeriodic() {

} // end Robot::TeleopPeriodic()

// Periodic code for test mode should go here.
void Robot::TestPeriodic() {
  
} // end Robot::TestPeriodic()

/****************** Private member function definitions ***********************/

// Outputs the version information to the console
void Robot::outputVersionInfoToConsole() {

  // Create the string to be output containing the version message
  m_RobotCode_version_msg = k_RobotName +
                            k_CodeVersionMessage +
                            k_SW_VersionNumber +
                            k_CodeVersionMessageEnd;

  // and output the version to the console
  printf("%s",&m_RobotCode_version_msg[0]);

} // end Robot::outputVersionInfoToConsole()

/****************************** START PROGRAM ********************************/

// If the macro RUNNING_FRC_TESTS is not defined...
#ifndef RUNNING_FRC_TESTS

/** This is the starting point for the entire robot code. */
int main() {

  // Start the robot
  return frc::StartRobot<Robot>(); 

} // end main()

#endif // #ifndef RUNNING_FRC_TESTS
