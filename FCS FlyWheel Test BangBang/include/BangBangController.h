/*
 * BangBangController.h
 *
 *  Created on: Jun 12, 2015
 *      Author: Erik
 */

#ifndef BANGBANGCONTROLLER_H_
#define BANGBANGCONTROLLER_H_

struct BangBangController{

	int onSpeed;
	int offSpeed;
	int setPoint;

}typedef BangBangController;

BangBangController initBangBangController(int onSpeed, int offSpeed, int setPoint);
void bangBangChangeSetPoint(BangBangController *controller, int setPoint);
int runBangBangController(BangBangController *controller, int processVariable);
int getError(BangBangController *controller, int processVariable);

#endif /* BANGBANGCONTROLLER_H_ */
