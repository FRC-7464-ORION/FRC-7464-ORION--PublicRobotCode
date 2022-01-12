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
 * Copyright (c) 2019-2020 FRC Team #7464 - ORION. All Rights Reserved.
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

// Define the Robot's static member variable m_AHRS
AHRS* Robot::m_AHRS;

// Define the Robot's static member variable m_subSysDriveTrain
std::shared_ptr<SubSysDriveTrain> Robot::m_subSysDriveTrain;

// Define the Robot's static member variable m_subSysPATTurner
std::shared_ptr<SubSysPATTurner> Robot::m_subSysPATTurner;

// Define the Robot's static member variable m_subSysHansFranz
std::shared_ptr<SubSysHansFranzMuscles> Robot::m_subSysHansFranzMuscles;

// Define the Robot's static member variable m_subSysHansFranzArms
std::shared_ptr<SubSysHansFranzArms> Robot::m_subSysHansFranzArms;

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

// Define the Robot's static member variable m_PIDsubSysPssh
std::shared_ptr<PIDSubSysPssh> Robot::m_PIDsubSysPssh;

#endif // #if USE_PID_PSSH

// If we are NOT using the PID controller for Pssh
#if !USE_PID_PSSH

// Define the Robot's static member variable m_subSysPssh
std::shared_ptr<SubSysPssh> Robot::m_subSysPssh;

#endif // #if !USE_PID_PSSH

// Define the Robot's static member variable m_oi, which is an OI type
std::unique_ptr<OI> Robot::m_oi;

// Define the Robot's static member variable m_cmdDriveArcadeStyle
std::shared_ptr<CmdDriveArcadeStyle> Robot::m_cmdDriveArcadeStyle;

// Define the Robot's static member variable m_cmdDriveTankStyle
std::shared_ptr<CmdDriveTankStyle> Robot::m_cmdDriveTankStyle;

// Define the Robot's static member variable m_cmdMoveHansFranzArms
std::shared_ptr<CmdMoveHansFranzArms> Robot::m_cmdMoveHansFranzArms;

// If we are NOT using the PID controller for Pssh
#if !USE_PID_PSSH

// Define the Robot's static member variable m_cmdControlPssh
std::shared_ptr<CmdControlPssh> Robot::m_cmdControlPssh;

#endif // #if !USE_PID_PSSH

// Define the Robot's static member variable m_CmdGrpAutoDefault
std::shared_ptr<CmdGrpAutoDefault> Robot::m_CmdGrpAutoDefault;

// Define the Robot's static member variable m_CmdGrpAutoDefLeft
std::shared_ptr<CmdGrpAutoDefLeft> Robot::m_CmdGrpAutoDefLeft;

// Define the Robot's static member variable m_CmdGrpAutoDefCenter
std::shared_ptr<CmdGrpAutoDefCenter> Robot::m_CmdGrpAutoDefCenter;

// Define the Robot's static member variable m_CmdGrpAutoDefRight
std::shared_ptr<CmdGrpAutoDefRight> Robot::m_CmdGrpAutoDefRight;

// Define the Robot's static member variable m_CmdGrpAutoOffLeft
std::shared_ptr<CmdGrpAutoOffLeft> Robot::m_CmdGrpAutoOffLeft;

// Define the Robot's static member variable m_CmdGrpAutoOffCenter
std::shared_ptr<CmdGrpAutoOffCenter> Robot::m_CmdGrpAutoOffCenter;

// Define the Robot's static member variable m_CmdGrpAutoOffRight
std::shared_ptr<CmdGrpAutoOffRight> Robot::m_CmdGrpAutoOffRight;

// Define the Robot's static member variable m_RobotTick
uint64_t Robot::m_RobotTick;

// Define the Robot's static member variable m_TelemetryOutputter
TelemetryOutputter* Robot::m_TelemetryOutputter;

// Define the Robot's static member variable m_Video
Video* Robot::m_Video;

/******************* Public member function definitions **********************/

