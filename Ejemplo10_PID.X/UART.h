/* 
 * File:   UART.h
 * Author: cd_te
 *
 * Created on 16 de abril de 2022, 10:37 PM
 */

#ifndef UART_H
#define	UART_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void UART_Init(uint32_t Baud_Rate);
void UART_TX_Char(char Caracter);
void UART_TX_String(char *str);

#endif	/* UART_H */

