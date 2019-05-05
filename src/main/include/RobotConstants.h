/** ===========================================================================
 * @file   RobotConstants.h
 * @brief  This file provides a "one-stop shopping" for constants used in
 *         the robot, other than for wiring (see RobotMap.h).
 *
 * COPYRIGHT NOTICES:
 *
 * Copyright (c) 2019 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

// Preprocessor directive to have this file only be included once in the
//  compilation
// See https://en.wikipedia.org/wiki/Pragma_once for details
#pragma once

/************************** Library Header Files ******************************/

// Include the header file for strings, so we can define strings
#include <string>

/******************************* Constants ************************************/

                  // ***** Software Version Messages *****

/** The version of the software */
const std::string k_SW_VersionNumber = "v2019.1.0.03B1";
/** The name of the robot */
const std::string k_RobotName = "Sirius";
/** The code version message */
const std::string k_CodeVersionMessage = " code version is ";
/** The code version message ending */
const std::string k_CodeVersionMessageEnd = ".\n";

                  // ************** Camera ****************

/** The name of the Microsoft Camera */
const std::string k_Camera0Name = "USB Camera 0";

                  // ********** Capt. Hook Mode ***********

// If we have not defined USE_PID_CAPT_HOOK already
#ifndef USE_PID_CAPT_HOOK

  // NOTE: To have our code use the PID controller for Capt. Hook,
  //       along with a working potentiometer hooked up, have the below read 
  //       (without the quotes) "#define USE_PID_CAPT_HOOK 1".
  //
  //       To have our code allow the driver to manually control Capt.
  //       Hook, have the below read (without the quotes)
  //       "#define USE_PID_CAPT_HOOK 0".
  //

  /** 
   * Define USE_PID_CAPT_HOOK to 0 (manual control), 
   * or 1 (using a PID controller and hooked up potentiometer) 
  */
  #define USE_PID_CAPT_HOOK 0

#endif // #ifndef USE_PID_CAPT_HOOK

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

  /** Define ORION_DEBUG to 0 (debug off), or 1 (debug on) */
  #define ORION_DEBUG 0

#endif // #ifndef ORION_DEBUG

// If we have not defined TELEMETRY_DEBUG already
#ifndef TELEMETRY_DEBUG

  // NOTE: To turn on debug for TELEMETRY code, have the the line
  //       below read (without the quotes) "#define TELEMETRY_DEBUG 1".
  //
  //       To turn off debug for TELEMETRY code, have the the line
  //       below read (without the quotes) "#define TELEMETRY_DEBUG 0".
  //
  //       Generally, for production code, leave debug off.

  /** Define TELEMETRY_DEBUG to 0 (debug off), or 1 (debug on) */
  #define TELEMETRY_DEBUG 0

#endif // #ifndef TELEMETRY_DEBUG

// If we have not defined CAPT_HOOK_DEBUG already
#ifndef CAPT_HOOK_DEBUG

  // NOTE: To turn on debug for CAPT_HOOK code, have the the line
  //       below read (without the quotes) "#define CAPT_HOOK_DEBUG 1".
  //
  //       To turn off debug for CAPT_HOOK code, have the the line
  //       below read (without the quotes) "#define CAPT_HOOK_DEBUG 0".
  //
  //       Generally, for production code, leave debug off.

  /** Define CAPT_HOOK_DEBUG to 0 (debug off), or 1 (debug on) */
  #define CAPT_HOOK_DEBUG 0

#endif // #ifndef CAPT_HOOK_DEBUG

                  // ********** Safety Timeouts ************

/** The drive train safety timout, in seconds */
constexpr double k_DriveTrainSafetyTimeout = 0.1;
/** The Capt. Hook safety timout, in seconds */
constexpr double k_CaptHookSafetyTimeout = 0.1;

                  // ********* Command Timeouts ************

// If we are using Capt. Hook with a PID controller...
#if USE_PID_CAPT_HOOK

/** 
 * The time that we will timeout the grab or release hatch panel 
 * command, in seconds
*/
constexpr double k_CaptHookGrabOrReleaseHatchPanelTimeout = 2.0;

#endif // #if USE_PID_CAPT_HOOK

                  // *********** Motor Speeds **************

/** The speed to stop motors */
constexpr double k_MotorStopSpeed = 0.0;

                  // ********** Drive Train Modes **********

/** A constant string to hold the text for arcade mode */
const std::string k_DriveTrainArcadeModeString = "ARCADE";

/** A constant string to hold the text for tank mode */
const std::string k_DriveTrainTankModeString = " TANK ";

                  // ******** Joystick/Motor Curves ********

