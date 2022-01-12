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
 * Copyright (c) 2020 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// Include the header file for the CmdAutoTurnAngle class
#include "commands/DriveTrain/CmdAutoTurnAngle.h"

// Include the header file for the drive train
#include "subsystems/SubSysDriveTrain.h"

/************************** Library Header Files ******************************/

// Include the I/O stream class, so we can write to the console
#include <iostream>

// Include the DriverStation header
#include <frc/DriverStation.h>

/************************ Member function definitions *************************/

// The default constructor for the CmdAutoTurnAngle class
CmdAutoTurnAngle::CmdAutoTurnAngle() {

  // Initialize the Navx
  navx_initialization();

  // Indicate that the default constructor was called
  m_default_constructor_called = true;

} // end CmdAutoTurnAngle::CmdAutoTurnAngle()

// The constructor for the CmdAutoTurnAngle class that sets the angle
CmdAutoTurnAngle::CmdAutoTurnAngle(double max_speed, double angle) {

  // Initialize the Navx
  navx_initialization();

  

  // Zero the yaw, so we are always pointing to 0 when starting
  // (Robot-Based Reference System)
  Robot::m_AHRS->ZeroYaw();

  // Set the maximum speed allowed in the rotation
  m_MaxRotateToAngleSpeed = max_speed;

  // Set the target angle with the passed in angle
  m_target_angle = angle;

// Ignore the warning that PIDController is deprecated
// TODO: WE WILL REMOVE ALL DEPRECATED CODE IN OFF-SEASON
// See https://gcc.gnu.org/onlinedocs/gcc/Diagnostic-Pragmas.html
//   and https://www.chiefdelphi.com/t/pragma-or-gradle-flag-for-ignoring-deprecated-warnings/375815
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
  // Create a new PID contoller
  m_turnController = new PIDController(
    m_P_val, m_I_val, m_D_val, m_F_val,
    Robot::m_AHRS,
    this
  );
#pragma GCC diagnostic pop

  // Disable the PID controller for now
  m_turnController->Disable();

  // Set the input range (the target angle) of the PID controller
  m_turnController->SetInputRange(-180.0f,  180.0f);

  // Set the output range (the motor speed - max as determined in constructor)
  m_turnController->SetOutputRange(
                    -1.0 * m_MaxRotateToAngleSpeed, 
                    m_MaxRotateToAngleSpeed);

  // Set how close (tolerance) we have to get to our target angle
  m_turnController->SetAbsoluteTolerance(m_Tol_val);

  // Set the PID controller to consider the input to be continuous
  m_turnController->SetContinuous(true);

  // Set the setpoint (the target angle) for the PID controller
  m_turnController->SetSetpoint(m_target_angle);

  // Set the motor speed to turn at 0, initially
  m_RotateToAngleSpeed = k_MotorStopSpeed;

  // Set the left and right motor speeds also to 0 initially
  m_left_motor_speed = m_RotateToAngleSpeed;
  m_right_motor_speed = m_RotateToAngleSpeed;

  // Indicate that the default constructor was not called
  m_default_constructor_called = false;

  // Get an instance of a LiveWindow
  m_LiveWindow = frc::LiveWindow::GetInstance();

  /* Add the PID Controller to the Test-mode dashboard, allowing manual  */
  /* tuning of the Turn Controller's P, I and D coefficients.            */
  /* Typically, only the P value needs to be modified.                   */
  // m_LiveWindow->AddActuator("DriveTrain", "CmdAutoTurnAngle", m_turnController);
  m_LiveWindow->UpdateValues();

} // end CmdAutoTurnAngle::CmdAutoTurnAngle(double, double)

// This method is used by the constructors to initialize the 
//   NavX MXP IMU
void CmdAutoTurnAngle::navx_initialization()
{
  // Use Requires() here to declare subsystem dependencies

  // Require the use of the drive train subsystem
  // NOTE: We have to use the .get() function because Requires() expects
  //       a pointer to a subsystem, and the pointer below is a 
  //       shared_ptr.
  // See https://stackoverflow.com/questions/505143/getting-a-normal-ptr-from-shared-ptr
  Requires(Robot::m_subSysDriveTrain.get());

  // Set the timeout for this command
  SetTimeout(k_DriveTrain_CmdAutoTurnAngle_Timeout);

} // end void CmdAutoTurnAngle::navx_initialization()

