bits 32 

global start        

extern exit, fopen, fclose, fwrite, fread, scanf, printf               
import exit msvcrt.dll  
import fopen msvcrt.dll 
import fclose msvcrt.dll 
import fwrite msvcrt.dll 
import fread msvcrt.dll 
import scanf msvcrt.dll 
import printf msvcrt.dll 

segment data use32 class=data
    fileName db 0
    c dd 0
    n dd 0
    character dd 0
    outputFile db 'output.txt', 0
    modwrite db 'w', 0
    format db "%c", 0
    formatNumber db "%d", 0
    formatRead db "%s", 0
    handle1 dd -1
    handle2 dd -1
    printFile db "file Name = ", 0
    printC db "c = ", 0
    printN db "n = ", 0
    modRead db 'r', 0
   
segment code use32 class=code
    start:
        ;citim caracterul c 
        push dword printC
        call [printf]
        add esp, 4 * 1 
       
        push dword c 
        push dword format 
        call [scanf]
        add esp, 4 * 2
        
        mov ebx, dword[c]
        
        ;citim numele fisierului
        push dword printFile
        call [printf]
        add esp, 4 * 1
        
        push dword fileName
        push dword formatRead
        call [scanf]
        add esp, 4 * 2
        
        ;deschidem fisierul input.txt 
        push dword modRead
        push dword fileName
        call [fopen]
        add esp, 4 * 1
        
        mov [handle1], eax 
        cmp eax, 0
        je final
        
        
        ;citim numarul de repetari n 
        push dword printN
        call [printf]
        add esp, 4 * 1
       
        push dword n
        push dword formatNumber
        call [scanf]
        add esp, 4 * 2
               
        push dword modwrite
        push dword outputFile
        call [fopen]
        add esp, 4 * 1
        
        
        mov [handle2], eax 
        cmp eax, 0
        je final 
        
        repeta: 
            push dword[handle1]
            push dword 1
            push dword 1
            push dword character 
            call [fread]
            add esp, 4 * 4 
            
            cmp eax, 0
            je final 
             
            cmp dword[character], ebx 
            jne skip
            mov ecx, [n]
            dec ecx 
            repeta1:
                push ecx 
                push dword[handle2]
                push dword 1
                push dword 1
                push dword character
                call [fwrite]
                add esp, 4 * 4
                pop ecx 
                loop repeta1
             
            skip:
                push dword[handle2]
                push dword 1
                push dword 1
                push dword character
                call [fwrite]
                add esp, 4 * 4
            jmp repeta
        
        final:
            push dword[handle1]
            call [fclose]
            add esp, 4 * 1
            
            push dword[handle2]
            call [fclose]
            add esp, 4 * 1
            
            push    dword 0      
            call    [exit]       
