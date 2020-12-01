bits 32 global start        
global start 
extern exit, printf, scanf               
import exit msvcrt.dll    
import printf msvcrt.dll 
import scanf msvcrt.dll 

%include "function.asm"
segment data use32 class=data public 
    string1 times 100 db 0
    string2 times 100 db 0
    format db "%s", 0
    is db "Da", 0
    no db "NU", 0
    n dd 0
    formatNumber db "%d", 0
    
;Se citeste de la tastatura un sir de numere in baza 10, cu semn. Sa se determine valoarea maxima din sir si sa se afiseze in fisierul max.txt (fisierul va fi creat) valoarea maxima, in baza 16.
segment code use32 class=code
    start:
        push dword n
        push dword formatNumber
        call [scanf]
        add esp, 4*2
        
        push dword string1
        push dword format
        call [scanf]
        add esp, 4*2
        
        mov ecx, [n]
        dec ecx 
        push ecx
        push dword formatNumber
        call [printf]
        add esp, 8
        repeta:
            push ecx 
            push dword string2
            push dword format
            call [scanf]
            add esp, 4*2
            
            push dword string1
            push dword string2
            call function
            add esp, 4*2
            
            cmp eax, 0
            je skip
            push dword is 
            call [printf]
            add esp, 4*1
            jmp skip2
            skip:
                push dword no
                call [printf]
                add esp, 4*1
            skip2:
                pop ecx 
            loop repeta
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
