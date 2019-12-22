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
 * Copyright (c) 2019 FRC Team #7464 - ORION. All Rights Reserved.
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

                      /**** VERIFIED BY TESTING ****/

// NOTE: These channels are only valid under the following conditions:
//       1. Switch on bottom is set to X emulator
//       2. In flight mode (mode light on gamepad is off)
//
// http://team358.org/files/programming/ControlSystem2015-2019/images/Logitech-F310_ControlMapping.pdf

/** The left thumbstick X axis channel */
constexpr int k_leftThumbstick_X = 0;
/** The left thumbstick Y axis channel */
constexpr int k_leftThumbstick_Y = 1;

/** The left trigger Y axis channel */
constexpr int k_leftTrigger_Y = 2;
/** The right trigger Y axis channel */
constexpr int k_rightTrigger_Y = 3;

/** The right thumbstick X axis channel */
constexpr int k_rightThumbstick_X = 4;
/** The right thumbstick Y axis channel */
constexpr int k_rightThumbstick_Y = 5;

/** The A button channel */
constexpr int k_A_Button = 1;
/** The B button channel */
constexpr int k_B_Button = 2;

/** The X button channel */
constexpr int k_X_Button = 3;
/** The Y button channel */
constexpr int k_Y_Button = 4;

/** The left rear button channel */
constexpr int k_leftRearButton = 5;
/** The right rear button channel */
constexpr int k_rightRearButton = 6;

                     /**** NOT VERIFIED BY TESTING ****/

/** The "Back" button channel */
constexpr int k_BackButton = 7;
/** The "Start" button channel */
constexpr int k_StartButton = 8;

/** The left thumbstick button */
constexpr int k_leftThumbstickButton = 9;
/** The left thumbstick button */
constexpr int k_rightThumbstickButton = 10;

/*************************** OTHER CONSTANTS ********************************/

/**
 * Used to correct Y axis inversion on joysticks/thumbsticks when used for
 * input into a motor controller.
 *
 * For a motor, the WPI Library expects input for a motor controller to be
 * between -1.0 to +1.0, where +1.0 is the fastest forward speed, and -1.0
 * is the fastest reverse speed.
 *
 * With most joysticks, including the Logitech F310, and using the WPI
 * library, when the joystick/thumbstick is pushed fully away from the
 * user, the output is -1.0. Likewise, when pulled fully toward the user,
 * the output is +1.0. Most users associate going forward with pushing
 * the joystick/thumbstick away from the user. If we use this output
 * from the joystick/thumbstick to directly drive the motors, the
 * motor direction will be reversed. Therefore, we can multiply the
 * Y-axis joystick/thumbstick output by -1.0 to get positive motor
 * speed when the joystick/thumbstick is pushed away from the user.
*/
constexpr double k_CorrectJoystickYAxisMotorSpeedInversion = -1.0;

/** Use the built in squaring of inputs */
constexpr bool k_UseBuiltInSquaring = true;

/** Do NOT use the built in squaring of inputs */
constexpr bool k_DoNOTUseBuiltInSquaring = false;

/************************** UTILITY FUNCTIONS *******************************/

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
