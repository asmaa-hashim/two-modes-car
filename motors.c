/*
 * motors.c
 *
 *  Created on: Feb 10, 2020
 *      Author: Asmaa Hashim
 */



#include "motors.h"

void MOTOR_init()
{
	PINS_DIR();  // macros in motors.h
}

void MOTOR_stop()
{
    SET_BIT(PORTC , PC0) ;  SET_BIT(PORTC , PC1) ;   SET_BIT(PORTC , PC2) ;  SET_BIT(PORTC , PC3) ;
	SET_BIT(PORTA , PA0) ;  SET_BIT(PORTA , PA1) ;   SET_BIT(PORTA , PA2) ;  SET_BIT(PORTA , PA3) ;
}

void GO_forward()
{
	MOTOR1_FORWARD();  MOTOR2_FORWARD();	MOTOR3_FORWARD();    MOTOR4_FORWARD();
}

void GO_backward()
{
	MOTOR1_BACKWARD();   MOTOR2_BACKWARD();    MOTOR3_BACKWARD();    MOTOR4_BACKWARD();
}

void turn_L()
{
	MOTOR1_FORWARD();   MOTOR2_FORWARD();   MOTOR3_BACKWARD();   MOTOR4_BACKWARD();
}

void turn_R()
{
	MOTOR1_BACKWARD();  MOTOR2_BACKWARD();   MOTOR3_FORWARD();   MOTOR4_FORWARD();
}
