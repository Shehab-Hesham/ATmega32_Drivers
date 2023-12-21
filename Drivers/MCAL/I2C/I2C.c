/*
 * I2C.c
 *
 *  Created on: Nov 11, 2023
 *      Author: SHAHB
 */

#include "..\..\STD.h"
#include "../../BITMATH.h"
#include "..\DIO/DIO_AD.h"
#include "I2C_HW.h"
void I2C_INIT()
{
	TWBR = 72 ;
}

void I2C_void_sendStart()
{
	TWCR |= (1<<TWCR_TWINT_BIT )|(1<<TWCR_TWSTA_BIT)|
	(1<<TWCR_TWEN_BIT) ;
	while (!(TWCR & (1<<TWCR_TWINT_BIT))) ;
}
void I2C_void_setAddress(uint8 SLA_W, uint8 state)
{
	TWDR = (SLA_W<<1) ;
	if (state == WRITE)
	{
		CLEAR_BIT(TWDR, 0) ;
	}
	else if (state == READ)
	{
		SET_BIT(TWDR, 0) ;
	}
	TWCR = (1<<TWCR_TWINT_BIT) | (1<<TWCR_TWEN_BIT);
	while (!(TWCR & (1<<TWCR_TWINT_BIT))) ;
}
void I2C_void_sendData(uint8 data)
{
	TWDR = (data) ;
	TWCR = (1<<TWCR_TWINT_BIT) | (1<<TWCR_TWEN_BIT);
	while (!(TWCR & (1<<TWCR_TWINT_BIT))) ;
}
void I2C_void_sendStop()
{
	TWCR = (1<<TWCR_TWINT_BIT) | (1<<TWCR_TWEN_BIT) | (1<<TWCR_TWSTO_BIT) ;
}
void I2C_void_Recive_Ack(uint8 * data)
{
	SET_BIT(TWDR, 0) ;
	TWCR = (1<<TWCR_TWINT_BIT) | (1<<TWCR_TWEN_BIT) | (1<<TWCR_TWEA_BIT);
	while (!(TWCR & (1<<TWCR_TWINT_BIT))) ;
	*data = TWDR ;
}
void I2C_void_Recive_NoAck(uint8 * data)
{
	SET_BIT(TWDR, 0) ;
	TWCR = (1<<TWCR_TWINT_BIT) | (1<<TWCR_TWEN_BIT) ;
	while (!(TWCR & (1<<TWCR_TWINT_BIT))) ;
	*data = TWDR ;
}
