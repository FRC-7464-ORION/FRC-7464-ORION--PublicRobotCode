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
 * Copyright (c) 2019-2020 FRC Team #7464 - ORION. All Rights Reserved.
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

/************************** Library Header Files ******************************/

// Include the SPI header file
#include <frc/SPI.h>

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

/** The PWM port for PAT's turner */
constexpr int k_PATTurnerMotorPWMPort = 2;

/** The PWM port for Pssh's motor */
constexpr int k_PsshMotorPWMPort = 3;

/** The PWM port for Hans' and Franz's arms motor */
constexpr int k_HansFranzArmsPWMPort = 4;

// **************************** MXP PORTS **************************************

/** The NavX MXP is using the SPI on the MXP */
const frc::SPI::Port k_navx_mxp_imu_port = frc::SPI::Port::kMXP;

// *********************** CAN Bus Device IDs **********************************

// Verify CAN bus device IDs with the Phoenix Tuner from CTRE.

/** The PDP CAN bus device ID */
constexpr int k_PDP_CAN_Bus_DeviceID = 0;

/** The Primary PCM CAN bus device ID */
constexpr int k_PrimaryPCM_CAN_Bus_DeviceID = 1;

// *************************** PDP CHANNELS ***********************************

/** The PDP channel number of motor #0 of the left drive train */
constexpr int k_LeftDriveTrainMotor0PDPChannel = 2;
/** The PDP channel number of motor #1 of the left drive train */
constexpr int k_LeftDriveTrainMotor1PDPChannel = 3;

/** The PDP channel number of motor #0 of the right drive train */
constexpr int k_RightDriveTrainMotor0PDPChannel = 13;
/** The PDP channel number of motor #1 of the right drive train */
constexpr int k_RightDriveTrainMotor1PDPChannel = 12;

/** The PDP channel number of the motor for PAT Turner */
constexpr int k_PATTurnerMotorPDPChannel = 1;

/** The PDP channel number of the motor for Pssh */
constexpr int k_PsshMotorPDPChannel = 14;

/** The PDP channel number for the Hans/Franz arms motor */
constexpr int k_HansFranzArmsMotorChannel = 15;

// *********************** PRIMARY PCM CHANNELS *******************************

/** The primary PCM channel for Hans muscle extend */
constexpr int k_HansExtendMuscleChannel=0;

/** The primary PCM channel for Hans muscle retract */
constexpr int k_HansRetractMuscleChannel=1;

/** The primary PCM channel for Franz muscle extend */
constexpr int k_FranzExtendMuscleChannel=2;

/** The primary PCM channel for Franz muscle retract */
constexpr int k_FranzRetractMuscleChannel=3;

// ******************* roboRIO Analog Input Channels **************************

/** The analog input channel for Pssh's potentiometer */
constexpr int k_Pssh_Pot_roboRIO_AnalogInChannel = 0;

// ****************** roboRIO Digital Input Channels **************************

/** The DIO channel for the Hans/Franz arms fully retracted limit switch */
constexpr int k_HansFranzArms_FullyRetracted_LimitSwitch_Channel = 0;

/** The DIO channel for the Hans/Franz arms fully extended limit switch */
constexpr int k_HansFranzArms_FullyExtended_LimitSwitch_Channel = 1;

// ********************* roboRIO USB DEVICE NUMBERS ***************************

/** The camera interface device number for the front camera */
constexpr int k_FrontCameraDeviceNumber = 0;

/** The camera interface device number for the front camera */
constexpr int k_BackCameraDeviceNumber = 1;

// ***************** DRIVER STATION USB DEVICE NUMBERS ************************

/** The device number of the primary controller */
constexpr int k_Joystick0DeviceNumber = 0;

/** The device number of the secondary Logitech controller */
constexpr int k_Joystick1DeviceNumber = 1;

#endif // #ifndef ROBOTMAP_H
