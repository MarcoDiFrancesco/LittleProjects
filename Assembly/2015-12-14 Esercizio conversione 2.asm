  
.model TINY                      
.code              
org 100h

prog:
       
mov bx,20h         
mov cl,00
mov ax,bx

inizio:
mov dx,0
div s
push dx
inc cl
cmp ax,0
jne inizio

ciclo: 
pop dx
add dl,30h
mov ah,02h
int 21h
dec cl
jnz ciclo

fine:
mov ah,4Ch
int 21h


   
.data             
                
s DW 0Ah
                                                   

END prog




