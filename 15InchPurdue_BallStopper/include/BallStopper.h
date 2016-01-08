/*
 * BallStopper.h
 *
 *  Created on: Jan 4, 2016
 *      Author: Erik
 */

#ifndef INCLUDE_BALLSTOPPER_H_
#define INCLUDE_BALLSTOPPER_H_

#define STOPPER_UP 1
#define STOPPER_DOWN 0

struct BallStopper{

	int extend;
	int state;

}typedef BallStopper;

BallStopper initBallStopper(int extend);
void ballStopperUp(BallStopper *stopper);
void ballStopperDown(BallStopper *stopper);
void runBallStopper(BallStopper *stopper);

#endif /* INCLUDE_BALLSTOPPER_H_ */
