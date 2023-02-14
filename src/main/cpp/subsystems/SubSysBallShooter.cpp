/** ===========================================================================
 * @file   SubSysBallShooter.cpp
 * @brief  This file defines the SubSysBallShooter class.
 *
 * The SubSysBallShooter class allows the robot to intake balls and shoot
 * them.
 *
 * COPYRIGHT NOTICES:
 *
 * Some portions:
 *
 * Copyright (c) 2017-2019 FIRST. All Rights Reserved.
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

// Include the header file for our SubSysBallShooter class
#include "subsystems/SubSysBallShooter.h"

// Include out robot map header file
#include "RobotMap.h"

// Include the header file for HID Constants
#include "HIDs/HID_Constants.h"

// Include the Logitech F310 header
#include "HIDs/LogitechF310.h"

// Include the header file for the projectile motion class
#include "ProjectileMotion/ProjectileMotion.h"

// Include the header file for math/physics constants
#include "MathPhysicsConstants.h"

/************************** Library Header Files ******************************/

// Include the motor safety header file
#include <frc/MotorSafety.h>

// Include the header file for the roboRIO controller telemetry
#include <frc/RobotController.h>

/************************ Member function definitions *************************/

// The SubSysBallShooter default constructor, initializing the motor contollers
// for the shooter system
// NOTE: The 2nd-4th lines are known as member initializations (or initializers)
//       list.
// See https://www.learncpp.com/cpp-tutorial/8-5a-constructor-member-initializer-lists/
SubSysBallShooter::SubSysBallShooter() 
  : m_IntakeController{k_IntakeMotorPWMPort},
    m_LeftIndexerController{k_LeftIndexerMotorPWMPort},
    m_RightIndexerController{k_RightIndexerMotorPWMPort},
    m_MB10X3{k_UltrasonicAnalogInputChannel}
    {

  // Set the subsystem's name
  SetName("SubSysBallShooter");

  // Set the motor safety timeout for the intake motor
  m_IntakeController.SetExpiration(k_IntakeMotorSafetyTimeout);

  // Set the motor safety timeout for the left indexer motor
  m_LeftIndexerController.SetExpiration(k_LeftIndexerMotorSafetyTimeout);

  // Set the motor safety timeout for the right indexer motor
  m_RightIndexerController.SetExpiration(k_RightIndexerMotorSafetyTimeout);

  // Set the PID coefficients 
  m_BallShooterMotorPIDController.SetP(k_P);
  m_BallShooterMotorPIDController.SetI(k_I);
  m_BallShooterMotorPIDController.SetD(k_D);
  m_BallShooterMotorPIDController.SetIZone(k_Iz);
  m_BallShooterMotorPIDController.SetFF(k_FF);

  // Set the output range
  m_BallShooterMotorPIDController.SetOutputRange(k_MinOutput, k_MaxOutput);

  // display PID coefficients on SmartDashboard
  frc::SmartDashboard::PutNumber("P Gain", k_P);
  frc::SmartDashboard::PutNumber("I Gain", k_I);
  frc::SmartDashboard::PutNumber("D Gain", k_D);
  frc::SmartDashboard::PutNumber("I Zone", k_Iz);
  frc::SmartDashboard::PutNumber("Feed Forward", k_FF);
  frc::SmartDashboard::PutNumber("Max Output", k_MaxOutput);
  frc::SmartDashboard::PutNumber("Min Output", k_MinOutput);

  // Set the ball shooter initially to at rest
  m_BallShooterState = AT_REST;

} // end SubSysBallShooter::SubSysBallShooter()

// The SubSysBallShooter destructor
SubSysBallShooter::~SubSysBallShooter() {

} // end SubSysBallShooter::~SubSysBallShooter()

// The periodic method for the shooter subsystem
void SubSysBallShooter::Periodic() {

  // Put code here to be run every loop

  // Feed the intake motor safety system
  m_IntakeController.Feed();

  // Feed the left indexer motor safety system
  m_LeftIndexerController.Feed();

  // Feed the right indexer motor safety system
  m_RightIndexerController.Feed();

  // Get our distance every loop
  m_ultrasonic_sensor_distance_m = 
    SubSysBallShooter::GetUltrasonicOutputMeters();

  SubSysBallShooter::Get_and_Set_PID_terms_from_SmartDashboard();  

} // end SubSysBallShooter::Periodic()

// Put methods for controlling this subsystem
// here. Call these from Commands.

// The method for setting the speed of the intake motor
void SubSysBallShooter::SetIntakeMotorSpeed(double speed) {

  // Set the intake controller to the passed in speed
  m_IntakeController.Set(speed);

} // end SubSysBallShooter::SetIntakeMotorSpeed(double speed)

