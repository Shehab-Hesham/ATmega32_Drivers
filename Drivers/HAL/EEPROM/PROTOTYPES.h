/*
 * PROTOTYPES.h
 *
 *  Created on: Nov 17, 2023
 *      Author: SHAHB
 */

#ifndef DRIVERS_MCAL_EEPROM_PROTOTYPES_H_
#define DRIVERS_MCAL_EEPROM_PROTOTYPES_H_

#include "..\..\MCAL\DIO\DIO_AD.h"
#include "..\..\STD.h"

void EEPROM_init() ;
void EEPROM_write(uint8 data, uint16 address) ;
void EEPROM_read(uint16 address, uint8 * data) ;


#endif /* DRIVERS_MCAL_EEPROM_PROTOTYPES_H_ */
