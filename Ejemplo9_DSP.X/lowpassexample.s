;This file was generated by dsPIC Filter Design Software
; ..............................................................................
;    File   lowpassexample.s
; ..............................................................................

                .equ lowpassexampleNumTaps, 41

; ..............................................................................
; Allocate and initialize filter taps

;               .section .xdata                 ;<-Syntax supported in MPLAB C30
                                                ;v1.20 and before
                .section .xdata, data, xmemory  ;<-Syntax supported in MPLAB C30
                                                ;v1.30 and later
                .align 256

lowpassexampleTaps:
 .hword    0x0000,0x0004,0x0010,0x0029,0x0051,0x008b,0x00d8,0x0139,0x01ad
 .hword	   0x0232,0x02c5,0x0362,0x0406,0x04a9,0x0546,0x05d7,0x0657,0x06c1
 .hword	   0x0710,0x0740,0x0750,0x0740,0x0710,0x06c1,0x0657,0x05d7,0x0546,0x04a9
 .hword	   0x0406,0x0362,0x02c5,0x0232,0x01ad,0x0139,0x00d8,0x008b,0x0051,0x0029
 .hword	   0x0010,0x0004,0x0000
    
    
    
   
    
    

    
    
    
    
; ..............................................................................
; Allocate delay line in (uninitialized) Y data space

;               .section .ybss,  "b"            ;<-Syntax supported in MPLAB C30
                                                ;v1.20 and before
                .section .ydata, data, ymemory  ;<-Syntax supported in MPLAB C30
                                                ;v1.30 and later
                .align 256

lowpassexampleDelay:
                .space lowpassexampleNumTaps*2

; ..............................................................................
; Allocate and intialize filter structure

                .section .data
                .global _lowpassexampleFilter

_lowpassexampleFilter:
.hword lowpassexampleNumTaps
.hword lowpassexampleTaps
.hword lowpassexampleTaps+lowpassexampleNumTaps*2-1
.hword 0xff00
.hword lowpassexampleDelay
.hword lowpassexampleDelay+lowpassexampleNumTaps*2-1
.hword lowpassexampleDelay

; ..............................................................................
; ..............................................................................
; Sample assembly language calling program
;  The following declarations can be cut and pasted as needed into a program
;               .extern _FIRFilterInit
;               .extern _BlockFIRFilter
;               .extern _lowpassexampleFilter
;
;               .section        .bss
;
;        The input and output buffers can be made any desired size
;          the value 40 is just an example - however, one must ensure
;          that the output buffer is at least as long as the number of samples
;          to be filtered (parameter 4)
;input:         .space  40
;output:        .space  40
;               .text
;
;
;  This code can be copied and pasted as needed into a program
;
;
; Set up pointers to access input samples, filter taps, delay line and
; output samples.
;               mov     #_lowpassexampleFilter, W0      ; Initalize W0 to filter structure
;               call    _FIRFilterInit  ; call this function once
;
; The next 4 instructions are required prior to each subroutine call
; to _BlockFIRFilter
;               mov     #_lowpassexampleFilter, W0      ; Initalize W0 to filter structure
;               mov     #input, W1      ; Initalize W1 to input buffer
;               mov     #output, W2     ; Initalize W2 to output buffer
;               mov     #20, W3 ; Initialize W3 with number of required output samples
;               call    _BlockFIRFilter ; call as many times as needed
