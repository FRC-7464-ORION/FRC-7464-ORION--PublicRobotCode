/** ===========================================================================
 * @file   CmdGrpAutoOffRight.h
 * @brief  This file declares the CmdGrpAutoOffRight class.
 *
 * The CmdGrpAutoOffRight class is used to allow the robot to be controlled 
 * autonomously using a set of commands.
 *
 * This command group is for a offensive strategy, starting in the right
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
 * Copyright (c) 2020 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

// INCLUDE GUARD - see https://en.wikipedia.org/wiki/Include_guard
// If we have not already defined CMDGRPAUTOOFFRIGHT_H...
#ifndef CMDGRPAUTOOFFRIGHT_H
// Define CMDGRPAUTOOFFRIGHT_H
#define CMDGRPAUTOOFFRIGHT_H

/*************************** Local Header Files *******************************/

// Include the header file for the drive train subsystem
#include "subsystems/SubSysDriveTrain.h"

// The header for the NavX MXP AHRS
#include "AHRS.h"

/************************** Library Header Files ******************************/

// Include the header file for the NEW(2020) Command helper class
#include <frc2/command/CommandHelper.h>

// Include the header file for the NEW(2020) sequential command group class
#include <frc2/command/SequentialCommandGroup.h>

/** ****************************************************************************
 * @class   CmdGrpAutoOffRight
 * @brief   This is a class that defines a group of commands that is used to
 *            control the robot autonomously, running offense from the right
 *            position.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/

class CmdGrpAutoOffRight 
  : public frc2::CommandHelper<frc2::SequentialCommandGroup, 
                               CmdGrpAutoOffRight> {

  public:

    /********************** PUBLIC MEMBER FUNCTIONS ***************************/

    /** 
     * The CmdGrpAutoOffRight class constructor.
     *
     * @param drivetrain    The drivetrain subsystem
     * @param ahrs          The AHRS
     */
    CmdGrpAutoOffRight(
      SubSysDriveTrain* drivetrain,
      AHRS* ahrs);

  // NOTE: FOR SOME REASON CANNOT CREATE A DESTRUCTOR

}; // end class CmdGrpAutoOffRight

#endif // #ifndef CMDGRPAUTOOFFRIGHT_H
