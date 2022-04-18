/* 
 * File:   main.c
 * Author: cd_te
 *
 * Created on 10 de abril de 2022, 10:33 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Configuracion.h"
#include <libpic30.h>
#include "I2C_dspic.h"
#include "ADC_dspic.h"
#include "Timer_dsPIC.h"
#include <xc.h>
#include <dsp.h>


extern FIRStruct lowpassexampleFilter;
#define Block 1
fractional FilterOut[Block];

bool bandera;
uint16_t ADC_READ;

void __attribute__((interrupt,no_auto_psv)) _T3Interrupt(void){
        ADC_READ  =  AnalogRead(AN0);
        bandera = 1;
        IFS0bits.T3IF = 0;//limpiamos flag
}




uint16_t i,salida;
float Temporal;
 uint8_t Val_H,Val_L;
int main(int argc, char** argv) {

   I2C_Init(100);//100 KHZ
   Analog_Init(Modo_12bits);
   Timer_Temporizador(Timer3,0,0.02,64);

   char *apuntador = NULL;
   apuntador = &FilterOut;
   
   
    FIRDelayInit(&lowpassexampleFilter); 
//    FIRDelayInit(&bandpassexampleFilter); 
//    FIRDelayInit(&highpassexampleFilter); 
    for(;;){
 
        if (bandera) {
            
            FIR(Block,&FilterOut,&ADC_READ,&lowpassexampleFilter);
            Val_H = apuntador[1];
            Val_L = apuntador[0];
            
            I2C_Start();
            I2C_Write_Address_Slave(0b11000000,I2C_WRITE);
            I2C_Write_Data_Slave(Val_H & 0x0F);
            I2C_Write_Data_Slave(Val_L);   
            I2C_Stop();
            bandera=0;
            
        }

        
    
    }
    
    
    return (EXIT_SUCCESS);
}


