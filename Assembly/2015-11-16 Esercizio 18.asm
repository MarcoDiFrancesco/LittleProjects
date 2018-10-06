;scrivere un programma dopo aver creato 
;un vettore di cinque elementi in memoria
;lo riempia con cinque caratteri letti da
;input (utilizzare il servizio dos 01h) e
;successivamente stampare a video il contenuto
;dei vettori (utilizzando il servizio 02h)
           
            .model TINY 
            DIM EQU 5
                                                   
            .code                
            org 100h                                 
inizio:      
            mov cx,dim
            mov di,0
            mov ah,1
leggi:      int 21h
            mov vett[di],al 
            inc di
            dec cx
            cmp cx,0
            jnz leggi
            mov cx,dim
            mov ah,2       
scrivi:     dec di
            mov dl, vett[di] 
            int 21h
            dec cx
            cmp cx,0
            jnz scrivi
                  
fine:       mov ah,40h
            int 21h
                                  
            .data 
            vett db dim duf (7)                                                          

        END prog                                                                       