bits 32 global start        
global start 
extern exit, printf, strstr               
import exit msvcrt.dll    
import printf msvcrt.dll 
import strstr msvcrt.dll
extern addition 

segment data use32 class=data public 
    a db "abcd"
    b db "abc"
    x dd 0
    format db "%d", 0
    
;Se citesc mai multe siruri de caractere. Sa se determine daca primul apare ca subsecventa in fiecare din celelalte si sa se dea un mesaj corespunzator.
    
segment code use32 class=code public 
    start:
        push dword a
        push dword b
        call strstr
        
        mov [x], eax
        push dword[x]
        push format
        call [printf]
        add esp, 4*2
       
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
