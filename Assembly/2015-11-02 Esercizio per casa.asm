.code
org 100h
.model TINY

INIZIO:
.startup

mov al,vett
add al,vett+1
add al,vett+2
add al,vett+3
add al,vett+4
mov ris,al

fine: mov ah,4Ch
int 21h

.data
vett db 2,3,5,9
ris db ?
END prog

;ho messo cosi perche mi piace e perche funziona comunque 