/* 
 * File:   I2C_dsPIC.h
 * Author: LENOVO
 *
 * Created on 17 de octubre de 2021, 07:59 PM
 */

#ifndef I2C_DSPIC_H
#define	I2C_DSPIC_H

#include <stdint.h>

#define I2C_ACK    0
#define I2C_nACK   1
#define I2C_WRITE  0b00000000
#define I2C_READ   0b00000001

#define ADDR_PCF1  0b01000000 
#define ADDR_PCF2  0b01001100 
#define ADDR_PCF3  0b01000110 

//Funciones I2C

void I2C_Init(uint16_t F_scl);
void I2C_Start(void);
void I2C_Restart(void);
void I2C_Write_Address_Slave(uint8_t address, uint8_t data_dir);
void I2C_Write_Data_Slave(uint8_t data);
void I2C_Stop(void);
void I2C_Read_Data(uint8_t *Ptr_Data, uint8_t var_Ack_nAck);


#endif	/* I2C_DSPIC_H */

