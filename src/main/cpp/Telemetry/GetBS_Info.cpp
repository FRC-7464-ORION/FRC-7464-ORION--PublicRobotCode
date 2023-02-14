/** ===========================================================================
 * @file   GetBS_Info.cpp
 * @brief  This file defines the functions used in getting ball shooter
 *         information, as declared in the TelemetryOutputter class.
 *
 * The TelemetryOutputter class is used to output telemetry related to the 
 * general operation of the robot.
 * 
 * COPYRIGHT NOTICES:
 *
 * Some portions:
 *
 * Copyright (c) 2017-2022 FIRST. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FIRST BSD license file in the root directory of
 * the project.
 *
 * Some portions:
 *
 * Copyright (c) 2022 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// Include the header file for the TelemetryOutputter class
#include "Telemetry/TelemetryOutputter.h"

/************************ Member function definitions *************************/

// Get ball shooter intake motor current
void TelemetryOutputter::GetBS_Intk_Mtr_Curr()
{

  // If we want to output the ball shooter intake motor current...
  if(mk_telemetry[BS_INTK_MTR_CURRENT].output)
  {
    m_IntakeMotorCurrent = 
      m_pdp->GetCurrent(k_IntakeMotorPDPChannel);
  } 

} // end TelemetryOutputter::GetBS_Intk_Mtr_Curr()

// Get the ball shooter left indexer motor current
void TelemetryOutputter::GetBS_LftIndxMtrCurr() {

  if(mk_telemetry[BS_LEFT_INDXR_MTR_CURRNT].output)
  {
    m_LeftIndexterMotorCurrent = 
      m_pdp->GetCurrent(k_LeftIndexerMotorPDPChannel);
  }

} // end TelemetryOutputter::GetBS_LftIndxMtrCurr()

// Get the ball shooter right indexer motor current
void TelemetryOutputter::GetBS_RghtIndxMtrCurr() {

  if(mk_telemetry[BS_RIGHT_INDXR_MTR_CURRNT].output)
  {
    m_RightIndexerMotorCurrent = 
      m_pdp->GetCurrent(k_RightIndexerMotorPDPChannel);
  }

} // end TelemetryOutputter::GetBS_RghtIndxMtrCurr()

// Get the ball shooter shooter motor current
void TelemetryOutputter::GetBS_ShtrMtrCurr() {

  if(mk_telemetry[BS_SHTR_MTR_CURRNT].output)
  {
    m_ShooterMotorCurrent = 
      m_pdp->GetCurrent(k_ShooterMotorPDPChannel);
  }

} // end TelemetryOutputter::GetBS_ShtrMtrCurr()

// Get ultrasonic distance
void TelemetryOutputter::GetBS_UltSon_Dist() {

  if(mk_telemetry[BS_ULTRASNC_DIST].output)
  {
    m_Ultrasonic_Distance_m = 
      m_subSysBallShooter->GetUltrasonicOutputMeters();
  }

} // end TelemetryOutputter::GetBS_UltSon_Dist()

// Get the NEO motor velocity setpoint
void TelemetryOutputter::GetBS_NEOMtrVelSP() {

  if(mk_telemetry[BS_SHTR_MTR_VEL_SP].output)
  {
    m_NEO_MotorVelocitySetpoint_rpm = 
      m_subSysBallShooter->GetShooterMotorVelocitySetPoint();
  }

} // end TelemetryOutputter::GetBS_NEOMtrVelSP()

// Get the ball shooter shooter 
void TelemetryOutputter::GetBS_NEOMtrVel() {

  // If we want to output the ball shooter shooter motor velocity...
  if(mk_telemetry[BS_SHTR_MTR_ACT_VEL].output)
  {
  
    // Save the velocity of the shooter motor to later output
    m_NEO_MotorVelocity_rpm =
      m_subSysBallShooter->GetShooterMotorVelocity();
  
  }

} // end TelemetryOutputter::GetBS_NEOMtrVel()
