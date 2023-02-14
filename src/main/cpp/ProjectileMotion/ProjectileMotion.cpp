/** ===========================================================================
 * @file   ProjectileMotion.cpp
 * @brief  This file defines the ProjectileMotion class.
 *
 * The ProjectileMotion class is used to perform kinematic projectile motion
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

/*************************** Local Header Files *******************************/

// Include the header file for the ProjectileMotion class
#include "ProjectileMotion/ProjectileMotion.h"

// Include the header file for the math/physics constants
#include "MathPhysicsConstants.h"

/************************** Library Header Files ******************************/

// Include the header file for math functions
#include <cmath>

/************************ Member function definitions *************************/

// A constructor for the ProjectileMotion class, given departure angle,
// initial coordinates, and target coordinates
ProjectileMotion::ProjectileMotion(
    double departure_angle_deg,
    double x_initial,
    double y_initial,
    double x_target,
    double y_target
)
  // Initialize the member variables with the constructor parameters
  : m_departure_angle_deg(departure_angle_deg),
    m_x_initial(x_initial),
    m_y_initial(y_initial),
    m_x_target(x_target),
    m_y_target(y_target)
{

  // Calculate the departure angle in radians
  m_departure_angle_rad = m_departure_angle_deg * k_DegToRad;

} // end ProjectileMotion::ProjectileMotion()

// The destructor for the ProjectileMotion class
ProjectileMotion::~ProjectileMotion() {

  // No code for this destructor

} // end ProjectileMotion::~ProjectileMotion()

// Method to calculate initial velocity given launch/departure angle,
// initial coordinates, and target coordinates
double 
  ProjectileMotion::get_initial_velocity_from_angle_x0_y0_xt_yt() {

  // The numerator for the equation
  double numerator;
  // The first part of the denominator for the equation
  double denominator1;
  // The second part of the denominator for the equation
  double denominator2;

  // Calculate the numerator
  numerator    = (k_earth_g_mps2*pow((m_x_target-m_x_initial),2.0));

  // Calculate the 1st part of the denominator
  denominator1 = (2.0*pow(cos(m_departure_angle_rad),2.0));

  // Calculate the 2nd part of the denominator
  denominator2 = ( (tan(m_departure_angle_rad)*(m_x_target-m_x_initial)) + 
                    m_y_initial - 
                    m_y_target);

  // Calculate the desired initial velocity magnitude
  m_initial_velocity = sqrt( numerator / (denominator1 * denominator2));

  // Return the desired initial velocity magnitude
  return m_initial_velocity;

} // end ProjectileMotion::get_initial_velocity_from_angle_x0_y0_xt_yt()

// Method to calculate time to target from initial velocity, initial
// x coordinate, and target x coordinate
double ProjectileMotion::get_time_to_target_from_v0_x0_xt() {

  // Calculate the time to target 
  m_time_to_target =  (m_x_target - m_x_initial) / 
                      (m_initial_velocity * cos(m_departure_angle_rad));

  // return the time to target 
  return m_time_to_target;

} // end ProjectileMotion::get_time_to_target_from_v0_x0_xt()
