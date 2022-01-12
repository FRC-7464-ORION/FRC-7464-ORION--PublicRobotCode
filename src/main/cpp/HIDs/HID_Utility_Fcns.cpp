/** ===========================================================================
 * @file   HID_Utility_Fcns.cpp
 * @brief  This file hosts some utility functions for HIDs.
 *
 * This file hosts some utility functions for human interface devices (HIDs).
 * It is currently not part of a class.
 *
 * COPYRIGHT NOTICES:
 *
 * Copyright (c) 2019-2020 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// Include the header file for the HID utility functions
#include "HIDs/HID_Utility_Fcns.h"

// Include the header file for HID constants
#include "HIDs/HID_Constants.h"

/************************** Library Header Files ******************************/

// Include the header for common mathematical functions
#include <cmath>

/**************************** Utility Functions *******************************/

// Correct the Y axis joystick/thumbstick inversion
double Correct_Y_Axis_Inversion(double y_axis) {

    // Return the y axis multiplied by our correction factor
    return y_axis * (k_CorrectJoystickYAxisMotorSpeedInversion);

} // end Correct_Y_Axis_Inversion(double)

// Null, desensitize, and limit a joystick output
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
