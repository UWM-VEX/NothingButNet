/*
 * SingleFlyWheelShooter.c
 *
 *  Created on: Jun 29, 2015
 *      Author: Erik
 */

#include "main.h"

SingleFlyWheelShooter initSingleFlyWheelShooter(int onSpeed, int offSpeed, int motor, int motorInverted, int ime, int imeInverted)
{
	SingleFlyWheelShooter newShooter;

	BangBangController newController = {onSpeed, offSpeed, 0};
	PantherMotor newMotor = {motor, motorInverted};
	IME newIME = initIME(ime, imeInverted);

	newShooter.controller = &newController;
	newShooter.motor = newMotor;
	newShooter.ime = newIME;
	newShooter.on = 0;
	newShooter.lastOffTime = millis();
	newShooter.processVariable = 0;

	return newShooter;
}

void setSetPoint(SingleFlyWheelShooter *shooter, int setPoint)
{
	(*(*shooter).controller).setPoint = (double) setPoint;
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
	(*shooter).processVariable = getIMEVelocity((*shooter).ime);

	printf("Speed: %f\n", (*shooter).processVariable);

	printf("Error: %f\n", (*(*shooter).controller).setPoint - (*shooter).processVariable);

	if(abs((int) (*(*shooter).controller).setPoint - (*shooter).processVariable) > 250)
	{
		(*shooter).lastOffTime = millis();
	}
}

int isShooterUpToSpeed(SingleFlyWheelShooter *shooter)
{
	return (((millis() - (*shooter).lastOffTime)) > 100);
}

void runShooter(SingleFlyWheelShooter *shooter)
{
	int speed = runBangBangController((*(*shooter).controller),
			(*shooter).processVariable);
	setPantherMotor((*shooter).motor, speed);
}
