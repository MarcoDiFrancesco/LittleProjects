package point;

public class Point3D extends Point {

  int z = 0;

  Point3D(int x, int y, int z) {
    super(x, y);
    this.z = z;
  }

  @Override
  public String toString() {
    return ("(" + super.x + "," + super.y + "," + z + ")");
  }

  public void move() {
    super.x += 1;
    super.y += 1;
    z += 1;
  }
}
