bits 32
; Calculati e - a * a
global start        

extern exit               
import exit msvcrt.dll    

segment data use32 class=data
    a DB 3
    e DW 8

segment code use32 class=code
    start:
        MOV AL, [a]     ; AL = a
        MUL byte[a]     ; AX := AL * a = a * a
        MOV DX, [e]     ; DX = e
        SUB DX, AX      ; DX = e - a * a
       
        push    dword 0      
        call    [exit]       