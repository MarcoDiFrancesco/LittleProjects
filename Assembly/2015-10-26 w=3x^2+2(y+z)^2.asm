;w=3x^2+2(y+z)^2


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
            mov cx,ax                
            mov ax,z            
            div t           
            add cx,ax
            mov w,cx
            
fine:                                          
            .data         
            y db 300  
            x db 150
            z db 120
            w dw ?
            
                
         END prog         