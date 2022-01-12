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
 * Copyright (c) 2019-2020 FRC Team #7464 - ORION. All Rights Reserved.
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

/******************************* Constants ************************************/

                  // ***** Software Version Messages *****

/** The version of the software for the robot */
const std::string k_SW_VersionNumber = "v2020.0.0.26";
/** The version of the WPILibC software used */
const std::string k_WPILibC_VersionNumber = "v2020.3.2";
/** The name of the robot */
const std::string k_RobotName = "Oscar Myar";
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

// If we have not defined PSSH_DEBUG already
#ifndef PSSH_DEBUG

  // NOTE: To turn on debug for PSSH code, have the the line
  //       below read (without the quotes) "#define PSSH_DEBUG 1".
  //
  //       To turn off debug for TELEMETRY code, have the the line
  //       below read (without the quotes) "#define PSSH_DEBUG 0".
  //
  //       Generally, for production code, leave debug off.
  //
  // NOTE: If the value of the macro below is changed, it will need to
  //       changed in the Doxyfile doxygen configuration file, in
  //       the preprocessor section "PREDEFINED".

  /** Define PSSH_DEBUG to 0 (debug off), or 1 (debug on) */
  #define PSSH_DEBUG 0

#endif // #ifndef PSSH_DEBUG

// If we have not defined USE_PID_PSSH already
#ifndef USE_PID_PSSH

  // NOTE: To have our code use the PID controller for Pssh,
  //       along with a working potentiometer hooked up, have the below read 
  //       (without the quotes) "#define USE_PID_PSSH 1".
  //
  //       To have our code allow the driver to manually control Pssh
  //       have the below read (without the quotes)
  //       "#define USE_PID_PSSH 0".
  //
  // NOTE: If the value of the macro below is changed, it will need to
  //       changed in the Doxyfile doxygen configuration file, in
  //       the preprocessor section "PREDEFINED".

  /** 
   * Define USE_PID_PSSH to 0 (manual control), 
   * or 1 (using a PID controller and hooked up potentiometer) 
  */
  #define USE_PID_PSSH 1

#endif // #ifndef USE_PID_PSSH

                  // ******** Telemetry Debugging **********

/** The number of whole seconds to wait before logging telemetry 
 *  output time */
constexpr uint64_t k_TelemetryOutputDelaySec = 5ull; 

                  // *********** Time Constants ************

/** The number of microseconds per millisecond */
constexpr double k_MicrosecondsPerMillisecond = 1000.0;

/** The expected times the RobotPeriodic function should run per second */
constexpr uint64_t k_ExpectedRobotTicksPerSecond = 50;

/** The approximate time for a single robot tick, in seconds */
constexpr double k_ApproximateRobotTickTime = 0.02;


                  // ********** Safety Timeouts ************

/** The drive train safety timout, in seconds */
constexpr double k_DriveTrainSafetyTimeout = 0.1;

/** The PAT turner safety timeout, in seconds */
constexpr double k_PATTurnerSafetyTimeout = 0.1;

/** The Pssh safety timeout, in seconds */
constexpr double k_PsshSafetyTimeout = 0.1;

/** The Hans and Franz safety timeout, in seconds */
constexpr double k_HansFranzSafetyTimeout = 0.1;

                  // ********* Command Timeouts ************

/** The command timeout for the drive train command
 *  CmdAutoTurnAngle, in seconds */
constexpr double k_DriveTrain_CmdAutoTurnAngle_Timeout = 5.0;

/** The command timeout for the Pssh command
 * CmdDumpPowerCells, in seconds */
constexpr double k_Pssh_CmdDumpPowerCells_Timeout = 5.0;

/** The command timeout for the Pssh command
 * CmdCollectPowerCells, in seconds */
constexpr double k_Pssh_CmdCollectPowerCells_Timeout = 5.0;

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

/** A constant string to hold the text for driving with Pssh
    up front  */
const std::string k_DriveTrainPsshFrontString = "Pssh";

/** A constant string to hold the text for driving with PAT
    up front  */
const std::string k_DriveTrainPATFrontString = "PAT";

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
constexpr double k_DriveTrainAbsValMaxSpeedNoTurbo = 0.40;
/** The absolute value of the maximum speed allowed to the drive train,
 *  in turbo mode */
constexpr double k_DriveTrainAbsValMaxSpeedTurboOn = 0.60;
/** The exponent used on the joystick to motor curve */
constexpr double k_DriveTrainExponent = 2.25;
/** The decay value d of the IIR DLPF */
constexpr double k_DriveTrain_IIR_DLPF_d = 0.25;

// The PAT turner joystick/motor curve parameters
/** The null zone range on the controller for the PAT turner */
constexpr double k_PATTurnerAbsNullZone = 0.05;
/** The absolute value of the maximum speed allowed to the PAT turner,
 *  in no-turbo mode */
constexpr double k_PATTurnerAbsValMaxSpeedNoTurbo = 0.15;
/** The absolute value of the maximum speed allowed to the PAT turner,
 *  in turbo mode */
constexpr double k_PATTurnerAbsValMaxSpeedTurbo = 0.30;
/** The exponent used on the joystick to motor curve */
constexpr double k_PATTurnerExponent = 2.25;
/** The cutoff point (absolute value) where we switch speeds */
constexpr double k_PATTurnerAbsCutoffPoint = 0.5;
/** The maximum input (absolute value) for PAT */
constexpr double k_PATTurnerAbsMaxInput = 1.0;

