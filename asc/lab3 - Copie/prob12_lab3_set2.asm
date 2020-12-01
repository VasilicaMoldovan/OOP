bits 32 

;Calculati (a - b - c) + (d - b - c) - (a - d)
;Interpretare cu semn
global start        

extern exit              
import exit msvcrt.dll    
                        
segment data use32 class=data
    a db 3
    b dw 8
    c dd 10
    d dd 15
   
segment code use32 class=code
    start:
        mov AL, [a]     ; AL = a
        cbw            ; conversie cu semn de la AL la AX
        sub AX, word[b] ; AX = a - b
        cwde           ; conversie cu semn de la AX la EAX
        sub EAX, dword[c]   ; EAX = a - b - c 
        mov EBX, dword[d]   ; EBX = d 
        mov EDX, EAX        ; EDX = a - b - c 
        mov AX, word[b]     ; AX = b 
        cwde                ; conversie cu semn de la AX la EAX
        sub EBX, EAX        ; EBX = d - b 
        sub EBX, dword[c]   ; EBX = d - b - c 
        add EDX, EBX        ; EDX = (a - b - c) + (d - b - c)
        mov AL, [a]         ; AL = a
        cbw                 ; conversie cu semn de la AL la AX
        cwde                ; conversie cu semn de la AX la EAX
        sub EAX, dword[d]   ; EAX = a - d 
        sub EDX, EAX        ; EDX = (a - b - c) + (d - b - c) - (a - d)
        mov EAX, EDX        ; EDX = (a - b - c) + (d - b - c) - (a - d)
        
        
   
        push    dword 0      
        call    [exit]       
