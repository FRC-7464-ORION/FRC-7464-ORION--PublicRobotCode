/** ===========================================================================
 * @file   TelemetryHelperFunctions.cpp
 * @brief  This file defines the functions used in helping to get robot
 *         information. These functions are declared in the 
 *         TelemetryOutputter class.
 *
 * The TelemetryOutputter class is used to output telemetry related to the 
 * general operation of the robot.
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

/*************************** Local Header Files *******************************/

// Include the header file for the TelemetryOutputter class
#include "Telemetry/TelemetryOutputter.h"

/************************ Member function definitions *************************/

// Method to convert a double representing seconds to standard match 
//   time format.
std::string 
  TelemetryOutputter::ConvertDblSecondsToMinutesSecondsTenths(
    double seconds_dbl)
{
    // A C style string so we can use sprintf
    char seconds[5];
    // The time in fraction seconds 
    //   (i.e. right of the decimal)
    double fraction_seconds;
    // The time in seconds stored as an integer
    int seconds_int;
    // The time in tenth seconds stored as an integer
    int display_tenth_seconds_int;
    // The time in seconds stored as an integer
    int display_seconds_int;
    // The time in minutes stored as an integer
    int display_minutes_int;

    // The number of seconds per minute
    const int k_seconds_per_minute = 60;
    // Multiplier to get the tenths of second
    const double k_tenths_second_multiplier = 10.0;

    // Get only the whole seconds in the time
    seconds_int = (int)seconds_dbl;

    // Calculate the minutes
    display_minutes_int = seconds_int/k_seconds_per_minute;

    // Calculate the fractional minute as seconds
    display_seconds_int = seconds_int - 
      (display_minutes_int * k_seconds_per_minute);

    // Format the seconds as a string with a leading zero and width of two
    sprintf(seconds,"%02d", display_seconds_int);

    // Convert the C string seconds to C++ string display_seconds
    std::string display_seconds(seconds);

    // Get the fractional seconds by subtracting the whole seconds
    fraction_seconds = seconds_dbl - (double)seconds_int;

    // Get the 1/10 second integer my multiplying by 10, 
    //   then converting to integer
    display_tenth_seconds_int = 
      (int)(fraction_seconds*k_tenths_second_multiplier);

    // Build the time as m:ss.t, where
    //   m  = 1 digit minute
    //   ss = 2 digit seconds, with leading zero
    //   t  = 1 digit tenth of a second
    return( 
      std::to_string(display_minutes_int) + 
      ":" + 
      display_seconds + 
      "." + 
      std::to_string(display_tenth_seconds_int));

} // end TelemetryOutputter::ConvertDblSecondsToMinutesSecondsTenths(double seconds)

// Method to convert celcius to farenheit.
double TelemetryOutputter::CelsiusToFarenheit(double celcius) {

  // Return the celcius temperature in farenheit
  //   using the formula 
  //
  //         9
  // F = C x - + 32
  //         5
  //
  return ((celcius*9.0)/5.0) + 32.0;

} // end CmdOutputTelemetry::CelsiusToFarenheit

// Method to get the FPGA major revision # from the FPGA Revision
int 
  TelemetryOutputter::GetMajorRevisionFromFPGARevision(
    int64_t FPGA_Revision
  ) {

  // The Major Revision is the 1st 12 bits, so we need to 
  //   shift 64 bits - 12 bits = 52 bits over to the right
  //   (k_FPGA_RevisionMajorRevisionShift = 52)
  return FPGA_Revision >> mk_FPGA_RevisionMajorRevisionShift;

} // end GetMajorRevisionFromFPGARevision(int64_t FPGA_Revision)

// Method to get the FPGA minor revision # from the FPGA Revision
int
  TelemetryOutputter::GetMinorRevisionFromFPGARevision(
    int64_t FPGA_Revision
  ) {

  // We need to first get rid of all the bits but the minor revision,
  //   then we shift the remaining bits (the minor version) over
  //   the appropriate number of bits.
  return (
    (FPGA_Revision & mk_FPGA_RevisionMinorRevisionMask) >>
     mk_FPGA_RevisionMinorRevisionShift);

} // end CmdOutputTelemetry::GetMinorRevisionFromFPGARevision(...)

// Method to get the FPGA build number from the FPGA Revision
int
  TelemetryOutputter::GetBuildNumberFromFPGARevision(
    int64_t FPGA_Revision
  ) {

  // We need to get rid of all the bits but the build number
  return FPGA_Revision & mk_FPGA_RevisionBuildNumberMask;

} // end TelemetryOutputter::GetBuildNumberFromFPGARevision(...)

// Method to see if measured value is within acceptable range
bool TelemetryOutputter::GetIfWithinRange(
  double MeasuredValue,
  accept_range_type AcceptRange) {

  // Declare a local status, assumed to be true at this time
  bool status = true;

  // If the measuerd value is less than the min,
  //   or greater than the max
  if( (MeasuredValue < AcceptRange.min_acc_value) ||
      (MeasuredValue > AcceptRange.max_acc_value) )
    // Indicate the status is bad
    status = false;

  // Return the status of if the measured value is within range or not
  return status;

} // end TelemetryOutputter::GetIfWithinRange(double, accept_range_type)

// Method to see if measured value is within acceptable range,
// with a maximum percent
bool TelemetryOutputter::GetIfWithinRangeWithMaxPercent(
  double MeasuredValue,
  accept_range_type AcceptRange) {

  // Declare a local status, assumed to be true at this time
  bool status = true;

  // If the measuerd value is less than the min,
  //   or greater than the max multiplied by the max percent
  if( (MeasuredValue < AcceptRange.min_acc_value) ||
      (MeasuredValue > AcceptRange.max_acc_value * mk_PercentageMaxCurrent) )
    // Indicate the status is bad
    status = false;

  // Return the status of if the measured value is within range or not
  return status;

} // end TelemetryOutputter::GetIfWithinRangeWithMaxPercent(double, accept_range_type)
