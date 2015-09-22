/*
 * Motor.c
 *
 *  Created on: Feb 20, 2015
 *      Author: Erik
 */
#include "main.h"

/**
 * Returns an initialized PantherMotor object.
 */
PantherMotor initPantherMotor(int port, int inverted)
{
	PantherMotor newPantherMotor = {port, inverted};
	return newPantherMotor;
}

/**
 * Sets a motor to a desired speed, motor inversion are handled in this
 * function.
 */
void setPantherMotor(PantherMotor motor, int speed)
{
	//printf("Motor: %d to %d\n", motor.port, speed);
	motorSet(motor.port, (motor.inverted) ? -speed : speed);
}

/**
 * Returns the speed of a PantherMotor factoring in inversions.
 */
int getPantherMotor(PantherMotor motor)
{
	return (motor.inverted) ? -motorGet(motor.port) : motorGet(motor.port);
}
