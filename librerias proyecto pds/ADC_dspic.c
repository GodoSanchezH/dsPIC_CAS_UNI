#include <xc.h>
#include "Configuracion.h"
#include <libpic30.h>

#include "ADC_dspic.h"

void Analog_Init(bool Modo){
    
   switch(Modo){ 
       
    case Modo_10bits:
    AD1CON1bits.ADON = 0;//apagamos el adc
    AD1CON1bits.AD12B = Modo_10bits;//establecemos a 10bits
    AD1CON1bits.FORM = 0b00;//entero sin signo
    AD1CON1bits.SSRC = 0b010;//sampleo de manera manual //timer3
    AD1CON1bits.SAMP = 0;//inicio automatico de la conversion
    AD1CON1bits.ASAM = 1;
    AD1CON2bits.VCFG = 0b000;//Seleccina Voltaje de referencia
    AD1CON2bits.CHPS = 0b00;//usaremos solo el canal CH0
    AD1CHS0bits.CH0NA = 0;//referencia megativa al -VRF
    AD1CON3bits.ADRC = 0;//RELOJ DEL SISTEMA
    AD1CON3bits.ADCS = 1;//TAD = 2*TCY = 0.4uS
    AD1CON1bits.ADON = 1;//Iniciamos el adc
    
    break;
    
       case Modo_12bits:
    AD1CON1bits.ADON = 0;//apagamos el adc
    AD1CON1bits.AD12B = Modo_12bits;//establecemos a 10bits
    AD1CON1bits.FORM = 0b00;//entero sin signo
    AD1CON1bits.SSRC = 0b010;//sampleo de manera manual
    AD1CON1bits.ASAM = 0;
    AD1CON1bits.SAMP = 0;//inicio automatico de la conversion
    AD1CON2bits.VCFG = 0b000;//Seleccina Voltaje de referencia
    AD1CON2bits.CHPS = 0b00;//usaremos solo el canal CH0
    AD1CHS0bits.CH0NA = 0;//referencia megativa al -VRF
    AD1CON3bits.ADRC = 0;//RELOJ DEL SISTEMA
    AD1CON3bits.ADCS = 2;//TAD = 2*TCY = 0.4uS
    AD1CON1bits.ADON = 1;//Iniciamos el adc
    break;
    
   }
    

}
uint16_t AnalogRead(uint8_t Canal){
AD1CHS0bits.CH0SA = Canal;
//AD1CON1bits.SAMP = 1;//Empieze la lectura
//__delay_ms(0.1);
//AD1CON1bits.SAMP = 0;
while(!AD1CON1bits.DONE);//esperar que complete la conversion

return ADC1BUF0;
}
