#include "TIMER.h"
#include <xc.h>



void TiempoMuestro(void){
/*Formula de Temporización
 * PRX = FCY*TIEMPO/Pres - 1;
 * PRX = 1seg*5000000/1 - 1 = 23999999
 * PRX = 1seg*5000000/8 - 1 = 2999999
 * PRX = 1seg*5000000/64 - 1 = 374999
 * PRX = 1seg*5000000/256 - 1 = 93749
 * 
*/
    T1CONbits.TON = 0;
    T1CONbits.TCS = 0; // Temporizador
    T1CONbits.TCKPS =1;
    PR1 = 9999;//10ms
    TMR1 = 0;
    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = 1;
    IPC0bits.T1IP = 4;
    T1CONbits.TON = 1;
}
void Timer2Contador(void){

    T2CONbits.TON = 0;          //Apagamos el TIMER 1
    T2CONbits.TCS = 1;          //Modo Contador -> External clock

    //Configuramos el pin de entrada para el External Clock
    TRISCbits.TRISC13 = 1;          
    //Seleccionamos el Preescaler
    T2CONbits.TCKPS = 0b00;      
    PR2 = 0xFFFF;
    TMR2 = 0;                //Cuenta desde TMRX hasta PRX
    T2CONbits.TON = 1;          //Encendemos el modulo TIMER 1
            
}

