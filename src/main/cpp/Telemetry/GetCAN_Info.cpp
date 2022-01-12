/** ===========================================================================
 * @file   GetCAN_Info.cpp
 * @brief  This file defines the functions used in getting CAN bus
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

// Method to get the current CAN bus utilization
void TelemetryOutputter::GetCANUtilization()
{

  // If we want to output CAN bus utilization percentage, 
  //   or its min or max
  if(mk_telemetry[CAN_UTILIZATION].output ||
     mk_telemetry[CAN_MIN_UTILIZATION].output ||
     mk_telemetry[CAN_MAX_UTILIZATION].output)
  {
 
    // Get the CAN bus utilization percentage
    m_CANUtilization = 
      frc::RobotController::GetCANStatus().percentBusUtilization;
      
  } // end if(mk_telemetry[CAN_UTILIZATION].output ||...

} // end TelemetryOutputter::GetCANUtilization()

// Method to get the maximum CAN bus utilization
void TelemetryOutputter::GetMaxCANUtilization()
{

  // If we want to output maximum CAN bus utilization percentage
  if(mk_telemetry[CAN_MAX_UTILIZATION].output)
  {

    // If the current utilization is higher than the maximum
    if(m_CANUtilization > m_MaxCANUtilization) 
    {

      // Get the maximum CAN bus utilization percentage
      m_MaxCANUtilization = m_CANUtilization;

    } // end if(m_CANUtilization > m_MaxCANUtilization)
  
  } // end if(mk_telemetry[CAN_MAX_UTILIZATION].output)

} // end TelemetryOutputter::GetMaxCANUtilization()

// Method to get the minimum CAN bus utilization
void TelemetryOutputter::GetMinCANUtilization()
{

  // If we want to output minimum CAN bus utilization percentage
  if(mk_telemetry[CAN_MIN_UTILIZATION].output)
  {

    // If the current utilization is lower than the minimum
    if(m_CANUtilization < m_MinCANUtilization) 
    {

      // Get the minimum CAN bus utilization percentage
      m_MinCANUtilization = m_CANUtilization;

    } // end if(m_CANUtilization < m_MinCANUtilization)
  
  } // end if(mk_telemetry[CAN_MIN_UTILIZATION].output)

} // end TelemetryOutputter::GetMinCANUtilization()

// Method to get the count of CAN bus off events
void TelemetryOutputter::GetCANBusOffCount()
{

  // If we want to output count of CAN bus off events
  if(mk_telemetry[CAN_BUS_OFF_COUNT].output)
  {
 
    // Get the count of CAN bus off events
    m_CANBusOffCount = 
      frc::RobotController::GetCANStatus().busOffCount;
      
  } // end if(mk_telemetry[CAN_BUS_OFF_COUNT].output)

} // end TelemetryOutputter::GetCANBusOffCount()

// Method to get the count of CAN TX full events
void TelemetryOutputter::GetCANTXFullCount()
{

  // If we want to output count of CAN bus TX full events
  if(mk_telemetry[CAN_TX_FULL_COUNT].output)
  {
 
    // Get the count of CAN bus TX full events
    m_CANTXFullCount = 
      frc::RobotController::GetCANStatus().txFullCount;
      
  } // end if(mk_telemetry[CAN_TX_FULL_COUNT].output)

} // end TelemetryOutputter::GetCANTXFullCount()

// Method to get the count of CAN RX error events
void TelemetryOutputter::GetCANRXErrorCount()
{

  // If we want to output count of CAN bus RX error events
  if(mk_telemetry[CAN_RX_ERR_COUNT].output)
  {
 
    // Get the count of CAN bus RX error events
    m_CANRXErrorCount = 
      frc::RobotController::GetCANStatus().receiveErrorCount;
      
  } // end if(mk_telemetry[CAN_RX_ERR_COUNT].output)

} // end TelemetryOutputter::GetCANRXErrorCount()

// Method to get the count of CAN TX error events
void TelemetryOutputter::GetCANTXErrorCount()
{

  // If we want to output count of CAN bus TX error events
  if(mk_telemetry[CAN_TX_ERR_COUNT].output)
  {
 
    // Get the count of CAN bus TX error events
    m_CANTXErrorCount = 
      frc::RobotController::GetCANStatus().transmitErrorCount;
      
  } // end if(mk_telemetry[CAN_TX_ERR_COUNT].output)

} // end TelemetryOutputter::GetCANTXErrorCount()
