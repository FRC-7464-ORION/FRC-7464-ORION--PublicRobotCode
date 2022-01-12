/** ===========================================================================
 * @file   TelemetryOutputter.h
 * @brief  This file declares the TelemetryOutputter class.
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

// INCLUDE GUARD - see https://en.wikipedia.org/wiki/Include_guard
// If we have not already defined TELEMETRYOUTPUTTER_H...
#ifndef TELEMETRYOUTPUTTER_H
// Define TELEMETRYOUTPUTTER_H
#define TELEMETRYOUTPUTTER_H

/*************************** Local Header Files *******************************/

// Include our constants header file
#include "RobotConstants.h"

// Include the SmartDashboard Keys header file
#include "Telemetry/SmartDashboardKeys.h"

/************************** Library Header Files ******************************/

// Include the header file to declare strings
#include <string>

// Include the header file for the Command class
#include <frc/commands/Command.h>

// Include the SmartDashboard class header file, which allows us to transmit
//   robot data to the operator console
// See:
// https://wpilib.screenstepslive.com/s/currentCS/m/smartdashboard
#include <frc/smartdashboard/SmartDashboard.h>

// Include the header file for the Power Distribution Panel
#include <frc/PowerDistributionPanel.h>

// Include the header file for the roboRIO internal accelerometers
#include <frc/BuiltInAccelerometer.h>

// Include the header file for the roboRIO controller telemetry
#include <frc/RobotController.h>

/** ****************************************************************************
 * @class   TelemetryOutputter
 * @brief   This is a class that provides a means to output general
 *            robot telemetry back to the driver station via the
 *            SmartDashboard.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class TelemetryOutputter {

  public:

    /** The TelemetryOutputter class default constructor. */
    TelemetryOutputter();

    /** The TelemetryOutputter class destructor. */
    ~TelemetryOutputter();

    /** Method to output the telemetry to the Smart Dashboard */
    void OutputTelemetryToSmartDashboard();

  private:

    /********************* Private member variables ***********************/

    /////////// Member variables for various telemetry deliverers ///////////

    /** Declare a pointer to a power distribution panel (PDP) instance */
    frc::PowerDistributionPanel* m_pdp;

    /** Declare a pointer to roboRIO's internal accelerometers instance */
    frc::BuiltInAccelerometer* m_roboRIO_accelerometers;

    ///////////////// Member variable for storing telemetry /////////////////

    /** A string to hold the drive train mode */
    std::string m_DriveTrainModeString;

    /** The PDP temperature, in Celsius */
    double m_PDP_temperature_C;

    /** The PDP temerature, in Farenheit */
    double m_PDP_temperature_F;

    /**
     * The operating temperature status
     * True  = Within specified operating temperature range
     * False = Outside of specified operating temperature range
    */
    bool m_PDP_OperatingTemperatureStatus;

    /** The battery voltage, as measured by the PDP, in Volts */
    double m_PDP_BatteryVoltage;

    /** The battery voltage status */
    bool m_PDP_BatteryVoltageStatus;

    /** The battery total current, as measured by the PDP, in Amps */
    double m_PDP_BatteryCurrent;

    /** The battery current status */
    bool m_PDP_BatteryCurrentStatus;

    /** 
     * The total power sourced from the battery,
     * as measured by the PDP, in Watts
    */
    double m_PDP_BatteryPower;

    /** 
     * The total energy supplied from the battery,
     * as measured by the PDP, in Joules
    */
    double m_PDP_BatteryEnergy;

    /** The overall battery status */
    bool m_PDP_BatteryStatus;

    /** The current used in the left drive train motor #0, in Amps */
    double m_PDP_LeftDriveTrainMotor0Current;

    /** The current used in the left drive train motor #1, in Amps */
    double m_PDP_LeftDriveTrainMotor1Current;

    /** The current used in the left drive train, both motors, in Amps */
    double m_PDP_LeftDriveTrainMotorsCurrent;

    /** The current used in the right drive train motor #0, in Amps */
    double m_PDP_RightDriveTrainMotor0Current;

    /** The current used in the right drive train motor #1, in Amps */
    double m_PDP_RightDriveTrainMotor1Current;

    /** The current used in the right drive train, both motors, in Amps */
    double m_PDP_RightDriveTrainMotorsCurrent;

    /** The current used in the drive train, all motors, in Amps */
    double m_PDP_DriveTrainMotorsCurrent;

    /** The current used in the PAT Turner motor, in Amps */
    double m_PDP_PATTurnerMotorCurrent;

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

    /** The current used in the Pssh motor, in Amps */
    double m_PDP_PsshMotorCurrent;

