/** ===========================================================================
 * @file   RobotConstants.h
 * @brief  This file provides a "one-stop shopping" for constants used in
 *         the robot, other than for wiring (see RobotMap.h).
 *
 *         It is generally a good idea to place constants into subsystem- or
 *         command-specific namespaces within this header, which can then be
 *         used where they are needed.
 * 
 * COPYRIGHT NOTICES:
 *
 * Copyright (c) 2019-2022 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

// INCLUDE GUARD - see https://en.wikipedia.org/wiki/Include_guard
// If we have not already defined ROBOTCONSTANTS_H...
#ifndef ROBOTCONSTANTS_H
// Define ROBOTCONSTANTS_H
#define ROBOTCONSTANTS_H

/*************************** Local Header Files *******************************/

/************************** Library Header Files ******************************/

// Include the header file for strings, so we can define strings
#include <string>

// Include the header file for time units
#include <units/time.h>

// Include the header file for distance units
#include <units/length.h>

// Include the header file for angles
#include <units/angle.h>

/******************************* Constants ************************************/

                  // ***** Software Version Messages *****

/** The version of the software for the robot */
const std::string k_SW_VersionNumber = "v2022.0.0.28";
/** The version of the WPILibC software used */
const std::string k_WPILibC_VersionNumber = "v2022.3.1";
/** The version of the NavX MXP software used */
const std::string k_navx_frc_VersionNumber = "v4.0.442";
/** The version of the REV Robotics library used */
const std::string k_REVLib_VersionNumber = "v2022.1.1";
/** The name of the robot */
const std::string k_RobotName = "Janky";
/** The code version message */
const std::string k_CodeVersionMessage = " code version is ";
/** The code version message ending */
const std::string k_CodeVersionMessageEnd = ".\n";

                  // ************** Camera ****************

/** The name of the front Microsoft Camera */
const std::string k_FrontCamera = "Front Camera 0";

/** The name of the back Microsoft Camera */
const std::string k_BackCamera = "Back Camera 1";

/** The name of the camera server */
const std::string k_CameraServer = "Switched Camera Server";

                  // ************* Debugging ***************

// If we have not defined ORION_DEBUG already
#ifndef ORION_DEBUG

  // NOTE: To turn on debug for ORION code, have the the line
  //       below read (without the quotes) "#define ORION_DEBUG 1".
  //
  //       To turn off debug for ORION code, have the the line
  //       below read (without the quotes) "#define ORION_DEBUG 0".
  //
  //       Generally, for production code, leave debug off.
  //
  // NOTE: If the value of the macro below is changed, it will need to
  //       changed in the Doxyfile doxygen configuration file, in
  //       the preprocessor section "PREDEFINED".

  /** Define ORION_DEBUG to 0 (debug off), or 1 (debug on) */
  #define ORION_DEBUG 0

#endif // #ifndef ORION_DEBUG

                  // ******** Telemetry Debugging **********

/** The number of whole seconds to wait before logging telemetry 
 *  output time */
constexpr uint64_t k_TelemetryOutputDelaySec = 5ull; 

                  // *********** Time Constants ************

/** The expected times the RobotPeriodic function should run per second */
constexpr uint64_t k_ExpectedRobotTicksPerSecond = 50;

/** The approximate time for a single robot tick, in seconds */
const auto k_ApproximateRobotTickTime = 0.02_s;


                  // ********** Safety Timeouts ************

/** The drive train safety timout, in seconds */
const auto k_DriveTrainSafetyTimeout = 0.1_s;

/** The intake motor safety timeout, in seconds */
const auto k_IntakeMotorSafetyTimeout = 0.1_s;

/** The left indexer motor safety timeout, in seconds */
const auto k_LeftIndexerMotorSafetyTimeout = 0.1_s;

/** The right indexer motor safety timeout, in seconds */
const auto k_RightIndexerMotorSafetyTimeout = 0.1_s;

/** The shooter motor safety timeout, in seconds */
const auto k_ShooterMotorSafetyTimeout = 0.1_s;

                  // ********* Command Timeouts ************

