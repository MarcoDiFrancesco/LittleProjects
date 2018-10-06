  
.model TINY                      
.code              
org 100h

prog:
       
mov bx,1Ah            
mov cx,00
mov ax,bx
            
inizio:
     
div s
add cx,01h 
push ax
cmp ax,00
jne stampa
jmp inizio          
            
stampa:
     
pop dx
add dx,30h
mov ah,02h
int 21h
sub cx,01h
cmp cx,00h
je stampa
loop inizio
      
fine:       
mov ah,4Ch       
int 21h                       
         
.data             
                
s  DW 10d 
                                                   

END prog




