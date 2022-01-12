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
 * Copyright (c) 2019-2020 FRC Team #7464 - ORION. All Rights Reserved.
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

  // If we want to output PAT Turner's motor current...
  if(m_Output_PDP_PATTurnerMotorCurrent) {

    // Output PAT Turner's motor current
    frc::SmartDashboard::PutNumber(k_PATTurnerMotorSD_Key,
                                     m_PDP_PATTurnerMotorCurrent);

  } //  end if(m_Output_PDP_PATTurnerMotorCurrent)

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

  // If we want to output Pssh's motor current...
  if(m_Output_PDP_PsshMotorCurrent) {

    // Output Pssh's motor current
    frc::SmartDashboard::PutNumber(k_PsshMotorSD_Key,
                                     m_PDP_PsshMotorCurrent);

  } //  end if(m_Output_PDP_PsshMotorCurrent)

#endif // #if USE_PID_PSSH

  // If we want to output H/F Arms's motor current...
  if(m_Output_PDP_H_F_ArmsMotorCurrent) {

    // Output H/F Arms's motor current
    frc::SmartDashboard::PutNumber(k_H_F_ArmsMotorSD_Key,
                                     m_PDP_H_F_ArmsMotorCurrent);

  } //  end if(m_Output_PDP_PATTurnerMotorCurrent)

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

  // If we want to output the angle of Pssh...
  if(m_Output_PsshPotAngle) {

    // Output Pssh's angle
    frc::SmartDashboard::PutNumber(k_PsshPotAngleSD_Key,
                                   m_PsshPotAngle);

  } // end if(m_Output_PsshPotAngle)

