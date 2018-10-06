 
            .model TINY 
COST1         EQU  23         
COST2         EQU  18h          
                             
            .code                
            org 100h

prog:
inizio:     mov al,bl          

                             
fine:       mov ah, 4Ch         
            int 21h            
         
            .data  DB           
                dato1 DB 10h    
                dato2 DW 350      


         END prog









                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
            