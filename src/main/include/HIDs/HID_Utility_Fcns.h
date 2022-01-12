/** ===========================================================================
 * @file   HID_Utility_Fcns.h
 * @brief  This file declares some utility functions used with human interface
 * devices (HIDs).
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
// If we have not already defined HID_UTILITY_FCNS_H...
#ifndef HID_UTILITY_FCNS_H
// Define HID_UTILITY_FCNS_H
#define HID_UTILITY_FCNS_H

/**
 * A function to correct the Y axis from the joystick/thumbstick to give
 * the expected direction. See k_CorrectJoystickYAxisMotorSpeedInversion
 * for a detailed explanation.
*/
double Correct_Y_Axis_Inversion(double y_axis);

/**
 * A method to provide a null zone, make the joystick/thumbstick less
 * sensitive, and provide a hard absolute limit when using the 
 * joystick/thumbstick to control a motor.
 *
 * @param joyout       The output of a joystick (thumbstick), which is
 *                     expected to be between -1.0 and +1.0
 *
 * @param abs_nullzone The absolute value of the null zone. A positive
 *                     number only. This will need to be a small
 *                     number between 0.0 and 1.0, probably no more
 *                     than 0.25. This will provide a null (dead) zone
 *                     between joystick/thumbstick outputs that range
 *                     between -abs_nullzone and +abs_nullzone.
 * 
 * @param abs_limit    The absolute value of the limit applied to the
 *                     motor. A positive number only. This will be
 *                     a number between 0.0 and 1.0, probably no less
 *                     than 0.5. This will limit the output of the motor
 *                     to be no greater than +abs_limit, and no less
 *                     than -abs_limit.
 * 
 * @param exponent     The exponent applied to the function to
 *                     curve the output. A positive number only, at a
 *                     value of 1 or higher. The larger the exponent,
 *                     the more sensitive the controller at low speeds,
 *                     but with less sensitivity at higher speeds.
 * 
 * @return             A motor controller output value that has been
 *                     nulled, desensitized, and limited.
*/
double NullDesensLimit(double joyout,
                       double abs_nullzone,
                       double abs_limit,
                       double exponent);

#endif // #ifndef LOGITECHF310_H
