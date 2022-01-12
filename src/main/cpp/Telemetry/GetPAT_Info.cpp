/** ===========================================================================
 * @file   GetPAT_Info.cpp
 * @brief  This file defines the functions used in getting PAT information,
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

// Get the PAT motor current
void TelemetryOutputter::GetPATMtrCurrent()
{

  // If we want to output the PAT Turner's motor current...
  if(mk_telemetry[PAT_TURNER_MOTOR_CURRENT].output) {

    // Get the PAT Turner's motor current, in Amps
    m_PDP_PATTurnerMotorCurrent =
      m_pdp->GetCurrent(k_PATTurnerMotorPDPChannel);

  } // end if(mk_telemetry[PAT_TURNER_MOTOR_CURRENT].output)

} // end TelemetryOutputter::GetPATMtrCurrent()
