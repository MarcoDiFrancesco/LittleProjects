 
            .model TINY 
COST1         EQU  23         
COST2         EQU  18h          
                             
            .code                
            org 100h


inizio:     cmp var,10h
            jnz ciclo
            mov dx,offset stringa1
            mov ah,09h
            int 21h
            jmp fine

ciclo:      mov dx,offset stringa2
            mov ah,09h
            int 21h                    
                            
fine:       mov ah,4Ch
            int 21h
                 
            .data            
            stringa1 DB 'variabile uguale a 10$'
            stringa2 DB 'variabile diversa da 10$'
            var      DB 10h                      


            END prog
                                                                                                                                                                    
                              
                                     
                                                                                                                                                                                                                           

