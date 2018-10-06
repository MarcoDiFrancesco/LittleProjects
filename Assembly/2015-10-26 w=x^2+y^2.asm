;W=x^2+y^2


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
            mul y
            add ax,bx
            mov w,ax      
            
fine:   
            .data         
            y db 4  
            x db 2    
            w dw ?
                 
         END prog
     