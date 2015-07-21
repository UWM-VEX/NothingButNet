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

}typedef Drive;

#endif /* DRIVE_H_ */
