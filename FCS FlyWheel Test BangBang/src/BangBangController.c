/*
 * BangBangController.c
 *
 *  Created on: Jun 12, 2015
 *      Author: Erik
 */

#include "main.h"

BangBangController initBangBangController(int onSpeed, int offSpeed, int setPoint)
{
	BangBangController newController = {onSpeed, offSpeed, setPoint};
	return newController;
}

void bangBangChangeSetPoint(BangBangController *controller, int setPoint)
{
	controller.setPoint = setPoint;
}

int runBangBangController(BangBangController *controller, int processVariable)
{
	printf("SP: %d\n", controller.setPoint);

	return ((processVariable < controller.setPoint) ?
			controller.onSpeed : controller.offSpeed);
}

int getError(BangBangController *controller, int processVariable)
{
	return controller.setPoint - processVariable;
}
