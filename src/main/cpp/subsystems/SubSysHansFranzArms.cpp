/** ===========================================================================
 * @file   SubSysHansFranzArms.cpp
 * @brief  This file defines the SubSysHansFranzArms class.
 *
 * The SubSysHansFranzArms class is used to raise and lower our lifting arms.
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

// Include the header file for our SubSysHansFranzArms class
#include "subsystems/SubSysHansFranzArms.h"

// Include out robot map header file
#include "RobotMap.h"

/************************** Library Header Files ******************************/

// Include the motor safety header file
#include <frc/MotorSafety.h>

/************************ Member function definitions *************************/

// The SubSysHansFranzArms constructor
// NOTE: The 2nd line is known as a member initialization (or initializer)
//       list.
// See https://www.learncpp.com/cpp-tutorial/8-5a-constructor-member-initializer-lists/
SubSysHansFranzArms::SubSysHansFranzArms()
  : m_HansFranzArmsController{k_HansFranzArmsPWMPort} {

  // Set the subsystem's name
  SetName("SubSysHansFranzArms");

  // Set the motor safety timeout for Hans and Franz
  m_HansFranzArmsController.SetExpiration(k_HansFranzSafetyTimeout);

  // Disable Hans and Franz arms initially
  m_HansFranzArmsEnabled = false;

  // Set the state to unknown initially
  m_HansFranzArmsSmartDashboardState = k_HansFranzArmsStateUnknown;

  // Create the fully retracted limit switch
  m_HansFranzArms_FullyRetracted_LimitSwitch = 
    new frc::DigitalInput(k_HansFranzArms_FullyRetracted_LimitSwitch_Channel);

  // Create the fully extended limit switch
  m_HansFranzArms_FullyExtended_LimitSwitch = 
    new frc::DigitalInput(k_HansFranzArms_FullyExtended_LimitSwitch_Channel);

  // NOTE: Make sure you create a digital input before creating a counter,
  //       or you will be using an uninitialized pointer. Don't do it!

  // Create the fully retracted counter
  m_HansFranzArms_FullyRetracted_Counter = 
    new frc::Counter(m_HansFranzArms_FullyRetracted_LimitSwitch);

  // Create the fully extended counter
  m_HansFranzArms_FullyExtended_Counter = 
    new frc::Counter(m_HansFranzArms_FullyExtended_LimitSwitch);

  // Set the state to unknown, initially
  m_HansFranzArmsState = SubSysHansFranzArms::UNKNOWN;

  // Set positive (up) speed not allowed
  m_PositiveSpeedUpAllowed = false;

  // Set negative (down) speed not allowed
  m_NegativeSpeedDownAllowed = false;

} // end SubSysHansFranzArms::SubSysHansFranzArms()

// The SubSysHansFranzArms default destructor
SubSysHansFranzArms::~SubSysHansFranzArms() {

  // Delete the fully extended counter
  delete m_HansFranzArms_FullyExtended_Counter;

  // Delete the fully retracted counter
  delete m_HansFranzArms_FullyRetracted_Counter;

  // Delete the fully extended limit switch
  delete m_HansFranzArms_FullyExtended_LimitSwitch;

  // Delete the fully retracted limit switch
  delete m_HansFranzArms_FullyRetracted_LimitSwitch;
  
} // end SubSysHansFranzArms::~SubSysHansFranzArms()

// The periodic method for the SubSysHansFranzArms subsystem
void SubSysHansFranzArms::Periodic() {

  // Put code here to be run every loop

  // Feed the motor controller safety system
  m_HansFranzArmsController.Feed();

} // end SubSysHansFranzArms::Periodic()

// Put methods for controlling this subsystem
// here. Call these from Commands.

