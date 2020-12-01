bits 32 global start        
global start 
extern exit, printf, scanf             
import exit msvcrt.dll    
import scanf msvcrt.dll
import printf msvcrt.dll 

segment data use32 class=data public 
    number dw 123
    format db "%h", 0
    readformat db "number = ", 0
    format1 db "%d", 0
        
;Conversie din baza 10 in baza 16
    
segment code use32 class=code public 
    start:
        
        ;mov edi, 0
        ;mov esi, number
        ;cmp word[number], 0
        ;jle skip
        ;repeta:
         ;   mov bl, 16
          ;  mov ax, word[number]
           ; idiv bl
            ;mov byte[number], al 
            ;cmp ah, 0
        ;    jl skip2 
         ;   cmp ah, 9
          ;  jg skip2
           ; add ah, '0'
            ;mov al, ah
        ;    stosb
         ;   cmp word[number], 0
          ;  jg repeta
           ; skip2:
            ;    sub ah, 10
             ;   add ah, 'A'
              ;  mov al, ah 
               ; stosb 
                ;cmp word[number], 0
                ;jg repeta
        ;skip:
        
        push dword readformat
        call [printf]
        add esp, 4
        
        push dword number
        push dword format1
        call [scanf]
        add esp, 4 * 2
        
        push dword[number]
        push dword format1
        call [printf]
        add esp, 4 * 2
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
