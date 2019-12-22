/** ===========================================================================
 * @file   Robot.cpp
 * @brief  This file defines the Robot class.
 *
 * The Robot class defines the entire robot, its subsystems, commands, etc.
 *
 * This robot is based on the "CommandBasedRobot" base class. See the
 * documentation at https://wpilib.screenstepslive.com/s/currentCS/m/cpp.
 *
 * Specifically, look at the section near the end entitled
 * "Command Based Programming", at
 * https://wpilib.screenstepslive.com/s/currentCS/m/cpp/c/88685.
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

// Include the Robot class header file
#include "Robot.h"

// Include out robot map header file
#include "RobotMap.h"

/************************** Library Header Files ******************************/

// Include the I/O stream class, so we can write to the console
#include <iostream>

// Include the Scheduler class header file, which allows us to schedule
//   various commands.
// See:
// https://wpilib.screenstepslive.com/s/currentCS/m/cpp/l/277232-scheduling-commands
#include <frc/commands/Scheduler.h>

// Include the SmartDashboard class header file, which allows us to transmit
//   robot data to the operator console
// See:
// https://wpilib.screenstepslive.com/s/currentCS/m/smartdashboard
#include <frc/smartdashboard/SmartDashboard.h>

/******************** Static member variable definitions *********************/

// Define the Robot's static member variable m_subSysDriveTrain
std::shared_ptr<SubSysDriveTrain> Robot::m_subSysDriveTrain;

// If we are using Tippy Toes...
#if USE_TIPPY_TOES

// Define the Robot's static member variable m_subSysTippyToes
std::shared_ptr<SubSysTippyToes> Robot::m_subSysTippyToes;

#endif // #if USE_TIPPY_TOES

// If we are not using the PID controller for Capt. Hook
#if !USE_PID_CAPT_HOOK

// Define the Robot's static member variable m_subSysCaptHook
std::shared_ptr<SubSysCaptHook> Robot::m_subSysCaptHook;

#endif // #if !USE_PID_CAPT_HOOK

// If we are using Capt. Hook with a PID controller...
#if USE_PID_CAPT_HOOK

// Define the Robot's static member variable m_PIDsubSysCaptHook
std::shared_ptr<PIDSubSysCaptHook> Robot::m_PIDsubSysCaptHook;

#endif // #if USE_PID_CAPT_HOOK

// Define the Robot's static member variable m_oi, which is an OI type
std::unique_ptr<OI> Robot::m_oi;

// Define the Robot's static member variable m_cmdDriveArcadeStyle
std::shared_ptr<CmdDriveArcadeStyle> Robot::m_cmdDriveArcadeStyle;

// Define the Robot's static member variable m_cmdDriveTankStyle
std::shared_ptr<CmdDriveTankStyle> Robot::m_cmdDriveTankStyle;

// Define the Robot's static member variable m_RobotTick
uint64_t Robot::m_RobotTick;

// Define the Robot's static member variable m_TelemetryOutputter
TelemetryOutputter* Robot::m_TelemetryOutputter;

/******************* Public member function definitions ***********************/

