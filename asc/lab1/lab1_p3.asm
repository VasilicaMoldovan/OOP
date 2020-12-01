bits 32
global start        

extern exit               
import exit msvcrt.dll    

segment data use32 class=data
    A db 10000111b
    B db 0
    C dd 0
    n db 0
;Se da octetul A. Sa se obtina numarul intreg n reprezentat de bitii 2-4 ai lui A. Sa se obtina apoi in B octetul ;rezultat prin rotirea spre dreapta a lui A cu n pozitii. Sa se obtina dublucuvantul C:
;bitii 8-15 ai lui C sunt 0
;bitii 16-23 ai lui C coincid cu bitii lui B
;bitii 24-31 ai lui C coincid cu bitii lui A
;bitii 0-7 ai lui C sunt 1
segment code use32 class=code
    start:
        ;Sa se obtina numarul intreg n reprezentat de bitii 2-4 ai lui A
        mov AL, [A]     ; AL = 10000111b
        and AL, 00011100b   ; izolam bitii 2-4
                            ; AL = 0000 0100b
        mov [n], AL  ; n = 0000 0100b = 4
        ;mov BL, [n]
        ;add BL, 4
        ;mov [n], BL
        
        ;Sa se obtina apoi in B octetul ;rezultat prin rotirea spre dreapta a lui A cu n pozitii
        mov AL, [A]     ; AL = 1000 0111b
        mov CL, [n]
        ror AL, CL     ; rotim spre dreapta AL cu n = 4 pozitii
                        ; AL = 0111 1000b
        mov [B], AL     ; B = 0111 1000b
        
        ;bitii 8-15 ai lui C sunt 0
        and dword[C], 00000000000000000000000000000000b    ; bitii 8-15 ai lui C sunt 0
        
        ;bitii 16-23 ai lui C coincid cu bitii lui B
        mov AL, [B]     ; AL = 0111 1000b
        mov AH, 0       ; conversie fara semn de la AL la AX
        mov DX , 0      ; conversie fara semn de la AX la DX:AX
        push AX
        push DX
        pop EAX         ; EAX = DX:AX
                        ; EAX = 0000 0000 0000 0000 0000 0000 0111 1000b
        shl EAX, 16     ; shfitam cu 16 pozitii spre stanga pentru ca bitii 0-7 din EAX(bitii octetului B) sa ajunga 
                        ; pe pozitiile 16-23
                        ; EAX = 0000 0000 0111 1000 0000 0000 0000 0000b
        ;and EAX, 00000000111111110000000000000000b  ;izolam bitii 16-23 
        or [C], EAX     ; bitii 16-23 ai lui C coincid cu bitii 16-23 ai lui EAX(cu bitii octetului B)
        
        ;bitii 24-31 ai lui C coincid cu bitii lui A
        mov AL, [A]     ; AL = 1000 0111b
        mov AH, 0       ; conversie fara semn de la AL la AX
        mov DX, 0       ; conversie fara semn de la AX la DX:AX
        push AX
        push DX
        pop EAX         ; EAX = DX:AX 
                        ; EAX = 0000 0000 0000 0000 0000 0000 1000 0111b
        shl EAX, 24     ; shiftam cu 24 de pozitii spre stanga pentru ca bitii 0-7 din EAX(bitii octetului A)
                        ; sa ajunga pe pozitiile 24-31
        ;and EAX, 11111111000000000000000000000000b   ; izolam bitii 24-31
        and EAX, 00000000111111110000000000000000b
        or [C], EAX     ; bitii 24-31 ai lui C coincid cu bitii 24-31 ai lui EAX(bitii octetului A)
        
        ;bitii 0-7 ai lui C sunt 1
        or dword[C], 00000000000000000000000011111111b    ; bitii 0-7 ai lui C devin 1
        
        
        push    dword 0      
        call    [exit]       