// The destructor for the CmdAutoTurnAngle class
CmdAutoTurnAngle::~CmdAutoTurnAngle() {

  // If we have created an instance of the turn controller
  if(m_turnController != nullptr)
    // Delete the turn controller
    delete m_turnController;

} // end CmdAutoTurnAngle::~CmdAutoTurnAngle()

// Called just before this Command runs the first time
void CmdAutoTurnAngle::Initialize() {

  // Set the drive train mode string to tank
  Robot::m_subSysDriveTrain->SetDriveTrainModeStringToTank();

  // Indicate our turn is not completed
  m_turn_completed = false;

  // While the navx is still calibrating...
  while(Robot::m_AHRS->IsCalibrating())
  {
    // Wait an approximate robot tick
    frc::Wait(k_ApproximateRobotTickTime);
  }

  // Reset the yaw, so we are always pointing to 0 when starting
  // (Robot-Based Reference System)
  Robot::m_AHRS->Reset();

  // Initialize the rotating speed to stopped
  m_RotateToAngleSpeed = k_MotorStopSpeed;

  // Start the PID controller
  m_turnController->Enable();

} // end CmdAutoTurnAngle::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdAutoTurnAngle::Execute() {

  // Set the left and right motors' speeds
  // NOTE: m_RotateToAngleSpeed is updated by PIDWrite()
  // NOTE: For tank drive, to turn, left and right motors must
  //       go in opposite directions, hence the negative 
  //       multiplier on the right motors' speed
  m_left_motor_speed = m_RotateToAngleSpeed;
  m_right_motor_speed = -1.0 * m_RotateToAngleSpeed;

  // In the AHRS class, which inherits from a PIDSource, the 
  // function PIDGet() returns the current yaw. This is where
  // we get the current yaw into the PID controller. A 
  // class inheriting from a PIDSource is expected to have
  // a PIDGet function.

  // Turn the robot
  Robot::m_subSysDriveTrain->DriveTankStyle(m_left_motor_speed,
                                            m_right_motor_speed);

  // Indicate our turn is completed when we are on target
  m_turn_completed = m_turnController->OnTarget();

}  // end CmdAutoTurnAngle::Execute()

// Make this return true when this Command no longer needs to run Execute()
bool CmdAutoTurnAngle::IsFinished() {

  // If we timed out...
  if(IsTimedOut())
    // Report the problem
    frc::DriverStation::ReportError("CmdAutoTurnAngle Timed Out!!!");

  // If we called the default constructor...
  if(m_default_constructor_called)
  {
    // Report the problem
    frc::DriverStation::ReportError("CmdAutoTurnAngle default constructor called!!!");

    // We are finished, as we don't want to run the default constructor
    return true;
  }
  else
  {
    // Return the logical OR of the value of m_turn_completed, 
    // which is set by OnTarget, or if the command has timed out
    return m_turn_completed || IsTimedOut();
  }

} // end CmdAutoTurnAngle::IsFinished()

// Called once after isFinished returns true
void CmdAutoTurnAngle::End() {

  // Disable the PID controller
  m_turnController->Disable();

  // Stop the robot
  Robot::m_subSysDriveTrain->DriveTankStyle(k_MotorStopSpeed,
                                            k_MotorStopSpeed);
  
  // Reset the yaw, so we are always pointing to 0 when starting
  // (Robot-Based Reference System)
  Robot::m_AHRS->Reset();

} // end CmdAutoTurnAngle::End()

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdAutoTurnAngle::Interrupted() {

  // Call the End method
  End();

} // end CmdAutoTurnAngle::Interrupted()

// Called periodically by the PID Controller, based upon navX MXP yaw 
// angle input and PID Coefficients.
void CmdAutoTurnAngle::PIDWrite(double output)
{
  // Set the rotation motor speed to the output provided by the
  // PID controller
  this->m_RotateToAngleSpeed = output;

} // end CmdAutoTurnAngle::PIDWrite(double output)