// Robot-wide initialization code should go here.
void Robot::RobotInit() {

  // MAKE SURE ALL SUBSYSTEMS ARE INSTANTIATED FIRST IN RobotInit()!!!
  // See note on OI instantiation below.

  // Reset the newly created SubSysDriveTrain
  m_subSysDriveTrain.reset(new SubSysDriveTrain());

#if ORION_DEBUG
  if(m_subSysDriveTrain == nullptr) {
    wpi::outs() << "m_subSysDriveTrain not initialized!\n";
    wpi::outs().flush();
  }
#endif // #if ORION_DEBUG

// If we are using Tippy Toes...
#if USE_TIPPY_TOES

  // Reset the newly created SubSysTippyToes
  m_subSysTippyToes.reset(new SubSysTippyToes());

#if ORION_DEBUG
  if(m_subSysTippyToes == nullptr) {
    wpi::outs() << "m_subSysTippyToes not initialized!\n";
    wpi::outs().flush();
  }
#endif // #if ORION_DEBUG

#endif // #if USE_TIPPY_TOES

// If we are not using the PID controller for Capt. Hook
#if !USE_PID_CAPT_HOOK

  // Reset the newly created SubSysCaptHook
  m_subSysCaptHook.reset(new SubSysCaptHook());

#if ORION_DEBUG
  if(m_subSysCaptHook == nullptr) {
    wpi::outs() << "m_subSysCaptHook not initialized!\n";
    wpi::outs().flush();
  }
#endif // #if ORION_DEBUG

#endif // #if !USE_PID_CAPT_HOOK

// If we are using Capt. Hook with a PID controller...
#if USE_PID_CAPT_HOOK

  // Reset the newly created PIDSubSysCaptHook
  m_PIDsubSysCaptHook.reset(new PIDSubSysCaptHook());

#if ORION_DEBUG
  if(m_PIDsubSysCaptHook == nullptr) {
    wpi::outs() << "m_PIDsubSysCaptHook not initialized!\n";
    wpi::outs().flush();
  }
#endif

#endif // #if USE_PID_CAPT_HOOK

  // The instantiation of the operator interface (OI) class MUST be
  // done after all subsytems have been instantiated, but before
  // any commands have been instantiated.
  //
  // If the OI creates Commands (which it very likely will), 
  // constructing it during the construction of CommandBase (from
  // which commands extend), subsystems are not guaranteed to be
  // yet. Thus, their requires() statements may grab null pointers. Bad
  // news. Don't move it.
  m_oi.reset(new OI());

#if ORION_DEBUG
  if(m_oi == nullptr) {
    wpi::outs() << "m_oi not initialized!\n";
    wpi::outs().flush();
  }
#endif // #if ORION_DEBUG

  // Reset the drive arcade style command after being created
  m_cmdDriveArcadeStyle.reset(new CmdDriveArcadeStyle());

#if ORION_DEBUG
  if(m_cmdDriveArcadeStyle == nullptr) {
    wpi::outs() << "m_cmdDriveArcadeStyle not initialized!\n";
    wpi::outs().flush();
  }
#endif // #if ORION_DEBUG

  // Reset the drive tank style command after being created
  m_cmdDriveTankStyle.reset(new CmdDriveTankStyle());

#if ORION_DEBUG
  if(m_cmdDriveTankStyle == nullptr) {
    wpi::outs() << "m_cmdDriveTankStyle not initialized!\n";
    wpi::outs().flush();
  }
#endif // #if ORION_DEBUG

  // Create a new instance of the telemetry outputter
  m_TelemetryOutputter = new TelemetryOutputter();

#if ORION_DEBUG
  if(m_TelemetryOutputter == nullptr) {
    wpi::outs() << "m_TelemetryOutputter not initialized!\n";
    wpi::outs().flush();
  }
#endif // #if ORION_DEBUG

  // Initialize our robot tick counter to 0
  m_RobotTick = 0;

  // Initialize the USB camera for streaming
  InitializeUSBCamera(k_Camera0Name, k_Camera0NameDeviceNumber);

  // Output the version info to the console
  outputVersionInfoToConsole();

#if ORION_DEBUG
  // Output to the console that ORION debug is turned on
  wpi::outs() << "!!!WARNING!!! - ORION DEBUG SET TO ON!";
  wpi::outs().flush();
#endif // #if ORION_DEBUG

#if TELEMETRY_DEBUG
  // Output to the console that telemetry debug is turned on
  wpi::outs() << "!!!WARNING!!! - TELEMETRY DEBUG SET TO ON!";
  wpi::outs().flush();
#endif // #if TELEMETRY_DEBUG

} // end Robot::RobotInit()

// Periodic code for all modes should go here.
void Robot::RobotPeriodic() {

#if TELEMETRY_DEBUG
  // The time we started the telemetry output, in microseconds (usec)
  uint64_t FPGATimeStart;
  // The time we ended the telemetry output, in microseconds (usec)
  uint64_t FPGATimeEnd;
  // The elapsed time of the telemetry output, in microseconds (usec)
  uint64_t FPGATimeElapsed;
  // The elapsed time of the telemetry output, in milliseconds (msec, ms)
  double TelemetryOutputTimeMS;
  // The expected times the RobotPeriodic function should run per second
  const uint64_t ExpectedRobotTicksPerSecond = 50;
  // The number of microseconds per millisecond
  const double MicrosecondsPerMillisecond = 1000.0;

  // If we are on a one second increment...
  if(m_RobotTick % ExpectedRobotTicksPerSecond == 0)
    // Get the starting FPGA time before we start telemetry
    FPGATimeStart = frc::RobotController::GetFPGATime();
#endif // #if TELEMETRY_DEBUG

  // If the telemetry output pointer has been initialized...
  if(m_TelemetryOutputter != nullptr) {

    // Output the telemetry to the dashboard
    m_TelemetryOutputter->OutputTelemetryToSmartDashboard();

#if TELEMETRY_DEBUG

    if(m_RobotTick % ExpectedRobotTicksPerSecond == 0) {

      // Get the ending time of the telemetry output
      FPGATimeEnd = frc::RobotController::GetFPGATime();
      // Calculate the elapsed time for telemetry output, in usec
      FPGATimeElapsed = FPGATimeEnd - FPGATimeStart;
      // Convert the elapsed time to milliseconds
      TelemetryOutputTimeMS = FPGATimeElapsed / MicrosecondsPerMillisecond;

      // Output the telemetry output time to the SmartDashboard
      frc::SmartDashboard::PutNumber("Telem. Out Time(ms)", TelemetryOutputTimeMS);

      // Output the telemetry output time to the console
      wpi::outs() << "Telemetry Output Time = "
                  << TelemetryOutputTimeMS
                  << "ms.\n";
      wpi::outs().flush();

    } // end if(m_RobotTick % ExpectedRobotTicksPerSecond == 0)

#endif // #if TELEMETRY_DEBUG

  } // if(m_TelemetryOutputter != nullptr)

#if ORION_DEBUG

  else {

    // Output that we have not initialized the telemetry outputter
    wpi::outs() << "m_TelemetryOutputter not initialized!\n";
    wpi::outs().flush();

  } // end else (if(m_TelemetryOutputter != nullptr))

#endif // #if ORION_DEBUG

  // Increment our robot tick counter
  m_RobotTick++;

} // end Robot::RobotPeriodic()

