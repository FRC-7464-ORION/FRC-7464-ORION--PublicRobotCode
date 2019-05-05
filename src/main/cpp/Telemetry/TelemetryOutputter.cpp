/** ===========================================================================
 * @file   TelemetryOutputter.cpp
 * @brief  This file defines the TelemetryOutputter class.
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
 * Copyright (c) 2019 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// Include the header file for the TelemetryOutputter class
#include "Telemetry/TelemetryOutputter.h"

// Include the header file for the robot
#include "Robot.h"

// Include the RobotMap header file
#include "RobotMap.h"

/************************ Member function definitions *************************/

// The default constructor for the TelemetryOutputter class
TelemetryOutputter::TelemetryOutputter() {

  // Declare a new instance of the power distribution panel
  m_pdp = new frc::PowerDistributionPanel();

  // Declare a new instance of the roboRIO's internal accelerometers
  m_roboRIO_accelerometers = new frc::BuiltInAccelerometer();

} // end TelemetryOutputter::TelemetryOutputter()

// The destructor for the TelemetryOutputter class
TelemetryOutputter::~TelemetryOutputter() {

  // Delete the instance of the roboRIO accelerometers
  delete m_roboRIO_accelerometers;

  // Delete the instance of the PDP
  delete m_pdp;

} // end TelemetryOutputter::~TelemetryOutputter()

// Method to output the telemetry to the Smart Dashboard
void TelemetryOutputter::OutputTelemetryToSmartDashboard() {

  // Get the telemetry
  GetTelemetry();

  // and then output it
  OutputTelemetry();

} // end OutputTelemetryToSmartDashboard()

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

// Method to see if measured value is between the minimum and maximum
//   acceptable range
bool TelemetryOutputter::GetIfWithinRange(double MeasuredValue,
                                          double MinValue,
                                          double MaxValue) {

  // Declare a local status, assumed to be true at this time
  bool status = true;

  // If the measuerd value is less than the min,
  //   or greater than the max
  if( (MeasuredValue < MinValue) ||
      (MeasuredValue > MaxValue) )
    // Indicate the status is bad
    status = false;

  // Return the status of the battery voltage
  return status;

} // end TelemetryOutputter::GetIfWithinRange(double, double, double)
