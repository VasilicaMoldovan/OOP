bits 32
global start
extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    a dw 0
    b dw 0
    rezultat dd 0
    format1 db 'a=', 0
    format2 db 'b=', 0
    readformat db '%d', 0
    
;Sa se citeasca de la tastatura doua numere (in baza 10) si sa se calculeze produsul lor. Rezultatul inmultirii se va salva in memorie in variabila "rezultat" (definita in segmentul de date).
segment code use32 class=code
    start:
        push dword format1
        call [printf]
        add ESP, 4*1
        
        push dword a
        push dword readformat
        call [scanf]
        add ESP, 4*2
        
        push dword format2
        call [printf]
        add ESP, 4*1
        
        push dword b 
        push dword readformat
        call [scanf]
        add ESP, 4*2
        
        mov AX, [a]     ; AX = a
        mul word[b]     ; DX:AX = AX * b = a * b
        push DX
        push AX
        pop EAX         ; EAX = a * b
        mov [rezultat], EAX     ; rezultat = a * b 
     
    push    dword 0
    call    [exit]