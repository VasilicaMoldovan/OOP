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
        cwd           ; conversie cu semn de la AX la DX:AX
        sub AX, word[c]
        sbb DX, word[c + 2] ; DX:AX = a - b - c
        mov BX, word[d]
        mov CX, word[d + 2] ; CX:BX = d
        sub BX, word[b]
        sbb CX, word[b + 2] ; CX:BX = d - b
        sub BX, word[c]
        sbb CX, word[c + 2] ; CX:BX = d - b - c
        add AX, BX
        adc DX, CX          ; DX:AX = (a - b - c) + (d - b - c)
        mov BX, AX
        mov CX, DX          ; CX:BX = (a - b - c) + (d - b - c)
        mov AL, [a]         ; AL = a
        cbw                 ; conversie cu semn de la AL la AX
        cwd                 ; conversie cu semn de la AX la DX:AX
        sub AX, word[d]
        sbb DX, word[d + 2] ; DX:AX = a - d
        sub BX, AX
        sbb CX, DX          ; CX:BX = (a - b - c) + (d - b - c) - (a - d)
        mov AX, BX
        mov DX, CX          ; DX:AX = (a - b - c) + (d - b - c) - (a - d)
        
        
   
        push    dword 0      
        call    [exit]       
