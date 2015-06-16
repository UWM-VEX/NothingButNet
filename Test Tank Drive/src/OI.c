/*
 * OI.c
 *
 *  Created on: Feb 20, 2015
 *      Author: Erik
 */
#include "main.h"

/**
 * Returns the output from the joystick for the magnitude of the drive.
 */
int OIGetDriveMagnitude()
{
	return joystickGetAnalog(1,3);
}

/**
 * Returns the output from the joystick for the rotation of the drive.
 */
int OIGetDriveRotation()
{
	return joystickGetAnalog(1,4);
}