/** The command timeout for the drive train command
 *  CmdAutoTurnAngle, in seconds */
const auto k_DriveTrain_CmdAutoTurnAngle_Timeout = 5.0_s;

                  // ***** Command Interruptability ********

/** The command can be interrupted */
constexpr double k_CmdIsInterruptable = true;

/** The command can NOT be interrupted */
constexpr double k_CmdIsNOTInterruptable = false;

                  // *********** Motor Speeds **************

/** The speed to stop motors */
constexpr double k_MotorStopSpeed = 0.0;

/** The multiplier for going in reverse */
constexpr double k_ReverseSpeedMultiplier = -1.0;

                  // *********** Axis Values ***************

/** The X-axis value for going straight */
constexpr double k_X_Axis_Value_For_Straight = 0.0;

/** The Y-axis value for turning */
constexpr double k_Y_Axis_Value_For_Turn = 0.0;

                  // ********** Drive Train Modes **********

/** A constant string to hold the text for arcade mode */
const std::string k_DriveTrainArcadeModeString = "ARCADE";

/** A constant string to hold the text for tank mode */
const std::string k_DriveTrainTankModeString   = " TANK ";

/** A constant string to hold the text for turbo mode on */
const std::string k_DriveTrainTurboModeOnString  = " ON ";

/** A constant string to hold the text for turbo mode off */
const std::string k_DriveTrainTurboModeOffString = "OFF ";

/** A constant string to hold the text for smoothing mode on */
const std::string k_DriveTrainSmoothingModeOnString  = " ON ";

/** A constant string to hold the text for smoothing mode off */
const std::string k_DriveTrainSmoothingModeOffString = "OFF ";

/** A constant string to hold the text for driving with the
    intake up front  */
const std::string k_DriveTrainIntakeFrontString = "Intake";

/** A constant string to hold the text for driving with the
    shooter up front  */
const std::string k_DriveTrainShooterFrontString = "Shooter";

                  // ******** Drivetrain Flags ********

/** Indicate that the right side of the drive train is to be inverted */
const bool k_DriveTrainRightSideIsInverted = true;

/** Indicate that the right side of the drive train is NOT to be inverted */
const bool k_DriveTrainRightSideIsNOTInverted = false;

                  // ******** Joystick/Motor Curves ********

