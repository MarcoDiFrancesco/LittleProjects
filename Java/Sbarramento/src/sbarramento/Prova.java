package sbarramento;

public class B {
    static int x = 2;
    B() { x++; }
    B(int y) {x=x+y;}
    public void finalize(){x--;}
    public static void main(String[] args) {
        A a2 = new A();
        System.out.print(a2);
        A a1 = new A(2);
        System.out.print(a1);
    }
    public String toString(){return ""+x;}
}
class A extends B {
    int x=4;
    A() { x++; }
    A(int x) {super(x); x++;}
    public String toString(){return super.toString()+x;}
}
/*
A
x=super(2)
x++
super.tostring + x

B
y=2
x=4
*/