#endif // #if USE_PID_PSSH

    /** The current used in the H/F Arms motor, in Amps */
    double m_PDP_H_F_ArmsMotorCurrent;

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

    /** The angle of Pssh, as read from the potentiometer */
    double m_PsshPotAngle;

#endif // #if USE_PID_PSSH

    /** The acceleration along the roboRIOs X-Axis, in Gs */
    double m_roboRIO_Accel_X_Axis;

    /** The acceleration along the roboRIOs Y-Axis, in Gs */
    double m_roboRIO_Accel_Y_Axis;

    /** The acceleration along the roboRIOs Z-Axis, in Gs */
    double m_roboRIO_Accel_Z_Axis;

    /** The status of the roboRIO; true = OK, false = FAULT */
    bool m_roboRIO_StatusOK;

    /** The roboRIO's input voltage, in Volts */
    double m_roboRIO_InputVoltage;

    /** The roboRIO's input voltage status */
    bool m_roboRIO_InputVoltageStatus;

    /** The roboRIO's input current, in Amps */
    double m_roboRIO_InputCurrent;

    /** The roboRIO's input current status */
    bool m_roboRIO_InputCurrentStatus;

    /** The roboRIO's power consumption, in Watts */
    double m_roboRIO_InputPower;

    /** The roboRIO's overall input power status */
    bool m_roboRIO_InputSPowerStatus;

    /** The roboRIO's 3.3V rail voltage, in Volts */
    double m_roboRIO_3_3V_Rail_Voltage;

    /** The roboRIO's 3.3V rail voltage status */
    bool m_roboRIO_3_3V_Rail_VoltageStatus;

    /** The roboRIO's 3.3V rail current, in Amps */
    double m_roboRIO_3_3V_Rail_Current;

    /** The roboRIO's 3.3V rail current status */
    bool m_roboRIO_3_3V_Rail_CurrentStatus;

    /** Boolean to determine if roboRIO 3.3V rail is enabled */
    bool m_roboRIO_3_3V_Rail_IsEnabled;

    /** The number of roboRIO 3.3V rail current faults since boot */ 
    int m_roboRIO_3_3V_Rail_FaultCount;

    /** roboRIO 3.3V rail current faults status */ 
    bool m_roboRIO_3_3V_Rail_FaultCountStatus;

    /** roboRIO 3.3V rail overall status */ 
    bool m_roboRIO_3_3V_Rail_Status;

    /** The roboRIO's 5V rail voltage, in Volts */
    double m_roboRIO_5V_Rail_Voltage;

    /** The roboRIO's 5V rail voltage status */
    bool m_roboRIO_5V_Rail_VoltageStatus;

    /** The roboRIO's 5V rail current, in Amps */
    double m_roboRIO_5V_Rail_Current;

    /** The roboRIO's 5V rail current status */
    bool m_roboRIO_5V_Rail_CurrentStatus;

    /** Boolean to determine if roboRIO 5V rail is enabled */
    bool m_roboRIO_5V_Rail_IsEnabled;

    /** The number of roboRIO 5V rail current faults since boot */ 
    int m_roboRIO_5V_Rail_FaultCount;

    /** roboRIO 5V rail current fault status */ 
    bool m_roboRIO_5V_Rail_FaultCountStatus;

    /** roboRIO 5V rail overall status */ 
    bool m_roboRIO_5V_Rail_Status;

    /** The roboRIO's 6V rail voltage, in Volts */
    double m_roboRIO_6V_Rail_Voltage;

    /** The roboRIO's 6V rail voltage status */
    bool m_roboRIO_6V_Rail_VoltageStatus;

    /** The roboRIO's 6V rail current, in Amps */
    double m_roboRIO_6V_Rail_Current;

    /** The roboRIO's 6V rail current status */
    bool m_roboRIO_6V_Rail_CurrentStatus;

    /** Boolean to determine if roboRIO 6V rail is enabled */
    bool m_roboRIO_6V_Rail_IsEnabled;

    /** The number of roboRIO 6V rail current faults since boot */ 
    int m_roboRIO_6V_Rail_FaultCount;

    /** roboRIO 6V rail current fault status */ 
    bool m_roboRIO_6V_Rail_FaultCountStatus;

    /** roboRIO 6V rail overall status */ 
    bool m_roboRIO_6V_Rail_Status;

    /** Boolean to determine if the roboRIO is browned out */
    bool m_roboRIO_IsBrownedOut;

    /** Boolean to determine if the roboRIO system is active */
    bool m_roboRIO_IsSysActive;

    /** 
     * The roboRIO's Field Programmable Gate Array (FPGA) revision
     * information.
     * 
     * @code{.cpp}
     * Note: 
     * 
     * Major Revision: 12 Most significant bits (MSBs)
     * Minor Revision:  8 bits following the major revision
     * Build Number:   12 Least significant bits (LSBs)
     * 
     * Example:
     * 
     * M = Major revision, m = minor revision, build number = b,
     * X = Don't care
     * 
     *    6         5         4         3         2         1   
     * 3210987654321098765432109876543210987654321098765432109876543210
     * MMMMMMMMMMMMmmmmmmmmXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXbbbbbbbbbbbb
     * @endcode
    */
    int64_t m_roboRIO_FPGA_Revision;

    /** The major revision # of the FPGA revision */
    int m_roboRIO_FPGA_MajorRevision;

    /** The minor revision # of the FPGA revision */
    int m_roboRIO_FPGA_MinorRevision;

    /** The build number of the FPGA revision */
    int m_roboRIO_FPGA_BuildNumber;

    /** The roboRIO FPGA time elapsed since boot, in microseconds (0.000001s) */
    uint64_t m_roboRIO_FPGA_Time;

    /** The roboRIO FPGA version number */
    int m_roboRIO_FPGA_VersionNumber;

    /** The status of the drive train turbo mode */
    std::string m_DriveTrainTurboState;

    /** The status of the drive train smoothing mode */
    std::string m_DriveTrainSmoothingState;

    /** The status of the AHRS connection */
    bool m_AHRS_ConnectionStatus;

    /** The status of the AHRS calibration */
    bool m_AHRS_CalibrationStatus;

    /** The pitch of the AHRS */
    double m_AHRS_Pitch;

    /** The roll of the AHRS */
    double m_AHRS_Roll;

    /** The yaw of the AHRS */
    double m_AHRS_Yaw;

    /** The compass heading of the AHRS */
    double m_AHRS_CompassHdg;

    /** The linear acceleration on the x axis */
    double m_AHRS_LinearAccelX;

    /** The linear acceleration on the y axis */
    double m_AHRS_LinearAccelY;

    /** The linear acceleration on the z axis */
    double m_AHRS_LinearAccelZ;

    /** The status of the movemement of the AHRS */
    bool m_AHRS_Moving;

    /** The status of the rotation of the AHRS */
    bool m_AHRS_Rotating;

    /** The fused heading of the AHRS */
    double m_AHRS_FusedHdg;

    /** The status of magnetic disturbance on the AHRS */
    bool m_AHRS_MagDisturb;

    /** The status of the AHRS magnetometer calibration */
    bool m_AHRS_MgntmtrCalStatus;

    /** The Quaternion W of the AHRS */
    double m_AHRS_QuatW;

    /** The Quaternion X of the AHRS */
    double m_AHRS_QuatX;

    /** The Quaternion Y of the AHRS */
    double m_AHRS_QuatY;

    /** The Quaternion Z of the AHRS */
    double m_AHRS_QuatZ;

    /** The yaw angle of the AHRS */
    double m_AHRS_YawAngle;

    /** The yaw angle adjustment of the AHRS */
    double m_AHRS_YawAngleAdj;

    /** The rotation rate of the AHRS */
    double m_AHRS_RotRate;

    /** The temperature of the AHRS */
    double m_AHRS_Temp_F;

    /** The firmware version of the AHRS */
    std::string m_AHRS_FWVer;

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

    /** The state of Pssh */
    std::string m_Pssh_State;

