/** ===========================================================================
 * @file   commands/PIDPssh/CmdLoad.cpp
 * @brief  This file defines the CmdLoad class.
 *
 * The CmdLoad class is used to set the power cell mover Pssh in load
 * position.
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

// Include the header file for the CmdLoad class
#include "commands/PIDPssh/CmdLoad.h"

/************************** Library Header Files ******************************/

/************************ Member function definitions *************************/

// The constructor for the CmdLoad class
CmdLoad::CmdLoad(PIDSubSysPssh* subsystem) 
  : m_PIDsubSysPssh(subsystem) {

  // Set the name of the command
  SetName("CmdLoad");

  // Use AddRequirements() here to declare subsystem dependencies

  // Require the use of the PID Pssh subsystem
  AddRequirements({subsystem});

} // end CmdLoad::CmdLoad(PIDSubSysPssh* subsystem)

// The destructor for the CmdLoad class
CmdLoad::~CmdLoad() {

} // end CmdLoad::~CmdLoad()

// Called just before this Command runs the first time
void CmdLoad::Initialize() {

  // Reset the PID controller for Pssh
  m_PIDsubSysPssh->ResetPIDController();

  // Indicate we are in load mode
  m_PIDsubSysPssh->SetPsshState(k_PsshLoadString);

  // Set the set point for load mode
  m_PIDsubSysPssh->SetSetpoint(k_PsshLoadSetpoint);

  // Indicate that this command is interruptable
//  SetInterruptible(k_CmdIsInterruptable);

#if PSSH_DEBUG
    frc::DriverStation::ReportWarning("Pssh in load mode!");
#endif // #if PSSH_DEBUG

} // end CmdLoad::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdLoad::Execute() {

  // Tell Pssh to go to dump mode
  m_PIDsubSysPssh->Dump();

}  // end CmdLoad::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdLoad::IsFinished() {

  // We'll always return false, as gravity and/or the spring 
  // will constantly change our position
  return false;

} // end CmdLoad::IsFinished()

// Called once after isFinished returns true, OR command 
//   is interrupted or canceled
void CmdLoad::End(bool interrupted) {

  // Stop Pssh
  m_PIDsubSysPssh->Stop();

} // end CmdLoad::End()
