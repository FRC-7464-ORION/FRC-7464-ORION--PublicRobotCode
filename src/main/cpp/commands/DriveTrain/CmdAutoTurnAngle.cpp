/** ===========================================================================
 * @file   CmdAutoTurnAngle.cpp
 * @brief  This file defines the CmdAutoTurnAngle class.
 *
 * The CmdAutoTurnAngle class is used to turn the robot autonomously using a 
 * differential drive in tank mode.
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
 * Copyright (c) 2020-2022 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// Include the header file for the CmdAutoTurnAngle class
#include "commands/DriveTrain/CmdAutoTurnAngle.h"

/************************** Library Header Files ******************************/

// Include the I/O stream class, so we can write to the console
#include <iostream>

/************************ Member function definitions *************************/

// The constructor for the CmdAutoTurnAngle class that sets the angle
CmdAutoTurnAngle::CmdAutoTurnAngle(
  SubSysDriveTrain* subsystem,
  AHRS* ahrs,
  double max_speed,
  double angle) {

  // Set the command's name
  SetName("CmdAutoTurnAngle");

  // Require the use of the drive train subsystem
  AddRequirements({subsystem});

  // Create an instance of a new PIDController
  m_turnController = new frc2::PIDController(m_P_val, m_I_val, m_D_val);

  // Disable the PID controller, through the use of Reset()
  m_turnController->Reset();

  // Set the controller to be continuous (because it is an angle controller)
  m_turnController->EnableContinuousInput(
    k_AutoTurn_Min_Val_Expected, 
    k_AutoTurn_Max_Val_Expected);

  // Set how close (tolerance) we have to get to our target angle
  m_turnController->SetTolerance(m_Tol_val);

  // Initialize the local subsystem
  m_subSysDriveTrain = subsystem;

  // Initialize the local AHRS
  m_AHRS = ahrs;

  // Initialize the local max turn speed
  m_MaxRotateToAngleSpeed = max_speed;

  // Initialize the local target angle
  m_target_angle = angle;

  // Set the motor speed to turn at 0, initially
  m_RotateToAngleSpeed = k_MotorStopSpeed;

  // Set the left and right motor speeds also to 0 initially
  m_left_motor_speed = m_RotateToAngleSpeed;
  m_right_motor_speed = m_RotateToAngleSpeed;

  // Set the timeout for this command
  // NOTE: Timeout is not set here, but when actually called, using
  //       WithTimeout

  /* Add the PID Controller to the Test-mode dashboard, allowing manual  */
  /* tuning of the Turn Controller's P, I and D coefficients.            */
  /* Typically, only the P value needs to be modified.                   */
  frc::LiveWindow::UpdateValues();

} // end CmdAutoTurnAngle::CmdAutoTurnAngle(double, double)

// The destructor for the CmdAutoTurnAngle class
CmdAutoTurnAngle::~CmdAutoTurnAngle() {

  // Delete the m_turnController
  delete m_turnController;

} // end CmdAutoTurnAngle::~CmdAutoTurnAngle()

// Called just before this Command runs the first time
void CmdAutoTurnAngle::Initialize() {

  // Zero the yaw, so we are always pointing to 0 when starting
  // (Robot-Based Reference System)
  m_AHRS->ZeroYaw();

  // Set the drive train mode string to tank
  m_subSysDriveTrain->SetDriveTrainModeStringToTank();

  // Indicate our turn is not completed
  m_turn_completed = false;

  // While the navx is still calibrating...
  while(m_AHRS->IsCalibrating())
  {
    // Wait an approximate robot tick
    frc::Wait(k_ApproximateRobotTickTime);
  }

  // Reset the yaw, so we are always pointing to 0 when starting
  // (Robot-Based Reference System)
  m_AHRS->Reset();

  // Initialize the rotating speed to stopped
  m_RotateToAngleSpeed = k_MotorStopSpeed;

} // end CmdAutoTurnAngle::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdAutoTurnAngle::Execute() {

  // Calculate the speed that we have to rotate at for the controller
  //   to reach our target, clamping our speed to the maximum provided
  m_RotateToAngleSpeed = 
    std::clamp(
      m_turnController->Calculate(m_AHRS->GetAngle(), m_target_angle),
      -1.0 * m_MaxRotateToAngleSpeed, 
      m_MaxRotateToAngleSpeed);

  // Set the left and right motors' speeds
  // NOTE: For tank drive, to turn, left and right motors must
  //       go in opposite directions, hence the negative 
  //       multiplier on the right motors' speed
  m_left_motor_speed = m_RotateToAngleSpeed;
  m_right_motor_speed = -1.0 * m_RotateToAngleSpeed;

  // Turn the robot
  m_subSysDriveTrain->DriveTankStyle(m_left_motor_speed,
                                     m_right_motor_speed);

  // Indicate our turn is completed when we are at the setpoint (target)
  m_turn_completed = m_turnController->AtSetpoint();

}  // end CmdAutoTurnAngle::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdAutoTurnAngle::IsFinished() {

    // Return the value of m_turn_completed, 
    return m_turn_completed;

} // end CmdAutoTurnAngle::IsFinished()

// Called once after isFinished returns true, OR command 
//   is interrupted or canceled
void CmdAutoTurnAngle::End(bool interrupted) {

  if(interrupted)
    // Report the problem
//    frc::DriverStation::ReportError("CmdAutoTurnAngle Timed Out!!!");

  // Disable the PID controller, through the use of Reset()
  m_turnController->Reset();

  // Stop the robot
  m_subSysDriveTrain->DriveTankStyle(k_MotorStopSpeed,
                                     k_MotorStopSpeed);
  
  // Reset the yaw, so we are always pointing to 0 when starting
  // (Robot-Based Reference System)
  m_AHRS->Reset();

} // end CmdAutoTurnAngle::End()
