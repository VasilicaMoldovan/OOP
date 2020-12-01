bits 32 
global start        
extern exit, printf          
import exit msvcrt.dll
import printf msvcrt.dll   
 
segment data use32 class=data
    ; ...
    string dd 1234A678h, 12345678h, 1AC3B47Dh, 1CFE9876h 
    len equ $-string
    final_string times len dd 0
    format db "%d", 0
    
segment code use32 class=code
    start:
        push dword[len]
        push dword format
        call [printf]
        add esp, 4 * 2
        
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
