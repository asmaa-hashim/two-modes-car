/*
 * uart.h
 *
 *  Created on: Feb 10, 2020
 *      Author: Asmaa Hashim
 */

#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include "data_types.h"
#include <avr/interrupt.h>

/****************************************************************************************************************************
 * 												UART Definitions
 * **************************************************************************************************************************/
#define NULL	(void*)0


/****************************************************************************************************************************
 * 												UART Data Structures
 * **************************************************************************************************************************/
typedef enum{ _9600 = 9600 }baudRate;

typedef enum{ Master = 1 , Slave = 2 , Master_Slave = 3 }mode;

typedef enum{ ONE = 0 , TWO = 1 }stopBits;

typedef enum{ _5BITS  = 0 , _6BITS = 1 , _7BITS = 2 , _8BITS  = 3, _9BITS  = 7}dataBits;

typedef enum{ ODD_PARITY = 3 , EVEN_PARITY = 2 , NO_PARITY = 0 }parity;

typedef enum{RXIE=1 , RXID=0  }INT_config;

typedef enum{ INVALID_OBJ , OK }uart_error;


// Sync || Async
//Double speed || no

typedef struct{
	baudRate	     baud;
	stopBits		 stop_bits;
	dataBits         data_bits;
	mode      		 mode;
	parity			 parity;
	unint32			 F_IO_clk;
	INT_config      INT_mode ;
}uart_cfg_t;
/****************************************************************************************************************************
 * 												UART Global Functions Prototypes
 * **************************************************************************************************************************/

uart_error HAL_uartInit(uart_cfg_t *obj);
uart_error HAL_uartSendByte(unint8 byte);
uart_error HAL_uartRecieveByte( unint8 *byte);

uart_error HAL_uartSendString( unint8 *str);
uart_error HAL_uartRecieveString( unint8 *str);

void UART_setCallBack(void(*a_ptr)(void));


#endif /* UART_H_ */