#endif // #if USE_PID_PSSH

    /** The drive direction */
    std::string m_drive_dir;

    /** Are the arms enabled */
    bool m_HansFranzArmsEnabled;

    /** Are the muscles enabled */
    bool m_HansFranzMusclesEnabled;

    /** The state of the arms */
    std::string m_HansFranzArmsState;

    /** The state of the muscles */
    std::string m_HansFranzMusclesState;

    /** Boolean to indicate if arms are fully retracted */
    bool m_HansFranzArmsRetracted;

    /** Boolean to indicate if arms are fully extended */
    bool m_HansFranzArmsExtended;

    ///////////// Member variables for choosing telemetry output /////////////

    /** Constant for choosing to output telemetry */
    const bool m_OutputTelemetry = true;
    /** Constant for NOT choosing to output telemetry */
    const bool m_DoNOT_OutputTelemetry = false;

    /** Choose to output drive train mode string or not */
    const bool m_Output_DriveTrainModeString             = m_OutputTelemetry;

    /** Choose to output temperature or not */
    const bool m_Output_PDP_Temperature                  = m_OutputTelemetry;
    /** Choose to output operating temperature status or not */
    const bool m_Output_PDP_OperatingTemperatureStatus   = m_OutputTelemetry;

    /** Choose to output battery voltage or not */
    const bool m_Output_PDP_BatteryVoltage               = m_OutputTelemetry;
    /** Choose to output battery voltage status or not */
    const bool m_Output_PDP_BatteryVoltageStatus         = m_OutputTelemetry;
    /** Choose to output battery current or not */
    const bool m_Output_PDP_BatteryCurrent               = m_OutputTelemetry;
    /** Choose to output battery current status or not */
    const bool m_Output_PDP_BatteryCurrentStatus         = m_OutputTelemetry;
    /** Choose to output battery power or not */
    const bool m_Output_PDP_BatteryPower                 = m_OutputTelemetry;
    /** Choose to output battery energy or not */
    const bool m_Output_PDP_BatteryEnergy                = m_OutputTelemetry;
    /** Choose to output battery status or not */
    const bool m_Output_PDP_BatteryStatus                = m_OutputTelemetry;

    /** Choose to output the current used in the left drive train motor #0 */
    const bool m_Output_PDP_LeftDriveTrainMotor0Current  = m_OutputTelemetry;
    /** Choose to output the current used in the left drive train motor #1 */
    const bool m_Output_PDP_LeftDriveTrainMotor1Current  = m_OutputTelemetry;
    /** Choose to output the current used in the left drive train (both motors) */
    const bool m_Output_PDP_LeftDriveTrainMotorsCurrent  = m_OutputTelemetry;

    /** Choose to output the current used in the right drive train motor #0 */
    const bool m_Output_PDP_RightDriveTrainMotor0Current = m_OutputTelemetry;
    /** Choose to output the current used in the right drive train motor #1 */
    const bool m_Output_PDP_RightDriveTrainMotor1Current = m_OutputTelemetry;
    /** Choose to output the current used in the right drive train (both motors) */
    const bool m_Output_PDP_RightDriveTrainMotorsCurrent = m_OutputTelemetry;

    /** Choose to output the current used in the drive train (all motors) */
    const bool m_Output_PDP_DriveTrainMotorsCurrent      = m_OutputTelemetry;

    /** Choose to output the current used in the PAT Turner motor */
    const bool m_Output_PDP_PATTurnerMotorCurrent        = m_OutputTelemetry;

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

    /** Choose to output the current used in the Pshh motor */
    const bool m_Output_PDP_PsshMotorCurrent             = m_OutputTelemetry;

