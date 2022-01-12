/** ===========================================================================
 * @file   CmdGrpEnableHansAndFranz.cpp
 * @brief  This file defines the CmdGrpEnableHansAndFranz class.
 *
 * The CmdGrpEnableHansAndFranz class is used to allow the robot to be controlled 
 * autonomously using a set of commands.
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

/*************************** Local Header Files *******************************/

// Include the header file for the CmdGrpEnableHansAndFranz class
#include "commandGroups/HansAndFranz/CmdGrpEnableHansAndFranz.h"

/************************** Library Header Files ******************************/

/************************ Member function definitions *************************/

// The default constructor for the CmdGrpEnableHansAndFranz class
CmdGrpEnableHansAndFranz::CmdGrpEnableHansAndFranz() {

  // TODO: Should we use pointers to commands, intialize them with new,
  //       use the pointers in AddSequential, AddParallel, etc., then
  //       delete the instances using the pointers?
  //       See https://www.chiefdelphi.com/t/can-the-old-commandgroup-framework-cause-memory-leaks/375847

  // Enable both Hans and Franz arms and muscles
  AddParallel(new CmdEnableHansFranzArms());
  AddParallel(new CmdEnableHansFranzMuscles());
  
} // end CmdGrpEnableHansAndFranz::CmdGrpEnableHansAndFranz()

// The destructor for the CmdGrpEnableHansAndFranz class
CmdGrpEnableHansAndFranz::~CmdGrpEnableHansAndFranz() {


} // end CmdGrpEnableHansAndFranz::~CmdGrpEnableHansAndFranz()
