/*
 * PIDController.c
 *
 *  Created on: Jun 15, 2015
 *      Author: Erik
 */
#include "main.h"

PIDController initPIDController(double kP, double kI, double kD, double kF, double setPoint, double errorEpsilon)
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

double getPContribution(PIDController *controller, double processVariable)
{
	return ((*controller).kP * ((*controller).setPoint - processVariable));
}

double getIContribution(PIDController *controller, double processVariable)
{
	double error = (*controller).setPoint - processVariable;

	if(absDouble(error) < (*controller).errorEpsilon)
	{
		(*controller).sumOfError = 0;
		puts("Error cleared.");
		return 0;
	}
	else
	{
		puts("Error accumulated.");
		long timeDiff = millis() - (*controller).lastTime;
		double newError = timeDiff * error;
		(*controller).sumOfError += newError;
		printf("Sum of Error: %f\n", (*controller).sumOfError);
		double numToReturn = (*controller).sumOfError * (*controller).kI;
		numToReturn = limitDouble(numToReturn, 2000000000, -2000000000);
		return numToReturn;
	}
}

double getDContribution(PIDController *controller, double processVariable)
{
	double error = (*controller).setPoint - processVariable;
	int timeDiff = (int) (millis() - (*controller).lastTime);
	double errorDiff = error - (*controller).lastError;

	double slope = (errorDiff / timeDiff);

	return (slope * (*controller).kD);
}

int getFContribution(PIDController *controller)
{
	return (int) ((*controller).kF * (*controller).setPoint);
}

int runPIDController(PIDController *controller, double processVariable)
{
	int pContribution = getPContribution(controller, processVariable);
	int iContribution = getIContribution(controller, processVariable);
	int dContribution = getDContribution(controller, processVariable);
	int fContribution = getFContribution(controller);

	(*controller).lastError = (int) (*controller).setPoint - processVariable;
	(*controller).lastTime = millis();

	printf("PV: %f\n", processVariable);
	printf("SP: %f\n", (*controller).setPoint);
	printf("I: %d\n", iContribution);

	return pContribution + iContribution + dContribution + fContribution;
}
