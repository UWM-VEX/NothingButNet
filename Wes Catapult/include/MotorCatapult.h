/*
 * MotorCatapult.h
 *
 *  Created on: Sep 17, 2015
 *      Author: Erik
 */

#ifndef MOTORCATAPULT_H_
#define MOTORCATAPULT_H_

#include "main.h"

struct MotorCatapult{

	PantherMotor motor;
	int upperLimit;
	int lowerLimit;
	int shooting;

}typedef MotorCatapult;

MotorCatapult initMotorCatapult(int motor, int motorInverted, int upperLimit, int lowerLimit);
void runMotorCatapult(MotorCatapult *catapult, int shoot);

MotorCatapult shooter;

#endif /* MOTORCATAPULT_H_ */
