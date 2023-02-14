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
 * Copyright (c) 2019-2022 FRC Team #7464 - ORION. All Rights Reserved.
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

// Include the header for our robot tick
#include "RobotTick.h"

// Include the SmartDashboard Keys header file
#include "Telemetry/SmartDashboardKeys.h"

// The header for the NavX MXP AHRS class
#include "AHRS.h"

// Include the drive train subsystem header
#include "subsystems/SubSysDriveTrain.h"

// Include the ball shooter subsystem header
#include "subsystems/SubSysBallShooter.h"

/************************** Library Header Files ******************************/

// Include the header file to declare strings
#include <string>

// Include the SmartDashboard class header file, which allows us to transmit
//   robot data to the operator console
// See:
// https://wpilib.screenstepslive.com/s/currentCS/m/smartdashboard
#include <frc/smartdashboard/SmartDashboard.h>

// Include the header file for the Power Distribution Panel
#include <frc/PowerDistribution.h>

// Include the header file for the roboRIO internal accelerometers
#include <frc/BuiltInAccelerometer.h>

// Include the header file for the roboRIO controller telemetry
#include <frc/RobotController.h>

// Include the header file for the FMS/Driver station telemetry
#include <frc/DriverStation.h>

/** ****************************************************************************
 * @class   TelemetryOutputter
 * @brief   This is a class that provides a means to output general
 *            robot telemetry back to the driver station via the
 *            SmartDashboard.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class TelemetryOutputter {

  public:

    /** 
     * The TelemetryOutputter class constructor.
     * 
     * @param robot_tick    A pointer to a robot tick
     * @param ahrs          A pointer to a NavX MXP AHRS
     * @param drivetrain    A pointer to a drivetrain subsystem
     * @param ballshooter   A pointer to a ball shooter subsystem
    */
    TelemetryOutputter(
      RobotTick *robot_tick,
      AHRS* ahrs,
      SubSysDriveTrain* drivetrain,
      SubSysBallShooter* ballshooter
    );

    /** The TelemetryOutputter class destructor. */
    ~TelemetryOutputter();

    /** Method to output the telemetry to the Smart Dashboard */
    void OutputTelemetryToSmartDashboard();

  private:

    /********************* Private member variables ***********************/

    /** A pointer to a robot tick class */
    RobotTick* m_RobotTick;

    /** A pointer to an AHRS NavX MXP */
    AHRS* m_AHRS;

    /** A pointer to a drive train subsystem */
    SubSysDriveTrain* m_subSysDriveTrain;

    /** A pointer to a ball shooter subsystem */
    SubSysBallShooter* m_subSysBallShooter;

    /////////// Member variables for various telemetry deliverers ///////////

    /** Declare a pointer to a power distribution panel (PDP) instance */
    frc::PowerDistribution* m_pdp;

    /** Declare a pointer to roboRIO's internal accelerometers instance */
    frc::BuiltInAccelerometer* m_roboRIO_accelerometers;

    ///////////////// Member variable for storing telemetry /////////////////

    // Field Management System (FMS) and Driver Station (DS) Information

    /** String to hold the alliance color and station # */
    std::string m_AllianceColorStationNumber;

    /** String to hold the match type and number */
    std::string m_MatchTypeNumber;

    /** String to hold the match mode type */
    std::string m_MatchMode;

    /** String to hold time remaining in the current period */
    std::string m_PeriodTimeRemaining;

    /** String to hold the FMS status */
    std::string m_FMSStatus;

    /** String to hold the driver station status */
    std::string m_DSStatus;

    /** String to hold the robot status */
    std::string m_RobotStatus;

    // Power distribution panel (PDP) overall information 
    //   (individual current for channels not shown here)

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

    // Controller Area Network (CAN) Information

    /** Float to hold CAN bus utilization percentage */
    float m_CANUtilization;

    /** Float to hold minimum CAN bus utilization percentage */
    float m_MinCANUtilization = 100.0;

    /** Float to hold maximum CAN bus utilization percentage */
    float m_MaxCANUtilization = 0.0;

    /** Integer to hold count of CAN bus off events */
    int m_CANBusOffCount;

    /** Integer to hold count of CAN bus TX full events */
    int m_CANTXFullCount;

    /** Integer to hold count of CAN bus RX error events */
    int m_CANRXErrorCount;

    /** Integer to hold count of CAN bus TX error events */
    int m_CANTXErrorCount;

    // RoboRIO Information

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

    /** Boolean to determine if the roboRIO is not browned out */
    bool m_roboRIO_IsNotBrownedOut;

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

    /** The roboRIO's FPGA version, revision, and build information */
    std::string m_roboRIO_FPGA_Ver_Rev_Bld;

    /** The roboRIO FPGA time elapsed since boot, in microseconds (0.000001s) */
    uint64_t m_roboRIO_FPGA_Time;

    /** The roboRIO FPGA version number */
    int m_roboRIO_FPGA_VersionNumber;

    // Software Version Information

    /** String to hold the ORION robot code software version */
    std::string m_ORION_RobotCode_SW_Version;

    /** String to hold the WPILibC code software version */
    std::string m_WPILibC_Code_SW_Version;

    /** String to hold the NavX MXP code software version */
    std::string m_NavX_MXP_Code_SW_Version;

    /** String to hold the REV Robotics library software version */
    std::string m_REVLib_SW_Version;

    // Attitude and Heading Reference System (AHRS) Information

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
    bool m_AHRS_NoMagDisturb;

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

    // Drive Train Information

    /** A string to hold the drive train mode */
    std::string m_DriveTrainModeString;

    /** The status of the drive train turbo mode */
    std::string m_DriveTrainTurboState;

    /** The status of the drive train smoothing mode */
    std::string m_DriveTrainSmoothingState;

    /** The drive direction */
    std::string m_drive_dir;

    /** The current used in the left drive train motor #0, in Amps */
    double m_LeftDriveTrainMotor0Current;

    /** The current used in the left drive train motor #1, in Amps */
    double m_LeftDriveTrainMotor1Current;

    /** The current used in the left drive train, both motors, in Amps */
    double m_LeftDriveTrainMotorsCurrent;

    /** The current used in the right drive train motor #0, in Amps */
    double m_RightDriveTrainMotor0Current;

    /** The current used in the right drive train motor #1, in Amps */
    double m_RightDriveTrainMotor1Current;

    /** The current used in the right drive train, both motors, in Amps */
    double m_RightDriveTrainMotorsCurrent;

    /** The current used in the drive train, all motors, in Amps */
    double m_DriveTrainMotorsCurrent;

    // Ball Shooter Information

    /** The intake motor current, in A */
    double m_IntakeMotorCurrent;

    /** The left indexer motor current, in A */
    double m_LeftIndexterMotorCurrent;

    /** The right indexer motor current, in A */
    double m_RightIndexerMotorCurrent;

    /** The ball shooter motor current */
    double m_ShooterMotorCurrent;

    /** The distance read by the ultrasonic, in meters */
    double m_Ultrasonic_Distance_m;

    /** The velocity setpoint of the NEO (ball shooter) motor, in rpm */
    double m_NEO_MotorVelocitySetpoint_rpm;

    /** The actual velocity of the NEO (ball shooter) motor, in rpm */
    double m_NEO_MotorVelocity_rpm;

    ///////////// Member variables for choosing telemetry output /////////////

    /** Constant for choosing to output telemetry */
    const bool mk_Output = true;
    /** Constant for NOT choosing to output telemetry */
    const bool mk_DoNOT_Output = false;

    ////////////////////////// Some other constants //////////////////////////

    /** 
     * A structure for storing a parameter's acceptable range of values
     * by storing its minimum and maximum acceptable values.
     * 
     * NOTE: The values are inclusive, meaning that the values given
     *       are acceptable. 
    */
    struct accept_range_type
    {
      /** The minimum acceptable value */
      double min_acc_value;
      /** The maximum acceptable value */
      double max_acc_value;

    }; // end struct acceptable_range_type

    /** The acceptable operating temperature range, in C */
    const accept_range_type mk_PDP_OperatingTemperatureRange = {0.0, 40.0};
    /** The acceptable range for the battery voltage, in Volts */
    const accept_range_type mk_PDP_BatteryVoltageRange = {12.25, 14.40};
    /** The acceptable range for the battery current, in Amps */
    const accept_range_type mk_PDP_BatteryCurrentRange = {0.00, 120.00};
    /** The maximum battery current for testing acceptable battery
        state of charge (SoC), in Amps */
    const double mk_PDP_BatteryVoltageMaxForSoCTest = 0.250;
    /** The acceptable range for roboRIO accelorometers (X,Y,Z), in Gs */
    const accept_range_type mk_roboRIOAccelRange = {-8.0, 8.0};
    /** The acceptable range for roboRIO input voltage, in Volts */
    const accept_range_type mk_roboRIOVoltageInRange = {7.00, 16.00};
    /** The acceptable range for roboRIO input current, in Amps */
    const accept_range_type mk_roboRIOCurrentInRange = {0.25, 6.50};
    /** The acceptable range for roboRIO input power, in Watts */
    const accept_range_type mk_roboRIOPowerInRange = {1.75, 104.0};
    /** The acceptable range for the 3.3V rail voltage, in Volts */
    const accept_range_type mk_roboRIO3V3VoltageRange = {3.1, 3.465};
    /** The acceptable range for the 3.3V rail current, in Amps */
    const accept_range_type mk_roboRIO3V3CurrentRange = {0.0, 1.225};
    /** The acceptable range for the 5V rail voltage, in Volts */
    const accept_range_type mk_roboRIO5VVoltageRange = {4.7, 5.25};
    /** The acceptable range for the 5V rail current, in Amps */
    const accept_range_type mk_roboRIO5VCurrentRange = {0.0, 1.0};
    /** The acceptable range for the 6V rail voltage, in Volts */
    const accept_range_type mk_roboRIO6VVoltageRange = {5.5, 6.1};
    /** The acceptable range for the 6V rail current, in Amps */
    const accept_range_type mk_roboRIO6VCurrentRange = {0.0, 2.2};

    /** The percentage of current where we will flag */
    const double mk_PercentageMaxCurrent = 0.9;

    /** 
     * The number of bits to shift to the right to get the FPGA 
     * major revision from the FPGA revision 
    */
    const uint64_t mk_FPGA_RevisionMajorRevisionShift = 52;

    /** 
     * The mask needed to get only the FPGA minor revision bits from 
     * the FPGA revision
    */
    const uint64_t mk_FPGA_RevisionMinorRevisionMask = 0x000FF00000000000;
    /** 
     * The number of bits to shift to the right to get the FPGA
     * minor revision from the FPGA revision
    */
    const uint64_t mk_FPGA_RevisionMinorRevisionShift = 44;

    /** 
     * The mask needed to get only the FPGA build number bits from
     * the FPGA revision
    */
    const uint64_t mk_FPGA_RevisionBuildNumberMask = 0x0000000000000FFF;

    /** The string for the red alliance */
    const std::string mk_RedAlliance = "RED";
    /** The string for the blue alliance */
    const std::string mk_BlueAlliance = "BLUE";
    /** The string for an invalid alliance */
    const std::string mk_InvalidAlliance = "INVALID";
    /** The string for an unknown alliance */
    const std::string mk_UnknownAlliance = "UNKNOWN";
    /** The string for station #0 (invalid) */
    const std::string mk_StationNumber0 = "INVALID";
    /** The string for station #1 (left) */
    const std::string mk_StationNumber1 = "1(L)";
    /** The string for station #2 (center) */
    const std::string mk_StationNumber2 = "2(C)";
    /** The string for station #3 (right) */
    const std::string mk_StationNumber3 = "3(R)";
    /** The string for an unknown station # */
    const std::string mk_StationNumberUnknown = "UNKNOWN";
    /** The string for combining Alliance color and station # */
    const std::string mk_AllianceStationNumberGlue = ": ";

    /** The string for no match type */
    const std::string mk_MatchTypeNone = "NONE";
    /** The string for a practice match type */
    const std::string mk_MatchTypePractice = "PRACTICE";
    /** The string for a qualification match type */
    const std::string mk_MatchTypeQualification = "QUALIFICATION";
    /** The string for an elimination match type */
    const std::string mk_MatchTypeElimination = "ELIMINATION";
    /** The string for an unknown match type */
    const std::string mk_MatchTypeUnknown = "UNKNOWN";
    /** The string for combining match type and match # */
    const std::string mk_MatchTypeNumberGlue = " #";

    /** The string indicating match mode is autonomous */
    const std::string mk_MatchModeAutonomous = "AUTO";
    /** The string indicating match mode is teleoperated */
    const std::string mk_MatchModeTeleoperated = "TELEOP";
    /** The string indicating match mode is test */
    const std::string mk_MatchModeTest = "TEST";
    /** The string indicating match mode is unknown */
    const std::string mk_MatchModeUnknown = "UNKNOWN";

    /** The string indicating that the FMS is attached */
    const std::string mk_FMSAttached = "YES";
    /** The string indicating that the FMS is not attached */
    const std::string mk_FMSNotAttached = "NO";

    /** The string indicating that the driver station is attached */
    const std::string mk_DSAttached = "YES";
    /** The string indicating that the driver station is not attached */
    const std::string mk_DSNotAttached = "NO";

    /** The string showing the robot status is enabled */
    const std::string mk_RobotStatusEnabled = "ENABLED";
    /** The string showing the robot status is disabled */
    const std::string mk_RobotStatusDisabled = "DISABLED";
    /** The string showing the robot status is emergency stopped */
    const std::string mk_RobotStatusEStopped = "E-STOPPED!";
    /** The string showing the robot status is unknown */
    const std::string mk_RobotStatusUnknown = "UNKNOWN";

    /** An enumeration of output telemetry data types */
    enum telemetry_output_data_type
    {

      /** For data type bool */
      BOOLEAN,
      /** For data type double */
      DOUBLE,
      /** For data type float */
      FLOAT,
      /** For data type int */
      INTEGER,
      /** For telemetry items with no data type */
      NOTYPE,
      /** For data type std::string */
      STRING,
      /** For data type uint64_t */
      UINT64T

    }; // end enum telemetry_output_data_type

    /** An enumeration of output telemetry IDs */
    enum telemetry_output_ID
    {

      /** This shall always be the first telemetry ID */
      FIRST_TELEMETRY_ID,

      // Field Management System (FMS) and Driver Station (DS) IDs

      /** The FMS alliance color and station number */
      FMS_ALLNC_STN,
      /** The FMS match type and match # */
      FMS_MATCH_TYPE_NUM,
      /** The FMS match mode */
      FMS_MATCH_MODE,
      /** The FMS period time remaining */
      FMS_PRD_TIME_REM,
      /** The status of the FMS */
      FMS_STATUS,
      /** The driver station status */
      DS_STATUS,
      /** The state of the robot from the driver station */
      DS_ROBOT_STATUS,

      // Power distribution panel (PDP) overall information IDs 
      //   (individual current for channels not shown here)

      /** The temperature reported by the PDP */
      PDP_TEMPERATURE,
      /** The PDP temperature status */
      PDP_TEMPERATURE_STATUS,
      /** The battery voltage, as reported by the PDP */
      PDP_BATTERY_VOLTAGE,
      /** The battery voltage status */
      PDP_BATTERY_VOLTAGE_STATUS,
      /** The battery current, as reported by the PDP */
      PDP_BATTERY_CURRENT,
      /** The battery current status */
      PDP_BATTERY_CURRENT_STATUS,
      /** The battery power being delivered, as reported by the PDP */
      PDP_BATTERY_POWER,
      /** The battery energy delivered since reset, as reported by the PDP */
      PDP_BATTERY_ENERGY,
      /** The overall battery status */
      PDP_BATTERY_STATUS,

      // Controller Area Network (CAN) Information IDs

      /** The CAN bus utilization */
      CAN_UTILIZATION,
      /** The maximum CAN bus utilization */
      CAN_MAX_UTILIZATION,
      /** The minimum CAN bus utilization */
      CAN_MIN_UTILIZATION,
      /** The CAN bus off event count */
      CAN_BUS_OFF_COUNT,
      /** The CAN bus TX full event count */
      CAN_TX_FULL_COUNT,
      /** The CAN RX error count */
      CAN_RX_ERR_COUNT,
      /** The CAN TX error count */
      CAN_TX_ERR_COUNT,

      // RoboRIO Information IDs

      /** roboRIO X acceleration axis */
      ROBORIO_ACCEL_X_AXIS,
      /** roboRIO Y acceleration axis */
      ROBORIO_ACCEL_Y_AXIS,
      /** roboRIO Z acceleration axis */
      ROBORIO_ACCEL_Z_AXIS,
      /** roboRIO input voltage */
      ROBORIO_INPUT_VOLTAGE,
      /** roboRIO input current */
      ROBORIO_INPUT_CURRENT,
      /** roboRIO input power consumption */
      ROBORIO_INPUT_POWER,
      /** roboRIO's 3.3V rail voltage */
      ROBORIO_3_3V_RAIL_VOLTAGE,
      /** roboRIO's 3.3V rail current */
      ROBORIO_3_3V_RAIL_CURRENT,
      /** roboRIO's 3.3V rail enabled or not */
      ROBORIO_3_3V_RAIL_ENABLED,
      /** roboRIO's 3.3V rail fault count */
      ROBORIO_3_3V_RAIL_FLT_CNT,
      /** roboRIO's 5V rail voltage */
      ROBORIO_5V_RAIL_VOLTAGE,
      /** roboRIO's 5V rail current */
      ROBORIO_5V_RAIL_CURRENT,
      /** roboRIO's 5V rail enabled or not */
      ROBORIO_5V_RAIL_ENABLED,
      /** roboRIO's 5V rail fault count */
      ROBORIO_5V_RAIL_FLT_CNT,
      /** roboRIO's 6V rail voltage */
      ROBORIO_6V_RAIL_VOLTAGE,
      /** roboRIO's 6V rail current */
      ROBORIO_6V_RAIL_CURRENT,
      /** roboRIO's 6V rail enabled or not */
      ROBORIO_6V_RAIL_ENABLED,
      /** roboRIO's 6V rail fault count */
      ROBORIO_6V_RAIL_FLT_CNT,
      /** roboRIO browned out status */
      ROBORIO_ISNT_BROWNED_OUT,
      /** roboRIO system active status */
      ROBORIO_IS_SYS_ACTIVE,
      /** 
       * roboRIO field programmable gate array (FPGA) 
       * version, revision, and build
      */
      ROBORIO_FPGA_VER_REV_BLD,
      /** roboRIO FPGA time */
      ROBORIO_FPGA_TIME,

      // Software Version Information IDs

      /** The software version of the ORION Robot Code */
      ORION_ROBOTCODE_SW_VER,
      /** The software version of the WPILibC code used */
      WPILIBC_CODE_SW_VER,
      /** The software version of the NavX MXP code used */
      NAVX_MXP_CODE_SW_VER,
      /** The software version of the REV Robotics library used */
      REVLIB_CODE_SW_VER,

      // Attitude and Heading Reference System (AHRS) Information IDs

      /** The AHRS connection status */
      AHRS_CONNECTION_STATUS,
      /** The AHRS calibration status */
      AHRS_CALIBRATION_STATUS,
      /** The AHRS pitch */
      AHRS_PITCH,
      /** The AHRS roll */
      AHRS_ROLL,
      /** The AHRS yaw */
      AHRS_YAW,
      /** The AHRS compass heading */
      AHRS_COMPASS_HDG,
      /** The AHRS linear acceleration on the X axis */
      AHRS_LIN_ACCL_X,
      /** The AHRS linear acceleration on the Y axis */
      AHRS_LIN_ACCL_Y,
      /** The AHRS linear acceleration on the Z axis */
      AHRS_LIN_ACCL_Z,
      /** The AHRS movement status */
      AHRS_MOVING_STATUS,
      /** The AHRS rotation status */
      AHRS_ROTATING_STATUS,
      /** The AHRS fused heading */
      AHRS_FUSED_HDG,
      /** The AHRS No Magnetic Disturbance status */
      AHRS_NO_MAG_DISTURB,
      /** The AHRS magnetometer calibration status */
      AHRS_MGNTMTR_CAL_STATUS,
      /** The AHRS Quaternion W */
      AHRS_QUAT_W,
      /** The AHRS Quaternion X */
      AHRS_QUAT_X,
      /** The AHRS Quaternion Y */
      AHRS_QUAT_Y,
      /** The AHRS Quaternion Z */
      AHRS_QUAT_Z,
      /** The AHRS yaw angle */
      AHRS_YAW_ANGLE,
      /** The AHRS yaw angle adjustment */
      AHRS_YAW_ANGLE_ADJ,
      /** The AHRS rotation rate */
      AHRS_ROTATION_RATE,
      /** The AHRS temperature in Farenheit */
      AHRS_TEMP_F,
      /** The AHRS firmware version */
      AHRS_FW_VER,

      // Drive Train Information IDs

      /** The drive train mode */
      DRV_TRN_MODE,
      /** The drive train turbo state */
      DRV_TRN_TURBO_STATE,
      /** The drive train smooting state */
      DRV_TRN_SMOOTH_STATE,
      /** The drive train driving direction */
      DRV_TRN_DRV_DIR,
      /** The drive train left motor #0 current */
      DRV_TRN_L_MTR_0_CURRENT,
      /** The drive train left motor #1 current */
      DRV_TRN_L_MTR_1_CURRENT,
      /** The drive train left motors current */
      DRV_TRN_L_MTRS_CURRENT,
      /** The drive train right motor #0 current */
      DRV_TRN_R_MTR_0_CURRENT,
      /** The drive train right motor #1 current */
      DRV_TRN_R_MTR_1_CURRENT,
      /** The drive train right motors current */
      DRV_TRN_R_MTRS_CURRENT,
      /** The drive train motors current */
      DRV_TRN_MOTORS_CURRENT,

      // Ball shooter

      /** The intake motor current*/
      BS_INTK_MTR_CURRENT,
      /** The left indexer motor current*/
      BS_LEFT_INDXR_MTR_CURRNT,
      /** The right indexer motor current */
      BS_RIGHT_INDXR_MTR_CURRNT,
      /** The ball shooter motor current */
      BS_SHTR_MTR_CURRNT,
      /** The distance read by the ultrasonic */
      BS_ULTRASNC_DIST,
      /** The velocity setpoint of the NEO (ball shooter) motor */
      BS_SHTR_MTR_VEL_SP,
      /** The actual velocity of the NEO (ball shooter) motor */
      BS_SHTR_MTR_ACT_VEL,

      /** This shall always be the last telemetry ID */
      LAST_TELEMETRY_ID 

    }; // end enum telemetry_output_ID

    /** A structure used to hold data for each telemetry item output */
    struct telemetry_output_type
    {

      /** The ID of the telemetry item */
      telemetry_output_ID ID;
      /** The SmartDashboard key for the telemetry item */
      const std::string SD_Key;
      /** Boolean to indicate if we are outputting this item or not */
      bool output;
      /** Integer indicating the number of ticks elapsed between outputs */
      uint64_t tick_interval;
      /** Integer indicating the of ticks offset from the interval */ 
      uint64_t tick_offset;
      /** Function pointer to the get function to be ran for this ID */
      void (TelemetryOutputter::*get_function)();
      /** The data type of the telemetry to be output */
      telemetry_output_data_type data_type;
      /** A void pointer to the value pertaining to this ID */
      void* value;

    }; // end struct telemetry_output_type

    // NOTE: If you change the SD keys below, you will need to redevelop your
    //       dashboard (default, SmartDashboard, or Shuffleboard). On some
    //       dashboards, you can change the displayed title, or add a
    //       label.

    /** A table representing the telemetry items */
    const telemetry_output_type mk_telemetry[LAST_TELEMETRY_ID+1] =
    {

//    |            ID             |     SD Key             | OUTPUT OR NOT  |INTV|OFST|                Getter function                     | DTYPE  |       Variable to output        |
      {FIRST_TELEMETRY_ID,         "",                      mk_DoNOT_Output,   1,   0, NULL,                                                NOTYPE,  NULL                             },

      // Field Management System (FMS) and Driver Station (DS) Information
//    |            ID             |     SD Key             | OUTPUT OR NOT  |INTV|OFST|                Getter function                     | DTYPE  |       Variable to output        |
      {FMS_ALLNC_STN,              "Alliance & Station #",  mk_Output,         1,   0, &TelemetryOutputter::GetAllianceColorStationNumber,  STRING,  &m_AllianceColorStationNumber    },
      {FMS_MATCH_TYPE_NUM,         "Match Type & #",        mk_Output,         1,   0, &TelemetryOutputter::GetMatchTypeMatchNumber,        STRING,  &m_MatchTypeNumber               },
      {FMS_MATCH_MODE,             "Match Mode",            mk_Output,         1,   0, &TelemetryOutputter::GetMatchMode,                   STRING,  &m_MatchMode                     },
      {FMS_PRD_TIME_REM,           "Period Time Remaining", mk_Output,         1,   0, &TelemetryOutputter::GetMatchTime,                   STRING,  &m_PeriodTimeRemaining           },
      {FMS_STATUS,                 "FMS Cnctd?",            mk_Output,         1,   0, &TelemetryOutputter::GetFMSStatus,                   STRING,  &m_FMSStatus                     },
      {DS_STATUS,                  "DS Cnctd?",             mk_Output,         1,   0, &TelemetryOutputter::GetDSStatus,                    STRING,  &m_DSStatus                      },
      {DS_ROBOT_STATUS,            "Robot Status",          mk_Output,         1,   0, &TelemetryOutputter::GetRobotStatus,                 STRING,  &m_RobotStatus                   },

      // Power distribution panel (PDP) overall information (individual current for channels not shown here)
//    |            ID             |     SD Key             | OUTPUT OR NOT  |INTV|OFST|                Getter function                     | DTYPE  |       Variable to output        |
      {PDP_TEMPERATURE,            "Temp (F)",              mk_Output,         1,   0, &TelemetryOutputter::Get_PDP_Temperature,            DOUBLE,  &m_PDP_temperature_F             },
      {PDP_TEMPERATURE_STATUS,     "Temp OK",               mk_Output,         1,   0, &TelemetryOutputter::Get_PDP_Temperature_Status,     BOOLEAN, &m_PDP_OperatingTemperatureStatus},
      {PDP_BATTERY_VOLTAGE,        "Batt V(V)",             mk_Output,         1,   0, &TelemetryOutputter::Get_PDP_Battery_Voltage,        DOUBLE,  &m_PDP_BatteryVoltage            },
      {PDP_BATTERY_VOLTAGE_STATUS, "Batt Volt OK",          mk_Output,         1,   0, &TelemetryOutputter::Get_PDP_Battery_Voltage_Status, BOOLEAN, &m_PDP_BatteryVoltageStatus      },
      {PDP_BATTERY_CURRENT,        "Batt C(A)",             mk_Output,         1,   0, &TelemetryOutputter::Get_PDP_Battery_Current,        DOUBLE,  &m_PDP_BatteryCurrent            },
      {PDP_BATTERY_CURRENT_STATUS, "Batt Curr OK",          mk_Output,         1,   0, &TelemetryOutputter::Get_PDP_Battery_Current_Status, BOOLEAN, &m_PDP_BatteryCurrentStatus      },
      {PDP_BATTERY_POWER,          "Batt P(W)",             mk_Output,         1,   0, &TelemetryOutputter::Get_PDP_Battery_Power,          DOUBLE,  &m_PDP_BatteryPower              },
      {PDP_BATTERY_ENERGY,         "Batt E(J)",             mk_Output,         1,   0, &TelemetryOutputter::Get_PDP_Battery_Energy,         DOUBLE,  &m_PDP_BatteryEnergy             },
      {PDP_BATTERY_STATUS,         "Batt OK",               mk_Output,         1,   0, &TelemetryOutputter::Get_PDP_Battery_Status,         BOOLEAN, &m_PDP_BatteryStatus             },

      // Controller Area Network (CAN) Information
//    |            ID             |     SD Key             | OUTPUT OR NOT  |INTV|OFST|                Getter function                     | DTYPE  |       Variable to output        |
      {CAN_UTILIZATION,            "CAN UTIL. (%)",         mk_Output,         1,   0, &TelemetryOutputter::GetCANUtilization,              FLOAT,   &m_CANUtilization                },
      {CAN_MAX_UTILIZATION,        "MAX. CAN UTIL. (%)",    mk_Output,         1,   0, &TelemetryOutputter::GetMaxCANUtilization,           FLOAT,   &m_MaxCANUtilization             },
      {CAN_MIN_UTILIZATION,        "MIN. CAN UTIL. (%)",    mk_Output,         1,   0, &TelemetryOutputter::GetMinCANUtilization,           FLOAT,   &m_MinCANUtilization             },
      {CAN_BUS_OFF_COUNT,          "CAN BUS OFF CNT",       mk_Output,         1,   0, &TelemetryOutputter::GetCANBusOffCount,              INTEGER, &m_CANBusOffCount                },
      {CAN_TX_FULL_COUNT,          "CAN TX FULL CNT",       mk_Output,         1,   0, &TelemetryOutputter::GetCANTXFullCount,              INTEGER, &m_CANTXFullCount                },
      {CAN_RX_ERR_COUNT,           "CAN RX ERROR CNT",      mk_Output,         1,   0, &TelemetryOutputter::GetCANRXErrorCount,             INTEGER, &m_CANRXErrorCount               },
      {CAN_TX_ERR_COUNT,           "CAN TX ERROR CNT",      mk_Output,         1,   0, &TelemetryOutputter::GetCANTXErrorCount,             INTEGER, &m_CANTXErrorCount               },

      // RoboRIO Information
//    |            ID             |     SD Key             | OUTPUT OR NOT  |INTV|OFST|                Getter function                     | DTYPE  |       Variable to output        |
      {ROBORIO_ACCEL_X_AXIS,       "X-Axis A(G)",           mk_Output,         1,   0, &TelemetryOutputter::GetRoboRIO_Accel_X_Axis,        DOUBLE,  &m_roboRIO_Accel_X_Axis          },
      {ROBORIO_ACCEL_Y_AXIS,       "Y-Axis A(G)",           mk_Output,         1,   0, &TelemetryOutputter::GetRoboRIO_Accel_Y_Axis,        DOUBLE,  &m_roboRIO_Accel_Y_Axis          },
      {ROBORIO_ACCEL_Z_AXIS,       "Z-Axis A(G)",           mk_Output,         1,   0, &TelemetryOutputter::GetRoboRIO_Accel_Z_Axis,        DOUBLE,  &m_roboRIO_Accel_Z_Axis          },
      {ROBORIO_INPUT_VOLTAGE,      "CTL V_IN(V)",           mk_Output,         1,   0, &TelemetryOutputter::GetRoboRIO_Input_Voltage,       DOUBLE,  &m_roboRIO_InputVoltage          },
      {ROBORIO_INPUT_CURRENT,      "CTL I_IN(A)",           mk_Output,         1,   0, &TelemetryOutputter::GetRoboRIO_Input_Current,       DOUBLE,  &m_roboRIO_InputCurrent          },
      {ROBORIO_INPUT_POWER,        "CTL P_IN(W)",           mk_Output,         1,   0, &TelemetryOutputter::GetRoboRIO_Input_Power,         DOUBLE,  &m_roboRIO_InputPower            },
      {ROBORIO_3_3V_RAIL_VOLTAGE,  "CTL 3.3V V(V)",         mk_Output,         1,   0, &TelemetryOutputter::GetRoboRIO_3_3V_Rail_Voltage,   DOUBLE,  &m_roboRIO_3_3V_Rail_Voltage     },
      {ROBORIO_3_3V_RAIL_CURRENT,  "CTL 3.3V I(A)",         mk_Output,         1,   0, &TelemetryOutputter::GetRoboRIO_3_3V_Rail_Current,   DOUBLE,  &m_roboRIO_3_3V_Rail_Current     },
      {ROBORIO_3_3V_RAIL_ENABLED,  "CTL 3.3V ENBLD",        mk_Output,         1,   0, &TelemetryOutputter::GetRoboRIO_3_3V_Rail_Enabled,   BOOLEAN, &m_roboRIO_3_3V_Rail_IsEnabled   },
      {ROBORIO_3_3V_RAIL_FLT_CNT,  "CTL 3.3V FAULTS",       mk_Output,         1,   0, &TelemetryOutputter::GetRoboRIO_3_3V_Rail_Flt_Cnt,   INTEGER, &m_roboRIO_3_3V_Rail_FaultCount  },
      {ROBORIO_5V_RAIL_VOLTAGE,    "CTL 5V V(V)",           mk_Output,         1,   0, &TelemetryOutputter::GetRoboRIO_5V_Rail_Voltage,     DOUBLE,  &m_roboRIO_5V_Rail_Voltage       },
      {ROBORIO_5V_RAIL_CURRENT,    "CTL 5V I(A)",           mk_Output,         1,   0, &TelemetryOutputter::GetRoboRIO_5V_Rail_Current,     DOUBLE,  &m_roboRIO_5V_Rail_Current       },
      {ROBORIO_5V_RAIL_ENABLED,    "CTL 5V ENBLD",          mk_Output,         1,   0, &TelemetryOutputter::GetRoboRIO_5V_Rail_Enabled,     BOOLEAN, &m_roboRIO_5V_Rail_IsEnabled     },
      {ROBORIO_5V_RAIL_FLT_CNT,    "CTL 5V FAULTS",         mk_Output,         1,   0, &TelemetryOutputter::GetRoboRIO_5V_Rail_Flt_Cnt,     INTEGER, &m_roboRIO_5V_Rail_FaultCount    },
      {ROBORIO_6V_RAIL_VOLTAGE,    "CTL 6V V(V)",           mk_Output,         1,   0, &TelemetryOutputter::GetRoboRIO_6V_Rail_Voltage,     DOUBLE,  &m_roboRIO_6V_Rail_Voltage       },
      {ROBORIO_6V_RAIL_CURRENT,    "CTL 6V I(A)",           mk_Output,         1,   0, &TelemetryOutputter::GetRoboRIO_6V_Rail_Current,     DOUBLE,  &m_roboRIO_6V_Rail_Current       },
      {ROBORIO_6V_RAIL_ENABLED,    "CTL 6V ENBLD",          mk_Output,         1,   0, &TelemetryOutputter::GetRoboRIO_6V_Rail_Enabled,     BOOLEAN, &m_roboRIO_6V_Rail_IsEnabled     },
      {ROBORIO_6V_RAIL_FLT_CNT,    "CTL 6V FAULTS",         mk_Output,         1,   0, &TelemetryOutputter::GetRoboRIO_6V_Rail_Flt_Cnt,     INTEGER, &m_roboRIO_6V_Rail_FaultCount    },
      {ROBORIO_ISNT_BROWNED_OUT,   "POWER OK",              mk_Output,         1,   0, &TelemetryOutputter::GetRoboRIO_Isnt_BrownedOut,     BOOLEAN, &m_roboRIO_IsNotBrownedOut       },
      {ROBORIO_IS_SYS_ACTIVE,      "SYS ACTV",              mk_Output,         1,   0, &TelemetryOutputter::GetRoboRIO_Is_SysActive,        BOOLEAN, &m_roboRIO_IsSysActive           },
      {ROBORIO_FPGA_VER_REV_BLD,   "FPGA Ver.",             mk_Output,         1,   0, &TelemetryOutputter::GetRoboRIO_FPGA_Ver_Rev_Bld,    STRING,  &m_roboRIO_FPGA_Ver_Rev_Bld      },
      {ROBORIO_FPGA_TIME,          "FPGA Time(uS)",         mk_Output,         1,   0, &TelemetryOutputter::GetRoboRIO_FPGA_Time,           UINT64T, &m_roboRIO_FPGA_Time             },

      // Software Version Information
//    |            ID             |     SD Key             | OUTPUT OR NOT  |INTV|OFST|                Getter function                     | DTYPE  |       Variable to output        |
      {ORION_ROBOTCODE_SW_VER,     "ORION SW Version:",     mk_Output,         1,   0, &TelemetryOutputter::GetORION_RobotCode_SW_Ver,      STRING,  &m_ORION_RobotCode_SW_Version    },
      {WPILIBC_CODE_SW_VER,        "WPILibC SW Version:",   mk_Output,         1,   0, &TelemetryOutputter::GetWPILibC_Code_SW_Ver,         STRING,  &m_WPILibC_Code_SW_Version       },
      {NAVX_MXP_CODE_SW_VER,       "NavX-MXP SW Version",   mk_Output,         1,   0, &TelemetryOutputter::GetNavXMXP_Code_SW_Ver,         STRING,  &m_NavX_MXP_Code_SW_Version      },
      {REVLIB_CODE_SW_VER,         "REV Library Version",   mk_Output,         1,   0, &TelemetryOutputter::GetREVLib_Code_SW_Ver,          STRING,  &m_REVLib_SW_Version             },

      // Attitude and Heading Reference System (AHRS) Information 
//    |            ID             |     SD Key             | OUTPUT OR NOT  |INTV|OFST|                Getter function                     | DTYPE  |       Variable to output        |
      {AHRS_CONNECTION_STATUS,     "AHRS Cnct'd",           mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_Connection_Status,      BOOLEAN, &m_AHRS_ConnectionStatus         },
      {AHRS_CALIBRATION_STATUS,    "AHRS Cal'd",            mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_Calibration_Status,     BOOLEAN, &m_AHRS_CalibrationStatus        },
      {AHRS_PITCH,                 "Pitch",                 mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_Pitch,                  DOUBLE,  &m_AHRS_Pitch                    },
      {AHRS_ROLL,                  "Roll",                  mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_Roll,                   DOUBLE,  &m_AHRS_Roll                     },
      {AHRS_YAW,                   "Yaw",                   mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_Yaw,                    DOUBLE,  &m_AHRS_Yaw                      },
      {AHRS_COMPASS_HDG,           "Compass Hdg",           mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_Compass_Hdg,            DOUBLE,  &m_AHRS_CompassHdg               },
      {AHRS_LIN_ACCL_X,            "Linear X Accel",        mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_Lin_Accl_X,             DOUBLE,  &m_AHRS_LinearAccelX             },
      {AHRS_LIN_ACCL_Y,            "Linear Y Accel",        mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_Lin_Accl_Y,             DOUBLE,  &m_AHRS_LinearAccelY             },
      {AHRS_LIN_ACCL_Z,            "Linear Z Accel",        mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_Lin_Accl_Z,             DOUBLE,  &m_AHRS_LinearAccelZ             },
      {AHRS_MOVING_STATUS,         "Moving",                mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_Moving_Status,          BOOLEAN, &m_AHRS_Moving                   },
      {AHRS_ROTATING_STATUS,       "Rotating",              mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_Rotating_Status,        BOOLEAN, &m_AHRS_Rotating                 },
      {AHRS_FUSED_HDG,             "Fused Hdg",             mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_Fused_Heading,          DOUBLE,  &m_AHRS_FusedHdg                 },
      {AHRS_NO_MAG_DISTURB,        "No Mag Disturb",        mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_No_Mag_Disturb,         BOOLEAN, &m_AHRS_NoMagDisturb             },
      {AHRS_MGNTMTR_CAL_STATUS,    "Mgntmtr Cal'd",         mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_Mgntmtr_Cal_Status,     BOOLEAN, &m_AHRS_MgntmtrCalStatus         },
      {AHRS_QUAT_W,                "Quat W",                mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_QuatW,                  DOUBLE,  &m_AHRS_QuatW                    },
      {AHRS_QUAT_X,                "Quat X",                mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_QuatX,                  DOUBLE,  &m_AHRS_QuatX                    },
      {AHRS_QUAT_Y,                "Quat Y",                mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_QuatY,                  DOUBLE,  &m_AHRS_QuatY                    },
      {AHRS_QUAT_Z,                "Quat Z",                mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_QuatZ,                  DOUBLE,  &m_AHRS_QuatZ                    },
      {AHRS_YAW_ANGLE,             "Yaw Angle",             mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_Yaw_Angle,              DOUBLE,  &m_AHRS_YawAngle                 },
      {AHRS_YAW_ANGLE_ADJ,         "Yaw Angle Adj",         mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_Yaw_Angle_Adj,          DOUBLE,  &m_AHRS_YawAngleAdj              },
      {AHRS_ROTATION_RATE,         "Rot. Rate",             mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_Rotation_Rate,          DOUBLE,  &m_AHRS_RotRate                  },
      {AHRS_TEMP_F,                "AHRS Temp.",            mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_Temperature_F,          DOUBLE,  &m_AHRS_Temp_F                   },
      {AHRS_FW_VER,                "AHRS FW Ver.",          mk_Output,         1,   0, &TelemetryOutputter::GetAHRS_FW_Ver,                 STRING,  &m_AHRS_FWVer                    },

      // Drive Train Information
//    |            ID             |     SD Key             | OUTPUT OR NOT  |INTV|OFST|                Getter function                     | DTYPE  |       Variable to output        |
      {DRV_TRN_MODE,               "DT Mode",               mk_Output,         1,   0, &TelemetryOutputter::GetDrvTrnMode,                  STRING,  &m_DriveTrainModeString          },
      {DRV_TRN_TURBO_STATE,        "Turbo Status",          mk_Output,         1,   0, &TelemetryOutputter::GetDrvTrnTurboState,            STRING,  &m_DriveTrainTurboState          },
      {DRV_TRN_SMOOTH_STATE,       "Smooth Status",         mk_Output,         1,   0, &TelemetryOutputter::GetDrvTrnSmoothState,           STRING,  &m_DriveTrainSmoothingState      },
      {DRV_TRN_DRV_DIR,            "Drive Front",           mk_Output,         1,   0, &TelemetryOutputter::GetDrvTrnDrvDir,                STRING,  &m_drive_dir                     },
      {DRV_TRN_L_MTR_0_CURRENT,    "LDTM0 C(A)",            mk_Output,         1,   0, &TelemetryOutputter::GetDrvTrnLftMtr0Current,        DOUBLE,  &m_LeftDriveTrainMotor0Current   },
      {DRV_TRN_L_MTR_1_CURRENT,    "LDTM1 C(A)",            mk_Output,         1,   0, &TelemetryOutputter::GetDrvTrnLftMtr1Current,        DOUBLE,  &m_LeftDriveTrainMotor1Current   },
      {DRV_TRN_L_MTRS_CURRENT,     "LDT C(A)",              mk_Output,         1,   0, &TelemetryOutputter::GetDrvTrnLftMtrsCurrent,        DOUBLE,  &m_LeftDriveTrainMotorsCurrent   },
      {DRV_TRN_R_MTR_0_CURRENT,    "RDTM0 C(A)",            mk_Output,         1,   0, &TelemetryOutputter::GetDrvTrnRghtMtr0Current,       DOUBLE,  &m_RightDriveTrainMotor0Current  },
      {DRV_TRN_R_MTR_1_CURRENT,    "RDTM1 C(A)",            mk_Output,         1,   0, &TelemetryOutputter::GetDrvTrnRghtMtr1Current,       DOUBLE,  &m_RightDriveTrainMotor1Current  },
      {DRV_TRN_R_MTRS_CURRENT,     "RDT C(A)",              mk_Output,         1,   0, &TelemetryOutputter::GetDrvTrnRghtMtrsCurrent,       DOUBLE,  &m_RightDriveTrainMotorsCurrent  },
      {DRV_TRN_MOTORS_CURRENT,     "DT C(A)",               mk_Output,         1,   0, &TelemetryOutputter::GetDrvTrnMtrsCurrent,           DOUBLE,  &m_DriveTrainMotorsCurrent       },

      // Ball Shooter Information
//    |            ID             |     SD Key             | OUTPUT OR NOT  |INTV|OFST|                Getter function                     | DTYPE  |       Variable to output        |
      {BS_INTK_MTR_CURRENT,         "INTAKE C(A)",          mk_Output,         1,   0, &TelemetryOutputter::GetBS_Intk_Mtr_Curr,            DOUBLE,  &m_IntakeMotorCurrent            },
      {BS_LEFT_INDXR_MTR_CURRNT,    "L_IDX C(A)",           mk_Output,         1,   0, &TelemetryOutputter::GetBS_LftIndxMtrCurr,           DOUBLE,  &m_LeftIndexterMotorCurrent      },
      {BS_RIGHT_INDXR_MTR_CURRNT,   "R IDX C(A)",           mk_Output,         1,   0, &TelemetryOutputter::GetBS_RghtIndxMtrCurr,          DOUBLE,  &m_RightIndexerMotorCurrent      },
      {BS_SHTR_MTR_CURRNT,          "SHTR C(A)",            mk_Output,         1,   0, &TelemetryOutputter::GetBS_ShtrMtrCurr,              DOUBLE,  &m_ShooterMotorCurrent           },
      {BS_ULTRASNC_DIST,            "US DIST (m)",          mk_Output,         1,   0, &TelemetryOutputter::GetBS_UltSon_Dist,              DOUBLE,  &m_Ultrasonic_Distance_m         },
      {BS_SHTR_MTR_VEL_SP,          "VEL SP (rpm)",         mk_Output,         1,   0, &TelemetryOutputter::GetBS_NEOMtrVelSP,              DOUBLE,  &m_NEO_MotorVelocitySetpoint_rpm },
      {BS_SHTR_MTR_ACT_VEL,         "VEL (rpm)",            mk_Output,         1,   0, &TelemetryOutputter::GetBS_NEOMtrVel,                DOUBLE,  &m_NEO_MotorVelocity_rpm         },

      // Last Telemetry
//    |            ID             |     SD Key             | OUTPUT OR NOT  |INTV|OFST|                Getter function                     | DTYPE  |       Variable to output        |
      {LAST_TELEMETRY_ID,          "",                      mk_DoNOT_Output,   1,   0, NULL,                                                NOTYPE,  NULL                             }
    
    }; // end const telemetry_output_type mk_telemetry[LAST_TELEMETRY_ID+1]=

    //////////////////////////// Member functions ///////////////////////////
    /**
     * Method to convert celcius to farenheit.
     *
     * @param  celcius The temperature in Celsius
     * @return         The temperature in Farenheit
    */
    double CelsiusToFarenheit(double celcius);

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
     * @param AcceptRange   The acceptable range
     *
     * @return true = Within acceptable range, false = outside range
    */
    bool GetIfWithinRange(double MeasuredValue, 
                          accept_range_type AcceptRange);

    /**
     * Method to see if measured value is between the minimum and maximum
     * acceptable range, with a maximum percent
     *
     * @param MeasuredValue The value that we have measured
     * @param AcceptRange   The acceptable range
     *
     * @return true = Within acceptable range, false = outside range
    */
    bool GetIfWithinRangeWithMaxPercent(double MeasuredValue, 
                                        accept_range_type AcceptRange);

    /**
     * Method to convert a double representing seconds to standard match 
     * time format. Standard match time format is:
     * 
     * m:ss.t
     * 
     * where 
     * m  = minutes (0-9)
     * ss = seconds (00-59)
     * t  = tenths of seconds (0-9)
     * 
     * @param  seconds_dbl  The seconds in double to convert
     * 
     * @return String containing the standard match time format.
     */ 
    std::string ConvertDblSecondsToMinutesSecondsTenths(double seconds_dbl);

    /** A method of outputting telemetry */
    void OutputTelemetry();

    ////////////////////// TELEMETRY GETTER FUNCTIONS //////////////////////////

    // Field Management System (FMS) and Driver Station (DS)

    /** Method to get the alliance color and station #. */
    void GetAllianceColorStationNumber();
    /** Method to get the match type and match #. */
    void GetMatchTypeMatchNumber();
    /** Method to get the match mode. */
    void GetMatchMode();
    /** Method to get the match time */
    void GetMatchTime();
    /** Method to get the FMS connection status */
    void GetFMSStatus();
    /** Method to get the DS status */
    void GetDSStatus();
    /** Method to get the robot state. */
    void GetRobotStatus();

    // Power distribution panel (PDP) overall information IDs 
    //   (individual current for channels not shown here)

    /** Method to get the temperature as reported by the PDP */
    void Get_PDP_Temperature();
    /** Method to get the temperature status */
    void Get_PDP_Temperature_Status();
    /** Method to get the main battery voltage as reported by the PDP */
    void Get_PDP_Battery_Voltage();
    /** Method to get the battery voltage status */
    void Get_PDP_Battery_Voltage_Status();
    /** Method to get the main battery current as reported by the PDP */
    void Get_PDP_Battery_Current();
    /** Method to get the battery current status */
    void Get_PDP_Battery_Current_Status();
    /** Method to get the current power output of the battery, 
     *  as reported by the PDP */
    void Get_PDP_Battery_Power();
    /** Method to get the energy output of the battery since last reset, 
     *  as reported by the PDP */
    void Get_PDP_Battery_Energy();
    /** Method to get the battery status */
    void Get_PDP_Battery_Status();

    // Controller Area Network (CAN) Information

    /** Method to get the current CAN bus utilization */
    void GetCANUtilization();
    /** Method to get the maximum CAN bus utilization */
    void GetMaxCANUtilization();
    /** Method to get the minimum CAN bus utilization */
    void GetMinCANUtilization();
    /** Method to get the count of CAN bus off events */
    void GetCANBusOffCount();
    /** Method to get the count of CAN TX full events */
    void GetCANTXFullCount();
    /** Method to get the count of CAN RX error events */
    void GetCANRXErrorCount();
    /** Method to get the count of CAN TX error events */
    void GetCANTXErrorCount();

    // RoboRIO Information

    /** Get the roboRIO X axis accelerometer value */
    void GetRoboRIO_Accel_X_Axis();
    /** Get the roboRIO Y axis accelerometer value */
    void GetRoboRIO_Accel_Y_Axis();
    /** Get the roboRIO Z axis accelerometer value */
    void GetRoboRIO_Accel_Z_Axis();
    /** Get the roboRIO input voltage*/
    void GetRoboRIO_Input_Voltage();
    /** Get the roboRIO input current */
    void GetRoboRIO_Input_Current();
    /** Get the roboRIO input power */
    void GetRoboRIO_Input_Power();
    /** Get the roboRIO 3.3V rail voltage */
    void GetRoboRIO_3_3V_Rail_Voltage();
    /** Get the roboRIO 3.3V rail current */
    void GetRoboRIO_3_3V_Rail_Current();
    /** Get the roboRIO 3.3V rail enabled status */
    void GetRoboRIO_3_3V_Rail_Enabled();
    /** Get the roboRIO 3.3V rail fault count */
    void GetRoboRIO_3_3V_Rail_Flt_Cnt();
    /** Get the roboRIO 5V rail voltage */
    void GetRoboRIO_5V_Rail_Voltage();
    /** Get the roboRIO 5V rail current */
    void GetRoboRIO_5V_Rail_Current();
    /** Get the roboRIO 5V rail enabled status */
    void GetRoboRIO_5V_Rail_Enabled();
    /** Get the roboRIO 5V rail fault count */
    void GetRoboRIO_5V_Rail_Flt_Cnt();
    /** Get the roboRIO 6V rail voltage */
    void GetRoboRIO_6V_Rail_Voltage();
    /** Get the roboRIO 6V rail current */
    void GetRoboRIO_6V_Rail_Current();
    /** Get the roboRIO 6V rail enabled status */
    void GetRoboRIO_6V_Rail_Enabled();
    /** Get the roboRIO 6V rail fault count */
    void GetRoboRIO_6V_Rail_Flt_Cnt();
    /** Get the roboRIO Isn't browned out status */
    void GetRoboRIO_Isnt_BrownedOut();
    /** Get the roboRIO is system active status */
    void GetRoboRIO_Is_SysActive();
    /** Get the roboRIO FPGA's version, revision, and build */
    void GetRoboRIO_FPGA_Ver_Rev_Bld();
    /** Get the roboRIO FPGA time */
    void GetRoboRIO_FPGA_Time();

    // Software Version Information

    /** Get the software version of the ORiON RobotCode */
    void GetORION_RobotCode_SW_Ver();
    /** Get the software version of the WPILibC code used */
    void GetWPILibC_Code_SW_Ver();
    /** Get the software version of the NavX MXP code used */
    void GetNavXMXP_Code_SW_Ver();
    /** Get the software version of the REV Robotics library used */
    void GetREVLib_Code_SW_Ver();

    // Attitude and Heading Reference System (AHRS) Information

    /** Get the AHRS connection status */
    void GetAHRS_Connection_Status();
    /** Get the AHRS calibration status */
    void GetAHRS_Calibration_Status();
    /** Get the AHRS pitch */
    void GetAHRS_Pitch();
    /** Get the AHRS roll */
    void GetAHRS_Roll();
    /** Get the AHRS yaw */
    void GetAHRS_Yaw();
    /** Get the AHRS compass heading */
    void GetAHRS_Compass_Hdg();
    /** Get the AHRS linear acceleration on the X axis */
    void GetAHRS_Lin_Accl_X();
    /** Get the AHRS linear acceleration on the Y axis */
    void GetAHRS_Lin_Accl_Y();
    /** Get the AHRS linear acceleration on the Z axis */
    void GetAHRS_Lin_Accl_Z();
    /** Get the AHRS movement status */
    void GetAHRS_Moving_Status();
    /** Get the AHRS rotation status */
    void GetAHRS_Rotating_Status();
    /** Get the AHRS fused heading */
    void GetAHRS_Fused_Heading();
    /** Get the AHRS No Magnetic Disturbance status */
    void GetAHRS_No_Mag_Disturb();
    /** Get the AHRS magnetometer calibration status */
    void GetAHRS_Mgntmtr_Cal_Status();
    /** Get the AHRS Quaternion W */
    void GetAHRS_QuatW();
    /** Get the AHRS Quaternion X */
    void GetAHRS_QuatX();
    /** Get the AHRS Quaternion Y */
    void GetAHRS_QuatY();
    /** Get the AHRS Quaternion Z */
    void GetAHRS_QuatZ();
    /** Get the AHRS yaw angle */
    void GetAHRS_Yaw_Angle();
    /** Get the AHRS yaw angle adjustment */
    void GetAHRS_Yaw_Angle_Adj();
    /** Get the AHRS rotation rate */
    void GetAHRS_Rotation_Rate();
    /** Get the AHRS temperature in Farenheit */
    void GetAHRS_Temperature_F();
    /** Get the AHRS firmware version */
    void GetAHRS_FW_Ver();

    // Drive Train Information

    /** Get the drive train mode */
    void GetDrvTrnMode();
    /** Get the drive train turbo state */
    void GetDrvTrnTurboState();
    /** Get the drive train smooting state */
    void GetDrvTrnSmoothState();
    /** Get the drive train driving direction */
    void GetDrvTrnDrvDir();
    /** Get the drive train left motor #0 current */
    void GetDrvTrnLftMtr0Current();
    /** Get the drive train left motor #1 current */
    void GetDrvTrnLftMtr1Current();
    /** Get the drive train left motors current */
    void GetDrvTrnLftMtrsCurrent();
    /** Get the drive train right motor #0 current */
    void GetDrvTrnRghtMtr0Current();
    /** Get the drive train right motor #1 current */
    void GetDrvTrnRghtMtr1Current();
    /** Get the drive train right motors current */
    void GetDrvTrnRghtMtrsCurrent();
    /** Get the drive train motors current */
    void GetDrvTrnMtrsCurrent();

    // Ball Shooter Information

    /** Get the ball shooter intake motor current */
    void GetBS_Intk_Mtr_Curr();

    /** Get the ball shooter left index motor current */
    void GetBS_LftIndxMtrCurr();

    /** Get the ball shooter right index motor current */
    void GetBS_RghtIndxMtrCurr();

    /** Get the ball shooter shooter motor (NEO) current */
    void GetBS_ShtrMtrCurr();

    /** Get the ball shooter ultrasonic motor distance */
    void GetBS_UltSon_Dist();

    /** Get the ball shooter shooter motor (NEO) velocity setpoint */
    void GetBS_NEOMtrVelSP();

    /** Get the ball shooter shooter motor (NEO) velocity */
    void GetBS_NEOMtrVel();

}; // end class TelemetryOutputter

# endif // #ifndef TELEMETRYOUTPUTTER_H
