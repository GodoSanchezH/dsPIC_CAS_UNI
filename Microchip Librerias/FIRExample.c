/**********************************************************************
* © 2005 Microchip Technology Inc.
*
* FileName:        FIRExample.c
* Dependencies:    Header (.h) files if applicable, see below
* Processor:       dsPIC30Fxxxx
* Compiler:        MPLAB® C30 v3.00 or higher
* IDE:             MPLAB® IDE v7.52 or later
* Dev. Board Used: dsPICDEM 1.1 Development Board
* Hardware Dependencies: None
*
* SOFTWARE LICENSE AGREEMENT:
* Microchip Technology Incorporated ("Microchip") retains all ownership and 
* intellectual property rights in the code accompanying this message and in all 
* derivatives hereto.  You may use this code, and any derivatives created by 
* any person or entity by or on your behalf, exclusively with Microchip,s 
* proprietary products.  Your acceptance and/or use of this code constitutes 
* agreement to the terms and conditions of this notice.
*
* CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS".  NO 
* WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED 
* TO, IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A 
* PARTICULAR PURPOSE APPLY TO THIS CODE, ITS INTERACTION WITH MICROCHIP,S 
* PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
*
* YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE LIABLE, WHETHER 
* IN CONTRACT, WARRANTY, TORT (INCLUDING NEGLIGENCE OR BREACH OF STATUTORY DUTY), 
* STRICT LIABILITY, INDEMNITY, CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT, SPECIAL, 
* PUNITIVE, EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, FOR COST OR EXPENSE OF 
* ANY KIND WHATSOEVER RELATED TO THE CODE, HOWSOEVER CAUSED, EVEN IF MICROCHIP HAS BEEN 
* ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT 
* ALLOWABLE BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO 
* THIS CODE, SHALL NOT EXCEED THE PRICE YOU PAID DIRECTLY TO MICROCHIP SPECIFICALLY TO 
* HAVE THIS CODE DEVELOPED.
*
* You agree that you are solely responsible for testing the code and 
* determining its suitability.  Microchip has no obligation to modify, test, 
* certify, or support the code.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author            Date      Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* HV               09/30/05  First release of source file
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ADDITIONAL NOTES:
* This file demonstrates how one can filter a square wave to produce
* a sine wave signal. For the example, we have used an input square
* wave of 1 KHz frequency sampled at 20 KHz. This signal was generated
* by dsPICworks Data Analysis and Design Software.
*
* Four (4) filter examples are provided in this project/workspace:
* 1. Demonstrating how to use the DSP library and the dsPIC Filter
*    Design software to perform a Low Pass Filter when:
*    a. FIR Filter Coefficients are stored in Program Flash Memory
*    b. FIR Filter Coefficients are stored in RAM
* 2. Demonstrating how to use the DSP library and the dsPIC Filter
*    Design software to perform a Band Pass Filter when:
*    a. FIR Filter Coefficients are stored in Program Flash Memory
*    b. FIR Filter Coefficients are stored in RAM
* The workspace has been configured for example (1a) above.
* To reconfigure the project for Bandpass filter, that uses filter
* coefficients stored in RAM (example (2b) above), perform the following :
*    1. Remove the lowpassexample_psv.s file
*    2. Add the bandpassexample.s file into the project
*    3. Comment out the line of code that defines "LOWPASSFILTER" as
*       follows:
*           // #define LOWPASSFILTER
*    4. Comment out the line of code that defines the symbol
*       "FILTERCOEFFS_IN_PROGMEM" as follows:
*           // #define FILTERCOEFFS_IN_PROGMEM
*    5. Re-build the project
*
*  Use the stopwatch feature in MPLAB SIM to compare the execution
*  time of a filter that uses coefficients stored in program memory
*  versus that of a filter that uses coefficients stored in RAM.
*  You will note that the performace in both cases is comparable.
*
**********************************************************************/
#include <p30Fxxxx.h>
#include <dsp.h>

/* Device configuration register macros for building the hex file */
_FOSC(CSW_FSCM_OFF & XT_PLL8);          /* XT with 8xPLL oscillator, Failsafe clock off */
_FWDT(WDT_OFF);                         /* Watchdog timer disabled */
_FBORPOR(PBOR_OFF & MCLR_EN);           /* Brown-out reset disabled, MCLR reset enabled */
_FGS(CODE_PROT_OFF);                    /* Code protect disabled */

/* Constant Definitions */
#define BLOCK_LENGTH    256             /*We will filter a block of 256 samples in this example*/
#define LOWPASSFILTER           /*<---Comment out this line of the code if BPF is desired */
#define FILTERCOEFFS_IN_PROGMEM /*<---Comment out this line of the code if filter coefficients */
                                /*reside in data memory (RAM) as opposed to Program Memory */

/* Extern definitions for the imported *.s files from dsPICWorks */
extern fractional square1k[256];        /* Input Array containing Square wave signal */
                                        /* of frequency 1KHz sampled at 20 KHz*/

/* extern definitions for the imported *.s files from dsPIC Filter Design */
#ifdef LOWPASSFILTER
        #ifdef FILTERCOEFFS_IN_PROGMEM
                extern FIRStruct lowpassexample_psvFilter;  /*Contains filter structures for FIR-LPF*/
        #else
                extern FIRStruct lowpassexampleFilter;  /*Contains filter structures for FIR-LPF*/
        #endif
#else
        #ifdef FILTERCOEFFS_IN_PROGMEM
                extern FIRStruct bandpassexample_psvFilter; /*Contains filter structures for FIR-BPF*/
        #else
                extern FIRStruct bandpassexampleFilter; /*Contains filter structures for FIR-BPF*/
        #endif
#endif

/* Filter Operation Vectors */
fractional FilterOut[BLOCK_LENGTH] ;    /*Output array where filtered output will*/
                                        /*be stored */


int main(void) {

        /* FILTER OPERATIONS */
        #ifdef LOWPASSFILTER
                #ifdef FILTERCOEFFS_IN_PROGMEM
                /*Initialize the filter state variables (delay line) prior to calling */
                /*the FIR() routine the very first time */
                        FIRDelayInit(&lowpassexample_psvFilter);

                /* Perform FIR Low Pass filtering on a square wave of frequency 1kHz    */
                        FIR(BLOCK_LENGTH,&FilterOut[0],&square1k[0],&lowpassexample_psvFilter);

                #else
                /*Initialize the filter state variables (delay line) prior to calling */
                /*the FIR() routine the very first time */
                        FIRDelayInit(&lowpassexampleFilter);

                /* Perform FIR Low Pass filtering on a square wave of frequency 1kHz    */
                        FIR(BLOCK_LENGTH,&FilterOut[0],&square1k[0],&lowpassexampleFilter);
                #endif
        #else
                #ifdef FILTERCOEFFS_IN_PROGMEM
                /*Initialize the filter state variables (delay line) prior to calling */
                /*the FIR() routine the very first time */
                        FIRDelayInit(&bandpassexample_psvFilter);

                /* Perform FIR Band Pass filtering on a square wave of frequency 1kHz   */
                        FIR(BLOCK_LENGTH,&FilterOut[0],&square1k[0],&bandpassexample_psvFilter);
                #else
                /*Initialize the filter state variables (delay line) prior to calling */
                /*the FIR() routine the very first time */
                        FIRDelayInit(&bandpassexampleFilter);

                /* Perform FIR Band Pass filtering on a square wave of frequency 1kHz   */
                        FIR(BLOCK_LENGTH,&FilterOut[0],&square1k[0],&bandpassexampleFilter);
                #endif
        #endif
        while (1);
}
