/*
 * circularBuffer.c
 *
 *  Created on: Feb 13, 2020
 *      Author: Asmaa Hashim
 */



#include "circularBuffer.h"

unsigned char static  buffer[MAX] ,head , tail , val;

void  setVal( unsigned char val)
{

	if((head == MAX -1 && tail == 0) || head+1 == tail )
	{
		tail +=1;

		 if(tail == MAX) tail=0;
	}
	buffer[head]=val;
	head++;

	if(head == MAX) head=0;


}
unsigned char getVal()
{

	if(tail != head)
	{
		val = buffer[tail];

		tail+=1;

		if(tail == MAX)  tail=0;

	}

	return val;
}

