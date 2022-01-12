/** ===========================================================================
 * @file   SmartDashboardKeys.h
 * @brief  This file provides keys for outputting data to the Smart
 *         Dashboard.
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
// If we have not already defined SMARTDASHBOARDKEYS_H...
#ifndef SMARTDASHBOARDKEYS_H
// Define SMARTDASHBOARDKEYS_H
#define SMARTDASHBOARDKEYS_H

/*************************** Local Header Files *******************************/

/************************** Library Header Files ******************************/

// Include the header file for strings, so we can define strings
#include <string>

                  // **** SmartDashboard Keys *****

// NOTE: If you change the keys below, you will need to redevelop your
//       dashboard (default, SmartDashboard, or Shuffleboard). On some
//       dashboards, you can change the displayed title, or add a
//       label.

/** The SmartDashboard key string for the telemetry output time */
const std::string k_TelemetryOutputTimeMS_Key = "Telem. Out Time(ms)";

/** The SmartDashboard key string for the min. telemetry output time */
const std::string k_MinTelemetryOutputTimeMS_Key = "Min. Telem. Out Time(ms)";

/** The SmartDashboard key string for the max. telemetry output time */
const std::string k_MaxTelemetryOutputTimeMS_Key = "Max. Telem. Out Time(ms)";

/** The SmartDashboard key string for the zero AHRS yaw command */
const std::string k_CmdZeroAHRSYaw_Key = "Cmd: Zero AHRS Yaw";

/** The SmartDashboard key string for the reset AHRS yaw command */
const std::string k_CmdResetAHRSYaw_Key = "Cmd: Reset AHRS Yaw";

#endif // #ifndef SMARTDASHBOARDKEYS_H
