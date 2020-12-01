bits 32 

;Calculati (a * b + 2) / (a + 7 - c) + d + x
;Interpretare fara semn
global start        

extern exit              
import exit msvcrt.dll    
                        
segment data use32 class=data
    a db 3
    b dw 8
    c db 5
    d dd 15
    x dd 20
   
segment code use32 class=code
    start:
        mov AL, [a]     ; AL = a
        mov AH, 0       ; conversie fara semn de la AL la AX
        mul word[b]     ; DX:AX = a * b
        mov BL, 2       ; BL = 2
        mov BH, 0       ; conversie fara semn de la BL la BX
        mov CX, 0       ; conversie fara semn de la BX la CX:BX
        add AX, BX
        adc DX, CX      ; DX:AX = a * b + 2
        mov BL, [a]     ; BL = a
        add BL, 7       ; BL = a + 7
        sub BL, [c]     ; BL = a + 7 - c
        mov BH, 0       ; conversie fara semn de la BL la BX
        div BX          ; AX = (a * b + 2) / (a + 7 - c)
        mov DX, 0       ; conversie fara semn de la AX la DX:AX
        add AX, word[d]
        adc DX, word[d + 2] ; DX:AX = (a * b + 2) / (a + 7 - c) + d
        add AX, word[x]
        adc DX, word[x + 2] ; DX:AX = (a * b + 2) / (a + 7 - c) + d + x
        
   
        push    dword 0      
        call    [exit]       
