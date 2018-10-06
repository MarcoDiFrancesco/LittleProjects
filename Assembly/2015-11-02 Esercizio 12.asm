;sommare i 10 elementi di un vettore in memoria 
;utilizzando l'istruzuine loop che si trova a pag 129
;e riferendo la dimensione come una costante
;utilizzando la dirrettiva .EQU
 

code
org 100h
.model TINY

INIZIO:
mov ax,vett1
mul vett2
mov vett3,ax
mov ax,vett1+1
mul vett2+1
mov vett3+1,ax  
mov ax,vett1+2
mul vett2+2
mov vett3+2,ax
mov ax,vett1+3
mul vett2+3
mov vett3+3,ax
mov ax,vett1+4
mul vett2+4
mov vett3+4,ax




fine: 
mov ah,4Ch
int 21h

.data
vett1 dw 359,3,5,9,6 
vett2 dw 1,2,3,4,5
vett3 dw 0,0,0,0,0

END prog