// Robot-wide initialization code should go here.
void Robot::RobotInit() {

  // NOTE: Create an instance of the AHRS class before subsystems, and 
  //       definitely before commands. Otherwise, when a subsystem or command
  //       is instantiated that uses AHRS, it will have a null pointer
  //       for the AHRS class.

  // Create a new instance of the AHRS navigation
  m_AHRS = new AHRS(k_navx_mxp_imu_port);

#if ORION_DEBUG
  if(m_AHRS == nullptr) {
    frc::DriverStation::ReportError("m_AHRS NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_AHRS initialized!");
  }
#endif // #if ORION_DEBUG

  // MAKE SURE ALL SUBSYSTEMS ARE INSTANTIATED FIRST IN RobotInit()!!!
  // See note on OI instantiation below.

  /***************************** SUBSYSTEMS **********************************/

  // Reset the newly created SubSysDriveTrain
  m_subSysDriveTrain.reset(new SubSysDriveTrain());

#if ORION_DEBUG
  if(m_subSysDriveTrain == nullptr) {
    frc::DriverStation::ReportError("m_subSysDriveTrain NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_subSysDriveTrain initialized!");
  }
#endif // #if ORION_DEBUG

  // Reset the newly created SubSysPATTurner
  m_subSysPATTurner.reset(new SubSysPATTurner());

#if ORION_DEBUG
  if(m_subSysPATTurner == nullptr) {
    frc::DriverStation::ReportError("m_subSysPATTurner NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_subSysPATTurner initialized!");
  }
#endif // #if ORION_DEBUG

  // Reset the newly created SubSysHansFranz
  m_subSysHansFranzMuscles.reset(new SubSysHansFranzMuscles());

#if ORION_DEBUG
  if(m_subSysHansFranzMuscles == nullptr) {
    frc::DriverStation::ReportError("m_subSysHansFranzMuscles NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_subSysHansFranzMuscles initialized!");
  }
#endif // #if ORION_DEBUG

  // Reset the newly created SubSysHansFranzArms
  m_subSysHansFranzArms.reset(new SubSysHansFranzArms());

#if ORION_DEBUG
  if(m_subSysHansFranzArms == nullptr) {
    frc::DriverStation::ReportError("m_subSysHansFranzArms NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_subSysHansFranzArms initialized!");
  }
#endif // #if ORION_DEBUG

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

  // Reset the newly created PIDSubSysPssh
  m_PIDsubSysPssh.reset(new PIDSubSysPssh());

#if ORION_DEBUG
  if(m_PIDsubSysPssh == nullptr) {
    frc::DriverStation::ReportError("m_PIDsubSysPssh NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_PIDsubSysPssh initialized!");
  }
#endif // #if ORION_DEBUG

#endif // #if USE_PID_PSSH

// If we are NOT using the PID controller for Pssh
#if !USE_PID_PSSH

  // Reset the newly created SubSysPssh
  m_subSysPssh.reset(new SubSysPssh());

#if ORION_DEBUG
  if(m_subSysPssh == nullptr) {
    frc::DriverStation::ReportError("m_subSysPssh NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_subSysPssh initialized!");
  }
#endif // #if ORION_DEBUG

#endif // #if !USE_PID_PSSH

/************************* OPERATOR INTERFACE ********************************/

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
    frc::DriverStation::ReportError("m_oi NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_oi initialized!");
  }
#endif // #if ORION_DEBUG

/********************** COMMANDS/COMMAND GROUPS ******************************/

  // Reset the drive arcade style command after being created
  m_cmdDriveArcadeStyle.reset(new CmdDriveArcadeStyle());

#if ORION_DEBUG
  if(m_cmdDriveArcadeStyle == nullptr) {
    frc::DriverStation::ReportError("m_cmdDriveArcadeStyle NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_cmdDriveArcadeStyle initialized!");
  }
#endif // #if ORION_DEBUG

  // Reset the drive tank style command after being created
  m_cmdDriveTankStyle.reset(new CmdDriveTankStyle());

#if ORION_DEBUG
  if(m_cmdDriveTankStyle == nullptr) {
    frc::DriverStation::ReportError("m_cmdDriveTankStyle NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_cmdDriveTankStyle initialized!");
  }
#endif // #if ORION_DEBUG

// If we are NOT using the PID controller for PSSH...
#if !USE_PID_PSSH

  // Reset the control Pssh command after being created
  m_cmdControlPssh.reset(new CmdControlPssh());

