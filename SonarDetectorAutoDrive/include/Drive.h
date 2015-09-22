/*
 * Drive.h
 *
 *  Created on: Jul 20, 2015
 *      Author: Erik
 */

#ifndef DRIVE_H_
#define DRIVE_H_

struct Drive{

	PantherMotor leftMotor;
	PantherMotor rightMotor;
	Encoder leftEncoder;
	Encoder rightEncoder;
	Gyro gyro;
	Ultrasonic sonar;

}typedef Drive;

Drive initDrive(int leftMotor, int leftMotorInverted,
		int rightMotor, int rightMotorInverted, int leftEncoderTopPort,
		int leftEncoderBottomPort, int leftEncoderInverted,
		int rightEncoderTopPort, int rightEncoderBottomPort,
		int rightEncoderInverted, int gyroPort, int echoPort,
		int pingPort);
void arcadeDrive(Drive drive, int magnitude, int rotation);
void tankDrive(Drive drive, int leftSpeed, int rightSpeed);
int getSonar(Drive drive);

#endif /* DRIVE_H_ */
