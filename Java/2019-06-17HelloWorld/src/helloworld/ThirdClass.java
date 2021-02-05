package helloworld;

public class ThirdClass extends SecondClass {

  int x = 0;
  int y = 0;
  int z = 0;

  ThirdClass(int x, int y, int z) {
    super(x, y);
    this.z = z;
  }

  @Override
  public String toString() {
    return ("(" + super.x + "-" + super.y + "-" + z + ")");
  }
}
