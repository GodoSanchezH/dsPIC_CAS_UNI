#include "ADC.h"
#include "Configuracion.h"
#include <libpic30.h>
#include <xc.h>


void adc_init(void){
    ADPCFG = 0x1FFE;//RB0 ANALOG
    ADCON2bits.VCFG = 0b000;// VSS VDD

    // ADCS = 2*(TAD/TCY) - 1 
    //      = 2*(334nS/(1/24MHZ)) - 1
    //      = 15.032
    ADCON3bits.ADCS = 15;
    ADCON3bits.ADRC = 0;
    ADCON3bits.SAMC = 14;
    ADCON1bits.SSRC = 0b000;//Manual
    ADCON1bits.FORM = 0b00;
    ADCON1bits.ADON = 1; //ACtiva el ADC
}
uint16_t analog_read(uint8_t channel){

       ADCON1bits.SAMP = 1;
        __delay_ms(100);
        ADCON1bits.SAMP = 0;
            ADCHSbits.CH0SA = 0;//Canal 0
        while(!ADCON1bits.DONE);
        return ADCBUF0;

}
