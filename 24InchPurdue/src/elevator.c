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

void ElevatorUp(elevator in){
	setPantherMotor(in.motor, 127);
}

void ElevatorDown(elevator out){
	setPantherMotor(out.motor, -127);
}
