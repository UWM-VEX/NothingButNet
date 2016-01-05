/*
 * Intake.h
 *
 *  Created on: Oct 29, 2015
 *      Author: Erik
 */

#ifndef INCLUDE_INTAKE_H_
#define INCLUDE_INTAKE_H_

struct Intake{

	PantherMotor leftMotor;
	PantherMotor rightMotor;
	PantherMotor middleMotor;
	PantherMotor backMotor;
	int leftLimitSwitch;
	int rightLimitSwitch;

}typedef Intake;

/**
 * Use in initIO method.
 */
Intake initIntake(PantherMotor leftMotor, PantherMotor rightMotor,
		PantherMotor middleMotor, PantherMotor backMotor, int leftLimitSwitch,
		int rightLimitSwitch);
void intake1In(Intake intake);
void intake1Out(Intake intake);
void intake1Stop(Intake intake);
void intake2In(Intake intake);
void intake2Out(Intake intake);
void intake2Stop(Intake intake);

#endif /* INCLUDE_INTAKE_H_ */
