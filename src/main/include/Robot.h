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
 * Copyright (c) 2019 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

// Preprocessor directive to have this file only be included once in the
//  compilation
// See https://en.wikipedia.org/wiki/Pragma_once for details
#pragma once

/*************************** Local Header Files *******************************/

// Include our constants header file
#include "RobotConstants.h"

// Include the SubSysDriveTrain class header file, which is our drivetrain
#include "subsystems/SubSysDriveTrain.h"

// If we are not using the PID controller for Capt. Hook
#if !USE_PID_CAPT_HOOK

// Include the SubSysCaptHook class header file, which is our hatch panel
//   mover
#include "subsystems/SubSysCaptHook.h"

#endif // #if !USE_PID_CAPT_HOOK

// If we are using Capt. Hook with a PID controller...
#if USE_PID_CAPT_HOOK

// Include the PIDSubSysCaptHook class header file, which is our hatch panel
//   mover
#include "subsystems/PIDSubSysCaptHook.h"

#endif // #if USE_PID_CAPT_HOOK

// Include the operator interface (OI) class header file, which allows us
//  to define our interface to the operator (driver)
#include "OI.h"

// Include the CmdDriveArcadeStyle class header file, which declares the
//   command to drive the robot arcade style
#include "commands/CmdDriveArcadeStyle.h"

// Include the CmdDriveTankStyle class header file, which declares the
//   command to drive the robot tank style
#include "commands/CmdDriveTankStyle.h"

// Include the TelemetryOutputter class header file
#include "Telemetry/TelemetryOutputter.h"

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
#include "frc/livewindow/LiveWindow.h"

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
     * A public, static instance of a SubSysDriveTrain class.
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     *   m_subSysDriveTrain is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static std::shared_ptr<SubSysDriveTrain> m_subSysDriveTrain;

// If we are not using the PID controller for Capt. Hook
#if !USE_PID_CAPT_HOOK

    /**
     * A public, static instance of a SubSysCaptHook class.
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     * m_subSysCaptHook is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static std::shared_ptr<SubSysCaptHook> m_subSysCaptHook;

#endif // #if !USE_PID_CAPT_HOOK

// If we are using Capt. Hook with a PID controller...
#if USE_PID_CAPT_HOOK

    /**
     * A public, static instance of a PIDSubSysCaptHook class.
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     * m_PIDsubSysCaptHook is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static std::shared_ptr<PIDSubSysCaptHook> m_PIDsubSysCaptHook;

#endif // #if USE_PID_CAPT_HOOK

    /**
     * A public, static instance of an OI (operator interface).
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
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     * m_cmdDriveArcadeStyle is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static std::shared_ptr<CmdDriveTankStyle> m_cmdDriveTankStyle;

    /**
     * A public, static instance of a TelemetryOutputter class.
     * This is a member variable, hence the m_ in front of the name.
     * The static modifier means that this example operator interface instance
     * m_TelemetryOutputter is shared between all Robot instances.
     * Since this is static, this is only the declaration.
     * The definition for the member variable must be done outside the
     * class.
    */
    static TelemetryOutputter* m_TelemetryOutputter;

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

    /*********************** Private Method Prototypes ************************/

    /** Outputs the version information to the console */
    void outputVersionInfoToConsole();

    /**
     * Initializes a USB Camera for streaming.
     *
     * @param CameraName      The name of the camera to be shown on the
     *                          SmartDashboard.
     * @param CameraDeviceNum The device number of the camera.
    */
    void InitializeUSBCamera(const std::string CameraName,
                             const int CameraDeviceNum);

}; // end class Robot