#endif // #if USE_PID_PSSH

    /** Choose to output the current used in the H/F Arms motor */
    const bool m_Output_PDP_H_F_ArmsMotorCurrent         = m_OutputTelemetry;

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

    /** Choose to output the angle of Pssh */
    const bool m_Output_PsshPotAngle                     = m_OutputTelemetry;

#endif // #if USE_PID_PSSH

    /** Choose to output the roboRIO's accelerometer X-axis */
    const bool m_Output_roboRIO_Accel_X_Axis             = m_OutputTelemetry;
    /** Choose to output the roboRIO's accelerometer Y-axis */
    const bool m_Output_roboRIO_Accel_Y_Axis             = m_OutputTelemetry;
    /** Choose to output the roboRIO's accelerometer Z-axis */
    const bool m_Output_roboRIO_Accel_Z_Axis             = m_OutputTelemetry;

    /** Choose to output the roboRIO's status */
    const bool m_Output_roboRIO_StatusOK                 = m_OutputTelemetry;

    /** Choose to output the roboRIO's input voltage */
    const bool m_Output_roboRIO_InputVoltage             = m_OutputTelemetry;
    /** Choose to output the roboRIO's input voltage status */
    const bool m_Output_roboRIO_InputVoltageStatus       = m_OutputTelemetry;
    /** Choose to output the roboRIO's input current */
    const bool m_Output_roboRIO_InputCurrent             = m_OutputTelemetry;
    /** Choose to output the roboRIO's input current status */
    const bool m_Output_roboRIO_InputCurrentStatus       = m_OutputTelemetry;
    /** Choose to output the roboRIO's power consumption */
    const bool m_Output_roboRIO_InputPower               = m_OutputTelemetry;
    /** Choose to output the roboRIO's overall input power status */
    const bool m_Output_roboRIO_InputSPowerStatus        = m_OutputTelemetry;

    /** Choose to output the roboRIO's 3.3V rail voltage */
    const bool m_Output_roboRIO_3_3V_Rail_Voltage        = m_OutputTelemetry;
    /** Choose to output the roboRIO's 3.3V rail voltage status */
    const bool m_Output_roboRIO_3_3V_Rail_VoltageStatus  = m_OutputTelemetry;
    /** Choose to output the roboRIO's 3.3V rail current */
    const bool m_Output_roboRIO_3_3V_Rail_Current        = m_OutputTelemetry;
    /** Choose to output the roboRIO's 3.3V rail current status */
    const bool m_Output_roboRIO_3_3V_Rail_CurrentStatus  = m_OutputTelemetry;

    /** Choose to output if roboRIO 3.3V rail is enabled */
    const bool m_Output_roboRIO_3_3V_Rail_IsEnabled      = m_OutputTelemetry;
    /** 
     * Choose to output the number of roboRIO 3.3V rail current faults
     *  since boot
    */ 
    const bool m_Output_roboRIO_3_3V_Rail_FaultCount     = m_OutputTelemetry;
    /** Choose to output the roboRIO 3.3V rail current faults status */ 
    const bool m_Output_roboRIO_3_3V_Rail_FaultCountStatus = m_OutputTelemetry;
    /** Choose to Output the roboRIO's 3.3V rail overall status */
    const bool m_Output_roboRIO_3_3V_Rail_Status           = m_OutputTelemetry;

    /** Choose to output the roboRIO's 5V rail voltage */
    const bool m_Output_roboRIO_5V_Rail_Voltage          = m_OutputTelemetry;
    /** Choose to output the roboRIO's 5V rail voltage status */
    const bool m_Output_roboRIO_5V_Rail_VoltageStatus    = m_OutputTelemetry;
    /** Choose to output the roboRIO's 5V rail current */
    const bool m_Output_roboRIO_5V_Rail_Current          = m_OutputTelemetry;
    /** Choose to outpuhe roboRIO's 5V rail current status */
    const bool m_Output_roboRIO_5V_Rail_CurrentStatus    = m_OutputTelemetry;
    /** Choose to output if roboRIO 5V rail is enabled */
    const bool m_Output_roboRIO_5V_Rail_IsEnabled        = m_OutputTelemetry;
    /** 
     * Choose to output the number of roboRIO 5V rail current faults
     * since boot
    */ 
    const bool m_Output_roboRIO_5V_Rail_FaultCount       = m_OutputTelemetry;
    /** Choose to output the roboRIO 5V rail current fault status */ 
    const bool m_Output_roboRIO_5V_Rail_FaultCountStatus = m_OutputTelemetry;
    /** Choose to output the roboRIO 5V rail overall status */ 
    const bool m_Output_roboRIO_5V_Rail_Status           = m_OutputTelemetry;


    /** Choose to output the roboRIO's 6V rail voltage */
    const bool m_Output_roboRIO_6V_Rail_Voltage          = m_OutputTelemetry;
    /** Choose to output the roboRIO's 6V rail voltage status */
    bool m_Output_roboRIO_6V_Rail_VoltageStatus          = m_OutputTelemetry;
    /** Choose to output the roboRIO's 6V rail current */
    const bool m_Output_roboRIO_6V_Rail_Current          = m_OutputTelemetry;
    /** Choose to output the roboRIO's 6V rail current status */
    const bool m_Output_roboRIO_6V_Rail_CurrentStatus    = m_OutputTelemetry;
    /** Choose to output if roboRIO 6V rail is enabled */
    const bool m_Output_roboRIO_6V_Rail_IsEnabled        = m_OutputTelemetry;
    /** 
     * Choose to output the number of roboRIO 6V rail current faults
     * since boot
    */ 
    const bool m_Output_roboRIO_6V_Rail_FaultCount       = m_OutputTelemetry;
    /** Choose to output the roboRIO 6V rail current fault status */ 
    const bool m_Output_roboRIO_6V_Rail_FaultCountStatus = m_OutputTelemetry;

    /** Choose to output the roboRIO 6V rail overall status */ 
    const bool m_Output_roboRIO_6V_Rail_Status           = m_OutputTelemetry;


    /** Choose to output if the roboRIO is browned out */
    const bool m_Output_roboRIO_IsBrownedOut             = m_OutputTelemetry;

    /** Choose to output if the roboRIO system is active */
    const bool m_Output_roboRIO_IsSysActive              = m_OutputTelemetry;

    /** 
     * Choose to output the roboRIO FPGA time elapsed since boot,
     * in microseconds (0.000001s = 1x10^(-6)s)
    */
    const bool m_Output_roboRIO_FPGA_Time                = m_OutputTelemetry;

    /** Choose to output the roboRIO FPGA version number and revision */
    const bool m_Output_roboRIO_FPGA_VerNumRev           = m_OutputTelemetry;

    /** Choose to output the drive train turbo mode */
    const bool m_Output_DriveTrainTurboState             = m_OutputTelemetry;

    /** Choose to output the drive train smoothing mode */
    const bool m_Output_DriveTrainSmoothingState         = m_OutputTelemetry;

    /** Choose to output the status of the AHRS connection */
    const bool m_Output_AHRS_ConnectionStatus            = m_OutputTelemetry;

    /** Choose to output the status of the AHRS calibration */
    const bool m_Output_AHRS_CalibrationStatus           = m_OutputTelemetry;

    /** Choose to output the pitch of the AHRS */
    const bool m_Output_AHRS_Pitch                       = m_OutputTelemetry;

    /** Choose to output the roll of the AHRS */
    const bool m_Output_AHRS_Roll                        = m_OutputTelemetry;

    /** Choose to output the yaw of the AHRS */
    const bool m_Output_AHRS_Yaw                         = m_OutputTelemetry;

    /** Choose to output the compass heading of the AHRS */
    const bool m_Output_AHRS_CompassHdg                  = m_OutputTelemetry;

    /** Choose to output the linear acceleration on the x axis */
    const bool m_Output_AHRS_LinearAccelX                = m_OutputTelemetry;

    /** Choose to output the linear acceleration on the y axis */
    const bool m_Output_AHRS_LinearAccelY                = m_OutputTelemetry;

    /** Choose to output the linear acceleration on the z axis */
    const bool m_Output_AHRS_LinearAccelZ                = m_OutputTelemetry;

    /** Choose to output the status of the movemement of the AHRS */
    const bool m_Output_AHRS_Moving                      = m_OutputTelemetry;

    /** Choose to output the status of the rotation of the AHRS */
    const bool m_Output_AHRS_Rotating                    = m_OutputTelemetry;

    /** Choose to output the fused heading of the AHRS */
    const bool m_Output_AHRS_FusedHdg                    = m_OutputTelemetry;

    /** Choose to output the status of magnetic disturbance on the AHRS */
    const bool m_Output_AHRS_MagDisturb                  = m_OutputTelemetry;

    /** Choose to output the status of the AHRS magnetometer calibration */
    const bool m_Output_AHRS_MgntmtrCalStatus            = m_OutputTelemetry;

    /** Choose to output the Quaternion W of the AHRS */
    const bool m_Output_AHRS_QuatW                       = m_OutputTelemetry;

    /** Choose to output the Quaternion X of the AHRS */
    const bool m_Output_AHRS_QuatX                       = m_OutputTelemetry;

    /** Choose to output the Quaternion Y of the AHRS */
    const bool m_Output_AHRS_QuatY                       = m_OutputTelemetry;

    /** Choose to output the Quaternion Z of the AHRS */
    const bool m_Output_AHRS_QuatZ                       = m_OutputTelemetry;

    /** Choose to output the yaw angle of the AHRS */
    const bool m_Output_AHRS_YawAngle                    = m_OutputTelemetry;

    /** Choose to output the yaw angle adjustment of the AHRS */
    const bool m_Output_AHRS_YawAngleAdj                 = m_OutputTelemetry;

    /** Choose to output the rotation rate of the AHRS */
    const bool m_Output_AHRS_RotRate                     = m_OutputTelemetry;

    /** Choose to output the temperature of the AHRS */
    const bool m_Output_AHRS_Temp_F                      = m_OutputTelemetry;

    /** Choose to output the firmware version of the AHRS */
    const bool m_Output_AHRS_FWVer                       = m_OutputTelemetry;

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

    /** Choose to output the state of Pssh */
    const bool m_Output_Pssh_State                       = m_OutputTelemetry;

