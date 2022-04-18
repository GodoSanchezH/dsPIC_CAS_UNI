#include "Uart_dspic.h"
#include "Configuracion.h"
#include <xc.h>


void UART_dsPIC_Init(uint32_t Baudios,bool Stop_bit,uint8_t Data_P ,uint8_t IPC_RX){
//DEFINIMOS NUESTRO PIN TX
    TRISB &= ~(1<<6);
    RPOR3bits.RP6R = 0b11;//tx = rb6
 //DEFINIMOS NUESTRO PIN RX
    TRISB |= (1<<7);
    RPINR18bits.U1RXR = 0x7;//rx=rb7
    
    U1MODEbits.UARTEN = 0;//iniciamos con la uart apagada
    U1MODEbits.STSEL = Stop_bit;//definimos el bit de stop
    U1MODEbits.PDSEL = Data_P;//definimos los datos y la paridad
    //= FCY/(16/BAUDIOS) -1;
    U1BRG = (uint16_t ) ((FCY/16/Baudios)-1);//Definimos Baudios
    
    U1STAbits.UTXEN = 1 ;//HABILITAMOS TX
    
    //habilitamos la recepcion
    U1STAbits.URXISEL = 0b00;//habiltamos la interrupcion por recepcion
    //IF , EC , IPC
    IFS0bits.U1RXIF = 0;//limpiamos el flag
    IEC0bits.U1RXIE = 1;//habilito su interrupciomn
    IPC2bits.U1RXIP = IPC_RX;//asignacion de prioridad
    
   U1MODEbits.UARTEN = 1;//iniciamos la uart
}
void UART_Tx_Char(char Caracter){

    while(U1STAbits.UTXBF == 1);
    U1TXREG = Caracter;

}
void UART_Tx_String(char *str){
    char *ptr;
    ptr = str ;
    
    while(*ptr)
        UART_Tx_Char(*ptr++);
}

void gets_USART(char *buffer, uint16_t len){
//	char data;
//	int32_t timeOut = 12000000;
//
//	for(uint8_t i=0; i<len; i++){
//		while( (UCSR0A & (1<<RXC0)) == 0){
//			timeOut--;
//			if(timeOut == 0){
//				return;
//			}
//		}
//		data = getc_USART();
//
//		*buffer = data;
//		buffer++;
//	}
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
              UART_Tx_Char(*(char*)buffer++);
              
  }
  return(len);
}
