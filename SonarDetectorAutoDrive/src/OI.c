/*
 * OI.c
 *
 *  Created on: Jul 27, 2015
 *      Author: Erik
 */

#include "main.h"

int OIGetDriveMagnitude()
{
	return joystickGetAnalog(1, 3);
}

int OIGetDriveRotation()
{
	return joystickGetAnalog(1, 1);
}
