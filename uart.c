/*
 * uart.c
 *
 *  Created on: Feb 10, 2020
 *      Author: Asmaa Hashim
 */



#include "uart.h"



void (*ptr_fun)(void)=NULL;

/***********interrupt service routine ***********/

ISR(USART_RXC_vect)
{
	if(ptr_fun !=NULL){

		ptr_fun();

		}
	//reseved_val=UDR;
}

uart_error HAL_uartInit(uart_cfg_t *obj)
{
	if(obj != NULL)
	{
//		UCSRA |= 1<<U2X;
		UCSRB = (UCSRC & 0xE7) | (obj->mode << 3);/*  Write to the 3rd and 4th bits  to choose master , slave or master slave mode*/
		UCSRB |=(obj->INT_mode << 7);
		UCSRC |=  1<<URSEL;                       /*  To Enable Writing to the UCSRC register */
		UCSRC = (UCSRC & 0xCF) | (obj->parity << 4);  /*  Write the 4th and 5th bits with the value presented in cfg struct  to choose parity or not*/
		UCSRC = (UCSRC & 0xF7) | (obj->stop_bits << 3);
		UCSRC = (UCSRC & 0xF9) | (obj->data_bits << 1);/*  write to 2nd and 3rd bits to choose the number of data bits in the frame 5,6,7,8,9*/
		unint16 baud = ((obj->F_IO_clk / ((unint32)16 * obj->baud)) - 1); /*  UBRR = (Fosc / (16UL * BAUD)) - 1*/
		UBRRH = baud >> 8;
		UBRRL = baud;

	}
	else
	{
		return INVALID_OBJ;
	}
	return OK;
}
uart_error HAL_uartSendByte( unint8 byte)
{
	while(!(UCSRA & (1<<UDRE))); 		  /*wait until data buffer is empty*/
	UDR = byte;
	return OK;
}
uart_error HAL_uartRecieveByte( unint8 *byte)
{
	while(!(UCSRA & (1<<RXC))); /*Wait until the last receiving operation(bit)  is complete*/
	*byte = UDR;
	return OK;
}
uart_error HAL_uartSendString(unint8 *str)
{
	while(*str != '\0')
	{
		HAL_uartSendByte(*str);
		str++;
	}
	return OK;
}
uart_error HAL_uartRecieveString(unint8 *str)
{
	unint8 i = 0;
	HAL_uartRecieveByte(&str[i]);
	while(str[i] != '#')
	{
		i++;
		HAL_uartRecieveByte(&str[i]);
	}
	str[i] = '\0';
	return OK;
}

void UART_setCallBack(void(*u_ptr)(void))
{
       ptr_fun=u_ptr;
}
