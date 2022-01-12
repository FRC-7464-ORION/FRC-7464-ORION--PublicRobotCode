/** ===========================================================================
 * @file   GetPssh_Info.cpp
 * @brief  This file defines the functions used in getting Pssh
 *         information, as declared in the TelemetryOutputter class.
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

// Get the Pssh motor current
void TelemetryOutputter::GetPsshMtrCurrent()
{

  // If we want to output the Pssh's motor current...
  if(mk_telemetry[PSSH_MOTOR_CURRENT].output) {

    // Get the Pssh's motor current, in Amps
    m_PDP_PsshMotorCurrent =
      m_pdp->GetCurrent(k_PsshMotorPDPChannel);

  } // end if(mk_telemetry[PSSH_MOTOR_CURRENT].output)

} // end TelemetryOutputter::GetPsshMtrCurrent()

// Get the Pssh potentiometer angle
void TelemetryOutputter::GetPsshPotAngle()
{

  // If we want to output the angle of Pssh...
  if(mk_telemetry[PSSH_POT_ANGLE].output) {

    // Get Pssh's potentiometer angle, in degrees (0 degrees up, 180 down)
    m_PsshPotAngle = m_PIDsubSysPssh->GetMeasurement();

  } // end if(mk_telemetry[PSSH_POT_ANGLE].output)

} // end TelemetryOutputter::GetPsshPotAngle()

// Get the Pssh state
void TelemetryOutputter::GetPsshState()
{

  // If we want to output the state of Pssh
  if(mk_telemetry[PSSH_STATE].output)
  {

    // Get the state of Pssh
    m_Pssh_State = m_PIDsubSysPssh->GetPsshState();

  } // end if(mk_telemetry[PSSH_STATE].output)

} // end TelemetryOutputter::GetPsshState()
