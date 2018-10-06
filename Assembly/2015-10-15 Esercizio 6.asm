;Scrivere un programma assembler w=x-2y+3e.
;Si supponga che x, y, z siano numeri a 16
;bit, in particolare x=100, y=45, z=15



                           
            .model TINY 
COST1         EQU  23         
COST2         EQU  18h            
                             
            .code             
            org 100h

prog:
inizio:     mov dh,op1
            add dh,op1
            mov bh,op2
            mov ah,op 
            sub ah,bh    
            mov ch,ah
            add ah,ch
            add ah,ch     
            add ah,op3        
            add dh,ah         
            mov w ,dh
           
                              
           ;istrN
fine:       mov ah, 4Ch         
            int 21h    
                   
         
            .data         
            op1 db 4  
            op2 db 2    
            op3 db 100
            w   dw ?
                 
                 
         END prog

                
                
        
                        
                
                
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
         
         
         
         
         
         
         
         
               
   