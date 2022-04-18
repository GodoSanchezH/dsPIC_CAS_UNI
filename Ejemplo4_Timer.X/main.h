/* 
 * File:   main.h
 * Author: LENOVO
 *
 * Created on 19 de marzo de 2022, 12:49 PM
 */

#ifndef MAIN_H
#define	MAIN_H





//Librerias del Compilador
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

//Definiciones

#define __XTAL_FREQ 10000000UL
#define FCY __XTAL_FREQ/2

//Librerias del dsPIC
#include <xc.h>
#include <libpic30.h>//libreria para generar los delays

#endif	/* MAIN_H */

