package binding;

class B extends A {

  public void g(A x) {
    System.out.println("called	1	on	instance	of	B");
  }

  public void g(B x) {
    System.out.println("called	2	on	instance	of	B");
  }
}
