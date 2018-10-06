                     
            .model TINY 
COST1         EQU  10d         
        
                             
            .code                
            org 100h

prog:
inizio:      
            MOV cx,cost1
ciclo:      ADD al,vett 
            INC vett
            LOOP ciclo
                             
fine:               
                 
         
            .data  
            VETT DB 0,1,2,3,4,5,6,7,8,9          
                                  


         END prog