// The joystick/motor curve parameters should make it easier to control
// motors with a joystick and/or thumbstick and/or other variable 
// control (such as the triggers on some controllers).
//
// Here is what each constant/parameter means/does:
//
// Null Zone:  Sometimes called deadzone. Any absolute value output from the
//             joystick/thumbstick/trigger/etc. that is less than the
//             null zone value will translate into zero output onto a motor.
//             This keeps the motor from "jittering", especially if the
//             output of the controller is noisy (or a nervous driver ;-).
//
//             Typical values for a null zone are from 0.0 to 0.2.
//             The null zone cannot exceed 1.0 (nothing will work!).
//
//             Constant name: k_DriveTrainAbsNullZone
//
// Max Speed:  This is the maximum speed that the motor will output
// (turbo off) (either forward or reverse) in non-turbo mode.
//             Any absolute value output from the
//             joystick/thumbstick/trigger/etc. that is greater than the
//             maximum speed will be limited to the maximum speed
//             (either forward or reverse) defined by this constant
//             parameter.
//
//             Set the maximum speed to the percentage of full speed desired.
//             For example, to limit the motor to half speed, set max speed
//             to 50% (0.50). Similar to the null zone, don't set the
//             max speed to 0.0, or again nothing will work!
//
//             Constant name: k_DriveTrainAbsValMaxSpeedNoTurbo
//
// Max Speed:  This is the maximum speed that the motor will output
// (turbo on)  (either forward or reverse) in turbo mode.
//             Any absolute value output from the
//             joystick/thumbstick/trigger/etc. will be multiplied
//             by the ratio of max_speed_turbo_on to
//             max_speed_turbo_off. By using this ratio, the maximum
//             speed will be limited to the maximum turbo speed, but
//             providing boosted speed at all other speeds as well.
//
//             Constant name: k_DriveTrainAbsValMaxSpeedTurboOn 
//
// Exponent:   This is the exponent of a curve used on the joystick input
//             to motor output mapping. Its intent is to make the motor more
//             responsive at lower speeds, at the loss of fine control
//             at higher speeds. An exponent of 1.0 makes the output
//             linear (like a straight line). Higher exponents provide
//             for better control at lower speeds, but sacrifice control
//             at higher speeds.
//
//             You'll typically want the exponent to be between 2.0-4.0.
//             Anything past 5.0 will result in an uncontrollable robot!
//             Do not use an exponent less than 1.0. The math breaks
//             down, and we may open a rift to another universe.
//
//             Constant name: k_DriveTrainExponent
//
// d:          This is the delay value of an infinite impulse response (IIR)
//             digital low pass filter (DLPF). Its intent is to make the motor
//             output less "jerky" (i.e. more smooth) over time, at the
//             expense of introducing some delay from the joystick input
//             to the motor output.
//
//             The value d must be constrained to 0.00 <= d <= 1.00.
//
//             As the value of d decreases, the more smoothing (but more
//             delay) is introduced. As d increases, less delay and
//             less smoothing is used.
//
//             NOTE: Motor controllers for the drive train should be
//                   put in "BRAKE" mode, and not in "COAST" mode for
//                   this to work properly.
//
//             For more information about IIR DLP filters, and how they
//             belong to a branch of engineering mathematics called
//             Digital Signal Processing (DSP), see the following:
//
//             https://en.wikipedia.org/wiki/Digital_signal_processing
//             https://en.wikipedia.org/wiki/Infinite_impulse_response
//             https://www.dsprelated.com/freebooks/filters/Introduction.html
//             https://www.embedded.com/design/configurable-systems/4025591/Digital-filtering-without-the-pain
//
//             Constant name: k_DriveTrain_IIR_DLPF_d
//
// See the SW_Design repository, and look at NewThumbsticksOutputs.xlsx
// and IIR_DLPF.xlsx for some graphs that illustrate these concepts.

// The drive train joystick/motor curve parameters
/** The null zone range on the controller for the drive train */
constexpr double k_DriveTrainAbsNullZone = 0.05;
/** The absolute value of the maximum speed allowed to the drive train,
 *  in non-turbo mode */
constexpr double k_DriveTrainAbsValMaxSpeedNoTurbo = 0.60;
/** The absolute value of the maximum speed allowed to the drive train,
 *  in turbo mode */
constexpr double k_DriveTrainAbsValMaxSpeedTurboOn = 0.80;
/** The exponent used on the joystick to motor curve */
constexpr double k_DriveTrainExponent = 2.25;
/** The decay value d of the IIR DLPF */
constexpr double k_DriveTrain_IIR_DLPF_d = 0.25;

                  // ****** DIO Constants ******

/** The value returned when using an open switch on digital input with 
 *  a pullup resistor (DIO 0..9 on DIO, DIO 0..15 on MXP)  */
constexpr bool k_DigitalInputPullUpSwitchOpen = true;

/** The value returned when using an close switch on digital input with 
 *  a pullup resistor (DIO 0..9 on DIO, DIO 0..15 on MXP)  */
constexpr bool k_DigitalInputPullUpSwitchClosed = false;

                  // ****** Counter Constants ******

/** The value of a counter when it is reset */
constexpr int k_CounterResetValue = 0;

                  // ****** IMU PID Variables ******

// Autonomous Turn using NavX IMU PIDS Variables

/** The Autonomous Turn Proportional coefficient */
constexpr double k_AutoTurn_Proportional     = 0.03;

/** The Autonomous Turn Integral coefficient */
constexpr double k_AutoTurn_Integral         = 0.00;

/** The Autonomous Turn Derivative coefficient */
constexpr double k_AutoTurn_Derivative       = 0.00;

/** The Autonomous Turn Feed-forward coefficient */
constexpr double k_AutoTurn_FeedForward      = 0.00;

/** The Autonomous Turn tolerance (how close we have to get
 *  to the target before we consider us close enough),
 *  in degrees */
constexpr double k_AutoTurn_ToleranceDegrees = 2.0;

