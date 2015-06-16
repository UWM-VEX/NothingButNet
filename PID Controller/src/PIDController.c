/*
 * PIDController.c
 *
 *  Created on: Jun 15, 2015
 *      Author: Erik
 */
#include "main.h"

PIDController initPIDController(double kP, double kI, double kD, double kF, int setPoint, int errorEpsilon)
{
	PIDController newController = {kP, kI, kD, kF, setPoint, 0, millis(),
			0, errorEpsilon};

	return newController;
}

void setkP(PIDController *controller, double kP)
{
	(*controller).kP = kP;
}

void setkI(PIDController *controller, double kI)
{
	(*controller).kI = kI;
}

void setkD(PIDController *controller, double kD)
{
	(*controller).kD = kD;
}

void setkF(PIDController *controller, double kF)
{
	(*controller).kF = kF;
}

void setSetPoint(PIDController *controller, double setPoint)
{
	(*controller).setPoint = setPoint;
}

void setErrorEpsilon(PIDController *controller, double errorEpsilon)
{
	(*controller).errorEpsilon = errorEpsilon;
}

int getPContribution(PIDController *controller, int processVariable)
{
	return (int) ((*controller).kP * (processVariable - (*controller).setPoint));
}

int getIContribution(PIDController *controller, int processVariable)
{
	int error = processVariable - (*controller).setPoint;

	if(abs(error) < (*controller).errorEpsilon)
	{
		(*controller).sumOfError = 0;
		return 0;
	}
	else
	{
		long timeDiff = millis() - (*controller).lastTime;
		int newError = (int) timeDiff * error;
		(*controller).sumOfError += newError;
		return (int) (*controller).sumOfError * (*controller).kI;
	}
}

int getDContribution(PIDController *controller, int processVariable)
{
	int error = processVariable - (*controller).setPoint;
	int timeDiff = (int) (millis() - (*controller).lastTime);
	int errorDiff = error - (*controller).lastError;

	double slope = (double) (errorDiff / timeDiff);

	return (int) (slope * (*controller).kD);
}

int getFContribution(PIDController *controller)
{
	return (int) ((*controller).kF * (*controller).setPoint);
}

int runPIDController(PIDController *controller, int processVariable)
{
	int pContribution = getPContribution(controller, processVariable);
	int iContribution = getIContribution(controller, processVariable);
	int dContribution = getDContribution(controller, processVariable);
	int fContribution = getFContribution(controller, processVariable);

	(*controller).lastError = processVariable - (*controller).setPoint;
	(*controller).lastTime = millis();

	return pContribution + iContribution + dContribution + fContribution;
}
