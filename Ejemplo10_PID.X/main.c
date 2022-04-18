/* 
 * File:   main.c
 * Author: cd_te
 *
 * Created on 17 de abril de 2022, 06:40 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "Configuracion.h"
#include <libpic30.h>
#include "PWM.h"
#include "TIMER.h"
#include "UART.h"
#include "PID.h"
#include <xc.h>

//#define PID_KP 0.0121
//#define PID_KI 0.3893
//#define PID_KD 1.089E-5
#define PID_KP 0.026436
#define PID_KI 0.64136
#define PID_KD 0
#define PID_TAU 0
#define PID_LMAX 9.3
#define PID_LMIN 0
#define PID_Ts 10E-3 //tiempo de muestreo
#define S 120


ControladorPID MotorDC = {PID_KP,PID_KI,PID_KD,PID_TAU,PID_LMAX,PID_LMIN,PID_Ts};
//ControladorPID Planta_Nivel;
//ControladorPID ServoMotor;
//ControladorPID Horno;


void gpio_init(void);
void __attribute__ ((interrupt,no_auto_psv ))_T1Interrupt(void);
void __attribute__ ((interrupt,no_auto_psv ))_U2RXInterrupt(void);

uint16_t PULSOS,i=0;
float rpm,FrecAngular,ref,U;
char DataTX[50],DataRX[50];

int main(int argc, char** argv) {
    UART_Init(9600);
    Timer2Contador();
    TiempoMuestro();
    OC1_PWM();
    gpio_init();
    asm("nop");
    Controlador_PID(&MotorDC);
    
    for(;;){
    
    
    
    }
    
    return (EXIT_SUCCESS);
}

void gpio_init(void){

    TRISDbits.TRISD3 = 0;//LED DE FUNCIONAMIENTO
    TRISBbits.TRISB9 = 0;
    TRISBbits.TRISB10 = 0;
    LATBbits.LATB9 = 0;
    LATBbits.LATB10 = 1;

}


void __attribute__ ((interrupt,no_auto_psv ))_T1Interrupt(void){
    
    /*calculamos los pulsos*/
    PULSOS = TMR2;//CALCULO LOS NUMERO DE PULSOS
    TMR2 =0; // VUELVE A INICIAR LA CUENTA
    
    /*calculamos los rpm y la frecuencia angular*/
    rpm = PULSOS*60.0/(0.01*S);
    FrecAngular = rpm*(2*3.14159265359)/60;
    
    //calculo del PID
    U = ControladorPID_Calculo(&MotorDC,ref,FrecAngular)*799/PID_LMAX;
    OC1RS = (uint16_t)  U;
    
    /*enviamos los datos a la pc*/
    sprintf((char*)DataTX,"%.2f\n\r",FrecAngular);
    UART_TX_String(DataTX);
    LATDbits.LATD3 = ~LATDbits.LATD3;
    IFS0bits.T1IF = 0;
    
}
void __attribute__ ((interrupt,no_auto_psv ))_U2RXInterrupt(void){
    char ch;
    if (U2STAbits.OERR == 1) {
        U2STAbits.OERR = 0;
    }
    else if ((U2STAbits.PERR==0) && (U2STAbits.FERR==0)) {
    ch = (char)U2RXREG; 
    }
   
    if (ch == 'D') {
    LATBbits.LATB9 = 0;
    LATBbits.LATB10 = 1;
    }
    else  if (ch == 'I') {
    LATBbits.LATB9 = 1;
    LATBbits.LATB10 = 0;
    }else  if (ch == 'x') {
        ref = atof(DataRX);
        memset(DataRX,0,i);
        i=0;
    }else{
        DataRX[i]=ch;
        i++;
    }

   
    
  IFS1bits.U2RXIF = 0;        //Borramos la bandera de interrupcion

}