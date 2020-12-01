bits 32 ; assembling for the 32 bits architecture

;Calculati d*(d+2*a)/(b*c)=
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions


segment data use32 class=data
        a db 2
        b db 3
        c db 4
        d dw 40

segment code use32 class=code
    start:
        mov AL, [b] ; AL = b 
        mul BYTE[c] ; AX = b * c 
        mov BX, AX  ; BX = b * c 
        mov AL, 2   ; AL = 2
        mul BYTE [a]    ; AX = AL * a = 2 * a 
        add AX, [d]     ; AX = d + 2 * a 
        mul WORD [d] ; DX:AX = d * (d + 2 * a)
        div BX       ; AX = d * (d + 2 * a) / (b * c)   
        
        
    
        push    dword 0      
        call    [exit]       
