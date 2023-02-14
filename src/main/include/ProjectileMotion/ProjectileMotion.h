/** ===========================================================================
 * @file   ProjectileMotion.h
 * @brief  This file declares the ProjectileMotion class.
 *
 * The ProjectileMotion class is used in projectile trajectory kinematic
 * calculations.
 * 
 * COPYRIGHT NOTICES:
 *
 * Copyright (c) 2022 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

// INCLUDE GUARD - see https://en.wikipedia.org/wiki/Include_guard
// If we have not already defined PROJECTILEMOTION_H...
#ifndef PROJECTILEMOTION_H
// Define PROJECTILEMOTION_H
#define PROJECTILEMOTION_H

/*************************** Local Header Files *******************************/

/************************** Library Header Files ******************************/

/** ****************************************************************************
 * @class   ProjectileMotion
 * @brief   This is a class that is used in projectile trajectory kinematic
 *          calculations
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class ProjectileMotion {

  public:

    /** 
     * The ProjectileMotion class constructor.
     * 
     * @param d_angle The departure angle, in degrees
     * @param x0      The initial x position, in meters
     * @param y0      The initial y position, in meters
     * @param xt      The x (horizontal) position of the target, in meters
     * @param yt      The y (vertical) position of the target, in meters
     * 
    */
    ProjectileMotion(
      double d_angle,
      double x0,
      double y0,
      double xt,
      double yt
    );

    /** The ProjectileMotion class destructor. */
    ~ProjectileMotion();

    /********************* Public member functions ************************/

    /**
     * Method to determine initial velocity from angle, initial position,
     * and target position.
     * 
     * @return The initial velocity required, in m/s
    */
    double get_initial_velocity_from_angle_x0_y0_xt_yt();

    /**
     * Method to determine time to target from initial velocity,
     * initial x coordinate, and target x coordinate.
     * 
     * @return The time to target, in seconds
    */
    double get_time_to_target_from_v0_x0_xt();

  private:

    /********************* Private member variables ***********************/

    /** The initial velocity of a projectile, in m/s */
    double m_initial_velocity;
    /** The launch/departure angle of a projectile, in degrees */
    double m_departure_angle_deg;
    /** The launch/departure angle of a projectile, in radians */
    double m_departure_angle_rad;
    /** The initial x coordinate of the projectile, in meters */
    double m_x_initial;
    /** The initial y coordinate of the projectile, in meters */
    double m_y_initial;
    /** The x coordinate at time t, in meters */
    double m_x_position;
    /** The y coordinate at time t, in meters */
    double m_y_position;
    /** The x coordinate of the target, in meters */
    double m_x_target;
    /** The y coordinate of the target, in meters */
    double m_y_target;
    /** The current time, in seconds past t=0 */
    double m_time_t;
    /** The time from launch/departure to arrival at target, in seconds */
    double m_time_to_target;

    /********************* Private member functions ***********************/

}; // end class ProjectileMotion

# endif // #ifndef PROJECTILEMOTION_H
