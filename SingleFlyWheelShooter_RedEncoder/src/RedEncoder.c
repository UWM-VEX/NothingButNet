/*
 * RedEncoder.c
 *
 *  Created on: Oct 8, 2015
 *      Author: Erik
 */

#include "main.h"

RedEncoder initRedEncoder(int top, int bottom, int inverted)
{
	Encoder encoder = encoderInit(top, bottom, inverted);

	RedEncoder newEncoder = {encoder, 0, millis(), 250, 0};

	return newEncoder;
}

double getRedEncoderVelocity(RedEncoder *encoder)
{
	if(millis() - (*encoder).lastTime > (*encoder).sampleTime)
	{
		int dPosition = encoderGet((*encoder).encoder) -
				(*encoder).lastReading;

		int dTime = (int) (millis() - (*encoder).lastTime);

		double velocity = (dPosition + 1.0) / dTime;

		(*encoder).lastReading = encoderGet((*encoder).encoder);
		(*encoder).lastTime = millis();
		(*encoder).lastVelocity = velocity;

		return velocity;
	}
	else
	{
		return (*encoder).lastVelocity;
	}
}

int getRedEncoderPosition(RedEncoder *encoder)
{
	return encoderGet((*encoder).encoder);
}
