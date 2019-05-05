/** ===========================================================================
 * @file   MainPage.h
 * @brief  This file is not part of the software, but contains the main page
 *         information (on index.html) using Doxygen.
 *
 * COPYRIGHT NOTICES:
 *
 * Copyright (c) 2019 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/**
 * @mainpage FRC Team 7464 - O.R.I.O.N.: Code for Sirius (2019 Season)
 *
 * @section intro_sec Introduction
 *
 * This is the documentation for the software code written for Sirius, the
 * <a href="https://orionfrc.wixsite.com/robotics">Oklahoma Robotic Institute
 * of Norman</a>'s (O.R.I.O.N.'s) entry for competition in the 
 * <a href="https://www.firstinspires.org/">FIRST</a> Robotic
 * Competition (FRC) 2019 season.
 *
 * This documentation was created by adding special 
 * <a href="https://en.wikipedia.org/wiki/Comment_(computer_programming)">
 * comments</a> to our computer code for Sirius, which is written in
 * <a href="https://en.wikipedia.org/wiki/C%2B%2B">C++</a>. A program 
 * called
 * <a href="http://www.doxygen.nl/">Doxygen</a> is used to examine the
 * <a href="https://en.wikipedia.org/wiki/Source_code">source code</a> for
 * these special comments, and generates this documentation.
 *
 * @section copyright_sec Copyright Notices
 *
 * Some portions:
 *
 * Copyright (c) 2019 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the 
 * <a href="../BSD_License_for_FRC_7464_ORION_code.txt">
 * FRC Team #7464 - ORION BSD license file</a> in the root directory of
 * the project.
 *
 * Some portions:
 *
 * Copyright (c) 2017-2018 FIRST. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the 
 * <a href="../BSD_License_for_WPILib_code.txt">
 * FIRST BSD license file</a> in the root directory of the project.
 *
*/

/*
 * @section overview_sec Robot Overview
 *
 * Below is an overview of the robot.
 *
 * @subsection hw_subsec Hardware
 *
 * Hardware can be defined as the physical parts of the robot that
 * make the robot work.
 *
 * @subsubsection elecHW_subsubsec Electrical
 *
 * Electrical hardware are items that use electricity to make the 
 * electronics of the robot work.
 *
 * @paragraph batt_Elec_para The Battery
 *
 * The battery provides electrical power to the entire robot. For
 * FRC competitions, we are limited to a battery with the following
 * constraints:
 *
 * Nominal Voltage: 12 Volts
 * Capacity (20 Hour Discharge Rate): 17.0 Ah minimum to 18.2 Ah maximum.
 * Nominal Dimensions: 7.1" x 3.0" x 6.6"
 * Nominal Weight: 11.0 pounds to 14.5 pounds
 * Terminal Style: Nut and bolt
 *
 * @paragraph CB_Elec_para The 120 Amp Circuit Breaker
 *
 * @paragraph PDP_Elec_para The Power Distribution Panel
 * 
 * The power distribution panel, also known as the PDP, receives power
 * from the battery, and distributes that power to the various 
 * electrical systems in the robot.
 *
 * @paragraph VRM_Elec_para The Voltage Regulator Module
 *
 * @paragraph roboRIO_Elec_para The roboRIO
 * 
 * @paragraph CAN_Elec_para The Controller Area Network (CAN) Bus
 * 
 * @paragraph USB_Elec_para The Universal Serial Bus (USB)
 * 
 * @paragraph ether_Elec_para Ethernet
 *
 * @paragraph radio_Elec_para The Radio
 * 
 * @paragraph MC_Elec_para The Motor Controllers
 *
 * @subsubsection Electromechanical
 *
 * <a href="https://en.wikipedia.org/wiki/Electromechanics">
 * Electromechanical</a> hardware is hardware that provides input
 * and/or output to/from electrical signals to/from mechanical
 * movement.
 *
 * @paragraph motor_EM_para Motors
 * 
 * @paragraph pot_EM_para The Potentiometer
 *
 * A 
 * <a href="https://en.wikipedia.org/wiki/Potentiometer">
 * potentiomenter</a>, as used on our robot,
 * is "a three terminal resistor with a rotating contact
 * that forms an adjustable 
 * <a href="https://en.wikipedia.org/wiki/Voltage_divider">
 * voltage divider</a>.
 *
 * By allowing a part of the robot that turns to turn
 * the potentiometer as well, and using some voltage outputs
 * and inputs on the roboRIO, we can tell where the 
 * potentiometer has been turned, and thus the tell where
 * the part that turns is located.
 *
 * @subsubsection Mechanical
 *
 * @paragraph frame_Mech_para The Frame
 *
 * @paragraph wheels_Mech_para The Wheels
 *
 * @paragraph CaptHook_Mech_para Capt. Hook
 *
 * @subsection sw_subsec Software
 *
 * @subsubsection robot_SW_subsubsec The Robot
 *
 * @subsubsection OI_SW_subsubsec The Operator Interface
 *
 * @subsubsection subsytems_subsubsec Subsytems
 *
 * @paragraph drive_train_SubSys_para Drive Train
 *
 * @paragraph CaptHook_SubSys_para Capt. Hook
 *
 * @subsubsection command_subsubsec Commands
 *
 * @paragraph arcade_Command_para Drive Arcade Mode
 *
 * @paragraph tank_Command_para Drive Tank Mode
 *
 * @paragraph GrabHatchPanel_Command_para Grab Hatch Panel
 *
 * @paragraph ReleaseHatchPanel_Command_para Release Hatch Panel
 *
 * @paragraph Grab_Command_para Grab Hatch Panel
 *
 * @paragraph Release_Command_para Release Hatch Panel
 *
 * @subsubsection Utilities_subsubsec Utilities
 *
 * @paragraph outputTelemetry_Utilities_para Output Telemetry
 *
 * Our robot consists of ... later..
 *
*/
