/*
 * Drive.c
 *
 *  Created on: Jul 20, 2015
 *      Author: Erik
 */

#include "main.h"

Drive initDrive(int leftMotor, int leftMotorInverted,
		int rightMotor, int rightMotorInverted, int leftEncoderTopPort,
		int leftEncoderBottomPort, int leftEncoderInverted,
		int rightEncoderTopPort, int rightEncoderBottomPort,
		int rightEncoderInverted, int gyroPort)
{
	PantherMotor left = initPantherMotor(leftMotor, leftMotorInverted);
	PantherMotor right = initPantherMotor(rightMotor, rightMotorInverted);

	Encoder leftEncoder = encoderInit(leftEncoderTopPort,
			leftEncoderBottomPort, leftEncoderInverted);
	Encoder rightEncoder = encoderInit(rightEncoderTopPort,
			rightEncoderBottomPort, rightEncoderInverted);

	Gyro gyro = gyroInit(gyroPort, 0);

	Drive newDrive = {left, right, leftEncoder, rightEncoder, gyro};

	return newDrive;
}

void arcadeDrive(Drive drive, int magnitude, int rotation)
{
	int leftSpeed = magnitude + rotation;
	int rightSpeed = magnitude - rotation;
}
