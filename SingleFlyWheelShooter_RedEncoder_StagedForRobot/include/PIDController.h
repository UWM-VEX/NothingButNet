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
	double setPoint;
	double lastError;
	long lastTime;
	double sumOfError;
	double errorEpsilon;

}typedef PIDController;

PIDController initPIDController(double kP, double kI, double kD, double kF, double setPoint, double errorEpsilon);
void setkP(PIDController *controller, double kP);
void setkI(PIDController *controller, double kP);
void setkD(PIDController *controller, double kP);
void setkF(PIDController *controller, double kP);
void setSetPoint(PIDController *controller, double setPoint);
void setErrorEpsilon(PIDController *controller, double errorEpsilon);
double getPContribution(PIDController *controller, double processVariable);
double getIContribution(PIDController *controller, double processVariable);
double getDContribution(PIDController *controller, double processVariable);
int getFContribution(PIDController *controller);
int runPIDController(PIDController *controller, double processVariable);

#endif /* PIDCONTROLLER_H_ */
