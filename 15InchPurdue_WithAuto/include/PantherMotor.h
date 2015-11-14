/*
 * PantherMotor.h
 *
 *  Created on: Feb 25, 2015
 *      Author: Erik
 */

#ifndef PANTHERMOTOR_H_
#define PANTHERMOTOR_H_

/**
 * Refence type for a motor and if it is inverted.
 */
struct PantherMotor{
	int port;
	int inverted;
}typedef PantherMotor;

PantherMotor initPantherMotor(int, int);
void setPantherMotor(PantherMotor, int);
int getPantherMotor(PantherMotor);

#endif /* PANTHERMOTOR_H_ */