// The joystick/motor curve parameters should make it easier to control
// motors with a joystick and/or thumbstick and/or other variable 
// control (such as the triggers on some controllers).
//
// Here is what each parameter means/does:
//
// Null Zone: Sometimes called deadzone. Any absolute value output from the
//            joystick/thumbstick/trigger/etc. that is less than the
//            null zone value will translate into zero output onto a motor.
//            This keeps the motor from "jittering", especially if the 
//            output of the controller is noisy (or a nervous driver ;-).
//
//            Typical values for a null zone are from 0.0 to 0.2.
//            The null zone cannot exceed 1.0 (nothing will work!).
//
// Max Speed: This is the maximum speed that the motor will output
//            (either forward or reverse). Any absolute value output from the
//            joystick/thumbstick/trigger/etc. that is greater than the
//            maximum speed will be limited to the maximum speed
//            (either forward or reverse).
//
//            Set the maximum speed to the percentage of full speed desired.
//            For example, to limit the motor to half speed, set max speed
//            to 50% (0.50). Similar to the null zone, don't see the
//            max speed to 0.0, or again nothing will work!
//
// Exponent:  This is the exponent of a curve used on the joystick input
//            to motor output mapping. Its intent is to make the motor more
//            responsive at lower speeds, at the loss of fine control
//            at higher speeds. An exponent of 1.0 makes the output
//            linear (like a straight line). Higher exponents provide 
//            for better control at lower speeds, but sacrifice control
//            at higher speeds.
//
//            You'll typically want the exponent to be between 2.0-4.0.
//            Anything past 5.0 will result in an uncontrollable robot!
//            Do not use an exponent less than 1.0. The math breaks
//            down, and we may open a rift to another universe.
//
// See the SW_Design repository, and look at NewThumbsticksOutputs.xlsx
// for some graphs.

// The drive train joystick/motor curve parameters
/** The null zone range on the controller for the drive train */
constexpr double k_DriveTrainAbsNullZone = 0.05;
/** The absolute value of the maximum speed allowed to the drive train */
constexpr double k_DriveTrainAbsValMaxSpeed = 0.70;
/** The exponent used on the joystick to motor curve */
constexpr double k_DriveTrainExponent = 2.25;

// If we are not using the PID controller for Capt. Hook
#if !USE_PID_CAPT_HOOK

// Capt. Hook joystick/motor curve parameters
/** The null zone range on the controller for Capt. Hook */
constexpr double k_CaptHookAbsNullZone = 0.05;
/** The absolute value of the maximum speed allowed to Capt. Hook */
constexpr double k_CaptHookAbsValMaxSpeed = 0.40;
/** The exponent used on the joystick to motor curve for Capt. Hook */
constexpr double k_CaptHookExponent = 2.25;

#endif // #if !USE_PID_CAPT_HOOK

// If we are using Capt. Hook with a PID controller...
#if USE_PID_CAPT_HOOK

                  // ********** Capt. Hook (PID) ************

/** 
 * The scaling factor for the Capt. Hook potentiometer.
 * The potentiometer we are using is a VEX Robotics potentiometer.
 * Its full range is 270 degrees. So that is the scale factor.
 */
constexpr double k_CaptHookPotScaleFactor = 270.0;

/**
 * The offset for the Capt. Hook potentiometer. The offset allows
 * a potentiomenter to start at 0 other than the start of the pot turns.
 * 
*/
constexpr double k_CaptHookPotOffset = -40.0;

/** The name of the Capt. Hook PID */
const std::string k_CaptHookPIDName = "PIDSubSysCaptHook";

/** The value for the PID proportional "P" term for Capt. Hook */
constexpr double k_CaptHookProportionalTerm = 0.2;
/** The value for the PID integral "I" term for Capt. Hook */
constexpr double k_CaptHookIntegralTerm = 0.0;
/** The value for the PID derivative "D" term for Capt. Hook */
constexpr double k_CaptHookDerivativeTerm = 0.0;
/** The value for the feedforward term */
constexpr double k_CaptHookFeedforwardTerm = 0.0;
/** The period (time) between PID calculations, in seconds */
constexpr double k_CaptHookPID_Period = 0.05;

/**
 * The minimum expected input to the PID controller, which is the
 * potentimeter output.
 */
constexpr double k_CaptHookMinimumInput = 70.0;
/**
 * The maximum expected input to the PID controller, which is the
 * potentimeter output.
 */
constexpr double k_CaptHookMaximumInput = 210.0;

/** The minimum output allowed on the output */
constexpr double k_CaptHookMinimumOutput = -0.5;
/** The maximum output allowed on the output */
constexpr double k_CaptHookMaximumOutput =  0.5;

/** The set point for grabbing a hatch panel */
constexpr double k_CaptHookGrabHatchpanelSetpoint = 80.0;
/** The set point for releasing a hatch panel */
constexpr double k_CaptHookReleaseHatchpanelSetpoint = 200.0;

/** 
 * The absolute tolerance of our set points, +/-.
 * This means that the value from the potentimeter has to be within
 * this many values. So if the set point is 90, and the absolute
 * tolerance is 5, anywhere from 95 (90+5) to 85 (90-5) should be 
 * recognized as meeting the set point.
*/ 
constexpr double k_CaptHookAbsoluteTolerance = 2.5;

/**
 * A constant string to hold the text for Capt. Hook released
 * state.
*/
const std::string k_CaptHookReleasedString  = "RELEASED";

/**
 * A constant string to hold the text for Capt. Hook releasing
 * state.
*/
const std::string k_CaptHookReleasingString = "RELEASING";

/**
 * A constant string to hold the text for Capt. Hook grabbed
 * state.
*/
const std::string k_CaptHookGrabbedString   = " GRABBED ";

/**
 * A constant string to hold the text for Capt. Hook grabbing
 * state.
*/
const std::string k_CaptHookGrabbingString  = "GRABBING";

/**
 * A constant string to hold the text for Capt. Hook unknown
 * state.
*/
const std::string k_CaptHookUnknownString   = "UNKNOWN";

/**
 * A constant string to hold the text for Capt. Hook timed out
 * state.
*/
const std::string k_CaptHookTimedOutString   = "TIMED OUT";

#endif // #if USE_PID_CAPT_HOOK
