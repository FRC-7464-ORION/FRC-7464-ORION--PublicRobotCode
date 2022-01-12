/** ===========================================================================
 * @file   OI.cpp
 * @brief  This file defines the OI (operator interface) class.
 *
 * The OI class is used to process input from the operator.
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

// Include the OI (operator interface) class header file
#include "OI.h"

// Include out robot map header file
#include "RobotMap.h"

// Include the header file for the drive arcade style command
#include "commands/DriveTrain/CmdDriveArcadeStyle.h"

// Include the header file for the drive tank style command
#include "commands/DriveTrain/CmdDriveTankStyle.h"

// Include the header file for the enable turbo mode command
#include "commands/DriveTrain/CmdEnableTurboMode.h"

// Include the header file for the disable turbo mode command
#include "commands/DriveTrain/CmdDisableTurboMode.h"

// Include the header file for the toggle smoothing mode command
#include "commands/DriveTrain/CmdToggleSmoothingMode.h"

// Include the header file for the toggle drive direction
#include "commands/DriveTrain/CmdToggleDriveDirection.h"

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

// Include the header file for the Pssh travel command
#include "commands/PIDPssh/CmdTravel.h"

// Include the header file for the Pssh dump command
#include "commands/PIDPssh/CmdDump.h"

// Include the header file for the Pssh load command
#include "commands/PIDPssh/CmdLoad.h"

#endif // #if USE_PID_PSSH

// Include the header file for PAT Turner turning WoF CW
#include "commands/PAT/CmdTurnWoFCW.h"

// Include the header file for PAT Turner turning WoF CCW
#include "commands/PAT/CmdTurnWoFCCW.h"

// Include the header file for disabling Hans and Franz muscles
#include "commands/HansAndFranzMuscles/CmdDisableHansFranzMuscles.h"

// Include the header file for extending Hans and Franz muscles
#include "commands/HansAndFranzMuscles/CmdExtendHansFranzMuscles.h"

// Include the header file for retracting Hans and Franz muscles
#include "commands/HansAndFranzMuscles/CmdRetractHansFranzMuscles.h"

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

// Include the header file for the Pssh travel command
#include "commands/PIDPssh/CmdTravel.h"

// Include the header file for the Pssh dump command
#include "commands/PIDPssh/CmdDump.h"

// Include the header file for the Pssh load command
#include "commands/PIDPssh/CmdLoad.h"

#endif // #if USE_PID_PSSH

// Include the header file for the enable Hans/Franz command
#include "commandGroups/HansAndFranz/CmdGrpEnableHansAndFranz.h"

/************************** Library Header Files ******************************/

// Include the SmartDashboard class header file, which allows us to transmit
//   robot data to the operator console
// See:
// https://wpilib.screenstepslive.com/s/currentCS/m/smartdashboard
#include <frc/smartdashboard/SmartDashboard.h>

/************************ Member function definitions *************************/

