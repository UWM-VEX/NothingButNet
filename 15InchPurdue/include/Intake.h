/*
 * Intake.h
 *
 *  Created on: Oct 29, 2015
 *      Author: Erik
 */

#ifndef INCLUDE_INTAKE_H_
#define INCLUDE_INTAKE_H_

struct Intake{

	PantherMotor intake1;
	PantherMotor intake2;

}typedef Intake;

Intake initIntake(PantherMotor intake1, PantherMotor intake2);
void intake1In(Intake intake);
void intake1Out(Intake intake);
void intake1Stop(Intake intake);
void intake2In(Intake intake);
void intake2Out(Intake intake);
void intake2Stop(Intake intake);

#endif /* INCLUDE_INTAKE_H_ */
