bits 32 global start        
global start 
extern exit, printf               
import exit msvcrt.dll    
import printf msvcrt.dll 
extern addition 

segment data use32 class=data public 
    a db 2
    b db 3
    x db 0
    format db "%d", 0
    
segment code use32 class=code
    start:
        mov bl, [a]
        mov bh, [b]
        call addition
        
        mov [x], al
        push dword[x]
        push format
        call [printf]
        add esp, 4*2
       
        push    dword 0      ; push the parameter for exit onto the stack
        call    [ex it]       ; call exit to terminate the program
