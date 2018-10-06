;Scrivere nei registri al bl e due valori immediati 200 12.
;Successivamente invertire il contenuto dei 2 registri e
;verificare il risultato con l'emulatore  
                             
            .model TINY 
COST1         EQU  23         
COST2         EQU  18h            
                             
            .code             
            org 100h

prog:
inizio:     mov ax,op1          
            add ax,op2
            mov ris,ax
            
            
                             
           ;istrN
fine:       mov ah, 4Ch         
            int 21h           
         
            .data         
            op1 DW 1048d   
            op2 DW 4960d    
            ris DW ?                                              

         END prog

                
                
        
                        
                
                










         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
               
   