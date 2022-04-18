/* 
 * File:   main.c
 * Author: LENOVO
 *
 * Created on 26 de marzo de 2022, 12:15 PM
 */
#include <xc.h>
#include "main.h"
#include "LCD_dsPIC.h"


// DSPIC33FJ32MC304 Configuration Bit Settings

// 'C' source line config statements

// FBS
#pragma config BWRP = WRPROTECT_OFF     // Boot Segment Write Protect (Boot Segment may be written)
#pragma config BSS = NO_FLASH           // Boot Segment Program Flash Code Protection (No Boot program Flash segment)

// FGS
#pragma config GWRP = OFF               // General Code Segment Write Protect (User program memory is not write-protected)
#pragma config GSS = OFF                // General Segment Code Protection (User program memory is not code-protected)

// FOSCSEL
#pragma config FNOSC = PRI              // Oscillator Mode (Primary Oscillator (XT, HS, EC))
#pragma config IESO = ON                // Internal External Switch Over Mode (Start-up device with FRC, then automatically switch to user-selected oscillator source when ready)

// FOSC
#pragma config POSCMD = XT              // Primary Oscillator Source (XT Oscillator Mode)
#pragma config OSCIOFNC = OFF           // OSC2 Pin Function (OSC2 pin has clock out function)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow Only One Re-configuration)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor (Both Clock Switching and Fail-Safe Clock Monitor are disabled)

// FWDT
#pragma config WDTPOST = PS32768        // Watchdog Timer Postscaler (1:32,768)
#pragma config WDTPRE = PR128           // WDT Prescaler (1:128)
#pragma config WINDIS = OFF             // Watchdog Timer Window (Watchdog Timer in Non-Window mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (Watchdog timer enabled/disabled by user software)

// FPOR
#pragma config FPWRT = PWR128           // POR Timer Value (128ms)
#pragma config ALTI2C = OFF             // Alternate I2C  pins (I2C mapped to SDA1/SCL1 pins)
#pragma config LPOL = ON                // Motor Control PWM Low Side Polarity bit (PWM module low side output pins have active-high output polarity)
#pragma config HPOL = ON                // Motor Control PWM High Side Polarity bit (PWM module high side output pins have active-high output polarity)
#pragma config PWMPIN = ON              // Motor Control PWM Module Pin Mode bit (PWM module pins controlled by PORT register at device Reset)

// FICD
#pragma config ICS = PGD1               // Comm Channel Select (Communicate on PGC1/EMUC1 and PGD1/EMUD1)
#pragma config JTAGEN = OFF             // JTAG Port Enable (JTAG is Disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.



volatile uint8_t i=0;
void __attribute__ ((interrupt,no_auto_psv)) _T1Interrupt(void){
    
    LATC ^= (1<<0);
 IFS0bits.T1IF = 0;
}
void __attribute__ ((interrupt,no_auto_psv)) _T2Interrupt(void){
   
    LATC ^= (1<<1);
  IFS0bits.T2IF = 0;
}
void __attribute__ ((interrupt,no_auto_psv)) _T3Interrupt(void){
    
    
    LATC ^= (1<<2);
 IFS0bits.T3IF = 0;
}


void timers_temporizador(void);
void timers_contador(void);
int main(int argc, char** argv) {

    TRISC=0X0000;
    
        //ISR-> 3 // TM3
        T2CONbits.TON = 0;//apagamos el timer 2
        T3CONbits.TON = 0;//apagamos el timerr 3
        T2CONbits.T32 = 1;//habilitado la configuracion del timer de 32 bits
        T2CONbits.TCS = 0;//reloj interno //temporizador
        T2CONbits.TGATE = 0;//desabilitmos el gate
        T2CONbits.TCKPS = 0b01;//el preescalador de 64 bits
       //937,500-1 > 937499  E 4E1B
        TMR2 = 0;
        TMR3 = 0;
        PR3 = 0X000E;
        PR2 = 0x4E1B;//3905;        
        IEC0bits.T3IE = 1;//Habilitamos interrupcion por desbordamiento
        IFS0bits.T3IF = 0;//limpiamos flag
        IPC2bits.T3IP = 3;//Prioridad 2
        T2CONbits.TON = 1;//Enciende Timer32
    
   
    
    for(;;){
    
    
    
    
    
    }
    
    return (EXIT_SUCCESS);
}
void timers_contador(void){
   //Timer 3 en modo contador:
       //Timer3 
    T3CONbits.TON = 0;//timer apgado
    T3CONbits.TCS = 1;//TICK3
    T3CONbits.TGATE = 0;
    T3CONbits.TCKPS = 0b00;//prescalador de 8
    TRISB |= (1<<14);
    RPINR3bits.T3CKR = 0XE;
    
    //33 ms-> 
    /*FCY = 5MHZ
     * PR3 -> FCY*T/PRE -1
     *  -> 5MZ*50MS/
     * PR3 -> 20,625 -1
     * PR3 -> 20624
     */
    PR3 = 4;
    TMR3 = 0;//Sin carga
    IEC0bits.T3IE = 1;//  habilitamos la interrucpion
    IFS0bits.T3IF = 0;
    IPC2bits.T3IP = 3;
    T3CONbits.TON = 1;//timer encendido
    


}
void timers_temporizador(void){

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
    
    
    
    
    //Timer 2 
    T2CONbits.TON = 0;//timer apgado
    T2CONbits.TCS = 0;//fcy
    T2CONbits.TGATE = 0;
    T2CONbits.TCKPS = 0b10;//prescalador de 64
    //100 ms -> 
    /*FCY = 5MHZ
     * PR2 -> FCY*T/PRE -1
     *  -> 5MZ*50MS/
     * PR2 -> 
     * PR2 -> 7,812
     */
    PR2 = 7812;
    TMR2 = 0;//Sin carga
    IEC0bits.T2IE = 1;//  habilitamos la interrucpion
    IFS0bits.T2IF = 0;
    IPC1bits.T2IP = 4;
    T2CONbits.TON = 1;//timer encendido
    
    
    
    //Timer3 
    T3CONbits.TON = 0;//timer apgado
    T3CONbits.TCS = 0;//fcy
    T3CONbits.TGATE = 0;
    T3CONbits.TCKPS = 0b01;//prescalador de 8
    //33 ms-> 
    /*FCY = 5MHZ
     * PR3 -> FCY*T/PRE -1
     *  -> 5MZ*50MS/
     * PR3 -> 20,625 -1
     * PR3 -> 20624
     */
    PR3 = 20624;
    TMR3 = 0;//Sin carga
    IEC0bits.T3IE = 1;//  habilitamos la interrucpion
    IFS0bits.T3IF = 0;
    IPC2bits.T3IP = 3;
    T3CONbits.TON = 1;//timer encendido
}