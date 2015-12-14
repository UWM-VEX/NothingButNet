/*
 * Shooter.c
 *
 *  Created on: Oct 29, 2015
 *      Author: Erik
 */

#include "main.h"

Shooter initShooter(PantherMotor motor1, PantherMotor motor2,
		PantherMotor motor3, PantherMotor motor4, int defaultSpeed)
{
	Shooter newShooter = {motor1, motor2, motor3, motor4, 0, defaultSpeed, 0, millis()};
	return newShooter;
}

void turnShooterOn(Shooter *shooter)
{
	(*shooter).turnedOn = 1;
	(*shooter).lastSpeed = 50;
	puts("Shooter turned on.");
}

void turnShooterOff(Shooter *shooter)
{
	(*shooter).turnedOn = 0;
	(*shooter).lastSpeed = (*shooter).SP;
	(*shooter).lastChangeTime = millis();
}

void changeShooterSP(Shooter *shooter, int SP)
{
	(*shooter).SP = SP;
}

void incrementShooterSP(Shooter *shooter, int amount)
{
	(*shooter).SP += amount;
}

void runShooter(Shooter *shooter)
{
	int speed;

	if((*shooter).turnedOn)
	{
		//speed = (*shooter).SP;

		//(*shooter).lastSpeed = 0;//(*shooter).SP;

		int dT = (int) (millis() - (*shooter).lastChangeTime);

		if(dT > 25)
		{
			speed = ++(*shooter).lastSpeed;
			(*shooter).lastChangeTime = millis();
		}
		else
		{
			speed = (*shooter).lastSpeed;
		}

		speed = limit(speed, (*shooter).SP, 0);
	}
	else
	{
		int dT = (int) (millis() - (*shooter).lastChangeTime);

		if(dT > 50)
		{
			speed = --(*shooter).lastSpeed;
			(*shooter).lastChangeTime = millis();
		}
		else
		{
			speed = (*shooter).lastSpeed;
		}

		speed = limit(speed, 127, 0);
	}

	setPantherMotor((*shooter).motor1, speed);
	setPantherMotor((*shooter).motor2, speed);
	setPantherMotor((*shooter).motor3, speed);
	setPantherMotor((*shooter).motor4, speed);
}
