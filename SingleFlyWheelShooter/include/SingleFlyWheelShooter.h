/*
 * SingleFlyWheelShooter.h
 *
 *  Created on: Jun 29, 2015
 *      Author: Erik
 */

#ifndef SINGLEFLYWHEELSHOOTER_H_
#define SINGLEFLYWHEELSHOOTER_H_

struct SingleFlyWheelShooter{

	BangBangController *controller;
	PantherMotor motor;
	IME ime;
	int on;
	long lastOffTime;
	double processVariable;

}typedef SingleFlyWheelShooter;

SingleFlyWheelShooter initSingleFlyWheelShooter(int onSpeed, int offSpeed, int motor, int motorInverted, int ime, int imeInverted);
void updateShooter(SingleFlyWheelShooter *shooter);
int isShooterUpToSpeed(SingleFlyWheelShooter *shooter);
void setSetPoint(SingleFlyWheelShooter *shooter, int setPoint);
void setOnSpeed(SingleFlyWheelShooter *shooter, int onSpeed);
void setOffSpeed(SingleFlyWheelShooter *shooter, int offSpeed);
void runShooter(SingleFlyWheelShooter *shooter);

SingleFlyWheelShooter shooter;

#endif /* SINGLEFLYWHEELSHOOTER_H_ */
