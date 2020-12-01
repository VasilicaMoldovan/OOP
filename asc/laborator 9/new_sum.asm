bits 32
global start

extern exit, printf, scanf 
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll 
extern sumToNumbers

segment data use32 class=data
    readformat db '%d', 0
    printformat db 'numar = ', 0
    a dd 0
    b dd 0
    suma dd 0
    

segment code use32 class=code
    start:
        push dword printformat
        call [printf]
        add esp, 4*1
        
        push dword a
        push dword readformat
        call [scanf]
        add esp, 4*2
        
        push dword b 
        push dword readformat
        call [scanf]
        add esp, 4*2
        
        mov eax, dword[a]
        mov ebx, dword[b]
        
        call sumToNumbers
        
        mov dword[suma], eax 
        
        push dword[suma]
        push dword readformat
        call [printf]
        add esp, 4*2
    
        push    dword 0
        call    [exit]