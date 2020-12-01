bits 32 global start        
global start 
extern exit, printf, scanf             
import exit msvcrt.dll    
import scanf msvcrt.dll
import printf msvcrt.dll 

segment data use32 class=data public 
    sir dd 1234A678h, 12345678h, 1AC3B47Dh, 0FEDC9876h
    len equ 4
    formatString db "%s", 0
    formatHexa db "%x", 0
    formatLength db "Length = ", 0
    a db 3
    b db 5
        
;Conversie din baza 10 in baza 16
    
segment code use32 class=code public 
    start:
        mov esi, sir 
        mov ecx, len 
        repeta:
            mov ebx, 0
            lodsb 
            cmp bl, al 
            jg skip
            mov bl, al
            skip:
                lodsb 
                cmp bl, al 
                jg skip2
                mov bl, al
                skip2:
                    lodsb 
                    cmp bl, al 
                    jg skip3
                    mov bl, al
                    skip3:
                        lodsb 
                        cmp bl, al 
                        jg skip4
                        mov bl, al
                        skip4:
            mov al, bl 
            cbw 
            cwde 
            push dword eax 
            push dword formatString
            call [printf]
            add esp, 4 * 2
                
            loop repeta 
            
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
