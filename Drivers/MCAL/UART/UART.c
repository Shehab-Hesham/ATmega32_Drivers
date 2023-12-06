/*
 * UART.c
 *
 *  Created on: Nov 4, 2023
 *      Author: SHAHB
 */

#include "..\..\STD.h"
#include "../../BITMATH.h"
#include "..\DIO/DIO_AD.h"
#include "PROTOTYPES.h"
#include "UART_PRIV.h"
#include "UART_CINFIG.h"


void UART_init ()
{
	CLEAR_BIT(UCSRB, RXCIE) ;
	CLEAR_BIT(UCSRB, TXCIE) ;
	CLEAR_BIT(UCSRB, UDRIE) ;
	SET_BIT(UCSRB, RXEN) ;
	SET_BIT(UCSRB, TXEN) ;

	uint8 dummy = 0x00 ;
	dummy = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1) ;
	UCSRC_UBRRH = dummy ;

	UCSRC_UBRRH = 0x00 ;
	UBRRL = 103 ;

}
uint8 UART_recieveData ()
{
	uint16 dummyTime = 0xFFFF ;
	while(!GET_BIT(UCSRA, RXC))
	{
		dummyTime-- ;
		if (dummyTime == 0)
			return 'x' ;
	}
	return UDR ;
}
void UART_sendData (uint8 data)
{
	while (!GET_BIT(UCSRA, UDRE)) ;
	UDR = data ;
}
void UART_sendString (uint8 * data)
{
	uint8 counter ;
	for(counter = 0 ; data[counter] != '0' ; counter++)
		UART_sendData(data[counter]) ;
}
