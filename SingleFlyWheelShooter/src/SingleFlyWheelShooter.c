/*
 * SingleFlyWheelShooter.c
 *
 *  Created on: Jun 29, 2015
 *      Author: Erik
 */

#include "main.h"

SingleFlyWheelShooter initSingleFlyWheelShooter(int onSpeed, int offSpeed, int motor, int motorInverted, int topEncoder, int bottomEncoder, int encoderInverted)
{
	SingleFlyWheelShooter newShooter;

	BangBangController newController = {onSpeed, offSpeed, 0};
	PantherMotor newMotor = {motor, motorInverted};
	Encoder newEncoder = encoderInit(topEncoder, bottomEncoder, encoderInverted);

	newShooter.controller = &newController;
	newShooter.motor = newMotor;
	newShooter.encoder = newEncoder;
	newShooter.on = 0;
	newShooter.lastOffTime = millis();
	newShooter.processVariable = 0;

	return newShooter;
}

void setSetPoint(SingleFlyWheelShooter *shooter, int setPoint)
{
	(*(*shooter).controller).setPoint = setPoint;
}

void setOnSpeed(SingleFlyWheelShooter *shooter, int onSpeed)
{
	(*(*shooter).controller).onSpeed = onSpeed;
}

void setOffSpeed(SingleFlyWheelShooter *shooter, int offSpeed)
{
	(*(*shooter).controller).offSpeed = offSpeed;
}

void updateShooter(SingleFlyWheelShooter *shooter)
{
	(*shooter).processVariable =

	if((*(*shooter).controller).setPoint - (*shooter).processVariable)
	{
		(*shooter).lastOffTime = millis();
	}
}

int isShooterUpToSpeed(SingleFlyWheelShooter *shooter)
{
	return (((millis - (*shooter).lastOffTime)) > 500);
}

void runShooter(SingleFlyWheelShooter *shooter)
{
	int speed = runBangBangController((*(*shooter).controller),
			(*shooter).processVariable);
	setPantherMotor((*shooter).motor, speed);
}
