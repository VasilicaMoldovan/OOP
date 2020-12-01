bits 32 ; assembling for the 32 bits architecture

global addition 
segment code use32 class=code public 

addition:
    mov eax, ebx
    add eax, ecx
    ret 