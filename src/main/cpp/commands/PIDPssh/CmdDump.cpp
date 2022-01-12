/** ===========================================================================
 * @file   commands/PIDPssh/CmdDump.cpp
 * @brief  This file defines the CmdDump class.
 *
 * The CmdDump class is used to set the power cell mover Pssh in dump
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
 * Copyright (c) 2020 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// Include the header file for the CmdDump class
#include "commands/PIDPssh/CmdDump.h"

/************************** Library Header Files ******************************/

/************************ Member function definitions *************************/

// The constructor for the CmdDump class
CmdDump::CmdDump(PIDSubSysPssh* subsystem) 
  : m_PIDsubSysPssh(subsystem) {

  // Set the name of the command
  SetName("CmdDump");

  // Use AddRequirements() here to declare subsystem dependencies

  // Require the use of the PID Pssh subsystem
  AddRequirements({subsystem});

} // end CmdDump::CmdDump(PIDSubSysPssh* subsystem)

// The destructor for the CmdDump class
CmdDump::~CmdDump() {

} // end CmdDump::~CmdDump()

// Called just before this Command runs the first time
void CmdDump::Initialize() {

  // Reset the PID controller for Pssh
  m_PIDsubSysPssh->ResetPIDController();

  // Indicate we are in dump mode
  m_PIDsubSysPssh->SetPsshState(k_PsshDumpString);

  // Set the set point for dump mode
  m_PIDsubSysPssh->SetSetpoint(k_PsshDumpSetpoint);

  // Indicate that this command is interruptable
//  SetInterruptible(k_CmdIsInterruptable);

#if PSSH_DEBUG
    frc::DriverStation::ReportWarning("Pssh in dump mode!");
#endif // #if PSSH_DEBUG

} // end CmdDump::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdDump::Execute() {

  // Tell Pssh to go to dump mode
  m_PIDsubSysPssh->Dump();

}  // end CmdDump::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdDump::IsFinished() {

  // We'll always return false, as gravity and/or the spring 
  // will constantly change our position
  return false;

} // end CmdDump::IsFinished()

// Called once after isFinished returns true, OR command 
//   is interrupted or canceled
void CmdDump::End(bool interrupted) {

  // Stop Pssh
  m_PIDsubSysPssh->Stop();

} // end CmdDump::End()
