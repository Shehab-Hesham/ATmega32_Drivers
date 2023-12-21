
#ifndef I2C_HW_H_
#define I2C_HW_H_

/******************************************
  INCLUDES
*******************************************/
#include "..\..\STD.h"
#define READ 0
#define WRITE 1
/*I2c Registers*/
#define TWBR            *((volatile uint8*)(0x20))

#define TWCR            *((volatile uint8*)(0x56))
#define TWCR_TWINT_BIT     7
#define TWCR_TWEA_BIT      6
#define TWCR_TWSTA_BIT     5
#define TWCR_TWSTO_BIT     4
#define TWCR_TWWC_BIT      3
#define TWCR_TWEN_BIT      2
#define TWCR_TWIE_BIT      0

#define TWSR            *((volatile uint8*)(0x21))
#define TWSR_TWPS0_BIT  0
#define TWSR_TWPS1_BIT  1
#define TWSR_TWS3_BIT   3
#define TWSR_TWS4_BIT   4
#define TWSR_TWS5_BIT   5
#define TWSR_TWS6_BIT   6
#define TWSR_TWS7_BIT   7

#define TWDR            *((volatile uint8*)(0x23))
#define TWDR_TWD0_BIT   0

#define TWAR             *((volatile uint8*)(0x22))
#define TWAR_TWGCE_BIT

void I2C_INIT() ;
void I2C_void_sendStart() ;
void I2C_void_setAddress(uint8 SLA_W, uint8 state) ;
void I2C_void_sendData(uint8 data) ;
void I2C_void_sendStop() ;
void I2C_void_Recive_Ack(uint8 * data) ;
void I2C_void_Recive_NoAck(uint8 * data) ;

#endif /* MCU_HW_H_ */
