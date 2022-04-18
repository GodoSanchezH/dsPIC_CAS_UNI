
    .include "p33fj32mc202.inc"  ;Incluimos libreria
    .global _main ;definimos el cuerpo de nuestro programa
  
    
    _main:

    ;Instrucciones de Movimiento
   ; mov	#343,W3
    ;mov W0,TRISB
    ;mov #111,W2
    ;mov W3
    ;*******SUMA************
    ;add W0,W3,W4
    ;add W0,#0XF,W4
    ;*******RESTA*******
;    SUB #200,W3
;    SUB W3,W0,W4;W3-W0
    ;*******MULTIPLICACION*******
;    MUL.UU W0,#10,W2
    ;*******DIVISION*******
;   DIV.U W3,W2
    ;*******AND*******
    ;AND W2,W3,W4
    ;*******OR*******
    ; IOR W2,W3,W4
    ;*******XOR*******
   ; XOR W2,W3,W4
   
   nop
   
   ;HOLA MUNDO EN ASSEMBLER
   
   ;Blink B0
   BSET AD1PCFGL,#2 ;RB0 COMO DIGITAL
   BCLR TRISB,#0 ;RB0 SALIDA
   
   ;entrada digital B15
  BSET TRISB,#15;RB15 COMO ENTRADA
   
    bucle:
    
;    BTG LATB,#0
;    call delay_50ms
    
    ;BOTON LED
    BTSC PORTB,#15
    GOTO APAGA_LED
    GOTO PRENDE_LED
    
    
    goto bucle
 
APAGA_LED:

 BCLR LATB,#0   
 GOTO bucle   
PRENDE_LED:   
  BSET LATB,#0     
 GOTO bucle   
 
delay_50ms:
    mov #50,W0
retardo:
    dec W0,W1
    MOV W1,W0
    BRA Z,retorna
    repeat,#5000
    nop 
retorna:    
    return
    
    
    
    .end ; pones fin al programa






