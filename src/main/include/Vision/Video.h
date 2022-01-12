/** ===========================================================================
 * @file   Video.h
 * @brief  This file declares the Video class.
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
 * Copyright (c) 2020 FRC Team #7464 - ORION. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FRC Team #7464 - ORION BSD license file in
 * the root directory of the project.
 *
============================================================================= */

// INCLUDE GUARD - see https://en.wikipedia.org/wiki/Include_guard
// If we have not already defined VIDEO_H...
#ifndef VIDEO_H
// Define VIDEO_H
#define VIDEO_H

/*************************** Local Header Files *******************************/

// Include our Robot constants
#include "RobotConstants.h"

/************************** Library Header Files ******************************/

// Include the string header file
#include <string>

// Include the CameraServer class for camera streaming
#include <cameraserver/CameraServer.h>

/** ****************************************************************************
 * @class   Video
 * @brief   This class defines video for the robot.
 * @author  FRC Team #7464 - ORION
 ******************************************************************************/
class Video
{
  public:

    /** An enumeration of camera directions */
    enum CAMERA_DIRECTION
    { 

      /** The front camera (with Pssh) */
      FRONT,
      /** The back camera (with PAT) */
      BACK

    };

    /************************ Public Method Prototypes ************************/

    /** The constructor for the Video class */
    Video();

    /**
     * Code to set the direction the camera server outputs
     * 
     * @param camera_direction The direction
    */
    void setCameraDirection(CAMERA_DIRECTION camera_direction);

  private:
 
    /*********************** Private member variables *************************/

    /** The front camera */
    cs::UsbCamera m_frontCamera;

    /** The back camera */
    cs::UsbCamera m_backCamera;

    /** The camera server */
    cs::VideoSink m_cameraServer;

    /*********************** Private Method Prototypes ************************/

    /**
     * Initializes a USB Camera for streaming.
     *
     * @param CameraName      The name of the camera to be shown on the
     *                          SmartDashboard.
     * @param CameraDeviceNum The device number of the camera.
    */
    cs::UsbCamera
      InitializeUSBCamera(const std::string CameraName,
                          const int CameraDeviceNum);

    /**
     * Initializes a Switched Camera Server for streaming.
     * 
     * NOTE: Use cs::VideoSink::SetSource(VideoSource source) to select
     * the source of the server.
     *
     * @param ServerName      The name of the camera server to be shown on the
     *                          SmartDashboard.
    */
    cs::VideoSink
      InitializeSwitchedCameraServer(const std::string ServerName);

}; // end class Video

#endif // #ifndef VIDEO_H
