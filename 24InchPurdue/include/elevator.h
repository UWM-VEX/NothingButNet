/*
 * elevator.h
 *
 *  Created on: Nov 12, 2015
 *      Author: Erik
 */

#ifndef INCLUDE_ELEVATOR_H_
#define INCLUDE_ELEVATOR_H_

#include "main.h"

struct elevator{
	PantherMotor motor;
}typedef elevator;

elevator initElevator(PantherMotor motor);
void elevatorUp(elevator in);
void elevatorDown(elevator out);
void elevatorStop(elevator out);

#endif /* INCLUDE_ELEVATOR_H_ */
