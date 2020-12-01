bits 32 

;Calculati (a * b + 2) / (a + 7 - c) + d + x
;Interpretare cu semn
global start        

extern exit              
import exit msvcrt.dll    
                        
segment data use32 class=data
    a db 3
    b dw 8
    c db 5
    d dd 15
    x dq 20
    y dd 0
;(a*b+2)/(a+7-c)+d+x; a,c-byte; b-word; d-doubleword; x-qword
segment code use32 class=code
    start:
        mov AL, [a]     ; AL = a
        add AL, 7       ; AL = a + 7
        sub AL, [c]     ; AL = a + 7 - c
        cbw             ; conversie cu semn de la AL la AX
        mov BX, AX      ; BX = a + 7 - c
        mov AL, [a]     ; AL = a
        cbw             ; conversie cu semn de la AL la AX
        imul word[b]    ; DX:AX = a * b
        mov dword[y], 2 ; y = 2
        add AX, word[y]
        adc DX, word[y+2] ; DX:AX = a * b + 2
        idiv BX         ; AX = (a * b + 2) / (a + 7 - c)
        cwd             ; conversie cu semn de la AX la DX:AX
        add AX, word[d]
        adc DX, word[d + 2]    ; DX:AX = (a * b + 2) / (a + 7 - c) + d
        push AX
        push DX
        pop EAX                ; EAX = (a * b + 2) / (a + 7 - c) + d
        cdq                     ; convertim EAX la EDX:EAX
        add EAX, dword[x]
        adc EDX, dword[x + 2]    ; EDX:EAX = (a * b + 2) / (a + 7 - c) + d + x
        
        
        push    dword 0      
        call    [exit]       
