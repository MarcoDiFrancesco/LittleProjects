package binding;

public class Main {

  public static void main(String[] args) {
    A a = new A();
    A ab = new B();
    B b = new B();
    a.g(a);
    a.g(ab);
    a.g(b);
    ab.g(a);
    ab.g(ab);
    ab.g(b);
    b.g(a);
    b.g(ab);
    b.g(b);

  }
}
