/** ===========================================================================
 * @file   CmdGrpAutoDefCenter.cpp
 * @brief  This file defines the CmdGrpAutoDefCenter class.
 *
 * The CmdGrpAutoDefCenter class is used to allow the robot to be controlled 
 * autonomously using a set of commands.
 *
 * This command group is for a defensive strategy, starting in the center
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

/*************************** Local Header Files *******************************/

// Include the header file for the CmdGrpAutoDefCenter class
#include "commandGroups/Autonomous/CmdGrpAutoDefCenter.h"

// Include the header file for the CmdAutoDriveStraight class
#include "commands/DriveTrain/CmdAutoDriveStraight.h"

// Include the header file for the CmdWaitSeconds class
#include "commands/Generic/CmdWaitSeconds.h"

/************************** Library Header Files ******************************/

/************************ Member function definitions *************************/

// The default constructor for the CmdAutoDriveStraight class
CmdGrpAutoDefCenter::CmdGrpAutoDefCenter() {

  AddSequential(new CmdAutoDriveStraight(
    0.25,
    CmdAutoDriveStraight::SECONDS,
    CmdAutoDriveStraight::FORWARD,
    0.25    
  ));

  AddSequential(new CmdWaitSeconds(2.0));

  AddSequential(new CmdAutoDriveStraight(
    0.25,
    CmdAutoDriveStraight::SECONDS,
    CmdAutoDriveStraight::REVERSE,
    0.25    
  ));

  AddSequential(new CmdWaitSeconds(2.0));

} // end CmdGrpAutoDefCenter::CmdGrpAutoDefCenter()

// The destructor for the CmdGrpAutoDefCenter class
CmdGrpAutoDefCenter::~CmdGrpAutoDefCenter() {


} // end CmdGrpAutoDefCenter::~CmdGrpAutoDefCenter()
