bits 32
global start

extern exit, fwrite, fopen, fclose, printf, scanf, fprintf
import fprintf msvcrt.dll 
import printf msvcrt.dll
import scanf msvcrt.dll  
import exit msvcrt.dll
import fwrite msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll 

segment data use32 class=data public
    outputfile db 'newfile.txt', 0
    message db 'word = ', 0
    modwrite db 'w', 0
    format db '%s', 0
    formatNumber db '%c', 0
    digits db '0123456789'
    len equ $-digits
    new_word dd 0
    handle db -1
    line db 10, 0
    

segment code use32 class=code public 
    start:
        push dword modwrite
        push dword outputfile
        call [fopen]
        add esp, 4*2
        
        mov [handle], eax 
        cmp eax, 0
        je theEnd
        
        repeta:
            push dword message
            call [printf]
            add esp, 4*1
            
            mov dword[new_word], 0
            
            push dword new_word
            push dword format
            call [scanf]
            add esp, 4*2
            
            mov edx, 0
            repeta1:
                mov ecx, len
                mov esi, digits
               repeta2:
                    lodsb 
                    cmp [new_word + edx], al
                    je isDigit
                    loop repeta2
                inc edx 
                cmp edx, 10
                jge isDigit
                jmp repeta1
                    
            isDigit:
            cmp ecx, 0
            je notDigit
            
            push dword[handle]
            push dword 1
            push dword 6
            push dword new_word
            call [fwrite]
            add esp, 4*4
            
            notDigit:
                  
            cmp dword[new_word], '$'
            je finish
            jmp repeta
        
        finish:
        
        push dword[handle]
        call [fclose]
        add esp, 4*1
        
        theEnd:
    
    push    dword 0
    call    [exit]