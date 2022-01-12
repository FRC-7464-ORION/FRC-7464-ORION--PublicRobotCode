/** ===========================================================================
 * @file   RobotTick.h
 * @brief  This file declares the RobotTick class.
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

// INCLUDE GUARD - see https://en.wikipedia.org/wiki/Include_guard
// If we have not already defined ROBOTTICK_H...
#ifndef ROBOTTICK_H
// Define ROBOTTICK_H
#define ROBOTTICK_H

/*************************** Local Header Files *******************************/

// The header that defines the hardware configuration of the robot
#include "RobotMap.h"

/************************** Library Header Files ******************************/

/** ****************************************************************************
 * @class   RobotTick
 * @brief   This class provides a means to keep track of "ticks" (such as a
 *          clock tick-tock, as opposed to the type that gets on 
 *          your pet). Ticks are often incremented periodically, and read for 
 *          certain events.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class RobotTick {

  public:

    /********************** PUBLIC MEMBER FUNCTIONS ***************************/

    /** The constructor for the RobotTick class */  
    RobotTick();

    /** The destructor for the RobotTick class */
    ~RobotTick();

    /** A method to increment the robot tick counter */
    void IncrementRobotTick();

    /** A method to get the # of robot tick elapsed */
    uint64_t GetRobotTick();

  private:

    /********************* PRIVATE MEMBER FUNCTIONS ***************************/


    /********************* PRIVATE MEMBER VARIABLES ***************************/

    // NOTE: The "ull" after the 0 specifies that the 0 is an 
    //       Unsigned Long Long (ull), which is 64 bits
    /** A tick counter for the robot. */
    uint64_t m_RobotTick = 0ull;

}; // end class RobotTick

#endif // #ifndef ROBOTTICK_H
