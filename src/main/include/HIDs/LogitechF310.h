/** ===========================================================================
 * @file   LogitechF310.h
 * @brief  This file declares some constants for the Logitech F310.
 *
 * See:
 * http://team358.org/files/programming/ControlSystem2015-2019/images/Logitech-F310_ControlMapping.pdf
 *
 * Also see the following for some good information:
 * http://team358.org/files/programming/ControlSystem2015-2019/
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
// If we have not already defined LOGITECHF310_H...
#ifndef LOGITECHF310_H
// Define LOGITECHF310_H
#define LOGITECHF310_H

/********************** F310 Button/Axis Channel IDs **************************/

// NOTE: These channels are only valid under the following conditions:
//       1. Switch on bottom of controller is set to X emulator
//       2. In flight mode (mode light on gamepad is off)
//
// http://team358.org/files/programming/ControlSystem2015-2019/images/Logitech-F310_ControlMapping.pdf

// Axis

/** The left thumbstick X axis channel */
constexpr int k_F310_leftThumbstick_X_axis = 0;
/** The left thumbstick Y axis channel */
constexpr int k_F310_leftThumbstick_Y_axis = 1;

/** The left trigger Y axis channel */
constexpr int k_F310_leftTrigger_Y_axis = 2;
/** The right trigger Y axis channel */
constexpr int k_F310_rightTrigger_Y_axis = 3;

/** The right thumbstick X axis channel */
constexpr int k_F310_rightThumbstick_X_axis = 4;
/** The right thumbstick Y axis channel */
constexpr int k_F310_rightThumbstick_Y_axis = 5;

// Buttons

/** The A button channel */
constexpr int k_F310_A_Button = 1;
/** The B button channel */
constexpr int k_F310_B_Button = 2;

/** The X button channel */
constexpr int k_F310_X_Button = 3;
/** The Y button channel */
constexpr int k_F310_Y_Button = 4;

/** The left rear button channel */
constexpr int k_F310_leftRearButton = 5;
/** The right rear button channel */
constexpr int k_F310_rightRearButton = 6;

/** The "Back" button channel */
constexpr int k_F310_BackButton = 7;
/** The "Start" button channel */
constexpr int k_F310_StartButton = 8;

/** The left thumbstick button */
constexpr int k_F310_leftThumbstickButton = 9;
/** The right thumbstick button */
constexpr int k_F310_rightThumbstickButton = 10;

// POV

/** The number ID of this POV on the F310 */
constexpr int k_F310_POV_ID=0;

/** The value of the center position of the POV */
constexpr int k_F310_POV_Center = -1;
/** The value of the North position of the POV */
constexpr int k_F310_POV_North = 0;
/** The value of the Northeast position of the POV */
constexpr int k_F310_POV_NorthEast = 45;
/** The value of the East position of the POV */
constexpr int k_F310_POV_East = 90;
/** The value of the Southeast position of the POV */
constexpr int k_F310_POV_SouthEast = 135;
/** The value of the South position of the POV */
constexpr int k_F310_POV_South = 180;
/** The value of the Southwest position of the POV */
constexpr int k_F310_POV_SouthWest = 225;
/** The value of the West position of the POV */
constexpr int k_F310_POV_West = 270;
/** The value of the Northwest position of the POV */
constexpr int k_F310_POV_NorthWest = 315;

#endif // #ifndef LOGITECHF310_H
