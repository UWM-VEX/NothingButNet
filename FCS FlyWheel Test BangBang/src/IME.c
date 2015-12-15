/*
 * IME.c
 *
 *  Created on: Mar 18, 2015
 *      Author: Erik
 */


#include "main.h"

IME initIME(int port, int inverted)
{
	IME newIME = {port, inverted};
	return newIME;
}

int getIME(IME ime)
{
	int value;

	imeGet(ime.port, &value);

	return (ime.inverted) ? -value : value;
}

int getIMEVelocity(IME ime)
{
	int value;

	imeGetVelocity(ime.port, &value);

	return (ime.inverted) ? -value : value;
}
