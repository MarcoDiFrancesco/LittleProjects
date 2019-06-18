package helloworld;

public class SecondClass {

  public int x = 0;
  public int y = 0;

  SecondClass(int x, int y) {
    this.x = x;
    this.y = y;
  }

  @Override
  public String toString() {
    return("("+x+","+y+")");
  }
}
