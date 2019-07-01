package point;

public class Point {

  int x = 0;
  int y = 0;

  Point(int x, int y) {
    this.x = x;
    this.y = y;
  }

  public String toString() {
    return ("(" + x + "," + y + ")");
  }

  public static void main(String[] args) {
    Point point1 = new Point(1, 2);
    System.out.println(point1);

    Point3D point2 = new Point3D(3, 4, 5);
    System.out.println(point2);

    point2.move();
    System.out.println(point2);
    
    NamedPoint point3 = new NamedPoint(7,8,"FantasticName");
    System.out.println(point3);

  }
}
