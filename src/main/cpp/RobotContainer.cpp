/** ===========================================================================
 * @file   RobotContainer.cpp
 * @brief  This file defines the RobotContainer class.
 *
 * The RobotContainer class holds robot subsystems and commands, and is where 
 * most of the declarative robot setup (e.g. button bindings) is performed.
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
 * Copyright (c) 2020-2022 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// The header for this class
#include "RobotContainer.h"

// The header for the robot constants
#include "RobotConstants.h"

// The header for mathematical/physical constants
#include "MathPhysicsConstants.h"

// The header containing the smart dashboard keys
#include "Telemetry/SmartDashboardKeys.h"

/************************ Member function definitions *************************/

// The constructor for the robot container
RobotContainer::RobotContainer() {

  // Initialize all of your commands and subsystems here

  // Set the default command for the drive train
  m_subSysDriveTrain.SetDefaultCommand(
    CmdDriveArcadeStyle(&m_subSysDriveTrain,&m_PrimaryJoystick));

  // Configure your SmartDashboard/Shuffleboard commands
  ConfigureXBoardCommands();

  // Configure the button bindings
  ConfigureButtonBindings();

} // end RobotContainer::RobotContainer()

// The destructor for the RobotContainer class
RobotContainer::~RobotContainer() {

} // end RobotContainer::~RobotContainer()

// Configure your commands for the SmartDashboard/Shuffleboard 
void RobotContainer::ConfigureXBoardCommands() {

  // Add commands to the autonomous command chooser

  // The default autonomous command
  m_autonomous_chooser.SetDefaultOption("Default Auto", &m_cmdGrpAutoDefault);
  // Add the command for running in the center, defensively
  m_autonomous_chooser.AddOption("Defensive Center", &m_cmdGrpAutoDefCenter);
  // Add the command for running in the left, defensively
  m_autonomous_chooser.AddOption("Defensive Left", &m_cmdGrpAutoDefLeft);
  // Add the command for running in the right, defensively
  m_autonomous_chooser.AddOption("Defensive Right", &m_cmdGrpAutoDefRight);
  // Add the command for running in the center, offensively
  m_autonomous_chooser.AddOption("Offensive Center", &m_cmdGrpAutoOffCenter);
  // Add the command for running in the left, offensively
  m_autonomous_chooser.AddOption("Offensive Left", &m_cmdGrpAutoOffLeft);
  // Add the command for running in the right, offensively
  m_autonomous_chooser.AddOption("Offensive Right", &m_cmdGrpAutoOffRight);

  // Put the chooser on the SmartDashboard
  frc::SmartDashboard::PutData("Autonomous Command Chooser", 
                               &m_autonomous_chooser);

  // Add the CmdZeroAHRS command to the SmartDashboard/Shuffleboard
  frc::SmartDashboard::PutData(k_CmdZeroAHRSYaw_Key, &m_cmdZeroAHRSYaw);

  // Add the CmdResetAHRS command to the SmartDashboard/Shuffleboard
  frc::SmartDashboard::PutData(k_CmdResetAHRSYaw_Key, &m_cmdResetAHRSYaw);

} // end RobotContainer::ConfigureXBoardCommands() 

// Configure your button bindings to commands
void RobotContainer::ConfigureButtonBindings() {

  // Configure your button bindings here

  // NOTE: Using `new` here will leak these commands if they are ever no 
  // longer needed. This is usually a non-issue as button-bindings tend
  // to be permanent - however, if you wish to avoid this, the commands
  // should be stack-allocated and declared as members of RobotContainer.

  // DRIVE TRAIN COMMAND BUTTON BINDINGS

  // When the Start button of the primary joystick is pressed,
  //   run the command to toggle the drive direction
  frc2::JoystickButton(&m_PrimaryJoystick, k_F310_StartButton)
    .WhenPressed(m_cmdToggleDriveDirection);

  // When the B button of the primary joystick is pressed,
  //   run the command to toggle the smoothing mode
  frc2::JoystickButton(&m_PrimaryJoystick, k_F310_B_Button)
    .WhenPressed(m_cmdToggleSmoothingMode);

  // When the A button of the primary joystick is pressed (and held),
  //   run the command to enable turbo mode
  frc2::JoystickButton(&m_PrimaryJoystick, k_F310_A_Button)
    .WhenPressed(&m_cmdEnableTurboMode);

  // When the A button of the primary joystick is released,
  //   run the command to disable turbo mode
  frc2::JoystickButton(&m_PrimaryJoystick, k_F310_A_Button)
    .WhenReleased(&m_cmdDisableTurboMode);

// BALL SHOOTER COMMAND BUTTON BINDINGS

  // When the X button of the primary joystick is pressed (and held),
  //   run the command to intake balls
  frc2::JoystickButton(&m_PrimaryJoystick, k_F310_X_Button)
   .WhenPressed(&m_cmdBallShooterIntake);

  // When the X button of the primary joystick is released,
  //   run the command to deactivate all shooter motors
  frc2::JoystickButton(&m_PrimaryJoystick, k_F310_X_Button)
   .WhenReleased(&m_cmdBallShooterAtRest);

  // When the east POV button of the primary joystick is released,
  //   run the command to shoot a ball to the lower target
  frc2::POVButton(&m_PrimaryJoystick, k_F310_POV_East, k_F310_POV_ID)
    .WhenReleased(&m_cmdBallShooterShootLow);

  // When the north POV button of the primary joystick is released,
  //   run the command to shoot a ball to the higher target
  frc2::POVButton(&m_PrimaryJoystick, k_F310_POV_North, k_F310_POV_ID)
    .WhenReleased(&m_cmdBallShooterShootHigh);
  
} // RobotContainer::ConfigureButtonBindings()

