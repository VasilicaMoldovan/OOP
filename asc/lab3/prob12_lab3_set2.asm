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
    d dq 15
    y dd 0
;Calculati (a - b - c) + (d - b - c) - (a - d)
;a - byte, b - word, c - double word, d - qword - Interpretare cu semn
segment code use32 class=code
    start:
        mov AL, [a]     ; AL = a
        cbw            ; conversie cu semn de la AL la AX
        sub AX, word[b] ; AX = a - b
        cwde           ; conversie cu semn de la AX la EAX
        sub EAX, dword[c]   ; EAX = a - b - c
        mov [y], EAX        ; y = a - b - c 
        mov EBX, dword[d]
        mov ECX, dword[d + 4] ; ECX:EBX = d
        mov AX, [b]           ; AX = b 
        cwde                  ; convertim AX la EAX 
        cdq                   ; convertim EAX la EDX:EAX
        sub EBX, EAX     
        sbb ECX, EDX          ; ECX:EBX = d - b 
        mov EAX, dword[c]      ; EAX = c 
        cdq                    ; convertim EAX la EDX:EAX 
        sub EBX, EAX
        sbb ECX, EDX           ; ECX:EBX = d - b - c
        mov EAX, dword[y]       ; EAX = a - b - c
        cdq                     ; EDX:EAX = a - b - c 
        add EAX, EBX
        adc EDX, ECX          ; EDX:EAX = (a - b - c) + (d - b - c)
        mov EBX, EAX
        mov ECX, EDX          ; ECX:EBX = (a - b - c) + (d - b - c)
        mov AL, [a]         ; AL = a
        cbw                 ; conversie cu semn de la AL la AX
        cwde                 ; conversie cu semn de la AX la EAX
        cdq                  ; convertim EAX la EDX:EAX 
        sub EAX, dword[d]
        sbb EDX, dword[d + 2] ; EDX:EAX = a - d
        sub EBX, EAX
        sbb ECX, EDX          ; ECX:EBX = (a - b - c) + (d - b - c) - (a - d)
        mov EAX, EBX
        mov EDX, ECX          ; EDX:EAX = (a - b - c) + (d - b - c) - (a - d)
       
   
        push    dword 0      
        call    [exit]       
