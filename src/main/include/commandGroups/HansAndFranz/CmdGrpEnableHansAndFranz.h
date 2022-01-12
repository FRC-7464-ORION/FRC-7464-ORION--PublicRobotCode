/** ===========================================================================
 * @file   CmdGrpEnableHansAndFranz.h
 * @brief  This file declares the CmdGrpEnableHansAndFranz class.
 *
 * The CmdGrpEnableHansAndFranz class is used to allow enable the Hans and
 * Franz muscles and arms.
 * 
 * This command group is the default for the autonomous period.
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
// If we have not already defined CMDGRPENABLEHANSANDFRANZ_H...
#ifndef CMDGRPENABLEHANSANDFRANZ_H
// Define CMDGRPENABLEHANSANDFRANZ_H
#define CMDGRPENABLEHANSANDFRANZ_H

/*************************** Local Header Files *******************************/

// Include the header file for the CmdEnableHansAndFranzArms class
#include "commands/HansAndFranzArms/CmdEnableHansFranzArms.h"

// Include the header file for the CmdEnableHansAndFranzMuscles class
#include "commands/HansAndFranzMuscles/CmdEnableHansFranzMuscles.h"

/************************** Library Header Files ******************************/

// Include the header file for the CommandGroup class
#include <frc/commands/CommandGroup.h>

/** ****************************************************************************
 * @class   CmdGrpEnableHansAndFranz
 * @brief   This is a class that defines a group of commands that is used to
 *            enable Hans and Franz arms and muscles.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class CmdGrpEnableHansAndFranz : public frc::CommandGroup {

  public:

    /** The CmdGrpEnableHansAndFranz class default constructor. */
    CmdGrpEnableHansAndFranz();

    /** The CmdGrpEnableHansAndFranz class destructor. */
    ~CmdGrpEnableHansAndFranz();


}; // end class CmdGrpEnableHansAndFranz

#endif // #ifndef CMDGRPENABLEHANSANDFRANZ_H