//////////////////////////////////////////////////////////////////////////////
// A little explanation is warranted.
//
// * We have the arms going up (extending) and going down (retracting).
//
// * We have two limit switches, one which closes when fully retracted,
//   and one which closes when fully extended
//
// * These switches are connected to DIO 0 and 1 (see RobotMap.h)
//
// * DIO 0 and 1 have internal pull-up resistors between Vcc (+3.3V or
//   +5V) and the signal. This makes the signal have a logic 1 (Vcc) when
//   nothing else is connected.
//
// * The common (C) of a switch is connected to the signal of a DIO, and
//   the the normally open (NO) of the switch will connect to ground.
//
// * When the switch closes, the NO contact makes contact with the common
//   contact, and makes the signal go to a logic 0 (approx. 0V).
//
// * However, we use positive logic to see when the switch is set (closed).
//   This means that a true indicates switch closed, and false for open.
//
// * Below is a table of inputs (motor direction, retracted switch,
//   and extended switch), along with what state the arms would be in based
//   on these inputs, along with the motor direction allowed.
//   
//  Dir 	Retracted Switch 	Extended Switch 	State 	         Dir Allowed 	
//   - 	        OPEN 	           OPEN 	      Retracting 	         0,-,+ 	
//   - 	        OPEN 	          CLOSED 	      StartRetracting 	   0,- 	
//   - 	       CLOSED 	         OPEN 	      Retracted 	         0,  + 	
//   - 	       CLOSED 	        CLOSED 	      Fault 	             0 	
//   0 	        OPEN 	           OPEN 	      Unknown 	           0,-,+ 		
//   0 	        OPEN 	          CLOSED 	      Extended 	           0,- 	
//   0 	       CLOSED 	         OPEN 	      Retracted 	         0,  + 	
//   0 	       CLOSED 	        CLOSED 	      Fault 	             0 	
//   + 	        OPEN 	           OPEN 	      Extending 	         0,-,+ 	
//   + 	        OPEN 	          CLOSED 	      Extended 	           0,- 	
//   + 	       CLOSED 	         OPEN 	      StartExtending 	     0,+ 	
//   + 	       CLOSED 	        CLOSED 	      Fault 	             0
//
// If we reorder the above table by the direction allowed (a spreadsheet
// is very helpful to do this), we get:
//
// Dir 	Retracted Switch 	Extended Switch 	State 	          Dir Allowed 	
//  - 	    CLOSED 	          CLOSED 	      Fault 	               0 	
//  0 	    CLOSED 	          CLOSED 	      Fault 	               0 	
//  + 	    CLOSED 	          CLOSED 	      Fault 	               0 	
//  0 	     OPEN 	          CLOSED 	      Extended 	             0,- 	
//  + 	     OPEN 	          CLOSED 	      Extended 	             0,- 	
//  - 	     OPEN 	          CLOSED 	      StartRetracting 	     0,- 	
//  + 	     OPEN 	           OPEN 	      Extending 	           0,-,+ 	
//  - 	     OPEN 	           OPEN 	      Retracting 	           0,-,+ 	
//  0 	     OPEN 	           OPEN 	      Unknown 	             0,-,+ 	
//  - 	    CLOSED 	           OPEN 	      Retracted 	           0,  + 	
//  0 	    CLOSED 	           OPEN 	      Retracted 	           0,  + 	
//  + 	    CLOSED 	           OPEN 	      StartExtending 	       0,  + 	
// 
// We use the above table in the code below. Enumerations are in the 
// header file.
//////////////////////////////////////////////////////////////////////////////
// The method for moving Hans and Franz arms 
void SubSysHansFranzArms::MoveHansFranzArms(double speed) {

  // If Hans and Franz arms are enabled...
  if(m_HansFranzArmsEnabled)
  {

    // Get the current state of Hans and Franz arms
    m_HansFranzArmsState = GetCurrentHansFranzArmsState(speed);

    // Now set the allowed speed directions
    SetAllowedSpeeds(m_HansFranzArmsState);

    // If the motor speed is positive AND positive is allowed, 
    //   OR
    // If the motor speed is negative AND negative is allowed...
    if( ((GetMotorSpeedDir(speed) == POSITIVE) && (m_PositiveSpeedUpAllowed))
        ||
        ((GetMotorSpeedDir(speed) == NEGATIVE) && (m_NegativeSpeedDownAllowed)) )
    {

      // Set the Hans and Franz arms motor to the passed in speed
      m_HansFranzArmsController.Set(speed);

    }
    else // positive or negative speeds are not allowed
    {

      // Set the Hans and Franz arms motor to be stopped
      m_HansFranzArmsController.Set(k_MotorStopSpeed);

    } // end ((GetMotorSpeedDir(speed) == POSITIVE)...

    // Switch on the state of the Hans and Franz Arms...
    switch(m_HansFranzArmsState)
    {

      // If we are extended or starting to retract
      case EXTENDED:
      case START_RETRACTING:
        // Set state for dashboard to extended
        m_HansFranzArmsSmartDashboardState = k_HansFranzArmsStateExtended;
        // Reset the counter for the extended limit switch
        ResetHansFranzArmsFullyExtendedCounter();
        break;

      // If we are retracted or starting to extend...
      case RETRACTED:
      case START_EXTENDING:
        // Set state for dashboard to retracted
        m_HansFranzArmsSmartDashboardState = k_HansFranzArmsStateRetracted;
        // Reset the counter for the retracted limit switch
        ResetHansFranzArmsFullyRetractedCounter();
        break;

      // If we are extending...
      case EXTENDING:
        // Set state for dashboard to extending      
        m_HansFranzArmsSmartDashboardState = k_HansFranzArmsStateExtending;
        break;

      // If we are retracting...
      case RETRACTING:
        // Set state for dashboard to extending
        m_HansFranzArmsSmartDashboardState = k_HansFranzArmsStateRetracting;
        break;

      // If we don't know what state we are in...
      case UNKNOWN:
        // Set state for dashboard to unknown
        m_HansFranzArmsSmartDashboardState = k_HansFranzArmsStateUnknown;
        break;

      // If we have a fault
      case FAULT:
      default:
        // Set state for dashboard to fault
        m_HansFranzArmsSmartDashboardState = k_HansFranzArmsStateFault;

    } // end switch(m_HansFranzArmsState)

  } // end if(m_HansFranzArmsEnabled)

} // end SubSysHansFranzArms::MoveHansFranzArms(double)

