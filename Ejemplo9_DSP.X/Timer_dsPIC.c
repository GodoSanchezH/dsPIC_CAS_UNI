#include "Timer_dsPIC.h"
#include "Configuracion.h"
#include <xc.h>

void Timer_Temporizador(uint8_t Timer,uint16_t Timer_C ,float Periodo_TMX,uint8_t Preescaler){
    uint16_t i ,PRX ;
    
    if(Preescaler==256) i=3;
    if(Preescaler==64)  i=2;
    if(Preescaler==8)   i=1;
    if(Preescaler==1)   i=0;
    
    switch(Timer){
        
        /***************************/
        case Timer1:
            T1CONbits.TON = 0;//apagamos el timer    
            T1CONbits.TCS = 0;//Activo el modo Temporizadoor
            T1CONbits.TGATE = 0;// Desactivo el Gate
            /*
             * 50ms = 
             * PR1 = 5MHz * 50ms
             */
            T1CONbits.TCKPS = i;//preescaler 
            PRX = (uint16_t) ((FCY*Periodo_TMX)/Preescaler)-1;
            PR1 = PRX;//-> Valor para 50 ms a 5Mhz
            TMR1 = Timer_C;//INICIE SIN CARGA
            IEC0bits.T1IE = 1;//Habilitamos interrupcion por desbordamiento
            IFS0bits.T1IF = 0;//limpiamos flag
            IPC0bits.T1IP = 1;//Prioridad 1
            T1CONbits.TON = 1;//Enciende Timer

            break;      
        /*****************************/    
        case Timer2:
            T2CONbits.TON = 0;//apagamos el timer    
            T2CONbits.TCS = 0;//Activo el modo Temporizadoor
            T2CONbits.TGATE = 0;// Desactivo el Gate
            /*
             * 50ms = 
             * PR1 = 5MHz * 50ms
             */
            T2CONbits.TCKPS = i;//preescaler 
            PRX = (uint16_t) ((FCY*Periodo_TMX)/Preescaler)-1;
            PR2 = PRX;//-> Valor para 50 ms a 5Mhz
            TMR2 = Timer_C;//INICIE SIN CARGA
            IEC0bits.T2IE = 1;//Habilitamos interrupcion por desbordamiento
            IFS0bits.T2IF = 0;//limpiamos flag
            IPC1bits.T2IP = 2;//Prioridad 2
            T2CONbits.TON = 1;//Enciende Timer

            break;
       /*****************************/       
        case Timer3:
            T3CONbits.TON = 0;//apagamos el timer    
            T3CONbits.TCS = 0;//Activo el modo Temporizadoor
            T3CONbits.TGATE = 0;// Desactivo el Gate
            /*
             * 50ms = 
             * PR1 = 5MHz * 50ms
             */
            T3CONbits.TCKPS = i;//preescaler 
            PRX = (uint16_t) ((FCY*Periodo_TMX)/Preescaler)-1;
            PR3 = PRX;//-> Valor para 50 ms a 5Mhz
            TMR3 = Timer_C;//INICIE SIN CARGA
            IEC0bits.T3IE = 1;//Habilitamos interrupcion por desbordamiento
            IFS0bits.T3IF = 0;//limpiamos flag
            IPC2bits.T3IP = 3;//Prioridad 3
            T3CONbits.TON = 1;//Enciende Timer
            
            
            break;


}
            
 

}


void Timer_Contador(uint8_t Timer,uint16_t Timer_C ,uint16_t Periodo_TMX,uint8_t Preescaler){
    uint16_t i  ;
    
    if(Preescaler==256) i=3;
    if(Preescaler==64)  i=2;
    if(Preescaler==8)   i=1;
    if(Preescaler==1)   i=0;

    switch(Timer){
    
        case Timer2:
            T2CONbits.TON = 0;//apagamos el timer    
            T2CONbits.TCS = 1;//Activo Contador
            TRISB |= (1<<15);//ENTRADA AL PIN B15
            RPINR3bits.T2CKR = 0xF;//15 TCK2
            /*
             * 50ms = 
             * PR1 = 5MHz * 50ms
             */
            
            T2CONbits.TCKPS = i;//preescaler 
           
            PR2 = Periodo_TMX ;//-> Valor para 50 ms a 5Mhz
            TMR2 = Timer;//INICIE SIN CARGA
            IEC0bits.T2IE = 1;//Habilitamos interrupcion por desbordamiento
            IFS0bits.T2IF = 0;//limpiamos flag
            IPC1bits.T2IP = 2;//Prioridad 2
            T2CONbits.TON = 1;//Enciende Timer
            
            break;
         case Timer3:
            T3CONbits.TON = 0;//apagamos el timer    
            T3CONbits.TCS = 1;//Activo Contador
            TRISB |= (1<<14);//ENTRADA AL PIN B14
            RPINR3bits.T3CKR = 0xF;//15 TCK2
            /*
             * 50ms = 
             * PR1 = 5MHz * 50ms
             */
            
            T3CONbits.TCKPS = i;//preescaler 
           
            PR3 = Periodo_TMX ;//-> Valor para 50 ms a 5Mhz
            TMR3 = Timer;//INICIE SIN CARGA
            IEC0bits.T3IE = 1;//Habilitamos interrupcion por desbordamiento
            IFS0bits.T3IF = 0;//limpiamos flag
            IPC2bits.T3IP = 3;//Prioridad 2
            T3CONbits.TON = 1;//Enciende Timer
            
            break;           
            
            
    
    }


}



