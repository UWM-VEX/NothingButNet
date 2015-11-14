/*
 * intake.h
 *
 *  Created on: Nov 12, 2015
 *      Author: Erik
 */

#ifndef INCLUDE_INTAKE_H_
#define INCLUDE_INTAKE_H_

struct intake{
	PantherMotor front;
	PantherMotor back;
}typedef intake;

intake initIntake(PantherMotor front, PantherMotor back);
void intakeIn(intake in);
void intakeOut(intake out);
void intakeStop(intake in);

#endif /* INCLUDE_INTAKE_H_ */
