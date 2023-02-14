/** ===========================================================================
 * @file   Video.cpp
 * @brief  This file defines the Video class.
 *
 * The Video class defines the video used for the robot.
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
 * Copyright (c) 2020-2022 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

/*************************** Local Header Files *******************************/

// Include the Video class header file
#include "Vision/Video.h"

// Include out robot map header file
#include "RobotMap.h"

/************************** Library Header Files ******************************/

// Include the I/O stream class, so we can write to the console
#include <iostream>

/******************* Public member function definitions **********************/

// The constructor for the Video class
Video::Video() 
{

  // Initialize the Front USB camera for streaming
  m_frontCamera = 
    InitializeUSBCamera(k_FrontCamera, k_FrontCameraDeviceNumber);

  // Initialize the Back USB camera for streaming
  m_backCamera = 
    InitializeUSBCamera(k_BackCamera, k_BackCameraDeviceNumber);

  // 
  m_cameraSelection = 
    nt::NetworkTableInstance::
      GetDefault().GetTable("")->GetEntry("CameraSelection");

  // Initialize the switched camera server for streaming
//  m_cameraServer = 
//    InitializeSwitchedCameraServer(k_CameraServer);

  // Set the front camera connection strategy
  m_frontCamera.SetConnectionStrategy(
    cs::VideoSource::ConnectionStrategy::kConnectionKeepOpen);

  // Set the back camera connection strategy
  m_backCamera.SetConnectionStrategy(
    cs::VideoSource::ConnectionStrategy::kConnectionKeepOpen);

  // Initially use the front camera
  m_cameraSelection.SetString(m_frontCamera.GetName());

  // Set the front camera to be the initial source for the server
//  m_cameraServer.SetSource(m_frontCamera);
  
} // end Video::Video()

// Set the camera direction
void Video::setCameraDirection(Video::CAMERA_DIRECTION camera_direction)
{
  // Switch on the camera direction
  switch (camera_direction)
  {

    // Front
    case Video::CAMERA_DIRECTION::FRONT:
//      m_cameraServer.SetSource(m_frontCamera);
      m_cameraSelection.SetString(m_frontCamera.GetName());
      break;

    // Back
    case Video::CAMERA_DIRECTION::BACK:
//      m_cameraServer.SetSource(m_backCamera);
      m_cameraSelection.SetString(m_backCamera.GetName());
      break;
      
    default:
//      m_cameraServer.SetSource(m_frontCamera);
      m_cameraSelection.SetString(m_frontCamera.GetName());
      
  } // end switch (camera_direction)

} // end Video::setCameraDirection(...)

/****************** Private member function definitions ***********************/

// Initialize a USB camera
cs::UsbCamera
  Video::InitializeUSBCamera(const std::string CameraName,
                             const int CameraDeviceNum) 
{

  // Start Automatic Capture of the specified camera
  // returning a reference to the camera
  return(
    frc::CameraServer::StartAutomaticCapture(
      CameraName,
      CameraDeviceNum));

} // end Video::InitializeUSBCamera(const std::string, const int)

// Initializes a Switched Camera Server for streaming.
cs::VideoSink
  Video::InitializeSwitchedCameraServer(const std::string ServerName)
{

  // Start the Switched camera server, returning a reference
  // of the server (a VideoSink)
  return(
    frc::CameraServer::AddSwitchedCamera(ServerName));

} // end cs::VideoSink Video::InitializeSwitchedCameraServer(...)
