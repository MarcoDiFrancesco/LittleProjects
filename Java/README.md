# Java

This is the folder of all my (little) java projects.

## Notes

Compile time → Allocazione nel momento in cui compilo
Run time → Allocazione mentre il programma runna
L’allocazione dinamica in C++ viene gestita da `new type` che alloca `sizeof(type)` bytes in memoria in heap. `delete(* p)` dealloca la memoria puntata dal puntatore p. In caso di mancato utilizzo della `delete` avviene il **memory leak** e un conseguente **memory error**.

La differenza tra le due allocazione sta nel fatto che `int x[100];` alloca in stack quindi appena esco dalla funzione questo viene cancellato, mentre int `*y; y=new int[100];` alloca in heap, quindi rimane in memoria anche quando esco dalla funzione.

Given the following objects:

``` Java
A aa = new A();
A ab = new B();
B bb = new B();
m(A ab){"A "+(x instanceof B)}
m(B bb){"B "+(x instanceof B)}
```

When using the following code the program uses the **dynamic** type:

``` Java
aa.f(); → goes to A
a   .f(); → goes to B
bb.f(); → goes to B
```

When using the following code the program uses the **static** type:

``` Java
m(aa); → A false
m(ab); → A true
m(bb); → B true
m((A)b); → becomes m(ab) so → A true
```

## Pila in Java

Una coda può essere:

* FIFO: first in first out
* LIFO: last in first out

Scelgo le pile perché:

* in un array devo scegliere la grandezza dell’array e non lo potrò mai scegliere abbastanza grande da coprire tutti i casi
* non vado a sprecare memoria

## Interfacce

Un'interfaccia è una classe completamente astratta, senza attributi. L'interfaccia è fatta in modo che anche se non compila esattamente fuzioni. Un interfaccia può ereditare da una o più interacce ma non da classi: `interface <nome> extends <nome1>,..,<nomen> {...}`.
Una classe può implementare una o più interfacce, e DEVE implementarne tutti i metodi (a meno che non sia astratta): `class <nome> implements <nome1>,..,<nomen> {...}`.
