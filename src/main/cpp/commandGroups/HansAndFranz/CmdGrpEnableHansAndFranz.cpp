/** ===========================================================================
 * @file   CmdGrpEnableHansAndFranz.cpp
 * @brief  This file defines the CmdGrpEnableHansAndFranz class.
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

/*************************** Local Header Files *******************************/

// Include the header file for the CmdGrpEnableHansAndFranz class
#include "commandGroups/HansAndFranz/CmdGrpEnableHansAndFranz.h"

/************************** Library Header Files ******************************/

/************************ Member function definitions *************************/

// The constructor for the CmdGrpEnableHansAndFranz class
CmdGrpEnableHansAndFranz::CmdGrpEnableHansAndFranz(
    SubSysHansFranzArms* arms,
    CmdMoveHansFranzArms* command,
    SubSysHansFranzMuscles* muscles
)
{
  // Set the command's name
  SetName("CmdGrpEnableHansAndFranz");

  // Add commands to the parallel command group
  // (See the class this class inherits from in the header for which type of 
  //  command group)  
  AddCommands(

    // Enable Hans and Franz arms (pulley)
    CmdEnableHansFranzArms(arms, command),

    // Enable Hans and Franz muscles (pneumatics)
    CmdEnableHansFranzMuscles(muscles)

  );

} // end CmdGrpEnableHansAndFranz::CmdGrpEnableHansAndFranz(...)
