/* 
 * File:   Uart_dsPIC.h
 * Author: LENOVO
 *
 * Created on 27 de marzo de 2022, 12:22 PM
 */

#ifndef UART_DSPIC_H
#define	UART_DSPIC_H

#include "main.h"


void Uart_Init(uint32_t Baud);//INgreso de parametro serialbegin9600
void Uart_Tx_CHAR(char caracter);
void Uart_Tx_STRING(char *Str);


#endif	/* UART_DSPIC_H */

