;Scrivere un programma per calcolare
;la seguente espressione W=2x+3(x-y)+z 


            .model TINY 
COST1         EQU  23         
COST2         EQU  18h            
                             
            .code             
            org 100h

prog:
inizio:     mov dh,op1
            add dh,op1
            mov bh,op2
            mov ah,op1 
            sub ah,bh    
            mov ch,ah
            add ah,ch
            add ah,ch     
            add ah,op3        
            add dh,ah         
            mov w ,dh
           
                              
           ;istrN
fine:                
           
                   
         
            .data         
            op1 db 4  
            op2 db 2    
            op3 db 100
            w   dw ?
                 
                 
         END prog
     