void Timer_Gate(uint8_t Timer,uint16_t Timer_C ,float Periodo_TMX,uint8_t Preescaler){

    uint16_t i ,PRX ;
    if(Preescaler==256) i=3;
    if(Preescaler==64)  i=2;
    if(Preescaler==8)   i=1;
    if(Preescaler==1)   i=0;
    
      switch(Timer){
       
          case Timer2:
            T2CONbits.TON = 0;//apagamos el timer    
            T2CONbits.TCS = 0;//Activo Contador
            T2CONbits.TGATE = 1;//gate
            TRISB |= (1<<15);//ENTRADA AL PIN B15
            RPINR3bits.T2CKR = 0xF;//15 TCK2
            /*
             * 50ms = 
             * PR1 = 5MHz * 50ms
             */
            
            T2CONbits.TCKPS = i;//preescaler 
            PRX = (uint16_t) ((FCY*Periodo_TMX)/Preescaler)-1;
            PR2 = PRX ;//-> Valor para 50 ms a 5Mhz
            TMR2 = Timer;//INICIE SIN CARGA
            IEC0bits.T2IE = 1;//Habilitamos interrupcion por desbordamiento
            IFS0bits.T2IF = 0;//limpiamos flag
            IPC1bits.T2IP = 2;//Prioridad 2
            T2CONbits.TON = 1;//Enciende Timer
            
            break;
         case Timer3:
            T3CONbits.TON = 0;//apagamos el timer    
            T3CONbits.TCS = 0;//Activo Temporizador
            T3CONbits.TGATE = 1;//gate
            TRISB |= (1<<14);//ENTRADA AL PIN B14
            RPINR3bits.T3CKR = 0xF;//15 TCK2
            /*
             * 50ms = 
             * PR1 = 5MHz * 50ms
             */
            
            T3CONbits.TCKPS = i;//preescaler 
            PRX = (uint16_t) ((FCY*Periodo_TMX)/Preescaler)-1;
            PR3 = PRX ;//-> Valor para 50 ms a 5Mhz
            TMR3 = Timer;//INICIE SIN CARGA
            IEC0bits.T3IE = 1;//Habilitamos interrupcion por desbordamiento
            IFS0bits.T3IF = 0;//limpiamos flag
            IPC2bits.T3IP = 3;//Prioridad 2
            T3CONbits.TON = 1;//Enciende Timer
            
            break;           
            

}

}


//numero de cuentas 4,294,967,295?
//
void Timer_32bits(uint8_t Modo){


switch(Modo){
    
    case T32_Temp:
        T2CONbits.TON = 0;//apagamos el timer 2
        T3CONbits.TON = 0;//apagamos el timerr 3
        T2CONbits.T32 = 1;//habilitado la configuracion del timer de 32 bits
        T2CONbits.TCS = 0;//reloj interno //temporizador
        T2CONbits.TGATE = 0;//desabilitmos el gate
        T2CONbits.TCKPS = 0b01;//el preescalador de 64 bits
        TMR2 = 0;
        TMR3 = 0;
        PR3 = 0X005F;
        PR2 = 0x5E10;//3905;        
        IEC0bits.T3IE = 1;//Habilitamos interrupcion por desbordamiento
        IFS0bits.T3IF = 0;//limpiamos flag
        IPC2bits.T3IP = 3;//Prioridad 2
        T2CONbits.TON = 1;//Enciende Timer32
        
        break;
    
    case T32_Cont:
        T2CONbits.TON = 0;//apagamos el timer 2
        T3CONbits.TON = 0;//apagamos el timerr 3
        T2CONbits.T32 = 1;//habilitado la configuracion del timer de 32 bits
        T2CONbits.TCS = 1;//reloj externp //contaodr
        T2CONbits.TCKPS = 0b00;//el preescalador de 64 bits
        TRISB |= (1<<15);//ENTRADA AL PIN B15
        RPINR3bits.T2CKR = 0xF;//15 TCK2
        TMR2 = 0;
        TMR3 = 0;
        PR3 = 0X0000;
        PR2 = 5;//3905;        
        IEC0bits.T3IE = 1;//Habilitamos interrupcion por desbordamiento
        IFS0bits.T3IF = 0;//limpiamos flag
        IPC2bits.T3IP = 3;//Prioridad 2
        T2CONbits.TON = 1;//Enciende Timer32
        
        break;
    case T32_Gate:
        T2CONbits.TON = 0;//apagamos el timer 2
        T3CONbits.TON = 0;//apagamos el timerr 3
        T2CONbits.T32 = 1;//habilitado la configuracion del timer de 32 bits
        T2CONbits.TCS = 0;//reloj interno //temporizador
        T2CONbits.TGATE = 1;//desabilitmos el gate
        T2CONbits.TCKPS = 0b10;//el preescalador de 64 bits
        TRISB |= (1<<15);//ENTRADA AL PIN B15
        RPINR3bits.T2CKR = 0xF;//15 TCK2
        TMR2 = 0;
        TMR3 = 0;
        PR3 = 0X0000;
        PR2 = 3905;        
        IEC0bits.T3IE = 1;//Habilitamos interrupcion por desbordamiento
        IFS0bits.T3IF = 0;//limpiamos flag
        IPC2bits.T3IP = 3;//Prioridad 2
        T2CONbits.TON = 1;//Enciende Timer32
        
        break;
    
    
}
}