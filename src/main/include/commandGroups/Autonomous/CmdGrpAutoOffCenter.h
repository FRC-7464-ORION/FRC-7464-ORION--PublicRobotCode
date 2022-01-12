/** ===========================================================================
 * @file   CmdGrpAutoOffCenter.h
 * @brief  This file declares the CmdGrpAutoOffCenter class.
 *
 * The CmdGrpAutoOffCenter class is used to allow the robot to be controlled 
 * autonomously using a set of commands.
 * 
 * This command group is for a offensive strategy, starting in the center
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
// If we have not already defined CMDGRPAUTOOFFCENTER_H...
#ifndef CMDGRPAUTOOFFCENTER_H
// Define CMDGRPAUTOOFFCENTER_H
#define CMDGRPAUTOOFFCENTER_H

/*************************** Local Header Files *******************************/

/************************** Library Header Files ******************************/

// Include the header file for the CommandGroup class
#include <frc/commands/CommandGroup.h>

/** ****************************************************************************
 * @class   CmdGrpAutoOffCenter
 * @brief   This is a class that defines a group of commands that is used to
 *            control the robot autonomously.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class CmdGrpAutoOffCenter : public frc::CommandGroup {

  public:

    /** The CmdGrpAutoOffCenter class default constructor. */
    CmdGrpAutoOffCenter();

    /** The CmdGrpAutoOffCenter class destructor. */
    ~CmdGrpAutoOffCenter();


}; // end class CmdGrpAutoOffCenter

#endif // #ifndef CMDGRPAUTOOFFCENTER_H
