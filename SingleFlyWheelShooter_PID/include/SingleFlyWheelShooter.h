/*
 * SingleFlyWheelShooter.h
 *
 *  Created on: Jun 29, 2015
 *      Author: Erik
 */

#ifndef SINGLEFLYWHEELSHOOTER_H_
#define SINGLEFLYWHEELSHOOTER_H_

struct SingleFlyWheelShooter{

	PIDController *controller;
	PantherMotor motor;
	IME ime;
	int on;
	long lastOffTime;
	int processVariable;

}typedef SingleFlyWheelShooter;

SingleFlyWheelShooter initSingleFlyWheelShooter(double kP, double kI, double kD, double kF, int errorEpsilon, int motor, int motorInverted, int ime, int imeInverted);
void updateShooter(SingleFlyWheelShooter *shooter);
int isShooterUpToSpeed(SingleFlyWheelShooter *shooter);
void shooterSetSetPoint(SingleFlyWheelShooter *shooter, int setPoint);
void shooterSetKP(SingleFlyWheelShooter*, double);
void shooterSetKI(SingleFlyWheelShooter*, double);
void shooterSetKD(SingleFlyWheelShooter*, double);
void shooterSetKF(SingleFlyWheelShooter*, double);
void shooterSetErrorEpsilon(SingleFlyWheelShooter*, int);
void runShooter(SingleFlyWheelShooter *shooter);

SingleFlyWheelShooter shooter;

#endif /* SINGLEFLYWHEELSHOOTER_H_ */
