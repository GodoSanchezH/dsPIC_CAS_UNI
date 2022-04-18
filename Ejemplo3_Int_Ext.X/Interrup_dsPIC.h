/* 
 * File:   Interrup_dsPIC.h
 * Author: LENOVO
 *
 * Created on 26 de marzo de 2022, 11:05 AM
 */

#ifndef INTERRUP_DSPIC_H
#define	INTERRUP_DSPIC_H

#include "main.h"

typedef enum{
    INT0=0,
            INT1,
            INT2
}Interrupciones;

typedef enum{
    F_subida=0,
            F_bajada     
}Flanco;

typedef enum{
    SinPrio=0,
            PRIORI1,
            PRIORI2,
            PRIORI3,
            PRIORI4,
            PRIORI5,
            PRIORI6,
            MaxPriority
}Prioridad;

void Interrupt_Config(Interrupciones INTX,Prioridad Priori,Flanco edge);

#endif	/* INTERRUP_DSPIC_H */

