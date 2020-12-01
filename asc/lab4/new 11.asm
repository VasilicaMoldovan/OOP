bits 32 

global start        

extern exit, fopen, fclose, fwrite, fread, scanf, printf               
import exit msvcrt.dll  
import fopen msvcrt.dll 
import fclose msvcrt.dll 
import fwrite msvcrt.dll 
import fread msvcrt.dll 
import scanf msvcrt.dll 
import printf msvcrt.dll 

segment data use32 class=data
    fileName db 0
    c dd 0
    n dd 0
    character dd 0
    outputFile db 'output.txt', 0
    modwrite db 'w', 0
    format db "%c", 0
    formatNumber db "%d", 0
    formatRead db "%s", 0
    handle1 dd -1
    handle2 dd -1
    printFile db "file Name = ", 0
    printC db "c = ", 0
    printN db "n = ", 0
    a db 3
   
segment code use32 class=code
    start:
        mov ax, 60000
        mov bl, 2
        div bl 
        ;push dword printC
        ;call [printf]
        ;add esp, 4 * 1
       
        ;push dword c 
        ;push dword format 
        ;call [scanf]
        ;add esp, 4 * 2
        
        ;mov edx, dword[c] 
        
        ;push dword modRead
        ;push dword [fileName]
        ;call [fopen]
        ;add esp, 4 * 1
        
            
        push    dword 0      
        call    [exit]       
