/** ===========================================================================
 * @file   CmdAutoDriveStraight.cpp
 * @brief  This file defines the CmdAutoDriveStraight class.
 *
 * The CmdAutoDriveStraight class is used to control the movement of the robot
 * autonomously using a differential drive in arcade mode.
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

// Include the header file for the CmdAutoDriveStraight class
#include "commands/DriveTrain/CmdAutoDriveStraight.h"

// Include the Robot class header file
#include "Robot.h"

/************************** Library Header Files ******************************/

// Include the I/O stream class, so we can write to the console
#include <iostream>

/************************ Member function definitions *************************/

// The default constructor for the CmdAutoDriveStraight class
CmdAutoDriveStraight::CmdAutoDriveStraight() {

  // Run the common constructor function
  common_constructor_function();

} // end CmdAutoDriveStraight::CmdAutoDriveStraight()

CmdAutoDriveStraight::CmdAutoDriveStraight(
  double spd,
  CmdAutoDriveStraight::DRIVE_STRAIGHT_AUTO_DX_MODE mode,
  CmdAutoDriveStraight::DRIVE_STRAIGHT_DIRECTION dir,
  double val)
{

  // Run the common constructor function
  common_constructor_function();

  // Set the speed to the passed in speed
  speed = spd;

  // Set the distance mode to the passed in mode
  dx_mode = mode;

  // Set the direction from the passed in direction
  direction = dir;

  // Depending on what mode we are using is what we will do with val
  switch(dx_mode)
  {
    // The mode is seconds
    case SECONDS:
      // Set the driven time in seconds from val
      driven_time_seconds = val;
      break;
    // The mode is encoder ticks
    case ENCODER_TICKS:
      // Set the driven distance in encoder ticks from val
      driven_distance_in_encoder_ticks = (int)val;
      break;
    // The mode is centimeters
    case CM:
      // Set the driven distance in cm from val
      driven_distance_in_cm = val;
      break;
    // default:
      // TODO: NEED TO THROW AN EXCEPTION HERE!!!
  }

} // end CmdAutoDriveStraight::CmdAutoDriveStraight(double, enum, enum, double)

// The destructor for the CmdAutoDriveStraight class
CmdAutoDriveStraight::~CmdAutoDriveStraight() {

  // Delete the timer, if instantiated
  if(m_timer != nullptr)
    delete m_timer;

} // end CmdAutoDriveStraight::~CmdAutoDriveStraight()

// Called just before this Command runs the first time
void CmdAutoDriveStraight::Initialize() {

  // Set the drive train mode string to arcade
  Robot::m_subSysDriveTrain->SetDriveTrainModeStringToArcade();

  // Indicate we have not exceeded our distance
  driven_distance_exceeded = false;

  // Create a new timer
  m_timer = new frc::Timer();

  // Reset the timer
  m_timer->Reset();

  // Start the timer
  m_timer->Start();

} // end CmdAutoDriveStraight::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdAutoDriveStraight::Execute() {

  // The corrected Y axis motor speed, set to stopped initially
  double corrected_Y_axis_motor_speed = k_MotorStopSpeed;

  // Switch on the direction we are to go
  switch(direction)
  {
    // If we are to go forward
    case FORWARD:
      // Simply use the passed in speed
      corrected_Y_axis_motor_speed = speed;
      break;
    case REVERSE:
      // Use the passed in speed, multiplied by our constant
      corrected_Y_axis_motor_speed = speed * k_ReverseSpeedMultiplier;
      break;
    // default:
      // TODO: NEED TO THROW EXCEPTION
  }

  // Switch on the distance mode selected
  switch(dx_mode)
  {
    // If we are using time...
    case SECONDS:
      // If the timer has exceeded our drive time...
      if(m_timer->Get() >= driven_time_seconds)
      {
        // We have exceeded our driven distance
        driven_distance_exceeded = true;
      }
      break;
    case ENCODER_TICKS:
      // Need code to get encoder ticks
      // For now, just say we've exceeded our distance
      driven_distance_exceeded = true;
      break;
    case CM:
      // Need code to get actual distance
      // For now, just say we've exceeded our distance
      driven_distance_exceeded = true;
      break;
    // default:
      // TODO: NEED TO THROW EXCEPTION
  }

  // If we have NOT exceeded our driven distance...
  if(!driven_distance_exceeded)
  {
    // Drive arcade style using the passed in speed and direction
    Robot::m_subSysDriveTrain->DriveArcadeStyle(
      corrected_Y_axis_motor_speed,
      k_X_Axis_Value_For_Straight
    );

  }
  else
  {
    // Stop the robot
    Robot::m_subSysDriveTrain->DriveArcadeStyle(k_MotorStopSpeed,
                                                k_MotorStopSpeed);
  }

}  // end CmdAutoDriveStraight::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdAutoDriveStraight::IsFinished() {

  // Return the status of if we exceeded our distance
  return driven_distance_exceeded;

} // end CmdAutoDriveStraight::IsFinished()

// Called once after isFinished returns true
void CmdAutoDriveStraight::End() {

  // Stop the robot
  Robot::m_subSysDriveTrain->DriveArcadeStyle(k_MotorStopSpeed,
                                              k_MotorStopSpeed);

  // Stop the timer
  m_timer->Stop();

} // end CmdAutoDriveStraight::End()

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdAutoDriveStraight::Interrupted() {

  // Call the End method
  End();

} // end CmdAutoDriveStraight::Interrupted()

void CmdAutoDriveStraight::common_constructor_function()
{
  // Use Requires() here to declare subsystem dependencies

  // Require the use of the drive train subsystem
  // NOTE: We have to use the .get() function because Requires() expects
  //       a pointer to a subsystem, and the pointer below is a 
  //       shared_ptr.
  // See https://stackoverflow.com/questions/505143/getting-a-normal-ptr-from-shared-ptr
  Requires(Robot::m_subSysDriveTrain.get());

} // end void CmdAutoDriveStraight::common_constructor_function()
