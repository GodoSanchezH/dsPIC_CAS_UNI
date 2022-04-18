/* 
 * File:   adc_dsPIC.h
 * Author: LENOVO
 *
 * Created on 27 de marzo de 2022, 10:37 AM
 */

#ifndef ADC_DSPIC_H
#define	ADC_DSPIC_H

#include "main.h"

typedef enum{
    AN0=0,
            AN1,
            AN2,
            AN3,
            AN4,
            AN5
}CanalesAnalog;


void ADC_Init(void);
uint16_t AnalogRead(CanalesAnalog Channel);




#endif	/* ADC_DSPIC_H */

