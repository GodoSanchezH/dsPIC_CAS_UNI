/* 
 * File:   main.c
 * Author: LENOVO
 *
 * Created on 26 de marzo de 2022, 10:44 AM
 */

#include "main.h"
#include "LCD_dsPIC.h"
#include "Interrup_dsPIC.h"

volatile uint8_t i;


int main(int argc, char** argv) {
    
    //INT0 - Interrupt B7

    
//    IPC0bits.INT0IP0 = 1;
//    IPC0bits.INT0IP1 = 1;
//    IPC0bits.INT0IP2 = 0;
    
    //INT1 - Interrupt B14

    //INT2 - Interrupt B15
    
    
    //definicion de gpio
    TRISC = 0X0000;//PUERTO COMO SALIDA
    
    Interrupt_Config(INT0,PRIORI6,F_bajada);
    Interrupt_Config(INT1,PRIORI5,F_bajada);
    Interrupt_Config(INT2,PRIORI4,F_subida);
    
    for(;;){
    
    
    }
    

    return (EXIT_SUCCESS);
}

