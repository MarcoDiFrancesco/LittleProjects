;dati due vettori in memoria di 5 elementi, effettuare la moltiplicazione
;a 8 bit come il precedente salvando il risultato in vett3                             
                                                    
.code
org 100h
.model TINY

INIZIO:
mov al,vett1
mul vett2
mov vett3,al
mov al,vett1+1
mul vett2+1
mov vett3+1,al  
mov al,vett1+2
mul vett2+2
mov vett3+2,al
mov al,vett1+3
mul vett2+3
mov vett3+3,al
mov al,vett1+4
mul vett2+4
mov vett3+4,al




fine: 
mov ah,4Ch
int 21h

.data
vett1 db 2,3,5,9,6 
vett2 db 1,2,3,4,5
vett3 db 0,0,0,0,0

END prog
