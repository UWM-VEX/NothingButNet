/*
 * Ramp.c
 *
 *  Created on: Oct 29, 2015
 *      Author: Erik
 */

#include "main.h"

Ramp initRamp(int solenoidPort)
{
	pinMode(solenoidPort, OUTPUT);

	Ramp newRamp = {solenoidPort};
	digitalWrite(newRamp.solenoidPort, LOW);
	return newRamp;
}

void deployRamp(Ramp ramp)
{
	digitalWrite(ramp.solenoidPort, HIGH);
}
