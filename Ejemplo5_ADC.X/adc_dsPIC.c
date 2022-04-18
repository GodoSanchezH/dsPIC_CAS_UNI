


#include "adc_dsPIC.h"


void ADC_Init(void){
    /*Definir pines analogicos*/
    TRISA |= (1<<0) | (1<<1);// Entras a0 ,a1
    TRISB |= (1<<0) | (1<<1) | (1<<2) | (1<<3);
    AD1PCFGL &= ~(1<<0) & ~(1<<1)  & ~(1<<2) & ~(1<<3) & ~(1<<4) & ~(1<<5) ;  

    
    /*Apagamos el ADC*/
    AD1CON1bits.ADON = 0;//Inicia apagado
    
    /*Modo de Operacion*/
    AD1CON1bits.AD12B =1;//Modo 10 bits
    
    /*Formato*/
    AD1CON1bits.FORM = 0b00;//Unsigned Integer 
    
    /*Trigger*/
    AD1CON1bits.SSRC = 0b000;//Trigger por Software
    
    /*Configuracion de Inicio*/
    AD1CON1bits.ASAM = 0;
    AD1CON1bits.SAMP = 0;
    
    /*Seleccionamos el voltage de referencia*/
    AD1CON2bits.VCFG = 0b000;//AVDD AVSS
    
    /*Seleccion del canal*/
    AD1CON2bits.CHPS = 0b00;//CH0
    
    /*Indicar pin de -Vref*/
    AD1CHS0bits.CH0NA = 0;// -Vref
    
    /*Seleccion del Clock*/
    AD1CON3bits.ADRC = 0;// FCY
    AD1CON3bits.ADCS = 19;//20*TCY = 4uS
    
    //GO ADC
    AD1CON1bits.ADON = 1;
    

}

uint16_t AnalogRead(CanalesAnalog Channel){
    
    AD1CHS0bits. CH0SA = Channel;
    AD1CON1bits.SAMP = 1;
    __delay_ms(1);
    AD1CON1bits.SAMP = 0;
    while (!AD1CON1bits.DONE); //esperamos q termine la conversion

    return ADC1BUF0;
}