// Method to get Hans and Franz arms's null zone.
double SubSysHansFranzArms::GetHansFranzArmsNullZone() {

  // Return Hans and Franz arms's null zone
  return k_HansFranzArmsAbsNullZone;

} // end SubSysHansFranzArms::GetHansFranzArmsNullZone()

// Method to get Hans and Franz arms's speed limit.
double SubSysHansFranzArms::GetHansFranzArmsLimit() {

  // Return Hans and Franz arms's speed limit
  return k_HansFranzArmsAbsValMaxSpeedNoTurbo;

} // end SubSysHansFranzArms::GetHansFranzArmsLimit()

// Method to get Hans and Franz arms's exponent for the curve.
double SubSysHansFranzArms::GetHansFranzArmsExponent() {

  // Return Hans and Franz arms's exponent
  return k_HansFranzArmsExponent;

} // end SubSysHansFranzArms::GetHansFranzArmsExponent()

// Method to enable Hans and Franz arms
void SubSysHansFranzArms::EnableHansFranzArms()
{

  // Enable Hans and Franz arms
  m_HansFranzArmsEnabled = true;

} // end SubSysHansFranzArms::EnableHansFranzArms()

// Method to get if Hans and Franz arms are enabled
bool SubSysHansFranzArms::AreHansFranzArmsEnabled()
{

  // Return if Hans and Franz arms are enabled
  return m_HansFranzArmsEnabled;

} // end SubSysHansFranzArms::AreHansFranzArmsEnabled()

// Method to get Hans and Franz arms state for the SmartDashboard
std::string SubSysHansFranzArms::GetHansFranzArmsSmartDashboardState()
{

  // return the state of Hans and Franz arms for the SmartDashboard
  return m_HansFranzArmsSmartDashboardState;

} // end SubSysHansFranzArms::GetHansFranzArmsState()

// Method to see if the arms are fully retracted
bool SubSysHansFranzArms::IsHansFranzArmsFullyRetracted() 
{

  // Return true if:
  //   The counter has a value greater than the reset value
  // OR 
  //   The switch has a value of closed
  return (
    (m_HansFranzArms_FullyRetracted_Counter->Get() > k_CounterResetValue)
    ||
    (m_HansFranzArms_FullyRetracted_LimitSwitch->Get() == k_DigitalInputPullUpSwitchClosed)
  );

} // end SubSysHansFranzArms::IsHansFranzArmsFullyRetracted()

// Method to see if the arms are fully extended 
bool SubSysHansFranzArms::IsHansFranzArmsFullyExtended()
{

  // Return true if:
  //   The counter has a value greater than the reset value
  // OR 
  //   The switch has a value of closed
  return (
    (m_HansFranzArms_FullyExtended_Counter->Get() > k_CounterResetValue)
    ||
    (m_HansFranzArms_FullyExtended_LimitSwitch->Get() == k_DigitalInputPullUpSwitchClosed)
  );

} // end SubSysHansFranzArms::IsHansFranzArmsFullyExtended()

// Method to reset the counter for Hans/Franz fully retracted
void SubSysHansFranzArms::ResetHansFranzArmsFullyRetractedCounter()
{

  // Reset the counter for the fully retracted limit switch
  m_HansFranzArms_FullyRetracted_Counter->Reset();

} // end SubSysHansFranzArms::ResetHansFranzArmsFullyRetractedCounter()