// Get the command to be ran in autonomous mode
frc2::Command* RobotContainer::GetAutonomousCommand() {

  // Get the selected autonomous command from the SmartDashboard/Shuffleboard
  return m_autonomous_chooser.GetSelected();

} // end RobotContainer::GetAutonomousCommand()

// Output telemetry
void RobotContainer::OutputTelemetryToSmartDashboard() {

  // Start the telemetry output time measurement
  StartTelemetryOutputTimeMeasurement();

  // Output the telemetry to the smart dashboard / shuffleboard
  m_TelemetryOutputter.OutputTelemetryToSmartDashboard();

  // Finish the telemetry output time measurement
  FinishTelemetryOutputTimeMeasurement();

} // end RobotContainer::OutputTelemetryToSmartDashboard()

// Increment Robot Tick counter
void RobotContainer::IncrementRobotTick() {

  // Increment the robot tick
  m_RobotPeriodicTick.IncrementRobotTick();

} // end RobotContainer::IncrementRobotTick()

// Get the robot tick count
uint64_t RobotContainer::GetRobotTick() {

  // Increment the robot tick
  return m_RobotPeriodicTick.GetRobotTick();

} // end RobotContainer::GetRobotTick()

// A method to start measuring the telemetry output time
void RobotContainer::StartTelemetryOutputTimeMeasurement() {

  // If we are on a one second increment after the 1st 5 seconds...
  if(GetRobotTick() % k_ExpectedRobotTicksPerSecond == 0
     && GetRobotTick() >= 
       k_TelemetryOutputDelaySec * k_ExpectedRobotTicksPerSecond)
  {

    // Get the starting FPGA time before we start telemetry
    m_FPGATimeStart = frc::RobotController::GetFPGATime();

    // Indicate we can output telemetry time
    m_output_telemetry_time = true;

  } // end if(GetRobotTick() ...)

} // end RobotContainer::StartTelemetryOutputTimeMeasurement()

// A method to finish measuring the telemetry output time
void RobotContainer::FinishTelemetryOutputTimeMeasurement() {

  // If we need to output the telemetry output time...
  if(m_output_telemetry_time) {

    // Get the ending time of the telemetry output
    m_FPGATimeEnd = frc::RobotController::GetFPGATime();

    // Calculate the elapsed time for telemetry output, in usec
    m_FPGATimeElapsed = m_FPGATimeEnd - m_FPGATimeStart;

    // Convert the elapsed time to milliseconds
    m_TelemetryOutputTimeMS = 
      m_FPGATimeElapsed / k_MicrosecondsPerMillisecond;

    // If we have a new maximum output time...
    if(m_TelemetryOutputTimeMS > m_MaxTelemetryOutputTimeMS) {

      // Save the new max output time
      m_MaxTelemetryOutputTimeMS = m_TelemetryOutputTimeMS;

    } // end if(m_TelemetryOutputTimeMS > m_MaxTelemetryOutputTimeMS)

    // If we have a new minimum output time...
    if(m_TelemetryOutputTimeMS < m_MinTelemetryOutputTimeMS) {

      // Save the new min output time
      m_MinTelemetryOutputTimeMS = m_TelemetryOutputTimeMS;

    } // end if(m_TelemetryOutputTimeMS > m_MinTelemetryOutputTimeMS)

    // Output the telemetry output time to the SmartDashboard
    frc::SmartDashboard::PutNumber(k_TelemetryOutputTimeMS_Key,
                                   m_TelemetryOutputTimeMS);

    // Output the maximum telemetry output time to the SmartDashboard
    frc::SmartDashboard::PutNumber(k_MaxTelemetryOutputTimeMS_Key,
                                   m_MaxTelemetryOutputTimeMS);

    // Output the minimum telemetry output time to the SmartDashboard
    frc::SmartDashboard::PutNumber(k_MinTelemetryOutputTimeMS_Key,
                                   m_MinTelemetryOutputTimeMS);

    // Don't output till the next second
    m_output_telemetry_time = false;

  } // end if(m_output_telemetry_time)

} // end RobotContainer::FinishTelemetryOutputTimeMeasurement()
