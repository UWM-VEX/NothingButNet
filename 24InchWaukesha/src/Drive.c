/*
 * Drive.c
 *
 *  Created on: Oct 29, 2015
 *      Author: Erik
 */

#include "main.h"

Drive initDrive(PantherMotor frontLeft, PantherMotor frontRight,
		PantherMotor rearLeft, PantherMotor rearRight)
{
	Drive newDrive = {frontLeft, frontRight, rearLeft, rearRight};
	return newDrive;
}

void tankDrive(Drive drive, int left, int right)
{
	int limitedLeft = limit(left, 127, -127);
	int limitedRight = limit(right, 127, -127);

	setPantherMotor(drive.frontLeft, limitedLeft);
	setPantherMotor(drive.frontRight, limitedRight);
	setPantherMotor(drive.rearLeft, limitedLeft);
	setPantherMotor(drive.rearRight, limitedRight);
}
