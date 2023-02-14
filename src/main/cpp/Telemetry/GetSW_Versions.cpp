/** ===========================================================================
 * @file   GetSW_Versions.cpp
 * @brief  This file defines the functions used in getting software versions,
 *         as declared in the TelemetryOutputter class.
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

// Get the software version of the ORiON RobotCode
void TelemetryOutputter::GetORION_RobotCode_SW_Ver()
{

  // If we want to output the string showing the ORION RobotCode SW vers.
  if(mk_telemetry[ORION_ROBOTCODE_SW_VER].output)
  {
 
    // Get the ORION RobotCode SW version
    m_ORION_RobotCode_SW_Version = k_SW_VersionNumber;
      
  } // end if(m_Output_ORION_RobotCode_SW_Version)

} // end TelemetryOutputter::GetORION_RobotCode_SW_Ver()

// Get the software version of the WPILibC code used
void TelemetryOutputter::GetWPILibC_Code_SW_Ver()
{

  // If we want to output the string showing the WPILibC Code SW vers.
  if(mk_telemetry[WPILIBC_CODE_SW_VER].output)
  {
 
    // Get the WPILibC Code SW version
    m_WPILibC_Code_SW_Version = k_WPILibC_VersionNumber;
      
  } // end if(m_Output_WPILibC_Code_SW_Version)

} // end TelemetryOutputter::GetWPILibC_Code_SW_Ver()

// Get the software version of the NavX MXP code used
void TelemetryOutputter::GetNavXMXP_Code_SW_Ver()
{

  // If we want to output the string showing the NavX MXP Code SW vers.
  if(mk_telemetry[NAVX_MXP_CODE_SW_VER].output)
  {
 
    // Get the NavX MXP Code SW version
    m_NavX_MXP_Code_SW_Version = k_navx_frc_VersionNumber;
      
  } // end if(mk_telemetry[NAVX_MXP_CODE_SW_VER].output)

} // end TelemetryOutputter::GetNavXMXP_Code_SW_Ver()

// Get the software version of the REV robotics library used
void TelemetryOutputter::GetREVLib_Code_SW_Ver()
{

  // If we want to output the string showing the REV library SW vers.
  if(mk_telemetry[REVLIB_CODE_SW_VER].output)
  {
 
    // Get the REV library SW version
    m_REVLib_SW_Version = k_REVLib_VersionNumber;
      
  } // end if(mk_telemetry[REVLIB_CODE_SW_VER].output)

} // end TelemetryOutputter::GetREVLib_Code_SW_Ver()
