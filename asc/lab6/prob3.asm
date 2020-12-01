bits 32
global start 
extern exit
import exit msvcrt.dll

segment data use32 class=data
    sir1 dd 0702090Ah, 0B0C0304h, 05060108h
    len1 equ $-sir1
    sir2 times 2 * len1 db 0
    var dd 23

;Se da un sir de 3 dublucuvinte, fiecare dublucuvant continand 2 valori pe cuvant (despachetate, deci fiecare cifra hexa e precedata de un 0). Sa se creeze un sir de octeti care sa contina acele valori (impachetate deci pe un singur octet), ordonate crescator in memorie, acestea fiind considerate numere cu semn. 
segment code use32 class=code
    start:
        mov ESI, sir1
        mov EDI, sir2
        mov ECX, len1
        cld 
        repeta:
            lodsd   ; in EAX punem dword-ul curent din sir1
                    ; EAX = 0702 090Ah
                    ; in AX avem word-ul low, AX := 090Ah
                    ; ESI = ESI + 1
            mov EBX, EAX    ; EBX = EAX = 0702 090Ah
            shr EAX, 16      ; EAX = 0000 0702h, AX = 0702h, AL = 02h, AH = 07h
            ror EAX, 4      ; EAX = 2000 0070h ,AX = 0070h
            mov EDX, EAX    ; var = 2000 0070h
            shr EAX, 28      ; EAX = 0000 0002h
            add EDX, EAX    ; var = 2000 0072h
            mov EAX, EDX    ; EAX = 2000 0072h
            stosb   ; in EDI punem byte-ul 72h
                    ; EDI = EDI + 1
            shl EBX, 16      ; EBX = 090A 0000h
            ror EBX, 20      ; EBX = A000 0090h
            mov EDX, EBX    ; var = A000 0090h
            shr EBX, 28      ; EBX = 0000 000Ah
            add EDX, EBX    ; var = 0000 009Ah
            mov EAX, EDX
            stosb   ; in EDI punem byte-ul 9Ah
                    ; EDI = EDI + 1
            loop repeta
            
        push    dword 0
        call    [exit]