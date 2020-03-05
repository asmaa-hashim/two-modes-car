/*
 * ultrasonic.c
 *
 *  Created on: Feb 10, 2020
 *      Author: Asmaa Hashim
 */

#include "ultrasonic.h"

/***************global variables  ********************/

volatile unint32 i , num_of_over_flow=0  , ticks_num ;

//volatile static unint8  flag=0;

unint32 distance ;

/******************     static functions      ************************/
static void INT0_init()
{
	DDRD &=~(1U << PD2);                       // configure  INT0 pin as input pin

	GICR |= (1U << INT0);                      // enable external interrupt INT0

	MCUCR |=  (1U << ISC00) | (1u << ISC01);  // interrupt sense control on rising edge

	SREG |= (1U << 7);                       // enable global interrupt
}

// these functions is used to generate PWM with width 10us for the  trigger pin
static void Timer2_Fast_PWM_Init()
{
   TCNT2 = 0;
   TCCR2 |=(1<< WGM21) | (1 << WGM20) | (1 << COM21) |(1 << CS20);
   OCR2 =10;
   DDRD |=(1 << PD7);         // OCR2 AS OUTPUT PIN
 }

//static void Timer2_enable()
//{
	   //TCCR2 |=(1<< WGM21) | (1 << WGM20) | (1 << COM21) |(1 << CS20);
   //}

//static void Timer2_disable()
//{
	//   TCCR2 =0;
//}


// this function is used with INT0 to calculate the width of external clock

static void timer0_init()
{
	SREG &= ~(1U << 7U);
	TCNT0 = 0;
    TIMSK |=(1U << TOIE0);
	TCCR0 = (1<<FOC0) | (1<<CS01) | (1<<CS00);  // CLK/64
    SREG |=(1U << 7U);
}

/********  these two functions will include them in the main function ********/

void ULTRASONIC_init() // this function will enable the trigger pin of ultrasonic & enable INT0 & enable timer0
{
	Timer2_Fast_PWM_Init();
    INT0_init();
    timer0_init();
}

unint32 read_distance() // this function returns the distance in cm
{
	//Timer2_enable();




//	while(!flag);       flag=0;

	distance = ((float)((float)(ticks_num * 64) / 1000000) / 2) * 34000 ;

    return distance;
}

/************************* ISR functions ************************/

ISR(INT0_vect)
{
	//Timer2_disable();

	i++;
   if(i==1)
	 {
		  TCNT0=0 ;     num_of_over_flow=0;
    	  MCUCR |= (1<< ISC01) ;    // interrupt sense control on falling edge
       }
	else
	{
		ticks_num = TCNT0 + (num_of_over_flow * 256 );
		//flag=1;
		i=0;
  	  MCUCR |=  (1U << ISC00) | (1<< ISC01) ;      // interrupt sense control on rising edge

    }
}

ISR(TIMER0_OVF_vect)
{
	num_of_over_flow++;

}
