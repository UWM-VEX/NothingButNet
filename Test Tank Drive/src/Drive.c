#include "main.h"

/**
 * Initializes a new drive object composed of two PantherMotors.
 */
Drive initDrive(PantherMotor frontLeftMotor, PantherMotor frontRightMotor,
		PantherMotor middleLeftMotor, PantherMotor middleRightMotor,
		PantherMotor rearLeftMotor, PantherMotor rearRightMotor)
{
	Drive newDrive = {frontLeftMotor, frontRightMotor, middleLeftMotor,
			middleRightMotor, rearLeftMotor, rearRightMotor};

	return newDrive;
}

/**
 * Drives a holonomic drive robot at the specified direction, magnitude,
 * and rotation.
 */
void tankDrive(Drive drive, int magnitude, int rotation)
{
	int leftSpeed = magnitude + rotation;
	int rightSpeed = magnitude - rotation;

	leftSpeed = limit(leftSpeed, 127, -127);
	rightSpeed = limit(rightSpeed, 127, -127);

	setPantherMotor(drive.frontLeftMotor, leftSpeed);
	setPantherMotor(drive.middleLeftMotor, leftSpeed);
	setPantherMotor(drive.rearLeftMotor, leftSpeed);
	setPantherMotor(drive.frontRightMotor, rightSpeed);
	setPantherMotor(drive.middleRightMotor, rightSpeed);
	setPantherMotor(drive.rearRightMotor, rightSpeed);

}
