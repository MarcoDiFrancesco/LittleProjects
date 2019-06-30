package sbarramento;

public class Test {

  public static void main(String[] args) {
    A aa = new A();
    A ab = new B();
    B bb = new B();
    
    aa.g(aa); // A 
    aa.g(ab); // A
    aa.g(bb); // A
    
    ab.g(aa); // B 1
    ab.g(ab); // B 2
    ab.g(bb); // B 2  
  }
}

class A {

  void g(A aa) {
    System.out.println("A");
  }
}

class B extends A {

  void g(A aa) {
    System.out.println("B 1");
  }

  void g(B bb) {
    System.out.println("B 2");
  }
}
