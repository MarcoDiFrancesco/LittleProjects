;Scrivere un programma assembly che assegni 2 numeri da 8 bit
;che si trovano nelle locazioni di memoria op1 e op2 e 
;momorizza il risultato nelle locazioni di memoria ris

            .model TINY 
COST1         EQU  23            ; costanti
COST2         EQU  18h           ; 
                             
            .code                ; segmento
            org 100h

prog:
inizio:     mov al,bl            ; corpo del programma
         
                             
           ;istrN
fine:       mov ah, 4Ch          ; istruzioni di fine progeramma
            int 21h              ; (devono essre sempre presenti) 
         
            .data  DB            ; inizio segmento dati
                dato1 DB 10h     ; 1 byte con valore 10 esadecimale
                dato2 DW 350         ; 2 bytes con valore 350 decimale


         END prog



                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
            