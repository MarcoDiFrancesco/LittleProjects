# Java
This is the folder of all my (little) java projects.

## Notes
Given the following objects:
```
A aa = new A();
A ab = new B();
B bb = new B();
m(A ab){"A "+(x instanceof B)}
m(B bb){"B "+(x instanceof B)}
```
when using the following code the program uses the **dynamic** type:
```
aa.f(); → goes to A
a   .f(); → goes to B
bb.f(); → goes to B
```

When using the following code the program uses the **static** type:
```
m(aa); → A false
m(ab); → A true
m(bb); → B true
m((A)b); → becomes m(ab) so → A true
```