#endif // #if USE_PID_PSSH

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

  // If we want to output the drive train turbo mode string...
  if(m_Output_DriveTrainTurboState) {

    // Output the state of the drive train turbo mode
    frc::SmartDashboard::PutString(k_DriveTrainTurboStatus_Key,
                                   m_DriveTrainTurboState);

  } // end if(m_Output_DriveTrainModeString)

  // If we want to output the drive train smoothing mode string...
  if(m_Output_DriveTrainSmoothingState) {

    // Output the state of the drive train turbo mode
    frc::SmartDashboard::PutString(k_DriveTrainSmoothingStatus_Key,
                                   m_DriveTrainSmoothingState);

  } // end if(m_Output_DriveTrainSmoothingState)

  // If we want to output the AHRS connection status
  if(m_Output_AHRS_ConnectionStatus)
  {

    // Output the AHRS connection status 
    frc::SmartDashboard::PutBoolean(k_AHRS_ConnectionStatus_Key,
                                    m_AHRS_ConnectionStatus);

  } // end if(m_Output_AHRS_ConnectionStatus)

  // If we want to output the calibration status of the AHRS
  if(m_Output_AHRS_CalibrationStatus)
  {

    // Output the AHRS calibration status 
    // Status is reversed because Calibrating is true, and
    // Calibrated is false. We want Calibrated to be green (true),
    // and calibrating to be red (false).
    frc::SmartDashboard::PutBoolean(k_AHRS_CalibrationStatus_Key,
                                    !m_AHRS_CalibrationStatus);

  } // end if(m_Output_AHRS_CalibrationStatus)

  // If we want to output the pitch of the AHRS
  if(m_Output_AHRS_Pitch)
  {

    // Output the AHRS pitch 
    frc::SmartDashboard::PutNumber(k_AHRS_Pitch_Key,
                                   m_AHRS_Pitch);

  } // end if(m_Output_AHRS_Pitch)

  // If we want to output the roll of the AHRS
  if(m_Output_AHRS_Roll)
  {

    // Output the AHRS roll
    frc::SmartDashboard::PutNumber(k_AHRS_Roll_Key,
                                   m_AHRS_Roll);

  } // end if(m_Output_AHRS_Roll)

  // If we want to output the yaw of the AHRS
  if(m_Output_AHRS_Yaw)
  {

    // Output the AHRS yaw 
    frc::SmartDashboard::PutNumber(k_AHRS_Yaw_Key,
                                   m_AHRS_Yaw);

  } // end if(m_Output_AHRS_Yaw)

  // If we want to output the compass heading of the AHRS
  if(m_Output_AHRS_CompassHdg)
  {

    // Output the AHRS compass heading 
    frc::SmartDashboard::PutNumber(k_AHRS_CompassHeading_Key,
                                   m_AHRS_CompassHdg);

  } // end if(m_Output_AHRS_CompassHdg)

  // If we want to output the X-axis linear acceleration of the AHRS
  if(m_Output_AHRS_LinearAccelX)
  {

    // Output the AHRS X-axis linear acceleration
    frc::SmartDashboard::PutNumber(k_AHRS_LinearAccelX_Key,
                                   m_AHRS_LinearAccelX);

  } // end if(m_Output_AHRS_LinearAccelX)

  // If we want to output the Y-axis linear acceleration of the AHRS
  if(m_Output_AHRS_LinearAccelY)
  {

    // Output the AHRS Y-axis linear acceleration
    frc::SmartDashboard::PutNumber(k_AHRS_LinearAccelY_Key,
                                   m_AHRS_LinearAccelY);

  } // end if(m_Output_AHRS_LinearAccelY)

  // If we want to output the Z-axis linear acceleration of the AHRS
  if(m_Output_AHRS_LinearAccelZ)
  {

    // Output the AHRS Z-axis linear acceleration
    frc::SmartDashboard::PutNumber(k_AHRS_LinearAccelZ_Key,
                                   m_AHRS_LinearAccelZ);

  } // end if(m_Output_AHRS_LinearAccelZ)

  // If we want to output the status of the AHRS moving
  if(m_Output_AHRS_Moving)
  {

    // Output the AHRS moving status
    frc::SmartDashboard::PutBoolean(k_AHRS_Moving_Key,
                                    m_AHRS_Moving);

  } // end if(m_Output_AHRS_Moving)

  // If we want to output the status of the AHRS rotating
  if(m_Output_AHRS_Rotating)
  {

    // Output the AHRS rotating status
    frc::SmartDashboard::PutBoolean(k_AHRS_Rotating_Key,
                                    m_AHRS_Rotating);

  } // end if(m_Output_AHRS_Rotating)

  // If we want to output the fused heading of the AHRS
  if(m_Output_AHRS_FusedHdg)
  {

    // Output the AHRS fused heading
    frc::SmartDashboard::PutNumber(k_AHRS_FusedHdg_Key,
                                   m_AHRS_FusedHdg);

  } // end if(m_Output_AHRS_FusedHdg)

  // If we want to see if the AHRS is experiencing magnetic disturbance
  if(m_Output_AHRS_MagDisturb)
  {

    // Output the AHRS magnetic disturbance status
    // Note: m_AHRS_MagDisturb is true if in magnetic disturbance,
    //       false if not. But we want green(true) when we are not
    //       in a disturbance, and red when we are. Hence, the
    //       negation. 
    frc::SmartDashboard::PutBoolean(k_AHRS_MagDisturb_Key,
                                   !m_AHRS_MagDisturb);

  } // end if(m_Output_AHRS_MagDisturb)

  // If we want to output the magnetometer calibration status of the AHRS
  if(m_Output_AHRS_MgntmtrCalStatus)
  {

    // Output the AHRS magnetometer calibration status 
    // Note: m_AHRS_MgntmtrCalStatus is true when the magnetometer,
    //       is calibrating, false if not. But we want green(true) 
    //       when we are not calibrating, but calibrated, and
    //       red when we are calibrating. Hence, the negation. 
    frc::SmartDashboard::PutBoolean(k_AHRS_IsMgntmtrCal_Key,
                                    !m_AHRS_MgntmtrCalStatus);

  } // end if(m_Output_AHRS_MgntmtrCalStatus)
  
  // If we want to output the Quaternion W of the AHRS
  if(m_Output_AHRS_QuatW)
  {

    // Output the AHRS quaternion of W
    frc::SmartDashboard::PutNumber(k_AHRS_QuatW_Key,
                                   m_AHRS_QuatW);

  } // end if(m_Output_AHRS_QuatW)

  // If we want to output the Quaternion X of the AHRS
  if(m_Output_AHRS_QuatX)
  {

    // Output the AHRS quaternion of X
    frc::SmartDashboard::PutNumber(k_AHRS_QuatX_Key,
                                   m_AHRS_QuatX);

  } // end if(m_Output_AHRS_QuatX)

  // If we want to output the Quaternion Y of the AHRS
  if(m_Output_AHRS_QuatY)
  {

    // Output the AHRS quaternion of Y
    frc::SmartDashboard::PutNumber(k_AHRS_QuatY_Key,
                                   m_AHRS_QuatY);

  } // end if(m_Output_AHRS_QuatY)

  // If we want to output the Quaternion Z of the AHRS
  if(m_Output_AHRS_QuatZ)
  {

    // Output the AHRS quaternion of Z
    frc::SmartDashboard::PutNumber(k_AHRS_QuatZ_Key,
                                   m_AHRS_QuatZ);

  } // end if(m_Output_AHRS_QuatZ)

  // If we want to output the AHRS yaw angle
  if(m_Output_AHRS_YawAngle)
  {

    // Output the AHRS yaw angle
    frc::SmartDashboard::PutNumber(k_AHRS_YawAngle_Key,
                                  m_AHRS_YawAngle);

  } // end if(m_Output_AHRS_YawAngle)

  // If we want to output the AHRS yaw angle adjustment
  if(m_Output_AHRS_YawAngleAdj)
  {

    // Output the AHRS yaw angle adjustment
    frc::SmartDashboard::PutNumber(k_AHRS_YawAngleAdj_Key,
                                   m_AHRS_YawAngleAdj);

  } // end if(m_Output_AHRS_YawAngleAdj)

  // If we want to output the AHRS rotation rate
  if(m_Output_AHRS_RotRate)
  {

    // Output the AHRS rotation rate
    frc::SmartDashboard::PutNumber(k_AHRS_RotRate_Key,
                                   m_AHRS_RotRate);

  } // end if(m_Output_AHRS_RotRate)

  // If we want to output the AHRS temperature
  if(m_Output_AHRS_Temp_F)
  {

    // Output the AHRS temperature in F
    frc::SmartDashboard::PutNumber(k_AHRS_Temp_Key,
                                   m_AHRS_Temp_F);

  } // end if(m_Output_AHRS_Temp_F)

  // If we want to output the AHRS firmware version
  if(m_Output_AHRS_FWVer)
  {

    // Output the AHRS firmware version
    frc::SmartDashboard::PutString(k_AHRS_FWVer_Key,
                                  m_AHRS_FWVer);

  } // end if(m_Output_AHRS_FWVer)

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

  // If we want to output the state of Pssh
  if(m_Output_Pssh_State)
  {

    // Output the state of Pssh
    frc::SmartDashboard::PutString(k_Pssh_State_Key,
                                   m_Pssh_State);

  } // end if(m_Output_Pssh_State)

