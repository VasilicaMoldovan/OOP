bits 32
global function 

segment data use32 class=data
    sum db 0

segment code use32 class=code
    function:
        pop ecx 
        pop esi 
        pop edi 
        repeta:
            push ecx 
            mov ecx, 4
            mov bl, 0
            greatestByte:
                lodsb 
                cmp al, bl 
                jb notMax 
                mov bl, al
                notMax:
                loop greatestByte
            mov eax, 0
            mov al, bl 
            stosb 
            add byte[sum], al 
            pop ecx 
            loop repeta
        mov al, byte[sum]
        cbw
        cwde
        push edi 