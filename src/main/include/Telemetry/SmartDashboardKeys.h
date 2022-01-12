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

/**
 * The Smartdashboard key string for drive train mode.
 * Expected values are "ARCADE" or "TANK"
*/
const std::string k_DriveTrainMode_Key = "DT Mode";

/**
 * The Smartdashboard key string for robot temperature.
 * Typical range is 40F-100F. 
*/
const std::string k_RobotTemperatureSD_Key = "Temp (F)";

/**
 * The Smartdashboard key string for robot operating temperature status
 * Expected value is true (within operating range). 
*/
const std::string k_PDP_OperatingTemperatureStatusSD_Key = "Temp OK";

/**
 * The Smartdashboard key string for battery voltage.
 * Typical range is 12.0V-14.4V.
*/
const std::string k_BatteryVoltageSD_Key = "Batt V(V)";

/**
 * The Smartdashboard key string for battery voltage status.
*/
const std::string k_BatteryVoltageStatusSD_Key = "Batt Volt OK";

/**
 * The Smartdashboard key string for battery current.
 * Typical range is 0A-120A (limited by the 120A circuit breaker).
*/
const std::string k_BatteryCurrentSD_Key = "Batt C(A)";

/**
 * The Smartdashboard key string for battery current status
*/
const std::string k_BatteryCurrentStatusSD_Key = "Batt Curr OK";

/**
 * The Smartdashboard key string for battery power.
 * Typical range is 0W-1500W.
*/
const std::string k_BatteryPowerSD_Key = "Batt P(W)";

/**
 * The Smartdashboard key string for battery energy.
 * Typical range is 0J-??J
 */
const std::string k_BatteryEnergySD_Key = "Batt E(J)";

/**
 * The Smartdashboard key string for battery status
*/
const std::string k_BatteryStatusSD_Key = "Batt OK";

/** 
 * The Smartdashboard key string for left drive train motor #0.
 * Typical range is 0A-40A.
 */
const std::string k_LeftDriveTrainMotor0SD_Key = "LDTM0 C(A)";

/**
 * The Smartdashboard key string for left drive train motor #1.
 * Typical range is 0A-40A.
*/
const std::string k_LeftDriveTrainMotor1SD_Key = "LDTM1 C(A)";

/**
 * The Smartdashboard key string for left drive train, both motors.
 * Typical range is 0A-80A.
*/
const std::string k_LeftDriveTrainMotorsSD_Key = "LDT C(A)";

/**
 * The Smartdashboard key string for right drive train motor #0.
 * Typical range is 0A-40A.
*/
const std::string k_RightDriveTrainMotor0SD_Key = "RDTM0 C(A)";

/**
 * The Smartdashboard key string for right drive train motor #1.
 * Typical range is 0A-40A.
*/
const std::string k_RightDriveTrainMotor1SD_Key = "RDTM1 C(A)";

/**
 * The Smartdashboard key string for right drive train, both motors.
 * Typical range is 0A-80A.
*/
const std::string k_RightDriveTrainMotorsSD_Key = "RDT C(A)";

/**
 * The Smartdashboard key string for the drive train, all motors.
 * Typical range is 0A-120A.
*/
const std::string k_DriveTrainMotorsSD_Key = "DT C(A)";

/**
 * The Smartdashboard key string for the PAT Turner current.
 * Typical range is 0A-40A.
*/
const std::string k_PATTurnerMotorSD_Key = "PAT C(A)";

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

/**
 * The Smartdashboard key string for the Pssh current.
 * Typical range is 0A-40A.
*/
const std::string k_PsshMotorSD_Key = "Pssh C(A)";

#endif // #if USE_PID_PSSH

/**
 * The Smartdashboard key string for the H/F Arms current.
 * Typical range is 0A-40A.
*/
const std::string k_H_F_ArmsMotorSD_Key = "H-F Arms C(A)";

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

/**
 * The Smartdashboard key string for the Pssh potentiometer
 * Typical range is -35 to 220 degrees.
 */
 const std::string k_PsshPotAngleSD_Key = "Pssh Angle (°)";

#endif // #if USE_PID_PSSH

/**
 * The Smartdashboard key string for roboRIO X-axis accelerometer.
 * Typical range is -8G to +8G.
*/
const std::string k_roboRIO_Accelorometer_X_Axis_Key = "X-Axis A(G)";

/**
 * The Smartdashboard key string for roboRIO Y-axis accelerometer.
 * Typical range is -8G to +8G.
*/
const std::string k_roboRIO_Accelorometer_Y_Axis_Key = "Y-Axis A(G)";

