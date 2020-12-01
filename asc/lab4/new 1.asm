bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, strstr, printf, scanf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll 
import printf msvcrt.dll
import scanf msvcrt.dll 
import strstr msvcrt.dll   ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

    a dd 0
    c dd 0
    x db 0
    y db 0
    printformat db "a=", 0
    format db "%d", 0
    

; our code starts here
segment code use32 class=code 
    start:
        mov ecx, 2
       repeta:
            push dword printformat
            call [printf]
            add esp, 4*1
            
            push dword a
            push dword format
            call [scanf]
            add esp, 4*2
            
            cmp dword[a], 0
            jbe final
            
            mov dword[c], ecx
            mov ecx, 0
            ;push dword a 
            mov eax, [a]
            jmp conversie
            
            mov [a], eax
            push dword[a]
            push dword printformat
            call [printf]
            add esp, 4*2
            
            mov ecx, dword[c]
            loop repeta 
            
        conversie:
        ;mov eax, [esp + 4]
        mov ebx, 0
        mov byte[x], al 
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
        ;mov eax, ebx
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
        ;ret
        
        final:
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
