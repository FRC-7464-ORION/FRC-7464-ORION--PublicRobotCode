/** ===========================================================================
 * @file   Robot.h
 * @brief  This file declares the Robot class.
 *
 * The Robot class defines the entire robot, its subsystems, commands, etc.
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
 * Copyright (c) 2019-2020 FRC Team #7464 - ORION. All Rights Reserved.
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

// Include our Robot constants
#include "RobotConstants.h"

// Include the SubSysDriveTrain class header file, which is our drivetrain
#include "subsystems/SubSysDriveTrain.h"

// Include the SubSysPATTurner class header file, which is our Wheel of
// Fortune Turner
#include "subsystems/SubSysPATTurner.h"

// Include the SubSysHansFranzMuscles class header file, which is our lifter
// pneumatics
#include "subsystems/SubSysHansFranzMuscles.h"

// Include the SubSysHansFranzArms class header file, which is for our
// lifter arms
#include "subsystems/SubSysHansFranzArms.h"

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

// Include the PIDSubSysPssh class header file, which is our power cell
// transporter
#include "subsystems/PIDSubSysPssh.h"

#endif // #if USE_PID_PSSH

// If we are NOT using the PID controller for Pssh
#if !USE_PID_PSSH

// Include the SubSysPssh class header file, which is our power cell
// transporter
#include "subsystems/SubSysPssh.h"

#endif // #if !USE_PID_PSSH

// Include the operator interface (OI) class header file, which allows us
//  to define our interface to the operator (driver)
#include "OI.h"

// Include the CmdDriveArcadeStyle class header file, which declares the
//   command to drive the robot arcade style
#include "commands/DriveTrain/CmdDriveArcadeStyle.h"

// Include the CmdDriveTankStyle class header file, which declares the
//   command to drive the robot tank style
#include "commands/DriveTrain/CmdDriveTankStyle.h"

// If we are NOT using the PID controller for Pssh
#if !USE_PID_PSSH

// Include the CmdControlPssh class header file, which declares the
//   command to control the power cell transporter manually
#include "commands/Pssh/CmdControlPssh.h"

#endif // #if !USE_PID_PSSH

// Include the CmdZeroAHRSYaw class
#include "commands/DriveTrain/CmdZeroAHRSYaw.h"

// Include the CmdResetAHRSYaw class
#include "commands/DriveTrain/CmdResetAHRSYaw.h"

// Include the CmdMoveHansFranzArms class header file, which declares the
//   command to move Hans' and Franz's arms
#include "commands/HansAndFranzArms/CmdMoveHansFranzArms.h"

// Include the CmdGrpAutoDefault class, which has some commands to execute
#include "commandGroups/Autonomous/CmdGrpAutoDefault.h"

// Include the CmdGrpAutoDefLeft class, which has some commands to execute
#include "commandGroups/Autonomous/CmdGrpAutoDefLeft.h"

// Include the CmdGrpAutoDefCenter class, which has some commands to execute
#include "commandGroups/Autonomous/CmdGrpAutoDefCenter.h"

// Include the CmdGrpAutoDefRight class, which has some commands to execute
#include "commandGroups/Autonomous/CmdGrpAutoDefRight.h"

// Include the CmdGrpAutoOffLeft class, which has some commands to execute
#include "commandGroups/Autonomous/CmdGrpAutoOffLeft.h"

// Include the CmdGrpAutoOffCenter class, which has some commands to execute
#include "commandGroups/Autonomous/CmdGrpAutoOffCenter.h"

// Include the CmdGrpAutoOffRight class, which has some commands to execute
#include "commandGroups/Autonomous/CmdGrpAutoOffRight.h"

// Include the TelemetryOutputter class header file
#include "Telemetry/TelemetryOutputter.h"

// Include the Video class header file
#include "Vision/Video.h"

/************************** Library Header Files ******************************/

// Include the string header file
#include <string>

// Include the TimedRobot class header file, which is the base class for the
//  Robot class
// http://first.wpi.edu/FRC/roborio/release/docs/cpp/classfrc_1_1TimedRobot.html
#include <frc/TimedRobot.h>

// Include the Command class header file, which allows us to create commands
//  for the robot, and the core of the command framework
// http://first.wpi.edu/FRC/roborio/release/docs/cpp/classfrc_1_1Command.html
#include <frc/commands/Command.h>

// Include the Sendable Choser class header file, which allows us to present
//  a selection of options to the SmartDashboard
// http://first.wpi.edu/FRC/roborio/release/docs/cpp/classfrc_1_1SendableChooser.html
#include <frc/smartdashboard/SendableChooser.h>

// Include the CameraServer class for camera streaming
#include <cameraserver/CameraServer.h>

// Include the LiveWindow class, The LiveWindow class is the public interface
//   for putting sensors and actuators on the LiveWindow.
// See:
// file:///C:/Users/Public/frc2019/documentation/cpp/classfrc_1_1LiveWindow.html
// (From RobotBuilder) 
#include <frc/livewindow/LiveWindow.h>

// Include the DriverStation, for errors and warnings
#include <frc/DriverStation.h>

// Include the NavX MXP AHRS class header
#include "AHRS.h"

