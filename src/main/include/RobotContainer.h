/** ===========================================================================
 * @file   RobotContainer.h
 * @brief  This file declares the RobotContainer class.
 *
 * The RobotContainer class holds robot subsystems and commands, and is where 
 * most of the declarative robot setup (e.g. button bindings) is performed.
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
 * Copyright (c) 2019-2020 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

// INCLUDE GUARD - see https://en.wikipedia.org/wiki/Include_guard
// If we have not already defined ROBOTCONTAINER_H...
#ifndef ROBOTCONTAINER_H
// Define ROBOTCONTAINER_H
#define ROBOTCONTAINER_H

/*************************** Local Header Files *******************************/

// The header that defines the hardware configuration of the robot
#include "RobotMap.h"

// The header file for the robot tick class
#include "RobotTick.h"

// PERIPHERALS

// The header for the NavX MXP AHRS class
#include "AHRS.h"

// OPERATOR INTERFACE (OI)

// The header for the Human Interface Device (HID) constants 
#include "HIDs/HID_Constants.h"
// The header for some HID utility functions
#include "HIDs/HID_Utility_Fcns.h"
// The header for the Logitech F310 game controller
#include "HIDs/LogitechF310.h"
// The header for a SmartDashboard/Shuffleboard chooser
#include <frc/smartdashboard/SendableChooser.h>

// SUBSYSTEMS

// The header for the drive train
#include "subsystems/SubSysDriveTrain.h"
// The header for the Hans/Franz arms subsystem
#include "subsystems/SubSysHansFranzArms.h"
// The header for the Hans/Franz Muscles
#include "subsystems/SubSysHansFranzMuscles.h"
// The header for the PAT Turner subsystem
#include "subsystems/SubSysPATTurner.h"
// The header for the PID Pssh subsystem
#include "subsystems/PIDSubSysPssh.h"

// COMMAND AND COMMAND GROUPS

// AUTONOMOUS COMMANDS
// The header for the default autonomous command
#include "commandGroups/Autonomous/CmdGrpAutoDefault.h"
// The header for the defensive center autonomous command
#include "commandGroups/Autonomous/CmdGrpAutoDefCenter.h"
// The header for the defensive left autonomous command
#include "commandGroups/Autonomous/CmdGrpAutoDefLeft.h"
// The header for the defensive right autonomous command
#include "commandGroups/Autonomous/CmdGrpAutoDefRight.h"
// The header for the offensive center autonomous command
#include "commandGroups/Autonomous/CmdGrpAutoOffCenter.h"
// The header for the offensive left autonomous command
#include "commandGroups/Autonomous/CmdGrpAutoOffLeft.h"
// The header for the offensive right autonomous command
#include "commandGroups/Autonomous/CmdGrpAutoOffRight.h"

// DRIVE TRAIN
// The header for driving in arcade style
#include "commands/DriveTrain/CmdDriveArcadeStyle.h"
// The header for driving in tank style
#include "commands/DriveTrain/CmdDriveTankStyle.h"
// The header for toggling drive direction
#include "commands/DriveTrain/CmdToggleDriveDirection.h"
// The header file for disabling smoothing mode
#include "commands/DriveTrain/CmdDisableSmoothingMode.h"
// The header file for enabling smoothing mode
#include "commands/DriveTrain/CmdEnableSmoothingMode.h"
// The header for toggling smoothing mode
#include "commands/DriveTrain/CmdToggleSmoothingMode.h"
// The header for disabling turbo mode
#include "commands/DriveTrain/CmdDisableTurboMode.h"
// The header for enabling turbo mode
#include "commands/DriveTrain/CmdEnableTurboMode.h"
// The header to zero out the AHRS yaw
#include "commands/DriveTrain/CmdZeroAHRSYaw.h"
// The header to reset the AHRS yaw
#include "commands/DriveTrain/CmdResetAHRSYaw.h"

// PAT
// The header for the command to turn Wheel of Fortune counter-clockwise
#include "commands/PAT/CmdTurnWoFCCW.h"
// The header for the command to turn Wheel of Fortune clockwise
#include "commands/PAT/CmdTurnWoFCW.h"