// The Pssh joystick/motor curve parameters
/** The null zone range on the controller for the Pssh */
constexpr double k_PsshAbsNullZone = 0.05;
/** The absolute value of the maximum speed allowed to the Pssh,
 *  in non-turbo mode - LEAVE AT 0.22! RML 2020-03-10 */
constexpr double k_PsshAbsValMaxSpeedNoTurbo = 0.22;
/** The exponent used on the joystick to motor curve */
constexpr double k_PsshExponent = 2.25;

// The Hans/Franz arms joystick/motor curve parameters
/** The null zone range on the controller for Hans/Franz arms */
constexpr double k_HansFranzArmsAbsNullZone = 0.05;
/** The absolute value of the maximum speed allowed for Hans/Franz arms,
 *  in non-turbo mode */
constexpr double k_HansFranzArmsAbsValMaxSpeedNoTurbo = 0.10;
/** The exponent used on the joystick to motor curve */
constexpr double k_HansFranzArmsExponent = 2.25;

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

                  // ********** Pssh (PID) ************

/** 
 * The scaling factor for the Pssh potentiometer.
 * The potentiometer we are using is a VEX Robotics potentiometer.
 * Its full range is 250 degrees. So that is the scale factor.
 */
constexpr double k_PsshPotScaleFactor = 250.0;

/**
 * The offset for the Pssh potentiometer. The offset allows
 * a potentiomenter to start at 0 other than the start of the pot turns.
 * 
*/
constexpr double k_PsshPotOffset = -113.0;

/** The name of the Pssh PID */
const std::string k_PsshPIDName = "PIDSubSysPssh";

/** The value for the PID proportional "P" term for Pssh */
constexpr double k_PsshProportionalTerm = 0.005;
/** The value for the PID integral "I" term for Pssh */
constexpr double k_PsshIntegralTerm = 0.0;
/** The value for the PID derivative "D" term for Pssh */
constexpr double k_PsshDerivativeTerm = 0.0;
/** The value for the feedforward term */
constexpr double k_PsshFeedforwardTerm = 0.0;
/** The period (time) between PID calculations, in seconds */
constexpr double k_PsshPID_Period = 0.02;

/** The minimum motor output allowed */
constexpr double k_PsshMinimumOutput = -0.23;
/** The maximum motor output allowed */
constexpr double k_PsshMaximumOutput =  0.23;

/**
 * The minimum expected input to the PID controller, which is the
 * potentimeter output.
 */
constexpr double k_PsshMinimumInput = -5.0;
/**
 * The maximum expected input to the PID controller, which is the
 * potentimeter output.
 */
constexpr double k_PsshMaximumInput = 63.0;

/** The set point for travel mode */
constexpr double k_PsshTravelSetpoint = 0.0;
/** The set point for load mode */
constexpr double k_PsshLoadSetpoint = 32.0;
/** The set point for dump mode */
constexpr double k_PsshDumpSetpoint = 58.0;

/** 
 * The absolute tolerance of our set points, +/-.
 * This means that the value from the potentimeter has to be within
 * this many values. So if the set point is 90, and the absolute
 * tolerance is 5, anywhere from 95 (90+5) to 85 (90-5) should be 
 * recognized as meeting the set point.
*/ 
constexpr double k_PsshAbsoluteTolerance = 1.0;

                  // ********** Pssh Modes **********

/**
 * A constant string to hold the text for Pssh travel mode
*/
const std::string k_PsshTravelString  = "TRAVEL";

/**
 * A constant string to hold the text for Pssh load mode
*/
const std::string k_PsshLoadString  = "LOAD";

/**
 * A constant string to hold the text for Pssh travel mode
*/
const std::string k_PsshDumpString  = "DUMP";

/**
 * A constant string to hold the text for Pssh timed out
 * state.
*/
const std::string k_PsshTimedOutString   = "TIMED OUT";

                  // ********** Hans/Franz Modes **********

/** A constant string to indicate muscles retracted */
const std::string k_HansFranzMusclesStateRetracted = "RETRACTED";

/** A constant string to indicate muscles extended */
const std::string k_HansFranzMusclesStateExtended = "EXTENDED";

/** A constant string to indicate muscles disabled */
const std::string k_HansFranzMusclesStateDisabled = "DISABLED";

/** A constant string to indicate arms retracted */
const std::string k_HansFranzArmsStateRetracted = "RETRACTED";

/** A constant string to indicate arms extended */
const std::string k_HansFranzArmsStateExtended = "EXTENDED";

/** A constant string to indicate arms retracting */
const std::string k_HansFranzArmsStateRetracting = "RETRACTING";

/** A constant string to indicate arms extending */
const std::string k_HansFranzArmsStateExtending = "EXTENDING";

/** A constant string to indicate arms are idle */
const std::string k_HansFranzArmsStateIdle = "IDLE";

/** A constant string to indicate arms are in an unknown state */
const std::string k_HansFranzArmsStateUnknown = "UNKNOWN";

/** A constant string to indicate arms are in an fault state */
const std::string k_HansFranzArmsStateFault = "FAULT";

#endif // #ifndef ROBOTCONSTANTS_H
