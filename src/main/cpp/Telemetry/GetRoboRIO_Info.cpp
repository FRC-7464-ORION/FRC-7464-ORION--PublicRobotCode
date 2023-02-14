/** ===========================================================================
 * @file   GetRoboRIO_Info.cpp
 * @brief  This file defines the functions used in getting RoboRIO
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

// Get the roboRIO X axis accelerometer value 
void TelemetryOutputter::GetRoboRIO_Accel_X_Axis()
{
  // If we want to output the roboRIO's X-axis acceleration...
  if(mk_telemetry[ROBORIO_ACCEL_X_AXIS].output) {

  // Get the roboRIO's X-axis acceleration, in Gs
  m_roboRIO_Accel_X_Axis = m_roboRIO_accelerometers->GetX();

  } // end if(mk_telemetry[ROBORIO_ACCEL_X_AXIS].output)

} // end TelemetryOutputter::GetRoboRIO_Accel_X_Axis()

// Get the roboRIO Y axis accelerometer value
void TelemetryOutputter::GetRoboRIO_Accel_Y_Axis()
{

  // If we want to output the roboRIO's Y-axis acceleration...
  if(mk_telemetry[ROBORIO_ACCEL_Y_AXIS].output) {

    // Get the roboRIO's Y-axis acceleration, in Gs
    m_roboRIO_Accel_Y_Axis = m_roboRIO_accelerometers->GetY();

  } // end if(mk_telemetry[ROBORIO_ACCEL_Y_AXIS].output)

} // end TelemetryOutputter::GetRoboRIO_Accel_Y_Axis()

// Get the roboRIO Z axis accelerometer value
void TelemetryOutputter::GetRoboRIO_Accel_Z_Axis()
{

  // If we want to output the roboRIO's Z-axis acceleration...
  if(mk_telemetry[ROBORIO_ACCEL_Z_AXIS].output) {

    // Get the roboRIO's Z-axis acceleration, in Gs
    m_roboRIO_Accel_Z_Axis = m_roboRIO_accelerometers->GetZ();

  } // end if(mk_telemetry[ROBORIO_ACCEL_Z_AXIS].output)

} // end TelemetryOutputter::GetRoboRIO_Accel_Z_Axis()

// Get the roboRIO input voltage
void TelemetryOutputter::GetRoboRIO_Input_Voltage()
{

  // If we want to output the roboRIO's input voltage, input power,
  //   input voltage status, or input power status
  if(mk_telemetry[ROBORIO_INPUT_VOLTAGE].output ||
     mk_telemetry[ROBORIO_INPUT_POWER].output
#if 0 
     || m_Output_roboRIO_InputVoltageStatus ||
     m_Output_roboRIO_InputSPowerStatus
#endif
    )
  {

    // Get the roboRIO's input voltage
    m_roboRIO_InputVoltage = frc::RobotController::GetInputVoltage();

  } // end if(mk_telemetry[ROBORIO_INPUT_VOLTAGE].output ||...

} // end TelemetryOutputter::GetRoboRIO_Input_Voltage()

// Get the roboRIO input current
void TelemetryOutputter::GetRoboRIO_Input_Current()
{

  // If we want to output the roboRIO's input current, input power,
  //   input current status, or input power status...
  if(mk_telemetry[ROBORIO_INPUT_CURRENT].output ||
     mk_telemetry[ROBORIO_INPUT_POWER].output
#if 0 
     || m_Output_roboRIO_InputCurrentStatus || 
     m_Output_roboRIO_InputSPowerStatus
#endif
    ) 
  {

    // Get the roboRIO's input current
    m_roboRIO_InputCurrent = frc::RobotController::GetInputCurrent();

  } // end if(mk_telemetry[ROBORIO_INPUT_CURRENT].output ||...

} // end TelemetryOutputter::GetRoboRIO_Input_Current()

// Get the roboRIO input power
void TelemetryOutputter::GetRoboRIO_Input_Power()
{

  // If we want to output the roboRIO input power...
  if(mk_telemetry[ROBORIO_INPUT_POWER].output)
  {

    // We have to calculate P=VI, as not reported via roboRIO
    m_roboRIO_InputPower = m_roboRIO_InputVoltage *
                             m_roboRIO_InputCurrent;

  } // end if(mk_telemetry[ROBORIO_INPUT_POWER].output)

} // end TelemetryOutputter::GetRoboRIO_Input_Power()

// Get the roboRIO 3.3V rail voltage
void TelemetryOutputter::GetRoboRIO_3_3V_Rail_Voltage()
{

  // If we want to output the roboRIO's 3.3V rail voltage,
  //   the 3.3V rail voltage status or overall 3.3V rail status
  if(mk_telemetry[ROBORIO_3_3V_RAIL_VOLTAGE].output 
#if 0
    || m_Output_roboRIO_3_3V_Rail_VoltageStatus ||
     m_Output_roboRIO_3_3V_Rail_Status
#endif
    ) 
  {

    // Get the roboRIO's 3.3V rail voltage, in Volts
    m_roboRIO_3_3V_Rail_Voltage = frc::RobotController::GetVoltage3V3();

  } // end if(mk_telemetry[ROBORIO_3_3V_RAIL_VOLTAGE].output...

} // end TelemetryOutputter::GetRoboRIO_3_3V_Rail_Voltage()

// Get the roboRIO 3.3V rail current
void TelemetryOutputter::GetRoboRIO_3_3V_Rail_Current()
{

  // If we want to output the roboRIO's 3.3V rail current,
  //   3.3V rail current status, or 3.3V rail overall status
  if(mk_telemetry[ROBORIO_3_3V_RAIL_CURRENT].output
#if 0 
    || m_Output_roboRIO_3_3V_Rail_CurrentStatus ||
     m_Output_roboRIO_3_3V_Rail_Status
#endif
    ) 
  {

    // Get the roboRIO's 3.3V rail current, in Amps
    m_roboRIO_3_3V_Rail_Current = frc::RobotController::GetCurrent3V3();

  } // end if(mk_telemetry[ROBORIO_3_3V_RAIL_CURRENT].output...

} // end TelemetryOutputter::GetRoboRIO_3_3V_Rail_Current()

// Get the roboRIO 3.3V rail enabled status
void TelemetryOutputter::GetRoboRIO_3_3V_Rail_Enabled()
{

  // If we want to output the roboRIO's 3.3V rail enabled status,
  //   or the roboRIO 3.3V rail overall status
  if(mk_telemetry[ROBORIO_3_3V_RAIL_ENABLED].output
#if 0
    || m_Output_roboRIO_3_3V_Rail_Status
#endif
    ) 
  {

    // Get the roboRIO's 3.3V rail enabled status 
    //  (true = Enabled, false = Not Enabled)
    m_roboRIO_3_3V_Rail_IsEnabled = frc::RobotController::GetEnabled3V3();

  } // end if(mk_telemetry[ROBORIO_3_3V_RAIL_ENABLED].output...

} // end TelemetryOutputter::GetRoboRIO_3_3V_Rail_Enabled()

// Get the roboRIO 3.3V rail fault count
void TelemetryOutputter::GetRoboRIO_3_3V_Rail_Flt_Cnt()
{

  // If we want to output the roboRIO's 3.3V rail fault count,
  //   the 3.3V rail fault count status, or the roboRIO 3.3V rail 
  //   overall status
  if(mk_telemetry[ROBORIO_3_3V_RAIL_FLT_CNT].output
#if 0
     || m_Output_roboRIO_3_3V_Rail_FaultCountStatus ||
     m_Output_roboRIO_3_3V_Rail_Status
#endif
    ) 
  {

    // Get the roboRIO's 3.3V rail fault count (an integer)
    m_roboRIO_3_3V_Rail_FaultCount = frc::RobotController::GetFaultCount3V3();

  } // end if(mk_telemetry[ROBORIO_3_3V_RAIL_FLT_CNT].output...

} // end TelemetryOutputter::GetRoboRIO_3_3V_Rail_Flt_Cnt()

// Get the roboRIO 5V rail voltage
void TelemetryOutputter::GetRoboRIO_5V_Rail_Voltage()
{

  // If we want to output the roboRIO's 5V rail voltage,
  //   the roboRIO's 5V rail voltage status, or
  //   the roboRIO's 5V rail overall status
  if(mk_telemetry[ROBORIO_5V_RAIL_VOLTAGE].output
#if 0 
     || m_Output_roboRIO_5V_Rail_VoltageStatus ||
     m_Output_roboRIO_5V_Rail_Status
#endif
    ) 
  {

    // Get the roboRIO's 5V rail voltage, in Volts
    m_roboRIO_5V_Rail_Voltage = frc::RobotController::GetVoltage5V();

  } // end if(mk_telemetry[ROBORIO_5V_RAIL_VOLTAGE].output...

} // end TelemetryOutputter::GetRoboRIO_5V_Rail_Voltage()

// Get the roboRIO 5V rail current
void TelemetryOutputter::GetRoboRIO_5V_Rail_Current()
{

  // If we want to output the roboRIO's 5V rail current,
  //   the roboRIO's 5V rail current status, or
  //   the roboRIO's 5V rail overall status
  if(mk_telemetry[ROBORIO_5V_RAIL_CURRENT].output
#if 0 
     || m_Output_roboRIO_5V_Rail_CurrentStatus ||
     m_Output_roboRIO_5V_Rail_Status
#endif
    ) 
  {

    // Get the roboRIO's 5V rail current, in Amps
    m_roboRIO_5V_Rail_Current = frc::RobotController::GetCurrent5V();

  } // end if(mk_telemetry[ROBORIO_5V_RAIL_CURRENT].output...

} // end TelemetryOutputter::GetRoboRIO_5V_Rail_Current()

// Get the roboRIO 5V rail enabled status
void TelemetryOutputter::GetRoboRIO_5V_Rail_Enabled()
{

  // If we want to output the roboRIO's 5V rail enabled status or
  //   the roboRIO's 5V rail overall status
  if(mk_telemetry[ROBORIO_5V_RAIL_ENABLED].output 
#if 0 
     || m_Output_roboRIO_5V_Rail_Status
#endif
    ) 
  {

    // Get the roboRIO's 5V rail enabled status 
    //  (true = Enabled, false = Not Enabled)
    m_roboRIO_5V_Rail_IsEnabled = frc::RobotController::GetEnabled5V();

  } // end if(mk_telemetry[ROBORIO_5V_RAIL_ENABLED].output...

} // end TelemetryOutputter::GetRoboRIO_5V_Rail_Enabled()

// Get the roboRIO 5V rail fault count
void TelemetryOutputter::GetRoboRIO_5V_Rail_Flt_Cnt()
{

  // If we want to output the roboRIO's 5V rail fault count,
  //   or the roboRIO's 5V rail overall status
  if(mk_telemetry[ROBORIO_5V_RAIL_FLT_CNT].output 
#if 0 
     || m_Output_roboRIO_5V_Rail_Status
#endif
    )
  {

    // Get the roboRIO's 5V rail fault count (an integer)
    m_roboRIO_5V_Rail_FaultCount = frc::RobotController::GetFaultCount5V();

  } // end if(mk_telemetry[ROBORIO_5V_RAIL_FLT_CNT].output...

} // end TelemetryOutputter::GetRoboRIO_5V_Rail_Flt_Cnt()

// Get the roboRIO 6V rail voltage
void TelemetryOutputter::GetRoboRIO_6V_Rail_Voltage()
{

  // If we want to output the roboRIO's 6V rail voltage, or
  //   the roboRIO's 6V rail voltage status, or
  //   the roboRIO's 6V rail overall status
  if(mk_telemetry[ROBORIO_6V_RAIL_VOLTAGE].output
#if 0
     || m_Output_roboRIO_6V_Rail_VoltageStatus ||
     m_Output_roboRIO_6V_Rail_Status
#endif
    )
  {

    // Get the roboRIO's 6V rail voltage, in Volts
    m_roboRIO_6V_Rail_Voltage = frc::RobotController::GetVoltage6V();

  } // end if(mk_telemetry[ROBORIO_6V_RAIL_VOLTAGE].output...

} // end TelemetryOutputter::GetRoboRIO_6V_Rail_Voltage()

// Get the roboRIO 6V rail current
void TelemetryOutputter::GetRoboRIO_6V_Rail_Current()
{

  // If we want to output the roboRIO's 6V rail current, or
  //   the roboRIO's 6V rail current status, or
  //   the roboRIO's 6V rail overall status
  if(mk_telemetry[ROBORIO_6V_RAIL_CURRENT].output 
#if 0
     || m_Output_roboRIO_6V_Rail_CurrentStatus ||
     m_Output_roboRIO_6V_Rail_Status
#endif
    )
  {

    // Get the roboRIO's 6V rail current, in Amps
    m_roboRIO_6V_Rail_Current = frc::RobotController::GetCurrent6V();

  } // end if(mk_telemetry[ROBORIO_6V_RAIL_CURRENT].output...

} // end TelemetryOutputter::GetRoboRIO_6V_Rail_Current()

// Get the roboRIO 6V rail enabled status
void TelemetryOutputter::GetRoboRIO_6V_Rail_Enabled()
{

  // If we want to output the roboRIO's 6V rail enabled status,
  // or the roboRIO's 6V rail overall status
  if(mk_telemetry[ROBORIO_6V_RAIL_ENABLED].output
#if 0 
     || m_Output_roboRIO_6V_Rail_Status
#endif
    )
  {

    // Get the roboRIO's 6V rail enabled status 
    //  (true = Enabled, false = Not Enabled)
    m_roboRIO_6V_Rail_IsEnabled = frc::RobotController::GetEnabled6V();

  } // end if(mk_telemetry[ROBORIO_6V_RAIL_ENABLED].output...

} // end TelemetryOutputter::GetRoboRIO_6V_Rail_Enabled()

// Get the roboRIO 6V rail fault count
void TelemetryOutputter::GetRoboRIO_6V_Rail_Flt_Cnt()
{

  // If we want to output the roboRIO's 6V rail fault count, or
  //   the roboRIO's 6V rail fault count status, or
  //   the roboRIO's 6V rail overall status
  if(mk_telemetry[ROBORIO_6V_RAIL_FLT_CNT].output
#if 0
     || m_Output_roboRIO_6V_Rail_FaultCountStatus ||
     m_Output_roboRIO_6V_Rail_Status
#endif
    )
  {

    // Get the roboRIO's 6V rail fault count (an integer)
    m_roboRIO_6V_Rail_FaultCount = frc::RobotController::GetFaultCount6V();

  } // end if(mk_telemetry[ROBORIO_6V_RAIL_FLT_CNT].output...

} // end TelemetryOutputter::GetRoboRIO_6V_Rail_Flt_Cnt()

// Get the roboRIO Isn't browned out status
void TelemetryOutputter::GetRoboRIO_Isnt_BrownedOut()
{

  // If we want to output the roboRIO's brown out status
  if(mk_telemetry[ROBORIO_ISNT_BROWNED_OUT].output) {

    // Get the roboRIO's browned out status
    //   (true = Browned Out, false = Not Browned Out)

    // However, we want to actually output if power is okay, equivalent to
    // a message stating "NO BROWN OUT". So we will invert it.
    m_roboRIO_IsNotBrownedOut = !(frc::RobotController::IsBrownedOut());

  } // end if(mk_telemetry[ROBORIO_ISNT_BROWNED_OUT].output)

} // end TelemetryOutputter::GetRoboRIO_Isnt_BrownedOut()

// Get the roboRIO is system active status
void TelemetryOutputter::GetRoboRIO_Is_SysActive()
{

  // If we want to output the roboRIO's system active status
  if(mk_telemetry[ROBORIO_IS_SYS_ACTIVE].output) {

    // Get the roboRIO's system active status
    //   (true = System Active, false = System Not Active)
    m_roboRIO_IsSysActive = frc::RobotController::IsSysActive();

  } // end if(mk_telemetry[ROBORIO_IS_SYS_ACTIVE].output)

} // end TelemetryOutputter::GetRoboRIO_Is_SysActive()

// Get the roboRIO FPGA's version, revision, and build
void TelemetryOutputter::GetRoboRIO_FPGA_Ver_Rev_Bld()
{

  // If we want to output the roboRIO's FPGA Version, Revision, & build
  if(mk_telemetry[ROBORIO_FPGA_VER_REV_BLD].output) {

    // Get the roboRIO's FPGA version
    m_roboRIO_FPGA_VersionNumber = frc::RobotController::GetFPGAVersion();
    // Get the roboRIO's FPGA revision
    m_roboRIO_FPGA_Revision = frc::RobotController::GetFPGARevision();

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
    m_roboRIO_FPGA_Ver_Rev_Bld =
        std::to_string(m_roboRIO_FPGA_VersionNumber)
      + "."
      + std::to_string(m_roboRIO_FPGA_MajorRevision)
      + "."
      + std::to_string(m_roboRIO_FPGA_MinorRevision)
      + " Build "
      + std::to_string(m_roboRIO_FPGA_BuildNumber);

  } // end if(mk_telemetry[ROBORIO_FPGA_VER_REV_BLD].output)

} // end TelemetryOutputter::GetRoboRIO_FPGA_Ver_Rev_Bld()
    
// Get the roboRIO FPGA time
void TelemetryOutputter::GetRoboRIO_FPGA_Time()
{

  // If we want to output the roboRIO's FPGA time elapsed since last boot
  if(mk_telemetry[ROBORIO_FPGA_TIME].output) {

    // Get the roboRIO's FPGA time elapsed since last boot, in usec
    m_roboRIO_FPGA_Time = frc::RobotController::GetFPGATime();

  } // end if(mk_telemetry[ROBORIO_FPGA_TIME].output)

} // end TelemetryOutputter::GetRoboRIO_FPGA_Time()
