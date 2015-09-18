/*
 * MotorCatapult.c
 *
 *  Created on: Sep 17, 2015
 *      Author: Erik
 */

#include "main.h"

MotorCatapult initMotorCatapult(int motor, int motorInverted, int upperLimit, int lowerLimit)
{
	MotorCatapult newCatapult;

	newCatapult.motor = initPantherMotor(motor, motorInverted);

	newCatapult.upperLimit = upperLimit;
	newCatapult.lowerLimit = lowerLimit;

	newCatapult.shooting = 0;

	pinMode(upperLimit, INPUT);
	pinMode(lowerLimit, INPUT);

	return newCatapult;
}

void runMotorCatapult(MotorCatapult *catapult, int shoot)
{
	if(shoot && !digitalRead((*catapult).lowerLimit)) (*catapult).shooting = 1;

	if((*catapult).shooting)
	{
		if(!digitalRead((*catapult).upperLimit))
		{
			setPantherMotor((*catapult).motor, -20);
			(*catapult).shooting = 0;
		}
		else
		{
			setPantherMotor((*catapult).motor, 127);
		}
	}
	else
	{
		if(!digitalRead((*catapult).lowerLimit))
		{
			setPantherMotor((*catapult).motor, 0);
		}
		else
		{
			setPantherMotor((*catapult).motor, -20);
		}
	}
}
