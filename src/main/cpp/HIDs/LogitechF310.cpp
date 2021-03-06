/** ===========================================================================
 * @file   LogitechF310.cpp
 * @brief  This file hosts some utility functions for the Logitech F310.
 *
 * This file hosts some utility functions for the Logitech F310.
 * It is currently not part of a class.
 *
 * COPYRIGHT NOTICES:
 *
 * Copyright (c) 2019 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// Include the header file for the Logitech F310
#include "HIDs/LogitechF310.h"

/************************** Library Header Files ******************************/

// Include the header for common mathematical functions
#include <cmath>

/**************************** Utility Functions *******************************/

// Correct the Y axis joystick/thumbstick inversion
double Correct_Y_Axis_Inversion(double y_axis) {

    // Return the y axis multiplied by our correction factor
    return y_axis * (k_CorrectJoystickYAxisMotorSpeedInversion);

} // end Correct_Y_Axis_Inversion(double)

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
double NullDesensLimit(double joyout, double abs_nullzone,
                       double abs_limit, double exponent) {
    
    // Used with copysign to get the sgn function
    const double sgn_value = 1.0;
    // Factor x. What is it? It's below!
    double factorx;
    // The unlimited output
    double unlimited_output;
    
    // If we are within the null zone...
    if( fabs(joyout) < abs_nullzone ) {

      // return 0
      return 0.0;

    } // end if( fabs(joyout) < abs_nullzone )

    else { // We are not within the null zone

      // Calculate factor x, a part of the unlimited output term
      factorx = joyout - abs_nullzone*copysign(1.0,joyout);
      // The calculated unlimited output, used a few times
      unlimited_output = copysign(sgn_value, factorx) * pow(fabs(factorx), exponent);

      // If our unlimited output would be above our limit...
      if(fabs(unlimited_output) > abs_limit) {
          
          // return the correctly signed limit value
          return abs_limit*copysign(sgn_value, joyout);

      } // end if(fabs(unlimited_output) > abs_limit)

      else {

        // Simply return the unlimited output
        return unlimited_output;

      } // end else (if(fabs(unlimited_output) > abs_limit))
    
    } // end else (if( fabs(joyout) < abs_nullzone )) 
        
} // end double NullDesensLimt(double, double, double, double)
