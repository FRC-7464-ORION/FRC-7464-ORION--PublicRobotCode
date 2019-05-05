/** ===========================================================================
 * @file   OutputTelemetry.cpp
 * @brief  This file defines the TelemetryOutputter class, with respect to
 *         outputting telemetry.
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
 * Copyright (c) 2019 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// Include the header file for the TelemetryOutputter class
#include "Telemetry/TelemetryOutputter.h"

// Include the header file for the robot
#include "Robot.h"

// Include the RobotMap header file
#include "RobotMap.h"

/************************ Member function definitions *************************/

// Method to output telemetry
void TelemetryOutputter::OutputTelemetry() {

  ///////////// Output the telemetry, if wanted ///////////////
 
  // If we want to output the drive train mode string...
  if(m_Output_DriveTrainModeString) {

    // Output the drive train mode string to the SmartDashboard
    frc::SmartDashboard::PutString(k_DriveTrainMode_Key,
                                     m_DriveTrainModeString);

  } // end if(m_Output_DriveTrainModeString)

  // If we want to output the temperature
  if(m_Output_PDP_Temperature) {

    // Output the robot's temperature to the SmartDashboard
    frc::SmartDashboard::PutNumber(k_RobotTemperatureSD_Key,
                                     m_PDP_temperature_F);

  } // end if(m_Output_PDP_Temperature)

  // If we want to output the operating temperature status...
  if(m_Output_PDP_OperatingTemperatureStatus) {

    // Output the robot's operating temperature status
    //   to the SmartDashboard
    frc::SmartDashboard::PutBoolean(k_PDP_OperatingTemperatureStatusSD_Key,
                                     m_PDP_OperatingTemperatureStatus);

  } // end if(m_Output_OperatingTemperatureStatus)

  // If we want to output the battery voltage...
  if(m_Output_PDP_BatteryVoltage) {

    // Output the battery voltage to the SmartDashboard
    frc::SmartDashboard::PutNumber(k_BatteryVoltageSD_Key,
                                     m_PDP_BatteryVoltage);

  } // end if(m_Output_PDP_BatteryVoltage)

  // If we want to output the battery voltage status...
  if(m_Output_PDP_BatteryVoltageStatus) {

    // Output the battery voltage status to the SmartDashboard
    frc::SmartDashboard::PutBoolean(k_BatteryVoltageStatusSD_Key,
                                    m_PDP_BatteryVoltageStatus);

  } // end if(m_Output_PDP_BatteryVoltageStatus)

  // If we want to output the battery current...
  if(m_Output_PDP_BatteryCurrent) {

    // Output the robot's total current to the SmartDashboard
    frc::SmartDashboard::PutNumber(k_BatteryCurrentSD_Key,
                                     m_PDP_BatteryCurrent);

  } // end if(m_Output_PDP_BatteryCurrent)

  // If we want to output the battery current status...
  if(m_Output_PDP_BatteryCurrentStatus) {

    // Output the battery current status to the SmartDashboard
    frc::SmartDashboard::PutBoolean(k_BatteryCurrentStatusSD_Key,
                                     m_PDP_BatteryCurrentStatus);

  } // end if(m_Output_PDP_BatteryCurrentStatus)

  // If we want to output the battery power...
  if(m_Output_PDP_BatteryPower) {

    // Output the robot's total power to the SmartDashboard
    frc::SmartDashboard::PutNumber(k_BatteryPowerSD_Key,
                                     m_PDP_BatteryPower);

  } // end if(m_Output_PDP_BatteryPower)

  // If we want to output the battery energy...
  if(m_Output_PDP_BatteryEnergy) {

    // Output the robot's total energy to the SmartDashboard
    frc::SmartDashboard::PutNumber(k_BatteryEnergySD_Key,
                                     m_PDP_BatteryEnergy);

  } // end if(m_Output_PDP_BatteryEnergy)

  // If we want to output the battery status...
  if(m_Output_PDP_BatteryStatus) {

    // Output the battery status to the SmartDashboard
    frc::SmartDashboard::PutBoolean(k_BatteryStatusSD_Key,
                                    m_PDP_BatteryStatus);
 
  } // end if(m_Output_PDP_BatteryStatus)

  // If we want to output the left drive train motor 0 current...
  if(m_Output_PDP_LeftDriveTrainMotor0Current) {

    // Output the left drive train motor #0 current, in Amps
    frc::SmartDashboard::PutNumber(k_LeftDriveTrainMotor0SD_Key,
                                     m_PDP_LeftDriveTrainMotor0Current);

  } // end if(m_Output_PDP_LeftDriveTrainMotor0Current)

  // If we want to output the left drive train motor 1 current...
  if(m_Output_PDP_LeftDriveTrainMotor1Current) {

    // Output the left drive train motor #1 current, in Amps
    frc::SmartDashboard::PutNumber(k_LeftDriveTrainMotor1SD_Key,
                                     m_PDP_LeftDriveTrainMotor1Current);

  } // end if(m_Output_PDP_LeftDriveTrainMotor1Current)

  // If we want to output the left drive train current (both motors)...
  if(m_Output_PDP_LeftDriveTrainMotorsCurrent) {

    // Sum the current from the left drive train motors #0 and #1 current
    m_PDP_LeftDriveTrainMotorsCurrent = m_PDP_LeftDriveTrainMotor0Current +
                                        m_PDP_LeftDriveTrainMotor1Current;

    // Output the left drive train motors current, in Amps
    frc::SmartDashboard::PutNumber(k_LeftDriveTrainMotorsSD_Key,
                                     m_PDP_LeftDriveTrainMotorsCurrent);

  } // end if(m_Output_PDP_LeftDriveTrainMotorsCurrent)

  // If we want to output the right drive train motor 0 current...
  if(m_Output_PDP_RightDriveTrainMotor0Current) {

    // Output the right drive train motor #0 current, in Amps
    frc::SmartDashboard::PutNumber(k_RightDriveTrainMotor0SD_Key,
                                     m_PDP_RightDriveTrainMotor0Current);

  } // end if(m_Output_PDP_RightDriveTrainMotor0Current)

  // If we want to output the right drive train motor 1 current...
  if(m_Output_PDP_RightDriveTrainMotor1Current) {

    // Output the right drive train motor #1 current, in Amps
    frc::SmartDashboard::PutNumber(k_RightDriveTrainMotor1SD_Key,
                                     m_PDP_RightDriveTrainMotor1Current);

  } // end if(m_Output_PDP_RightDriveTrainMotor1Current)

  // If we want to output the right drive train current (both motors)...
  if(m_Output_PDP_RightDriveTrainMotorsCurrent) {

    // Sum the current from the right drive train motors #0 and #1 current
    m_PDP_RightDriveTrainMotorsCurrent = m_PDP_RightDriveTrainMotor0Current +
                                         m_PDP_RightDriveTrainMotor1Current;

    // Output the right drive train motors current, in Amps
    frc::SmartDashboard::PutNumber(k_RightDriveTrainMotorsSD_Key,
                                     m_PDP_RightDriveTrainMotorsCurrent);

  } // end if(m_Output_PDP_RightDriveTrainMotorsCurrent)

  // If we want to output the drive train current (all motors)...
  if(m_Output_PDP_DriveTrainMotorsCurrent) {

    // Sum the current from the all the drive train motors
    m_PDP_DriveTrainMotorsCurrent = m_PDP_LeftDriveTrainMotor0Current +
                                    m_PDP_LeftDriveTrainMotor1Current +
                                    m_PDP_RightDriveTrainMotor0Current +
                                    m_PDP_RightDriveTrainMotor1Current;

    // Output the drive train motors current, in Amps
    frc::SmartDashboard::PutNumber(k_DriveTrainMotorsSD_Key,
                                     m_PDP_DriveTrainMotorsCurrent);

  } // end if(m_Output_PDP_DriveTrainMotorsCurrent)

  // If we want to output Capt. Hook motor current...
  if(m_Output_PDP_CaptHookMotorCurrent) {

    // Output Capt. Hook's motor current, in Amps
    frc::SmartDashboard::PutNumber(k_CaptHookMotorSD_Key,
                                     m_PDP_CaptHookMotorCurrent);

  } // if(m_Output_PDP_CaptHookMotorCurrent)

  // If we want to output the roboRIO's X-axis acceleration...
  if(m_Output_roboRIO_Accel_X_Axis) {

    // Output the roboRIO's X-axis accelerometer
    frc::SmartDashboard::PutNumber(k_roboRIO_Accelorometer_X_Axis_Key,
                                     m_roboRIO_Accel_X_Axis);

  } //  end if(m_Output_roboRIO_Accel_X_Axis)

  // If we want to output the roboRIO's Y-axis acceleration...
  if(m_Output_roboRIO_Accel_Y_Axis) {

    // Output the roboRIO's Y-axis accelerometer
    frc::SmartDashboard::PutNumber(k_roboRIO_Accelorometer_Y_Axis_Key,
                                     m_roboRIO_Accel_Y_Axis);

  } // end if(m_Output_roboRIO_Accel_Y_Axis)

  // If we want to output the roboRIO's Z-axis acceleration...
  if(m_Output_roboRIO_Accel_Z_Axis) {

    // Output the roboRIO's Z-axis accelerometer
    frc::SmartDashboard::PutNumber(k_roboRIO_Accelorometer_Z_Axis_Key,
                                     m_roboRIO_Accel_Z_Axis);

  } // if(m_Output_roboRIO_Accel_Z_Axis)

  // If we want to output the roboRIO's input voltage...
  if(m_Output_roboRIO_InputVoltage) {

    // Output the roboRIO's input voltage
    frc::SmartDashboard::PutNumber(k_roboRIO_InputVoltage_Key,
                                     m_roboRIO_InputVoltage);

  } // end if(m_Output_roboRIO_InputVoltage)

  // If we want to output the roboRIO's input current...
  if(m_Output_roboRIO_InputCurrent) {

    // Output the roboRIO's input current
    frc::SmartDashboard::PutNumber(k_roboRIO_InputCurrent_Key,
                                     m_roboRIO_InputCurrent);

  } // end if(m_Output_roboRIO_InputCurrent)

  // If we want to output the roboRIO's input power...
  if(m_Output_roboRIO_InputPower) {

    // Output the roboRIO's input power
    frc::SmartDashboard::PutNumber(k_roboRIO_InputPower_Key,
                                     m_roboRIO_InputVoltage *
                                     m_roboRIO_InputCurrent);

  } // end if(m_Output_roboRIO_InputPower)

  // If we want to output the roboRIO's 3.3V rail voltage...
  if(m_Output_roboRIO_3_3V_Rail_Voltage) {

    // Output the roboRIO's 3.3V rail voltage
    frc::SmartDashboard::PutNumber(k_roboRIO_3V3_Voltage_Key,
                                     m_roboRIO_3_3V_Rail_Voltage);

  } // end if(m_Output_roboRIO_3_3V_Rail_Voltage)

  // If we want to output the roboRIO's 3.3V rail current...
  if(m_Output_roboRIO_3_3V_Rail_Current) {

    // Output the roboRIO's 3.3V rail current
    frc::SmartDashboard::PutNumber(k_roboRIO_3V3_Current_Key,
                                     m_roboRIO_3_3V_Rail_Current);

  } // end if(m_Output_roboRIO_3_3V_Rail_Current)

  // If we want to output the roboRIO's 3.3V rail enabled status...
  if(m_Output_roboRIO_3_3V_Rail_IsEnabled) {

    // Output the roboRIO's 3.3V rail enabled status
    frc::SmartDashboard::PutBoolean(k_roboRIO_3V3_Enabled_Key,
                                      m_roboRIO_3_3V_Rail_IsEnabled);

  } // end if(m_Output_roboRIO_3_3V_Rail_IsEnabled)

  // If we want to output the roboRIO's 3.3V rail fault count...
  if(m_Output_roboRIO_3_3V_Rail_FaultCount) {

    // Output the roboRIO's 3.3V rail fault count
    frc::SmartDashboard::PutNumber(k_roboRIO_3V3_Faults_Key,
                                     m_roboRIO_3_3V_Rail_FaultCount);

  } // end if(m_Output_roboRIO_3_3V_Rail_FaultCount)

  // If we want to output the roboRIO's 5V rail voltage...
  if(m_Output_roboRIO_5V_Rail_Voltage) {

    // Output the roboRIO's 5V rail voltage
    frc::SmartDashboard::PutNumber(k_roboRIO_5V_Voltage_Key,
                                     m_roboRIO_5V_Rail_Voltage);

  } // end if(m_Output_roboRIO_5V_Rail_Voltage)

  // If we want to output the roboRIO's 5V rail current...
  if(m_Output_roboRIO_5V_Rail_Current) {

    // Output the roboRIO's 5V rail current
    frc::SmartDashboard::PutNumber(k_roboRIO_5V_Current_Key,
                                     m_roboRIO_5V_Rail_Current);

  } // end if(m_Output_roboRIO_5V_Rail_Current)

  // If we want to output the roboRIO's 5V rail enabled status...
  if(m_Output_roboRIO_5V_Rail_IsEnabled) {

    // Output the roboRIO's 5V rail enabled status
    frc::SmartDashboard::PutBoolean(k_roboRIO_5V_Enabled_Key,
                                      m_roboRIO_5V_Rail_IsEnabled);

  } // end if(m_Output_roboRIO_5V_Rail_IsEnabled)

  // If we want to output the roboRIO's 5V rail fault count...
  if(m_Output_roboRIO_5V_Rail_FaultCount) {

    // Output the roboRIO's 5V rail fault count
    frc::SmartDashboard::PutNumber(k_roboRIO_5V_Faults_Key,
                                     m_roboRIO_5V_Rail_FaultCount);

  } // end if(m_Output_roboRIO_5V_Rail_FaultCount)

  // If we want to output the roboRIO's 6V rail voltage...
  if(m_Output_roboRIO_6V_Rail_Voltage) {

    // Output the roboRIO's 6V rail voltage
    frc::SmartDashboard::PutNumber(k_roboRIO_6V_Voltage_Key,
                                     m_roboRIO_6V_Rail_Voltage);

  } // end if(m_Output_roboRIO_6V_Rail_Voltage)

  // If we want to output the roboRIO's 6V rail current...
  if(m_Output_roboRIO_6V_Rail_Current) {

    // Output the roboRIO's 6V rail current
    frc::SmartDashboard::PutNumber(k_roboRIO_6V_Current_Key,
                                     m_roboRIO_6V_Rail_Current);

  } // end if(m_Output_roboRIO_6V_Rail_Current)

  // If we want to output the roboRIO's 6V rail enabled status...
  if(m_Output_roboRIO_5V_Rail_IsEnabled) {

    // Output the roboRIO's 6V rail enabled status
    frc::SmartDashboard::PutBoolean(k_roboRIO_6V_Enabled_Key,
                                      m_roboRIO_6V_Rail_IsEnabled);

  } // end if(m_Output_roboRIO_6V_Rail_IsEnabled)

  // If we want to output the roboRIO's 6V rail fault count...
  if(m_Output_roboRIO_6V_Rail_FaultCount) {

    // Output the roboRIO's 6V rail fault count
    frc::SmartDashboard::PutNumber(k_roboRIO_6V_Faults_Key,
                                     m_roboRIO_6V_Rail_FaultCount);

  } // end if(m_Output_roboRIO_6V_Rail_FaultCount)

    // If we want to output the roboRIO's brown out status
  if(m_Output_roboRIO_IsBrownedOut) {

    // Output the roboRIO's brown out status. However, we want to 
    // actually output if power is okay, and not a message stating
    // "NO BROWN OUT". So we will invert it.
    frc::SmartDashboard::PutBoolean(k_roboRIO_IsBrownedOut_Key,
                                    !m_roboRIO_IsBrownedOut);

  } // end if(m_Output_roboRIO_IsBrownedOut)

  // If we want to output the roboRIO's system active status
  if(m_Output_roboRIO_IsSysActive) {

    // Output the roboRIO's system active status 
    frc::SmartDashboard::PutBoolean(k_roboRIO_IsSysActive_Key,
                                    m_roboRIO_IsSysActive);

  } // end if(m_Output_roboRIO_IsSysActive)

  // If we want to output the roboRIO's FPGA Version, Revision, Build
  if(m_Output_roboRIO_FPGA_VerNumRev) {

    // Declare a string for the FPGA Version, Revision, and Build
    std::string VersionNumber_Revision_Build;

    // Compute the major revision
    m_roboRIO_FPGA_MajorRevision =
      GetMajorRevisionFromFPGARevision(m_roboRIO_FPGA_Revision);

    // Compute the minor revision
    m_roboRIO_FPGA_MinorRevision =
      GetMinorRevisionFromFPGARevision(m_roboRIO_FPGA_Revision);

    // Compute the build number
    m_roboRIO_FPGA_BuildNumber =
      GetBuildNumberFromFPGARevision(m_roboRIO_FPGA_Revision);

    // And put it all together in the string
    VersionNumber_Revision_Build =
        std::to_string(m_roboRIO_FPGA_VersionNumber)
      + "."
      + std::to_string(m_roboRIO_FPGA_MajorRevision)
      + "."
      + std::to_string(m_roboRIO_FPGA_MinorRevision)
      + " Build "
      + std::to_string(m_roboRIO_FPGA_BuildNumber);

    // Output the roboRIO's FPGA Version, Revision, Build
    frc::SmartDashboard::PutString(k_roboRIO_FPGA_VerNumRev_Key,
                                   VersionNumber_Revision_Build);

  } // end if(m_Output_roboRIO_FPGA_VerNumRev)

  // If we want to output the roboRIO's FPGA time elapsed since last boot
  if(m_Output_roboRIO_FPGA_Time) {

    // Output the roboRIO's FPGA time elapsed since last boot
    frc::SmartDashboard::PutNumber(k_roboRIO_FPGA_Time_Key,
                                     m_roboRIO_FPGA_Time);

  } // end if(m_Output_roboRIO_FPGA_Time)

// If we are using Capt. Hook with a PID controller...
#if USE_PID_CAPT_HOOK

  // If we want to output Capt. Hook's potentimeter value...
  if(m_Output_CaptHook_PotValue) {

    // Output Capt. Hook's potentiometer value
    frc::SmartDashboard::PutNumber(k_CaptHookPotValue_Key,
                                   m_CaptHook_PotValue);

  } // end if(m_Output_CaptHook_PotValue)

  // If we want to output the state of Capt. Hook...
  if(m_Output_CaptHookState) {

    // Output the state of Capt. Hook
    frc::SmartDashboard::PutString(k_CaptHookStatus_Key,
                                   m_CaptHookState);

  } // end if(m_Output_CaptHookState)

#endif // #if USE_PID_CAPT_HOOK

} // end CmdOutputTelemetry::OutputTelemetry()