// The method for setting the speed of the left indexer motor.
void SubSysBallShooter::SetLeftIndexerMotorSpeed(double speed) {

  // Set the left indexer controller to the passed in speed
  m_LeftIndexerController.Set(speed);

} // end SubSysBallShooter::SetLeftIndexerMotorSpeed(double speed)

// The method for setting the speed of the right indexer motor.
void SubSysBallShooter::SetRightIndexerMotorSpeed(double speed) {

  // Set the right indexer controller to the passed in speed
  m_RightIndexerController.Set(speed);

} // end SubSysBallShooter::SetRightIndexerMotorSpeed(double speed)

// The method for setting the speed of the shooter motor,
//   where the speed is in RPM
void SubSysBallShooter::SetShooterMotorSpeed(double SetPoint) {

  // Save  the setpoint off to our class member variable
  m_ShooterMotorVelocitySetPoint = SetPoint;

  // Set the reference set point 
  m_BallShooterMotorPIDController.SetReference(
    m_ShooterMotorVelocitySetPoint, 
    rev::CANSparkMaxLowLevel::ControlType::kVelocity);

} // end SubSysBallShooter::SetShooterMotorSpeed(double speed)

// The method for getting the current shooter motor
// velocity setpoint
double SubSysBallShooter::GetShooterMotorVelocitySetPoint()
{

  // Return the shooter velocity setpoint
  return m_ShooterMotorVelocitySetPoint;

} // end SubSysBallShooter::GetShooterMotorVelocitySetPoint

// The method for getting the shooter motor velocity
double SubSysBallShooter::GetShooterMotorVelocity()
{
 
  // Return the velocity of the shooter motor as
  // reported by the NEO encoder
  return m_BallShooterMotorEncoder.GetVelocity();

} // end SubSysBallShooter::GetShooterMotorVelocity()

// The method for setting the shooter state
void SubSysBallShooter::SetShooterState(
  SubSysBallShooter::BallShooterStates state) {

  // Set the ball shooter state
  m_BallShooterState = state;

} // end SubSysBallShooter::SetShooterState(BallShooterStates state)

// Set the ball shooter state to at rest
void SubSysBallShooter::SetBallShooterStateToAtRest() {

  // Set the ball shooter state to at rest
  SubSysBallShooter::SetShooterState(
    SubSysBallShooter::BallShooterStates::AT_REST);

} // end SubSysBallShooter::SetBallShooterStateToAtRest()

// Set the ball shooter state to at rest
void SubSysBallShooter::SetBallShooterStateToIntaking() {

  // Set the ball shooter state to intaking
  SubSysBallShooter::SetShooterState(
    SubSysBallShooter::BallShooterStates::INTAKING);

} // end SubSysBallShooter::SetBallShooterStateToIntake()

// Set the ball shooter state to shooting low
void SubSysBallShooter::SetBallShooterStateToShootingLow() {

  // Set the ball shooter state to shoot low
  SubSysBallShooter::SetShooterState(
    SubSysBallShooter::BallShooterStates::SHOOTING_LOW);

} // end SubSysBallShooter::SetBallShooterStateToShootingLow()

// Set the ball shooter state to shooting high
void SubSysBallShooter::SetBallShooterStateToShootingHigh() {

  // Set the ball shooter state to shooting high
  SubSysBallShooter::SetShooterState(
    SubSysBallShooter::BallShooterStates::SHOOTING_HIGH);

} // end SubSysBallShooter::SetBallShooterStateToShootingHigh()

// The method for getting the shooter state as a string
std::string SubSysBallShooter::GetShooterStateString() {

  // Depending on which state the ball shooter is in...
  switch(m_BallShooterState) {

    case SubSysBallShooter::BallShooterStates::AT_REST:
      // Set the string for at rest
      m_BallShooterSmartDashboardState = k_BallShooterStateAtRestString;
      break;

    case SubSysBallShooter::BallShooterStates::INTAKING:
      // Set the string for intaking
      m_BallShooterSmartDashboardState = k_BallShooterStateIntakingString;
      break;

    case SubSysBallShooter::BallShooterStates::SHOOTING_LOW:
      // Set the string for shooting low
      m_BallShooterSmartDashboardState = k_BallShooterStateShootingLowString;
      break;

    case SubSysBallShooter::BallShooterStates::SHOOTING_HIGH:
      // Set the string for shooting low
      m_BallShooterSmartDashboardState = k_BallShooterStateShootingHighString;
      break;

    case SubSysBallShooter::BallShooterStates::FAULT:
      // Set the string for fault
      m_BallShooterSmartDashboardState = k_BallShooterStateFaultString;
      break;

    default:
      // Set the string for default
      m_BallShooterSmartDashboardState = k_BallShooterStateUnknownString;

  } // end switch(m_BallShooterState)

  // Now return the string for the dashboard
  return m_BallShooterSmartDashboardState;

} // end SubSysBallShooter::GetShooterStateString()

