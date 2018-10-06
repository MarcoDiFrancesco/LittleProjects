;Scrivere nei registri al bl e due valori immediati 200 12.
;Successivamente invertire il contenuto dei 2 registri e
;verificare il risultato con l'emulatore  
                             
            .model TINY 
COST1         EQU  23         
COST2         EQU  18h            
                             
            .code             
            org 100h

prog:
inizio:     mov al,op1          
            add al,op2
            mov ris,al
            
            
                             
           ;istrN
fine:       mov ah, 4Ch         
            int 21h           
         
            .data  DB         
                op1 DB 101   
                op2 DB 21    
                ris DB ?                                              

         END prog

                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
            