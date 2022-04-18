/* 
 * File:   ADC_dspic.h
 * Author: HP
 *
 * Created on 10 de octubre de 2021, 04:34 PM
 */

#ifndef ADC_DSPIC_H
#define	ADC_DSPIC_H

    #include <stdint.h>
#include <stdbool.h>

#define Modo_10bits 0
#define Modo_12bits 1
#define Disparo_Timer3

#define AN0 0b0000
#define AN1 0b0001
#define AN2 0b0010
#define AN3 0b0011
#define AN4 0b0100
#define AN5 0b0101


void Analog_Init(bool Modo);
uint16_t AnalogRead(uint8_t Canal);

#endif	/* ADC_DSPIC_H */