#if ORION_DEBUG
  if(m_cmdControlPssh == nullptr) {
    frc::DriverStation::ReportError("m_cmdControlPssh NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_cmdControlPssh initialized!");
  }
#endif // #if ORION_DEBUG

#endif // #if !USE_PID_PSSH

  // Reset the move Hans/Franz arms command after being created
  m_cmdMoveHansFranzArms.reset(new CmdMoveHansFranzArms());

#if ORION_DEBUG
  if(m_cmdMoveHansFranzArms == nullptr) {
    frc::DriverStation::ReportError("m_cmdMoveHansFranzArms NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_cmdMoveHansFranzArms initialized!");
  }
#endif // #if ORION_DEBUG

  // Reset the command group CmdGrpAutoDefault after being created
  m_CmdGrpAutoDefault.reset(new CmdGrpAutoDefault());

#if ORION_DEBUG
  if(m_CmdGrpAutoDefault == nullptr) {
    frc::DriverStation::ReportError("m_CmdGrpAutoDefault NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_CmdGrpAutoDefault initialized!");
  }
#endif // #if ORION_DEBUG

  // Reset the command group CmdGrpAutoDefLeft after being created
  m_CmdGrpAutoDefLeft.reset(new CmdGrpAutoDefLeft());

#if ORION_DEBUG
  if(m_CmdGrpAutoDefLeft == nullptr) {
    frc::DriverStation::ReportError("m_CmdGrpAutoDefLeft NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_CmdGrpAutoDefLeft initialized!");
  }
#endif // #if ORION_DEBUG

  // Reset the command group CmdGrpAutoDefCenter after being created
  m_CmdGrpAutoDefCenter.reset(new CmdGrpAutoDefCenter());

#if ORION_DEBUG
  if(m_CmdGrpAutoDefCenter == nullptr) {
    frc::DriverStation::ReportError("m_CmdGrpAutoDefCenter NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_CmdGrpAutoDefCenter initialized!");
  }
#endif // #if ORION_DEBUG

  // Reset the command group CmdGrpAutoDefRight after being created
  m_CmdGrpAutoDefRight.reset(new CmdGrpAutoDefRight());

#if ORION_DEBUG
  if(m_CmdGrpAutoDefRight == nullptr) {
    frc::DriverStation::ReportError("m_CmdGrpAutoDefRight NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_CmdGrpAutoDefRight initialized!");
  }
#endif // #if ORION_DEBUG

  // Reset the command group CmdGrpAutoOffLeft after being created
  m_CmdGrpAutoOffLeft.reset(new CmdGrpAutoOffLeft());

#if ORION_DEBUG
  if(m_CmdGrpAutoOffLeft == nullptr) {
    frc::DriverStation::ReportError("m_CmdGrpAutoOffLeft NOT initialized!\n");
  }
  else {
    frc::DriverStation::ReportWarning("m_CmdGrpAutoOffLeft initialized!\n");
  }
#endif // #if ORION_DEBUG

  // Reset the command group CmdGrpAutoOffCenter after being created
  m_CmdGrpAutoOffCenter.reset(new CmdGrpAutoOffCenter());

#if ORION_DEBUG
  if(m_CmdGrpAutoOffCenter == nullptr) {
    frc::DriverStation::ReportError("m_CmdGrpAutoOffCenter NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_CmdGrpAutoOffCenter initialized!");
  }
#endif // #if ORION_DEBUG

  // Reset the command group CmdGrpAutoOffRight after being created
  m_CmdGrpAutoOffRight.reset(new CmdGrpAutoOffRight());

#if ORION_DEBUG
  if(m_CmdGrpAutoOffRight == nullptr) {
    frc::DriverStation::ReportError("m_CmdGrpAutoOffRight NOT initialized!\n");
  }
  else {
    frc::DriverStation::ReportWarning("m_CmdGrpAutoOffRight initialized!\n");
  }
#endif // #if ORION_DEBUG

/********************************* OTHERS ************************************/

  // Create a new instance of the telemetry outputter
  m_TelemetryOutputter = new TelemetryOutputter();

