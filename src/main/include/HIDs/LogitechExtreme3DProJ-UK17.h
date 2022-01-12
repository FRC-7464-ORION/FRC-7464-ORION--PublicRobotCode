/** ===========================================================================
 * @file   LogitechExtreme3DProJ-UK17.h
 * @brief  This file declares some constants for the Logitech Extreme 3D Pro,
 *         Model # J-UK17.
 *
 * See the following for some good information:
 * http://team358.org/files/programming/ControlSystem2015-2019/
 *
 * COPYRIGHT NOTICES:
 *
 * Copyright (c) 2020 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

// INCLUDE GUARD - see https://en.wikipedia.org/wiki/Include_guard
// If we have not already defined LOGITECHEXTREME3DPROJ-UK17_H...
#ifndef LOGITECHEXTREME3DPROJ-UK17_H
/** Define LOGITECHEXTREME3DPROJ-UK17_H */
#define LOGITECHEXTREME3DPROJ-UK17_H

/********************* J-UK17 Button/Axis Channel IDs *************************/

// Axis

/** The joystick X axis channel */
constexpr int k_J_UK17_Joystick_X_axis = 0;
/** The joystick Y axis channel */
constexpr int k_J_UK17_Joystick_Y_axis = 1;
/** The joystick Z (rotate) axis channel */
constexpr int k_J_UK17_Joystick_Z_Rotate_axis = 2;
/** The slider (throttle) axis channel */
constexpr int k_J_UK17_slider_axis = 3;

// Buttons

/** The trigger button (button 1) */
constexpr int k_J_UK17_trigger_button_1 = 1;
/** The thumb button (button) 2 */
constexpr int k_J_UK17_thumb_button_2 = 2;
/** Button 3 */
constexpr int k_J_UK17_button_3 = 3;
/** Button 4 */
constexpr int k_J_UK17_button_4 = 4;
/** Button 5 */
constexpr int k_J_UK17_button_5 = 5;
/** Button 6 */
constexpr int k_J_UK17_button_6 = 6;
/** Button 7 */
constexpr int k_J_UK17_button_7 = 7;
/** Button 8 */
constexpr int k_J_UK17_button_8 = 8;
/** Button 9 */
constexpr int k_J_UK17_button_9 = 9;
/** Button 10 */
constexpr int k_J_UK17_button_10 = 10;
/** Button 11 */
constexpr int k_J_UK17_button_11 = 11;
/** Button 12 */
constexpr int k_J_UK17_button_12 = 12;

// POV

/** The value of the center position of the POV */
constexpr int k_J_UK17_POV_Center = -1;
/** The value of the North position of the POV */
constexpr int k_J_UK17_POV_North = 0;
/** The value of the Northeast position of the POV */
constexpr int k_J_UK17_POV_NorthEast = 45;
/** The value of the East position of the POV */
constexpr int k_J_UK17_POV_East = 90;
/** The value of the Southeast position of the POV */
constexpr int k_J_UK17_POV_SouthEast = 135;
/** The value of the South position of the POV */
constexpr int k_J_UK17_POV_South = 180;
/** The value of the Southwest position of the POV */
constexpr int k_J_UK17_POV_SouthWest = 225;
/** The value of the West position of the POV */
constexpr int k_J_UK17_POV_West = 270;
/** The value of the Northwest position of the POV */
constexpr int k_J_UK17_POV_NorthWest = 315;

#endif // #ifndef LOGITECHEXTREME3DPROJ-UK17_H
