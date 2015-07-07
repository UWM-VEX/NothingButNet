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
	Encoder encoder;
	int on;
	long lastOffTime;
	int processVariable;

}typedef SingleFlyWheelShooter;

SingleFlyWheelShooter initSingleFlyWheelShooter(int onSpeed, int offSpeed, int motor, int motorInverted, int topEncoder, int bottomEncoder, int encoderInverted);
void updateShooter(SingleFlyWheelShooter *shooter, int processVariable);
int isShooterUpToSpeed(SingleFlyWheelShooter *shooter);

SingleFlyWheelShooter shooter;

#endif /* SINGLEFLYWHEELSHOOTER_H_ */
