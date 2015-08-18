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
	return (int) ((*controller).kP * ((*controller).setPoint - processVariable));
}

int getIContribution(PIDController *controller, int processVariable)
{
	int error = (*controller).setPoint - processVariable;

	if(abs(error) < (*controller).errorEpsilon)
	{
		(*controller).sumOfError = 0;
		puts("Error cleared.");
		return 0;
	}
	else
	{
		puts("Error accumulated.");
		long timeDiff = millis() - (*controller).lastTime;
		int newError = (int) timeDiff * error;
		(*controller).sumOfError += newError;
		printf("Sum of Error: %d\n", (*controller).sumOfError);
		long numToReturn = (long) (*controller).sumOfError * (*controller).kI;
		numToReturn = limit(numToReturn, 2000000000, -2000000000);
		return (int) numToReturn;
	}
}

int getDContribution(PIDController *controller, int processVariable)
{
	int error = (*controller).setPoint - processVariable;
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
	int fContribution = getFContribution(controller);

	(*controller).lastError = (*controller).setPoint - processVariable;
	(*controller).lastTime = millis();

	printf("PV: %d\n", processVariable);
	printf("SP: %d\n", (*controller).setPoint);
	printf("I: %d\n", iContribution);

	return pContribution + iContribution + dContribution + fContribution;
}
