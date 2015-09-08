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
	double initialDistance;
	int initialAngle;
	int isFinished;
	double slowDownDistance;
	long timeToAccelerate;

}typedef PropDriveToWayPoint;

PropDriveToWayPoint initPropDriveToWayPoint(Drive drive, double distance, int rotation);
void propDriveToWayPointSetMagnitudeKP(PropDriveToWayPoint *step, double kP);
void propDriveToWayPointSetRotationKP(PropDriveToWayPoint *step, double kP);
void propDriveToWayPointSetMaxSpeed(PropDriveToWayPoint *step, int speed);
void propDriveToWayPointSetMinSpeed(PropDriveToWayPoint *step, int speed);
void propDriveToWayPoint(PropDriveToWayPoint *step);


#endif /* PROPDRIVETOWAYPOINT_H_ */
