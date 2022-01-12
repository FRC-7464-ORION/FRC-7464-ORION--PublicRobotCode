/** ===========================================================================
 * @file   HID_Constants.h
 * @brief  This file declares some constants for human interface devices
 * (HIDs).
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
// If we have not already defined HID_CONSTANTS_H...
#ifndef HID_CONSTANTS_H
// Define HID_CONSTANTS_H
#define HID_CONSTANTS_H

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

#endif // #ifndef HID_CONSTANTS_H
