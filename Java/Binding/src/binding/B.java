package binding;

public class B extends A {
    public void f(A x) {
      System.out.println("Called 1 on istance of B");
    }

    public void f(B x) {
      System.out.println("Called 2 on istance of B");
    }

}
