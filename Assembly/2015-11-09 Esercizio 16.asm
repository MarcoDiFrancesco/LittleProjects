;sommare un vettore di 10 numeri utilizzando l'istruzione CMP e la  JNZ

            .model TINY 
COST1         EQU  23         
COST2         EQU  18h                                                    
            .code                
            org 100h                          
prog:        
inizio:      
            mov cx,10d
            mov al,0d
ciclo:      
            add al,vett
            inc vett
            del cx
            cmp cx,0d
            jnz ciclo                          
fine:                                         
            .data  DB 0,1,2,3,4,5,6,7,8,9                                                            

         END prog                                          