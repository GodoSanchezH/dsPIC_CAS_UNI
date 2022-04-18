/* 
 * File:   main.c
 * Author: Godo Sanchez
 *
 * Created on 19 de marzo de 2022, 12:49 PM
 */

#include <p33FJ32MC202.h>
#include "main.h"

//void Gpio_Init()

int main(int argc, char** argv) {

    //DEFINICION DE PINES
 
    //definimos pines como digitales
   /* AD1PCFGLbits.PCFG2 = 1;// como digital
    AD1PCFGLbits.PCFG3 = 1;// como digital
    AD1PCFGLbits.PCFG4 = 1;// como digital
    AD1PCFGLbits.PCFG5 = 1;// como digital*/
    
    /*00000001
     * (<<3) -> 001000
     */
    
    AD1PCFGL |= (1<<2) | (1<<3) | (1<<4) | (1<<5);  //Pined como Digitales
            
    /***Por estructuras
     *  0 -> salida
     *  1 -> entrda
     * */
   /* TRISBbits.TRISB0= 0;
    TRISBbits.TRISB1= 0;
    TRISBbits.TRISB2= 0;
    TRISBbits.TRISB3= 0;*/
    
    //0000 0000 0000 1110 &
    //1111111111111111110
    
    //Definicion de Salidas digitales
    TRISB &= ~(1<<0) & ~(1<<1) & ~(1<<2) & ~(1<<3); // Pines B0 ,B1 ,B2 ,B3  como salidas
    //Definicion de las entradas digitales
    //B1 -> B7
    //B2 -> B15
    //B3 -> B14
    TRISB |= (1<<4) | (1<<15) | (1<<14); //definimos nuestras entrdas digitales
   //activamos la resitencia pull up
    CNPU1 |= (1<<1); //CN1
    
    for(;;){
    
        /*LATBbits.LATB0 = 1;
        LATBbits.LATB1 = 0;
        LATBbits.LATB2 = 1;
        LATBbits.LATB3 = 0;
        __delay_ms(100);
        LATBbits.LATB0 = 0;
        LATBbits.LATB1 = 1;
        LATBbits.LATB2 = 0;
        LATBbits.LATB3 = 1;
        __delay_ms(100);*/
        
       // LATB ^= (1<<0) | (1<<1) | (1<<2) | (1<<3);
       // __delay_ms(200);
      //  LATB &= ~(1<<0) & ~(1<<1) & ~(1<<2) & ~(1<<3); 
        //__delay_ms(200);
        
//        if (!(PORTB & (1<<7))) {
//            
//            LATB |= (1<<0);
//        }
//        if (!(PORTB & (1<<15))) {
//            LATB |= (1<<1);
//        }
//         if (!(PORTB & (1<<14))) {
//            LATB |= (1<<2);
//            
//        }
//        else {
//        LATB &= ~(1<<0) & ~(1<<1)& ~(1<<2);
//        
//        }

        if (!(PORTB & (1<<4))) {
        LATB |= (1<<0);
        }else{
         LATB &= ~(1<<0);
        }
        
    
    }
   
    return (EXIT_SUCCESS);
}

