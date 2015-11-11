#include "main.h"

/**
 * Initializes a new drive object composed of two PantherMotors.
 */
Drive initDrive(PantherMotor frontLeftMotor, PantherMotor frontRightMotor,
		PantherMotor middleLeftMotor, PantherMotor middleRightMotor,
		PantherMotor rearLeftMotor, PantherMotor rearRightMotor,
		Encoder leftEncoder, Encoder rightEncoder)
{
	Drive newDrive = {frontLeftMotor, frontRightMotor, middleLeftMotor,
			middleRightMotor, rearLeftMotor, rearRightMotor,
			leftEncoder, rightEncoder};

	return newDrive;
}

/**
 * Drives a holonomic drive robot at the specified direction, magnitude,
 * and rotation.
 */
void tankDrive(Drive drive, int left, int right)
{
	int leftSpeed = limit(left, 127, -127);
	int rightSpeed = limit(right, 127, -127);

	setPantherMotor(drive.frontLeftMotor, leftSpeed);
	setPantherMotor(drive.middleLeftMotor, leftSpeed);
	setPantherMotor(drive.rearLeftMotor, leftSpeed);
	setPantherMotor(drive.frontRightMotor, rightSpeed);
	setPantherMotor(drive.middleRightMotor, rightSpeed);
	setPantherMotor(drive.rearRightMotor, rightSpeed);
}
