bits 32 

global start        

extern exit, strstr, printf, scanf               
import exit msvcrt.dll 
import printf msvcrt.dll
import scanf msvcrt.dll 
import strstr msvcrt.dll   
extern conversion 
                         
global x
global y

segment data use32 class=data
    a dd 0
    c dd 0
    x db 0
    y db 0
    b dd 0
    printformat db "a=", 0
    format db "%d", 0
    format2 db 10, 0
    
;Se citesc mai multe numere de la tastatura, in baza 2. Sa se afiseze aceste numere in baza 8.    
segment code use32 class=code 
    start:
        mov ecx, 2
       repeta:
            push dword printformat
            call [printf]
            add esp, 4*1
            
            push dword a
            push dword format
            call [scanf]
            add esp, 4*2
            
            cmp dword[a], 0
            jbe final
            
            mov dword[c], ecx
            mov ecx, 0
            ;push dword a
            mov dword[b], eax
            mov eax, [a]
            call conversion
            
            mov [a], eax
            mov eax, dword[b]
            
            push dword[a]
            push dword format
            ;push dword[b]
            call [printf]
            add esp, 4*2
            
            push dword format2
            call [printf]
            add esp, 4*1
            
            mov ecx, dword[c]
            loop repeta 
        
        
        final:
        
        push    dword 0      
        call    [exit]    