#if ORION_DEBUG
  if(m_TelemetryOutputter == nullptr) {
    frc::DriverStation::ReportError("m_TelemetryOutputter NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_TelemetryOutputter initialized!");
  }
#endif // #if ORION_DEBUG

  // Create a new instance of the video system
  m_Video = new Video();

#if ORION_DEBUG
  if(m_Video == nullptr) {
    frc::DriverStation::ReportError("m_Video NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_Video initialized!");
  }
#endif // #if ORION_DEBUG

  // Initialize our robot tick counter to 0
  m_RobotTick = 0;

  // Output the version info to the console
  outputVersionInfoToConsole();

#if ORION_DEBUG
  // Output to the console that ORION debug is turned on
  frc::DriverStation::ReportWarning("!!!WARNING!!! - ORION DEBUG SET TO ON!");
#endif // #if ORION_DEBUG

#if TELEMETRY_DEBUG
  // Output to the console that telemetry debug is turned on
  frc::DriverStation::ReportWarning("!!!WARNING!!! - TELEMETRY DEBUG SET TO ON!");
#endif // #if TELEMETRY_DEBUG

  // Add our subsystems to be shown in the dashboard
  // NOTE: We have to use the .get() function because PutData() expects
  //       a pointer to a Sendable, and the pointers below are 
  //       shared_ptr's.
  // See https://stackoverflow.com/questions/505143/getting-a-normal-ptr-from-shared-ptr
  frc::SmartDashboard::PutData(m_subSysDriveTrain.get());
  frc::SmartDashboard::PutData(m_subSysPATTurner.get());
  frc::SmartDashboard::PutData(m_subSysHansFranzMuscles.get());
  frc::SmartDashboard::PutData(m_subSysHansFranzArms.get());
// If we are using the PID controller for Pssh
#if USE_PID_PSSH
  frc::SmartDashboard::PutData(m_PIDsubSysPssh.get());
#endif // #if USE_PID_PSSH
// If we are NOT using the PID controller for Pssh
#if !USE_PID_PSSH
  frc::SmartDashboard::PutData(m_subSysPssh.get());
#endif // #if !USE_PID_PSSH

  // Add the default command 
  autonomous_chooser.SetDefaultOption("Default Auto", new CmdGrpAutoDefault());
  // Add the command for running on the left, offensively
  autonomous_chooser.AddOption("Offensive Left", new CmdGrpAutoOffLeft());
  // Add the command for running in the center, offensively
  autonomous_chooser.AddOption("Offensive Center", new CmdGrpAutoOffCenter());
  // Add the command for running on the right, offensively
  autonomous_chooser.AddOption("Offensive Right", new CmdGrpAutoOffRight());
  // Add the command for running on the left, defensively
  autonomous_chooser.AddOption("Defensive Left", new CmdGrpAutoDefLeft());
  // Add the command for running in the center, defensively
  autonomous_chooser.AddOption("Defensive Center", new CmdGrpAutoDefCenter());
  // Add the command for running on the right, defensively
  autonomous_chooser.AddOption("Defensive Right", new CmdGrpAutoDefRight());
  // Put the chooser on the dashboard
  frc::SmartDashboard::PutData("Autonomous Commands",
     &autonomous_chooser);

  // Add some commands to the SmartDashboard (ShuffleBoard in our case)
  frc::SmartDashboard::PutData("Cmd: Zero AHRS Yaw", new CmdZeroAHRSYaw());
  frc::SmartDashboard::PutData("Cmd: Reset AHRS Yaw", new CmdResetAHRSYaw());

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
  // A boolean to tell us when to output the telemetry time
  bool output_telemetry_time = false;

  // If we are on a one second increment...
  if(m_RobotTick % k_ExpectedRobotTicksPerSecond == 0)
  {
    // Get the starting FPGA time before we start telemetry
    FPGATimeStart = frc::RobotController::GetFPGATime();

    // Indicate we can output telemetry time
    output_telemetry_time = true;
  }
