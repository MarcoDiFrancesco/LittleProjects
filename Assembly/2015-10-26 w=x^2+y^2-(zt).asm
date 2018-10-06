;W=x^2+y^2-(z/t)


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
            y db 4  
            x db 2
            z db 20
            t db 2    
            w dw ?
            
            
                 
         END prog                                                            
         