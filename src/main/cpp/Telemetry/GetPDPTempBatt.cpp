/** ===========================================================================
 * @file   GetPDPTempBatt.cpp
 * @brief  This file defines the functions used in getting temperature and
 *         battery values for the power distribution panel (PDP), as 
 *         declared in the TelemetryOutputter class.
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

// Method to get the temperature as reported by the PDP
void TelemetryOutputter::Get_PDP_Temperature()
{

  // If we want to output the temperature,
  //  or the operating temperature status...
  if(mk_telemetry[PDP_TEMPERATURE].output ||
     mk_telemetry[PDP_TEMPERATURE_STATUS].output) {

    // Get the PDP's temperature (in Celsius) via the CAN bus
    m_PDP_temperature_C = m_pdp->GetTemperature();
    // and convert it to Farenheit
    m_PDP_temperature_F = CelsiusToFarenheit(m_PDP_temperature_C);

  } // end if(m_Output_PDP_Temperature)

} // end TelemetryOutputter::Get_PDP_Temperature()

// Method to get the temperature status
void TelemetryOutputter::Get_PDP_Temperature_Status()
{

  // If we want to output the operating temperature status...
  if(mk_telemetry[PDP_TEMPERATURE_STATUS].output) {

    // Get the operating temperature status
    m_PDP_OperatingTemperatureStatus =
      GetIfWithinRange(m_PDP_temperature_C,
                       mk_PDP_OperatingTemperatureRange);

  } // end if(m_Output_OperatingTemperatureStatus)

} // end TelemetryOutputter::Get_PDP_Temperature_Status()

// Method to get the main battery voltage as reported by the PDP
void TelemetryOutputter::Get_PDP_Battery_Voltage()
{

  // If we want to output the battery voltage, or
  //   the battery voltage status, or
  //   the battery status
  if(mk_telemetry[PDP_BATTERY_VOLTAGE].output ||
     mk_telemetry[PDP_BATTERY_VOLTAGE_STATUS].output ||
     mk_telemetry[PDP_BATTERY_STATUS].output) {

    // Get the battery voltage, in Volts
    m_PDP_BatteryVoltage = m_pdp->GetVoltage();

  } // end if(m_Output_PDP_BatteryVoltage)

} // end TelemetryOutputter::Get_PDP_Battery_Voltage()

// Method to get the battery voltage status
void TelemetryOutputter::Get_PDP_Battery_Voltage_Status()
{

  // If we want to output the battery voltage status, or
  //   the battery status
  if(mk_telemetry[PDP_BATTERY_VOLTAGE_STATUS].output ||
     mk_telemetry[PDP_BATTERY_STATUS].output) {

    // If the battery current is sufficiently low enough to check SoC...
    if(m_PDP_BatteryCurrent < mk_PDP_BatteryVoltageMaxForSoCTest)
    {

      // See if the battery voltage is within the acceptable range
      m_PDP_BatteryVoltageStatus =
        GetIfWithinRange(m_PDP_BatteryVoltage,
                         mk_PDP_BatteryVoltageRange);

    } // end if(m_PDP_BatteryCurrent < mk_PDP_BatteryVoltageMaxForSoCTest)

  } // end if(m_Output_PDP_BatteryVoltageStatus)

} // end TelemetryOutputter::Get_PDP_Battery_Voltage_Status()

// Method to get the main battery current as reported by the PDP
void TelemetryOutputter::Get_PDP_Battery_Current()
{

  // If we want to output the battery current, or
  //   the battery current status, or
  //   the battery status
  if(mk_telemetry[PDP_BATTERY_CURRENT].output ||
     mk_telemetry[PDP_BATTERY_CURRENT_STATUS].output ||
     mk_telemetry[PDP_BATTERY_STATUS].output) {

    // Get the battery's total current consumption, in Amps
    m_PDP_BatteryCurrent = m_pdp->GetTotalCurrent();

  } // end if(m_Output_PDP_BatteryCurrent)

} // end TelemetryOutputter::Get_PDP_Battery_Current()

// Method to get the battery current status
void TelemetryOutputter::Get_PDP_Battery_Current_Status()
{

  // If we want to output the battery current status, or
  //   the battery status
  if(mk_telemetry[PDP_BATTERY_CURRENT_STATUS].output ||
     mk_telemetry[PDP_BATTERY_STATUS].output) {

    // See if the battery current is within the acceptable range
    m_PDP_BatteryCurrentStatus =
      GetIfWithinRangeWithMaxPercent(
        m_PDP_BatteryCurrent,
        mk_PDP_BatteryCurrentRange);

  } // end if(m_Output_PDP_BatteryCurrentStatus)

} // end TelemetryOutputter::Get_PDP_Battery_Current_Status()

// Method to get the current power output of the battery,
//   as reported by the PDP
void TelemetryOutputter::Get_PDP_Battery_Power()
{

  // If we want to output the battery power...
  if(mk_telemetry[PDP_BATTERY_POWER].output) {

    // Get the battery's total power consumed, in Watts
    m_PDP_BatteryPower = m_pdp->GetTotalPower();

  } // end if(m_Output_PDP_BatteryPower)

} // end TelemetryOutputter::Get_PDP_Battery_Power()

// Method to get the energy output of the battery since last reset, 
//   as reported by the PDP
void TelemetryOutputter::Get_PDP_Battery_Energy()
{

  // If we want to output the battery energy...
  if(mk_telemetry[PDP_BATTERY_ENERGY].output) {

    // Get the battery's total energy used, in Joules
    m_PDP_BatteryEnergy = m_pdp->GetTotalEnergy();

  } // end if(m_Output_PDP_BatteryEnergy)

} // end TelemetryOutputter::Get_PDP_Battery_Energy()

// Method to get the battery status
void TelemetryOutputter::Get_PDP_Battery_Status()
{

  // If we want to output the battery status
  if(mk_telemetry[PDP_BATTERY_STATUS].output) {

    // The battery status is the logical anding of the
    //   battery voltage status and battery current status,
    //   i.e. both voltage status and current status have
    //        to be good(true) for battery status to be good(true)
    m_PDP_BatteryStatus = m_PDP_BatteryVoltageStatus &&
                          m_PDP_BatteryCurrentStatus;

  } // end if(m_Output_PDP_BatteryStatus)

} // end TelemetryOutputter::Get_PDP_Battery_Status()
