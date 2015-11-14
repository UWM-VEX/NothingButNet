/*
 * IME.h
 *
 *  Created on: Mar 18, 2015
 *      Author: Erik
 */

#ifndef IME_H_
#define IME_H_

struct IME{

	int port;
	int inverted;

}typedef IME;

IME initIME(int port, int inverted);
int getIME(IME ime);
int getIMEVelocity(IME ime);

#endif /* IME_H_ */