// HANS/FRANZ
// The header for the command group for Hans and Franz
#include "commandGroups/HansAndFranz/CmdGrpEnableHansAndFranz.h"

// HANS/FRANZ ARMS
// The header for the command to enable Hans/Franz arms
#include "commands/HansAndFranzArms/CmdEnableHansFranzArms.h"
// The header for the command to move Hans/Franz arms
#include "commands/HansAndFranzArms/CmdMoveHansFranzArms.h"

// HANS/FRANZ MUSCLES
// The header for disabling Hans and Franz muscles
#include "commands/HansAndFranzMuscles/CmdDisableHansFranzMuscles.h"
// The header for enabling Hans and Franz muscles
#include "commands/HansAndFranzMuscles/CmdEnableHansFranzMuscles.h"
// The header for extending Hans and Franz muscles
#include "commands/HansAndFranzMuscles/CmdExtendHansFranzMuscles.h"
// The header for retracting Hans and Franz muscles
#include "commands/HansAndFranzMuscles/CmdRetractHansFranzMuscles.h"

// PID PSSH
// The header to putting Pssh into dump mode
#include "commands/PIDPssh/CmdDump.h"
// The header to putting Pssh into load mode
#include "commands/PIDPssh/CmdLoad.h"
// The header to putting Pssh into travel mode
#include "commands/PIDPssh/CmdTravel.h"

// TELEMETRY

// Include the header for telemetry output
#include "Telemetry/TelemetryOutputter.h"

/************************** Library Header Files ******************************/

// For the joystick
#include <frc/Joystick.h>
// For the joystick buttons (NEW commands)
#include <frc2/command/button/JoystickButton.h>
// For the joystick POV (NEW commands)
#include <frc2/command/button/POVButton.h>
// The header for the NEW commands 
#include <frc2/command/Command.h>

// Include the SmartDashboard class header file, which allows us to transmit
//   robot data to the operator console
// See:
// https://wpilib.screenstepslive.com/s/currentCS/m/smartdashboard
#include <frc/smartdashboard/SmartDashboard.h>

// Include the Shuffleboard class header file, similar to SmartDashboard
#include <frc/shuffleboard/Shuffleboard.h>

