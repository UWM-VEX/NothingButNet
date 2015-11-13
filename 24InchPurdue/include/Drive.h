/*
 * Drive.h
 *
 *  Created on: Oct 29, 2015
 *      Author: Erik
 */

#ifndef INCLUDE_DRIVE_H_
#define INCLUDE_DRIVE_H_

struct Drive{

	PantherMotor frontLeft;
	PantherMotor frontRight;
	PantherMotor rearLeft;
	PantherMotor rearRight;

}typedef Drive;

Drive initDrive(PantherMotor frontLeft, PantherMotor frontRight,
		PantherMotor rearLeft, PantherMotor rearRight);
void tankDrive(Drive drive, int left, int right);

#endif /* INCLUDE_DRIVE_H_ */
