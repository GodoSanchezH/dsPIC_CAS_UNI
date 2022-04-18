/* 
 * File:   Timer_dsPIC.h
 * Author: lenovo
 *
 * Created on 4 de octubre de 2021, 19:31
 */

#ifndef TIMER_DSPIC_H
#define	TIMER_DSPIC_H

#include <stdint.h>
typedef enum{
    Timer1,
            Timer2,
            Timer3
}Timers;


typedef enum{
    T32_Temp,
            T32_Cont,
            T32_Gate
}Timer_32;

      //65,536?                                                  
void Timer_Temporizador(uint8_t Timer,uint16_t Timer_C ,float Periodo_TMX,uint8_t Preescaler);
void Timer_Contador(uint8_t Timer,uint16_t Timer_C ,uint16_t Periodo_TMX,uint8_t Preescaler);
void Timer_Gate(uint8_t Timer,uint16_t Timer_C ,float Periodo_TMX,uint8_t Preescaler);
void Timer_32bits(uint8_t Modo);


#endif	/* TIMER_DSPIC_H */

