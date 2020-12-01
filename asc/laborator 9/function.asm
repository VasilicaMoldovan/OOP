bits 32
extern printf
import printf msvcrt.dll
segment data use32 class=data public 
    len1 dd 0
    len2 dd 0
    testing db "testing", 0

segment code use32 class=code public 
function:
    mov ebx, [esp+16]
    mov edx, [esp+12]
    mov cl, [ebx]
    mov al, [edx]
    push dword testing
    call [printf]
    add esp, 4
    repeta1:
          push dword testing 
          call [printf]
          add esp, 4
          
          cmp al, cl
          je fskip
          inc dword[len2]
          mov dword[len1], 0
          jmp fskip2
          fskip:
            inc dword[len1]
            inc dword[len2]
          fskip2:
          mov al, [edx+len1]
          mov cl, [ebx+len2]
          cmp al, 0
          je final 
          cmp cl, 0
          je final2
          jmp repeta1
          
    final:
        mov eax, 1
        ret
    final2:
        mov eax, 0
        ret
        
        
          
