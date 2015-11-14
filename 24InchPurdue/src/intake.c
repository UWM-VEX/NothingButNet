/*
 * intake.c
 *
 *  Created on: Nov 12, 2015
 *      Author: Erik
 */

#include "main.h"

intake initIntake(PantherMotor front, PantherMotor back){
	intake newIntake = {front, back};
	return newIntake;
}

void intakeIn(intake in){
	setPantherMotor(in.front, 127);
	setPantherMotor(in.back, 127);
}

void intakeOut(intake out){
	setPantherMotor(out.front, -127);
	setPantherMotor(out.back, -127);
}

void intakeStop(intake in)
{
	setPantherMotor(in.front, 0);
	setPantherMotor(in.back, 0);
}