/** The minimum value expected from the AHRS GetAngle() */
constexpr double k_AutoTurn_Min_Val_Expected = -180.0;

/** The maximum value expected from the AHRS GetAngle() */
constexpr double k_AutoTurn_Max_Val_Expected = 180.0;

                  // ***** Compressor Variables *****
/** 
 * Used to set the closed loop control for the compressor to be
 * automatically controlled.
*/
constexpr bool k_CompressorAutomaticallyControlled=true;

/** 
 * Used to set the closed loop control for the compressor to be
 * manually controlled.
*/
constexpr bool k_CompressorManuallyControlled=false;

                  // ***** Ball Shooter State Strings *****

/** A constant string to hold the text for unknown state */
const std::string k_BallShooterStateUnknownString = "UNKNOWN";

/** A constant string to hold the text for fault state */
const std::string k_BallShooterStateFaultString = "FAULT";

/** A constant string to hold the text for the at rest state */
const std::string k_BallShooterStateAtRestString = "AT REST";

/** A constant string to hold the text for the intake state */
const std::string k_BallShooterStateIntakingString = "INTAKING";

/** A constant string to hold the text for the shooting low state */
const std::string k_BallShooterStateShootingLowString = "SHOOTING LOW";

/** A constant string to hold the text for the shooting high state */
const std::string k_BallShooterStateShootingHighString = "SHOOTING HI";

                  // ***** Ball Shooter Motor Speeds *****

/** The speed for the intake motor */
constexpr double k_BallShooterIntakeMotorSpeed = -0.99;

/**
 *  The magnitude speed for the indexer motors. 
 *  (left and right must always have the same absolute vale,
 *  but opposite in sign, i.e. +0.5 and -0.5 )
*/
constexpr double k_BallShooterIndexerMotorSpeed = -0.50;

/** The speed for the ball shooter when shooting low.
 *  (This is just temporary, as we should change the speed later on,
 *  based on how far from target, shooting high or low, etc.)
*/
constexpr double k_BallShooterShooterMotorLowSpeed = 0.50;

/** The speed for the ball shooter when shooting high.
 *  (This is just temporary, as we should change the speed later on,
 *  based on how far from target, shooting high or low, etc.)
*/
constexpr double k_BallShooterShooterMotorHighSpeed = 0.50;

// RAMP CONSTANTS

/** The angle of the ramp with respect to the floor at the departure point,
 *  in degrees */
const double k_RampDepartureAngle = 78.0;

/** The height of the ramp at the departure point, in meters */
const double k_RampDepartureHeight = 0.55;

// TARGET DISTANCES

/** Height from the floor of the top of the top target, in meters */
const double k_TopofTopTargetHeightFromFloor = 2.641;

/** 
 * Horizontal Distance from the center of the top and bottom targets
 * from the Rapid React wall, in meters
*/
const double k_CenterofTopBottomTargetDistanceFromReactWall = 0.925;

/** Height from floor of the bottom of the top target, in meters */
const double k_BottomofTopTargetHeightFromFloor = 1.661;

/** Height from the floor of the top of the bottom target, in meters */
const double k_TopofBottomTargetHeight = 1.042;

/** 
 * The horizontal distance from the front of the ramp to the back of
 *   the ultrasonic sensor, in meters 
*/
const double k_RampPositionRelativeToUltrasonic_x0 = 0.03;

/** 
 * The vertical distance from the top of the ramp to the floor,
 *    in meters
*/
const double k_RampPositionRelativeToFloor_y0 = 0.57;

/** Nominal 5V Power Supply Voltage */
const double k_Nominal_5V_Voltage = 5.0;

/** 
 * Conversion Factor for converting 0-4095 (12 bit) count to centimeters.
 *  See https://www.maxbotix.com/firstrobotics.
 */
const double k_MB10X3_ConversionFactor = 0.125;

/** 
 * The diameter of the shooter wheels, in meters.
 * 
 * Note: 2" = 0.0508 m
*/
const double k_Shooter_Wheel_Diam_m = 0.0508;

#endif // #ifndef ROBOTCONSTANTS_H