/** ===========================================================================
 * @file   SubSysBallShooter.h
 * @brief  This file declares the SubSysBallShooter class, which is a
 *         subsystem of the robot.
 *
 * The SubSysBallShooter class is used to gather balls and shoot them.
 * 
 * This subsystem consists of:
 * 
 * 1. An intake mechanism to load balls into the robot
 * 2. An indexer mechanism, that has two purposes:
 *   a. Help move a single ball up, so we can load two balls into the robot
 *   b. Help move a single ball up to the shooter mechanism.
 * 3. A shooter mechanism to shoot balls away from the robot
 * 4. An encoder used to monitor the speed of the shooter motor
 * 5. An ultrasonic distance measurement tool
 * 
 * The intake mechanism consists of:
 * 1. A CIM motor directly driving a shaft to turn three wheels over the top 
 *    of the ball
 * 
 * The indexer mechanism consists of: 
 * 1. Two mini-CIM motors, one on the left, one on the right, that turn two 
 *    wheels each side connected via a belt to move balls from the side up 
 *    the ramp
 * 
 * 3. A NEO motor used to directly drive a shaft that turns ?? wheels on
 *    top of the ball to eject/shoot the ball to the target.
 * 
 * 4. An encoder is built into the NEO motor, which will be used as feedback
 *    to monitor the speed of the shooter (NEO) motor.
 * 
 * 5. An ultrasonic distance meansurement tool is used to measure the distance
 *    from the robot to the target. This distance is used as feedback in a 
 *    trajectory following algorithm that helps determine the speed required
 *    of the shooter motor to accurately hit the target.
 * 
 * The commands for this subsystem are:
 * 
 * 1. Intake
 * 2. Shoot low target
 * 3. Shoot high target
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
 * Copyright (c) 2020-2022 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

// INCLUDE GUARD - see https://en.wikipedia.org/wiki/Include_guard
// If we have not already defined SUBSYSBALLSHOOTER_H...
#ifndef SUBSYSBALLSHOOTER_H
// Define SUBSYSBALLSHOOTER_H
#define SUBSYSBALLSHOOTER_H

/*************************** Local Header Files *******************************/

// Include the robot constants header
#include "RobotConstants.h"

// Include the robot map
#include "RobotMap.h"

// Include the Spark Max via CAN header file, for the NEO motor controller
#include "rev/CANSparkMax.h"

/************************** Library Header Files ******************************/

// Include the NEW(2020) subsystem base class header file
#include <frc2/command/SubsystemBase.h>

// Include the PWMVictorSPX header file, for the motor controllers
#include <frc/motorcontrol/PWMVictorSPX.h>

// Include the DriverStation, for errors and warnings
#include <frc/DriverStation.h>

// Include the analog input, for the ultrasonic sensor
#include <frc/AnalogInput.h>

// Include the SmartDashboard class header file, which allows us to transmit
//   robot data to the operator console
// See:
// https://wpilib.screenstepslive.com/s/currentCS/m/smartdashboard
#include <frc/smartdashboard/SmartDashboard.h>

