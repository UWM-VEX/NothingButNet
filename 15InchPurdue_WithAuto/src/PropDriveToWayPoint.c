/*
 * PropDriveToWayPoint.c
 *
 *  Created on: Jul 27, 2015
 *      Author: Erik
 */

#include "main.h"

PropDriveToWayPoint initPropDriveToWayPoint(Drive drive, double distance, int rotation)
{
	PropDriveToWayPoint newStep = {drive, /*12.7*/ 1.50, 1.00, distance, rotation, 100, 15, 0, 0, 0, 18.0, 500};
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
	int driveStraight = (*step).rotation == 0;

	if(autonomousInfo.step != autonomousInfo.lastStep)
	{
		(*step).initialDistance = (encoderGet((*step).drive.leftEncoder) +
				encoderGet((*step).drive.rightEncoder)) / 2.0;
		(*step).initialDistance = encoderToInches((*step).initialDistance, 3.25);
		(*step).initialAngle = gyroGet((*step).drive.gyro);
	}

	printf("\nInitial Distance: %f", (*step).initialDistance);

	double currentDistance = (encoderGet((*step).drive.leftEncoder) +
			encoderGet((*step).drive.rightEncoder)) / 2.0;
	currentDistance = encoderToInches(currentDistance, 3.25);
	int currentAngle = gyroGet((*step).drive.gyro);

	double deltaDistance = currentDistance - (*step).initialDistance;
	int deltaAngle = currentAngle - (*step).initialAngle;

	double distanceError = (*step).distance - deltaDistance;
	int angleError = (*step).rotation - deltaAngle;

	int turnRight = angleError >= 0;

	printf("\nDistance Error: %f\nAngle Error: %d\n", distanceError, angleError);

	int left = encoderGet((*step).drive.leftEncoder);
	int right = encoderGet((*step).drive.rightEncoder);

	printf("Left: %d\nRight: %d\n\n", left, right);

	if(absDouble(distanceError) < .5)
	{
		//magnitude = (forward) ? -10 : 10;
		goodDistance = 1;
	}
	else if(absDouble(distanceError) < (*step).slowDownDistance)
	{
		magnitude = (int) (distanceError * (*step).magnitudeKP);

		if(forward) magnitude += (*step).minSpeed;
		else magnitude -= (*step).minSpeed;

		if(forward) magnitude = limit(magnitude, (*step).maxSpeed, (*step).minSpeed);
		else magnitude = limit(magnitude, -(*step).minSpeed, -(*step).maxSpeed);
	}
	else if(autonomousInfo.elapsedTime < (*step).timeToAccelerate)
	{
		magnitude = (int) ((autonomousInfo.elapsedTime * 1.0 / (*step).timeToAccelerate)
				* (*step).maxSpeed);

		if(!forward) magnitude *= -1;
	}
	else
	{
		if(forward) magnitude = (*step).maxSpeed;
		else magnitude = -(*step).maxSpeed;
	}

	if(!driveStraight || driveStraight)//TODO change back
	{
		if(abs(angleError) < 2)
		{
			rotation = 0;
			goodRotation = 1;
		}
		else
		{
			rotation = (int) (angleError * (*step).rotationKP);

			if(turnRight) rotation += (*step).minSpeed;
			else rotation -= (*step).minSpeed;

			if(turnRight) rotation = limit(rotation, (*step).maxSpeed, -(*step).maxSpeed);
			else rotation = limit(rotation, -(*step).minSpeed, -(*step).maxSpeed);
		}

		if(driveStraight) goodRotation = 0;
	}
	//else TODO reverse
	{
		if(goodDistance && driveStraight)
		{
			int turnEncoderError = right - left;

			if(abs(turnEncoderError) < 2 || 1)
			{
				goodRotation = 1;
			}
			else if(turnEncoderError > 0)
			{
				rotation = 20;
				goodRotation = 0;
			}
			else
			{
				rotation = -20;
				goodRotation = 0;
			}
		}
	}

	arcadeDrive((*step).drive, magnitude, rotation);

	(*step).isFinished = goodDistance && goodRotation;
}
