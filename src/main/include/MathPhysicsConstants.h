/** ===========================================================================
 * @file   MathPhysicsConstants.h
 * @brief  This file provides a "one-stop shopping" for mathematical and 
 *         physical constants used in the robot code.
 *         the robot, other than for wiring (see RobotMap.h).
 *
 * COPYRIGHT NOTICES:
 *
 * Copyright (c) 2022 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

// INCLUDE GUARD - see https://en.wikipedia.org/wiki/Include_guard
// If we have not already defined MATHPHYSICSCONSTANTS_H...
#ifndef MATHPHYSICSCONSTANTS_H
// Define MATHPHYSICSCONSTANTS_H
#define MATHPHYSICSCONSTANTS_H

/*************************** Local Header Files *******************************/

/************************** Library Header Files ******************************/

// Define _USE_MATH_DEFINES so we can use constants in <cmath>
#define _USE_MATH_DEFINES

// Include the mathematics library
#include <cmath>

/************************** Angular Constants *********************************/

/** The number of radians in a single revolution */
constexpr double k_radians_per_revolution = 2.0 * M_PI;

/*********************** Mathematical Constants *******************************/

// Trigonometry

/** The number of degrees in a half circle */
constexpr double k_HalfCircleDegrees = 180.0;

/** The number of radians in a half circle */
constexpr double k_HalfCircleRadians = M_PI;

/** Constant to convert degrees to radians */
constexpr double k_DegToRad = k_HalfCircleRadians / k_HalfCircleDegrees;

/** Constant to convert radians to degrees */
constexpr double k_RadToDeg = k_HalfCircleDegrees / k_HalfCircleRadians;

/************************** Physics Constants *********************************/

/** The earth's average acceleration due to gravity, in m/s^2 */
constexpr double k_earth_g_mps2 = 9.80665;

/**************************** Time Constants **********************************/

/** The number of microseconds per millisecond */
constexpr double k_MicrosecondsPerMillisecond = 1000.0;

#endif // #ifndef MATHPHYSICSCONSTANTS_H
