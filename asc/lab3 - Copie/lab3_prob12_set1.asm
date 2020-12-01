bits 32 

;Calculati (a+b+d)-(a-c+d)+(b-c)
;Interpretare fara semn
 
global start        
extern exit               
import exit msvcrt.dll    
                          

segment data use32 class=data
    a DB 3
    b DW 8
    c DD 9
    d DD 10

segment code use32 class=code
    start:
        mov AL, [a]     ; AL = a
        mov AH, 0       ; conversie fara semn de la AL la AX
        add AX, [b]     ; AX = a + b
        mov DX, 0       ; conversie fara semn de la AX la DX:AX
        push AX
        push DX
        pop EAX         ; conversie fara semn de la DX:AX la EAX
        add EAX, dword[d]   ; EAX = a + b + d
        mov BL, [a]     ; BL = a
        mov BH, 0       ; conversie fara semn de la BL la BX
        mov CX, 0       ; conversie fara semn de la BX la CX:BX
        push BX
        push CX
        pop EBX         ; conversie fara semn de la CX:BX la EBX
        sub EBX, dword[c]   ; EBX = a - c
        add EBX, dword[d]   ; EBX = a - c + d
        sub EAX, EBX        ; EAX = (a + b + d) - (a - c + d)
        mov BX, [b]             ; BX = b
        mov CX, 0               ; conversie de la BX la CX:BX
        push BX
        push CX
        pop EBX         ; conversie fara semn de la CX:BX la EBX
        sub EBX, dword[c]       ; EBX = b - c
        add EAX, EBX    ; EAX = (a + b + d) - (a - c + d) + (b - c)
        
        
        
        push    dword 0      
        call    [exit]       