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

	RedEncoder newEncoder = {encoder, 0, millis(), 125, 0.0};

	return newEncoder;
}

double getRedEncoderVelocity(RedEncoder *encoder)
{
	if((millis() - (*encoder).lastTime) > (*encoder).sampleTime)
	{
		double dPosition = (double) (encoderGet((*encoder).encoder) -
				(*encoder).lastReading);

		int dTime = (int) (millis() - (*encoder).lastTime);

		double velocity = dPosition / dTime;

		(*encoder).lastReading = encoderGet((*encoder).encoder);
		(*encoder).lastTime = millis();
		(*encoder).lastVelocity = velocity;

		puts("Update");

		return velocity;
	}
	else
	{
		puts("No");
		return (*encoder).lastVelocity;
	}
}

int getRedEncoderPosition(RedEncoder *encoder)
{
	return encoderGet((*encoder).encoder);
}
