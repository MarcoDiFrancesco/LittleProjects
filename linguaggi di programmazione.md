# Linguaggi di programmazione
Compile time → Allocazione nel momento in cui compilo
Run time → Allocazione mentre il programma runna
L’allocazione dinamica in C++ viene gestita da `new type` che alloca `sizeof(type)` bytes in memoria in heap. `delete(* p)` dealloca la memoria puntata dal puntatore p. In caso di mancato utilizzo della `delete` avviene il **memory leak** e un conseguente **memory error**.

La differenza tra le due allocazione sta nel fatto che `int x[100];` alloca in stack quindi appena esco dalla funzione questo viene cancellato, mentre int `*y; y=new int[100];` alloca in heap, quindi rimane in memoria anche quando esco dalla funzione.

## Pila in Java.
Una coda può essere:
* FIFO: first in first out
* LIFO: last in first out

Scelgo le pile perché:
* in un array devo scegliere la grandezza dell’array e non lo potrò mai scegliere abbastanza grande da coprire tutti i casi
* non vado a sprecare memoria