/** ****************************************************************************
 * @class   RobotContainer
 * @brief   This class is where the bulk of the robot should be declared.
 *          Since Command-based is a "declarative" paradigm, very little robot
 *          logic should actually be handled in the {@link Robot} periodic
 *          methods (other than the scheduler calls).  Instead, the structure
 *          of the robot (including subsystems, commands, and button mappings)
 *          should be declared here.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class RobotContainer {

  public:

    /********************** PUBLIC MEMBER FUNCTIONS ***************************/

    /** The constructor for the RobotContainer class */  
    RobotContainer();

    /** The destructor for the RobotContainer class */
    ~RobotContainer();

    /** A "getter" for getting the chosen autonomous command */
    frc2::Command* GetAutonomousCommand();

    /** A method to output the telemetry */
    void OutputTelemetryToSmartDashboard();

    /** A method to increment the robot tick counter */
    void IncrementRobotTick();

    /** A method to get the # of robot tick elapsed */
    uint64_t GetRobotTick();

    /** A method to start measuring the telemetry output time */
    void StartTelemetryOutputTimeMeasurement();

    /** A method to finish measuring the telemetry output time */
    void FinishTelemetryOutputTimeMeasurement();

  private:

    /********************* PRIVATE MEMBER FUNCTIONS ***************************/

    /** Configure the buttons that commands are bound */
    void ConfigureButtonBindings();

    /** Configure the SmartDashboard/Shuffleboard commands */
    void ConfigureXBoardCommands();

    /********************* PRIVATE MEMBER VARIABLES ***************************/

    /** The tick for the robot period */
    RobotTick m_RobotPeriodicTick;

    // PERIPHERALS

    /** An AHRS, using the NavX MXP */
    AHRS m_AHRS{k_navx_mxp_imu_port};

    // OI/HIDs

    /** Instantiating the primary Logitech F310 joystick,
     *  initialized using a member initializer list */
    frc::Joystick m_PrimaryJoystick{k_Joystick0DeviceNumber};

    /** Instantiating the secondary Logitech F310 joystick,
     *   initialized using a member initializer list */
    frc::Joystick m_SecondaryJoystick{k_Joystick1DeviceNumber};

    /** A pointer to the chooser for the autonomous routines */
    frc::SendableChooser<frc2::Command*> m_autonomous_chooser;

    // The robot's subsystems and commands are declared here...

    // SUBSYSTEMS

    /** The drive train subsystem */
    SubSysDriveTrain m_subSysDriveTrain;

    /** The Wheel of Fortune (WoF) PAT Turner subsystem */
    SubSysPATTurner m_subSysPATTurner;

    /** The Hans and Frans Arm subsystem */
    SubSysHansFranzArms m_subSysHansFranzArms;

    /** The Hans and Frans Muscles subsystem */
    SubSysHansFranzMuscles m_subSysHansFranzMuscles;

    /** The PID Pssh subsystem */
    PIDSubSysPssh m_PIDsubSysPssh;

    // COMMAND AND COMMAND GROUPS

    // AUTONOMOUS COMMANDS

    /** The default autonomous command */
    CmdGrpAutoDefault m_cmdGrpAutoDefault{&m_subSysDriveTrain, &m_AHRS};
    /** The center defensive autonomous command */
    CmdGrpAutoDefCenter m_cmdGrpAutoDefCenter{&m_subSysDriveTrain, &m_AHRS};
    /** The left defensive autonomous command */
    CmdGrpAutoDefLeft m_cmdGrpAutoDefLeft{&m_subSysDriveTrain, &m_AHRS};
    /** The right defensive autonomous command */
    CmdGrpAutoDefRight m_cmdGrpAutoDefRight{&m_subSysDriveTrain, &m_AHRS};
    /** The center offensive autonomous command */
    CmdGrpAutoOffCenter m_cmdGrpAutoOffCenter{&m_subSysDriveTrain, &m_AHRS};
    /** The left offensive autonomous command */
    CmdGrpAutoOffLeft m_cmdGrpAutoOffLeft{&m_subSysDriveTrain, &m_AHRS};
    /** The right offensive autonomous command */
    CmdGrpAutoOffRight m_cmdGrpAutoOffRight{&m_subSysDriveTrain, &m_AHRS};

    // DRIVE TRAIN COMMANDS

    /** Command to drive arcade style */
    CmdDriveArcadeStyle m_cmdDriveArcadeStyle{&m_subSysDriveTrain,
                                              &m_PrimaryJoystick};
    /** Command to drive tank style */
    CmdDriveTankStyle m_cmdDriveTankStyle{&m_subSysDriveTrain,
                                          &m_PrimaryJoystick};
    /** Command to toggle drive direction */
    CmdToggleDriveDirection m_cmdToggleDriveDirection{&m_subSysDriveTrain};
    /** Command to disable smoothing mode */
    CmdDisableSmoothingMode m_cmdDisableSmoothingMode{&m_subSysDriveTrain};
    /** Command to enable smoothing mode */
    CmdEnableSmoothingMode m_cmdEnableSmoothingMode{&m_subSysDriveTrain};
    /** Command to toggle smoothing mode */
    CmdToggleSmoothingMode m_cmdToggleSmoothingMode{&m_subSysDriveTrain};
    /** Command to disable turbo mode */
    CmdDisableTurboMode m_cmdDisableTurboMode{&m_subSysDriveTrain};
    /** Command to enable turbo mode */
    CmdEnableTurboMode m_cmdEnableTurboMode{&m_subSysDriveTrain};
    /** Command to zero out the AHRS yaw */
    CmdZeroAHRSYaw m_cmdZeroAHRSYaw{&m_subSysDriveTrain, &m_AHRS};
    /** Command to reset the AHRS yaw */
    CmdResetAHRSYaw m_cmdResetAHRSYaw{&m_subSysDriveTrain, &m_AHRS};

    // PAT TURNER SUBSYSTEM COMMANDS

    /** Command to turn WoF counter clockwise */
    CmdTurnWoFCCW m_cmdTurnWofCCW{&m_subSysPATTurner,&m_SecondaryJoystick};
    /** Command to turn WoF clockwise */
    CmdTurnWoFCW m_cmdTurnWofCW{&m_subSysPATTurner,&m_SecondaryJoystick};

    // HANS/FRANZ ARMS SUBSYSTEM COMMANDS

    /** 
     * Command to move Hans/Franz arms
     * 
     * NOTE: Must be instantiated before m_cmdEnableHansFranzArms!
     */
    CmdMoveHansFranzArms m_cmdMoveHansFranzArms{&m_subSysHansFranzArms,
                                                &m_SecondaryJoystick};
    /** Command to enable Hans/Franz Arms */
    CmdEnableHansFranzArms m_cmdEnableHansFranzArms{&m_subSysHansFranzArms,
                                                    &m_cmdMoveHansFranzArms};

    // HANS/FRANZ MUSCLES SUBSYSTEM COMMANDS

    /** Command to disable Hans and Franz muscles */
    CmdDisableHansFranzMuscles 
      m_cmdDisableHansFranzMuscles{&m_subSysHansFranzMuscles};
    /** Command to enable Hans and Franz muscles */
    CmdEnableHansFranzMuscles 
      m_cmdEnableHansFranzMuscles{&m_subSysHansFranzMuscles};
    /** Command to extend Hans and Franz muscles */
    CmdExtendHansFranzMuscles 
      m_cmdExtendHansFranzMuscles{&m_subSysHansFranzMuscles};
    /** Command to retract Hans and Franz muscles */
    CmdRetractHansFranzMuscles 
      m_cmdRetractHansFranzMuscles{&m_subSysHansFranzMuscles};

    // HANS/FRANZ ARMS/MUSCLES COMMANDGROUPS

    /** Command Group to enable Hans and Franz Arms and Muscles */
    CmdGrpEnableHansAndFranz
      m_cmdGrpEnableHansAndFranz{&m_subSysHansFranzArms,
                                 &m_cmdMoveHansFranzArms,
                                 &m_subSysHansFranzMuscles};

    // PID PSSH COMMANDS

    /** Command to put Pssh in dump mode */
    CmdDump m_cmdDump{&m_PIDsubSysPssh};
    /** Command to put Pssh in load mode */
    CmdLoad m_cmdLoad{&m_PIDsubSysPssh};
    /** Command to put Pssh in travel mode */
    CmdTravel m_cmdTravel{&m_PIDsubSysPssh};

    // TELEMETRY

    /** The time we started the telemetry output, in microseconds (usec) */
    uint64_t m_FPGATimeStart;
    /** The time we ended the telemetry output, in microseconds (usec) */
    uint64_t m_FPGATimeEnd;
    /** The elapsed time of the telemetry output, in microseconds (usec) */
    uint64_t m_FPGATimeElapsed;
    /** The elapsed time of the telemetry output, in milliseconds (msec, ms) */
    double m_TelemetryOutputTimeMS;
    /** The maximum elapsed time of the telemetry output, in milliseconds (msec, ms) */
    double m_MaxTelemetryOutputTimeMS = 0.0;
    /** The minimum elapsed time of the telemetry output, in milliseconds (msec, ms) */
    double m_MinTelemetryOutputTimeMS = 9999.0;
    /** A boolean to tell us when to output the telemetry time */
    bool m_output_telemetry_time = false;

    /** The telemetry outputter */
    TelemetryOutputter m_TelemetryOutputter{
      &m_RobotPeriodicTick,
      &m_AHRS,
      &m_subSysDriveTrain,
      &m_PIDsubSysPssh,
      &m_subSysHansFranzArms,
      &m_subSysHansFranzMuscles
    };

}; // end class RobotContainer

#endif // #ifndef ROBOTCONTAINER_H
