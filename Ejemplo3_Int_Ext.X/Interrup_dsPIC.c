

#include "Interrup_dsPIC.h"

extern volatile uint8_t i;

void Interrupt_Config(Interrupciones INTX,Prioridad Priori,Flanco edge){

    switch(INTX){
        case INT0:
        TRISB |= (1<<7);//Definimos como entrada
        //IEC0 |= (1<<0);
        IEC0bits.INT0IE = 1;//Habilitado la Interrupcion
        IFS0bits.INT0IF = 0;//Limpiando el Flag
        IPC0bits.INT0IP = Priori;//Nive7
        INTCON2bits.INT0EP = edge;//flanco de bajada
        
            break;
        case INT1:
            IEC1bits.INT1IE = 1;//Habilitado la Interrupcion
            IFS1bits.INT1IF = 0;//Limpiando el Flag
            IPC5bits.INT1IP = Priori;//Nive7
            INTCON2bits.INT1EP = edge;//flanco de bajada    
            TRISB |= (1<<15);//Definimos como entrada
            RPINR0bits.INT1R = 0xF; //PIN15
            
            break;
            
        case INT2:
            IEC1bits.INT2IE = 1;//Habilitado la Interrupcion
            IFS1bits.INT2IF = 0;//Limpiando el Flag
            IPC7bits.INT2IP = Priori;//Nive7
            INTCON2bits.INT2EP = edge;//flanco de bajada
            TRISB |= (1<<14);//Definimos como entrada
            RPINR1bits.INT2R = 0xE;//PIN14
            
            break;
    
    }



}



void __attribute__ ((interrupt,no_auto_psv)) _INT0Interrupt(void){
    i++;
    LATC = i;

  IFS0bits.INT0IF = 0;//Limpiando el Flag
}

void __attribute__ ((interrupt,no_auto_psv)) _INT1Interrupt(void){
    i--;
    LATC = i;

  IFS1bits.INT1IF = 0;//Limpiando el Flag
}

void __attribute__ ((interrupt,no_auto_psv)) _INT2Interrupt(void){

    LATC = ~LATC;
  IFS1bits.INT2IF = 0;//Limpiando el Flag
}
