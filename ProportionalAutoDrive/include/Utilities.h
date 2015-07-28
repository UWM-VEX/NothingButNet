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
double absDouble(double num);
int inDeadBand(int realNum, int desiredNum, int deadBand);
int inDeadBandDouble(double realNum, double desiredNum, double deadBand);
double encoderToInches(int encoderLines, double wheelDiameter);

#endif /* UTILITIES_H_ */
