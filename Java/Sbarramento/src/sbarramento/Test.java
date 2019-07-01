package sbarramento;

class A {
    A(int x) {System.out.println("X");}
    A() {System.out.println("Z");}
    public void finalize() {System.out.println("Y");}
}
class B extends A {
    B(int x) {System.out.println("A");}
    B() {System.out.println("C");}
    public void finalize() {System.out.println("B");}
}
public class Prova {
    public static void main(String args[]) {
        A a=new B(3);
        a = null;
        System.gc();
        System.runFinalization();
    }
}