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

// If we are using Tippy Toes...
#if USE_TIPPY_TOES

// Include the header file for Tippy Toes climbing forward command
#include "commands/CmdClimbForward.h"

// Include the header file for Tippy Toes climbing backward command
#include "commands/CmdClimbBackward.h"

#endif // #if USE_TIPPY_TOES

// Include the header file for the enable turbo mode command
#include "commands/CmdEnableTurboMode.h"

// Include the header file for the disable turbo mode command
#include "commands/CmdDisableTurboMode.h"

// Include the header file for the toggle smoothing mode command
#include "commands/CmdToggleSmoothingMode.h"

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

  // Create a new button instance for enabling turbo mode
  m_buttonTurboModeDriveTrain =
    new frc::JoystickButton(m_joystick, k_A_Button);

  // Create a new button instance for toggling smoothing mode
  m_buttonToggleDriveTrainSmoothingMode =
    new frc::JoystickButton(m_joystick, k_B_Button);

// If we are using Tippy Toes...
#if USE_TIPPY_TOES

  // Create a new button instance for climbing forward
  m_buttonClimbForward = new frc::JoystickButton(m_joystick, k_StartButton);

  // Create a new button instance for climbing backward
  m_buttonClimbBackward = new frc::JoystickButton(m_joystick, k_BackButton);

#endif // #if USE_TIPPY_TOES

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

  // Associate enabling turbo mode with holding down the turbo speed button
  m_buttonTurboModeDriveTrain->WhenPressed(new CmdEnableTurboMode());

  // Associate disabling turbo mode with releasing the turbo speed button
  m_buttonTurboModeDriveTrain->WhenReleased(new CmdDisableTurboMode());

  // Associate enabling/disabling smoothing mode with pressing the
  //   smoothing mode button
  m_buttonToggleDriveTrainSmoothingMode->WhenPressed(
    new CmdToggleSmoothingMode());

// If we are using Tippy Toes...
#if USE_TIPPY_TOES

  // Associate climbing forward with holding the climb forward button
  m_buttonClimbForward->WhileHeld(new CmdClimbForward());

  // Associate climbing backward with holding the climb backward button
  m_buttonClimbBackward->WhileHeld(new CmdClimbBackward());

#endif // #if USE_TIPPY_TOES

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

// If we are using Capt. Hook with a PID controller...
#if USE_PID_CAPT_HOOK

  // Release the memory for the grab hatch panel button
  delete m_buttonGrabHatchPanel;

  // Release the memory for the release hatch panel button
  delete m_buttonReleaseHatchPanel;

#endif // #if USE_PID_CAPT_HOOK

// If we are not using the PID controller for Capt. Hook
#if !USE_PID_CAPT_HOOK

  // Release the memory for the release hatch panel safety button
  delete m_buttonReleaseHatchPanelSafety;

  // Release the memory for the grab hatch panel safety button
  delete m_buttonGrabHatchPanelSafety;

#endif // #if !USE_PID_CAPT_HOOK

// If we are using Tippy Toes...
#if USE_TIPPY_TOES

  // Release the memory for the climb backward button
  delete m_buttonClimbBackward;

  // Release the memory for the climb forward button
  delete m_buttonClimbForward;

#endif // #if USE_TIPPY_TOES

  // Release the memory for the toggle smoothing mode button
  delete m_buttonToggleDriveTrainSmoothingMode;

  // Release the memory for the enable turbo mode button
  delete m_buttonTurboModeDriveTrain;

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
