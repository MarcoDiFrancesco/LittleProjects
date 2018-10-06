;la prima strina si chiama "prima stringa" la seconda "seconda stringa"

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
\
            inc vett
            del cx
            cmp cx,0d
            jnz ciclo                          
fine:                                         
            .data 
            DB 0,1,2,3,4,5,6,7,8,9                                                            

                 END prog                                                                  