double SubSysBallShooter::GetUltrasonicOutputMeters() {

  double raw_value;
  double voltage_scale_factor;
  double distance_cm;
  double distance_m;

  raw_value = m_MB10X3.GetValue();

  //voltage_scale_factor allows us to compensate for differences in supply voltage
  voltage_scale_factor = k_Nominal_5V_Voltage / frc::RobotController::GetVoltage5V();

  // Get the distance from the ultrasonic sensor in centimeters
  distance_cm = raw_value * voltage_scale_factor * k_MB10X3_ConversionFactor;

  // Distance in 
  distance_m = distance_cm/100.0;

  return distance_m;

} // end SubSysBallShooter::GetUltrasonicOutputMeters()

void SubSysBallShooter::Get_and_Set_PID_terms_from_SmartDashboard() {

  // read PID coefficients from SmartDashboard
  double p = frc::SmartDashboard::GetNumber("P Gain", 0);
  double i = frc::SmartDashboard::GetNumber("I Gain", 0);
  double d = frc::SmartDashboard::GetNumber("D Gain", 0);
  double iz = frc::SmartDashboard::GetNumber("I Zone", 0);
  double ff = frc::SmartDashboard::GetNumber("Feed Forward", 0);
  double max = frc::SmartDashboard::GetNumber("Max Output", 0);
  double min = frc::SmartDashboard::GetNumber("Min Output", 0);

  // if PID coefficients on SmartDashboard have changed, write new values to controller
  if((p != k_P)) { m_BallShooterMotorPIDController.SetP(p); k_P = p; }
  if((i != k_I)) { m_BallShooterMotorPIDController.SetI(i); k_I = i; }
  if((d != k_D)) { m_BallShooterMotorPIDController.SetD(d); k_D = d; }
  if((iz != k_Iz)) { m_BallShooterMotorPIDController.SetIZone(iz); k_Iz = iz; }
  if((ff != k_FF)) { m_BallShooterMotorPIDController.SetFF(ff); k_FF = ff; }
  if((max != k_MaxOutput) || (min != k_MinOutput)) { 

    m_BallShooterMotorPIDController.SetOutputRange(min, max); 
    k_MinOutput = min; 
    k_MaxOutput = max;

  } // end if 

} // end SubSysBallShooter::Get_and_Set_PID_terms_from_SmartDashboard()

double SubSysBallShooter::CalcShooterMotorSpeedGivenTargetHeight(
  double target_height_m) {

  double y_t = target_height_m;
  double x_t;
  double linear_speed_mps;
  double angular_speed_rpm;

  // Get the target distance (x)
  x_t = SubSysBallShooter::SubSysBallShooter::GetUltrasonicOutputMeters() +
        k_CenterofTopBottomTargetDistanceFromReactWall;

  ProjectileMotion pm_vel0(k_RampDepartureAngle,
                           k_RampPositionRelativeToUltrasonic_x0,
                           k_RampPositionRelativeToFloor_y0,
                           x_t,
                           y_t);

  linear_speed_mps = 
    pm_vel0.get_initial_velocity_from_angle_x0_y0_xt_yt();

  angular_speed_rpm = 
    SubSysBallShooter::GetAngularSpeedFromLinearSpeed(linear_speed_mps);

  return angular_speed_rpm;
}

double SubSysBallShooter::GetAngularSpeedFromLinearSpeed(
  double linear_speed_mps) {

  // Angular speed is linear velocity divided by the radius of the wheel
  double angular_speed_radians_per_sec;
  // Angular speed in rps
  double angular_speed_revolutions_per_sec;
  // Angular speed in  rpm
  double angular_speed_revolutions_per_min;

  const double k_seconds_per_minute = 60.0;  

  angular_speed_radians_per_sec = 
    linear_speed_mps / (k_Shooter_Wheel_Diam_m / 2.0);

  angular_speed_revolutions_per_sec = 
    angular_speed_radians_per_sec / k_radians_per_revolution;

  angular_speed_revolutions_per_min = 
    angular_speed_revolutions_per_sec*k_seconds_per_minute;

  return angular_speed_revolutions_per_min;

} // end SubSysBallShooter::GetAngularSpeedFromLinearSpeed()
