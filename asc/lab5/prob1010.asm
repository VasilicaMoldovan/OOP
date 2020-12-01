bits 32
global start 
extern exit
import exit msvcrt.dll

segment data use32 class=data
    s1 db '2','a','v','b','A','3'
    S2 db  '3','d','e','1'
    lens1 equ ($-s1)/2
    lens2 equ $-S2
    D times lens1+lens2 db 0

;Se dau doua siruri de caractere S1 si S2. Sa se construiasca sirul D prin concatenarea elementelor sirului S2 in ordine inversa cu elementele de pe pozitiile pare din sirul S1. 
segment code use32 class=code
    start:
        mov ESI, S2 + lens2 - 1 ; punem in ESI sirul S2
        mov EDI, D
        mov ECX, lens2
        repeat:
            std     ; DF = 1, parcurgem sirul S2 in ordine inversa
            lodsb   ; punem in AL byte-ul curent din S2
                    ; ESI := ESI - 1
            cld     ; DF = 0, parcurgem sirul D de la stanga la dreapta
            stosb   ; mutam din AL in EDI(sirul D)
                    ; EDI := EDI + 1
            loop repeat     ; ECX := ECX - 1
                            ; cmp ECX, 0
                            ; ja repeat(daca ECX > 0 repetam ciclul)
       
        ;mov ESI, s1 + 1
        ;mov ECX, lens1
        ;cld         ; DF = 0, parcurgem sirul s1 de la stanga la dreapta
        ;repeat1:
            ;lodsb
            ;inc ESI
            ;stosb
           ; mov AL, [ESI]
           ; mov [EDI], AL
            ;inc ESI
            ;inc ESI
           ; inc EDI
            ;dec ECX
            ;cmp ECX, 0
            ;ja repeat1
            ;loop repeat1
            
        push    dword 0
        call    [exit]