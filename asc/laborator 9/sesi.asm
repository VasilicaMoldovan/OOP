bits 32 
global start     

extern function    
extern exit, printf          
import exit msvcrt.dll
import printf msvcrt.dll   
 
segment data use32 class=data
    ; ...
    string dd 1234A678h, 12345678h, 1AC3B47Dh, 1CFE9876h 
    len equ ($-string) / 4 
    final_string times len dd 0
    format db "%x", 0
    format2 db "%d", 0
    ;sum db 0
    currentByte db 0 
    
segment code use32 class=code
    start:
             
        mov ecx, len 
        mov esi, string
        mov edi, final_string
        call function 
           
        push dword eax 
        push dword format2
        call [printf]
        add esp, 4 * 2
        
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
