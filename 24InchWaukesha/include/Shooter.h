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

}typedef Shooter;

Shooter initShooter(PantherMotor motor1, PantherMotor motor2);
void shooterAtSpeed(Shooter shooter, int speed);
void runShooterFull(Shooter shooter);
void runShooterHalf(Shooter shooter);
void reverseShooterFull(Shooter shooter);
void reverseShooterHalf(Shooter shooter);

#endif /* INCLUDE_SHOOTER_H_ */
