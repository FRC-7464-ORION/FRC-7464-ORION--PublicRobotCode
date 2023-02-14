/** ===========================================================================
 * @file   CmdGrpAutoDefLeft.h
 * @brief  This file declares the CmdGrpAutoDefLeft class.
 *
 * The CmdGrpAutoDefLeft class is used to allow the robot to be controlled 
 * autonomously using a set of commands.
 *
 * This command group is for a defensive strategy, starting in the left
 * field position, in the autonomous period.
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
 * Copyright (c) 2020-2022 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

// INCLUDE GUARD - see https://en.wikipedia.org/wiki/Include_guard
// If we have not already defined CMDGRPAUTODEFLEFT_H...
#ifndef CMDGRPAUTODEFLEFT_H
// Define CMDGRPAUTODEFLEFT_H
#define CMDGRPAUTODEFLEFT_H

/*************************** Local Header Files *******************************/

// Include the header file for the drive train subsystem
#include "subsystems/SubSysDriveTrain.h"

// The header for the NavX MXP AHRS
#include "AHRS.h"

// Include the header file for the ball shooter subsystem
#include "subsystems/SubSysBallShooter.h"

/************************** Library Header Files ******************************/

// Include the header file for the NEW(2020) Command helper class
#include <frc2/command/CommandHelper.h>

// Include the header file for the NEW(2020) sequential command group class
#include <frc2/command/SequentialCommandGroup.h>

/** ****************************************************************************
 * @class   CmdGrpAutoDefLeft
 * @brief   This is a class that defines a group of commands that is used to
 *            control the robot autonomously, running defense from the left
 *            position.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/

class CmdGrpAutoDefLeft 
  : public frc2::CommandHelper<frc2::SequentialCommandGroup, 
                               CmdGrpAutoDefLeft> {

  public:

    /********************** PUBLIC MEMBER FUNCTIONS ***************************/

    /** 
     * The CmdGrpAutoDefLeft class constructor.
     *
     * @param drivetrain    The drivetrain subsystem
     * @param ahrs          The AHRS
     * @param ballshooter   The ball shooter subsystem
     */
    CmdGrpAutoDefLeft(
      SubSysDriveTrain* drivetrain,
      AHRS* ahrs,
      SubSysBallShooter* ballshooter);

  // NOTE: FOR SOME REASON CANNOT CREATE A DESTRUCTOR

}; // end class CmdGrpAutoDefLeft

#endif // #ifndef CMDGRPAUTODEFLEFT_H
