;Scrivere un programma per calcolare
;la seguente espressione W=-3x+2(y-tz)      W=2x+3(x-y)+z
;x=5   y=100   z=2   t=7 


            .model TINY 
COST1         EQU           
COST2         EQU              
                             
            .code             
            org 

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
     