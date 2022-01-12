/** ===========================================================================
 * @file   GetAHRS_Info.cpp
 * @brief  This file defines the functions used in getting AHRS
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

// Get the AHRS connection status
void TelemetryOutputter::GetAHRS_Connection_Status()
{

  // If we want to output the AHRS connection status
  if(mk_telemetry[AHRS_CONNECTION_STATUS].output)
  {

    // Get the AHRS connection status 
    m_AHRS_ConnectionStatus = m_AHRS->IsConnected();

  } // end if(mk_telemetry[AHRS_CONNECTION_STATUS].output)

} // end TelemetryOutputer::GetAHRS_Connection_Status()

// Get the AHRS calibration status
void TelemetryOutputter::GetAHRS_Calibration_Status()
{

  // If we want to output the calibration status of the AHRS
  if(mk_telemetry[AHRS_CALIBRATION_STATUS].output)
  {

    // Get the AHRS calibration status 

    // Status is reversed because Calibrating is true, and
    // Calibrated is false. We want Calibrated to be green (true),
    // and calibrating to be red (false).
    m_AHRS_CalibrationStatus = !m_AHRS->IsCalibrating();

  } // end if(mk_telemetry[AHRS_CALIBRATION_STATUS].output)

} // end TelemetryOutputer::GetAHRS_Calibration_Status()

// Get the AHRS pitch
void TelemetryOutputter::GetAHRS_Pitch()
{

  // If we want to output the pitch of the AHRS
  if(mk_telemetry[AHRS_PITCH].output)
  {

    // Get the AHRS pitch 
    m_AHRS_Pitch = m_AHRS->GetPitch();

  } // end if(mk_telemetry[AHRS_PITCH].output)

} // end TelemetryOutputer::GetAHRS_Pitch()

// Get the AHRS roll
    void TelemetryOutputter::GetAHRS_Roll()
{

  // If we want to output the roll of the AHRS
  if(mk_telemetry[AHRS_ROLL].output)
  {

    // Get the AHRS roll 
    m_AHRS_Roll = m_AHRS->GetRoll();

  } // end if(mk_telemetry[AHRS_ROLL].output)

} // end TelemetryOutputer::GetAHRS_Roll()

// Get the AHRS yaw
void TelemetryOutputter::GetAHRS_Yaw()
{

  // If we want to output the yaw of the AHRS
  if(mk_telemetry[AHRS_YAW].output)
  {

    // Get the AHRS yaw 
    m_AHRS_Yaw = m_AHRS->GetYaw();

  } // end if(mk_telemetry[AHRS_YAW].output)

} // end TelemetryOutputer::GetAHRS_Yaw()
    
// Get the AHRS compass heading
void TelemetryOutputter::GetAHRS_Compass_Hdg()
{

  // If we want to output the compass heading of the AHRS
  if(mk_telemetry[AHRS_COMPASS_HDG].output)
  {

    // Get the AHRS compass heading 
    m_AHRS_CompassHdg = m_AHRS->GetCompassHeading();

  } // end if(mk_telemetry[AHRS_COMPASS_HDG].output)

} // end TelemetryOutputer::GetAHRS_Compass_Hdg()

// Get the AHRS linear acceleration on the X axis
void TelemetryOutputter::GetAHRS_Lin_Accl_X()
{

  // If we want to output the X-axis linear acceleration of the AHRS
  if(mk_telemetry[AHRS_LIN_ACCL_X].output)
  {

    // Get the AHRS X-axis linear acceleration
    m_AHRS_LinearAccelX = m_AHRS->GetWorldLinearAccelX();

  } // end if(mk_telemetry[AHRS_LIN_ACCL_X].output)

} // end TelemetryOutputer::GetAHRS_Lin_Accl_X()

// Get the AHRS linear acceleration on the Y axis
void TelemetryOutputter::GetAHRS_Lin_Accl_Y()
{

  // If we want to output the Y-axis linear acceleration of the AHRS
  if(mk_telemetry[AHRS_LIN_ACCL_Y].output)
  {

    // Get the AHRS Y-axis linear acceleration
    m_AHRS_LinearAccelY = m_AHRS->GetWorldLinearAccelY();

  } // end if(mk_telemetry[AHRS_LIN_ACCL_Y].output)

} // end TelemetryOutputer::GetAHRS_Lin_Accl_Y()

// Get the AHRS linear acceleration on the Z axis
void TelemetryOutputter::GetAHRS_Lin_Accl_Z()
{

  // If we want to output the Z-axis linear acceleration of the AHRS
  if(mk_telemetry[AHRS_LIN_ACCL_Z].output)
  {

    // Get the AHRS Z-axis linear acceleration
    m_AHRS_LinearAccelZ = m_AHRS->GetWorldLinearAccelZ();

  } // end if(mk_telemetry[AHRS_LIN_ACCL_Z].output)

} // end TelemetryOutputer::GetAHRS_Lin_Accl_Z()

// Get the AHRS movement status
void TelemetryOutputter::GetAHRS_Moving_Status()
{

  // If we want to output the status of the AHRS moving
  if(mk_telemetry[AHRS_MOVING_STATUS].output)
  {

    // Get the AHRS moving status
    m_AHRS_Moving = m_AHRS->IsMoving();

  } // end if(mk_telemetry[AHRS_MOVING_STATUS].output)

} // end TelemetryOutputer::GetAHRS_Moving_Status()

// Get the AHRS rotation status
void TelemetryOutputter::GetAHRS_Rotating_Status()
{

  // If we want to output the status of the AHRS rotating
  if(mk_telemetry[AHRS_ROTATING_STATUS].output)
  {

    // Get the AHRS rotating status
    m_AHRS_Rotating = m_AHRS->IsRotating();

  } // end if(mk_telemetry[AHRS_ROTATING_STATUS].output)

} // end TelemetryOutputer::GetAHRS_Rotating_Status()

// Get the AHRS fused heading
void TelemetryOutputter::GetAHRS_Fused_Heading()
{

  // If we want to output the fused heading of the AHRS
  if(mk_telemetry[AHRS_FUSED_HDG].output)
  {

    // Get the AHRS fused heading
    m_AHRS_FusedHdg = m_AHRS->GetFusedHeading();

  } // end if(mk_telemetry[AHRS_FUSED_HDG].output)

} // end TelemetryOutputer::GetAHRS_Fused_Heading()

// Get the AHRS No Magnetic Disturbance status
void TelemetryOutputter::GetAHRS_No_Mag_Disturb()
{
  // If we want to see if the AHRS is experiencing magnetic disturbance
  if(mk_telemetry[AHRS_NO_MAG_DISTURB].output)
  {

    // Get the AHRS magnetic disturbance status

    // Note: IsMagDisturb is true if in magnetic disturbance,
    //       false if not. But we want green(true) when we are not
    //       in a disturbance, and red when we are. Hence, the
    //       negation. 
    m_AHRS_NoMagDisturb = !(m_AHRS->IsMagneticDisturbance());

  } // end if(mk_telemetry[AHRS_NO_MAG_DISTURB].output)

} // end TelemetryOutputer::GetAHRS_No_Mag_Disturb()

// Get the AHRS magnetometer calibration status
void TelemetryOutputter::GetAHRS_Mgntmtr_Cal_Status()
{

  // If we want to output the magnetometer calibration status of the AHRS
  if(mk_telemetry[AHRS_MGNTMTR_CAL_STATUS].output)
  {

    // Get the AHRS magnetometer calibration status 

    // Note: m_AHRS_MgntmtrCalStatus is true when the magnetometer,
    //       is calibrating, false if not. But we want green(true) 
    //       when we are not calibrating, but calibrated, and
    //       red when we are calibrating. Hence, the negation. 
    m_AHRS_MgntmtrCalStatus = !(m_AHRS->IsMagnetometerCalibrated());

  } // end if(mk_telemetry[AHRS_MGNTMTR_CAL_STATUS].output)

} // end TelemetryOutputer::GetAHRS_Mgntmtr_Cal_Status()

// Get the AHRS Quaternion W
void TelemetryOutputter::GetAHRS_QuatW()
{

  // If we want to output the Quaternion W of the AHRS
  if(mk_telemetry[AHRS_QUAT_W].output)
  {

    // Get the AHRS quaternion of W
    m_AHRS_QuatW = m_AHRS->GetQuaternionW();

  } // end if(mk_telemetry[AHRS_QUAT_W].output)

} // end TelemetryOutputer::GetAHRS_QuatW()

// Get the AHRS Quaternion X
void TelemetryOutputter::GetAHRS_QuatX()
{

  // If we want to output the Quaternion X of the AHRS
  if(mk_telemetry[AHRS_QUAT_X].output)
  {

    // Get the AHRS quaternion of X
    m_AHRS_QuatX = m_AHRS->GetQuaternionX();

  } // end if(mk_telemetry[AHRS_QUAT_X].output)

} // end TelemetryOutputer::GetAHRS_QuatX()

// Get the AHRS Quaternion Y
void TelemetryOutputter::GetAHRS_QuatY()
{

  // If we want to output the Quaternion Y of the AHRS
  if(mk_telemetry[AHRS_QUAT_Y].output)
  {

    // Get the AHRS quaternion of Y
    m_AHRS_QuatY = m_AHRS->GetQuaternionY();

  } // end if(mk_telemetry[AHRS_QUAT_Y].output)

} // end TelemetryOutputer::GetAHRS_QuatY()

// Get the AHRS Quaternion Z
void TelemetryOutputter::GetAHRS_QuatZ()
{

  // If we want to output the Quaternion Z of the AHRS
  if(mk_telemetry[AHRS_QUAT_Z].output)
  {

    // Get the AHRS quaternion of Z
    m_AHRS_QuatZ = m_AHRS->GetQuaternionZ();

  } // end if(mk_telemetry[AHRS_QUAT_Z].output)

} // end TelemetryOutputer::GetAHRS_QuatZ()

// Get the AHRS yaw angle
void TelemetryOutputter::GetAHRS_Yaw_Angle()
{

  // If we want to output the AHRS yaw angle
  if(mk_telemetry[AHRS_YAW_ANGLE].output)
  {

    // Get the AHRS yaw angle
    m_AHRS_YawAngle = m_AHRS->GetAngle();

  } // end if(mk_telemetry[AHRS_YAW_ANGLE].output)

} // end TelemetryOutputer::GetAHRS_Yaw_Angle()

// Get the AHRS yaw angle adjustment
void TelemetryOutputter::GetAHRS_Yaw_Angle_Adj()
{

  // If we want to output the AHRS yaw angle adjustment
  if(mk_telemetry[AHRS_YAW_ANGLE_ADJ].output)
  {

    // Get the AHRS yaw angle adjustment
    m_AHRS_YawAngleAdj = m_AHRS->GetAngleAdjustment();

  } // end if(mk_telemetry[AHRS_YAW_ANGLE_ADJ].output)

} // end TelemetryOutputer::GetAHRS_Yaw_Angle_Adj()

// Get the AHRS rotation rate
void TelemetryOutputter::GetAHRS_Rotation_Rate()
{

  // If we want to output the AHRS rotation rate
  if(mk_telemetry[AHRS_ROTATION_RATE].output)
  {

    // Get the AHRS rotation rate
    m_AHRS_RotRate = m_AHRS->GetRate();

  } // end if(mk_telemetry[AHRS_ROTATION_RATE].output)

} // end TelemetryOutputer::GetAHRS_Rotation_Rate()

// Get the AHRS temperature in Farenheit
void TelemetryOutputter::GetAHRS_Temperature_F()
{

  // If we want to output the AHRS temperature
  if(mk_telemetry[AHRS_TEMP_F].output)
  {

    // Get the AHRS temperature in C, and convert to F
    m_AHRS_Temp_F = CelsiusToFarenheit(m_AHRS->GetTempC());

  } // end if(mk_telemetry[AHRS_TEMP_F].output)

} // end TelemetryOutputer::GetAHRS_Temperature_F()

// Get the AHRS firmware version
void TelemetryOutputter::GetAHRS_FW_Ver()
{

  // If we want to output the AHRS firmware version
  if(mk_telemetry[AHRS_FW_VER].output)
  {

    // Get the AHRS firmware version
    m_AHRS_FWVer = m_AHRS->GetFirmwareVersion();

  } // end if(mk_telemetry[AHRS_FW_VER].output)

} // end TelemetryOutputer::GetAHRS_FW_Ver()