/** ****************************************************************************
 * @class   SubSysBallShooter
 * @brief   This class declares the ball intake and shooter system.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class SubSysBallShooter : public frc2::SubsystemBase {

  public:

    /************************** PUBLIC ENUMERATIONS ***************************/

    /** An enumeration of states that the ball shooter can have */ 
    enum BallShooterStates
    {
      /** We don't know what state it is in */
      UNKNOWN,
      /** Something wrong has happened */
      FAULT,
      /** We are not doing anything */
      AT_REST,
      /** We are getting some balls from the floor */
      INTAKING,
      /** We are shooting balls at the low target */
      SHOOTING_LOW,
      /** We are shooting balls at the high target */
      SHOOTING_HIGH
    };

    /********************** PUBLIC MEMBER FUNCTIONS ***************************/

    /** The default constructor for the SubSysBallShooter class */
    SubSysBallShooter();

    /** The default destructor for the SubSysBallShooter class */
    ~SubSysBallShooter();

    /** The periodic method for BallShooter */
    void Periodic() override;

    /** 
     * The method for setting the speed of the intake motor.
     * 
     * @param speed The normalized speed (-1 to +1) to set to the intake motor
     * 
    */
    void SetIntakeMotorSpeed(double speed);

    /** 
     * The method for setting the speed of the left indexer motor.
     * 
     * @param speed The normalized speed (-1 to +1) to set to the left 
     *              indexer motor
     * 
    */
    void SetLeftIndexerMotorSpeed(double speed);

    /** 
     * The method for setting the speed of the right indexer motor.
     * 
     * @param speed The normalized speed (-1 to +1) to set to the right 
     *              indexer motor
     * 
    */
    void SetRightIndexerMotorSpeed(double speed);

    /** 
     * The method for setting the speed of the shooter motor.
     * 
     * @param SetPoint The anglular speed to set to the shooter 
     *                 motor, in RPM
     * 
    */
    void SetShooterMotorSpeed(double SetPoint);

    /** 
     * The method for getting the velocity setpoint of the shooter motor 
     * 
     * @return The velocity set point for the shooter motor
    */
    double GetShooterMotorVelocitySetPoint();

    /** 
     * The method for getting the actual velocity of the shooter motor 
     * 
     * @return The actual velocity of the shooter motor
    */
    double GetShooterMotorVelocity();

    /** 
     * The method for setting the state to at rest 
    */
    void SetBallShooterStateToAtRest();

    /** 
     * The method for setting the state to intake 
    */
    void SetBallShooterStateToIntaking();

    /** 
     * The method for setting the state to shoot low 
    */
    void SetBallShooterStateToShootingLow();

    /** 
     * The method for setting the state to shoot high 
    */
    void SetBallShooterStateToShootingHigh();

    /** 
     * The method for getting the shooter state as a string
     * 
     * @return The string indicating the shooter state
     * 
    */
    std::string GetShooterStateString();

    /**
     * The method for getting the ultrasonic output, in meters
     * 
     * @return The output of the ultrasonic distance in meters
     * 
    */
    double GetUltrasonicOutputMeters();

    /** 
     * The method for getting PID terms from the SmartDashboard,
     * and setting them into the Spark MAX controller */
    void Get_and_Set_PID_terms_from_SmartDashboard();

    /**
     * The method for calculating shooter motor speed in RPM,
     * given a target height (y_t) in meters
     * 
     * @param target_height_m The height of the target to hit,
     * in meters
    */
   double CalcShooterMotorSpeedGivenTargetHeight(
     double target_height_m
   );

   /** 
    * The method for calculating the angular speed (RPM) required
    *  given the linear speed in meters per second.
    * 
    * @param linear_speed_mps Linear speed, in meters per second  
   */
   double GetAngularSpeedFromLinearSpeed(
     double linear_speed_mps
   );

  private:
    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities

    /********************* PRIVATE MEMBER FUNCTIONS ***************************/

    /**
     * The method for setting the shooter state
     * 
     * @param state The shooter state
     * 
    */
    void SetShooterState(BallShooterStates state);

    /********************* PRIVATE MEMBER VARIABLES ***************************/

    /** The intake motor controller */
    frc::PWMVictorSPX m_IntakeController;

    /** The left indexer motor controller */
    frc::PWMVictorSPX m_LeftIndexerController;

    /** The right indexer motor controller */
    frc::PWMVictorSPX m_RightIndexerController;

    /** Declare a Spark MAX motor controller controlled via CAN */
    rev::CANSparkMax m_BallShooterMotorControllerviaCAN{
      k_SparkMAXShooter_CAN_Bus_DeviceID, 
      rev::CANSparkMax::MotorType::kBrushless};

    /** Declare a Spark MAX PID controller */
    rev::SparkMaxPIDController m_BallShooterMotorPIDController = 
      m_BallShooterMotorControllerviaCAN.GetPIDController();
 
    /** Declare a Spark MAX relative encoder */
    rev::SparkMaxRelativeEncoder m_BallShooterMotorEncoder = 
      m_BallShooterMotorControllerviaCAN.GetEncoder();

    /** A string to hold the state of the ball shooter for 
     * the SmartDashboard */
    std::string m_BallShooterSmartDashboardState;

    /** The state of the ball shooter */
    BallShooterStates m_BallShooterState;

    /** The ultrasonic sensor */
    frc::AnalogInput m_MB10X3;

    /** The distance from the back of the MB10X3 circuit board, in meters */
    double m_ultrasonic_sensor_distance_m;

    /** The distance of the ramp to the target board */
    double m_ramp_distance_m;

    /** The shooter motor velocity setpoint */
    double m_ShooterMotorVelocitySetPoint;

    /** The actual shooter motor velocity */
    double m_ShooterMotorVelocity;

    // Default PID Coefficients
    
    /** Ball Shooter PID Proportional Term */
    double k_P = 6e-5;

    /** Ball Shooter PID Integral Term */
    double k_I = 1e-6;

    /** Ball Shooter PID Derivative Term */
    double k_D = 0.0;

    /** Ball shooter PID IZone Term */
    double k_Iz = 0.0;

    /** Ball Shooter PID Feed forward gain Ball Shooter PID */
    double k_FF = 0.000015;

    /** The maximum output of the ball shooter controller */
    double k_MaxOutput = 1.0;

    /** The minimum output of the ball shooter controller */
    double k_MinOutput = -1.0;

    /** The maximum RPM of the NEO */
    const double NEO_MaxRPM = 5700.0;

}; // end class SubSysBallShooter

#endif // #ifndef SUBSYSBALLSHOOTER_H
