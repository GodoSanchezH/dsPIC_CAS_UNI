/* 
 * File:   main.c
 * Author: LENOVO
 *
 * Created on 26 de marzo de 2022, 12:15 PM
 */
#include <xc.h>
#include "main.h"
#include "LCD_dsPIC.h"

volatile uint8_t i=0;
void __attribute__ ((interrupt,no_auto_psv)) _T1Interrupt(void){
    i++;
    LATC = i;
    
 IFS0bits.T1IF = 0;
}

int main(int argc, char** argv) {

    TRISC=0X0000;
    
    
    //Timer 1 Temporizador
    T1CONbits.TON = 0;//timer apgado
    T1CONbits.TCS = 0;//fcy
    T1CONbits.TGATE = 0;
    T1CONbits.TCKPS = 0b11;//prescalador de 256
    //50 ms -> 
    /*FCY = 5MHZ
     * PR1 -> FCY*T/PRE -1
     *  -> 5MZ*50MS/
     * PR1 -> 977 -1
     * PR1 -> 976
     */
    PR1 = 976;
    TMR1 = 0;//Sin carga
    IEC0bits.T1IE = 1;//  habilitamos la interrucpion
    IFS0bits.T1IF = 0;
    IPC0bits.T1IP = 5;
    T1CONbits.TON = 1;//timer encendido
    
    for(;;){
    
    
    
    
    
    }
    
    return (EXIT_SUCCESS);
}

