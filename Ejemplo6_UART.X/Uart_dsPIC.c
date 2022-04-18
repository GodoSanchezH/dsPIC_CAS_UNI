
#include "Uart_dsPIC.h"
#include <stdio.h>
extern volatile char RX_CHAR;

void Uart_Init(uint32_t Baud){
/*Configuracion de Pines*/
    //TX -RB8
    TRISB &= ~(1<<8);
    RPOR4bits.RP8R = 0b00011;//TX -> RB8
    
    //RX -RB9
    TRISB |= (1<<9);
    RPINR18bits.U1RXR = 0x9;//RX-> RB9
    
    /*INICIAMOS APAGANDO LA UART*/
    U1MODEbits.UARTEN = 0;//Apagado
    
    /*Bit de STOP*/
    U1MODEbits.STSEL = 0;//1 bit de stop
    
    /*Bit de partidad y tamaño de dato*/
    U1MODEbits.PDSEL = 0b00;//8 bit sin paridad
    
    /*calcular los baudios*/
    //UXBRG= FCY/(16*B) -1
    U1BRG = (uint16_t) ((FCY/16/Baud)-1);
   
    
    /*Habilitar la TX*/
    U1STAbits.UTXEN = 1;//Habilito tx
    
    
    /*Habilitar RX*/
    U1STAbits.URXISEL = 0b00;//Seleccionamos Interrupcion por 1 caracter
    
    IEC0bits.U1RXIE = 1;//Habilito la interrupcion por RX
    IFS0bits.U1RXIF = 0;//Apago la bandera de rx
    IPC2bits.U1RXIP = 0b111;//maxima prioridad


    //Habilitamos el periferico
    U1MODEbits.UARTEN = 1;//ON 
}

void Uart_Tx_CHAR(char caracter){

    while (U1STAbits.UTXBF==1);
    U1TXREG = caracter;

    
}


void Uart_Tx_STRING(char *Str){
    char *ptr;
    ptr = Str;
    while(*ptr)
        Uart_Tx_CHAR(*ptr++);

}

int    write(int handle, void *buffer, unsigned int len)
{
  int i;
   switch (handle)
  {
      case 0:        // handle 0 corresponds to stdout
      case 1:        // handle 1 corresponds to stdin
      case 2:        // handle 2 corresponds to stderr
      default:
          for (i=0; i<len; i++)
              Uart_Tx_CHAR(*(char*)buffer++);
              
  }
  return(len);
}


void __attribute__ ((interrupt,no_auto_psv)) _U1RXInterrupt(void){
    
    if (U1STAbits.OERR == 1) {
        U1STAbits.OERR = 0;
    }
    else if ((U1STAbits.PERR==0) && (U1STAbits.FERR==0)) {
    RX_CHAR = (char)U1RXREG; 
    }
   
   //printf("\n\r El caracter Recibido es %c ",RX_CHAR);
    
    
  IFS0bits.U1RXIF = 0;//Apago la bandera de rx
}




