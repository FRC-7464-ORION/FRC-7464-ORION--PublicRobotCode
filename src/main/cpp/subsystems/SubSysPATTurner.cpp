/** ===========================================================================
 * @file   SubSysPATTurner.cpp
 * @brief  This file defines the SubSysPATTurner class.
 *
 * The SubSysPATTurner class allows the robot to move (clockwise (CW) or 
 * counter-clockwise (CCW)) the Wheel of Fortune (WoF) in the trench.
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

// Include the header file for our SubSysPATTurner class
#include "subsystems/SubSysPATTurner.h"

// Include out robot map header file
#include "RobotMap.h"

/************************** Library Header Files ******************************/

// Include the motor safety header file
#include <frc/MotorSafety.h>

/************************ Member function definitions *************************/

// The SubSysPATTurner default constructor
SubSysPATTurner::SubSysPATTurner() : Subsystem("SubSysPATTurner") {

  // Create a new motor controller for the PAT turner motor and reset
  m_PATTurnerController.reset(
    new frc::PWMVictorSPX(k_PATTurnerMotorPWMPort));

#if ORION_DEBUG
  if(m_PATTurnerController == nullptr) {
    frc::DriverStation::ReportError("m_PATTurnerController NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_PATTurnerController initialized!");
  }
#endif

  // Set the motor safety timeout for PAT turner
  m_PATTurnerController->SetExpiration(k_PATTurnerSafetyTimeout);

} // end SubSysPATTurner::SubSysPATTurner()

// The SubSysPATTurner default destructor
SubSysPATTurner::~SubSysPATTurner() {

  // Delete the PAT turner controller
  std::default_delete<frc::PWMVictorSPX> m_PATTurnerController;

} // end SubSysPATTurner::~SubSysPATTurner()

// The initial default command
void SubSysPATTurner::InitDefaultCommand() {

  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());

} // end SubSysPATTurner::InitDefaultCommand()

// The periodic method for the SubSysPATTurner subsystem
void SubSysPATTurner::Periodic() {

  // Put code here to be run every loop

  // Feed the motor controller safety system
  m_PATTurnerController->Feed();


} // end SubSysPATTurner::Periodic()

// Put methods for controlling this subsystem
// here. Call these from Commands.
// The method for having the PAT turner turn the WoF 
void SubSysPATTurner::TurnWoF(double RawPATSpeed) {

  //PAT Speed that has been adjusted for control
  double AdjustedPATSpeed;

  //If the right trigger is between the null zone and the cutoff point...
  if (k_PATTurnerAbsNullZone < RawPATSpeed && 
      RawPATSpeed <= k_PATTurnerAbsCutoffPoint)
  {

    //Adjusts PAT's Speed to non-turbo speed
    AdjustedPATSpeed = k_PATTurnerAbsValMaxSpeedNoTurbo;

  //If the right trigger is between our cutoff point and our max input...
  } else if (k_PATTurnerAbsCutoffPoint < RawPATSpeed && 
             RawPATSpeed <= k_PATTurnerAbsMaxInput)
  {

    //Adjusts PAT's Speed to turbo speed
    AdjustedPATSpeed = k_PATTurnerAbsValMaxSpeedTurbo;

  // If the raw speed is more than our max input
  // (shouldn't happen, but just in case)
  } else if (RawPATSpeed > k_PATTurnerAbsMaxInput)
  {

    //Adjusts PAT's Speed to turbo speed
    AdjustedPATSpeed = k_PATTurnerAbsValMaxSpeedTurbo;

  // If the left trigger is between the negative null zone and
  //  the negative cutoff point...
  } else if (-k_PATTurnerAbsCutoffPoint <= RawPATSpeed && 
             RawPATSpeed < -k_PATTurnerAbsNullZone)
  {

    //Adjusts PAT's Speed to a negitive non turbo speed
    AdjustedPATSpeed = -k_PATTurnerAbsValMaxSpeedNoTurbo;

  // If the left trigger is between the negative cutoff point and 
  //   the negative max input
  } else if (-k_PATTurnerAbsMaxInput <= RawPATSpeed && 
             RawPATSpeed < -k_PATTurnerAbsCutoffPoint)
  {

    //Adhusts PAT's Speed to a negitive turbo speed
    AdjustedPATSpeed = -k_PATTurnerAbsValMaxSpeedTurbo;

  // If the raw speed is less than our max input
  // (shouldn't happen, but just in case)
  } else if (RawPATSpeed < -k_PATTurnerAbsMaxInput)
  {
    //Adhusts PAT's Speed to a negitive turbo speed
    AdjustedPATSpeed = -k_PATTurnerAbsValMaxSpeedTurbo;
  }
  else
  {

    // Just don't do anything
    AdjustedPATSpeed = k_MotorStopSpeed;
    
  }

  // Set the PAT turner motor to the adjusted speed
  m_PATTurnerController->Set(AdjustedPATSpeed);

} // end SubSysPATTurner::TurnWoF(double)

// Method to get PAT turner's null zone.
double SubSysPATTurner::GetPATTurnerNullZone() {

  // Return PAT turner's null zone
  return k_PATTurnerAbsNullZone;

} // end SubSysPATTurner::GetPATTurnerNullZone()

// Method to get PAT turner's speed limit.
double SubSysPATTurner::GetPATTurnerLimit() {

  // Return PAT turner's speed limit
  return k_PATTurnerAbsValMaxSpeedNoTurbo;

} // end SubSysPATTurner::GetPATTurnerLimit()

// Method to get PAT turner's exponent for the curve.
double SubSysPATTurner::GetPATTurnerExponent() {

  // Return PAT turner's exponent
  return k_PATTurnerExponent;

} // end SubSysPATTurner::GetPATTurnerExponent()
