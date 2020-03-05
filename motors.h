/*
 * motors.h
 *
 *  Created on: Feb 10, 2020
 *      Author: Asmaa Hashim
 */

#ifndef MOTORS_H_
#define MOTORS_H_


#include "std_macros.h"
#include <avr/io.h>

/*************************   MACROS *******************/

#define PINS_DIR() SET_BIT(DDRC , PC0) ;\
                   SET_BIT(DDRC , PC1) ;\
                   SET_BIT(DDRC , PC2) ;\
                   SET_BIT(DDRC , PC3) ;\
                   SET_BIT(DDRA , PA0) ;\
                   SET_BIT(DDRA , PA1) ;\
                   SET_BIT(DDRA , PA2) ;\
                   SET_BIT(DDRA , PA3)

#define MOTOR1_FORWARD()  SET_BIT(PORTC , PC0) ;  CLEAR_BIT(PORTC , PC1)

#define MOTOR1_BACKWARD()  SET_BIT(PORTC , PC1) ;  CLEAR_BIT(PORTC , PC0)

#define MOTOR2_FORWARD()  SET_BIT(PORTC , PC2) ;  CLEAR_BIT(PORTC , PC3)

#define MOTOR2_BACKWARD()  SET_BIT(PORTC , PC3) ;  CLEAR_BIT(PORTC , PC2)

#define MOTOR3_FORWARD()  SET_BIT(PORTA , PA0) ;  CLEAR_BIT(PORTA , PA1)

#define MOTOR3_BACKWARD()  SET_BIT(PORTA , PA1) ;  CLEAR_BIT(PORTA , PA0)

#define MOTOR4_FORWARD()  SET_BIT(PORTA , PA2) ;  CLEAR_BIT(PORTA , PA3)

#define MOTOR4_BACKWARD()  SET_BIT(PORTA , PA3) ;  CLEAR_BIT(PORTA , PA2)

/***************** FUNCTIONS PROTOYPES ***************************/

void MOTOR_init();
void MOTOR_stop();
void GO_forward();
void GO_backward();
void turn_L();
void turn_R();
#endif /* MOTORS_H_ */
