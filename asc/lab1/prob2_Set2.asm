bits 32 ; assembling for the 32 bits architecture

; Calculati (b+b)+(c-a)+d
global start        

extern exit               
import exit msvcrt.dll    
                          


segment data use32 class=data
        a db 2
        b db 3
        c db 4
        d db 5

segment code use32 class=code
    start:
        mov AL, [b] ; AL = b
        add AL, [b] ; AL = b + b
        mov BL, [c] ; BL = c
        sub BL, [a] ; BL = c - a
        add AL, BL  ; AL = b + b + c - a
        add AL, [d] ; AL = b + b + c - a + d
        
    
        push    dword 0      
        call    [exit]       
