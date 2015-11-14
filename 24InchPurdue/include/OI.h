/*
 * OI.h
 *
 *  Created on: Oct 29, 2015
 *      Author: Erik
 */

#ifndef INCLUDE_OI_H_
#define INCLUDE_OI_H_

int numJoysticks;

int OIGetDriveLeft();
int OIGetDriveRight();
int OIGetRunShooterFull();
int OIGetRunShooterHalf();
int OIGetReverseShooterFull();
int OIGetReverseShooterHalf();
int OIGetIntakeIn();
int OIGetIntakeOut();
int OIGetElevatorUp();
int OIGetElevatorDown();
int OIGetDeployRamp();

#endif /* INCLUDE_OI_H_ */