/**
 * The Smartdashboard key string for roboRIO Z-axis accelerometer.
 * Typical range is -8G to +8G.
*/
const std::string k_roboRIO_Accelorometer_Z_Axis_Key = "Z-Axis A(G)";

/**
 * The Smartdashboard key string for roboRIO input power status.
 * Typical range is 7V-16V.
*/
const std::string k_roboRIO_InputVoltage_Key = "CTL V_IN(V)";

/**
 * The Smartdashboard key string for roboRIO input supply status
 * Expected value is true
*/
const std::string k_roboRIO_StatusOK_Key = "CTL V_IN OK";

/**
 * The Smartdashboard key string for roboRIO input current.
 * Typical range is 0.25A-6.5A.
*/
const std::string k_roboRIO_InputCurrent_Key = "CTL I_IN(A)";

/**
 * The Smartdashboard key string for roboRIO input power.
 * Typical range is 1.75W - 104W.
*/
const std::string k_roboRIO_InputPower_Key = "CTL P_IN(W)";

/**
 * The Smartdashboard key string for roboRIO 3.3V rail voltage.
 * Typical range is 3.1V-3.465V.
*/
const std::string k_roboRIO_3V3_Voltage_Key = "CTL 3.3V V(V)";

/**
 * The Smartdashboard key string for roboRIO 3.3V rail current.
 * Typical range is 0A-1.225A.
*/
const std::string k_roboRIO_3V3_Current_Key = "CTL 3.3V I(A)";

/**
 * The Smartdashboard key string for roboRIO 3.3V rail enabled status.
 * Range is true/false. Expected value is true.
*/
const std::string k_roboRIO_3V3_Enabled_Key = "CTL 3.3V ENBLD";

/**
 * The Smartdashboard key string for roboRIO 3.3V rail fault count.
 * Typical value should be 0.
*/
const std::string k_roboRIO_3V3_Faults_Key = "CTL 3.3V FAULTS";

/**
 * The Smartdashboard key string for roboRIO 5V rail voltage.
 * Typical range is 4.7V-5.25V.
*/
const std::string k_roboRIO_5V_Voltage_Key = "CTL 5V V(V)";

/**
 * The Smartdashboard key string for roboRIO 5V rail current.
 * Typical range is 0A-1.0A.
*/
const std::string k_roboRIO_5V_Current_Key = "CTL 5V I(A)";

/**
 * The Smartdashboard key string for roboRIO 5V rail enabled status.
 * Range is true/false. Expected value is true.
*/
const std::string k_roboRIO_5V_Enabled_Key = "CTL 5V ENBLD";

/**
 * The Smartdashboard key string for roboRIO 5V rail fault count.
 * Typical value should be 0.
*/
const std::string k_roboRIO_5V_Faults_Key = "CTL 5V FAULTS";

/**
 * The Smartdashboard key string for roboRIO 6V rail voltage.
 * Typical range is 5.5V-6.1V.
*/
const std::string k_roboRIO_6V_Voltage_Key = "CTL 6V V(V)";

/**
 * The Smartdashboard key string for roboRIO 6V rail current.
 * Typical range is 0A-2.2A.
*/
const std::string k_roboRIO_6V_Current_Key = "CTL 6V I(A)";

/**
 * The Smartdashboard key string for roboRIO 6V rail enabled status.
 * Range is true/false. Expected value is true.
*/
const std::string k_roboRIO_6V_Enabled_Key = "CTL 6V ENBLD";

/**
 * The Smartdashboard key string for roboRIO 5V rail fault count.
 * Typical value should be 0.
*/
const std::string k_roboRIO_6V_Faults_Key = "CTL 6V FAULTS";

/**
 * The Smartdashboard key string for roboRIO Power OK.
 * "Power OK" means that there is not currently a brown out.
 * Range is true/false. Expected value is true.
*/
const std::string k_roboRIO_IsBrownedOut_Key = "POWER OK";

/**
 * The Smartdashboard key string for roboRIO System Active.
 * Range is true/false. Expected value is false when
 * system is disabled, true when enabled
*/
const std::string k_roboRIO_IsSysActive_Key = "SYS ACTV";

/**
 * The Smartdashboard key string for roboRIO FPGA time.
 * Expected range is 0-900,000,000 (15 minutes)
*/
const std::string k_roboRIO_FPGA_Time_Key = "FPGA Time(uS)";

/**
 * The Smartdashboard key string for roboRIO FPGA version,
 * revision (major/minor), and build number.
*/
const std::string k_roboRIO_FPGA_VerNumRev_Key = "FPGA Ver.";

/**
 * The SmartDashboard key string for drive train turbo status
*/
const std::string k_DriveTrainTurboStatus_Key = "Turbo Status";