// Method to reset the counter for Hans/Franz fully extended
void SubSysHansFranzArms::ResetHansFranzArmsFullyExtendedCounter()
{

  // Reset the counter for the fully extended limit switch
  m_HansFranzArms_FullyExtended_Counter->Reset();

} // end SubSysHansFranzArms::ResetHansFranzArmsFullyExtendedCounter()

// Method to determine the current state of the arms based on inputs.
SubSysHansFranzArms::HansFranzArmsStates 
  SubSysHansFranzArms::GetCurrentHansFranzArmsState(double speed)
{

  // A state variable for Hans and Franz arms, set to unknown initially
  HansFranzArmsStates state = UNKNOWN;

  // If both switches are closed...
  if(IsHansFranzArmsFullyRetracted() && IsHansFranzArmsFullyExtended())
    // we have a fault
    state = FAULT;

  // If the retracted switch is open and the extended switch is closed...
  if(!IsHansFranzArmsFullyRetracted() && IsHansFranzArmsFullyExtended())
  {

    // If the motor speed is negative...
    if(GetMotorSpeedDir(speed) == NEGATIVE)
      state = START_RETRACTING;
    else // Speed is ZERO or POSITIVE
      state = EXTENDED;
    
  } // end if(!IsHansFranzArmsFullyRetracted() && IsHansFranzArmsFullyExtended())

  // If the both switches are open...
  if(!IsHansFranzArmsFullyRetracted() && !IsHansFranzArmsFullyExtended())
  {

    // If the motor speed is positive...
    if(GetMotorSpeedDir(speed) == POSITIVE)
      // We are extending
      state = EXTENDING;

    // If the motor speed is negative...
    else if(GetMotorSpeedDir(speed) == NEGATIVE)
      // We are retracting
      state = RETRACTING;

    // Must be zero speed
    else
      // So we don't know what we are doing
      state = UNKNOWN;
    
  } // end if(!IsHansFranzArmsFullyRetracted() && !IsHansFranzArmsFullyExtended())

  // If the retracted switch is closed and the extended switch is open...
  if(IsHansFranzArmsFullyRetracted() && !IsHansFranzArmsFullyExtended())
  {

    // If the motor speed is positive...
    if(GetMotorSpeedDir(speed) == POSITIVE)
      // We are starting to extend from the retracted position
      state = START_EXTENDING;
    else // speed is negative or zero
      state = RETRACTED;

  } // end if(IsHansFranzArmsFullyRetracted() && !IsHansFranzArmsFullyExtended())
  
  // Return the determined state
  return state;

} // end SubSysHansFranzArms::GetCurrentHansFranzArmsState(...)

// Method to set the allowed speeds based on the passed in state
void SubSysHansFranzArms::SetAllowedSpeeds(
  SubSysHansFranzArms::HansFranzArmsStates state
)
{

  // Switch on the state passed in...
  switch(state)
  {

    // If we are extended or starting to retract...
    case EXTENDED:
    case START_RETRACTING:
      // Can't move up
      m_PositiveSpeedUpAllowed   = false;
      // but we can move down
      m_NegativeSpeedDownAllowed = true;
      break;

    // If we are retracted or starting to extend
    case RETRACTED:
    case START_EXTENDING:
      // Can move up
      m_PositiveSpeedUpAllowed   = true;
      // but we can't move down
      m_NegativeSpeedDownAllowed = false;
      break;

    // If we are extending or retracting...
    case EXTENDING:
    case RETRACTING:
    case UNKNOWN:
      // Can move up
      m_PositiveSpeedUpAllowed   = true;
      // and we can move down
      m_NegativeSpeedDownAllowed = true;
      break;

    // If we have a fault
    case FAULT:
    default:
      // Can't move up
      m_PositiveSpeedUpAllowed   = false;
      // and we can't move down
      m_NegativeSpeedDownAllowed = false;

  } // end switch(state)

} // end SubSysHansFranzArms::SetAllowedSpeeds(...)

// Determine the direction of the arms motor, based on passed in speed
SubSysHansFranzArms::MotorSpeedDirTypes 
  SubSysHansFranzArms::GetMotorSpeedDir(double speed)
{

  // If the absolute value of the speed is less than our null zone
  if(fabs(speed) < k_HansFranzArmsAbsNullZone)
    // Return ZERO direction
    return ZERO;

  // If the speed is greater than or equal to our null zone... 
  else if (speed >= k_HansFranzArmsAbsNullZone)
    // Return POSITIVE direction
    return POSITIVE;

  else // Must be negative...
    // Return NEGATIVE direction
    return NEGATIVE;

} // end SubSysHansFranzArms::GetMotorSpeedDir(double speed)
