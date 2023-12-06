/*
 * EEPROM.c
 *
 *  Created on: Nov 17, 2023
 *      Author: SHAHB
 */
#include "PROTOTYPES.h"
#include "..\..\MCAL\DIO\DIO_AD.h"
#include "../../MCAL/I2C/I2C_HW.h"
#include "..\..\BITMATH.h"

void EEPROM_init()
{
	I2C_INIT() ;
}
void EEPROM_write(uint8 data, uint16 address)
{
	uint8 start_3address = 0x00 ;
	start_3address = (0b1010<<4) | (GET_BIT(address, 10) << 3) | (GET_BIT(address, 9) << 2) | (GET_BIT(address, 8) << 1) ;
	//alternative: start_3address = (0b1010<<4) | ((address>>8)<<1) | CLEAR_BIT(start_3address,0) ;
	uint8 rest_address = (GET_BIT(address, 7) << 7) | (GET_BIT(address, 6) << 6) | (GET_BIT(address, 5) << 5) | (GET_BIT(address, 4) << 4) | (GET_BIT(address, 3) << 3) | (GET_BIT(address, 2) << 2) | (GET_BIT(address, 1) << 1) | GET_BIT(address, 0)  ;
	I2C_void_sendStart() ;
	I2C_void_sendData(start_3address) ;
	I2C_void_sendData(rest_address) ;
	//or I2C_void_sendData((uint8)address) ;
	I2C_void_sendData(data) ;
	I2C_void_sendStop() ;

}
void EEPROM_read(uint16 address, uint8 * data)
{
	uint8 start_3address = (0b1010<<4) | (GET_BIT(address, 10) << 3) | (GET_BIT(address, 9) << 2) | (GET_BIT(address, 8) << 1) ;
	I2C_void_sendStart() ;
	I2C_void_sendData(start_3address) ;
	I2C_void_sendData((uint8)address) ;
	I2C_void_sendStart() ;
	SET_BIT(start_3address, 0) ;
	I2C_void_sendData(start_3address) ;
	I2C_void_Recive_NoAck(data) ;
	I2C_void_sendStop() ;
}
