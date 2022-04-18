#include "Configuracion.h"
#include "UART.h"
#include <xc.h>

void UART_Init(uint32_t Baud_Rate){
    
    //Configurar los pines RX y TX
    TRISF |= (1 << 4);          //PIN RF4 -> U2RX
    TRISF &= ~(1 << 5);         //PIN RF5 -> U2TX
    //U2MODEbits.ALTIO = 0;       //USAR UxTX y UxRX
    
    // ----------------> CONFIGURAMOS TX <---------------- //
    //Bits de paridad y selección de datos
    U2MODEbits.PDSEL = 0b00;    //8 bits - No paridad
    
    //Bits de seleccion de parada
    U2MODEbits.STSEL = 0;       // 1 bits de STOP
    
    // ----------------> CONFIGURAMOS RX <---------------- //
    U2STAbits.URXISEL = 0b00;
        
    //Registros de interrupción
    IFS1bits.U2RXIF = 0;        //Borramos la bandera de interrupcion
    IEC1bits.U2RXIE = 1;        //Habilitamos la interrupción
    IPC6bits.U2RXIP = 5;        //Seleccionamos la prioridad
    
    // --------------------------------------------------- //
    
    //BRG = (FCY/(16*Baud_Rate))-1
    U2BRG = (uint16_t)((FCY/16/Baud_Rate)-1);

    U2MODEbits.UARTEN = 1;  //Habilitar el modulo UART
    U2STAbits.UTXEN = 1;    //Habilitar la transmision
}

void UART_TX_Char(char Caracter){
    
    //Mientras el Bufer esta lleno = 1, se mantiene en el bucle
    while(U2STAbits.UTXBF == 1);  //Sale del bucle cuando esta vacio

    U2TXREG = Caracter; //Se almacena el dato en el bufer
   
}

void UART_TX_String(char *str){
    char *ptr;
    ptr = str ;
    
    while(*ptr)
        UART_TX_Char(*ptr++);
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
              UART_TX_Char(*(char*)buffer++);
              
  }
  return(len);
}

