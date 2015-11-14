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
	int turnedOn;
	int SP;
	int lastSpeed;
	long lastChangeTime;
	PIDController controller;
	int processVariable;
	long lastOffTime;
	IME ime;
	int speed;

}typedef Shooter;

Shooter initShooter(PIDController controller, PantherMotor motor1, PantherMotor motor2, int defaultSpeed, int IMEPort, int IMEInverted);
void turnShooterOn(Shooter *shooter);
void turnShooterOff(Shooter *shooter);
void changeShooterSP(Shooter *shooter, int SP);
void incrementShooterSP(Shooter *shooter, int amount);
void runShooter(Shooter *shooter);
void shooterSetKP(Shooter *shooter, double kP);
void shooterSetKI(Shooter *shooter, double kI);
void shooterSetKD(Shooter *shooter, double kD);
void shooterSetKF(Shooter *shooter, double kF);
void shooterSetErrorEpsilon(Shooter *shooter, int errorEpsilon);
void updateShooter(Shooter *shooter);
int isShooterUpToSpeed(Shooter *shooter);
void runShooterAtSpeed(Shooter *shooter);

#endif /* INCLUDE_SHOOTER_H_ */
