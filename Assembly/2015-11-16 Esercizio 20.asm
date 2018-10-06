;scrivere un programma che verifichi se un
;carattere inserito da tasriera e una cifra
;in caso contrario il programma continua a 
;chiedere di inserire una cifra 


            .model TINY 
COST1         EQU  23         
COST2         EQU  18h          
                             
            .code                
            org 100h



inizio:     
            mov dx,offset stringa1
            mov ah,01
            int 21h
            mov var,al    
            
            cmp var,39h
            jmp ciclo1
            cmp var,30h
            jnz ciclo1
           
ciclo1:
            mov dx,offset stringa2
            mov,ah,09h
            int 21h

           
ciclo:
            mov dx,offset stringa
            mov,ah,09h
            int 21h
            
                             
fine:               
                 
         
            .data             
            var    DB 10h                      
            stringa1 DB
            stringa2 DB
           
           
            ;devo dichiarare ancora tutte le variabili
            
        END prog















         
         
         
         
         
         
         
         
         
         