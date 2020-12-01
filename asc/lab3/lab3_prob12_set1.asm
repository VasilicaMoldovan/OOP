bits 32 

;Calculati (a+b+d)-(a-c+d)+(b-c)
;Interpretare fara semn
 
global start        
extern exit               
import exit msvcrt.dll    
                          
segment data use32 class=data
    a DB 9
    b DW 8
    c DD 3
    d DQ 10
;Calculati (a+b+d)-(a-c+d)+(b-c)
;a - byte, b - word, c - double word, d - qword - Interpretare fara semn
segment code use32 class=code
    start:
        mov AL, [a]     ; AL = a
        mov AH, 0       ; conversie fara semn de la AL la AX
        add AX, [b]     ; AX = a + b
        mov DX, 0       ; conversie fara semn de la AX la DX:AX
        push DX
        push AX
        pop EAX         ; EAX = a + b 
        mov EDX, 0
        add EAX, dword[d]
        adc EDX, dword[d + 4]     ; EDX:EAX = a + b + d
        mov BL, [a]     ; BL = a
        mov BH, 0       ; conversie fara semn de la BL la BX
        mov CX, 0       ; conversie fara semn de la BX la CX:BX
        sub BX, word[c]
        sbb CX, word[c + 2]     ; CX:BX = a - c
        push CX
        push BX
        pop EBX         ; EBX = a - c 
        mov ECX, 0
        add EBX, dword[d]
        adc ECX, dword[d + 4]     ; CX:BX = a - c + d
        sub EAX, EBX
        sbb EDX, ECX              ; EDX:EAX = (a + b + d) - (a - c + d)
        mov BX, [b]             ; BX = b
        mov CX, 0               ; conversie de la BX la CX:BX
        sub BX, word[c]
        sbb CX, word[c + 2]     ; CX:BX = b - c
        push BX
        push CX
        pop EBX                 ; EBX = b - c
        mov ECX, 0
        add EAX, EBX
        adc EDX, ECX              ; EAX = (a + b + d) - (a - c + d) + (b - c)
        
        
        
        push    dword 0      
        call    [exit]       