// Initialization code for disabled mode should go here.
void Robot::DisabledInit() {

} // end Robot::DisabledInit()

// Periodic code for disabled mode should go here.
void Robot::DisabledPeriodic() {

  /*
   * Get the instance of the scheduler (if it doesn't exist, create one),
   *   then run the scheduler for a single iteration of the loop,
   *   which consists of:
   *   1. Poll the buttons
   *   2. Execute/Remove the commands
   *   3. Send values to SmartDashboard
   *   4. Add commands
   *   5. Add defaults
  */
  frc::Scheduler::GetInstance()->Run();

} // end Robot::DisabledPeriodic()

/*
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString code to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to the
 * chooser code above (like the commented example) or additional comparisons to
 * the if-else structure below with additional strings & commands.
*/
// Initialization code for autonomous mode should go here.
void Robot::AutonomousInit() {

  // If the drive arcade style command pointer has been intialized...
  if ( m_cmdDriveArcadeStyle != nullptr) {

    // Start the drive arcade style command
    m_cmdDriveArcadeStyle->Start();

  } // end if ( m_cmdDriveArcadeStyle != nullptr)
  else {

#if ORION_DEBUG
    // Output a warning
    wpi::outs() << "!!! WARNING !!! - m_cmdDriveArcadeStyle not initialized!";
    wpi::outs().flush();
#endif // #if ORION_DEBUG

  } // end else (if ( m_cmdDriveArcadeStyle != nullptr))

} // end Robot::AutonomousInit()

// Periodic code for autonomous mode should go here.
void Robot::AutonomousPeriodic() {

  /*
   * Get the instance of the scheduler (if it doesn't exist, create one),
   *   then run the scheduler for a single iteration of the loop,
   *   which consists of:
   *   1. Poll the buttons
   *   2. Execute/Remove the commands
   *   3. Send values to SmartDashboard
   *   4. Add commands
   *   5. Add defaults
  */
  frc::Scheduler::GetInstance()->Run();

} // end Robot::AutonomousPeriodic()

// Initialization code for teleop mode should go here.
void Robot::TeleopInit() {

} // end Robot::TeleopInit()

// Periodic code for teleop mode should go here.
void Robot::TeleopPeriodic() {

  /*
   * Get the instance of the scheduler (if it doesn't exist, create one),
   *   then run the scheduler for a single iteration of the loop,
   *   which consists of:
   *   1. Poll the buttons
   *   2. Execute/Remove the commands
   *   3. Send values to SmartDashboard
   *   4. Add commands
   *   5. Add defaults
  */
  frc::Scheduler::GetInstance()->Run();
  
} // end Robot::TeleopPeriodic()

// Periodic code for test mode should go here.
void Robot::TestPeriodic() {

} // end Robot::TestPeriodic()

/****************** Private member function definitions ***********************/

// Outputs the version information to the console
void Robot::outputVersionInfoToConsole() {

  // Output to the WPI output stream the version of the code we are running
  wpi::outs() << k_RobotName
              << k_CodeVersionMessage
              << k_SW_VersionNumber
              << k_CodeVersionMessageEnd;
  // Flush the WPI output stream, so above message will be output
  wpi::outs().flush();

} // end outputVersionInfoToConsole()

// Initialize a USB camera
void Robot::InitializeUSBCamera(const std::string CameraName,
                                const int CameraDeviceNum) {

  // If we are running on a Linux platform (The roboRIO runs Linux)
  #if defined(__linux__)

    // Start Automatic Capture of the specified camera
    frc::CameraServer::GetInstance()->StartAutomaticCapture(CameraName,
                                                            CameraDeviceNum);

  #else // We are not running on a Linux platform

    // Write to the WPI error stream the problem
    wpi::errs() << "Vision only available on Linux.\n";
    // Flush the error stream, so it will be displayed immediately
    wpi::errs().flush();

  #endif // #if defined(__linux__)

} // end Robot::InitializeUSBCamera(const std::string, const int)

/****************************** START PROGRAM ********************************/

// If the macro RUNNING_FRC_TESTS is not defined...
#ifndef RUNNING_FRC_TESTS

  /** This is the starting point for the entire robot code. */
  int main(int argc, char** argv) {

    return frc::StartRobot<Robot>();

  } // end main()

#endif // #ifndef RUNNING_FRC_TESTS
