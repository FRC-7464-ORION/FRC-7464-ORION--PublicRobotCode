/** ===========================================================================
 * @file   commands/PIDPssh/CmdTravel.cpp
 * @brief  This file defines the CmdTravel class.
 *
 * The CmdTravel class is used to set the power cell mover Pssh in travel
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

// Include the header file for the CmdTravel class
#include "commands/PIDPssh/CmdTravel.h"

/************************** Library Header Files ******************************/

/************************ Member function definitions *************************/

// The constructor for the CmdTravel class
CmdTravel::CmdTravel(PIDSubSysPssh* subsystem) 
  : m_PIDsubSysPssh(subsystem) {

  // Set the name of the command
  SetName("CmdTravel");

  // Use AddRequirements() here to declare subsystem dependencies

  // Require the use of the PID Pssh subsystem
  AddRequirements({subsystem});

} // end CmdTurnWoFCW::CmdTurnWoFCW(SubSysPATTurner* subsystem)...

// The destructor for the CmdTravel class
CmdTravel::~CmdTravel() {

} // end CmdTravel::~CmdTravel()

// Called just before this Command runs the first time
void CmdTravel::Initialize() {

  // Reset the PID controller for Pssh
  m_PIDsubSysPssh->ResetPIDController();

  // Indicate we are in travel mode
  m_PIDsubSysPssh->SetPsshState(k_PsshTravelString);

  // Set the set point for travel mode
  m_PIDsubSysPssh->SetSetpoint(k_PsshTravelSetpoint);

  // Indicate that this command is interruptable
//  SetInterruptible(k_CmdIsInterruptable);

#if PSSH_DEBUG
    frc::DriverStation::ReportWarning("Pssh in travel mode!");
#endif // #if PSSH_DEBUG

} // end CmdTravel::Initialize()

// Called repeatedly when this Command is scheduled to run
void CmdTravel::Execute() {

  // Tell Pssh to go to travel mode
  m_PIDsubSysPssh->Travel();

}  // end CmdTravel::Execute()

// Make this return true when this Command no longer needs to run execute()
bool CmdTravel::IsFinished() {

  // Boolean to see if we are finished
  bool at_travel_position;

  // Boolean to see if we have timed out
//  bool cmd_timed_out;

  // See if we are on target
  at_travel_position = 
    m_PIDsubSysPssh->GetController().AtSetpoint();

  // See if we have timed out
//  cmd_timed_out = IsTimedOut();

  // If we are on target...
  if(at_travel_position)
    // Set the state to travel
    m_PIDsubSysPssh->SetPsshState(k_PsshTravelString);

  // If we have timed out
//  if(cmd_timed_out)
    // Set the state to timed out
//    m_PIDsubSysPssh->SetPsshState(k_PsshTimedOutString);

  // Return true if we have made our target or timed out
//  return at_travel_position || cmd_timed_out;

  // Return true if we have made our target
  return at_travel_position;

} // end CmdTravel::IsFinished()

// Called once after isFinished returns true
void CmdTravel::End(bool interrupted) {

  // Stop Pssh
  m_PIDsubSysPssh->Stop();

  // Disable the PID controller
  m_PIDsubSysPssh->Disable();

} // end CmdTravel::End()