/**
 * The SmartDashboard key string for drive train smoothing status
*/
const std::string k_DriveTrainSmoothingStatus_Key = "Smooth Status";

/******************************** AHRS *************************************/

/** The SmartDashboard key string for AHRS connection status */
const std::string k_AHRS_ConnectionStatus_Key = "AHRS Cnct'd";

/** The SmartDashboard key string for AHRS calibration */
const std::string k_AHRS_CalibrationStatus_Key = "AHRS Cal'd";

/** The SmartDashboard key string for AHRS Pitch */
const std::string k_AHRS_Pitch_Key = "Pitch";

/** The SmartDashboard key string for AHRS Roll */
const std::string k_AHRS_Roll_Key = "Roll";

/** The SmartDashboard key string for AHRS Yaw */
const std::string k_AHRS_Yaw_Key = "Yaw";

/** The SmartDashboard key string for AHRS Compass Heading */
const std::string k_AHRS_CompassHeading_Key = "Compass Hdg";

/** The SmartDashboard key string for AHRS Linear Acceleration, X-axis */
const std::string k_AHRS_LinearAccelX_Key = "Linear X Accel";

/** The SmartDashboard key string for AHRS Linear Acceleration, Y-axis */
const std::string k_AHRS_LinearAccelY_Key = "Linear Y Accel";

/** The SmartDashboard key string for AHRS Linear Acceleration, Z-axis */
const std::string k_AHRS_LinearAccelZ_Key = "Linear Z Accel";

/** The SmartDashboard key string for AHRS IsMoving */
const std::string k_AHRS_Moving_Key = "Moving";

/** The SmartDashboard key string for AHRS IsRotating */
const std::string k_AHRS_Rotating_Key = "Rotating";

/** The SmartDashboard key string for AHRS Fused Heading */
const std::string k_AHRS_FusedHdg_Key = "Fused Hdg";

/** The SmartDashboard key string for AHRS Magnetic Disturbance */
const std::string k_AHRS_MagDisturb_Key = "No Mag Disturb";

/** The SmartDashboard key string for AHRS Is Magnetometer Calibrated */
const std::string k_AHRS_IsMgntmtrCal_Key = "Mgntmtr Cal'd";

/** The SmartDashboard key string for AHRS Quaternion W */
const std::string k_AHRS_QuatW_Key = "Quat W";

/** The SmartDashboard key string for AHRS Quaternion X */
const std::string k_AHRS_QuatX_Key = "Quat X";

/** The SmartDashboard key string for AHRS Quaternion Y */
const std::string k_AHRS_QuatY_Key = "Quat Y";

/** The SmartDashboard key string for AHRS Quaternion Z */
const std::string k_AHRS_QuatZ_Key = "Quat Z";

/** The SmartDashboard key string for AHRS Yaw Angle */
const std::string k_AHRS_YawAngle_Key = "Yaw Angle";

/** The SmartDashboard key string for AHRS Yaw Angle Adjustment*/
const std::string k_AHRS_YawAngleAdj_Key = "Yaw Angle Adj";

/** The SmartDashboard key string for AHRS Rotation Rate */
const std::string k_AHRS_RotRate_Key = "Rot. Rate";

/** The SmartDashboard key string for AHRS Temperature */
const std::string k_AHRS_Temp_Key = "AHRS Temp.";

/** The SmartDashboard key string for AHRS Firmware Version */
const std::string k_AHRS_FWVer_Key = "AHRS FW Ver.";

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

/** The SmartDashboard key string for the state of Pssh */
const std::string k_Pssh_State_Key = "Pssh State";

#endif // #if USE_PID_PSSH

/** The SmartDashboard key string for the drive direction */
const std::string k_drive_dir_Key = "Drive Front";

/** The SmartDashboard key string for the H/F arms being enabled */
const std::string k_HansFranzArmsEnabled_Key = "Arms Enabled";

/** The SmartDashboard key string for the H/F muscles being enabled */
const std::string k_HansFranzMusclesEnabled_Key = "Muscles Enabled";

/** The SmartDashboard key string for the state of H/F arms */
const std::string k_HansFranzArmsState_Key = "Arms State";

/** The SmartDashboard key string for the state of H/F muscles */
const std::string k_HansFranzMusclesState_Key = "Muscles State";

/** The SmartDashboard key string for H/F Arms Retracted LS */
const std::string k_HansFranzArmsRetractedLSState_Key = "Arms Fully Retracted";

/** The SmartDashboard key string for H/F Arms Extended LS */
const std::string k_HansFranzArmsExtendedLSState_Key = "Arms Fully Extended";

#endif // #ifndef SMARTDASHBOARDKEYS_H
