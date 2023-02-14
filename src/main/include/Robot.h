/** ===========================================================================
 * @file   Robot.h
 * @brief  This file declares the Robot class.
 *
 * The Robot class is responsible for the main control flow of the robot.
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
 * Copyright (c) 2019-2022 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

// INCLUDE GUARD - see https://en.wikipedia.org/wiki/Include_guard
// If we have not already defined ROBOT_H...
#ifndef ROBOT_H
// Define ROBOT_H
#define ROBOT_H

/*************************** Local Header Files *******************************/

// Include the header robot container, which has the subsystems, commands, and
// button bindings
#include "RobotContainer.h"

// Include the header file for using a Spark Max motor controller via CAN
#include "rev/CANSparkMax.h"

/************************** Library Header Files ******************************/

// Include the TimedRobot class header file, which is the base class for the
//  Robot class
// http://first.wpi.edu/FRC/roborio/release/docs/cpp/classfrc_1_1TimedRobot.html
#include <frc/TimedRobot.h>

// Include the NEW(2020) Command class header file, which allows us to create 
//   commands for the robot, and the core of the command framework
#include <frc2/command/Command.h>

// Include the string header file
#include <string>

/** ****************************************************************************
 * @class   Robot
 * @brief   This is the main class that defines our robot.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class Robot : public frc::TimedRobot {

  public:

    /********************** PUBLIC MEMBER FUNCTIONS ***************************/

    /**
     * Robot-wide initialization code should go here.
     *
     * Users should override this method for default Robot-wide initialization
     * which will be called when the robot is first powered on. It will be
     * called exactly one time.
     *
     * Warning: the Driver Station "Robot Code" light and FMS "Robot Ready"
     * indicators will be off until RobotInit() exits. Code in RobotInit() that
     * waits for enable will cause the robot to never indicate that the code is
     * ready, causing the robot to be bypassed in a match.
     *
     * @see virtual void frc::IterativeRobotBase::RobotInit()
    */
    void RobotInit() override;

    /**
     * Robot-wide simulation initialization code should go here.
     * 
     * This method is used for default Robot-wide simulation related
     * initialization which will be called when the robot is first started.
     * It will be called exactly one time after RobotInit is called only 
     * when the robot is in simulation.
     * 
     * @see virtual void frc::IterativeRobotBase::SimulationInit()
    */
    void SimulationInit() override;

    /**
     * Initialization code for disabled mode should go here.
     *
     * Users should override this method for initialization code which will be
     * called each time the robot enters disabled mode.
     *
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
     * the robot is disabled.
     *
     * @see virtual void frc::IterativeRobotBase::DisabledInit()
    */
    void DisabledInit() override;

    /**
     * Periodic code for all modes should go here.
     *
     * This function is called each time a new packet is received from the
     * driver station.
     *
     * This function is called every robot packet, no matter the mode. Use
     * this for items like diagnostics that you want ran during disabled,
     * autonomous, teleoperated and test.
     *
     * <p> This runs after the mode specific periodic functions, but before
     * LiveWindow and SmartDashboard integrated updating.
     *
     * @see virtual void frc::IterativeRobotBase::RobotPeriodic()
    */
    void RobotPeriodic() override;

    /**
     * Periodic simulation code should go here. 
     * 
     * This function is called in a simulated robot after user code executes.
     * 
     * @see virtual void frc::IterativeRobotBase::SimulationPeriodic()
    */ 
    void SimulationPeriodic() override;

    /**
     * Periodic code for disabled mode should go here.
     *
     * Users should override this method for code which will be called each time
     * a new packet is received from the driver station and the robot is in
     * disabled mode.
     *
     * @see virtual void frc::IterativeRobotBase::DisabledPeriodic()
    */
    void DisabledPeriodic() override;

    /**
     * Initialization code for autonomous mode should go here.
     *
     * Users should override this method for initialization code which will be
     * called each time the robot enters autonomous mode.
     *
     * This autonomous runs the autonomous command selected by your {@link
     * RobotContainer} class.
     *
     * @see virtual void frc::IterativeRobotBase::AutonomousInit()
    */
    void AutonomousInit() override;

    /**
     * Periodic code for autonomous mode should go here.
     *
     * Users should override this method for code which will be called each time
     * a new packet is received from the driver station and the robot is in
     * autonomous mode.
     *
     * @see virtual void frc::IterativeRobotBase::AutonomousPeriodic()
    */
    void AutonomousPeriodic() override;

    /**
     * Initialization code for teleop mode should go here.
     *
     * Users should override this method for initialization code which will be
     * called each time the robot enters teleop mode.
     *
     * @see virtual void frc::IterativeRobotBase::TeleopInit()
    */
    void TeleopInit() override;

    /**
     * Periodic code for teleop mode should go here.
     *
     * This function is called periodically during operator control.
     * 
     * Users should override this method for code which will be called each time
     * a new packet is received from the driver station and the robot is in 
     * teleop mode.
     *
     * @see virtual void frc::IterativeRobotBase::TeleopPeriodic()
    */
    void TeleopPeriodic() override;

    /**
     * Periodic code for test mode should go here.
     *
     * This function is called periodically during test mode.
     * 
     * Users should override this method for code which will be called each time
     * a new packet is received from the driver station and the robot is in test
     * mode.
     *
     * @see virtual void frc::IterativeRobotBase::TestPeriodic()
    */
    void TestPeriodic() override;

  private:

    /********************* PRIVATE MEMBER FUNCTIONS ***************************/

    /** Outputs the version information to the console */
    void outputVersionInfoToConsole();

    /********************* PRIVATE MEMBER VARIABLES ***************************/

    /**
     * The autonomous command to run.
     * 
     * Have it null by default so that if testing teleop it
     * doesn't have undefined behavior and potentially crash.
    */
    frc2::Command* m_autonomousCommand = nullptr;

    /** Declare a container for the robot, which has commands, subsystems
     *    and button bindings */
    RobotContainer m_RobotContainer;

    /** Define a string for the robot code version message */
    std::string m_RobotCode_version_msg;

}; // end class Robot

#endif // #ifndef ROBOT_H
