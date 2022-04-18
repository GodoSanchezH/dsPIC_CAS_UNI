/* 
 * File:   Uart_dspic.h
 * Author: LENOVO
 *
 * Created on 11 de octubre de 2021, 08:18 PM
 */

#ifndef UART_DSPIC_H
#define	UART_DSPIC_H

#include <stdint.h>
#include <stdbool.h>

typedef enum{
    one_bit_Stop,
        two_bit_Stop
}Bist_stop;

typedef enum{
    Ocho_D_SP,
        Ocho_D_EP,
            Ocho_D_OP,
            Nueve_D_SP
}Data_Parity;

#

void UART_dsPIC_Init(uint32_t Baudios,bool Stop_bit,uint8_t Data_P,uint8_t IPC_RX);
void UART_Tx_Char(char Caracter);
void UART_Tx_String(char *str);


#endif	/* UART_DSPIC_H */

