/*
 * Utilities.h
 *
 *  Created on: Feb 25, 2015
 *      Author: Erik
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#define SIN_45 0.70710678118
#define PI 3.14159265359

int limit(int, int, int);
int abs(int);
int inDeadBand(int realNum, int desiredNum, int deadBand);
int holonomicInchesToIME(double inches, double wheelDiameter);

#endif /* UTILITIES_H_ */
