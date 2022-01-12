/** ===========================================================================
 * @file   SubSysHansFranzMuscles.h
 * @brief  This file declares the SubSysHansFranzMuscles class, which is a
 *         subsystem of the robot.
 *
 * The SubSysHansFranzMuscles class is used to activate the shields by
 * climbing onto the shield generator switch. This class controls the 
 * pneumatics.
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
// If we have not already defined SUBSYSHANSFRANZMUSCLES_H...
#ifndef SUBSYSHANSFRANZMUSCLES_H
// Define SUBSYSHANSFRANZMUSCLES_H
#define SUBSYSHANSFRANZMUSCLES_H

/*************************** Local Header Files *******************************/

// Include the robot constants header
#include "RobotConstants.h"

/************************** Library Header Files ******************************/

// Include the NEW(2020) subsystem base class header file
#include <frc2/command/SubsystemBase.h>

// Include the header file for a compressor
#include <frc/Compressor.h>

// Include the header file for double solenoids
#include <frc/DoubleSolenoid.h>

// Include the DriverStation, for errors and warnings
#include <frc/DriverStation.h>

/** ****************************************************************************
 * @class   SubSysHansFranzMuscles
 * @brief   This class declares our lift robot mechanism subsystem.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class SubSysHansFranzMuscles : public frc2::SubsystemBase {

  public:

    /********************** PUBLIC MEMBER FUNCTIONS ***************************/

    /** The default constructor for the SubSysHansFranzMuscles class */
    SubSysHansFranzMuscles();

    /** The default destructor for the SubSysHansFranzMuscles class */
    ~SubSysHansFranzMuscles();

    /** The periodic method for HansFranz muscles */
    void Periodic() override;

    /** Method to disable Hans and Franz muscles */
    void DisableHansFranzMuscles();

    /** Method to extend Hans/Franz muscles (cylinder rod is out when done) */
    void ExtendHansFranzMuscles();

    /** Method to retract Hans/Franz muscles (cylinder rod is in when done) */
    void RetractHansFranzMuscles();

    /** Method to enable Hans and Franz muscles */
    void EnableHansFranzMuscles();

    /** 
     * Method to get if Hans and Franz muscles are enabled 
     * 
     * @return true=Hans/Franz Muscles enabled, false=not enabled 
     */
    bool AreHansFranzMusclesEnabled();

    /** 
     * Method to get Hans and Franz muscles state
     * 
     * @return String telling state of Hans/Franz muscles
     */
    std::string GetHansFranzMusclesState();

  private:
    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities

    /********************* PRIVATE MEMBER FUNCTIONS ***************************/

    /********************* PRIVATE MEMBER VARIABLES ***************************/

    /** A pointer to a compressor */
    frc::Compressor* m_compressor;

    /** A pointer to the double solenoid for Hans (left side) */
    frc::DoubleSolenoid* m_Hans_DoubleSolenoid;

    /** A pointer to the double solenoid for Franz (right side) */
    frc::DoubleSolenoid* m_Franz_DoubleSolenoid;

    /** A boolean to indicate that Hans and Franz muscles are enabled */
    bool m_HansFranzMusclesEnabled;

    /** A string to hold the state of Hans' and Franz's muscles */
    std::string m_HansFranzMusclesState;

}; // end class SubSysHansFranzMuscles

#endif // #ifndef SUBSYSHANSFRANZMUSCLES_H
