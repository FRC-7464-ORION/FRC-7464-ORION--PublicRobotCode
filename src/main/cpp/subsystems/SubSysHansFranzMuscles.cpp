/** ===========================================================================
 * @file   SubSysHansFranzMuscles.cpp
 * @brief  This file defines the SubSysHansFranzMuscles class.
 *
 * The SubSysHansFranzMuscles class is used to activate the shields by 
 * climbing onto the shield generator switch. This class controls the 
 * pneumatics.
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

// Include the header file for our SubSysHansFranzMuscles class
#include "subsystems/SubSysHansFranzMuscles.h"

// Include out robot map header file
#include "RobotMap.h"

/************************** Library Header Files ******************************/


/************************ Member function definitions *************************/

// SubSysHansFranzMuscles default constructor
SubSysHansFranzMuscles::SubSysHansFranzMuscles() : Subsystem("SubSysHansFranzMuscles") {

  // Create a new compressor instance
  m_compressor = new frc::Compressor(k_PrimaryPCM_CAN_Bus_DeviceID);

#if ORION_DEBUG
  if(m_compressor == nullptr) {
    frc::DriverStation::ReportError("m_compressor NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_compressor initialized!");
  }
#endif

  // Set the closed loop control for the compressor to be automatically
  // controlled
  m_compressor->SetClosedLoopControl(k_CompressorAutomaticallyControlled);

  // Create a double solenoid instance for Hans (left)
  m_Hans_DoubleSolenoid = new frc::DoubleSolenoid(
    k_PrimaryPCM_CAN_Bus_DeviceID,
    k_HansExtendMuscleChannel,
    k_HansRetractMuscleChannel
  );

#if ORION_DEBUG
  if(m_Hans_DoubleSolenoid == nullptr) {
    frc::DriverStation::ReportError("m_Hans_DoubleSolenoid NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_Hans_DoubleSolenoid initialized!");
  }
#endif

  // Create a double solenoid instance for Franz (right)
  m_Franz_DoubleSolenoid = new frc::DoubleSolenoid(
    k_PrimaryPCM_CAN_Bus_DeviceID,
    k_FranzExtendMuscleChannel,
    k_FranzRetractMuscleChannel
  );

#if ORION_DEBUG
  if(m_Franz_DoubleSolenoid == nullptr) {
    frc::DriverStation::ReportError("m_Franz_DoubleSolenoid NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_Franz_DoubleSolenoid initialized!");
  }
#endif

  // Set Hans and Franz muscles disabled, initially
  m_HansFranzMusclesEnabled = false;

  // Set Hans' double solenoid to off
  m_Hans_DoubleSolenoid->Set(frc::DoubleSolenoid::Value::kOff);

  // Set Franz's double solenoid to off
  m_Franz_DoubleSolenoid->Set(frc::DoubleSolenoid::Value::kOff);

  // Indicate we are initially diabled
  m_HansFranzMusclesState = k_HansFranzMusclesStateDisabled;

} // end SubSysHansFranzMuscles::SubSysHansFranzMuscles()

// The SubSysHansFranzMuscles default destructor
SubSysHansFranzMuscles::~SubSysHansFranzMuscles() {

  // Delete the double solenoid instance for Franz
  delete m_Franz_DoubleSolenoid;

  // Delete the double solenoid instance for Hans
  delete m_Hans_DoubleSolenoid;

  // Delete the compressor instance
  delete m_compressor;

} // end SubSysHansFranzMuscles::~SubSysHansFranzMuscles()

// The initial default command
void SubSysHansFranzMuscles::InitDefaultCommand() {

  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());

} // end SubSysHansFranzMuscles::InitDefaultCommand()

// The periodic method for the SubSysHansFranzMuscles subsystem
void SubSysHansFranzMuscles::Periodic() {

  // Put code here to be run every loop

} // SubSysHansFranzMuscles::Periodic()

// Put methods for controlling this subsystem
// here. Call these from Commands.

// Method to disable Hans and Franz muscles
void SubSysHansFranzMuscles::DisableHansFranzMuscles()
{

  // If Hans and Franz muscles are enabled...
  if(m_HansFranzMusclesEnabled)
  {

    // Set Hans' double solenoid to off
    m_Hans_DoubleSolenoid->Set(frc::DoubleSolenoid::Value::kOff);

    // Set Franz's double solenoid to off
    m_Franz_DoubleSolenoid->Set(frc::DoubleSolenoid::Value::kOff);

    // Set muscles state to disabled
    m_HansFranzMusclesState = k_HansFranzMusclesStateDisabled;

  } // end if(m_HansFranzMusclesEnabled)

} // end SubSysHansFranzMuscles::DisableHansFranzMuscles()

// Method to extend Hans and Franz muscles
void SubSysHansFranzMuscles::ExtendHansFranzMuscles()
{

  // If Hans and Franz muscles are enabled...
  if(m_HansFranzMusclesEnabled)
  {

    // Set Hans' double solenoid to forward (extend)
    m_Hans_DoubleSolenoid->Set(frc::DoubleSolenoid::Value::kForward);

    // Set Franz's double solenoid to forward (extend)
    m_Franz_DoubleSolenoid->Set(frc::DoubleSolenoid::Value::kForward);

    // Set muscles state to extended
    m_HansFranzMusclesState = k_HansFranzMusclesStateExtended;

  } // end if(m_HansFranzMusclesEnabled)

} // end SubSysHansFranzMuscles::ExtendHansFranzMuscles()

// Method to retract Hans and Franz muscles
void SubSysHansFranzMuscles::RetractHansFranzMuscles()
{

  // If Hans and Franz muscles are enabled...
  if(m_HansFranzMusclesEnabled)
  {

    // Set Hans' double solenoid to reverse (which retracts)
    m_Hans_DoubleSolenoid->Set(frc::DoubleSolenoid::Value::kReverse);

    // Set Franz's double solenoid to reverse (which retracts)
    m_Franz_DoubleSolenoid->Set(frc::DoubleSolenoid::Value::kReverse);

    // Set muscles state to retracted
    m_HansFranzMusclesState = k_HansFranzMusclesStateRetracted;

  } // end if(m_HansFranzMusclesEnabled)

} // end SubSysHansFranzMuscles::RetractHansFranzMuscles()

// Method to enable Hans and Franz muscles
void SubSysHansFranzMuscles::EnableHansFranzMuscles()
{

    // Enable Hans and Franz muscles
    m_HansFranzMusclesEnabled = true;

} // end SubSysHansFranzMuscles::EnableHansFranzMuscles()

// Method to get if Hans and Franz muscles are enabled
bool SubSysHansFranzMuscles::AreHansFranzMusclesEnabled()
{

  // Return if Hans and Franz muscles are enabled
  return m_HansFranzMusclesEnabled;

} // end SubSysHansFranzMuscles::AreHansFranzMusclesEnabled()

// Method to get Hans and Franz muscles state
std::string SubSysHansFranzMuscles::GetHansFranzMusclesState()
{

  // return the state of Hans and Franz muscles
  return m_HansFranzMusclesState;

} // end SubSysHansFranzMuscles::GetHansFranzMusclesState()
