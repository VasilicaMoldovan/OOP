bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf, scanf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll 
import scanf msvcrt.dll 
import printf msvcrt.dll   ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
%include "modul3.asm"
segment data use32 class=data public 
    a dd 0
    b dd 0
    format db "%d", 0
    ; ...

; our code starts here
segment code use32 class=code public 
    start:
        ; ...
        push dword a 
        push dword format
        call [scanf]
        add esp, 4 * 2
        
        push dword b 
        push dword format
        call [scanf]
        add esp, 4 * 2
        
        mov eax, [a]
        mov ebx, [b] 
        call function 
        
        mov [a], eax 
        push dword [a] 
        push dword format
        call [printf]
        add esp, 4*2
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
