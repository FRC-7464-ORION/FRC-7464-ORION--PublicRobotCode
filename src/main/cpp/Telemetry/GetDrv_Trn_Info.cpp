/** ===========================================================================
 * @file   GetDrv_Trn_Info.cpp
 * @brief  This file defines the functions used in getting drive train
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

// Get the drive train mode
void TelemetryOutputter::GetDrvTrnMode()
{

  // If we want to output the drive train mode string...
  if(mk_telemetry[DRV_TRN_MODE].output) {

    m_DriveTrainModeString =
      m_subSysDriveTrain->GetDriveTrainModeString();

  } // end if(mk_telemetry[DRV_TRN_MODE].output)

} // end TelemetryOutputter::GetDrvTrnMode()

// Get the drive train turbo state
void TelemetryOutputter::GetDrvTrnTurboState()
{

  // If we want to output the drive train turbo mode string...
  if(mk_telemetry[DRV_TRN_TURBO_STATE].output) {

    // Get the drive train turbo mode string
    m_DriveTrainTurboState =
      m_subSysDriveTrain->GetTurboModeStatusString();

  } // end if(mk_telemetry[DRV_TRN_TURBO_STATE].output)

} // end TelemetryOutputter::GetDrvTrnTurboState()

// Get the drive train smooting state
void TelemetryOutputter::GetDrvTrnSmoothState()
{

  // If we want to output the drive train smoothing mode string...
  if(mk_telemetry[DRV_TRN_SMOOTH_STATE].output) {

    // Get the drive train smoothing mode string
    m_DriveTrainSmoothingState =
      m_subSysDriveTrain->GetSmoothingStatusString();

  } // end if(mk_telemetry[DRV_TRN_SMOOTH_STATE].output)

} // end TelemetryOutputter::GetDrvTrnSmoothState()

// Get the drive train driving direction
void TelemetryOutputter::GetDrvTrnDrvDir()
{

  // If we want to output the drive direction
  if(mk_telemetry[DRV_TRN_DRV_DIR].output)
  {

    // Get the drive direction
    m_drive_dir = m_subSysDriveTrain->GetDriveDirectionString();

  } // end if(mk_telemetry[DRV_TRN_DRV_DIR].output)

} // end TelemetryOutputter::GetDrvTrnDrvDir()

// Get the drive train left motor #0 current
void TelemetryOutputter::GetDrvTrnLftMtr0Current()
{

  // If we want to output the left drive train motor 0 current,
  //   the left drive train motors current (both motors), or
  //   the drive train motors current (all motors)...
  if(mk_telemetry[DRV_TRN_L_MTR_0_CURRENT].output ||
     mk_telemetry[DRV_TRN_L_MTRS_CURRENT].output  ||
     mk_telemetry[DRV_TRN_MOTORS_CURRENT].output) {

    // Get the left drive train's #0 motor current, in Amps
    m_LeftDriveTrainMotor0Current =
      m_pdp->GetCurrent(k_LeftDriveTrainMotor0PDPChannel);

  } // end if(mk_telemetry[DRV_TRN_L_MTR_0_CURRENT].output || ...)

} // end TelemetryOutputter::GetDrvTrnLftMtr0Current()

// Get the drive train left motor #1 current
void TelemetryOutputter::GetDrvTrnLftMtr1Current()
{

  // If we want to output the left drive train motor 1 current,
  //   the left drive train motors current (both motors), or
  //   the drive train motors current (all motors)...
  if(mk_telemetry[DRV_TRN_L_MTR_1_CURRENT].output ||
     mk_telemetry[DRV_TRN_L_MTRS_CURRENT].output  ||
     mk_telemetry[DRV_TRN_MOTORS_CURRENT].output) {

    // Get the left drive train's #1 motor current, in Amps
    m_LeftDriveTrainMotor1Current =
      m_pdp->GetCurrent(k_LeftDriveTrainMotor1PDPChannel);

  } // end if(mk_telemetry[DRV_TRN_L_MTR_1_CURRENT].output || ...)

} // end TelemetryOutputter::GetDrvTrnLftMtr1Current()

// Get the drive train left motors current
void TelemetryOutputter::GetDrvTrnLftMtrsCurrent()
{

  // If we want to output the left drive train motors current...
  if(mk_telemetry[DRV_TRN_L_MTRS_CURRENT].output)
  {
  
    // Sum the current from the left drive train motors #0 and #1 current
    m_LeftDriveTrainMotorsCurrent = m_LeftDriveTrainMotor0Current +
                                        m_LeftDriveTrainMotor1Current;

  } // end if(mk_telemetry[DRV_TRN_L_MTRS_CURRENT].output)

} // end TelemetryOutputter::GetDrvTrnLftMtrsCurrent()

// Get the drive train right motor #0 current
void TelemetryOutputter::GetDrvTrnRghtMtr0Current()
{

  // If we want to output the right drive train motor 0 current,
  //   the right drive train motors current (both motors), or
  //   the drive train motors current (all motors)...
  if(mk_telemetry[DRV_TRN_R_MTR_0_CURRENT].output ||
     mk_telemetry[DRV_TRN_R_MTRS_CURRENT].output  ||
     mk_telemetry[DRV_TRN_MOTORS_CURRENT].output) {

    // Get the right drive train's #0 motor current, in Amps
    m_RightDriveTrainMotor0Current =
      m_pdp->GetCurrent(k_RightDriveTrainMotor0PDPChannel);

  } // end if(mk_telemetry[DRV_TRN_R_MTR_0_CURRENT].output || ...)

} // end TelemetryOutputter::GetDrvTrnRghtMtr0Current()

// Get the drive train right motor #1 current
void TelemetryOutputter::GetDrvTrnRghtMtr1Current()
{

  // If we want to output the right drive train motor 1 current,
  //   the right drive train motors current (both motors), or
  //   the drive train motors current (all motors)...
  if(mk_telemetry[DRV_TRN_R_MTR_1_CURRENT].output ||
     mk_telemetry[DRV_TRN_R_MTRS_CURRENT].output  ||
     mk_telemetry[DRV_TRN_MOTORS_CURRENT].output) {

    // Get the right drive train's #1 motor current, in Amps
    m_RightDriveTrainMotor1Current =
      m_pdp->GetCurrent(k_RightDriveTrainMotor1PDPChannel);

  } // end if(mk_telemetry[DRV_TRN_R_MTR_1_CURRENT].output || ...)

} // end TelemetryOutputter::GetDrvTrnRghtMtr1Current()

// Get the drive train right motors current
void TelemetryOutputter::GetDrvTrnRghtMtrsCurrent()
{

  // If we want to output the right drive train current (both motors)...
  if(mk_telemetry[DRV_TRN_R_MTRS_CURRENT].output)
  {

      // Sum the current from the right drive train motors #0 and #1 current
    m_RightDriveTrainMotorsCurrent = m_RightDriveTrainMotor0Current +
                                         m_RightDriveTrainMotor1Current;

 
  } // end if(mk_telemetry[DRV_TRN_R_MTRS_CURRENT].output)

} // end TelemetryOutputter::GetDrvTrnRghtMtrsCurrent()

// Get the drive train motors current
void TelemetryOutputter::GetDrvTrnMtrsCurrent()
{

  // If we want to output the drive train current (all motors)...
  if(mk_telemetry[DRV_TRN_MOTORS_CURRENT].output) 
  {
  
      // Sum the current from the all the drive train motors
    m_DriveTrainMotorsCurrent = m_LeftDriveTrainMotor0Current +
                                    m_LeftDriveTrainMotor1Current +
                                    m_RightDriveTrainMotor0Current +
                                    m_RightDriveTrainMotor1Current;


  } // end if(mk_telemetry[DRV_TRN_MOTORS_CURRENT].output)

} // end TelemetryOutputter::GetDrvTrnMtrsCurrent()