/** ****************************************************************************
 * @class   Robot
 * @brief   This is the main class that defines our robot.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class Robot : public frc::TimedRobot {
  public:

    /*********************** Public member variables **************************/

    /** A constant string that we can use to print out our version # */
    const std::string m_version = k_SW_VersionNumber;

    /**
     * A public, static instance of a AHRS class.
     * 
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this pointer
     * m_AHRS is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static AHRS* m_AHRS;

    /**
     * A public, static instance of a SubSysDriveTrain class.
     * 
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     * m_subSysDriveTrain is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static std::shared_ptr<SubSysDriveTrain> m_subSysDriveTrain;

    /**
     * A public, static instance of a SubSysPATTurner class.
     * 
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     * m_subSysPATTurner is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static std::shared_ptr<SubSysPATTurner> m_subSysPATTurner;

    /**
     * A public, static instance of a SubSysHansFranz class.
     * 
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     * m_subSysHansFranz is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static std::shared_ptr<SubSysHansFranzMuscles> m_subSysHansFranzMuscles;

    /**
     * A public, static instance of a SubSysHansFranzArms class.
     * 
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     * m_subSysHansFranzArms is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static std::shared_ptr<SubSysHansFranzArms> m_subSysHansFranzArms;

// If we are using the PID controller for Pssh
#if USE_PID_PSSH

    /**
     * A public, static instance of a PIDSubSysPssh class.
     * 
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     * m_PIDsubSysPssh is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static std::shared_ptr<PIDSubSysPssh> m_PIDsubSysPssh;

#endif // #if USE_PID_PSSH

// If we are NOT using the PID controller for Pssh
#if !USE_PID_PSSH

    /**
     * A public, static instance of a SubSysPssh class.
     * 
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     * m_subSysPssh is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static std::shared_ptr<SubSysPssh> m_subSysPssh;

#endif // #if !USE_PID_PSSH

    /**
     * A public, static instance of an OI (operator interface).
     * 
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     * m_oi is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static std::unique_ptr<OI> m_oi;

    /**
     * A public, static instance of a CmdDriveArcadeStyle class.
     * 
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     * m_cmdDriveArcadeStyle is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static std::shared_ptr<CmdDriveArcadeStyle> m_cmdDriveArcadeStyle;

    /**
     * A public, static instance of a CmdDriveTankStyle class.
     * 
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     * m_cmdDriveArcadeStyle is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static std::shared_ptr<CmdDriveTankStyle> m_cmdDriveTankStyle;

// If we are NOT using the PID controller for Pssh...
#if !USE_PID_PSSH

    /**
     * A public, static instance of a CmdControlPssh class.
     * 
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     * m_cmdControlPssh is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static std::shared_ptr<CmdControlPssh> m_cmdControlPssh;

#endif // #if !USE_PID_PSSH

    /**
     * A public, static instance of a CmdDriveArcadeStyle class.
     * 
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     * m_cmdDriveArcadeStyle is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static std::shared_ptr<CmdMoveHansFranzArms> m_cmdMoveHansFranzArms;

    /**
     * A public, static instance of a CmdGrpAutoDefault class.
     * 
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     * m_cmdDriveArcadeStyle is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static std::shared_ptr<CmdGrpAutoDefault> m_CmdGrpAutoDefault;

    /**
     * A public, static instance of a CmdGrpAutoDefLeft class.
     * 
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     * m_cmdDriveArcadeStyle is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static std::shared_ptr<CmdGrpAutoDefLeft> m_CmdGrpAutoDefLeft;

    /**
     * A public, static instance of a CmdGrpAutoDefCenter class.
     * 
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     * m_cmdDriveArcadeStyle is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static std::shared_ptr<CmdGrpAutoDefCenter> m_CmdGrpAutoDefCenter;

    /**
     * A public, static instance of a CmdGrpAutoDefRight class.
     * 
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     * m_cmdDriveArcadeStyle is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static std::shared_ptr<CmdGrpAutoDefRight> m_CmdGrpAutoDefRight;

    /**
     * A public, static instance of a CmdGrpAutoOffLeft class.
     * 
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     * m_cmdDriveArcadeStyle is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static std::shared_ptr<CmdGrpAutoOffLeft> m_CmdGrpAutoOffLeft;

    /**
     * A public, static instance of a CmdGrpAutoOffCenter class.
     * 
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     * m_cmdDriveArcadeStyle is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static std::shared_ptr<CmdGrpAutoOffCenter> m_CmdGrpAutoOffCenter;

    /**
     * A public, static instance of a CmdGrpAutoOffRight class.
     * 
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     * m_cmdDriveArcadeStyle is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static std::shared_ptr<CmdGrpAutoOffRight> m_CmdGrpAutoOffRight;

    /**
     * A public, static instance of a TelemetryOutputter class.
     * 
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this pointer 
     * m_TelemetryOutputter is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static TelemetryOutputter* m_TelemetryOutputter;

    /**
     * A public, static instance of a Video class.
     * 
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this pointer
     * m_Video is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static Video* m_Video;

    /**
     * A public, static instance of a robot tick counter. A robot tick counter
     * is a counter that keeps count of the times the scheduler has been
     * ran on the Robot::RobotPeriodic() method.
     * 
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this variable
     * m_RobotTick is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static uint64_t m_RobotTick;

    /************************ Public Method Prototypes ************************/

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
     * Users should override this method for code which will be called each time
     * a new packet is received from the driver station and the robot is in test
     * mode.
     *
     * @see virtual void frc::IterativeRobotBase::TestPeriodic()
    */
    void TestPeriodic() override;

  private:
 
    /*********************** Private member variables *************************/

    /** Define a sendable chooser for autonomous mode */
    frc::SendableChooser<frc::Command*> autonomous_chooser;

    /** Define a pointer to THE autonomous command that we will be using */
    std::unique_ptr<frc::Command> autonomousCommand;

    /** Define a string for the robot code version message */
    std::string m_RobotCode_version_msg;

    /** Define a string for telemetry debug */
    std::string m_telemetry_debug_msg;

    /*********************** Private Method Prototypes ************************/

    /** Outputs the version information to the console */
    void outputVersionInfoToConsole();

}; // end class Robot

#endif // #ifndef ROBOT_H
