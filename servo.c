/*
 * servo.c
 *
 *  Created on: Feb 10, 2020
 *      Author: Asmaa Hashim
 */

#include "servo.h"

static void Timer1_Fast_PWM_Init(unsigned short duty_cycle)
{

	TCNT1 = 0;		/* Set timer1 initial count to zero */
	ICR1 = 2499;	/* top value */
    OCR1A = duty_cycle;
    TCCR1A = (1<<WGM11) | (1<<COM1A1);
      /* Configure timer control register TCCR1A
	 * 1. Fast Pwm Mode with the TOP in ICR1 WGM12=1 WGM13=1 (Mode Number 14)
	 * 2. Prescaler = F_CPU/8   set CS11
     */
	TCCR1B = (1<<WGM12) | (1<<WGM13)  | (1<<CS11);
}

 void SERVO_init()
{
	DDRD |= (1<<PD5);	        /* Make OC1A pin as output */

	look_F();
}
void look_R()
{
	Timer1_Fast_PWM_Init(124);	/* Set Servo shaft at 0° position by 1 ms pulse */
}

void look_L()
{
	Timer1_Fast_PWM_Init(250);	/* Set Servo shaft at 180° position by 2 ms pulse */
}

void look_F()
{
	Timer1_Fast_PWM_Init(187);  /* Set Servo shaft at 90° position by 1.5 ms pulse */
}



