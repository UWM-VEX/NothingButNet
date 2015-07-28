/*
 * PropDriveToWayPoint.h
 *
 *  Created on: Jul 27, 2015
 *      Author: Erik
 */

#ifndef PROPDRIVETOWAYPOINT_H_
#define PROPDRIVETOWAYPOINT_H_

#include "main.h"

struct PropDriveToWayPoint{

	Drive drive;
	double magnitudeKP;
	double rotationKP;
	double distance;
	int rotation;
	int maxSpeed;
	int minSpeed;
	int initialDistance;
	int initialAngle;

}typedef PropDriveToWayPoint;

#endif /* PROPDRIVETOWAYPOINT_H_ */
