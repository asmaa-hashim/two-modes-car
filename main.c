/*
 * main.c
 *
 *  Created on: Feb 10, 2020
 *      Author: Asmaa Hashim
 */

#include"uart.h"

#include "motors.h"

#include "servo.h"

#include "ultrasonic.h"

#include "circularBuffer.h"

unint16 distance_forward , distance_right , distance_L;

 unint8  reseved_val;

void callBack()
{

	unint8 val=UDR;

	setVal(val);

}

int main(void)
{
	uart_cfg_t uart = {_9600 , ONE , _8BITS , Master_Slave , NO_PARITY , 1000000 ,RXIE };

     HAL_uartInit(&uart);
     UART_setCallBack(&callBack);


     MOTOR_init();   SERVO_init();     ULTRASONIC_init();

  while(1)
       {
	        reseved_val=getVal();

           if(reseved_val == 'a')   // begin automatic mode
              {

        	       while(reseved_val != 'c')
        	             {
		                    distance_forward  = read_distance();

		                    if(distance_forward <= 30 )
		                       {

			                     MOTOR_stop();

			                     look_R();

			                     _delay_ms(1000);

			                     distance_right = read_distance();

			                     look_L();

			                     _delay_ms(1000);

			                     distance_L = read_distance();

                                 look_F();

                                 if(distance_right >= distance_L)
                                 {
		                  		      turn_R();

		                  		      GO_forward();

                                  }
                                 else
                                  {
	                     			turn_L();

	                     			GO_forward();
                                  }

		                        } else if(distance_forward > 30)
		                                {
                       		                 GO_forward();
		                                }

		              	                     reseved_val=getVal();

                                     }    // end Automatic mode

	                    }
                 else if(reseved_val == 'c')     // begin control mode
                       {
                                MOTOR_stop();
                             while(reseved_val !='a')
        	                       {


        		                    	if(reseved_val == 'f')
        		                    	{
        				                      GO_forward();
        			                        }
        			                       else if(reseved_val == 'b')
        			                              {

        				                                GO_backward();
        			                                }
        		                     	else if(reseved_val == 'r')
        			                           {

        				                          turn_R();

                                                _delay_ms(1000);

                                                  GO_forward();
        	                                      }
        		                	else if(reseved_val == 'l')
        		                        	{

        		                           		turn_L();

        			                    	 _delay_ms(1000);

                                               GO_forward();
        			                           }
                               	                 reseved_val=getVal();

        	                    }   // end control mode when the user choose automatic mode
                                   MOTOR_stop();
                                   }
                             } // end while(1)
                        }               // end main method
