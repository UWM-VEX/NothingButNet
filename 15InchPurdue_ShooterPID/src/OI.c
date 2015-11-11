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

int OIGetIntake1In()
{
	return joystickGetDigital(1, 8, JOY_DOWN);
}

int OIGetIntake1Out()
{
	return joystickGetDigital(1, 8, JOY_UP);
}

int OIGetIntake2In()
{
	return joystickGetDigital(1, 7, JOY_DOWN);
}

int OIGetIntake2Out()
{
	return joystickGetDigital(1, 7, JOY_UP);
}

int OIShooterOn()
{
	return joystickGetDigital(1, 6, JOY_DOWN);
}

int OIShooterOff()
{
	return joystickGetDigital(1, 5, JOY_DOWN);
}

int OIShooterUp()
{
	return joystickGetDigital(1, 6, JOY_UP);
}

int OIShooterDown()
{
	return joystickGetDigital(1, 5, JOY_UP);
}
