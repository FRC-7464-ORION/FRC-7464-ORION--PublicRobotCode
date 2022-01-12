/** ===========================================================================
 * @file   RobotTick.cpp
 * @brief  This file defines the RobotTick class.
 *
 * The RobotTick class provides a means to keep track of "ticks" 
 * (such as a clock tick-tock, as opposed to the type that gets on 
 * your pet). Ticks are often incremented periodically, and read for 
 * certain events.
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

// The header for this class
#include "RobotTick.h"

/************************ Member function definitions *************************/

// The constructor for the robot tick
RobotTick::RobotTick() {

} // end RobotTick::RobotTick()

// The destructor for the RobotTick class
RobotTick::~RobotTick() {

} // end RobotTick::~RobotTick()

// Increment Robot Tick counter
void RobotTick::IncrementRobotTick() {

  // Increment the robot tick
  m_RobotTick++;

} // end RobotTick::IncrementRobotTick()

// Get the robot tick count
uint64_t RobotTick::GetRobotTick() {

  // Get the robot tick
  return m_RobotTick;

} // end RobotTick::GetRobotTick()