// The OI (operator interface) constructor
OI::OI() {

  // Process operator interface input here.

  // Create a new joystick instance (this is a Logitech F310)
  m_PrimaryJoystick = new frc::Joystick(k_Joystick0DeviceNumber);

#if ORION_DEBUG
  if(m_PrimaryJoystick == nullptr) {
    frc::DriverStation::ReportError("m_PrimaryJoystick NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_PrimaryJoystick initialized!");
  }
#endif

  // Create a new joystick instance (this is also a Logitech F310)
  m_SecondaryJoystick = new frc::Joystick(k_Joystick1DeviceNumber);

#if ORION_DEBUG
  if(m_SecondaryJoystick == nullptr) {
    frc::DriverStation::ReportError("m_SecondaryJoystick NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_SecondaryJoystick initialized!");
  }
#endif

  //////////////////////////// Create Buttons ////////////////////////////////

  // Create a new button instance for selecting arcade drive
//  m_buttonSelectArcadeDrive = 
//    new frc::JoystickButton(m_joystick, k_F310_leftThumbstickButton);

  // Create a new button instance for selecting tank drive
//  m_buttonSelectTankDrive = 
//    new frc::JoystickButton(m_joystick, k_F310_rightThumbstickButton);

  // Create a new button instance for enabling turbo mode
  m_buttonTurboModeDriveTrain =
    new frc::JoystickButton(m_PrimaryJoystick, k_F310_A_Button);

#if ORION_DEBUG
  if(m_buttonTurboModeDriveTrain == nullptr) {
    frc::DriverStation::ReportError("m_buttonTurboModeDriveTrain NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_buttonTurboModeDriveTrain initialized!");
  }
#endif

  // Create a new button instance for toggling smoothing mode
  m_buttonToggleDriveTrainSmoothingMode =
    new frc::JoystickButton(m_PrimaryJoystick, k_F310_B_Button);

#if ORION_DEBUG
  if(m_buttonToggleDriveTrainSmoothingMode == nullptr) {
    frc::DriverStation::ReportError("m_buttonToggleDriveTrainSmoothingMode NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_buttonToggleDriveTrainSmoothingMode initialized!");
  }
#endif

  // Create a new button instance for toggling drive direction
  m_buttonToggleDriveDirection =
    new frc::JoystickButton(m_PrimaryJoystick, k_F310_StartButton);

#if ORION_DEBUG
  if(m_buttonToggleDriveDirection == nullptr) {
    frc::DriverStation::ReportError("m_buttonToggleDriveDirection NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_buttonToggleDriveDirection initialized!");
  }
#endif

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

  // Create a new button instance for loading power cells
  m_buttonPsshLoad =
    new frc::JoystickButton(m_SecondaryJoystick, k_F310_X_Button);

#if ORION_DEBUG
  if(m_buttonPsshLoad == nullptr) {
    frc::DriverStation::ReportError("m_buttonPsshLoad NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_buttonPsshLoad initialized!");
  }
#endif

  // Create a new button instance for dumping power cells
  m_buttonPsshDump =
    new frc::JoystickButton(m_SecondaryJoystick, k_F310_Y_Button);

#if ORION_DEBUG
  if(m_buttonPsshDump == nullptr) {
    frc::DriverStation::ReportError("m_buttonPsshDump NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_buttonPsshDump initialized!");
  }
#endif

#endif // #if USE_PID_PSSH

  // Create a new button instance for safely turning WoF clockwise
  m_buttonTurnWoFCWSafety =
     new frc::JoystickButton(m_SecondaryJoystick, k_F310_leftRearButton);

#if ORION_DEBUG
  if(m_buttonTurnWoFCWSafety == nullptr) {
    frc::DriverStation::ReportError("m_buttonTurnWoFCWSafety NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_buttonTurnWoFCWSafety initialized!");
  }
#endif

  // Create a new button instance for safely turning WoF counter-clockwise
  m_buttonTurnWoFCCWSafety =
     new frc::JoystickButton(m_SecondaryJoystick, k_F310_rightRearButton);

#if ORION_DEBUG
  if(m_buttonTurnWoFCCWSafety == nullptr) {
    frc::DriverStation::ReportError("m_buttonTurnWoFCCWSafety NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_buttonTurnWoFCCWSafety initialized!");
  }
#endif

  // Create a new button instance for disabling Hans and Franz muscles
  m_buttonDisableHansFranzMuscles =
     new frc::JoystickButton(m_SecondaryJoystick, k_F310_BackButton);

#if ORION_DEBUG
  if(m_buttonDisableHansFranzMuscles == nullptr) {
    frc::DriverStation::ReportError("m_buttonDisableHansFranzMuscles NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_buttonDisableHansFranzMuscles initialized!");
  }
#endif

  // Create a new button instance for enabling Hans and Franz
  m_buttonEnableHansFranz =
     new frc::JoystickButton(m_SecondaryJoystick, k_F310_rightThumbstickButton);

#if ORION_DEBUG
  if(m_buttonEnableHansFranz == nullptr) {
    frc::DriverStation::ReportError("m_buttonEnableHansFranz NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_buttonEnableHansFranz initialized!");
  }
#endif

  // Create a new POV button instance for extending Hans and Franz
  // NOTE: You have to dereference the pointer (the * in front of m_joystick),
  //       as POVButton expects a GenericHID& (reference), as opposed to 
  //       JoystickButton, which expects an pointer (address).
  m_buttonExtendHansFranzMuscles =
     new frc::POVButton(*m_SecondaryJoystick, k_F310_POV_North, k_F310_POV_ID);

#if ORION_DEBUG
  if(m_buttonExtendHansFranzMuscles == nullptr) {
    frc::DriverStation::ReportError("m_buttonExtendHansFranzMuscles NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_buttonExtendHansFranzMuscles initialized!");
  }
#endif

  // Create a new POV button instance for retracting Hans and Franz muscles
  // NOTE: You have to dereference the pointer (the * in front of m_joystick),
  //       as POVButton expects a GenericHID& (reference), as opposed to 
  //       JoystickButton, which expects an pointer (address).
  m_buttonRetractHansFranzMuscles =
     new frc::POVButton(*m_SecondaryJoystick, k_F310_POV_South, k_F310_POV_ID);

#if ORION_DEBUG
  if(m_buttonRetractHansFranzMuscles == nullptr) {
    frc::DriverStation::ReportError("m_buttonRetractHansFranzMuscles NOT initialized!");
  }
  else {
    frc::DriverStation::ReportWarning("m_buttonRetractHansFranzMuscles initialized!");
  }
#endif

  //////////////////// Associate commands with buttons //////////////////////

  // Associate driving arcade style with pressing the arcade drive button
//  m_buttonSelectArcadeDrive->WhenPressed(new CmdDriveArcadeStyle());

  // Associate driving tank style with pressing the tank drive button
//  m_buttonSelectTankDrive->WhenPressed(new CmdDriveTankStyle());

  // Associate enabling turbo mode with holding down the turbo speed button
  m_buttonTurboModeDriveTrain->WhenPressed(new CmdEnableTurboMode());

  // Associate disabling turbo mode with releasing the turbo speed button
  m_buttonTurboModeDriveTrain->WhenReleased(new CmdDisableTurboMode());

  // Associate enabling/disabling smoothing mode with pressing the
  //   smoothing mode button
  m_buttonToggleDriveTrainSmoothingMode->WhenPressed(
    new CmdToggleSmoothingMode());

  // Associate making normal or reversing drive direction with pressing the
  //   drive direction button
  m_buttonToggleDriveDirection->WhenPressed(
    new CmdToggleDriveDirection());

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

  // Associate loading power cells with the pressing of the load power cells
  //   button
  m_buttonPsshLoad->WhenPressed(new CmdLoad());

  // Associate the power cell transport going to travel mode with the 
  // releasing of the load power cells button
  m_buttonPsshLoad->WhenReleased(new CmdTravel());

  // Associate dumping power cells with the pressing of the dump power cells
  //   button
  m_buttonPsshDump->WhenPressed(new CmdDump());

  // Associate the power cell transport going to travel mode with the 
  // releasing of the dump power cells button
  m_buttonPsshDump->WhenReleased(new CmdTravel());

#endif // #if USE_PID_PSSH

  // Associate turning the WoF clockwise with hitting the Turn WoF CW safety 
  m_buttonTurnWoFCWSafety->WhenPressed(new CmdTurnWoFCW());

  // Associate turning the WoF counter clockwise with hitting the
  // Turn WoF CCW safety 
  m_buttonTurnWoFCCWSafety->WhenPressed(new CmdTurnWoFCCW());

  // Associate disabling Hans and Franz muscles with the hitting its button
  m_buttonDisableHansFranzMuscles->WhenPressed(new CmdDisableHansFranzMuscles());

  // Associate enabling Hans and Franz with the hitting its button
  m_buttonEnableHansFranz->WhenPressed(new CmdGrpEnableHansAndFranz());

  // Associate extending Hans and Franz with the hitting its button
  m_buttonExtendHansFranzMuscles->WhenPressed(new CmdExtendHansFranzMuscles());

  // Associate retracting Hans and Franz muscles with the hitting its button
  m_buttonRetractHansFranzMuscles->WhenPressed(new CmdRetractHansFranzMuscles());

  /////////////////////// SmartDashboard Buttons /////////////////////////////

} // end OI::OI()

