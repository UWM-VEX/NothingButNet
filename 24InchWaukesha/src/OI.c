/*
 * OI.c
 *
 *  Created on: Oct 29, 2015
 *      Author: Erik
 */

#include "main.h"

int OIGetDriveLeft()
{
	return joystickGetAnalog(1, 3);
}

int OIGetDriveRight()
{
	return joystickGetAnalog(1, 2);
}

int OIGetRunShooterFull()
{
	return joystickGetDigital(1, 8, JOY_DOWN);
}

int OIGetRunShooterHalf()
{
	return joystickGetDigital(1, 7, JOY_DOWN);
}

int OIGetReverseShooterFull()
{
	return joystickGetDigital(1, 8, JOY_UP);
}

int OIGetReverseShooterHalf()
{
	return joystickGetDigital(1, 7, JOY_UP);
}

int OIGetDeployRamp()
{
	return (joystickGetDigital(1, 5, JOY_DOWN) && joystickGetDigital(1, 6, JOY_DOWN));
}
