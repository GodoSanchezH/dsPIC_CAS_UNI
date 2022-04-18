/* 
 * File:   ADC.h
 * Author: cd_te
 *
 * Created on 16 de abril de 2022, 10:36 PM
 */

#ifndef ADC_H
#define	ADC_H
#include <stdint.h>
void adc_init(void);
uint16_t analog_read(uint8_t channel);

#endif	/* ADC_H */

