;programma che copia dei valori nei regitri
;copiare nei registri al,bl,cl rispettivamente i valori 11decimale, 11binario, 11esadecimale 
;successessivamente tramite l'assemblatore il funzionamento del programma          
   .model TINY 
                     
            .code                ; segmento
            org 100h

prog:
inizio:     mov al,bl           

                             
            ;istrN
fine:       mov ah, 4Ch          ; istruzioni di fine progeramma
            int 21h              ; (devono essre sempre presenti) 
         
            .data  DB            ; inizio segmento dati
                dato1 DB 10h     ; 1 byte con valore 10 esadecimale
                dato2 DW 350         ; 2 bytes con valore 350 decimale


         END prog