// The OI (operator interface) destructor
OI::~OI() {

  // Release the memory for the retract Hans/Franz muscles button
  delete m_buttonRetractHansFranzMuscles;

  // Release the memory for the extend Hans/Franz muscles button
  delete m_buttonExtendHansFranzMuscles;

  // Release the memory for the enable Hans/Franz muscles button
  delete m_buttonEnableHansFranz;

  // Release the memory for the disable Hans/Franz muscles button
  delete m_buttonDisableHansFranzMuscles;

  // Release the memory for the turn WoF CCW safety button
  delete m_buttonTurnWoFCCWSafety;

  // Release the memory for the turn WoF CW safety button
  delete m_buttonTurnWoFCWSafety;

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

  // Release the memory for the power cell dump button
  delete m_buttonPsshDump;

  // Release the memory for the power cell load button
  delete m_buttonPsshLoad;

#endif // #if USE_PID_PSSH

  // Release the memory for the toggle drive direction button
  delete m_buttonToggleDriveDirection;
  
  // Release the memory for the toggle smoothing mode button
  delete m_buttonToggleDriveTrainSmoothingMode;

  // Release the memory for the enable turbo mode button
  delete m_buttonTurboModeDriveTrain;

  // Release the memory for the select tank drive button
//  delete m_buttonSelectTankDrive;

  // Release the memory for the select arcade drive button
//  delete m_buttonSelectArcadeDrive;

  // Release the memory for the joystick
  delete m_PrimaryJoystick;

} // end OI::~OI()

// Returns a pointer to the primary Joystick
frc::Joystick* OI::getJoystick() {

   // Return the pointer to the joystick
   return m_PrimaryJoystick;

} // end frc::Joystick* OI::getJoystick()

// Returns a pointer to the secondary joystick
frc::Joystick* OI::getSecondaryJoystick() {

   // Return the pointer to the joystick
   return m_SecondaryJoystick;

} // end frc::Joystick* OI::getSecondaryJoystick()
