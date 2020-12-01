bits 32
global start
extern exit, perror, fopen, fclose, fread, printf
import exit msvcrt.dll
import perror msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    inputfile db 'fisier.txt', 0
    modread db 'r', 0
    handle1 dd -1
    eroare db 'error:', 0
    c db 0
    vocale db 'aeiouAEIOU'
    len equ $-vocale + 1
    nr dd 0
    format db "%d", 0
    
;Se da un fisier text. Sa se citeasca continutul fisierului, sa se contorizeze numarul de vocale si sa se afiseze aceasta valoare. Numele fisierului text este definit in segmentul de date.
segment code use32 class=code
    start:
        push dword modread
        push dword inputfile
        call [fopen]
        add ESP, 4*2
        
        mov [handle1], EAX
        cmp EAX, 0
        je finish 
        
        mov EBX, 0
        repeat:
            push dword[handle1]
            push dword 1
            push dword 1
            push dword c
            call [fread]
            add ESP, 4*4
            
            cmp EAX, 0
            je error
            
            mov ECX, len
            mov ESI, vocale
            repeta1:
                lodsb 
                cmp [c], AL
                je Vocala
                loop repeta1
            
            Vocala:
            cmp ECX, 0
            je NuEVocala
            add EBX, 1
            NuEVocala:
            jmp repeat
            
          error:
            push dword [handle1]
            call [fclose]
            add ESP, 4*1
            
          mov dword[nr], EBX
          push dword[nr]
          push dword format
          call [printf]
          add ESP, 4*2
          
        finish:
        push    dword 0
        call    [exit]

