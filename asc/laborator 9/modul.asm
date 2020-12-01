bits 32

global conversion 
import x, y

segment code use32 class=data public 
    x db 0
    y db 0
    
segment code use32 class=code public 
    conversion:
        mov ebx, 0
        mov [x], al 
        mov cl, 1
        .repeta1:
            mov dl, 10
            mov al, byte[x]
            div dl
            mov byte[x], al
            mov al, ah
            mul cl
            cwd 
            add ebx, eax 
            add cl, cl 
            cmp byte[x], 0
            jg .repeta1
        mov cl, 1
        mov byte[x], bl
        mov ebx, 0
        repeta2:
            mov dl, 8
            mov al, byte[x]
            div dl
            mov byte[x], al
            mov al, ah
            mul cl
            cwd 
            add ebx, eax 
            cmp cl, 1
            jne skip
            mov byte[y], cl
            mov cl, 0
            times 10 add cl, byte[y]  
            cmp byte[x], 0
            jg repeta2
            skip:
                mov byte[y], cl
                times 10 add cl, byte[y]  
                cmp byte[x], 0
                jg repeta2
        mov eax, ebx
        ret 