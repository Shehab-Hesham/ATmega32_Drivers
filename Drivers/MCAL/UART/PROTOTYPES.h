/*
 * PROTOTYPES.h
 *
 *  Created on: Nov 4, 2023
 *      Author: SHAHB
 */

#ifndef DRIVERS_MCAL_UART_PROTOTYPES_H_
#define DRIVERS_MCAL_UART_PROTOTYPES_H_

#include "..\..\STD.h"


void UART_init () ;
uint8 UART_recieveData () ;
void UART_sendData (uint8 data) ;
void UART_sendString (uint8 * data) ;

#endif /* DRIVERS_MCAL_UART_PROTOTYPES_H_ */
