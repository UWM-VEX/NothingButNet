/*
 * Shooter.c
 *
 *  Created on: Oct 29, 2015
 *      Author: Erik
 */

#include "main.h"

Shooter initShooter(PantherMotor motor1, PantherMotor motor2)
{
	Shooter newShooter = {motor1, motor2};
	return  newShooter;
}

void shooterAtSpeed(Shooter shooter, int speed)
{
	speed = limit(speed, 127, -127);

	setPantherMotor(shooter.motor1, speed);
	setPantherMotor(shooter.motor2, speed);
}

void runShooterFull(Shooter shooter)
{
	shooterAtSpeed(shooter, 127);
}

void runShooterHalf(Shooter shooter)
{
	shooterAtSpeed(shooter, 60);
}

void reverseShooterFull(Shooter shooter)
{
	shooterAtSpeed(shooter, -127);
}

void reverseShooterHalf(Shooter shooter)
{
	shooterAtSpeed(shooter, -60);
}
