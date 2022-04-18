/* 
 * File:   main.c
 * Author: LENOVO
 *
 * Created on 27 de marzo de 2022, 10:36 AM
 */

#include "main.h"
#include "LCD_dsPIC.h"
#include "adc_dsPIC.h"
// DSPIC33FJ32MC202 Configuration Bit Settings

// 'C' source line config statements

// FBS
#pragma config BWRP = WRPROTECT_OFF     // Boot Segment Write Protect (Boot Segment may be written)
#pragma config BSS = NO_FLASH           // Boot Segment Program Flash Code Protection (No Boot program Flash segment)

// FGS
#pragma config GWRP = OFF               // General Code Segment Write Protect (User program memory is not write-protected)
#pragma config GSS = OFF                // General Segment Code Protection (User program memory is not code-protected)

// FOSCSEL
#pragma config FNOSC = PRI              // Oscillator Mode (Primary Oscillator (XT, HS, EC))
#pragma config IESO = ON                // Internal External Switch Over Mode (Start-up device with FRC, then automatically switch to user-selected oscillator source when ready)

// FOSC
#pragma config POSCMD = XT              // Primary Oscillator Source (XT Oscillator Mode)
#pragma config OSCIOFNC = OFF           // OSC2 Pin Function (OSC2 pin has clock out function)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow Only One Re-configuration)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor (Both Clock Switching and Fail-Safe Clock Monitor are disabled)

// FWDT
#pragma config WDTPOST = PS32768        // Watchdog Timer Postscaler (1:32,768)
#pragma config WDTPRE = PR128           // WDT Prescaler (1:128)
#pragma config WINDIS = OFF             // Watchdog Timer Window (Watchdog Timer in Non-Window mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (Watchdog timer enabled/disabled by user software)

// FPOR
#pragma config FPWRT = PWR128           // POR Timer Value (128ms)
#pragma config ALTI2C = OFF             // Alternate I2C  pins (I2C mapped to SDA1/SCL1 pins)
#pragma config LPOL = ON                // Motor Control PWM Low Side Polarity bit (PWM module low side output pins have active-high output polarity)
#pragma config HPOL = ON                // Motor Control PWM High Side Polarity bit (PWM module high side output pins have active-high output polarity)
#pragma config PWMPIN = ON              // Motor Control PWM Module Pin Mode bit (PWM module pins controlled by PORT register at device Reset)

// FICD
#pragma config ICS = PGD1               // Comm Channel Select (Communicate on PGC1/EMUC1 and PGD1/EMUD1)
#pragma config JTAGEN = OFF             // JTAG Port Enable (JTAG is Disabled)

// #pragma config statements should precede project file includes.
 //Use project enums instead of #define for ON and OFF.


float res0,res1,res2,res3,res4,res5;
uint8_t Str_res0[10],Str_res1[10],Str_res2[10],Str_res3[10],Str_res4[10],Str_res5[10];

int main(int argc, char** argv) {

    
    
    LCD_dsPIC_Init();
    ADC_Init();
    LCD_dsPIC_SetCursor(0,Fila1);
    LCD_dsPIC_Print_String("ADC0:");
    LCD_dsPIC_SetCursor(0,Fila2);
    LCD_dsPIC_Print_String("ADC1:");
    LCD_dsPIC_SetCursor(0,Fila3);
    LCD_dsPIC_Print_String("ADC2:");
    LCD_dsPIC_SetCursor(0,Fila4);
    LCD_dsPIC_Print_String("ADC3:");
    LCD_dsPIC_SetCursor(11,Fila1);
    LCD_dsPIC_Print_String("ADC4:");
    LCD_dsPIC_SetCursor(11,Fila2);
    LCD_dsPIC_Print_String("ADC5:");
    for(;;){
    
        res0 = AnalogRead(AN0)*3.3/4095.0;
        res1 = AnalogRead(AN1)*3.3/4095.0;
        res2 = AnalogRead(AN2)*3.3/4095.0;
        res3 = AnalogRead(AN3)*3.3/4095.0;
        res4 = AnalogRead(AN4)*3.3/4095.0;
        res5 = AnalogRead(AN5)*3.3/4095.0;
        
//        sprintf(Str_res0,"%04u",res0);
//        sprintf(Str_res1,"%04u",res1);
//        sprintf(Str_res2,"%04u",res2);
//        sprintf(Str_res3,"%04u",res3);
//        sprintf(Str_res4,"%04u",res4);
//        sprintf(Str_res5,"%04u",res5);

        sprintf(Str_res0,"%0.2f",res0);
        sprintf(Str_res1,"%0.2f",res1);
        sprintf(Str_res2,"%0.2f",res2);
        sprintf(Str_res3,"%0.2f",res3);
        sprintf(Str_res4,"%0.2f",res4);
        sprintf(Str_res5,"%0.2f",res5);
        
        LCD_dsPIC_SetCursor(6,Fila1);
        LCD_dsPIC_Print_String(Str_res0);
        LCD_dsPIC_SetCursor(6,Fila2);
        LCD_dsPIC_Print_String(Str_res1);
        LCD_dsPIC_SetCursor(6,Fila3);
        LCD_dsPIC_Print_String(Str_res2);
        LCD_dsPIC_SetCursor(6,Fila4);
        LCD_dsPIC_Print_String(Str_res3);
        LCD_dsPIC_SetCursor(16,Fila1);
        LCD_dsPIC_Print_String(Str_res4);
        LCD_dsPIC_SetCursor(16,Fila2);
        LCD_dsPIC_Print_String(Str_res5);
    
    }
    
    
    return (EXIT_SUCCESS);
}

