bits 32

global start       
extern exit, scanf, fopen, fclose, fwrite             
import exit msvcrt.dll 
import scanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fwrite msvcrt.dll 
                        
segment data use32 class=data
    a dd -12
    readformat db "a=", 0
    outputfile db 'fisie.txt', 0
    modwrite db 'w', 0
    handle dd -1
    
    

;Se citeste de la tastatura un sir de numere in baza 10, cu semn. Sa se determine valoarea maxima din sir si sa se afiseze in fisierul max.txt (fisierul va fi creat) valoarea maxima, in baza 16.
segment code use32 class=code
    start:
        mov eax, dword[a]
        add eax, 3
        add eax, 15
        push    dword 0   
        call    [exit]  
