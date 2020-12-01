bits 32 
global start     

extern function    
extern exit, printf          
import exit msvcrt.dll
import printf msvcrt.dll   
 
;include function 
segment data use32 class=data
    ; ...
    string dd 1234A678h, 12345678h, 1AC3B47Dh, 1CFE9876h 
    len equ ($-string) / 4 
    final_string times len dd 0
    format db "%x", 0
    format2 db "%d", 0
    ;sum db 0
    var1 db "enter the function", 0
    var2 db "exit the function", 0
    
segment code use32 class=code
    start:
    
        push dword string
        pop eax 
        
        push dword eax 
        push dword format
        call [printf]
        add esp, 4 * 2 
             
        ;mov ecx, len 
        ;mov esi, string
        ;mov edi, final_string
        ;push dword ecx 
        ;push dword esi 
        ;push dword edi 
        
        ;push dword var1
        ;call [printf]
        ;add esp, 4
  
        ;call function 
        
        ;push dword var2
        ;call [printf]
        ;add esp, 4
           
        ;pop edi 
        ;push dword eax 
        ;push dword format2
        ;call [printf]
        ;add esp, 4 * 2
        
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
