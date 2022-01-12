/** ===========================================================================
 * @file   SubSysHansFranzArms.h
 * @brief  This file declares the SubSysHansFranzArms class, which is a
 *         subsystem of the robot.
 *
 * The SubSysHansFranzArms class is used to raise and lower our lifting arms.
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

// INCLUDE GUARD - see https://en.wikipedia.org/wiki/Include_guard
// If we have not already defined SUBSYSHANSFRANZARMS_H...
#ifndef SUBSYSHANSFRANZARMS_H
// Define SUBSYSHANSFRANZARMS_H
#define SUBSYSHANSFRANZARMS_H

/*************************** Local Header Files *******************************/

// Include the robot constants header
#include "RobotConstants.h"

/************************** Library Header Files ******************************/

// Include the subsystem class header file
#include <frc/commands/Subsystem.h>

// Include the PWMVictorSPX header file, for the motor controllers
#include <frc/PWMVictorSPX.h>

// Include the digital input header, which is used for the limit switches
#include <frc/DigitalInput.h>

// Include the header for a counter, which we will use to monitor the switches
#include <frc/Counter.h>

// Include the DriverStation, for errors and warnings
#include <frc/DriverStation.h>

/** ****************************************************************************
 * @class   SubSysHansFranzArms
 * @brief   This class declares the arms for the lifting mechanism subsystem.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class SubSysHansFranzArms : public frc::Subsystem {

  public:

    /** An enumeration of states that Hans/Franz arms can have */ 
    enum HansFranzArmsStates
    {
      /** We don't know what state it is in */
      UNKNOWN,
      /** Something wrong has happened */
      FAULT,
      /** We have been fully extended, and starting to retract */
      START_RETRACTING,
      /** We have been fully retracted, and starting to extend */
      START_EXTENDING,
      /** Retracting (moving down) */
      RETRACTING,
      /** Extending (moving up) */ 
      EXTENDING,
      /** Fully retracted (in the down position) */
      RETRACTED,
      /** Fully extended (in the up position) */
      EXTENDED
    };

    /** An enumeration of motor speed types */
    enum MotorSpeedDirTypes
    {
      /** The motor speed is negative */
      NEGATIVE,
      /** The motor speed is zero */
      ZERO,
      /** The motor speed is positive */
      POSITIVE
    };

    /** The default constructor for the SubSysHansFranzArms class */
    SubSysHansFranzArms();

    /** The default destructor for the SubSysHansFranzArms class */
    ~SubSysHansFranzArms();

    /**
     * Initialize the default command for this subsystem.
     *
     * This is meant to be the place to call SetDefaultCommand in a subsystem
     * and will be called on all the subsystems by the CommandBase method 
     * before the program starts running by using the list of all registered
     * Subsystems inside the Scheduler.
    */
    void InitDefaultCommand() override;

    /** The periodic method for PATTurner */
    void Periodic() override;

    /**
     * The method for having Hans and Franz move their arms.
     *
     * @param speed The motor speed, presumbably from some
     *                thumbstick, trigger, etc.
    */
    void MoveHansFranzArms(double speed);

    /**
     * Method to get Hans and Franz arms' null zone.
     *
     * @return Hans and Franz arms' null zone value
    */
    double GetHansFranzArmsNullZone();

    /**
     * Method to get Hans and Franz arms' speed limit.
     *
     * @return Hans and Franz arms' speed limit
    */
    double GetHansFranzArmsLimit();

    /**
     * Method to get Hans and Franz arms' exponent for the curve.
     *
     * @return Hans and Franz arms' exponent for the curve
    */
    double GetHansFranzArmsExponent();

    /** Method to enable Hans and Franz arms */
    void EnableHansFranzArms();

    /** 
     * Method to get if Hans and Franz arms are enabled
     * 
     * @return true  = H/F Arms Enabled, 
     *         false = NOT enabled 
    */
    bool AreHansFranzArmsEnabled();

    /** 
     * Method to get Hans and Franz arms state for the SmartDashboard
     * 
     * @return String indicating H/F arms' state */
    std::string GetHansFranzArmsSmartDashboardState();

    /** 
     * Method to see if the arms are fully retracted
     * 
     * @return true  = H/F arms fully retracted (switch closed or counter +), 
     *         false = NOT fully retracted (switch open or counter = 0)
    */
    bool IsHansFranzArmsFullyRetracted();

    /** 
     * Method to see if the arms are fully extended
     *  
     * @return true  = H/F arms fully extended (switch closed or counter +), 
     *         false = NOT fully extended (switch open or counter = 0)
    */
    bool IsHansFranzArmsFullyExtended();

  private:
    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities

    /***************************** Private Members ****************************/

    /** A pointer to Hans and Franz arms' motor(speed) controller */
    std::shared_ptr<frc::PWMVictorSPX> m_HansFranzArmsController;

    /** A boolean to indicate that Hans and Franz arms are enabled */
    bool m_HansFranzArmsEnabled;

    /** A string to hold the state of Hans' and Franz's arms for 
     * the SmartDashboard */
    std::string m_HansFranzArmsSmartDashboardState;

    /** The state of Hans/Franz arms */
    HansFranzArmsStates m_HansFranzArmsState;

    /** Boolean to indicate positive (up) speeds are allowed */
    bool m_PositiveSpeedUpAllowed;

    /** Boolean to indicate negative (down) speeds are allowed */
    bool m_NegativeSpeedDownAllowed;

    /** The limit switch that is tripped when the arms are fully retracted */
    frc::DigitalInput* m_HansFranzArms_FullyRetracted_LimitSwitch;

    /** The limit switch that is tripped when the arms are fully extended */
    frc::DigitalInput* m_HansFranzArms_FullyExtended_LimitSwitch;

    /** The counter used in monitoring the fully retracted limit switch*/
    frc::Counter* m_HansFranzArms_FullyRetracted_Counter;

    /** The counter used in monitoring the fully extended limit switch*/
    frc::Counter* m_HansFranzArms_FullyExtended_Counter;

    /***************************** Private Methods ****************************/

    /** Method to reset the counter for Hans/Franz fully retracted */
    void ResetHansFranzArmsFullyRetractedCounter();

    /** Method to reset the counter for Hans/Franz fully extended */
    void ResetHansFranzArmsFullyExtendedCounter();

    /** 
     * Method to determine the current state of the arms based on inputs.
     * 
     * @return The state of Hans/Franz arms based on the paassed in inputs.
     * 
     * @param  speed                 The speed from the joystick
    */ 
    HansFranzArmsStates GetCurrentHansFranzArmsState(double speed);

    /** 
     * Method to set the allowed speeds based on the passed in state
     * 
     * @param  state   The current state of Hans and Franz arms
    */ 
    void SetAllowedSpeeds(HansFranzArmsStates state);

    /** 
     * Determine the direction of the arms motor, based on passed in
     * inputs.
     * 
     * @return The direction the motor is turning
     * 
     * @param speed The speed from the joystick
    */ 
    MotorSpeedDirTypes GetMotorSpeedDir(double speed);

}; // end class SubSysHansFranzArms

#endif // #ifndef SUBSYSHANSFRANZARMS_H
