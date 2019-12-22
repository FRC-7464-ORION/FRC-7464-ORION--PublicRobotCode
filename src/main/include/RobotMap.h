/** ===========================================================================
 * @file   RobotMap.h
 * @brief  This file provides a "one-stop shopping" for constants used in
 *         the mapping (wiring) of subsystems to the roboRIO, PDP, etc.
 *
 * The RobotMap is a mapping from the ports, sensors, and actuators that are
 * wired into to a constant variable name. This provides flexibility in
 * changing wiring, makes checking the wiring easier, and significantly
 * reduces the number of magic numbers floating around.
 *
 * In a lot of examples by FRC, you will see subsystems mapped to the roboRIO
 * by actual numbers.
 *
 * For example:
 *
 * @code{.cpp}
 * // The left motor controller is connected to roboRIO PWM port 0
 * frc::PWMVictorSPX m_left{0};
 * // The right motor controller is connected to roboRIO PWM port 1
 * frc::PWMVictorSPX m_right{1};
 * @endcode
 *
 * The above 0 and 1 are sometimes called "magic numbers", because they
 * are "magic" in what they mean, or represent.
 *
 * If we define some constant expressions in this file, such as:
 *
 * @code{.cpp}
 * // The left motor is attached to PWM port #0
 * constexpr int kLeftMotorPWMPort = 0;
 * // The right motor is attached to PWM port #1
 * constexpr int kRightMotorPWMPort = 1;
 * @endcode
 *
 * then the above lines with the "magic" numbers could be rewritten as:
 *
 * @code{.cpp}
 * // The left motor controller is connected to roboRIO
 * //   specified by kLeftMotorPWMPort
 * frc::PWMVictorSPX m_left{kLeftMotorPWMPort};
 * // The right motor controller is connected to roboRIO
 * //   specified by kRightMotorPWMPort
 * frc::PWMVictorSPX m_right{kRightMotorPWMPort};
 * @endcode
 *
 * Using these constants allow us to use the constant variable names
 * everywhere we need to specify a port, sensor, actuator, etc.,
 * IN THE CODE, and have only ONE location that specifies the port,
 * sensor, actuator, etc. that has to be changed if the wiring changes.
 *
 * If you are using multiple modules, make sure to define both the port
 * number and the module. For example, with a rangefinder:
 * @code{.cpp}
 * constexpr int kRangeFinderPort = 1;
 * constexpr int kRangeFinderModule = 1;
 * @endcode
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

// INCLUDE GUARD - see https://en.wikipedia.org/wiki/Include_guard
// If we have not already defined ROBOTMAP_H...
#ifndef ROBOTMAP_H
// Define ROBOTMAP_H
#define ROBOTMAP_H

/*************************** Local Header Files *******************************/

// Include our constants header file
#include "RobotConstants.h"

// **************************** PWM PORTS *************************************

/**
 * The PWM port on the roboRIO for the left drive train motors controller.
 *
 * Note: There are two motors attached to the left side of the drive train:
 *       Motor #0 and Motor #1. Both these motors are driven by the port
 *       specified by @c k_LeftDriveTrainMotorsPWMPort using a PWM Y-cable.
*/
constexpr int k_LeftDriveTrainMotorsPWMPort  = 0;
/**
 * The PWM port on the roboRIO for the right drive train motors controller.
 *
 * Note: There are two motors attached to the right side of the drive train:
 *       Motor #0 and Motor #1. Both these motors are driven by the port
 *       specified by @c k_RightDriveTrainMotorsPWMPort using a PWM Y-cable.
*/
constexpr int k_RightDriveTrainMotorsPWMPort = 1;

// If we are using Tippy Toes...
#if USE_TIPPY_TOES

/**
 * The PWM port on the roboRIO for the Tippy Toes motors controller.
 *
 * Note: There are two motors attached to Tippy Toes:
 *       Motor #0 and Motor #1. Both these motors are driven by the port
 *       specified by @c k_TippyToesMotorsPWMPort using a PWM Y-cable.
*/
constexpr int k_TippyToesMotorsPWMPort = 2;

#endif // #if USE_TIPPY_TOES

/**
 * The PWM port on the roboRIO for the Capt. Hook motor controller.
*/
constexpr int k_CaptHookMotorPWMPort = 3;

// *************************** PDP CHANNELS ************************************

/** The PDP channel number of motor #0 of the left drive train */
constexpr int k_LeftDriveTrainMotor0PDPChannel = 2;
/** The PDP channel number of motor #1 of the left drive train */
constexpr int k_LeftDriveTrainMotor1PDPChannel = 3;

/** The PDP channel number of motor #0 of the right drive train */
constexpr int k_RightDriveTrainMotor0PDPChannel = 13;
/** The PDP channel number of motor #1 of the right drive train */
constexpr int k_RightDriveTrainMotor1PDPChannel = 12;

// If we are using Tippy Toes...
#if USE_TIPPY_TOES

/** The PDP channel number of motor #0 of Tippy Toes */
constexpr int k_TippyToesMotor0PDPChannel = 15;
/** The PDP channel number of motor #1 of Tippy Toes */
constexpr int k_TippyToesMotor1PDPChannel = 14;

#endif // #if USE_TIPPY_TOES

/** The PDP channel number of the motor for Capt. Hook */
constexpr int k_CaptHookMotorPDPChannel = 11;

// *********************** CAN Bus Device IDs **********************************

// Verify CAN bus device IDs with the Phoenix Tuner from CTRE.

/** The PDP CAN bus device ID */
constexpr int k_PDP_CAN_Bus_DeviceID = 0;

/** The PCM CAN bus device ID */
constexpr int k_PCM_CAN_Bus_DeviceID = 1;

// ******************* roboRIO Analog Input Channels **************************

// If we are using Capt. Hook with a PID controller...
#if USE_PID_CAPT_HOOK

/** The analog input channel for Captain Hook's potentiometer */
constexpr int k_CaptHook_Pot_roboRIO_AnalogInChannel = 0;

#endif // #if USE_PID_CAPT_HOOK

// ****************** roboRIO Digital Input Channels **************************

// ********************* roboRIO USB DEVICE NUMBERS ***************************

/** The camera interface device number for the above camera */
constexpr int k_Camera0NameDeviceNumber = 0;

// ***************** DRIVER STATION USB DEVICE NUMBERS ************************

/** The device number of the Logitech controller */
constexpr int k_Joystic0DeviceNumber = 0;

#endif // #ifndef ROBOTMAP_H
