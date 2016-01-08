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
	if(numJoysticks == 2)
	{
		return joystickGetDigital(1, 6, JOY_DOWN) ||
				joystickGetDigital(2, 8, JOY_DOWN);
	}
	else
	{
		return joystickGetDigital(1, 8, JOY_DOWN);
	}

}

int OIGetIntake1Out()
{
	if(numJoysticks == 2)
	{
		return joystickGetDigital(1, 6, JOY_UP)
				|| joystickGetDigital(2, 8, JOY_UP);
	}
	else
	{
		return joystickGetDigital(1, 8, JOY_UP);
	}
}

int OIGetIntake2In()
{
	if(numJoysticks == 2)
	{
		return joystickGetDigital(1, 5, JOY_DOWN) ||
				joystickGetDigital(2, 7, JOY_DOWN);
	}
	else
	{
		return joystickGetDigital(1, 7, JOY_DOWN);
	}
}

int OIGetIntake2Out()
{
	if(numJoysticks == 2)
	{
		return joystickGetDigital(1, 5, JOY_UP) ||
				joystickGetDigital(2, 7, JOY_UP);
	}
	else
	{
		return joystickGetDigital(1, 7, JOY_UP);
	}
}

int OIShooterOn()
{
	return joystickGetDigital(numJoysticks, 6, JOY_DOWN);
}

int OIShooterOff()
{
	return joystickGetDigital(numJoysticks, 5, JOY_DOWN);
}

int OIShooterUp()
{
	return joystickGetDigital(numJoysticks, 6, JOY_UP);
}

int OIShooterDown()
{
	return joystickGetDigital(numJoysticks, 5, JOY_UP);
}

int OIBallStopperUp()
{
	return joystickGetDigital(1, 8, JOY_UP);
}

int OIBallStopperDown()
{
	return joystickGetDigital(1, 8, JOY_DOWN);
}