#endif // #if USE_PID_PSSH

    /** Choose to output the drive direction */
    const bool m_Output_drive_dir                        = m_OutputTelemetry;

    /** Choose to output if the arms are enabled */
    const bool m_Output_HansFranzArmsEnabled             = m_OutputTelemetry;

    /** Choose to output if the muscles enabled */
    const bool m_Output_HansFranzMusclesEnabled          = m_OutputTelemetry;

    /** Choose to output the state of the arms */
    const bool m_Output_HansFranzArmsState               = m_OutputTelemetry;

    /** Choose to output the state of the muscles */
    const bool m_Output_HansFranzMusclesState            = m_OutputTelemetry;

    /** Choose to output the boolean to indicate if arms are fully retracted */
    bool m_Output_HansFranzArmsRetracted                 = m_OutputTelemetry;

    /** Choose to output the boolean to indicate if arms are fully extended */
    bool m_Output_HansFranzArmsExtended                  = m_OutputTelemetry;

    ////////////////////////// Some other constants //////////////////////////

    /** The minimum operating temperature, in C (0C = 32F)*/
    const double mk_PDP_OperatingTemperatureMin = 0.0;
    /** The maximum operating temperature, in C (40C = 104F) */
    const double mk_PDP_OperatingTemperatureMax = 40.0;
    /** The battery voltage minimum acceptable voltage, in Volts
        Note: This is no-load voltage */
    const double mk_PDP_BatteryVoltageMin = 12.25;
    /** The battery voltage maximum acceptable voltage, in Volts
        Note: This is no-load voltage */
    const double mk_PDP_BatteryVoltageMax = 14.40;
    /** The battery current minimum acceptable current, in Amps */
    const double mk_PDP_BatteryCurrentMin = 0.00;
    /** The battery current maximum acceptable current, in Amps */
    const double mk_PDP_BatteryCurrentMax = 120.00;
    /** The maximum battery current for testing acceptable battery
        state of charge (SoC), in Amps */
    const double mk_PDP_BatteryVoltageMaxForSoCTest = 0.250;
    /** The roboRIO input voltage minimum acceptable voltage, in Volts */
    const double mk_roboRIOVoltageInMin = 7.00;
    /** The roboRIO input voltage maximum acceptable voltage, in Volts */
    const double mk_roboRIOVoltageInMax = 16.00;
    /** The roboRIO input current minimum acceptable current, in Amps */
    const double mk_roboRIOCurrentInMin = 0.25;
    /** The roboRIO input current maximum acceptable current, in Amps */
    const double mk_roboRIOCurrentInMax = 6.5;
    /** The roboRIO 3.3V output minimum acceptable voltage, in Volts */
    const double mk_roboRIO3V3VoltageMin = 3.1;
    /** The roboRIO 3.3V output maximum acceptable voltage, in Volts */
    const double mk_roboRIO3V3VoltageMax = 3.465;
    /** The roboRIO 3.3V output minimum acceptable current, in Amps */
    const double mk_roboRIO3V3CurrentMin = 0.0;
    /** The roboRIO 3.3V output maximum acceptable current, in Amps */
    const double mk_roboRIO3V3CurrentMax = 1.225;
    /** The roboRIO 5V output minimum acceptable voltage, in Volts */
    const double mk_roboRIO5VVoltageMin = 4.7;
    /** The roboRIO 5V output maximum acceptable voltage, in Volts */
    const double mk_roboRIO5VVoltageMax = 5.25;
    /** The roboRIO 5V output minimum acceptable current, in Amps */
    const double mk_roboRIO5VCurrentMin = 0.0;
    /** The roboRIO 5V output maximum acceptable current, in Amps */
    const double mk_roboRIO5VCurrentMax = 1.0;
    /** The roboRIO 6V output minimum acceptable voltage, in Volts */
    const double mk_roboRIO6VVoltageMin = 5.5;
    /** The roboRIO 6V output maximum acceptable voltage, in Volts */
    const double mk_roboRIO6VVoltageMax = 6.1;
    /** The roboRIO 6V output minimum acceptable current, in Amps */
    const double mk_roboRIO6VCurrentMin = 0.0;
    /** The roboRIO 6V output maximum acceptable current, in Amps */
    const double mk_roboRIO6VCurrentMax = 2.2;

    /** The percentage of current where we will flag */
    const double mk_PercentageMaxCurrent = 0.9;

    /** 
     * The number of bits to shift to the right to get the FPGA 
     * major revision from the FPGA revision 
    */
    const uint mk_FPGA_RevisionMajorRevisionShift = 52;

    /** 
     * The mask needed to get only the FPGA minor revision bits from 
     * the FPGA revision
    */
    const uint64_t mk_FPGA_RevisionMinorRevisionMask = 0x000FF00000000000;
    /** 
     * The number of bits to shift to the right to get the FPGA
     * minor revision from the FPGA revision
    */
    const uint mk_FPGA_RevisionMinorRevisionShift = 44;

    /** 
     * The mask needed to get only the FPGA build number bits from
     * the FPGA revision
    */
    const uint64_t mk_FPGA_RevisionBuildNumberMask = 0x0000000000000FFF;

    //////////////////////////// Member functions ////////////////////////////

    /**
     * Method to convert celcius to farenheit.
     *
     * @param  celcius The temperature in Celsius
     * @return         The temperature in Farenheit
    */
    double CelsiusToFarenheit(double celcius);

    /** Method to get telemetry */
    void GetTelemetry();

    /** Method to output telemetry */
    void OutputTelemetry();

    /**
     * Method to get the FPGA major revision # from the FPGA Revision.
     *
     * @param FPGA_Revision A 64-bit integer containing FPGA revision
     *                      information, got by using
     *                      RobotController::GetFPGAVersion()
     * 
     * @return              An integer containing the major revision #.
    */
    int GetMajorRevisionFromFPGARevision(int64_t FPGA_Revision);

    /**
     * Method to get the FPGA minor revision # from the FPGA Revision.
     *
     * @param FPGA_Revision A 64-bit integer containing FPGA revision
     *                      information, got by using
     *                      RobotController::GetFPGAVersion()
     *
     * @return              An integer containing the minor revision #.
    */
    int GetMinorRevisionFromFPGARevision(int64_t FPGA_Revision);

    /**
     * Method to get the FPGA build number from the FPGA Revision.
     *
     * @param FPGA_Revision A 64-bit integer containing FPGA revision
     *                      information, got by using 
     *                      RobotController::GetFPGAVersion()
     *
     * @return              An integer containing the build #.
     *
    */
    int GetBuildNumberFromFPGARevision(int64_t FPGA_Revision);

    /**
     * Method to see if measured value is between the minimum and maximum
     * acceptable range
     *
     * @param MeasuredValue The value that we have measured
     * @param MinValue      The minimum acceptable value
     * @param MaxValue      The maximum acceptable value
     *
     * @return true = Within accepaptable range, false = outside range
    */
    bool GetIfWithinRange(double MeasuredValue, double MinValue, double MaxValue);

}; // end class TelemetryOutputter

# endif // #ifndef TELEMETRYOUTPUTTER_H
