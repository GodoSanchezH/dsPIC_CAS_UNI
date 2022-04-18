#include <xc.h>
#include "Configuracion.h"
#include "I2C_dsPIC.h"

/* argumento es frecuencia : khz */
void I2C_Init(uint16_t F_scl)
{
    /*120 nseg*/
    float Delay=120*0.000000001; /*120 nanosegundos*/
  /*CONFIGURAR LA VELOCIDAD EN BAUDIOS*/  
    float registro=(((FCY/F_scl)/1000)-FCY*Delay) -2;
    /*CONVERTIR A ENTERO*/
    I2C1BRG=(uint8_t)registro;
    I2C1CONbits.IPMIEN=0;
    /*HABILITAR EL BUS I2C*/
    I2C1CONbits.I2CEN=1;
}
void I2C_Start(void)
{
    /*INCIIAR COMUNICACIÓN*/
    I2C1CONbits.SEN=1;
    while(I2C1CONbits.SEN==1);
    /*YA SE HA ENVIADO EL BIT DE INICIO*/
}
void I2C_Restart(void)
{
      /*RE-INCIIAR COMUNICACIÓN*/
    I2C1CONbits.RSEN=1;
    while(I2C1CONbits.RSEN==1);
    /*YA SE HA ENVIADO EL BIT DE REPETICIÓN-INICIO*/
}
void I2C_Write_Data_Slave(uint8_t data)
{
    I2C1TRN=data;
    while(I2C1STATbits.TRSTAT);
    //return I2C1STATbits.ACKSTAT;
}
void I2C_Write_Address_Slave(uint8_t address, uint8_t data_dir)
{
//Ejemplo:
    // 0100000 0 & 1111111 0  -> Enmascarar los 7 bits de Address
    // 0000000 0 & 0000000 1  -> Enmascarar al bit de RW

    /*ENVIAR DIRECCIÓN*/
    I2C1TRN=( (address & 0b11111110) | (data_dir & 0b00000001) );
    /*DETERMINAR SI SE ENVIO LOS 8 BITS Y SE HA RECIBIDO EL ACK*/
    while(I2C1STATbits.TRSTAT);
    /*SE HA RECIBIDO EL BIT ACK*/
    //return I2C1STATbits.ACKSTAT;
}
void I2C_Read_Data(uint8_t *Ptr_Data, uint8_t var_Ack_nAck)
{
     I2C1CONbits.ACKEN=0;
    /*Iniciar un proceso de recepción */
    I2C1CONbits.RCEN=1;
    
    if(var_Ack_nAck == I2C_ACK)
    {
       while(I2C1CONbits.RCEN==1); //Esperar mientras SSPBUF esta vacio 
        *Ptr_Data = I2C1RCV; //Leo el dato recibido
        I2C1CONbits.ACKDT=0; //Preparo el bit ACK
       I2C1CONbits.ACKEN = 1; //Procedemos a enviar el ACK
        while(I2C1CONbits.ACKEN==1);//Esperar hasta que el bit ACK sea enviado
    }
    else if(var_Ack_nAck == I2C_nACK)
    {
       while(I2C1CONbits.RCEN==1); //Esperar mientras SSPBUF esta vacio 
        *Ptr_Data = I2C1RCV; //Leo el dato recibido
        I2C1CONbits.ACKDT=1; //Preparo el bit nACK
        I2C1CONbits.ACKEN = 1; //Procedemos a enviar el nACK
        while(I2C1CONbits.ACKEN==1);//Esperar hasta que el bit nACK sea enviado
    }
    
    
}
void I2C_Stop(void)
{
    /*FINALIZAR COMUNICACIÓN*/
    I2C1CONbits.PEN=1;
    while(I2C1CONbits.PEN==1);
    /*YA SE HA FINALIZADO LA COMUNICACIÓN*/
}

