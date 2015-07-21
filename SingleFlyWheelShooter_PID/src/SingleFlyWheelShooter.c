/*
 * SingleFlyWheelShooter.c
 *
 *  Created on: Jun 29, 2015
 *      Author: Erik
 */

#include "main.h"

SingleFlyWheelShooter initSingleFlyWheelShooter(double kP, double kI, double kD, double kF, int errorEpsilon, int motor, int motorInverted, int ime, int imeInverted)
{
	SingleFlyWheelShooter newShooter;

	PIDController newController = initPIDController(kP, kI, kD, kF, 0, errorEpsilon);
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

void shooterSetSetPoint(SingleFlyWheelShooter *shooter, int setPoint)
{
	setSetPoint((*shooter).controller, (double) setPoint);
}

void shooterSetKP(SingleFlyWheelShooter *shooter, double kP)
{
	setkP((*shooter).controller, kP);
}

void shooterSetKI(SingleFlyWheelShooter *shooter, double kI)
{
	setkI((*shooter).controller, kI);
}

void shooterSetKD(SingleFlyWheelShooter *shooter, double kD)
{
	setkD((*shooter).controller, kD);
}

void shooterSetKF(SingleFlyWheelShooter *shooter, double kF)
{
	setkF((*shooter).controller, kF);
}

void shooterSetErrorEpsilon(SingleFlyWheelShooter *shooter, int errorEpsilon)
{
	setErrorEpsilon((*shooter).controller, errorEpsilon);
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
	int speed = runPIDController((*shooter).controller,
			(*shooter).processVariable);
	setPantherMotor((*shooter).motor, speed);
}
