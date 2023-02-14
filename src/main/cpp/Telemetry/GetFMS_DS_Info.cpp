/** ===========================================================================
 * @file   GetFMS_DS_Info.cpp
 * @brief  This file defines the functions used in getting FMS and DS
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

// Method to get the alliance color and station #
void TelemetryOutputter::GetAllianceColorStationNumber()
{
  // The alliance color from the driver station
  frc::DriverStation::Alliance alliance_color;

  // The string containing the alliance color
  std::string alliance;

  // The station location from the driver station
  int station_location;

  // The string holding the station #
  std::string station_number;

  // If we need to ouput the alliance color and station #...
  if(mk_telemetry[FMS_ALLNC_STN].output)
  {

    // Get the alliance color from the driver station
    alliance_color = frc::DriverStation::GetAlliance();

    // Switch on the alliance color
    switch(alliance_color)
    {
      // If it's red...
      case frc::DriverStation::kRed :
        // Make it red
        alliance = mk_RedAlliance;
        break;

      // If it's blue...
      case frc::DriverStation::kBlue :
        // Make it blue
        alliance = mk_BlueAlliance;
        break;

      // If it's invalid...
      case frc::DriverStation::kInvalid :
        // Make it invalid
        alliance = mk_InvalidAlliance;
        break;

      default :
        // Make it unknown
        alliance = mk_UnknownAlliance;

    } // end switch(alliance_color)
    
    // Get the station location number
    station_location = frc::DriverStation::GetLocation();

    // Switch on the station location
    switch(station_location)
    {

      // If we get #0 station
      case 0 :
        // Make it invalid
        station_number = mk_StationNumber0;
        break;

      // If we get #1 station
      case 1 :
        // Make it #1 (LEFT)
        station_number = mk_StationNumber1;
        break;

      // If we get #2 station
      case 2 :
        // Make it #2 (CENTER)
        station_number = mk_StationNumber2;
        break;

      // If we get #3 station
      case 3 :
        // Make it #3 (RIGHT)
        station_number = mk_StationNumber3;
        break;

      default :
        // Make it unknown
        station_number = mk_StationNumberUnknown;

    } // end switch(station_location)

    // If the alliance color was INVALID or UNKNOWN
    if( (alliance.compare(mk_InvalidAlliance) == 0)
        || (alliance.compare(mk_UnknownAlliance) == 0) )
      // Just use the alliance color, as a station # makes no sense
      m_AllianceColorStationNumber = alliance;
    else
      // Concatenate the alliance and station # together
      m_AllianceColorStationNumber =
        (alliance + mk_AllianceStationNumberGlue + station_number);

  } // end if(mk_telemetry[FMS_ALLNC_STN].output)

} // end TelemetryOutputter::GetAllianceColorStationNumber()

// Method to get the match type and match #
void TelemetryOutputter::GetMatchTypeMatchNumber()
{

  // The match type from the driver station
  frc::DriverStation::MatchType MatchType;

  // The match type as a string
  std::string str_MatchType;

  // The match number from the driver station
  int MatchNumber;

  // The match number as a string
  std::string str_MatchNumber;

  // If we want to output the match type and match #...
  if(mk_telemetry[FMS_MATCH_TYPE_NUM].output)
  {

    // Get the match type 
    MatchType = frc::DriverStation::GetMatchType();

    // Switch on the match type
    switch(MatchType)
    {
      // If it is kNone
      case frc::DriverStation::kNone :
        // Make it NONE
        str_MatchType = mk_MatchTypeNone;
        break;

      // If it is kPractice
      case frc::DriverStation::kPractice :
        // Make it PRACTICE
        str_MatchType = mk_MatchTypePractice;
        break;

      // If it is kQualification
      case frc::DriverStation::kQualification :
        // Make it QUALIFICATION
        str_MatchType = mk_MatchTypeQualification;
        break;

      // If it is kElimination
      case frc::DriverStation::kElimination :
        // Make it ELIMINATION
        str_MatchType = mk_MatchTypeElimination;
        break;

      // Otherwise, it is UNKNOWN
      default : 
        str_MatchType = mk_MatchTypeUnknown;

    } // end switch(MatchType)

    // Get the match number from the driver station
    MatchNumber = frc::DriverStation::GetMatchNumber();

    // Convert the match number to a string
    str_MatchNumber = std::to_string(MatchNumber);

    // If the match type was NONE or UNKNOWN
    if( (str_MatchType.compare(mk_MatchTypeNone) == 0) ||
        (str_MatchType.compare(mk_MatchTypeUnknown) == 0) )
        // Just use the match type, as a # makes no sense
      m_MatchTypeNumber = str_MatchType;
    else
      // Concatenate the match type and match # strings
      m_MatchTypeNumber =
        (str_MatchType + mk_MatchTypeNumberGlue + str_MatchNumber);

  } // end if(mk_telemetry[FMS_MATCH_TYPE_NUM].output)

} // end TelemetryOutputter::GetMatchTypeMatchNumber()

// Method to get the match mode
void TelemetryOutputter::GetMatchMode()
{

  // If we want to output the FMS match mode...
  if(mk_telemetry[FMS_MATCH_MODE].output)
  {

    // If we are autonomous
    if(frc::DriverStation::IsAutonomous())
      // Set match mode to autonomous
      m_MatchMode = mk_MatchModeAutonomous;
    // Else if we are teleoperating (under operator control)
    else if(frc::DriverStation::IsTeleop())
      // Set match mode to teleoperated
      m_MatchMode = mk_MatchModeTeleoperated;
    // Else if we are testing 
    else if(frc::DriverStation::IsTest())
      // Set match mode to test
      m_MatchMode = mk_MatchModeTest;
    // Else
    else
      // Set match mode to unknown
      m_MatchMode = mk_MatchModeUnknown;

  } // end if(mk_telemetry[FMS_MATCH_MODE].output)

} // end TelemetryOutputter::GetMatchMode()

void TelemetryOutputter::GetMatchTime()
{

  // If we want to output the period time remaining...
  if(mk_telemetry[FMS_PRD_TIME_REM].output)
  {

    // Get the string indicating the time remaining
    m_PeriodTimeRemaining = 
      ConvertDblSecondsToMinutesSecondsTenths(
        frc::DriverStation::GetMatchTime());

  } // end if(mk_telemetry[FMS_PRD_TIME_REM].output)

} // end TelemetryOutputter::GetMatchTime()

void TelemetryOutputter::GetFMSStatus()
{

  // If we want to output the FMS status...
  if(mk_telemetry[FMS_STATUS].output)
  {

    // If the driver station is attached to the FMS
    if(frc::DriverStation::IsFMSAttached())
      // Set status to attached
      m_FMSStatus = mk_FMSAttached;
    else
      // Set status to not attached
      m_FMSStatus = mk_FMSNotAttached;

  } // end if(mk_telemetry[FMS_STATUS].output)

} // end TelemetryOutputter::GetFMSStatus()

void TelemetryOutputter::GetDSStatus()
{

  // If we want to output the DS status...
  if(mk_telemetry[DS_STATUS].output)
  {

    // If the robot is attached to the driver station
    if(frc::DriverStation::IsDSAttached())
      // Set status to attached
      m_DSStatus = mk_DSAttached;
    else
      // Set status to not attched
      m_DSStatus = mk_DSNotAttached;

  } // end if(mk_telemetry[DS_STATUS].output)

} // end TelemetryOutputter::GetDSStatus()

// Method to get the robot state
void TelemetryOutputter::GetRobotStatus()
{

  // If we want to output the robot status...
  if(mk_telemetry[DS_ROBOT_STATUS].output)
  {

    // If the robot is enabled
    if(frc::DriverStation::IsEnabled())
      // Set status to enabled
      m_RobotStatus = mk_RobotStatusEnabled;
    // Else if the robot is disabled
    else if(frc::DriverStation::IsDisabled())
      // Set status to disabled 
      m_RobotStatus = mk_RobotStatusDisabled;
    // Else if status is emergency stopped
    else if(frc::DriverStation::IsEStopped())
      // Set status to E-Stopped
      m_RobotStatus = mk_RobotStatusEStopped;
    else
      // Status is unknown
      m_RobotStatus = mk_RobotStatusUnknown;

  } // end if(mk_telemetry[DS_ROBOT_STATUS].output)

} // end TelemetryOutputter::GetRobotStatus
