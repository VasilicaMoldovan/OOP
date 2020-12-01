bits 32
global start        
extern exit              
import exit msvcrt.dll  

segment data use32 class=data
    S db 'a', 'b', 'A', 'D', 'e', 'c'
    lenS equ $-S 
    D times lenS db 0
   
;Se da un sir de caractere S. Sa se construiasca sirul D care sa contina toate literele mici din sirul S. 
segment code use32 class=code
    start:
        mov ESI, S  ;punem in ESI primul byte din sirul S
        mov EDI, D  ;punem in EDI primul byte din sirul D
        mov ECX, lenS   ; punem in ECX lungimea lenS pentru a realiza bucla loop de ECX ori
        
        repeat:
            mov AL, [ESI]   ; mutam in AL byte-ul din ESI
            inc ESI         ; crestem pozitia in ESI cu 1
            
            cmp AL, 'a'
            jae litera
            litera:
                cmp AL, 'z'
                jbe litera1
            ja skip
            litera1:
                mov [EDI], AL   ; punem litera din AL in EDI(sirul D)
                inc EDI         ; inaintam in sirul EDI
            skip:
            dec ECX             ; scadem numarul de repetari 
            cmp ECX, 0
            ja repeat
       
        push    dword 0    
        call    [exit]    
