/** ===========================================================================
 * @file   GetTelemetry.cpp
 * @brief  This file defines the TelemetryOutputter class, with respect to
 *         getting telemetry.
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

// Method to get telemetry
void TelemetryOutputter::GetTelemetry() {

  //////////////// Get the telemetry, if needed ////////////////

  // If we want to output the drive train mode string...
  if(m_Output_DriveTrainModeString) {

    m_DriveTrainModeString =
      Robot::m_subSysDriveTrain->GetDriveTrainModeString();

  } // end if if(m_Output_DriveTrainModeString)

  // If we want to output the temperature,
  //  or the operating temperature status...
  if(m_Output_PDP_Temperature ||
     m_Output_PDP_OperatingTemperatureStatus) {

    // Get the PDP's temperature (in Celsius) via the CAN bus
    m_PDP_temperature_C = m_pdp->GetTemperature();
    // and convert it to Farenheit
    m_PDP_temperature_F = CelsiusToFarenheit(m_PDP_temperature_C);

  } // end if(m_Output_PDP_Temperature)

  // If we want to output the operating temperature status...
  if(m_Output_PDP_OperatingTemperatureStatus) {

    // Get the operating temperature status
    m_PDP_OperatingTemperatureStatus =
      GetIfWithinRange(m_PDP_temperature_C,
                      mk_PDP_OperatingTemperatureMin,
                      mk_PDP_OperatingTemperatureMax);

  } // end if(m_Output_OperatingTemperatureStatus)

  // If we want to output the battery voltage, or
  //   the battery voltage status, or
  //   the battery status
  if(m_Output_PDP_BatteryVoltage ||
     m_Output_PDP_BatteryVoltageStatus ||
     m_Output_PDP_BatteryStatus) {

    // Get the battery voltage, in Volts
    m_PDP_BatteryVoltage = m_pdp->GetVoltage();

  } // end if(m_Output_PDP_BatteryVoltage)

  // If we want to output the battery voltage status, or
  //   the battery status
  if(m_Output_PDP_BatteryVoltageStatus ||
     m_Output_PDP_BatteryStatus) {

    // See if the battery voltage is within the acceptable range
    m_PDP_BatteryVoltageStatus =
      GetIfWithinRange(m_PDP_BatteryVoltage,
                       mk_PDP_BatteryVoltageMin,
                       mk_PDP_BatteryVoltageMax);

  } // end if(m_Output_PDP_BatteryVoltageStatus)

  // If we want to output the battery current, or
  //   the battery current status, or
  //   the battery status
  if(m_Output_PDP_BatteryCurrent ||
     m_Output_PDP_BatteryCurrentStatus ||
     m_Output_PDP_BatteryStatus) {

    // Get the battery's total current consumption, in Amps
    m_PDP_BatteryCurrent = m_pdp->GetTotalCurrent();

  } // end if(m_Output_PDP_BatteryCurrent)

  // If we want to output the battery current status, or
  //   the battery status
  if(m_Output_PDP_BatteryCurrentStatus ||
     m_Output_PDP_BatteryStatus) {

    // See if the battery current is within the acceptable range
    m_PDP_BatteryCurrentStatus =
      GetIfWithinRange(m_PDP_BatteryCurrent,
                       mk_PDP_BatteryCurrentMin,
                       mk_PDP_BatteryCurrentMax * 
                       mk_PercentageMaxCurrent);

  } // end if(m_Output_PDP_BatteryCurrentStatus)

  // If we want to output the battery power...
  if(m_Output_PDP_BatteryPower) {

    // Get the battery's total power consumed, in Watts
    m_PDP_BatteryPower = m_pdp->GetTotalPower();

  } // end if(m_Output_PDP_BatteryPower)

  // If we want to output the battery energy...
  if(m_Output_PDP_BatteryEnergy) {

    // Get the battery's total energy used, in Joules
    m_PDP_BatteryEnergy = m_pdp->GetTotalEnergy();

  } // end if(m_Output_PDP_BatteryEnergy)

  // If we want to output the battery status
  if(m_Output_PDP_BatteryStatus) {

    // The battery status is the logical anding of the
    //   battery voltage status and battery current status,
    //   i.e. both voltage status and current status have
    //        to be good(true) for battery status to be good(true)
    m_PDP_BatteryStatus = m_PDP_BatteryVoltageStatus &&
                          m_PDP_BatteryCurrentStatus;

  } // end if(m_Output_PDP_BatteryStatus)

  // If we want to output the left drive train motor 0 current,
  //   the left drive train motors current (both motors), or
  //   the drive train motors current (all motors)...
  if(m_Output_PDP_LeftDriveTrainMotor0Current ||
     m_Output_PDP_LeftDriveTrainMotorsCurrent ||
     m_Output_PDP_DriveTrainMotorsCurrent) {

    // Get the left drive train's #0 motor current, in Amps
    m_PDP_LeftDriveTrainMotor0Current =
      m_pdp->GetCurrent(k_LeftDriveTrainMotor0PDPChannel);

  } // end if(m_Output_PDP_LeftDriveTrainMotor0Current || ...)

  // If we want to output the left drive train motor 1 current,
  //   the left drive train motors current (both motors), or
  //   the drive train motors current (all motors)...
  if(m_Output_PDP_LeftDriveTrainMotor1Current ||
     m_Output_PDP_LeftDriveTrainMotorsCurrent ||
     m_Output_PDP_DriveTrainMotorsCurrent) {

    // Get the left drive train's #1 motor current, in Amps
    m_PDP_LeftDriveTrainMotor1Current =
      m_pdp->GetCurrent(k_LeftDriveTrainMotor1PDPChannel);

  } // end if if(m_Output_PDP_LeftDriveTrainMotor1Current ||

  // If we want to output the right drive train motor 0 current,
  //   the right drive train motors current (both motors), or
  //   the drive train motors current (all motors)...
  if(m_Output_PDP_RightDriveTrainMotor0Current ||
     m_Output_PDP_RightDriveTrainMotorsCurrent ||
     m_Output_PDP_DriveTrainMotorsCurrent) {

    // Get the right drive train's #0 motor current, in Amps
    m_PDP_RightDriveTrainMotor0Current =
      m_pdp->GetCurrent(k_RightDriveTrainMotor0PDPChannel);

  } // end if(m_Output_PDP_RightDriveTrainMotor0Current || ...

  // If we want to output the right drive train motor 1 current,
  //   the right drive train motors current (both motors), or
  //   the drive train motors current (all motors)...
  if(m_Output_PDP_RightDriveTrainMotor1Current ||
     m_Output_PDP_RightDriveTrainMotorsCurrent ||
     m_Output_PDP_DriveTrainMotorsCurrent) {

    // Get the right drive train's #1 motor current, in Amps
    m_PDP_RightDriveTrainMotor1Current =
      m_pdp->GetCurrent(k_RightDriveTrainMotor1PDPChannel);

  } // end if(m_Output_PDP_RightDriveTrainMotor1Current || ...

  // If we want to output Capt. Hook motor current...
  if(m_Output_PDP_CaptHookMotorCurrent) {

    // Get Capt. Hook motor current, in Amps
    m_PDP_CaptHookMotorCurrent =
      m_pdp->GetCurrent(k_CaptHookMotorPDPChannel);

  } // end if(m_Output_PDP_CaptHookMotorCurrent)...

  // If we want to output the roboRIO's X-axis acceleration...
  if(m_Output_roboRIO_Accel_X_Axis) {

    // Get the roboRIO's X-axis acceleration, in Gs
    m_roboRIO_Accel_X_Axis = m_roboRIO_accelerometers->GetX();

  } // end if(m_Output_roboRIO_Accel_X_Axis)

  // If we want to output the roboRIO's Y-axis acceleration...
  if(m_Output_roboRIO_Accel_Y_Axis) {

    // Get the roboRIO's Y-axis acceleration, in Gs
    m_roboRIO_Accel_Y_Axis = m_roboRIO_accelerometers->GetY();

  } // end if(m_Output_roboRIO_Accel_Y_Axis)

  // If we want to output the roboRIO's Z-axis acceleration...
  if(m_Output_roboRIO_Accel_Z_Axis) {

    // Get the roboRIO's Z-axis acceleration, in Gs
    m_roboRIO_Accel_Z_Axis = m_roboRIO_accelerometers->GetZ();

  } // end if(m_Output_roboRIO_Accel_Z_Axis)

  // If we want to output the roboRIO's input voltage, input power,
  //   input voltage status, or input power status
  if(m_Output_roboRIO_InputVoltage ||
     m_Output_roboRIO_InputPower ||
     m_Output_roboRIO_InputVoltageStatus ||
     m_Output_roboRIO_InputSPowerStatus) {

    // Get the roboRIO's input voltage
    m_roboRIO_InputVoltage = frc::RobotController::GetInputVoltage();

  } // end if(m_Output_roboRIO_InputVoltage)

  // If we want to output the roboRIO's input current, input power,
  //   input current status, or input power status...
  if(m_Output_roboRIO_InputCurrent ||
     m_Output_roboRIO_InputPower ||
     m_Output_roboRIO_InputCurrentStatus || 
     m_Output_roboRIO_InputSPowerStatus) {

    // Get the roboRIO's input current
    m_roboRIO_InputCurrent = frc::RobotController::GetInputCurrent();

  } // end if(m_Output_roboRIO_InputCurrent)

  // If we want to output the roboRIO's 3.3V rail voltage,
  //   the 3.3V rail voltage status or overall 3.3V rail status
  if(m_Output_roboRIO_3_3V_Rail_Voltage ||
     m_Output_roboRIO_3_3V_Rail_VoltageStatus ||
     m_Output_roboRIO_3_3V_Rail_Status) {

    // Get the roboRIO's 3.3V rail voltage, in Volts
    m_roboRIO_3_3V_Rail_Voltage = frc::RobotController::GetVoltage3V3();

  } // end if(m_Output_roboRIO_3_3V_Rail_Voltage)

  // If we want to output the roboRIO's 3.3V rail current,
  //   3.3V rail current status, or 3.3V rail overall status
  if(m_Output_roboRIO_3_3V_Rail_Current ||
     m_Output_roboRIO_3_3V_Rail_CurrentStatus ||
     m_Output_roboRIO_3_3V_Rail_Status) {

    // Get the roboRIO's 3.3V rail current, in Amps
    m_roboRIO_3_3V_Rail_Current = frc::RobotController::GetCurrent3V3();

  } // end if(m_Output_roboRIO_3_3V_Rail_Current)

  // If we want to output the roboRIO's 3.3V rail enabled status,
  //   or the roboRIO 3.3V rail overall status
  if(m_Output_roboRIO_3_3V_Rail_IsEnabled || 
     m_Output_roboRIO_3_3V_Rail_Status) {

    // Get the roboRIO's 3.3V rail enabled status 
    //  (true = Enabled, false = Not Enabled)
    m_roboRIO_3_3V_Rail_IsEnabled = frc::RobotController::GetEnabled3V3();

  } // end if(m_Output_roboRIO_3_3V_Rail_IsEnabled)

  // If we want to output the roboRIO's 3.3V rail fault count,
  //   the 3.3V rail fault count status, or the roboRIO 3.3V rail 
  //   overall status
  if(m_Output_roboRIO_3_3V_Rail_FaultCount ||
     m_Output_roboRIO_3_3V_Rail_FaultCountStatus ||
     m_Output_roboRIO_3_3V_Rail_Status) {

    // Get the roboRIO's 3.3V rail fault count (an integer)
    m_roboRIO_3_3V_Rail_FaultCount = frc::RobotController::GetFaultCount3V3();

  } // end if(m_Output_roboRIO_3_3V_Rail_FaultCount)

  // If we want to output the roboRIO's 5V rail voltage,
  //   the roboRIO's 5V rail voltage status, or
  //   the roboRIO's 5V rail overall status
  if(m_Output_roboRIO_5V_Rail_Voltage ||
     m_Output_roboRIO_5V_Rail_VoltageStatus ||
     m_Output_roboRIO_5V_Rail_Status) {

    // Get the roboRIO's 5V rail voltage, in Volts
    m_roboRIO_5V_Rail_Voltage = frc::RobotController::GetVoltage5V();

  } // end if(m_Output_roboRIO_5V_Rail_Voltage)

  // If we want to output the roboRIO's 5V rail current,
  //   the roboRIO's 5V rail current status, or
  //   the roboRIO's 5V rail overall status
  if(m_Output_roboRIO_5V_Rail_Current ||
     m_Output_roboRIO_5V_Rail_CurrentStatus ||
     m_Output_roboRIO_5V_Rail_Status) {

    // Get the roboRIO's 5V rail current, in Amps
    m_roboRIO_5V_Rail_Current = frc::RobotController::GetCurrent5V();

  } // end if(m_Output_roboRIO_5V_Rail_Current)

  // If we want to output the roboRIO's 5V rail enabled status or
  //   the roboRIO's 5V rail overall status
  if(m_Output_roboRIO_5V_Rail_IsEnabled ||
     m_Output_roboRIO_5V_Rail_Status) {

    // Get the roboRIO's 5V rail enabled status 
    //  (true = Enabled, false = Not Enabled)
    m_roboRIO_5V_Rail_IsEnabled = frc::RobotController::GetEnabled5V();

  } // end if(m_Output_roboRIO_5V_Rail_IsEnabled)

  // If we want to output the roboRIO's 5V rail fault count,
  //   or the roboRIO's 5V rail overall status
  if(m_Output_roboRIO_5V_Rail_FaultCount ||
     m_Output_roboRIO_5V_Rail_Status) {

    // Get the roboRIO's 5V rail fault count (an integer)
    m_roboRIO_5V_Rail_FaultCount = frc::RobotController::GetFaultCount5V();

  } // end if(m_Output_roboRIO_5V_Rail_FaultCount)

  // If we want to output the roboRIO's 6V rail voltage, or
  //   the roboRIO's 6V rail voltage status, or
  //   the roboRIO's 6V rail overall status
  if(m_Output_roboRIO_6V_Rail_Voltage ||
     m_Output_roboRIO_6V_Rail_VoltageStatus ||
     m_Output_roboRIO_6V_Rail_Status) {

    // Get the roboRIO's 6V rail voltage, in Volts
    m_roboRIO_6V_Rail_Voltage = frc::RobotController::GetVoltage6V();

  } // end if(m_Output_roboRIO_6V_Rail_Voltage)

  // If we want to output the roboRIO's 6V rail current, or
  //   the roboRIO's 6V rail current status, or
  //   the roboRIO's 6V rail overall status
  if(m_Output_roboRIO_6V_Rail_Current ||
     m_Output_roboRIO_6V_Rail_CurrentStatus ||
     m_Output_roboRIO_6V_Rail_Status) {

    // Get the roboRIO's 6V rail current, in Amps
    m_roboRIO_6V_Rail_Current = frc::RobotController::GetCurrent6V();

  } // end if(m_Output_roboRIO_6V_Rail_Current)

  // If we want to output the roboRIO's 6V rail enabled status,
  // or the roboRIO's 6V rail overall status
  if(m_Output_roboRIO_6V_Rail_IsEnabled ||
     m_Output_roboRIO_6V_Rail_Status) {

    // Get the roboRIO's 6V rail enabled status 
    //  (true = Enabled, false = Not Enabled)
    m_roboRIO_6V_Rail_IsEnabled = frc::RobotController::GetEnabled6V();

  } // end if(m_Output_roboRIO_6V_Rail_IsEnabled)

  // If we want to output the roboRIO's 6V rail fault count, or
  //   the roboRIO's 6V rail fault count status, or
  //   the roboRIO's 6V rail overall status
  if(m_Output_roboRIO_6V_Rail_FaultCount ||
     m_Output_roboRIO_6V_Rail_FaultCountStatus ||
     m_Output_roboRIO_6V_Rail_Status) {

    // Get the roboRIO's 6V rail fault count (an integer)
    m_roboRIO_6V_Rail_FaultCount = frc::RobotController::GetFaultCount6V();

  } // end if(m_Output_roboRIO_6V_Rail_FaultCount)

  // If we want to output the roboRIO's brown out status
  if(m_Output_roboRIO_IsBrownedOut) {

    // Get the roboRIO's browned out status
    //   (true = Browned Out, false = Not Browned Out)
    m_roboRIO_IsBrownedOut = frc::RobotController::IsBrownedOut();

  } // end if(m_Output_roboRIO_IsBrownedOut)

  // If we want to output the roboRIO's system active status
  if(m_Output_roboRIO_IsSysActive) {

    // Get the roboRIO's system active status
    //   (true = System Active, false = System Not Active)
    m_roboRIO_IsSysActive = frc::RobotController::IsSysActive();

  } // end if(m_Output_roboRIO_IsSysActive)

  // If we want to output the roboRIO's FPGA Version and Revision
  if(m_Output_roboRIO_FPGA_VerNumRev) {

    // Get the roboRIO's FPGA version
    m_roboRIO_FPGA_VersionNumber = frc::RobotController::GetFPGAVersion();
    // Get the roboRIO's FPGA revision
    m_roboRIO_FPGA_Revision = frc::RobotController::GetFPGARevision();

  } // end if(m_Output_roboRIO_FPGA_VerNumRev)

  // If we want to output the roboRIO's FPGA time elapsed since last boot
  if(m_Output_roboRIO_FPGA_Time) {

    // Get the roboRIO's FPGA time elapsed since last boot, in usec
    m_roboRIO_FPGA_Time = frc::RobotController::GetFPGATime();

  } // end if(m_Output_roboRIO_FPGA_Time)

// If we are using Capt. Hook with a PID controller...
#if USE_PID_CAPT_HOOK

  // If we want to output Capt. Hook's potentimeter value...
  if(m_Output_CaptHook_PotValue) {

    // Get Capt. Hook's potentiometer value
    m_CaptHook_PotValue = Robot::m_PIDsubSysCaptHook->ReturnPIDInput();

  } // end if(m_Output_CaptHook_PotValue)

  // If we want to output the state of Capt. Hook...
  if(m_Output_CaptHookState) {

    m_CaptHookState = Robot::m_PIDsubSysCaptHook->GetCaptHookState();

  } // end if(m_Output_CaptHookState) 

#endif // #if USE_PID_CAPT_HOOK

} // end TelemetryOutputter::GetTelemetry()
