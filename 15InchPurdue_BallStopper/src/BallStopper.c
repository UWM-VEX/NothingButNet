/*
 * BallStopper.c
 *
 *  Created on: Jan 4, 2016
 *      Author: Erik
 */

#include "main.h"

/**
 * Helper method, do not use outside of BallStopper.c file or include in header file.
 */
void setBallStopperDown(BallStopper *stopper)
{
	digitalWrite((*stopper).extend, LOW);
}

/**
 * Helper method, do not use outside of BallStopper.c file or include in header file.
 */
void setBallStopperUp(BallStopper *stopper)
{
	digitalWrite((*stopper).extend, HIGH);
}

BallStopper initBallStopper(int extend)
{
	pinMode(extend, OUTPUT);

	BallStopper newBallStopper = {extend, STOPPER_DOWN};

	return newBallStopper;
}

void ballStopperUp(BallStopper *stopper)
{
	(*stopper).state = STOPPER_UP;
}

void ballStopperDown(BallStopper *stopper)
{
	(*stopper).state = STOPPER_DOWN;
}

void runBallStopper(BallStopper *stopper)
{
	if((*stopper).state == STOPPER_UP)
	{
		setBallStopperUp(stopper);
	}
	else
	{
		setBallStopperDown(stopper);
	}
}
