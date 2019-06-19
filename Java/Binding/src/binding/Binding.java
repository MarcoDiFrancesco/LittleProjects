package binding;

public class Binding {
  
  public void f(A x) {
    System.out.println("A");
  }
  
  public void f(B x) {
    System.out.println("A");
  }
  
  public static void main(String[] args) {
    A a = new A();
    a.f(a);
  }

}
