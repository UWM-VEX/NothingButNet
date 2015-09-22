/*
 * PIDController.h
 *
 *  Created on: Jun 15, 2015
 *      Author: Erik
 */

#ifndef PIDCONTROLLER_H_
#define PIDCONTROLLER_H_

struct PIDController{

	double kP;
	double kI;
	double kD;
	double kF;
	int setPoint;
	int lastError;
	long lastTime;
	int sumOfError;
	int errorEpsilon;

}typedef PIDController;

PIDController initPIDController(double kP, double kI, double kD, double kF, int setPoint, int errorEpsilon);
void setkP(PIDController *controller, double kP);
void setkI(PIDController *controller, double kP);
void setkD(PIDController *controller, double kP);
void setkF(PIDController *controller, double kP);
void setSetPoint(PIDController *controller, double setPoint);
void setErrorEpsilon(PIDController *controller, double errorEpsilon);
int getPContribution(PIDController *controller, int processVariable);
int getIContribution(PIDController *controller, int processVariable);
int getDContribution(PIDController *controller, int processVariable);
int getFContribution(PIDController *controller);
int runPIDController(PIDController *controller, int processVariable);

#endif /* PIDCONTROLLER_H_ */
