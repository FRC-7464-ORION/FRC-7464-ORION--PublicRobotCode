/** ===========================================================================
 * @file   OI.h
 * @brief  This file declares the OI (operator interface) class.
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

// INCLUDE GUARD - see https://en.wikipedia.org/wiki/Include_guard
// If we have not already defined OI_H...
#ifndef OI_H
// Define OI_H
#define OI_H

/*************************** Local Header Files *******************************/

// Include the robot constants header file
#include "RobotConstants.h"

// Include the Logitech F310 HID header file
#include "HIDs/LogitechF310.h"

/************************** Library Header Files ******************************/

// Include the WPI library header file
#include "frc/WPILib.h"

/** ****************************************************************************
 * @class   OI
 * @brief   This is the class that defines the interface between the operator
 *            and the robot (Operator Interface = OI).
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class OI {

  public:

    /************************ Public Method Prototypes ************************/

    /** The OI (operator interface) class constructor. */
    OI();

    /** The OI (operator interface) class destructor */
    ~OI();

    /**
     * Gets a pointer to the joystick.
     *
     * @return A pointer to the Joystick 
    */
    frc::Joystick* getJoystick();

    private:

      /******************* Private member variables *********************/

      /** A pointer to a joystick */
      frc::Joystick* m_joystick;

      /** A joystick button to select arcade drive */
      frc::JoystickButton* m_buttonSelectArcadeDrive;

      /** A joystick button to select tank drive */
      frc::JoystickButton* m_buttonSelectTankDrive;

      /** A joystick button to enable turbo mode for the drive train */
      frc::JoystickButton* m_buttonTurboModeDriveTrain;

      /** A joystick button to toggle between smoothing mode on or off */
      frc::JoystickButton* m_buttonToggleDriveTrainSmoothingMode;

// If we are using Tippy Toes...
#if USE_TIPPY_TOES

      /** A joystick button to climb forward */
      frc::JoystickButton* m_buttonClimbForward;

      /** A joystick button to climb backward */
      frc::JoystickButton* m_buttonClimbBackward;

#endif // #if USE_TIPPY_TOES

// If we are not using the PID controller for Capt. Hook
#if !USE_PID_CAPT_HOOK

      /** A joystick button to safely select grabbing a hatch panel */
      frc::JoystickButton* m_buttonGrabHatchPanelSafety;

      /** A joystick button to safely select releasing a hatch panel */
      frc::JoystickButton* m_buttonReleaseHatchPanelSafety;

#endif // #if !USE_PID_CAPT_HOOK

// If we are using Capt. Hook with a PID controller...
#if USE_PID_CAPT_HOOK

      /** A joystick button to grab a hatch panel */
      frc::JoystickButton* m_buttonGrabHatchPanel;

      /** A joystick button to release a hatch panel */
      frc::JoystickButton* m_buttonReleaseHatchPanel;

#endif // #if USE_PID_CAPT_HOOK

}; // end class OI

#endif // #ifndef OI_H
