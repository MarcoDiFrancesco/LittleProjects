            .model TINY 
COST1         EQU           
COST2         EQU              
                             
            .code             
            org 100h

prog:
inizio:   
            mov al,x
            mul x
            mov bx,ax
            mov al,y
            mov y
            add ax,bx
            mov cx,ax
            mov ax,z
            div r
            add cx,ax
            mov ax,cx      
            
fine:   
            .data         
         
                 
         END prog
     