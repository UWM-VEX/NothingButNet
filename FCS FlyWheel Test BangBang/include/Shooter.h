/*
 * Shooter.h
 *
 *  Created on: Oct 29, 2015
 *      Author: Erik
 */

#ifndef INCLUDE_SHOOTER_H_
#define INCLUDE_SHOOTER_H_

struct Shooter{

	PantherMotor motor1;
	PantherMotor motor2;
	PantherMotor motor3;
	PantherMotor motor4;
	int turnedOn;
	int SP;
	int lastSpeed;
	long lastChangeTime;
	BangBangController controller;
	IME ime;

}typedef Shooter;

Shooter initShooter(PantherMotor motor1, PantherMotor motor2,
		PantherMotor motor3, PantherMotor motor4, int defaultSpeed);
void turnShooterOn(Shooter *shooter);
void turnShooterOff(Shooter *shooter);
void changeShooterSP(Shooter *shooter, int SP);
void incrementShooterSP(Shooter *shooter, int amount);
void runShooter(Shooter *shooter);

#endif /* INCLUDE_SHOOTER_H_ */
