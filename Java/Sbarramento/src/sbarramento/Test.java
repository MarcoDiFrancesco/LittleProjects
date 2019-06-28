package sbarramento;

public class Test {
    public static void main(String[] args) {
        B b1=new B(new A()); b1.m(3);
  //      B b2 = new B(); b2.m(5);
  //      System.out.println(b2);
    }
}
class A {
    static int x = 3;
    A () { x++; }
    void m(int x) { this.x += x; }
    public String toString() { return "x="+x; }
}
class B {
    A a;
    B(A a) { this.a = a; }
    B() { super(); }
    void m(int x) { a.m(x); }
    public String toString() { return a.toString(); }
}