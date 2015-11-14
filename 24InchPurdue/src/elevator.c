/*
 * elevator.c
 *
 *  Created on: Nov 12, 2015
 *      Author: Erik
 */
#include "main.h"

elevator initElevator(PantherMotor motor){
	elevator newElevator = {motor};
	return newElevator;
}

void elevatorUp(elevator in){
	setPantherMotor(in.motor, 127);
}

void elevatorDown(elevator out){
	setPantherMotor(out.motor, -127);
}

void elevatorStop(elevator out){
	setPantherMotor(out.motor, 0);
}
