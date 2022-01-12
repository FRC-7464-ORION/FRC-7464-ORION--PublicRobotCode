/** ===========================================================================
 * @file   GetHansFranz_Info.cpp
 * @brief  This file defines the functions used in getting Hans and Franz
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

// Get the Hans/Franz Arms motor current
void TelemetryOutputter::GetHFArmsMtrCurrent()
{

  // If we want to output the H/F Arms's motor current...
  if(mk_telemetry[H_F_ARMS_MTR_CURRENT].output) {

    // Get the H/F Arms's motor current, in Amps
    m_PDP_H_F_ArmsMotorCurrent =
      m_pdp->GetCurrent(k_HansFranzArmsMotorPDPChannel);

  } // end if(mk_telemetry[H_F_ARMS_MTR_CURRENT].output)

} // end TelemetryOutputter::GetHFArmsMtrCurrent()

// Get the Hans/Franz Arms enabled status
void TelemetryOutputter::GetHFArmsEnabled()
{

  // If we want to output if the arms are enabled...
  if(mk_telemetry[H_F_ARMS_ENABLED].output)
  {

    // Get if Arms are enabled 
    m_HansFranzArmsEnabled = 
      m_subSysHansFranzArms->AreHansFranzArmsEnabled();

  } // end if(mk_telemetry[H_F_ARMS_ENABLED].output)

} // end TelemetryOutputter::GetHFArmsEnabled()

// Get the Hans/Franz Muscles enabled status
void TelemetryOutputter::GetHFMusclesEnabled()
{

  // If we want to output if the muscles are enabled...
  if(mk_telemetry[H_F_MUSCLES_ENABLED].output)
  {

    // Get if muscles are enabled 
    m_HansFranzMusclesEnabled = 
      m_subSysHansFranzMuscles->AreHansFranzMusclesEnabled();

  } // end if(mk_telemetry[H_F_MUSCLES_ENABLED].output)

} // end TelemetryOutputter::GetHFMusclesEnabled()

// Get the Hans/Franz Arms state
void TelemetryOutputter::GetHFArmsState()
{
  // If we want to output the state of the arms
  if(mk_telemetry[H_F_ARMS_STATE].output)
  {

    // Get the state of the arms 
    m_HansFranzArmsState = 
      m_subSysHansFranzArms->GetHansFranzArmsSmartDashboardState();

  } // end if(mk_telemetry[H_F_ARMS_STATE].output)

} // end TelemetryOutputter::GetHFArmsState()

// Get the Hans/Franz Muscles state
void TelemetryOutputter::GetHFMusclesState()
{

  // If we want to output the state of the muscles
  if(mk_telemetry[H_F_MUSCLES_STATE].output)
  {

    // Get the state of the muscles 
    m_HansFranzMusclesState = 
      m_subSysHansFranzMuscles->GetHansFranzMusclesState();

  } // end if(mk_telemetry[H_F_MUSCLES_STATE].output)

} // end TelemetryOutputter::GetHFMusclesState()

// Get the Hans/Franz Arms retracted state
void TelemetryOutputter::GetHFArmsRtrctd()
{

  // If we want to output the boolean to indicate if arms are fully retracted
  if(mk_telemetry[H_F_ARMS_RETRACTED].output)
  {

    // Get the boolean to indicate if arms are fully retracted
    m_HansFranzArmsRetracted = 
      m_subSysHansFranzArms->IsHansFranzArmsFullyRetracted();

  } // end if(mk_telemetry[H_F_ARMS_RETRACTED].output)

} // end TelemetryOutputter::GetHFArmsRtrctd()

// Get the Hans/Franz Arms extended state
void TelemetryOutputter::GetHFArmsExtnded()
{

  // If we want to output the boolean to indicate if arms are fully extended
  if(mk_telemetry[H_F_ARMS_EXTENDED].output)
  {

    // Get the boolean to indicate if arms are fully extended
    m_HansFranzArmsExtended = 
      m_subSysHansFranzArms->IsHansFranzArmsFullyExtended();

  } // end if(mk_telemetry[H_F_ARMS_EXTENDED].output)

} // end TelemetryOutputter::GetHFArmsExtnded()
