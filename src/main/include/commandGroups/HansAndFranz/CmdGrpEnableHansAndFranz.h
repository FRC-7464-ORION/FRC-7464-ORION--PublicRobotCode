/** ===========================================================================
 * @file   CmdGrpEnableHansAndFranz.h
 * @brief  This file declares the CmdGrpEnableHansAndFranz class.
 *
 * The CmdGrpEnableHansAndFranz class is used to allow the robot to enable  
 * the lifting mechanism of the robot, which consists of a pulley system
 * to move the lifting arms, and a pneumatics system (muscles) that lifts the
 * weight of the robot.
 * 
 * COPYRIGHT NOTICES:
 *
 * Some portions:
 *
 * Copyright (c) 2017-2019 FIRST. All Rights Reserved.
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

// Include the header for the Hans/Franz arms subsystem
#include "subsystems/SubSysHansFranzArms.h"

// Include the header for the Hans/Franz muscles subsystem
#include "subsystems/SubSysHansFranzMuscles.h"

// Include the header file for the CmdEnableHansAndFranzArms class
#include "commands/HansAndFranzArms/CmdEnableHansFranzArms.h"

// Include the header file for the CmdMoveHansFranzArms class
#include "commands/HansAndFranzArms/CmdMoveHansFranzArms.h"

// Include the header file for the CmdEnableHansAndFranzMuscles class
#include "commands/HansAndFranzMuscles/CmdEnableHansFranzMuscles.h"

/************************** Library Header Files ******************************/

// Include the header file for the NEW(2020) Command helper class
#include <frc2/command/CommandHelper.h>

// Include the header file for the NEW(2020) parallel command group class
#include <frc2/command/ParallelCommandGroup.h>

/** ****************************************************************************
 * @class   CmdGrpEnableHansAndFranz
 * @brief   This is a class that defines a group of commands that is used to
 *            enable Hans and Franz arms and muscles.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class CmdGrpEnableHansAndFranz 
  : public frc2::CommandHelper<frc2::ParallelCommandGroup, 
                               CmdGrpEnableHansAndFranz> {

  public:

    /********************** PUBLIC MEMBER FUNCTIONS ***************************/

    /** 
     * The CmdGrpEnableHansAndFranz class constructor.
     *
     * @param arms    The Hans/Franz arms subsystem
     * @param command The Hans/Frans command to move the arms
     * @param muscles The Hans/Franz muscles subsystem
     */
    CmdGrpEnableHansAndFranz(SubSysHansFranzArms* arms,
                             CmdMoveHansFranzArms* command,
                             SubSysHansFranzMuscles* muscles);

  // NOTE: FOR SOME REASON CANNOT CREATE A DESTRUCTOR

}; // end class CmdGrpEnableHansAndFranz

#endif // #ifndef CMDGRPENABLEHANSANDFRANZ_H
