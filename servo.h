/*
 * servo.h
 *
 *  Created on: Feb 10, 2020
 *      Author: Asmaa Hashim
 */

#ifndef SERVO_H_
#define SERVO_H_

#include <avr/io.h>

#include <util/delay.h>

void SERVO_init();

void look_R();

void look_L();

void look_F();


#endif /* SERVO_H_ */