#endif // #if USE_PID_PSSH

  // If we want to output the drive direction
  if(m_Output_drive_dir)
  {

    // Output the drive direction
    frc::SmartDashboard::PutString(k_drive_dir_Key,m_drive_dir);

  } // end if(m_Output_drive_dir)

  // If we want to output if the arms are enabled...
  if(m_Output_HansFranzArmsEnabled)
  {

    // Output if Arms are enabled 
    frc::SmartDashboard::PutBoolean(k_HansFranzArmsEnabled_Key,
                                    m_HansFranzArmsEnabled);

  } // end if(m_Output_HansFranzArmsEnabled)

  // If we want to output if the muscles are enabled...
  if(m_Output_HansFranzMusclesEnabled)
  {

    // Output if muscles are enabled 
    frc::SmartDashboard::PutBoolean(k_HansFranzMusclesEnabled_Key,
                                    m_HansFranzMusclesEnabled);

  } // end if(m_Output_HansFranzArmsEnabled)

  // If we want to output the state of the arms
  if(m_Output_HansFranzArmsState)
  {

    // Output the state of the arms 
    frc::SmartDashboard::PutString(k_HansFranzArmsState_Key,
                                   m_HansFranzArmsState);

  } // end if(m_Output_HansFranzArmsEnabled)
  
  // If we want to output the state of the muscles
  if(m_Output_HansFranzMusclesState)
  {

    // Output the state of the muscles
    frc::SmartDashboard::PutString(k_HansFranzMusclesState_Key,
                                   m_HansFranzMusclesState);

  } // end if(m_Output_HansFranzArmsEnabled)

  // If we want to output the boolean to indicate if arms are fully retracted
  if(m_Output_HansFranzArmsRetracted)
  {

    // Output the boolean to indicate if arms are fully retracted
    frc::SmartDashboard::PutBoolean(k_HansFranzArmsRetractedLSState_Key,
                                    m_HansFranzArmsRetracted);

  } // end if(m_Output_HansFranzArmsRetracted)

  // If we want to output the boolean to indicate if arms are fully extended
  if(m_Output_HansFranzArmsExtended)
  {

    // Output the boolean to indicate if arms are fully extended
    frc::SmartDashboard::PutBoolean(k_HansFranzArmsExtendedLSState_Key,
                                    m_HansFranzArmsExtended);

  } // end if(m_Output_HansFranzArmsExtended)

} // end CmdOutputTelemetry::OutputTelemetry()
