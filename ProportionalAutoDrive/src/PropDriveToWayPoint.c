/*
 * PropDriveToWayPoint.c
 *
 *  Created on: Jul 27, 2015
 *      Author: Erik
 */

#include "main.h"

PropDriveToWayPoint initPropDriveToWayPoint(Drive drive, double distance, int rotation)
{
	PropDriveToWayPoint newStep = {drive, 12.7, .750, distance, rotation, 127, 10, 0, 0, 0};
	return newStep;
}

void propDriveToWayPointSetMagnitudeKP(PropDriveToWayPoint *step, double kP)
{
	(*step).magnitudeKP = kP;
}

void propDriveToWayPointSetRotationKP(PropDriveToWayPoint *step, double kP)
{
	(*step).rotationKP = kP;
}

void propDriveToWayPointSetMaxSpeed(PropDriveToWayPoint *step, int speed)
{
	(*step).maxSpeed = speed;
}

void propDriveToWayPointSetMinSpeed(PropDriveToWayPoint *step, int speed)
{
	(*step).minSpeed = speed;
}

void propDriveToWayPoint(PropDriveToWayPoint *step)
{
	int goodDistance = 0;
	int goodRotation = 0;
	int magnitude = 0;
	int rotation = 0;

	int forward = (*step).distance >= 0;
	int turnRight = (*step).rotation >= 0;

	if(autonomousInfo.step != autonomousInfo.lastStep)
	{
		(*step).initialDistance = (encoderGet((*step).drive.leftEncoder) +
				encoderGet((*step).drive.rightEncoder)) / 2;
		(*step).initialAngle = gyroGet((*step).drive.gyro);
	}

	int currentDistance = (encoderGet((*step).drive.leftEncoder) +
			encoderGet((*step).drive.rightEncoder)) / 2;
	int currentAngle = gyroGet((*step).drive.gyro);

	int deltaDistance = currentDistance - (*step).initialDistance;
	int deltaAngle = currentAngle - (*step).initialAngle;

	double distanceError = (*step).distance - deltaDistance;
	int angleError = (*step).rotation - deltaAngle;

	if(absDouble(distanceError) < .5)
	{
		magnitude = (forward) ? -1 : 1;
		goodDistance = 1;
	}
	else
	{
		magnitude = (int) (distanceError * (*step).magnitudeKP);

		if(forward) magnitude += (*step).minSpeed;
		else magnitude -= (*step).minSpeed;

		magnitude = limit(magnitude, (*step).maxSpeed, -(*step).minSpeed);
	}

	if(abs(angleError) < 4)
	{
		rotation = 0;
		goodRotation = 1;
	}
	else
	{
		rotation = (int) (angleError * (*step).rotationKP);

		if(turnRight) rotation += (*step).minSpeed;
		else rotation -= (*step).minSpeed;

		rotation = limit(rotation, (*step).maxSpeed, -(*step).minSpeed);
	}

	arcadeDrive((*step).drive, magnitude, rotation);

	(*step).isFinished = goodDistance && goodRotation;
}
