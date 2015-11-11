/*
 * RedEncoder.h
 *
 *  Created on: Sep 21, 2015
 *      Author: Erik
 */

#ifndef REDENCODER_H_
#define REDENCODER_H_

struct RedEncoder{

	Encoder encoder;
	int lastReading;
	long lastTime;
	long sampleTime; //milliseconds
	double lastVelocity;

}typedef RedEncoder;

RedEncoder initRedEncoder(int top, int bottom, int inverted);
double getRedEncoderVelocity(RedEncoder *encoder);
int getRedEncoderPosition(RedEncoder *encoder);

#endif /* REDENCODER_H_ */
