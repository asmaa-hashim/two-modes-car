/*
 * ultrsonic.h
 *
 *  Created on: Feb 10, 2020
 *      Author: Asmaa Hashim
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include <avr/interrupt.h>

#include <avr/io.h>

#include "data_types.h"
#include <util/delay.h>

void ULTRASONIC_init();

unint32 read_distance();

#endif /* ULTRASONIC_H_ */
