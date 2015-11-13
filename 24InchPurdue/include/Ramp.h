/*
 * Ramp.h
 *
 *  Created on: Oct 29, 2015
 *      Author: Erik
 */

#ifndef INCLUDE_RAMP_H_
#define INCLUDE_RAMP_H_

struct Ramp{

	int solenoidPort;

}typedef Ramp;

Ramp initRamp(int solenoidPort);
void deployRamp(Ramp ramp);

#endif /* INCLUDE_RAMP_H_ */
