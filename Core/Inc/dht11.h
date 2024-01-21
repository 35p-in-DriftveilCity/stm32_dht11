/*
 * dht11.h
 *
 *  Created on: Jan 15, 2024
 *      Author: USER
 */

#ifndef SRC_DHT11_H_
#define SRC_DHT11_H_

#include "main.h"

extern int Temperature;
extern int Humidity;

int dht11_read(void);


#endif /* SRC_DHT11_H_ */
