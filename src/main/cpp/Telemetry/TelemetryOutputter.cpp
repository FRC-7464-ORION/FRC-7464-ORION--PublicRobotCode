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
 * Copyright (c) 2019-2022 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// Include the header file for the TelemetryOutputter class
#include "Telemetry/TelemetryOutputter.h"

/************************ Member function definitions *************************/

// The constructor for the TelemetryOutputter class
TelemetryOutputter::TelemetryOutputter(
  RobotTick* robot_tick,
  AHRS* ahrs,
  SubSysDriveTrain* drivetrain,
  SubSysBallShooter* ballshooter
)

  : m_RobotTick(robot_tick),
    m_AHRS(ahrs),
    m_subSysDriveTrain(drivetrain),
    m_subSysBallShooter(ballshooter)
{

  // Declare a new instance of the power distribution panel
  m_pdp = new frc::PowerDistribution();

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

  // Output PDP telemetry with new method
  OutputTelemetry();

} // end OutputTelemetryToSmartDashboard()

// A new method of outputting telemetry
void TelemetryOutputter::OutputTelemetry()
{
  // Index to go through all the telemetry items
  int index;

  // The current telemetry ID
  telemetry_output_ID current_telemetry_ID;

  // A function pointer to the current telemetry item getter
  //   function.
  void (TelemetryOutputter::*getter)();

  // Loop through all of the telemetry items, starting at the 
  //   2nd telemetry ID (the first real item) until we get to the
  //   next to last telemetry item 
  for(index = FIRST_TELEMETRY_ID+1; 
      index != LAST_TELEMETRY_ID; 
      index++)
  {

    // Convert the index back to a telemetry output ID
    current_telemetry_ID = (telemetry_output_ID)index;

    // If the telemetry item is scheduled to be output...
    if(m_RobotTick->GetRobotTick() % 
       mk_telemetry[current_telemetry_ID].tick_interval == 
       mk_telemetry[current_telemetry_ID].tick_offset)
    {
      // Get the getter from the structure
      getter = mk_telemetry[current_telemetry_ID].get_function;

      // Run the getter function
      (this->*getter)();

      // Switch on the data type of the telemetry item
      switch(mk_telemetry[current_telemetry_ID].data_type)
      {

        // NOTE: A little explanation is warranted for the value sent.
        //       The value to send was referenced via a void pointer.
        //       A void pointer allows you to point to any type of data.
        //       This makes it ideal for our purposes, where we have
        //       different data types to output. However, when we want
        //       to actually use the data, we have to convert it back
        //       to the original data type (bool, double, float, int,
        //       string, etc.). So we cast the value (again, stored
        //       as a void pointer) to the specific data type pointer.
        //       This is done by putting the (bool*), (double*), 
        //       (float*), (int*), (std::string*), etc. in front of the
        //       value from the telemetry item. But now we have a
        //       pointer to the value we want, not the actual value.
        //       So we dereference the pointer with a "*" in front.
        //
        //       So the whole thing looks like:
        //
        // Dereference       Data Type Ptr
        //       |               |
        //       |   |-----------|             |--- void ptr to output value
        //       |   |                         |
        //       ||-----||----------------------------------------|
        //       *(bool*)(mk_telemetry[current_telemetry_ID].value)

        case BOOLEAN:

          frc::SmartDashboard::PutBoolean(
            mk_telemetry[current_telemetry_ID].SD_Key,
            *(bool*)(mk_telemetry[current_telemetry_ID].value));

          break;

        case DOUBLE:

          frc::SmartDashboard::PutNumber(
            mk_telemetry[current_telemetry_ID].SD_Key,
            *(double*)(mk_telemetry[current_telemetry_ID].value));

          break;

        case FLOAT:

          frc::SmartDashboard::PutNumber(
            mk_telemetry[current_telemetry_ID].SD_Key,
            *(float*)(mk_telemetry[current_telemetry_ID].value));

          break;

        case INTEGER:

          frc::SmartDashboard::PutNumber(
            mk_telemetry[current_telemetry_ID].SD_Key,
            *(int*)(mk_telemetry[current_telemetry_ID].value));

          break;

        case STRING:

          frc::SmartDashboard::PutString(
            mk_telemetry[current_telemetry_ID].SD_Key,
            *(std::string*)(mk_telemetry[current_telemetry_ID].value));

          break;

        case UINT64T:

          frc::SmartDashboard::PutNumber(
            mk_telemetry[current_telemetry_ID].SD_Key,
            *(uint64_t*)(mk_telemetry[current_telemetry_ID].value));

          break;
          
        case NOTYPE:
        default:

          // Intentionally do nothing here

          break;

      } // end switch(mk_telemetry[current_telemetry_ID].data_type)

    } // end if(m_RobotTick->GetRobotTick() % ...

  } // end for(index...)

} // end void TelemetryOutputter::OutputTelemetry()
