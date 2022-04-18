/* 
 * File:   main.c
 * Author: LENOVO
 *
 * Created on 20 de marzo de 2022, 11:24 AM
 */

#include "main.h"
#include "LCD_dsPIC.h"
/*
 * 
 */

    uint8_t i;
    char  str_i[5];
int main(int argc, char** argv) {

    LCD_dsPIC_Init();
    LCD_dsPIC_New_Char(1,0x0A,0x1F,0x1F,0x1F,0x0E,0x04,0x00,0x00);
    LCD_dsPIC_New_Char(2,0x0E,0x1F,0x1E,0x1C,0x1C,0x1F,0x0E,0x00);
    LCD_dsPIC_New_Char(3,0x04,0x0E,0x0E,0x0E,0x0E,0x1F,0x00,0x00);
//    LCD_dsPIC_Print_Char('C');
//    LCD_dsPIC_Print_Char('A');
//    LCD_dsPIC_Print_Char('S') ; 
//    LCD_dsPIC_SetCursor(12,Fila3); 
//    LCD_dsPIC_Print_Char('U');
//    LCD_dsPIC_Print_Char('N');
//    LCD_dsPIC_Print_Char('I');  
    
    LCD_dsPIC_SetCursor(0,Fila1);
    LCD_dsPIC_Print_String("Bienvenidos al");
    LCD_dsPIC_SetCursor(0,Fila2);
    LCD_dsPIC_Print_String("Curso de dsPIC");
    LCD_dsPIC_Write_New_Char(1);
    LCD_dsPIC_SetCursor(0,Fila3);
    LCD_dsPIC_Print_String("Organizado por");
    LCD_dsPIC_Write_New_Char(2);
    LCD_dsPIC_SetCursor(0,Fila4);
    LCD_dsPIC_Print_String("CAS UNI");
    LCD_dsPIC_Write_New_Char(3);
    for(;;){
        
    
        for (i = 0; i <=256; i++) {
            
            sprintf(str_i,"%03u",i);
            LCD_dsPIC_SetCursor(12,Fila4);
            LCD_dsPIC_Print_String(str_i);
            __delay_ms(500);
        }

        
        
    }
    
    return (EXIT_SUCCESS);
}