#endif // #if TELEMETRY_DEBUG

  // If the telemetry output pointer has been initialized...
  if(m_TelemetryOutputter != nullptr) {

    // Output the telemetry to the dashboard
    m_TelemetryOutputter->OutputTelemetryToSmartDashboard();

#if TELEMETRY_DEBUG

    if(output_telemetry_time) {

      // Get the ending time of the telemetry output
      FPGATimeEnd = frc::RobotController::GetFPGATime();

// Ignore the warning that FPGATimeStart is uninitialized
// It is initialized in the previous #if TELEMETRY
// See https://gcc.gnu.org/onlinedocs/gcc/Diagnostic-Pragmas.html
//   and https://www.chiefdelphi.com/t/pragma-or-gradle-flag-for-ignoring-deprecated-warnings/375815
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
      // Calculate the elapsed time for telemetry output, in usec
      FPGATimeElapsed = FPGATimeEnd - FPGATimeStart;
#pragma GCC diagnostic pop

      // Convert the elapsed time to milliseconds
      TelemetryOutputTimeMS = FPGATimeElapsed / k_MicrosecondsPerMillisecond;

      // Output the telemetry output time to the SmartDashboard
      frc::SmartDashboard::PutNumber("Telem. Out Time(ms)", TelemetryOutputTimeMS);

      // Create the telemetry message
      m_telemetry_debug_msg = "Telemetry Output Time = " + 
                              std::to_string(TelemetryOutputTimeMS) +
                              "ms.\n";

      // and output to the DriveStation as a warning
      frc::DriverStation::ReportWarning(m_telemetry_debug_msg);

    } // end if(m_RobotTick % k_ExpectedRobotTicksPerSecond == 0)

#endif // #if TELEMETRY_DEBUG

  } // if(m_TelemetryOutputter != nullptr)

#if ORION_DEBUG

  else {

    // Output that we have not initialized the telemetry outputter
    frc::DriverStation::ReportError("m_TelemetryOutputter NOT initialized!");

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

  // Get the chosen autonomous command
  autonomousCommand.reset(autonomous_chooser.GetSelected());

  // If the chosen command/command group pointer has been intialized...
  if (autonomousCommand.get() != nullptr) {

    // Start the chosen autonomous command
    autonomousCommand->Start();

  } // end if (autonomousCommand.get() != nullptr)

#if ORION_DEBUG

  else {

    // Output a error
    frc::DriverStation::ReportError("autonomousCommand NOT initialized!");

  } // end else (if (autonomousCommand.get() != nullptr))

#endif // #if ORION_DEBUG

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
  
  // If the drive arcade style command pointer has been intialized...
  if(m_cmdDriveArcadeStyle != nullptr) {
    // Start the drive arcade style command
    m_cmdDriveArcadeStyle->Start();
  } // end if(m_cmdDriveArcadeStyle != nullptr)

#if ORION_DEBUG
  else {
    // Output a error
    frc::DriverStation::ReportError("m_cmdDriveArcadeStyle NOT initialized!");
  }
#endif // #if ORION_DEBUG

#if !USE_PID_PSSH

  // If the control Pssh command pointer has been intialized...
  if(m_cmdControlPssh != nullptr) {
    // Start the control Pssh command
    m_cmdControlPssh->Start();
  } // end if(m_cmdControlPssh != nullptr)

#if ORION_DEBUG
  else {
    // Output a error
    frc::DriverStation::ReportError("m_cmdControlPssh NOT initialized!");
  }
#endif // #if ORION_DEBUG

#endif // #if !USE_PID_PSSH

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

  // Create the string to be output containing the version message
  m_RobotCode_version_msg = k_RobotName +
                            k_CodeVersionMessage +
                            k_SW_VersionNumber +
                            k_CodeVersionMessageEnd;

  // and output to the DriveStation as a warning
//  frc::DriverStation::ReportWarning(m_RobotCode_version_msg);

  // and output the version to the console
  printf("%s",&m_RobotCode_version_msg[0]);

} // end outputVersionInfoToConsole()

/****************************** START PROGRAM ********************************/

// If the macro RUNNING_FRC_TESTS is not defined...
#ifndef RUNNING_FRC_TESTS

  /** This is the starting point for the entire robot code. */
  int main(int argc, char** argv) {

    return frc::StartRobot<Robot>();

  } // end main()

#endif // #ifndef RUNNING_FRC_TESTS
