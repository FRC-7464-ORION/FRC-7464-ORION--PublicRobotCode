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
 * Copyright (c) 2019 FRC Team #7464 - ORION. All Rights Reserved.
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
#include "commands/CmdDriveArcadeStyle.h"

// Include the header file for the drive tank style command
#include "commands/CmdDriveTankStyle.h"

// If we are not using the PID controller for Capt. Hook
#if !USE_PID_CAPT_HOOK

// Include the header file for Capt. Hook grabbing the hatch panel command
#include "commands/CmdGrabHatchPanel.h"

// Include the header file for Capt. Hook releasing the hatch panel command
#include "commands/CmdReleaseHatchPanel.h"

#endif // #if !USE_PID_CAPT_HOOK

// If we are using Capt. Hook with a PID controller...
#if USE_PID_CAPT_HOOK

// Include the header file for the grab hatch panel command
#include "commands/PIDCmdGrabHatchPanel.h"

// Include the header file for the release hatch panel command
#include "commands/PIDCmdReleaseHatchPanel.h"

#endif // #if USE_PID_CAPT_HOOK

/************************** Library Header Files ******************************/

// Provides access to many other library header files
#include <frc/WPILib.h>

// Include the SmartDashboard class header file, which allows us to transmit
//   robot data to the operator console
// See:
// https://wpilib.screenstepslive.com/s/currentCS/m/smartdashboard
#include "frc/smartdashboard/SmartDashboard.h"

/************************ Member function definitions *************************/

// The OI (operator interface) constructor
OI::OI() {

  // Process operator interface input here.

  // Create a new joystick instance
  m_joystick = new frc::Joystick(k_Joystic0DeviceNumber);

  //////////////////////////// Create Buttons ////////////////////////////////

  // Create a new button instance for selecting arcade drive
  m_buttonSelectArcadeDrive = new frc::JoystickButton(m_joystick, k_X_Button);

  // Create a new button instance for selecting tank drive
  m_buttonSelectTankDrive = new frc::JoystickButton(m_joystick, k_Y_Button);

// If we are not using the PID controller for Capt. Hook
#if !USE_PID_CAPT_HOOK

  // Create a new button instance for safely selecting grab hatch panel
  m_buttonGrabHatchPanelSafety = new frc::JoystickButton(m_joystick, k_leftRearButton);

  // Create a new button instance for safely selecting release hatch panel
  m_buttonReleaseHatchPanelSafety = new frc::JoystickButton(m_joystick, k_rightRearButton);

#endif // #if !USE_PID_CAPT_HOOK

// If we are using Capt. Hook with a PID controller...
#if USE_PID_CAPT_HOOK

  // Create a new button instance for releasing a hatch panel
  m_buttonReleaseHatchPanel = new frc::JoystickButton(m_joystick, k_A_Button);

  // Create a new button instance for grabbing a hatch panel
  m_buttonGrabHatchPanel = new frc::JoystickButton(m_joystick, k_B_Button);

#endif // #if USE_PID_CAPT_HOOK

  //////////////////// Associate commands with buttons //////////////////////

  // Associate driving arcade style with pressing the arcade drive button
  m_buttonSelectArcadeDrive->WhenPressed(new CmdDriveArcadeStyle());

  // Associate driving tank style with pressing the tank drive button
  m_buttonSelectTankDrive->WhenPressed(new CmdDriveTankStyle());

// If we are not using the PID controller for Capt. Hook
#if !USE_PID_CAPT_HOOK

  // Associate grabbing a hatch panel with pressing the grab hatch panel 
  //   safety button
  m_buttonGrabHatchPanelSafety->WhenPressed(new CmdGrabHatchPanel());

  // Associate releasing a hatch panel with pressing the release hatch panel
  //   safety button
  m_buttonReleaseHatchPanelSafety->WhenPressed(new CmdReleaseHatchPanel());

#endif // #if !USE_PID_CAPT_HOOK

// If we are using Capt. Hook with a PID controller...
#if USE_PID_CAPT_HOOK

  // Associate releasing a hatch panel with the release hatch panel button
  m_buttonReleaseHatchPanel->WhenPressed(new PIDCmdReleaseHatchPanel());

  // Associate grabbing a hatch panel with the grab hatch panel button
  m_buttonGrabHatchPanel->WhenPressed(new PIDCmdGrabHatchPanel());

#endif // #if USE_PID_CAPT_HOOK

    /////////////////////// SmartDashboard Buttons /////////////////////////////

} // end OI::OI()

// The OI (operator interface) destructor
OI::~OI() {

// If we are not using the PID controller for Capt. Hook
#if !USE_PID_CAPT_HOOK

  // Release the memory for the release hatch panel safety button
  delete m_buttonReleaseHatchPanelSafety;

  // Release the memory for the grab hatch panel safety button
  delete m_buttonGrabHatchPanelSafety;

#endif // #if !USE_PID_CAPT_HOOK

// If we are using Capt. Hook with a PID controller...
#if USE_PID_CAPT_HOOK

  // Release the memory for the release hatch panel button
  delete m_buttonReleaseHatchPanel;

  // Release the memory for the grab hatch panel button
  delete m_buttonGrabHatchPanel;

#endif // #if USE_PID_CAPT_HOOK

  // Release the memory for the select tank drive button
  delete m_buttonSelectTankDrive;

  // Release the memory for the select arcade drive button
  delete m_buttonSelectArcadeDrive;

  // Release the memory for the joystick
  delete m_joystick;

} // end OI::~OI()

// Returns a pointer to the Joystick
frc::Joystick* OI::getJoystick() {

   // Return the pointer to the joystick
   return m_joystick;

} // end frc::Joystick* OI::getJoystick0()
