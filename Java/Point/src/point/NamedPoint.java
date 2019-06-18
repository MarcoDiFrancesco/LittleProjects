package point;

public class NamedPoint extends Point {

  int x = 0;
  int y = 0;
  String name = "";

  NamedPoint(int x, int y, String name) {
    super(x, y);
    this.name = name;
  }
  
  public String toString(){
    return ("(" + super.x + "," + super.y + "," + name + ")");
  }
  
}
