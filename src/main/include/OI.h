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
 * Copyright (c) 2019-2020 FRC Team #7464 - ORION. All Rights Reserved.
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

// Include the Robot constants
#include "RobotConstants.h"

// Include the Logitech F310 HID header file
#include "HIDs/LogitechF310.h"

/************************** Library Header Files ******************************/

// For the joystick
#include <frc/Joystick.h>

// For the joystick buttons
#include <frc/buttons/JoystickButton.h>

// For the joystick POV buttons
#include <frc/buttons/POVButton.h>

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
     * Gets a pointer to the primary joystick.
     *
     * @return A pointer to the primary joystick 
    */
    frc::Joystick* getJoystick();

    /**
     * Gets a pointer to the secondary joystick.
     *
     * @return A pointer to the secondary joystick 
    */
    frc::Joystick* getSecondaryJoystick();

    private:

      /******************* Private member variables *********************/

      /** A pointer to a Logitech F310 joystick */
      frc::Joystick* m_PrimaryJoystick;

      /** A pointer to another Logitech F310 joystick */
      frc::Joystick* m_SecondaryJoystick;

      /** A joystick button to select arcade drive */
//      frc::JoystickButton* m_buttonSelectArcadeDrive;

      /** A joystick button to select tank drive */
//      frc::JoystickButton* m_buttonSelectTankDrive;

      /** A joystick button to enable turbo mode for the drive train */
      frc::JoystickButton* m_buttonTurboModeDriveTrain;

      /** A joystick button to toggle between smoothing mode on or off */
      frc::JoystickButton* m_buttonToggleDriveTrainSmoothingMode;

      /** A joystick button to toggle the drive direction (front/back) */
      frc::JoystickButton* m_buttonToggleDriveDirection;

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

      /** A joystick button to dump power cells and then return to travel */
      frc::JoystickButton* m_buttonPsshDump;

      /** A joystick button to load power cells and then return to travel */
      frc::JoystickButton* m_buttonPsshLoad;

#endif // #if USE_PID_PSSH

      /** A joystick button to safely select turning WoF CW */
      frc::JoystickButton* m_buttonTurnWoFCWSafety;

      /** A joystick button to safely select turning WoF CCW */
      frc::JoystickButton* m_buttonTurnWoFCCWSafety;

      /** A joystick button to disable Hans and Franz muscles */
      frc::JoystickButton* m_buttonDisableHansFranzMuscles;

      /** A joystick button to enable Hans and Franz */
      frc::JoystickButton* m_buttonEnableHansFranz;

      /** A POV button to extend Hans and Franz muscles */
      frc::POVButton* m_buttonExtendHansFranzMuscles;

      /** A POV button to retract Hans and Franz muscles */
      frc::POVButton* m_buttonRetractHansFranzMuscles;

}; // end class OI

#endif // #ifndef OI_H
